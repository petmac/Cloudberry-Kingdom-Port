#ifndef PRESSNOTE
#define PRESSNOTE

#include <small_header.h>

//#include "Core/Graphics/Draw/Quads/QuadClass.h"
//#include "Game/Localization.h"
//#include "Core/Input/ButtonCheck.h"
//#include "Core/Text/EzText.h"
//#include "Core/Tools/ColorHelper.h"
//#include "Game/Objects/Door/Door.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Text.h"
//#include "Game/Objects/In Game Objects/Grab/MakeData.h"
//#include "Game/Level/Level.h"


namespace CloudberryKingdom
{

	struct PressNote : public GUI_Text
	{

		virtual ~PressNote()
		{
#ifdef BOOST_BIN
			OnDestructor( "PressNote" );
#endif
		}

	
		static const int ButtonScale = 87;
		static const float TextScale;

	
		boost::shared_ptr<Door> Parent;

		PressNote( const boost::shared_ptr<Door> &Parent );
		boost::shared_ptr<PressNote> PressNote_Construct( const boost::shared_ptr<Door> &Parent );
	
		int Life;
	
		int LifeSpeed; //9;
		void FadeIn();

		int DelayToFadeOut; //80;
	
		int Count;
	
		void FadeOut();

		virtual void MyPhsxStep();
	
		virtual void Draw();
	
		void InitializeInstanceFields();

	};

}


#endif	//#ifndef PRESSNOTE
