#include <small_header.h>
#include "Game/Menus/Concrete Menus/Help/HintGiver.h"

#include "Game/Localization.h"
#include "Core/Input/ButtonCheck.h"
#include "Core/Text/EzText.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Panel.h"
#include "Game/Player/PlayerManager.h"
#include "Game/Menus/Concrete Menus/Help/HintBlurb.h"
#include "Game/Objects/In Game Objects/Grab/MakeData.h"
#include "Game/Level/Level.h"

#include "Game/Games/GameType.h"

#include <Hacks/String.h>

namespace CloudberryKingdom
{

	int Hints::YForHelpNum = 0;

	void Hints::SetYForHelpNum( int val )
	{
		YForHelpNum = val;
		PlayerManager::SavePlayerData->Changed = true;
	}

	void Hints::IncrYForHelpNum()
	{
		YForHelpNum++;
		PlayerManager::SavePlayerData->Changed = true;
	}

	int Hints::QuickSpawnNum = 0;

	void Hints::SetQuickSpawnNum( int val )
	{
		QuickSpawnNum = val;
		PlayerManager::SavePlayerData->Changed = true;
	}

	void Hints::IncrQuickSpawnNum()
	{
		QuickSpawnNum++;
		PlayerManager::SavePlayerData->Changed = true;
	}

	boost::shared_ptr<HintGiver> Hints::CurrentGiver = 0;

	HintGiver::Check_QuickSpawnHelper::Check_QuickSpawnHelper( const boost::shared_ptr<HintGiver> &hg )
	{
		this->hg = hg;
	}

	void HintGiver::Check_QuickSpawnHelper::Apply()
	{
		boost::shared_ptr<HintBlurb> hint = MakeMagic( HintBlurb, () );
		hint->SetText( HintGiver::getQuickSpawnHint() );

		/*
		hint.MyPile.BackdropShift = new Vector2(166.6668f, -152.2223f);
		hint.MyPile.Backdrop.CalcQuads(new Vector2(855, 330));
		*/

		hg->Call( hint );
	}

	HintGiver::Check_YForHelpHelper::Check_YForHelpHelper( const boost::shared_ptr<HintGiver> &hg )
	{
		this->hg = hg;
	}

	void HintGiver::Check_YForHelpHelper::Apply()
	{
		if ( Hints::YForHelpNum > 10 )
			return;

		boost::shared_ptr<HintBlurb> hint = MakeMagic( HintBlurb, () );
		hint->SetText( HintGiver::getPowerupHint() );

		/*
		hint.MyPile.BackdropShift = new Vector2(169.4445f, -102.2223f);
		hint.MyPile.Backdrop.CalcQuads(new Vector2(855, 230));
		*/

		hg->Call( hint );
	}

	HintGiver::HintGiver() { }
	boost::shared_ptr<HintGiver> HintGiver::HintGiver_Construct()
	{
		GUI_Panel::GUI_Panel_Construct();

		Active = true;
		PauseOnPause = true;

		Hints::CurrentGiver =  boost::static_pointer_cast<HintGiver>( shared_from_this() );

		return boost::static_pointer_cast<HintGiver>( shared_from_this() );
	}

	void HintGiver::ReleaseBody()
	{
		GUI_Panel::ReleaseBody();

		if ( Hints::CurrentGiver.get() == this )
			Hints::CurrentGiver.reset();
	}

	void HintGiver::MyPhsxStep()
	{
		GUI_Panel::MyPhsxStep();

		if ( !Active )
			return;

		Check_YForHelp();
		Check_QuickSpawn();
	}

	void HintGiver::Check_QuickSpawn()
	{
#if CAFE
		if ( !ButtonTexture::UseGamepad ) return;
#endif

		boost::shared_ptr<Level> level = getCore()->MyLevel;

		// "Quickspawn"
		//int FirstHint = 12, SecondHint = 36, ThirdHint = 70;
		int FirstHint = 9, SecondHint = 20, ThirdHint = 40;
		//int FirstHint = 2, SecondHint = 4, ThirdHint = 6;
		if ( level->CurPhsxStep == 20 && level->PieceAttempts > FirstHint && Hints::QuickSpawnNum == 0 || level->CurPhsxStep == 20 && level->PieceAttempts > SecondHint && Hints::QuickSpawnNum == 1 || level->CurPhsxStep == 20 && level->PieceAttempts > ThirdHint && Hints::QuickSpawnNum == 2 )
		{
			Hints::IncrQuickSpawnNum();

			MyGame->WaitThenDo( 5, boost::make_shared<Check_QuickSpawnHelper>( boost::static_pointer_cast<HintGiver>( shared_from_this() ) ) );
		}
	}

	const std::wstring HintGiver::getQuickSpawnHint()
	{
	#if defined(PC_VERSION)
		return Format( Localization::WordString( Localization::Words_RespawnNoteKeyboard ).c_str(), ButtonString::KeyStr( ButtonCheck::Quickspawn_KeyboardKey->KeyboardKey, 85 ).c_str() );
		//return Format( _T( "Press %ls or %ls to respawn quickly!" ), ButtonString::KeyStr( ButtonCheck::Quickspawn_KeyboardKey->KeyboardKey, 85 ).c_str(), ButtonString::KeyStr( Keys_Space, 85 ).c_str() );
	#else
		return Format( Localization::WordString( Localization::Words_RespawnNoteGamepad ).c_str(), ButtonString::LeftBumper( 85 ).c_str(), ButtonString::RightBumper( 85 ).c_str() );
		//return Format( _T( "Hold %ls and %ls to respawn quickly!" ), ButtonString::LeftBumper( 85 ).c_str(), ButtonString::RightBumper( 85 ).c_str() );
	#endif
	}

	const std::wstring HintGiver::getPowerupHint()
	{
	#if defined(PC_VERSION)
		return Format( Localization::WordString( Localization::Words_PowerupNote ).c_str(), ButtonString::Y( 85 ).c_str() );
		//return Format( _T( "Press %ls or %ls for powerups!" ), ButtonString::Y( 85 ).c_str(), ButtonString::KeyStr( Keys_Enter, 85 ).c_str() );
	#else
		return Format( Localization::WordString( Localization::Words_PowerupNote ).c_str(), ButtonString::Y( 85 ).c_str() );
		//return Format( _T( "Press %ls for powerups!" ), ButtonString::Y( 85 ).c_str() );
	#endif
	}

	void HintGiver::Check_YForHelp()
	{
		boost::shared_ptr<Level> level = getCore()->MyLevel;

		// "Press (Y) for help"
		//int FirstHint = 24, SecondHint = 50, ThirdHint = 90;
		//int FirstHint = 18, SecondHint = 50, ThirdHint = 90;
		int FirstHint = 14, SecondHint = 27, ThirdHint = 60;
		if ( level->CurPhsxStep == 30 && level->PieceAttempts > FirstHint && Hints::YForHelpNum == 0 || level->CurPhsxStep == 30 && level->PieceAttempts > SecondHint && Hints::YForHelpNum == 1 || level->CurPhsxStep == 30 && level->PieceAttempts > ThirdHint && Hints::YForHelpNum == 2 )
		{
			Hints::IncrYForHelpNum();

			MyGame->WaitThenDo( 5, boost::make_shared<Check_YForHelpHelper>( boost::static_pointer_cast<HintGiver>( shared_from_this() ) ) );
		}
	}
}
