#include <global_header.h>



#if ! defined(PC_VERSION) && (defined(XBOX) || defined(XBOX_SIGNIN))

#endif

namespace CloudberryKingdom
{

	PlayerIntLambda::PlayerIntLambda()
	{
	}

	int PlayerIntLambda::Apply( const std::shared_ptr<PlayerData> &p )
	{
		return 0;
	}

bool UserPowers::CanSkipScreensaver = false;
std::shared_ptr<CloudberryKingdom::Set<std::wstring> > UserPowers::WatchedVideo = std::make_shared<Set<std::wstring> >();

	void UserPowers::Set( bool &variable, bool value )
	{
		variable = value;
		SetToSave();
	}

	void UserPowers::SetToSave()
	{
		PlayerManager::SavePlayerData->Changed = true;
	}

	_SavePlayerData::_SavePlayerData()
	{
	InitializeInstanceFields();
	#if defined(PC_VERSION)
		AlwaysSave = true;
	#endif
	}

	void _SavePlayerData::Serialize( const std::shared_ptr<BinaryWriter> &writer )
	{
		SaveLoad::Serialize( writer );

		Chunk::WriteSingle( writer, 0, UserPowers::CanSkipScreensaver );
		Chunk::WriteSingle( writer, 1, HeroRush_Tutorial::HasWatchedOnce );
		Chunk::WriteSingle( writer, 2, Hints::QuickSpawnNum );
		Chunk::WriteSingle( writer, 3, Hints::YForHelpNum );

		// Save the names of videos the user has already watched.
//C# TO C++ CONVERTER TODO TASK: There is no equivalent to implicit typing in C++ unless the C++11 inferred typing option is selected:
		for ( CloudberryKingdom::Set<std::wstring>::const_iterator video = UserPowers::WatchedVideo->begin(); video != UserPowers::WatchedVideo->end(); ++video )
			Chunk::WriteSingle( writer, 5, *video );
	}

	void _SavePlayerData::Deserialize( std::vector<unsigned char> Data )
	{
		for ( CloudberryKingdom::Chunks::const_iterator chunk = Chunks::Get( Data )->begin(); chunk != Chunks::Get(Data)->end(); ++chunk )
		{
			switch ( ( *chunk )->Type )
			{
				case 0:
					( *chunk )->ReadSingle( UserPowers::CanSkipScreensaver );
					break;
				case 1:
					( *chunk )->ReadSingle( HeroRush_Tutorial::HasWatchedOnce );
					break;
				case 2:
					( *chunk )->ReadSingle( Hints::QuickSpawnNum );
					break;
				case 3:
					( *chunk )->ReadSingle( Hints::YForHelpNum );
					break;

				// Load the names of videos the user has already watched.
				case 5:
					std::wstring VideoName = _T( "" );
					( *chunk )->ReadSingle( VideoName );
					UserPowers::WatchedVideo += VideoName;
					break;
			}
		}
	}

	void _SavePlayerData::InitializeInstanceFields()
	{
		ResolutionPreferenceSet = false;
	}

	PlayerManager::SaveRezAndKeysLambda::SaveRezAndKeysLambda()
	{
	}

	void PlayerManager::SaveRezAndKeysLambda::Apply( const std::shared_ptr<BinaryWriter> &writer )
	{
		PlayerManager::_SaveRezAndKeys( writer );
	}

	PlayerManager::LoadRezAndKeysLambda::LoadRezAndKeysLambda()
	{
	}

	void PlayerManager::LoadRezAndKeysLambda::Apply( std::vector<unsigned char> Data )
	{
		PlayerManager::_LoadRezAndKeys( Data );
	}

	float PlayerManager::GetGroupGamerTagNameLength::Apply( const std::shared_ptr<StringBuilder> &name )
	{
		return name->Length;
	}

	PlayerManager::AnyAwardmentLambda::AnyAwardmentLambda( const std::shared_ptr<Awardment> &award )
	{
		this->award = award;
	}

	bool PlayerManager::AnyAwardmentLambda::Apply( const std::shared_ptr<PlayerData> &player )
	{
		return player->Awardments_Renamed[ award->Guid ];
	}

	PlayerManager::AnyBoughtLambda::AnyBoughtLambda( const std::shared_ptr<Buyable> &item )
	{
		this->item = item;
	}

	bool PlayerManager::AnyBoughtLambda::Apply( const std::shared_ptr<PlayerData> &player )
	{
		return player->Purchases[ item->GetGuid() ];
	}

	int PlayerManager::BankLambda::Apply( const std::shared_ptr<PlayerData> &p )
	{
		return p->Bank();
	}

	PlayerManager::NotAllAwardedLambda::NotAllAwardedLambda( const std::shared_ptr<Awardment> &award )
	{
		this->award = award;
	}

	bool PlayerManager::NotAllAwardedLambda::Apply( const std::shared_ptr<PlayerData> &player )
	{
		return !player->Awardments_Renamed[ award->Guid ];
	}

	PlayerManager::ExistingPlayerFindLambda::ExistingPlayerFindLambda()
	{
	}

	bool PlayerManager::ExistingPlayerFindLambda::Apply( const std::shared_ptr<PlayerData> &player )
	{
		return player->getMyGamer() != 0 || player->StoredName.length() > 0;
	}

#if defined(PC_VERSION)
	void PlayerManager::SaveRezAndKeys()
	{
		EzStorage::Save( _T( "Settings" ), _T( "Custom" ), std::make_shared<SaveRezAndKeysLambda>(), 0 );
	}
#endif

#if defined(PC_VERSION)
	void PlayerManager::_SaveRezAndKeys( const std::shared_ptr<BinaryWriter> &writer )
	{
		Chunk::WriteSingle( writer, 0, SavePlayerData->ResolutionPreferenceSet );

		// Fullscreen
		Chunk::WriteSingle( writer, 1, Tools::getFullscreen() );

		// Resolution
		if ( ResolutionGroup::LastSetMode == 0 )
		{
			Chunk::WriteSingle( writer, 2, Tools::TheGame->MyGraphicsDeviceManager->PreferredBackBufferWidth );
			Chunk::WriteSingle( writer, 3, Tools::TheGame->MyGraphicsDeviceManager->PreferredBackBufferHeight );
		}
		else
		{
			Chunk::WriteSingle( writer, 2, ResolutionGroup::LastSetMode->Width );
			Chunk::WriteSingle( writer, 3, ResolutionGroup::LastSetMode->Height );
		}

		// Secondary keys
		Chunk::WriteSingle( writer, 4, ButtonCheck::Quickspawn_KeyboardKey->KeyboardKey );
		Chunk::WriteSingle( writer, 5, ButtonCheck::Start_Secondary );
		Chunk::WriteSingle( writer, 6, ButtonCheck::Go_Secondary );
		Chunk::WriteSingle( writer, 7, ButtonCheck::Back_Secondary );
		Chunk::WriteSingle( writer, 8, ButtonCheck::ReplayPrev_Secondary );
		Chunk::WriteSingle( writer, 9, ButtonCheck::ReplayNext_Secondary );
		Chunk::WriteSingle( writer,10, ButtonCheck::SlowMoToggle_Secondary );
		Chunk::WriteSingle( writer,11, ButtonCheck::Left_Secondary );
		Chunk::WriteSingle( writer,12, ButtonCheck::Right_Secondary );
		Chunk::WriteSingle( writer,13, ButtonCheck::Up_Secondary );
		Chunk::WriteSingle( writer,14, ButtonCheck::Down_Secondary );

		// Volume
		Chunk::WriteSingle( writer, 15, Tools::MusicVolume->getVal() );
		Chunk::WriteSingle( writer, 16, Tools::SoundVolume->getVal() );

		// Fixed time step setting
		Chunk::WriteSingle( writer, 17, Tools::FixedTimeStep );

		// Bordered window
		Chunk::WriteSingle( writer, 18, Tools::WindowBorder );
	}
#endif

#if defined(PC_VERSION)
RezData PlayerManager::d = 0;
#endif

#if defined(PC_VERSION)
	CloudberryKingdom::PlayerManager::RezData PlayerManager::LoadRezAndKeys()
	{
		EzStorage::Load( _T( "Settings" ), _T( "Custom" ), std::make_shared<LoadRezAndKeysLambda>(), 0 );

		return d;
	}
#endif

#if defined(PC_VERSION)
	void PlayerManager::_LoadRezAndKeys( std::vector<unsigned char> Data )
	{
		d = RezData();

		for ( CloudberryKingdom::Chunks::const_iterator chunk = Chunks::Get( Data )->begin(); chunk != Chunks::Get(Data)->end(); ++chunk )
		{
			switch ( ( *chunk )->Type )
			{
				case 0:
					( *chunk )->ReadSingle( d.Custom );
					break;

				// Fullscreen
				case 1:
					( *chunk )->ReadSingle( d.Fullscreen );
					break;

				// Resolution
				case 2:
					( *chunk )->ReadSingle( d.Width );
					break;
				case 3:
					( *chunk )->ReadSingle( d.Height );
					break;

				// Secondary keys
				case 4:
					( *chunk )->ReadSingle( ButtonCheck::Quickspawn_KeyboardKey->KeyboardKey );
					break;
				case 5:
					( *chunk )->ReadSingle( ButtonCheck::Start_Secondary );
					break;
				case 6:
					( *chunk )->ReadSingle( ButtonCheck::Go_Secondary );
					break;
				case 7:
					( *chunk )->ReadSingle( ButtonCheck::Back_Secondary );
					break;
				case 8:
					( *chunk )->ReadSingle( ButtonCheck::ReplayPrev_Secondary );
					break;
				case 9:
					( *chunk )->ReadSingle( ButtonCheck::ReplayNext_Secondary );
					break;
				case 10:
					( *chunk )->ReadSingle( ButtonCheck::SlowMoToggle_Secondary );
					break;
				case 11:
					( *chunk )->ReadSingle( ButtonCheck::Left_Secondary );
					break;
				case 12:
					( *chunk )->ReadSingle( ButtonCheck::Right_Secondary );
					break;
				case 13:
					( *chunk )->ReadSingle( ButtonCheck::Up_Secondary );
					break;
				case 14:
					( *chunk )->ReadSingle( ButtonCheck::Down_Secondary );
					break;

				// Volume
				case 15:
					Tools::MusicVolume->setVal( ( *chunk )->ReadFloat() );
					break;
				case 16:
					Tools::SoundVolume->setVal( ( *chunk )->ReadFloat() );
					break;

				// Fixed time step setting
				case 17:
					( *chunk )->ReadSingle( Tools::FixedTimeStep );
					break;

				// Bordered window
				case 18:
					( *chunk )->ReadSingle( Tools::WindowBorder );
					break;
			}
		}
	}
#endif

bool PartiallyInvisible, PlayerManager::TotallyInvisible = false;
int PlayerManager::_CoinsSpent = 0;

	const int &PlayerManager::getCoinsSpent()
	{
		return _CoinsSpent;
	}

	void PlayerManager::setCoinsSpent( const int &value )
	{
		_CoinsSpent = value;
	}

std::shared_ptr<_SavePlayerData> PlayerManager::SavePlayerData = 0;
#if defined(PC_VERSION)
std::wstring PlayerManager::_DefaultName = _T( "" );
#endif

#if defined(PC_VERSION)
	const std::wstring &PlayerManager::getDefaultName()
	{
		return _DefaultName;
	}
#endif

#if defined(PC_VERSION)
	void PlayerManager::setDefaultName( const std::wstring &value )
	{
		if ( value.compare( _DefaultName ) != 0 )
			SavePlayerData->Changed = true;
		_DefaultName = value;
	}
#endif

	void PlayerManager::CleanTempStats()
	{
		for ( int i = 0; i < 4; i++ )
			Get( i )->TempStats->Clean();
	}

	void PlayerManager::AbsorbTempStats()
	{
		for ( int i = 0; i < 4; i++ )
		{
			Get( i )->LevelStats->Absorb( Get( i )->TempStats );
			Get( i )->TempStats->Clean();
		}
	}

	void PlayerManager::AbsorbLevelStats()
	{
		for ( int i = 0; i < 4; i++ )
		{
			Get( i )->GameStats->Absorb( Get( i )->LevelStats );
			Get( i )->LevelStats->Clean();
		}
	}

	void PlayerManager::AbsorbGameStats()
	{
		for ( int i = 0; i < 4; i++ )
		{
			Get( i )->LifetimeStats->Absorb( Get( i )->GameStats );
			Get( i )->CampaignStats->Absorb( Get( i )->GameStats );
			Get( i )->GameStats->Clean();
		}
	}

const std::wstring tempVector[] = { _T( "Honky Tonk" ), _T( "Bosco" ), _T( "Nuh Guck" ), _T( "Short-shorts" ), _T( "Itsy-bitsy" ), _T( "Low Ball" ), _T( "Cowboy Stu" ), _T( "Capsaicin" ), _T( "Hoity-toity" ), _T( "Ram Bam" ), _T( "King Kong" ), _T( "Upsilon" ), _T( "Omega" ), _T( "Peristaltic Pump" ), _T( "Jeebers" ), _T( "Sugar Cane" ), _T( "See-Saw" ), _T( "Ink Blot" ), _T( "Glottal Stop" ), _T( "Olive Oil" ), _T( "Cod Fish" ), _T( "Flax" ), _T( "Tahini" ), _T( "Cotton Ball" ), _T( "Sweet Justice" ), _T( "Ham Sandwich" ), _T( "Liverwurst" ), _T( "Cumulus" ), _T( "Oyster" ), _T( "Klein" ), _T( "Hippopotamus" ), _T( "Bonobo" ), _T( "Homo Erectus" ), _T( "Australopithecine" ), _T( "Quetzalcoatl" ), _T( "Balogna" ), _T( "Ceraunoscopy" ), _T( "Shirley" ), _T( "Susie" ), _T( "Sally" ), _T( "Sue" ), _T( "Tyrannosaur" ), _T( "Stick Man Chu" ), _T( "Paragon" ), _T( "Woodchuck" ), _T( "Laissez Faire" ), _T( "Ipso Facto" ), _T( "Leviticus" ), _T( "Berrylicious" ), _T( "Elderberry" ), _T( "Currant" ), _T( "Blackberry" ), _T( "Blueberry" ), _T( "Strawberry" ), _T( "Gooseberry" ), _T( "Honeysuckle" ), _T( "Nannyberry" ), _T( "Hackberry" ), _T( "Boysenberry" ), _T( "Cloudberry" ), _T( "Thimbleberry" ), _T( "Huckleberry" ), _T( "Bilberry" ), _T( "Bearberry" ), _T( "Mulberry" ), _T( "Wolfberry" ), _T( "Raisin" ), _T( "Samson" ) };
std::vector<std::wstring> PlayerManager::RandomNames = std::vector<std::wstring>( tempVector, tempVector + sizeof( tempVector ) / sizeof( tempVector[ 0 ] ) );
int PlayerManager::FirstPlayer = 0;
bool PlayerManager::HaveFirstPlayer = false;

	int PlayerManager::GetFirstPlayer()
	{
		HaveFirstPlayer = true;
		if ( Players[ FirstPlayer ]->Exists )
			return FirstPlayer;
		else
		{
			for ( int i = 0; i < 4; i++ )
			{
				if ( Players[ i ]->Exists )
				{
					FirstPlayer = i;
					return FirstPlayer;
				}
			}
		}

		HaveFirstPlayer = false;
		return 0;
	}

int PlayerManager::NumPlayers = 1;
std::vector<PlayerData*> PlayerManager::Players = 0;

	int PlayerManager::length( std::vector<StringBuilder*> &names )
	{
		int count = 0;
		for ( std::vector<StringBuilder*>::const_iterator name = names.begin(); name != names.end(); ++name )
			count += ( *name )->Length;
		return count;
	}

	std::wstring PlayerManager::GetGroupGamerTag( int MaxLength )
	{
		std::vector<PlayerData*> players = getLoggedInPlayers();
		if ( players.empty() )
			players = getExistingPlayers();

		int N = players.size();
		int CharLength = MaxLength - ( N - 1 ); // The max number of characters, exlucing slashes

		// Get a list of all names
		std::vector<StringBuilder*> names = std::vector<StringBuilder*>();
		for ( std::vector<PlayerData*>::const_iterator player = players.begin(); player != players.end(); ++player )
			names.push_back( std::make_shared<StringBuilder>( ( *player )->GetName() ) );

		// Remove one character from the longest name until the total length is small enough
		std::shared_ptr<GetGroupGamerTagNameLength> groupNameLengthGetter = std::make_shared<GetGroupGamerTagNameLength>();
		while ( length( names ) > CharLength )
		{
			std::shared_ptr<StringBuilder> str = Tools::ArgMax( names, groupNameLengthGetter );
			str->Remove( str->Length - 1, 1 );
		}

		// Concatenate the names together
		std::wstring GroupTag = _T( "" );
		//foreach (StringBuilder str in names)
		for ( int i = 0; i < names.size(); i++ )
		{
			std::shared_ptr<StringBuilder> str = names[ i ];
			std::shared_ptr<PlayerData> player = players[ i ];

			//string clr = EzText.ColorToCode(new Color(player.GetTextColor()));

			// Add '/' between player names
			if ( GroupTag.length() > 0 )
				GroupTag += L'/';

//C# TO C++ CONVERTER TODO TASK: There is no native C++ equivalent to 'ToString':
			std::wstring name = str->ToString();
			//GroupTag += clr + name;
			GroupTag += name;
		}

		return GroupTag;
	}

	int PlayerManager::MaxPlayerHighScore( int GameId )
	{
		int max = 0;
		for ( std::vector<PlayerData*>::const_iterator player = getExistingPlayers().begin(); player != getExistingPlayers().end(); ++player )
			max = __max( max, ( *player )->GetHighScore( GameId ) );

		return max;
	}

	bool PlayerManager::Awarded( const std::shared_ptr<Awardment> &award )
	{
		return Tools::Any( getExistingPlayers(), std::make_shared<AnyAwardmentLambda>(award) );
	}

	bool PlayerManager::Bought( const std::shared_ptr<Buyable> &item )
	{
		return Tools::Any( getExistingPlayers(), std::make_shared<AnyBoughtLambda>(item) );
	}

	bool PlayerManager::BoughtOrFree( const std::shared_ptr<Buyable> &item )
	{
		return item->GetPrice() == 0 || Bought(item);
	}

	int PlayerManager::CombinedBank()
	{
		return PlayerSum( std::make_shared<BankLambda>() );
	}

	void PlayerManager::DeductCost( int Cost )
	{
		if ( Cost > CombinedBank() )
			return;

		int SafetyCounter = 0;

		int PlayerIndex = 0;
		while ( Cost > 0 )
		{
			SafetyCounter++;
			if ( SafetyCounter > 1000000 )
				return;

			// Deduct one coin from each player at a time, so long as they can afford it.
			std::shared_ptr<PlayerData> p = Players[ PlayerIndex ];
			if ( p->Exists && p->Bank() > 0 )
			{
				p->LifetimeStats->CoinsSpentAtShop++;
				Cost--;
			}

			PlayerIndex++;
			if ( PlayerIndex > 3 )
				PlayerIndex = 0;
		}
	}

	void PlayerManager::GiveBoughtItem( const std::shared_ptr<Buyable> &buyable )
	{
		if ( buyable == 0 )
			return;

		// Give the hat to each player
		for ( std::vector<PlayerData*>::const_iterator p = getExistingPlayers().begin(); p != getExistingPlayers().end(); ++p )
			( *p )->Purchases += buyable->GetGuid();

		SavePlayerData->Changed = true;
	}

	bool PlayerManager::NotAllAwarded( const std::shared_ptr<Awardment> &award )
	{
		return Tools::Any( getExistingPlayers(), std::make_shared<NotAllAwardedLambda>(award) );
	}

	int PlayerManager::GetGameScore()
	{
		int score = 0;
		for ( std::vector<PlayerData*>::const_iterator player = getExistingPlayers().begin(); player != getExistingPlayers().end(); ++player )
			score += ( *player )->GetGameScore();

		return score;
	}

	int PlayerManager::GetGameScore_WithTemporary()
	{
		int score = 0;
		for ( std::vector<PlayerData*>::const_iterator player = getExistingPlayers().begin(); player != getExistingPlayers().end(); ++player )
			score += ( *player )->GetGameScore() + (*player)->TempStats->Score;

		return score;
	}

	int PlayerManager::PlayerSum( const std::shared_ptr<LambdaFunc_1<PlayerData*, int> > &f )
	{
		int sum = 0;
		for ( std::vector<PlayerData*>::const_iterator player = getExistingPlayers().begin(); player != getExistingPlayers().end(); ++player )
		{
			if ( *player != 0 )
				sum += f->Apply( *player );
		}

		return sum;
	}

	int PlayerManager::PlayerMax( const std::shared_ptr<LambdaFunc_1<PlayerData*, int> > &f )
	{
		int max = int::MinValue;
		for ( std::vector<PlayerData*>::const_iterator player = getExistingPlayers().begin(); player != getExistingPlayers().end(); ++player )
		{
			if ( *player != 0 )
				max = __max( max, f->Apply( *player ) );
		}

		return max;
	}

	int PlayerManager::GetLevelCoins()
	{
		int coins = 0;
		for ( std::vector<PlayerData*>::const_iterator player = getExistingPlayers().begin(); player != getExistingPlayers().end(); ++player )
			coins += ( *player )->GetLevelCoins();

		return coins;
	}

	const std::vector<PlayerData*> &PlayerManager::getLoggedInPlayers()
	{
	#if defined(PC_VERSION)
		return getExistingPlayers();
	#elif defined(XBOX) || defined(XBOX_SIGNIN)
		return Tools::FindAll( getExistingPlayers(), std::make_shared<ExistingPlayerFindLambda>() );
	#else
		return getExistingPlayers();
	#endif
	}

	const std::vector<PlayerData*> &PlayerManager::getExistingPlayers()
	{
		_ExistingPlayers.clear();
		for ( std::vector<CloudberryKingdom::PlayerData*>::const_iterator data = Players.begin(); data != Players.end(); ++data )
			if ( *data != 0 && ( *data )->Exists )
				_ExistingPlayers.push_back( *data );

		return _ExistingPlayers;
	}

std::vector<PlayerData*> PlayerManager::_ExistingPlayers = std::vector<PlayerData*>();

	const std::vector<PlayerData*> &PlayerManager::getAlivePlayers()
	{
		_AlivePlayers.clear();
		for ( std::vector<CloudberryKingdom::PlayerData*>::const_iterator data = Players.begin(); data != Players.end(); ++data )
			if ( ( *data )->Exists && ( *data )->IsAlive )
				_AlivePlayers.push_back( *data );

		return _AlivePlayers;
	}

std::vector<PlayerData*> PlayerManager::_AlivePlayers = std::vector<PlayerData*>();

#if defined(PC_VERSION)
	const std::shared_ptr<PlayerData> &PlayerManager::getPlayer()
	{
		return Players[ 0 ];
	}
#endif

	std::shared_ptr<PlayerData> PlayerManager::Get( int i )
	{
		return Players[ i ];
	}

	std::shared_ptr<PlayerData> PlayerManager::Get( PlayerIndex Index )
	{
		return Players[ static_cast<int>( Index ) ];
	}

	std::shared_ptr<PlayerData> PlayerManager::Get( const std::shared_ptr<Bob> &bob )
	{
		return Players[ static_cast<int>( bob->MyPlayerIndex ) ];
	}

int Score_Blobs, Score_Coins, Score_Attempts, PlayerManager::Score_Time = 0;

	void PlayerManager::CalcScore( StatGroup group )
	{
		if ( group == StatGroup_LEVEL )
			AbsorbTempStats();
		else if ( group == StatGroup_GAME )
		{
			AbsorbTempStats();
			AbsorbLevelStats();
		}

		Score_Attempts = Score_Blobs = Score_Coins = Score_Time = 0;

		for ( int i = 0; i < 4; i++ )
			if ( PlayerManager::Get( i )->Exists )
			{
				std::shared_ptr<PlayerStats> stats = Get( i )->GetStats( group );

				Score_Coins += stats->Coins;
				Score_Blobs += stats->Blobs;
				Score_Attempts += stats->DeathsBy[ static_cast<int>( Bob::BobDeathType_TOTAL ) ];
				Score_Time = __max( Score_Time, stats->TimeAlive );
			}
	}

bool PlayerManager::Showed_ShouldCheckOutWorlds = false;
int Showed_ShouldLeaveLevel, PlayerManager::Showed_ShouldWatchComputer = 0;

	int PlayerManager::GetNumPlayers()
	{
		NumPlayers = 0;
		for ( int i = 0; i < 4; i++ )
			if ( Players[ i ]->Exists )
				NumPlayers++;

		return NumPlayers;
	}

	bool PlayerManager::AllDead()
	{
		bool All = true;
		for ( int i = 0; i < 4; i++ )
			All = All && ( !Players[ i ]->IsAlive || !Players[ i ]->Exists );

		return All;
	}

	bool PlayerManager::AllOffscreen()
	{
		bool All = true;
		for ( std::vector<Bob*>::const_iterator bob = Tools::CurLevel->Bobs.begin(); bob != Tools::CurLevel->Bobs.end(); ++bob )
			All = All && !Tools::CurLevel->getMainCamera()->OnScreen((*bob)->getCore()->Data->Position);

		return All;
	}

	bool PlayerManager::IsAlive( PlayerIndex PIndex )
	{
		int Index = GetIndexFromPlayerIndex( PIndex );

		return Players[ Index ]->IsAlive;
	}

	int PlayerManager::GetIndexFromPlayerIndex( PlayerIndex PIndex )
	{
		for ( int i = 0; i < 4; i++ )
			if ( Players[ i ]->MyPlayerIndex == PIndex )
				return i;

		throw ( std::exception( _T( "PlayerIndex not found!" ) ) );
	}

	void PlayerManager::KillPlayer( PlayerIndex PIndex )
	{
		int Index = GetIndexFromPlayerIndex( PIndex );

		Players[ Index ]->IsAlive = false;
	}

	void PlayerManager::ReviveBob( const std::shared_ptr<Bob> &bob )
	{
		bob->Dead = bob->Dying = false;

		RevivePlayer( bob->MyPlayerIndex );
	}

	void PlayerManager::RevivePlayer( PlayerIndex PIndex )
	{
		int Index = GetIndexFromPlayerIndex( PIndex );

		Players[ Index ]->IsAlive = true;
	}

	void PlayerManager::Init()
	{
	#if defined(PC_VERSION)
		_DefaultName = PlayerManager::RandomNames.Choose( Tools::GlobalRnd );
	#endif

		Players = std::vector<PlayerData*>( 4 );
		ColorSchemeManager::InitColorSchemes();

		// Player templates
		for ( int i = 0; i < 4; i++ )
		{
			Players[ i ] = std::make_shared<PlayerData>();
			Players[ i ]->Init( i );
		}
	}
}