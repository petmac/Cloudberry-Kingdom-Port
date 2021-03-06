#include <small_header.h>
#include "Game/Objects/In Game Objects/Obstacles/Firesnake__Auto.h"

#include "Game/Objects/ObjectBase.h"
#include "Game/Level/Make/DifficultyHelper.h"
#include "Game/Level/Make/PieceSeedData.h"
#include "Game/Level/Make/Parameters/Param.h"
#include "Game/Objects/AutoGen.h"
#include "Game/Objects/In Game Objects/Grab/MakeData.h"
#include "Game/Level/Level.h"
#include "Game/Objects/In Game Objects/Obstacles/CloudberryKingdom.Firesnake.h"
#include "Game/Tools/Recycler.h"
#include "Game/Tools/Tools.h"

#include "Game/Level/Make/Parameters/Upgrades.h"
#include "Core/Tools/Random.h"


namespace CloudberryKingdom
{

	void Firesnake_Parameters::SetParameters( const boost::shared_ptr<PieceSeedData> &PieceSeed, const boost::shared_ptr<Level> &level )
	{
		AutoGen_Parameters::SetParameters( PieceSeed, level );

		boost::shared_ptr<CloudberryKingdom::Upgrades> u = PieceSeed->getu();

		if ( PieceSeed->MyUpgrades1->Get( Upgrade_FIRESNAKE ) > 0 || PieceSeed->MyUpgrades2->Get( Upgrade_FIRESNAKE ) > 0 )
			Make = true;
		else
			Make = false;

		// General difficulty
		float FloaterLevel = PieceSeed->MyUpgrades1->Get( Upgrade_FIRESNAKE );
		if ( FloaterLevel > 6 )
			NumOffsets = 8;
		else
			NumOffsets = 4;

		BobWidthLevel = Param( PieceSeed, u->Get( Upgrade_FIRESNAKE ) );

		Step = Param( PieceSeed, DifficultyHelper::Interp159( 1340, 830, 340, u->Get( Upgrade_FIRESNAKE ) ) );

		Period = Param( PieceSeed, DifficultyHelper::Interp( 290, 150, u->Get( Upgrade_FIRESNAKE ) ) * DifficultyHelper::Interp( 1.7f, 1.0f, u->Get( Upgrade_SPEED ) ) );

		RadiiX = VectorParam( PieceSeed, Vector2( 400, 1000 ) );
		RadiiY = VectorParam( PieceSeed, Vector2( 1550, 1850 ) );
	}

	void Firesnake_Parameters::InitializeInstanceFields()
	{
		Make = false;
		Snakes = std::vector<std::vector<unsigned long long> >();
	}

boost::shared_ptr<Firesnake_AutoGen> Firesnake_AutoGen::instance = boost::make_shared<Firesnake_AutoGen>();

	const boost::shared_ptr<Firesnake_AutoGen> &Firesnake_AutoGen::getInstance()
	{
		return instance;
	}

	Firesnake_AutoGen::Firesnake_AutoGen()
	{
		Do_PreFill_2 = true;
	}

	boost::shared_ptr<AutoGen_Parameters> Firesnake_AutoGen::SetParameters( const boost::shared_ptr<PieceSeedData> &data, const boost::shared_ptr<Level> &level )
	{
		boost::shared_ptr<Firesnake_Parameters> Params = boost::make_shared<Firesnake_Parameters>();
		Params->SetParameters( data, level );

		return boost::static_pointer_cast<AutoGen_Parameters>( Params );
	}

	boost::shared_ptr<Firesnake_Parameters> Firesnake_AutoGen::GetParams( const boost::shared_ptr<Level> &level )
	{
		return boost::static_pointer_cast<Firesnake_Parameters>( level->getStyle()->FindParams( Firesnake_AutoGen::getInstance() ) );
	}

	void Firesnake_AutoGen::Cleanup_2( const boost::shared_ptr<Level> &level, Vector2 BL, Vector2 TR )
	{
		AutoGen::Cleanup_2( level, BL, TR );

		boost::shared_ptr<Firesnake_Parameters> Params = GetParams( level );

		for ( std::vector<std::vector<unsigned long long> >::const_iterator GuidList = Params->Snakes.begin(); GuidList != Params->Snakes.end(); ++GuidList )
		{
			// Convert the list to objects
			std::vector<unsigned long long> v = *GuidList;
			ObjectVec Snake = level->GuidToObj( v );

			// Find a deleted element to start with
			int start = 0;
			for ( int i = 0; i < static_cast<int>( Snake.size() ); i++ )
				if ( Snake[ i ] == 0 )
				{
					start = i + 1;
					break;
				}

			// Find which elements can serve as heads
			std::vector<int> PotentialHeads = std::vector<int>();

			int count = 0;
			for ( int j = 0; j < static_cast<int>( Snake.size() ); j++ )
			{
				int i = ( j + start ) % Snake.size();

				if ( Snake[ i ] == 0 )
				{
					//if (count > 8)
					if ( count > 4 )
						PotentialHeads.push_back( ( j - 1 + start ) % Snake.size() );
					count = 0;
				}
				else
					count++;

				if ( count > static_cast<int>( Snake.size() ) / 2 )
					PotentialHeads.push_back( i );
			}

			// If no potential heads were found delete everything
			if ( PotentialHeads.empty() )
			{
				for ( ObjectVec::const_iterator snake = Snake.begin(); snake != Snake.end(); ++snake )
					if ( *snake != 0 )
						( *snake )->CollectSelf();
				continue;
			}

			// Choose a head
			/*int head = PotentialHeads.Choose( level->getRnd() );*/
			int head = ListExtension::Choose( PotentialHeads, level->getRnd() );

			// Find the end of the chain
			int l = 0;
			for ( l = 0; l < static_cast<int>( Snake.size() ) / 2; l++ )
			{
				int i = ( head - l + Snake.size() ) % Snake.size();

				if ( Snake[ i ] == 0 )
					break;
			}

			// Delete the rest
			while ( l < static_cast<int>( Snake.size() ) )
			{
				int i = ( head - l + Snake.size() ) % Snake.size();

				if ( Snake[ i ] != 0 )
					Snake[ i ]->CollectSelf();

				l++;
			}
		}

		Params->Snakes.clear();
	}

	void Firesnake_AutoGen::CreateLine( const boost::shared_ptr<Level> &level, Vector2 pos )
	{
		boost::shared_ptr<Firesnake_Parameters> Params = GetParams( level );

		float Period = Params->Period.GetVal( pos );

		//int n = 36;
		int n = 18;

		std::vector<unsigned long long> Snake = std::vector<unsigned long long>( n );

		//Vector2 Radii = new Vector2(Params.RadiiX.RndFloat(pos, level.Rnd), Params.RadiiY.RndFloat(pos, level.Rnd));
		//Vector2 Radii = new Vector2(0, 800);
		Vector2 Radii = Vector2( 500, 500 );

		float periodstep = Period / n;
		for ( int i = 0; i < n; i++ )
		{
			boost::shared_ptr<Firesnake> snake = boost::static_pointer_cast<Firesnake>( CreateAt( level, pos ) );
			snake->Offset = static_cast<int>( i * periodstep );
			snake->Radii = Radii;

			Snake.push_back( snake->getCore()->MyGuid );
		}

		Params->Snakes.push_back( Snake );
	}

	boost::shared_ptr<ObjectBase> Firesnake_AutoGen::CreateAt( const boost::shared_ptr<Level> &level, Vector2 pos )
	{
		// Get Floater parameters
		boost::shared_ptr<Firesnake_Parameters> Params = boost::static_pointer_cast<Firesnake_Parameters>( level->getStyle()->FindParams( Firesnake_AutoGen::getInstance() ) );

		// Get the new snake
		boost::shared_ptr<Firesnake> NewSnake = boost::static_pointer_cast<Firesnake>( level->getRecycle()->GetObject(ObjectType_FIRESNAKE, true) );

		//if (level.Rnd.RndBool())
		//    pos.Y = level.FillBL.Y - 300;
		//else
			pos.Y = level->Fill_TR.Y + 550;

		NewSnake->Move( pos );

		NewSnake->Offset = level->getRnd()->Rnd->Next(0, NewSnake->Period);

		// Discrete period offsets
		int NumOffsets = Params->NumOffsets;
		int Period = static_cast<int>( Params->Period.GetVal( pos ) / NumOffsets ) * NumOffsets;
		NewSnake->Period = Period;
		NewSnake->Offset = level->getRnd()->Rnd->Next(0, NumOffsets) * Period / NumOffsets;

		NewSnake->getCore()->GenData.RemoveIfUnused = false;

		level->AddObject( NewSnake );

		return NewSnake;
	}

	void Firesnake_AutoGen::PreFill_2( const boost::shared_ptr<Level> &level, Vector2 BL, Vector2 TR )
	{
		AutoGen::PreFill_2( level, BL, TR );

		// Get Floater parameters
		boost::shared_ptr<Firesnake_Parameters> Params = boost::static_pointer_cast<Firesnake_Parameters>( level->getStyle()->FindParams( Firesnake_AutoGen::getInstance() ) );

		if ( !Params->Make )
			return;

		float step = 5;
		Vector2 loc = Vector2( BL.X + 600, ( TR.Y + BL.Y ) / 2 );

		while ( loc.X < TR.X )
		{
			step = level->getRnd()->RndFloat(Params->Step.GetVal(loc), Params->Step.GetVal(loc));

			float shift = level->getRnd()->RndFloat(-800, 800);

			CreateLine( level, loc );

			loc.X += step;
		}
	}
}
