#include <small_header.h>
#include "Game/Objects/In Game Objects/BaseClasses/_BoxDeath.h"

#include "Game/Collision Detection/AABox.h"
#include "Game/Collision Detection/Phsx.h"
#include "Game/Objects/ObjectBase.h"
#include "Game/Objects/Bob/Bob.h"
#include "Game/Objects/In Game Objects/BaseClasses/_Death.h"
#include "Game/Objects/In Game Objects/Grab/MakeData.h"
#include "Game/Level/Level.h"

#include "Game/Tools/Recycler.h"

namespace CloudberryKingdom
{

	void _BoxDeath::MakeNew()
	{
		_Death::MakeNew();

		Box->Initialize( Vector2(), Vector2(1) );
	}

	_BoxDeath::_BoxDeath()
	{
	}

	_BoxDeath::_BoxDeath( bool BoxesOnly )
	{
		Construct( BoxesOnly );
	}

	void _BoxDeath::Construct( bool BoxesOnly )
	{
		getCore()->BoxesOnly = BoxesOnly;

		Box = boost::make_shared<AABox>();

		MakeNew();
	}

	Vector2 _BoxDeath::GetBoxPos()
	{
		return getPos();
	}

	void _BoxDeath::Init( Vector2 pos, const boost::shared_ptr<Level> &level )
	{
		_Death::Init( pos, level );

		Box->Initialize( GetBoxPos(), BoxSize );

		Box->SetTarget( GetBoxPos(), BoxSize );
		Box->SwapToCurrent();
	}

	void _BoxDeath::Scale( float scale )
	{
		Box->Scale( scale );
	}

	void _BoxDeath::TargetPos()
	{
	}

	void _BoxDeath::ActivePhsxStep()
	{
		Box->SetTarget( getPos(), BoxSize );

		if ( getCore()->WakeUpRequirements )
		{
			Box->SwapToCurrent();
			getCore()->WakeUpRequirements = false;
		}
	}

	void _BoxDeath::PhsxStep2()
	{
		if ( getCore()->SkippedPhsx )
			return;

		Box->SwapToCurrent();
	}

	void _BoxDeath::OnMarkedForDeletion()
	{
		_Death::OnMarkedForDeletion();
	}

	void _BoxDeath::DrawBoxes()
	{
		Box->Draw( bColor( 50, 50, 255, 120 ), 5 );
	}

	void _BoxDeath::Move( Vector2 shift )
	{
		_Death::Move( shift );

		Box->Move( shift );
	}

	void _BoxDeath::Interact( const boost::shared_ptr<Bob> &bob )
	{
		if ( !getCore()->SkippedPhsx )
		{
			bool Col = Phsx::BoxBoxOverlap( bob->Box2, Box );

			if ( Col )
			{
				if ( getCore()->MyLevel->PlayMode == 0 )
					bob->Die( DeathType, shared_from_this() );

				if ( getCore()->MyLevel->PlayMode != 0 )
				{
					bool col = Phsx::BoxBoxOverlap_Tiered( Box, getCore(), bob, AutoGenSingleton );

					if ( col )
					{
						//if ((Pos - bob.Pos).Length() > 2000) Tools::Write(0);
						getCore()->getRecycle()->CollectObject( shared_from_this() );
					}
				}
			}
		}
	}

	void _BoxDeath::Clone( const boost::shared_ptr<ObjectBase> &A )
	{
		getCore()->Clone(A->getCore());

		getCore()->WakeUpRequirements = true;
	}
}
