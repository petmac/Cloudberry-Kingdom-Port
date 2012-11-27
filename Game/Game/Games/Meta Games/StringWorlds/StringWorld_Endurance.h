﻿#ifndef STRINGWORLD_ENDURANCE
#define STRINGWORLD_ENDURANCE

#include <global_header.h>

namespace CloudberryKingdom
{
	class LevelSeedData;
}

namespace CloudberryKingdom
{
	class GUI_Score;
}

namespace CloudberryKingdom
{
	class GUI_Level;
}

namespace CloudberryKingdom
{
	class GUI_LivesLeft;
}

namespace CloudberryKingdom
{
	class GUI_Lives;
}

namespace CloudberryKingdom
{
	class GUI_NextLife;
}

namespace CloudberryKingdom
{
	class CoinScoreMultiplierObject;
}

namespace CloudberryKingdom
{
	class GameData;
}


namespace CloudberryKingdom
{
	class StringWorldEndurance : public StringWorldGameData
	{
	private:
		class OnSwapLambda : public Lambda_1<LevelSeedData*>
		{
		private:
			std::shared_ptr<StringWorldEndurance> ch;
		public:
			OnSwapLambda( const std::shared_ptr<StringWorldEndurance> &ch );

			void Apply( const std::shared_ptr<LevelSeedData> &data );
		};

	private:
		std::shared_ptr<GUI_Score> MyGUI_Score;
		std::shared_ptr<GUI_Level> MyGUI_Level;

		std::shared_ptr<GUI_LivesLeft> Gui_LivesLeft;
		std::shared_ptr<GUI_Lives> Gui_Lives;
		std::shared_ptr<GUI_NextLife> Gui_NextLife;
		std::shared_ptr<CoinScoreMultiplierObject> MyCoinScoreMultiplier;

	public:
		StringWorldEndurance( const std::shared_ptr<LambdaFunc_1<int, LevelSeedData*> > &GetSeed, const std::shared_ptr<GUI_LivesLeft> &Gui_LivesLeft, int NextLife );

		virtual void Release();

		virtual void AdditionalSwapToLevelProcessing( const std::shared_ptr<GameData> &game );
	};
}


#endif	//#ifndef STRINGWORLD_ENDURANCE