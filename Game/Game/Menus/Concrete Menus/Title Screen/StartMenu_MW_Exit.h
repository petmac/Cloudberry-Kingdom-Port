#ifndef STARTMENU_MW_EXIT
#define STARTMENU_MW_EXIT

#include <small_header.h>

#include "Game/Menus/Concrete Menus/Title Screen/Sub Menus/VerifyQuitGame.h"


namespace CloudberryKingdom
{
	struct StartMenu_MW_Exit : public VerifyQuitGameMenu2
	{

		virtual ~StartMenu_MW_Exit()
		{
#ifdef BOOST_BIN
			OnDestructor( "StartMenu_MW_Exit" );
#endif
		}


		using VerifyQuitGameMenu2::SlideOut;
		using VerifyQuitGameMenu2::SlideIn;
		using VerifyQuitGameMenu2::Call;

		StartMenu_MW_Exit( int Control );
		boost::shared_ptr<StartMenu_MW_Exit> StartMenu_MW_Exit_Construct( int Control );

		virtual void SlideIn( int Frames );

		virtual void SlideOut( PresetPos Preset, int Frames );
	};
}


#endif	//#ifndef STARTMENU_MW_EXIT
