#ifndef STARTMENU_MW_BLACK
#define STARTMENU_MW_BLACK

#include <small_header.h>

//#include "Core/Graphics/Draw/DrawPile.h"
//#include "Core/Graphics/Draw/Quads/QuadClass.h"
#include "Game/Menus/CkBaseMenu.h"


namespace CloudberryKingdom
{
	struct StartMenu_MW_Black : public CkBaseMenu
	{

		virtual ~StartMenu_MW_Black()
		{
#ifdef BOOST_BIN
			OnDestructor( "StartMenu_MW_Black" );
#endif
		}


		using CkBaseMenu::SlideOut;
		using CkBaseMenu::SlideIn;
		using CkBaseMenu::Call;

		virtual void SlideIn( int Frames );

		virtual void SlideOut( PresetPos Preset, int Frames );

		virtual void OnAdd();

		StartMenu_MW_Black();
		boost::shared_ptr<StartMenu_MW_Black> StartMenu_MW_Black_Construct();

	
		boost::shared_ptr<QuadClass> Black;
	
		virtual void Init();

	
		void BlackBox();

	
		void SlideFromRight();

	
		virtual void MyPhsxStep();

	
		virtual void OnReturnTo();
	};
}


#endif	//#ifndef STARTMENU_MW_BLACK
