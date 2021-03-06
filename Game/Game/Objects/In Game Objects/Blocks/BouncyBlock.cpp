#include <small_header.h>
#include "Game/Objects/In Game Objects/Blocks/BouncyBlock.h"

#include "Core/Graphics/Draw/Quads/PieceQuad.h"
#include "Core/Sound/EzSound.h"
#include "Game/Collision Detection/AABox.h"
#include "Game/Objects/ObjectBase.h"
#include "Game/Tilesets/TileSet.h"
#include "Game/Objects/In Game Objects/Blocks/Block.h"
#include "Game/Objects/Bob/Bob.h"
#include "Game/Objects/In Game Objects/Blocks/NormalBlockDraw.h"
#include "Game/Objects/In Game Objects/Grab/MakeData.h"
#include "Game/Level/Level.h"
#include "Game/Tilesets/BlockGroup.h"
#include "Game/Tools/Recycler.h"
#include "Game/Tools/Tools.h"
#include "Game/Tilesets/TileSetInfo.h"

#include "Core/Sound/EzSoundWad.h"
#include "Game/Player/Hero Physics/Base.h"
#include "Game/Collision Detection/FloatRectangle.h"
#include "Game/Tools/Camera.h"

namespace CloudberryKingdom
{

	void BouncyBlock::BouncyBlockTileInfo::InitializeInstanceFields()
	{
		Group = PieceQuad::BouncyGroup;
		BounceSound = Tools::SoundWad->FindByName( std::wstring( L"BouncyBlock_Bounce" ) );
	}

	void BouncyBlock::MakeNew()
	{
		getCore()->Init();
		//BlockCore.GivesVelocity = false;
		getCore()->DrawLayer = 3;
		getBlockCore()->MyType = ObjectType_BOUNCY_BLOCK;

		SideDampening = 1;

		SetState( BouncyBlockState_REGULAR );
	}

	void BouncyBlock::SetState( BouncyBlockState NewState )
	{
		SetState( NewState, false );
	}

	void BouncyBlock::SetState( BouncyBlockState NewState, bool ForceSet )
	{
		if ( State != NewState || ForceSet )
		{
			switch ( NewState )
			{
				case BouncyBlockState_REGULAR:
					if ( !getCore()->BoxesOnly )
						MyDraw->MyPieces->CalcTexture( 0, 0 );
					break;
				case BouncyBlockState_SUPER_STIFF:
					if ( !getCore()->BoxesOnly )
						MyDraw->MyPieces->CalcTexture( 0, 1 );
					break;
			}
		}

		State = NewState;
	}

	BouncyBlock::BouncyBlock( bool BoxesOnly )
	{
		InitializeInstanceFields();
		MyBox = boost::make_shared<AABox>();
		MyDraw = boost::make_shared<NormalBlockDraw>();

		MakeNew();

		getCore()->BoxesOnly = BoxesOnly;
	}

	void BouncyBlock::Init( Vector2 center, Vector2 size, float speed, const boost::shared_ptr<Level> &level )
	{
		Active = true;

		this->speed = speed;

		getBlockCore()->Layer = .35f;

		BlockBase::Init( center, size, level, level->getInfo()->BouncyBlocks->Group );

		SetState( BouncyBlockState_REGULAR, true );

		Update();
	}

	void BouncyBlock::Snap( const boost::shared_ptr<Bob> &bob )
	{
		TouchedCountdown = 3;

		if ( Offset.X != 0 )
			bob->getCore()->Data.Velocity.X = 1.1f * speed * Offset.X * SideDampening;
		if ( Offset.Y != 0 )
		{
			bob->NewVel = speed * Offset.Y;
			bob->MyPhsx->OnGround = false;
			bob->MyPhsx->DisableJump( 5 );
			bob->MyPhsx->DampForcedJump();
		}

		float scale = 1.2f;
		Offset *= 42 * scale;
		SizeOffset = Vector2( 14 * scale );

		//Offset *= 52;
		//SizeOffset = new Vector2(18);

		SetState( BouncyBlockState_SUPER_STIFF );

        if ( getMyLevel()->PlayMode == 0 && getInfo()->BouncyBlocks->BounceSound != 0 )
            getInfo()->BouncyBlocks->BounceSound->Play();
	}

	void BouncyBlock::SideHit( const boost::shared_ptr<Bob> &bob )
	{
		Offset = Vector2( static_cast<float>( ::Sign( bob->getCore()->Data.Position.X - getCore()->Data.Position.X ) ), 0.f );
		bob->MyPhsx->Forced( Offset );

		Snap( bob );
	}

	void BouncyBlock::LandedOn( const boost::shared_ptr<Bob> &bob )
	{
		bob->MyPhsx->OverrideSticky = true;

		Offset = Vector2( 0, 1 );
		bob->MyPhsx->Forced( Offset );

		bob->MyPhsx->MaxJumpAccelMultiple = 2.5f;
		bob->MyPhsx->JumpLengthModifier = .85f;
		Snap( bob );
	}

	void BouncyBlock::HitHeadOn( const boost::shared_ptr<Bob> &bob )
	{
		bob->MyPhsx->KillJump();
		Offset = Vector2( 0, -1 );
		bob->MyPhsx->Forced( Offset );

		Snap( bob );
	}

	void BouncyBlock::Reset( bool BoxesOnly )
	{
		BlockBase::Reset( BoxesOnly );

		Active = true;

		Offset = Vector2();
		SizeOffset = Vector2();

		SetState( BouncyBlockState_REGULAR, true );

		getBlockCore()->Data = getBlockCore()->StartData;

		MyBox->Current->Center = getBlockCore()->StartData.Position;

		MyBox->SetTarget( MyBox->Current->Center, MyBox->Current->Size );
		MyBox->SwapToCurrent();

		Update();
	}

	void BouncyBlock::PhsxStep()
	{
		Active = getCore()->Active = true;
		if ( !getCore()->Held )
		{
			if ( MyBox->Current->BL.X > getBlockCore()->MyLevel->getMainCamera()->TR.X || MyBox->Current->BL.Y > getBlockCore()->MyLevel->getMainCamera()->TR.Y + 50 )
				Active = getCore()->Active = false;
			if ( MyBox->Current->TR.X < getBlockCore()->MyLevel->getMainCamera()->BL.X || MyBox->Current->TR.Y < getBlockCore()->MyLevel->getMainCamera()->BL.Y - 150 )
				Active = getCore()->Active = false;
		}

		Update();

		//if (!Core.BoxesOnly)
		//{
		//    if ((Pos - MyLevel.Bobs[0].Pos).Length() > 500)
		//        MyDraw.MyPieces.CalcTexture(0, 2);
		//    else
		//        //if (MyDraw.MyPieces.t > 0)
		//            MyDraw.MyPieces.CalcTexture(0, 0);
		//}

		if ( TouchedCountdown == 0 )
		{
			Offset *= .5f;
			SizeOffset *= .5f;
		}
		else
			TouchedCountdown--;

		// Update the block's apparent center according to attached objects
		getBlockCore()->UseCustomCenterAsParent = true;
		getBlockCore()->CustomCenterAsParent = getBox()->Target->Center + Offset;
		getBlockCore()->OffsetMultAsParent = Vector2(1) + SizeOffset / getBox()->Current->Size;

		if ( SizeOffset.X < .1f && State == BouncyBlockState_SUPER_STIFF )
			SetState( BouncyBlockState_REGULAR );

		MyBox->SetTarget( getCore()->Data.Position, MyBox->Current->Size );

		getBlockCore()->StoodOn = false;
	}

	void BouncyBlock::PhsxStep2()
	{
		if ( !Active )
			return;

		MyBox->SwapToCurrent();
	}

	void BouncyBlock::Update()
	{
		if ( getBlockCore()->BoxesOnly )
			return;
	}

	void BouncyBlock::Extend( Side side, float pos )
	{
		switch ( side )
		{
			case Side_LEFT:
				MyBox->Target->BL.X = pos;
				break;
			case Side_RIGHT:
				MyBox->Target->TR.X = pos;
				break;
			case Side_TOP:
				MyBox->Target->TR.Y = pos;
				break;
			case Side_BOTTOM:
				MyBox->Target->BL.Y = pos;
				break;
		}

		MyBox->Target->FromBounds();
		MyBox->SwapToCurrent();

		Update();

		getBlockCore()->StartData.Position = MyBox->Current->Center;
	}

	void BouncyBlock::Move( Vector2 shift )
	{
		getBlockCore()->Data.Position += shift;
		getBlockCore()->StartData.Position += shift;

		getBox()->Move(shift);

		Update();
	}

	void BouncyBlock::Draw()
	{
		Update();

		if ( Tools::DrawBoxes )
		{
			//MyBox.Draw(Tools::QDrawer, Color.Olive, 15);
			MyBox->DrawFilled( Tools::QDrawer, Color::SpringGreen );
		}

		if ( Tools::DrawGraphics )
		{
			if ( !getBlockCore()->BoxesOnly )
			{
				//MyDraw.MyPieces.Center.MyEffect = Tools::EffectWad.FindByName("Hsl");
				MyDraw->Update();
				MyDraw->MyPieces->Base.Origin += Offset;
				//MyDraw.MyPieces.Base.Origin += Offset
				//    + new Vector2(MyLevel.Rnd.Rnd.Next(-10, 10), MyLevel.Rnd.Rnd.Next(-10, 10)); ;

				MyDraw->Draw();
			}
		}

		getBlockCore()->Draw();
	}

	void BouncyBlock::Clone( const boost::shared_ptr<ObjectBase> &A )
	{
		getCore()->Clone(A->getCore());

		boost::shared_ptr<BouncyBlock> BlockA = boost::dynamic_pointer_cast<BouncyBlock>( A );

		Init( BlockA->getBox()->Current->Center, BlockA->getBox()->Current->Size, BlockA->speed, BlockA->getMyLevel() );

		SideDampening = BlockA->SideDampening;

		State = BlockA->State;
	}

	void BouncyBlock::InitializeInstanceFields()
	{
		State = static_cast<BouncyBlockState>( 0 );
		speed = 0;
		TouchedCountdown = 0;
		SideDampening = 0;
		TouchedCountdown = 0;
	}
}
