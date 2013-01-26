#include <global_header.h>

#include <Hacks/List.h>
#include <Hacks/String.h>

#include <MasterHack.h>

#include <Core\Tools\Set.h>

#include <Game/CloudberryKingdom/CloudberryKingdom.CloudberryKingdomGame.h>

namespace CloudberryKingdom
{

    boost::shared_ptr<Awardment> Awardments::Award_Campaign1;
    boost::shared_ptr<Awardment> Awardments::Award_ArcadeHighScore;
    boost::shared_ptr<Awardment> Awardments::Award_Bungee;
    boost::shared_ptr<Awardment> Awardments::Award_ArcadeHighScore2;
    boost::shared_ptr<Awardment> Awardments::Award_Die;
    boost::shared_ptr<Awardment> Awardments::Award_Campaign3;
    boost::shared_ptr<Awardment> Awardments::Award_Invisible;
    boost::shared_ptr<Awardment> Awardments::Award_Hats;
    boost::shared_ptr<Awardment> Awardments::Award_Campaign2;
    boost::shared_ptr<Awardment> Awardments::Award_UnlockAllArcade;
    boost::shared_ptr<Awardment> Awardments::Award_NoDeath;
    boost::shared_ptr<Awardment> Awardments::Award_Save;
    boost::shared_ptr<Awardment> Awardments::Award_Obstacles;
    boost::shared_ptr<Awardment> Awardments::Award_Buy;
    boost::shared_ptr<Awardment> Awardments::Award_Campaign4;
    boost::shared_ptr<Awardment> Awardments::Award_BuyHat;
    boost::shared_ptr<Awardment> Awardments::Award_HeroRush2Level;
    boost::shared_ptr<Awardment> Awardments::Award_Replay;
    boost::shared_ptr<Awardment> Awardments::Award_Campaign5;

    boost::shared_ptr<Awardment> Awardments::UnlockTimeCrisis;
    boost::shared_ptr<Awardment> Awardments::UnlockHeroRush;
    boost::shared_ptr<Awardment> Awardments::UnlockHeroRush2;

    std::wstring Awardment::NewGameMode;
    std::wstring Awardment::Default;

	void Awardments::InitializeStatics()
	{
        Awardment::NewGameMode = L"New Game Mode";
        Awardment::Default = L"Awardment";

        Award_Campaign1 = boost::make_shared<Awardment>( 1, Localization::Words_AwardTitle_Campaign1, Localization::Words_AwardText_Campaign1);
        Award_ArcadeHighScore = boost::make_shared<Awardment>( 2, Localization::Words_AwardTitle_ArcadeHighScore, Localization::Words_AwardText_ArcadeHighScore);
        Award_Bungee = boost::make_shared<Awardment>( 3, Localization::Words_AwardTitle_Bungee, Localization::Words_AwardText_Bungee);
        Award_ArcadeHighScore2 = boost::make_shared<Awardment>( 4, Localization::Words_AwardTitle_ArcadeHighScore2, Localization::Words_AwardText_ArcadeHighScore2);
        Award_Die = boost::make_shared<Awardment>( 5, Localization::Words_AwardTitle_Die, Localization::Words_AwardText_Die);
        Award_Campaign3 = boost::make_shared<Awardment>( 6, Localization::Words_AwardTitle_Campaign3, Localization::Words_AwardText_Campaign3);
        Award_Invisible = boost::make_shared<Awardment>( 7, Localization::Words_AwardTitle_Invisible, Localization::Words_AwardText_Invisible);
        Award_Hats = boost::make_shared<Awardment>( 8, Localization::Words_AwardTitle_Hats, Localization::Words_AwardText_Hats);
        Award_Campaign2 = boost::make_shared<Awardment>( 9, Localization::Words_AwardTitle_Campaign2, Localization::Words_AwardText_Campaign2);
        Award_UnlockAllArcade = boost::make_shared<Awardment>( 10, Localization::Words_AwardTitle_UnlockAllArcade, Localization::Words_AwardText_UnlockAllArcade);
        Award_NoDeath = boost::make_shared<Awardment>( 11, Localization::Words_AwardTitle_NoDeath, Localization::Words_AwardText_NoDeath);
        Award_Save = boost::make_shared<Awardment>( 12, Localization::Words_AwardTitle_Save, Localization::Words_AwardText_Save);
        Award_Obstacles = boost::make_shared<Awardment>( 13, Localization::Words_AwardTitle_Obstacles, Localization::Words_AwardText_Obstacles);
        Award_Buy = boost::make_shared<Awardment>( 14, Localization::Words_AwardTitle_Buy, Localization::Words_AwardText_Buy);
        Award_Campaign4 = boost::make_shared<Awardment>( 15, Localization::Words_AwardTitle_Campaign4, Localization::Words_AwardText_Campaign4);
        Award_BuyHat = boost::make_shared<Awardment>( 16, Localization::Words_AwardTitle_BuyHat, Localization::Words_AwardText_BuyHat);
        Award_HeroRush2Level = boost::make_shared<Awardment>( 17, Localization::Words_AwardTitle_HeroRush2Level, Localization::Words_AwardText_HeroRush2Level);
        Award_Replay = boost::make_shared<Awardment>( 18, Localization::Words_AwardTitle_Replay, Localization::Words_AwardText_Replay);
        Award_Campaign5 = boost::make_shared<Awardment>( 19, Localization::Words_AwardTitle_Campaign5, Localization::Words_AwardText_Campaign5);

        // Arcade Unlocks
        UnlockTimeCrisis = boost::make_shared<Awardment>(100, L"Time Crisis Unlocked!", 
            L"Fill me in!",
            Awardment::NewGameMode, false);

        UnlockHeroRush = boost::make_shared<Awardment>(101, L"Hero Rush unlocked!",
            L"Fill me in!",
            Awardment::NewGameMode, false);

        UnlockHeroRush2 = boost::make_shared<Awardment>(102, L"Hero Rush 2 unlocked!",
            L"Fill me in!",
            Awardment::NewGameMode, false);

        Awardment_PostConstruct( Award_Campaign1 );
		Awardment_PostConstruct( Award_ArcadeHighScore );
		Awardment_PostConstruct( Award_Bungee );
		Awardment_PostConstruct( Award_ArcadeHighScore2 );
		Awardment_PostConstruct( Award_Die );
		Awardment_PostConstruct( Award_Campaign3 );
		Awardment_PostConstruct( Award_Invisible );
		Awardment_PostConstruct( Award_Hats );
		Awardment_PostConstruct( Award_Campaign2 );
		Awardment_PostConstruct( Award_UnlockAllArcade );
		Awardment_PostConstruct( Award_NoDeath );
		Awardment_PostConstruct( Award_Save );
		Awardment_PostConstruct( Award_Obstacles );
		Awardment_PostConstruct( Award_Buy );
		Awardment_PostConstruct( Award_Campaign4 );
		Awardment_PostConstruct( Award_BuyHat );
		Awardment_PostConstruct( Award_HeroRush2Level );
		Awardment_PostConstruct( Award_Replay );
		Awardment_PostConstruct( Award_Campaign5 );
	}

	// Statics
	std::vector<boost::shared_ptr<Awardment> > Awardments::Awards;
	std::map<int, boost::shared_ptr<Awardment> > Awardments::AwardsDict;


    Awardment::Awardment(int Guid, Localization::Words Name, Localization::Words Description)
    {
        Official = true;
#if defined(XBOX)
        ShowWhenAwarded = false;
#else
        ShowWhenAwarded = true;
#endif

        this->Name = Name;
        this->Description = Description;
        this->Unlockable = Unlockable;
        this->Guid = Guid;
        this->TitleType = Default;
    }

    //Awardment(int Guid, Localization.Words Name, Localization.Words Description, string TitleType, bool ShowWhenAwarded)
	Awardment::Awardment(int Guid, std::wstring Name, std::wstring Description, std::wstring TitleType, bool ShowWhenAwarded)
    {
        Official = false;

        //this->Name = Name;
        //this->Description = Description;
        this->Name = Localization::Words_None;;
        this->Description = Localization::Words_None;

        this->Unlockable = Unlockable;
        this->Guid = Guid;
        this->TitleType = TitleType;
        this->ShowWhenAwarded = ShowWhenAwarded;
    }		

	bool Awardments::MessageOnScreen()
	{
		for ( GameObjVec::const_iterator obj = Tools::CurGameData->MyGameObjects.begin(); obj != Tools::CurGameData->MyGameObjects.end(); ++obj )
		{
			if ( boost::dynamic_pointer_cast<AwardmentMessage>( *obj ) != 0 )
				return true;
		}

		return false;
	}

	int Awardments::AwardDelay()
	{
		if ( MessageOnScreen() )
			return 160;
		else
			return 0;
	}


        void Awardments::CheckForAward_TimeCrisisUnlock(int Level, boost::shared_ptr<PlayerData> player)
        {
            if (Level >= UnlockTimeCrisis->MyInt)
                GiveAward(UnlockTimeCrisis, player);
        }

        void Awardments::CheckForAward_HeroRushUnlock(int Level, boost::shared_ptr<PlayerData> player)
        {
            if (Level >= UnlockHeroRush->MyInt)
                GiveAward(UnlockHeroRush, player);
        }

        void Awardments::CheckForAward_HeroRush2Unlock(int Level, boost::shared_ptr<PlayerData> player)
        {
            if (Level >= UnlockHeroRush2->MyInt)
            {
                GiveAward(UnlockHeroRush2, player);
                CheckForAward_UnlockAllArcade();
            }
        }

        void Awardments::CheckForAward_HeroRush2_Level(int Level)
        {
            if (Level >= 50)
                GiveAward(Awardments::Award_HeroRush2Level);
        }

        void Awardments::CheckForAward_ArcadeScore(int Score)
        {
            if (Score >= 500000)
                GiveAward(Awardments::Award_ArcadeHighScore);
        }

        void Awardments::CheckForAward_ArcadeScore2(int Score)
        {
            if (Score >= 1500000)
                GiveAward(Awardments::Award_ArcadeHighScore2);
        }

        void Awardments::CheckForAward_Invisible(int Level)
        {
            if (Level < 20) return;

            if (PlayerManager::TotallyInvisible)
                GiveAward(Award_Invisible);
        }

        void Awardments::CheckForAward_Die(boost::shared_ptr<Bob> bob)
        {
            int deaths = bob->getMyStats()->getTotalDeaths() + PlayerManager::Get(bob)->GameStats->getTotalDeaths() + PlayerManager::Get(bob)->LifetimeStats->getTotalDeaths();
            if (deaths >= 1337)
                GiveAward(Award_Die);
        }

        void Awardments::CheckForAward_NoDeath(boost::shared_ptr<PlayerData> player)
        {
            int deaths = player->CampaignStats->getTotalDeaths();
            if (deaths == 0)
                GiveAward(Award_NoDeath, player);
        }

        void Awardments::CheckForAward_UnlockAllArcade()
        {
            GiveAward(Award_UnlockAllArcade);
        }

        void Awardments::CheckForAward_Save()
        {
            GiveAward(Award_Save);
        }

        void Awardments::CheckForAward_Obstacles(boost::shared_ptr<Bob> bob)
        {
            int obstacles = bob->getMyStats()->ObstaclesSeen + PlayerManager::Get(bob)->GameStats->ObstaclesSeen + PlayerManager::Get(bob)->LifetimeStats->ObstaclesSeen;

            if (obstacles >= 1000)
                GiveAward(Award_Obstacles);
        }

        void Awardments::CheckForAward_Buy()
        {
            GiveAward(Award_Buy);
        }

        void Awardments::CheckForAward_Replay(int Attempts)
        {
            if (Attempts >= 50)
                GiveAward(Award_Replay);
        }

        void Awardments::CheckForAward_Bungee(boost::shared_ptr<GameData> game)
        {
            if (game == 0) return;
            if (game->MyLevel == 0) return;
            if (game->MyLevel->MyLevelSeed == 0) return;

            if (game->MyLevel->MyLevelSeed->MyGameFlags.IsTethered &&
                PlayerManager::NumPlayers > 3)
            {
                int AliveCount = 0;
				for ( BobVec::const_iterator bob = game->MyLevel->Bobs.begin(); bob != game->MyLevel->Bobs.end(); ++bob )
                {
                    if (!( *bob )->Dead && !( *bob )->Dying)
                        AliveCount++;
                }

                if (AliveCount != 1) return;

				for ( BobVec::const_iterator bob = game->MyLevel->Bobs.begin(); bob != game->MyLevel->Bobs.end(); ++bob )
                    if (!( *bob )->Dead && !( *bob )->Dying)
                        GiveAward(Award_Bungee, ( *bob )->getMyPlayerData() );
            }
        }

        void Awardments::GiveAward( const boost::shared_ptr<Awardment> &award )
        {
            GiveAward(award, 0);
        }
        void Awardments::GiveAward( const boost::shared_ptr<Awardment> &award, const boost::shared_ptr<PlayerData> player)
        {
            if (CloudberryKingdomGame::getIsDemo()) return;

            if (award == 0) return;

            if ( player == 0 && PlayerManager::NotAllAwarded(award) ||
                 player != 0 && !player->Awardments_Renamed->Has( award->Guid ) )
            {
                // Give the award to each player, or to the specified player
                if (player == 0)
                {
					std::vector<boost::shared_ptr<PlayerData> > vec = PlayerManager::getExistingPlayers();
					for ( std::vector<boost::shared_ptr<PlayerData> >::const_iterator p = vec.begin(); p != vec.end(); ++p )
                        ( *p )->Awardments_Renamed->Add( award->Guid );
                }
                else
                    player->Awardments_Renamed->Add( award->Guid );

                // Show a note saying the reward was given
                if (award->ShowWhenAwarded)
                {
                    boost::shared_ptr<AwardmentMessage> msg = MakeMagic( AwardmentMessage, ( award ) );
                    Tools::CurGameData->AddGameObject(msg);

					// Remove all other hints
					for ( GameObjVec::const_iterator obj = Tools::CurGameData->MyGameObjects.begin(); obj != Tools::CurGameData->MyGameObjects.end(); ++obj )
					{
						if ( *obj == msg )
							continue;

						boost::shared_ptr<AwardmentMessage> _msg = boost::dynamic_pointer_cast<AwardmentMessage>( *obj );
						if ( 0 != _msg )
							_msg->MyPile->setPos( _msg->MyPile->getPos() + Vector2(0, Shift) );
					}
                }

                PlayerManager::SavePlayerData->Changed = true;
            }
        }

	float Awardments::CurShift = 0, Awardments::Shift = 520;

	void Awardments::Init()
	{
        UnlockTimeCrisis->MyInt = TimeCrisis_LevelUnlock;
        UnlockHeroRush->MyInt = HeroRush_LevelUnlock;
        UnlockHeroRush2->MyInt = HeroRush2_LevelUnlock;

		for ( std::vector<boost::shared_ptr<Awardment> >::const_iterator award = Awards.begin(); award != Awards.end(); ++award )
			AwardsDict.insert( std::make_pair( ( *award )->Guid, *award ) );
	}
}
