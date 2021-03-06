#include <small_header.h>
#include "Core/Graphics/Draw/Simple/SimpleObject.h"

#include "Core/Animation/AnimQueue.h"
#include "Core/Effects/EzEffect.h"
#include "Core/Effects/EzEffectWad.h"
#include "Core/Graphics/QuadDrawer.h"
#include "Core/Graphics/Draw/Object/ObjectClass.h"
#include "Core/Graphics/Draw/Quads/Quad.h"
#include "Core/Graphics/Draw/Simple/BasePoint.h"
#include "Core/Graphics/Draw/Simple/SimpleBox.h"
#include "Core/Graphics/Draw/Simple/SimpleQuad.h"
#include "Game/Tools/Tools.h"


#include "Hacks/List.h"
#include "Hacks/String.h"

#include <Core/Animation/AnimQueue.h>

namespace CloudberryKingdom
{

	void SimpleObject::Release()
	{
		//return;
		if ( Released )
			return;
		Released = true;

		if ( Quads.size() > 0 )
		{
			for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
				Quads[ i ].Release();
		}
		Quads.clear();

		if ( Boxes.size() > 0 )
		{
			for ( std::vector<boost::shared_ptr<SimpleBox> >::const_iterator box = Boxes.begin(); box != Boxes.end(); ++box )
				( *box )->Release();
		}
		Boxes.clear();

		//AnimQueue.clear();
		std::queue<boost::shared_ptr<AnimQueueEntry> > empty;
		std::swap( AnimQueue, empty );
		
		LastAnimEntry.reset();
		AnimLength.clear();
		AnimName.clear();
		AnimSpeed.clear();

		MyEffects.clear();
	}

	void SimpleObject::UpdateEffectList()
	{
		if ( Quads.empty() || Quads.empty() )
			return;

		if ( MyEffects.empty() )
			MyEffects = std::vector<boost::shared_ptr<EzEffect> >();
		else
			MyEffects.clear();

		for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
			if ( std::find( MyEffects.begin(), MyEffects.end(), Quads[ i ].MyEffect ) == MyEffects.end() )
				MyEffects.push_back( Quads[ i ].MyEffect );
	}

	int SimpleObject::GetQuadIndex( const std::wstring &name )
	{
		for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
		{
			if ( CompareIgnoreCase( Quads[ i ].Name, name ) == 0 )
				return i;
		}

		return -1;
	}

	void SimpleObject::Scale( float scale )
	{
		Base.e1 *= scale;
		Base.e2 *= scale;
	}

	void SimpleObject::SetColor( Color color )
	{
		if ( Quads.size() > 0 )
			for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
				Quads[ i ].SetColor( color );
	}

	SimpleObject::SimpleObject( const boost::shared_ptr<SimpleObject> &obj, bool BoxesOnly )
	{
		xFlip = false; yFlip = false; CenterFlipOnBox = false;;
		Play = false; Loop = false; Transfer = false; OldLoop = false; Linear = false;
		anim = 0; OldAnim = 0;
		t = 0; OldT = 0; StartT = 0;
		Released = false;

		Constructor( obj, BoxesOnly, false );
	}

	void SimpleObject::Constructor( const boost::shared_ptr<SimpleObject> &obj, bool BoxesOnly, bool DeepCopy )
	{
		xFlip = false; yFlip = false; CenterFlipOnBox = false;
		Play = false; Loop = false; Transfer = false; OldLoop = false; Linear = false;
		anim = 0; OldAnim = 0;
		t = 0; OldT = 0; StartT = 0;

		Base = obj->Base;

		CenterFlipOnBox = obj->CenterFlipOnBox;

		if ( !BoxesOnly )
		{
			Quads = std::vector<SimpleQuad>( obj->Quads.size() );
			for ( int i = 0; i < static_cast<int>( obj->Quads.size() ); i++ )
				Quads[ i ] = SimpleQuad( obj->Quads[ i ] );
		}

		Boxes = std::vector<boost::shared_ptr<SimpleBox> >( obj->Boxes.size() );
		for ( int i = 0; i < static_cast<int>( obj->Boxes.size() ); i++ )
			Boxes[ i ] = boost::make_shared<SimpleBox>( obj->Boxes[ i ] );

		// Copy the AnimQueue
		AnimQueue = std::queue<boost::shared_ptr<AnimQueueEntry> >();
		std::queue<boost::shared_ptr<AnimQueueEntry> > QueueCopy = std::queue<boost::shared_ptr<AnimQueueEntry> >( obj->AnimQueue );
		std::vector<boost::shared_ptr<AnimQueueEntry> > array_Renamed;
		while( !QueueCopy.empty() )
		{
			array_Renamed.push_back( QueueCopy.front() );
			QueueCopy.pop();
		}

		// FIXME: Make sure make_shared actually copies the object.
		if ( array_Renamed.size() > 0 )
		{
			LastAnimEntry = boost::make_shared<AnimQueueEntry>( array_Renamed[ array_Renamed.size() - 1 ] );
			for ( size_t i = 0; i < array_Renamed.size() - 1; i++ )
				AnimQueue.push( boost::make_shared<AnimQueueEntry>( array_Renamed[ i ] ) );
			AnimQueue.push( LastAnimEntry );
		}

		Play = obj->Play;
		Loop = obj->Loop;
		anim = obj->anim;
		t = obj->t;

		if ( DeepCopy )
		{
			AnimLength = std::vector<int>( 50 );
			CopyFromTo( obj->AnimLength, AnimLength );
			//obj->AnimLength.CopyTo( AnimLength, 0 );
			AnimSpeed = std::vector<float>( 50 );
			CopyFromTo( obj->AnimSpeed, AnimSpeed );
			//obj->AnimSpeed.CopyTo( AnimSpeed, 0 );
			AnimName = std::vector<std::wstring>( 50 );
			CopyFromTo( obj->AnimName, AnimName );
			//obj->AnimName.CopyTo( AnimName, 0 );

			UpdateEffectList();
		}
		else
		{
			AnimLength = obj->AnimLength;
			AnimSpeed = obj->AnimSpeed;
			AnimName = obj->AnimName;

			MyEffects = obj->MyEffects;
		}
	}

	SimpleObject::SimpleObject( const boost::shared_ptr<ObjectClass> &obj ) :
		xFlip( false ), yFlip( false )
	{
		Base.Init();

		CenterFlipOnBox = obj->CenterFlipOnBox;

		Quads = std::vector<SimpleQuad>( obj->QuadList.size() );
		for ( int i = 0; i < static_cast<int>( obj->QuadList.size() ); i++ )
			Quads[ i ] = SimpleQuad( boost::dynamic_pointer_cast<Quad>( obj->QuadList[ i ] ) );
		
		Boxes = std::vector<boost::shared_ptr<SimpleBox> >( obj->BoxList.size() );
		for ( int i = 0; i < static_cast<int>( obj->BoxList.size() ); i++ )
			Boxes[ i ] = boost::make_shared<SimpleBox>( obj->BoxList[ i ] );

		// Copy the AnimQueue
		AnimQueue = std::queue<boost::shared_ptr<AnimQueueEntry> >();
		std::queue<boost::shared_ptr<AnimQueueEntry> > QueueCopy = std::queue<boost::shared_ptr<AnimQueueEntry> >( obj->AnimQueue );
		std::vector<boost::shared_ptr<AnimQueueEntry> > array_Renamed;
		while( !QueueCopy.empty() )
		{
			array_Renamed.push_back( QueueCopy.front() );
			QueueCopy.pop();
		}

		// FIXME: Make sure make_shared actually copies the object.
		if ( array_Renamed.size() > 0 )
		{
			LastAnimEntry = boost::make_shared<AnimQueueEntry>( array_Renamed[ array_Renamed.size() - 1 ] );
			for ( size_t i = 0; i < array_Renamed.size() - 1; i++ )
				AnimQueue.push( boost::make_shared<AnimQueueEntry>( array_Renamed[ i ] ) );
			AnimQueue.push( LastAnimEntry );
		}

		Play = obj->Play;
		Loop = obj->Loop;
		anim = obj->anim;
		t = obj->t;

		/*
		//AnimLength = std::vector<int>( 50 );
		AnimLength = std::vector<int>( obj->AnimLength.size() );
		CopyFromTo( obj->AnimLength, AnimLength );
		//AnimSpeed = std::vector<float>( 50 );
		AnimSpeed = std::vector<float>( obj->AnimSpeed.size() );
		CopyFromTo( obj->AnimSpeed, AnimSpeed );
		//AnimName = std::vector<std::wstring>( 50 );
		//AnimName = std::vector<std::wstring>( obj->AnimName.size() );
		//CopyFromTo( obj->AnimName, AnimName );
		*/

		AnimLength = std::vector<int>(); AnimLength.push_back( obj->AnimLength[ 0 ] );
		AnimSpeed = std::vector<float>(); AnimSpeed.push_back( obj->AnimSpeed[ 0 ] );

		UpdateEffectList();
	}

	Vector2 SimpleObject::GetBoxCenter( int i )
	{
		Vector2 c = Boxes[ i ]->Center();
		if ( xFlip )
			c.X = FlipCenter.X - ( c.X - FlipCenter.X );
		if ( yFlip )
			c.Y = FlipCenter.Y - ( c.Y - FlipCenter.Y );
		return c;
	}

	void SimpleObject::CopyUpdate( const boost::shared_ptr<SimpleObject> &source )
	{
		Vector2 shift = Base.Origin - source->Base.Origin;

		if ( Quads.size() > 0 )
			for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
				Quads[ i ].CopyUpdate( source->Quads[ i ], shift );

		for ( int i = 0; i < static_cast<int>( Boxes.size() ); i++ )
			Boxes[ i ]->CopyUpdate( source->Boxes[ i ], shift );

		if ( Boxes.size() > 0 )
			FlipCenter = Boxes[ 0 ]->Center();
		else
			FlipCenter = Base.Origin;
	}

	void SimpleObject::UpdateQuads()
	{
		if ( Quads.size() > 0 )
			for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
				Quads[ i ].Update( Base );
	}

	void SimpleObject::UpdateBoxes()
	{
		for ( int i = 0; i < static_cast<int>( Boxes.size() ); i++ )
			Boxes[ i ]->Update( Base );

		if ( Boxes.size() > 0 )
			FlipCenter = Boxes[ 0 ]->Center();
		else
			FlipCenter = Base.Origin;
	}

	void SimpleObject::Update()
	{
		UpdateQuads();

		UpdateBoxes();
	}

	void SimpleObject::UpdatedShift( Vector2 shift )
	{
		for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
			Quads[ i ].UpdatedShift( shift );
	}

	void SimpleObject::Draw()
	{
		Draw( Tools::QDrawer, Tools::EffectWad );
	}

	void SimpleObject::Draw( const boost::shared_ptr<QuadDrawer> &QDrawer, const boost::shared_ptr<EzEffectWad> &EffectWad )
	{
		int n = 0;
		if ( Quads.size() > 0 )
			n = Quads.size();

		Draw( QDrawer, EffectWad, 0, n - 1 );
	}

	void SimpleObject::Draw( const boost::shared_ptr<QuadDrawer> &QDrawer, const boost::shared_ptr<EzEffectWad> &EffectWad, int StartIndex, int EndIndex )
	{
		if ( xFlip || yFlip )
			for ( std::vector<boost::shared_ptr<EzEffect> >::const_iterator fx = MyEffects.begin(); fx != MyEffects.end(); ++fx )
			{
				( *fx )->FlipCenter->SetValue( FlipCenter );
				( *fx )->FlipVector->SetValue( Vector2( xFlip ? 1.f : -1.f, yFlip ? 1.f : -1.f ) );
			}


		for ( int i = StartIndex; i <= EndIndex; i++ )
			QDrawer->DrawQuad( Quads[ i ] );

		if ( xFlip || yFlip )
		{
			QDrawer->Flush();
			for ( std::vector<boost::shared_ptr<EzEffect> >::const_iterator fx = MyEffects.begin(); fx != MyEffects.end(); ++fx )
				( *fx )->FlipVector->SetValue( Vector2( -1.f, -1.f ) );
		}
	}

	void SimpleObject::DrawQuad( SimpleQuad &Quad_Renamed )
	{
		if ( xFlip || yFlip )
			for ( std::vector<boost::shared_ptr<EzEffect> >::const_iterator fx = MyEffects.begin(); fx != MyEffects.end(); ++fx )
			{
				( *fx )->FlipCenter->SetValue( FlipCenter );
				( *fx )->FlipVector->SetValue( Vector2( xFlip ? 1.f : -1.f, yFlip ? 1.f : -1.f ) );
			}

		Tools::QDrawer->DrawQuad( Quad_Renamed );

		if ( xFlip || yFlip )
		{
			Tools::QDrawer->Flush();
			for ( std::vector<boost::shared_ptr<EzEffect> >::const_iterator fx = MyEffects.begin(); fx != MyEffects.end(); ++fx )
				( *fx )->FlipVector->SetValue( Vector2( -1.f, -1.f ) );
		}
	}

	void SimpleObject::EnqueueTransfer( int _anim, float _destT, float speed, bool DestLoop )
	{
		DequeueTransfers();

		boost::shared_ptr<AnimQueueEntry> NewEntry = boost::make_shared<AnimQueueEntry>();
		NewEntry->anim = _anim;
		NewEntry->AnimSpeed = speed;
		NewEntry->StartT = 0;
		NewEntry->EndT = 1;
		NewEntry->DestT = _destT;
		NewEntry->Loop = DestLoop;
		NewEntry->Type = AnimQueueEntryType_TRANSFER;
		NewEntry->Initialized = false;

		AnimQueue.push( NewEntry );
		LastAnimEntry = NewEntry;
	}

	void SimpleObject::EnqueueAnimation( int _anim, float startT, bool loop )
	{
		EnqueueTransfer( _anim, startT,.5f, loop );

		boost::shared_ptr<AnimQueueEntry> NewEntry = boost::make_shared<AnimQueueEntry>();
		NewEntry->anim = _anim;
		NewEntry->AnimSpeed = 1;
		NewEntry->StartT = startT;
		NewEntry->EndT = -1;
		NewEntry->Loop = loop;
		NewEntry->Type = AnimQueueEntryType_PLAY;
		NewEntry->Initialized = false;

		AnimQueue.push( NewEntry );
		LastAnimEntry = NewEntry;
	}

	int SimpleObject::DestinationAnim()
	{
		if ( AnimQueue.size() > 0 )
			return LastAnimEntry->anim;
		else
			return anim;
	}

	void SimpleObject::DequeueTransfers()
	{
		while ( AnimQueue.size() > 0 && AnimQueue.front()->Type == AnimQueueEntryType_TRANSFER )
			AnimQueue.pop();
	}

	void SimpleObject::PlayUpdate( float DeltaT )
	{
		if ( !Play )
			return;
		if ( AnimQueue.empty() )
			return;

		boost::shared_ptr<AnimQueueEntry> CurAnimQueueEntry = AnimQueue.front();

		if ( !CurAnimQueueEntry->Initialized )
		{
			t = CurAnimQueueEntry->StartT;
			Loop = CurAnimQueueEntry->Loop;
			anim = CurAnimQueueEntry->anim;

			if ( CurAnimQueueEntry->Type == AnimQueueEntryType_TRANSFER )
				SetHold();

			CurAnimQueueEntry->Initialized = true;
		}

		t += DeltaT * AnimSpeed[ anim ] * CurAnimQueueEntry->AnimSpeed;
		if ( CurAnimQueueEntry->Type == AnimQueueEntryType_TRANSFER )
		{
			if ( t > 1 )
			{
				AnimQueue.pop();
				if ( AnimQueue.size() > 0 )
				{
					boost::shared_ptr<AnimQueueEntry> Next = AnimQueue.front();
					if ( Next->anim == anim )
						Next->StartT = CurAnimQueueEntry->DestT;
				}

				t = 1;
			}
		}
		else
		{
			if ( t > CurAnimQueueEntry->EndT && t - DeltaT <= CurAnimQueueEntry->EndT )
			{
				t = CurAnimQueueEntry->EndT;
				AnimQueue.pop();
			}
			else
			{
				if ( Loop )
				{
					if ( t <= 0 )
						t += AnimLength[ anim ] + 1;
					if ( t > AnimLength[ anim ] + 1 )
						t -= AnimLength[ anim ] + 1;
				}
				else
				{
					if ( t < 0 )
					{
						t = 0;
						AnimQueue.pop();
					}
					if ( t > AnimLength[ anim ] )
					{
						t = static_cast<float>( AnimLength[ anim ] );
						AnimQueue.pop();
					}
				}
			}
		}

		if ( CurAnimQueueEntry->Type == AnimQueueEntryType_PLAY )
		{
			if ( Quads.size() > 0 )
				for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
					if ( Quads[ i ].Animated )
						Quads[ i ].Calc( anim, t, AnimLength[ anim ], Loop, Linear );
			for ( int i = 0; i < static_cast<int>( Boxes.size() ); i++ )
				if ( Boxes[ i ]->Animated )
					Boxes[ i ]->Calc( anim, t, AnimLength[ anim ], Loop, Linear );
		}
		else
		{
			if ( Quads.size() > 0 )
				for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
					Quads[ i ].Transfer( anim, CurAnimQueueEntry->DestT, AnimLength[ anim ], CurAnimQueueEntry->Loop, Linear, t );
			for ( int i = 0; i < static_cast<int>( Boxes.size() ); i++ )
				Boxes[ i ]->Transfer( anim, CurAnimQueueEntry->DestT, AnimLength[ anim ], CurAnimQueueEntry->Loop, Linear, t );
		}
	}

	void SimpleObject::SetHold()
	{
		if ( Quads.size() > 0 )
			for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
				Quads[ i ].SetHold();
		for ( int i = 0; i < static_cast<int>( Boxes.size() ); i++ )
			Boxes[ i ]->SetHold();
	}

	void SimpleObject::Read( int anim, int frame )
	{
		if ( Quads.size() > 0 )
			for ( int i = 0; i < static_cast<int>( Quads.size() ); i++ )
				Quads[ i ].ReadAnim( anim, frame );
		for ( int i = 0; i < static_cast<int>( Boxes.size() ); i++ )
			Boxes[ i ]->ReadAnim( anim, frame );
	}
}
