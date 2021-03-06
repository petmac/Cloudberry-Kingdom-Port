#ifndef GUI_TIMER
#define GUI_TIMER

#include <small_header.h>

//#include "Core/Tools/CoreMath.h"
//#include "Game/Objects/ObjectBase.h"
//#include "Game/Objects/Game Objects/GameObject.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Timer_Base.h"
//#include "Game/Objects/In Game Objects/Grab/MakeData.h"
//#include "Game/Level/Level.h"


namespace CloudberryKingdom
{

	struct GUI_Timer : public GUI_Timer_Base
	{

		virtual ~GUI_Timer()
		{
#ifdef BOOST_BIN
			OnDestructor( "GUI_Timer" );
#endif
		}


		struct OnCoinGrabProxy : public Lambda_1<boost::shared_ptr<ObjectBase> >
		{
		
			boost::shared_ptr<GUI_Timer> timer;

		
			OnCoinGrabProxy( const boost::shared_ptr<GUI_Timer> &timer );

			void Apply( const boost::shared_ptr<ObjectBase> &obj );
		};

	
		struct OnCompleteLevelProxy : public Lambda_1<boost::shared_ptr<Level> >
		{
		
			boost::shared_ptr<GUI_Timer> timer;

		
			OnCompleteLevelProxy( const boost::shared_ptr<GUI_Timer> &timer );

			void Apply( const boost::shared_ptr<Level> &level );
		};

		virtual void OnAdd();

		virtual void ReleaseBody();
	
		int CoinTimeValue, MinLevelStartTimeValue;
		int MaxTime;
		void OnCoinGrab( const boost::shared_ptr<ObjectBase> &obj );

		void OnCompleteLevel( const boost::shared_ptr<Level> &level );

	
		void InitializeInstanceFields();


		GUI_Timer();
		boost::shared_ptr<GUI_Timer> GUI_Timer_Construct();
	};

}


#endif	//#ifndef GUI_TIMER
