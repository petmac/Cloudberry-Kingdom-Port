#pragma once

#ifndef SUPER_GLOBAL_HEADER_H
#define SUPER_GLOBAL_HEADER_H

//#define _CRTDBG_MAP_ALLOC
//#include <stdlib.h>
//#include <crtdbg.h>
//#define new DEBUG_NEW

#include "enums.h"
#include "forward_declarations.h"
#include <ForwardDeclarations.h>

// System includes.
#include <algorithm>
#include <PwneeAssert.h>
#include <list>
#include <map>
#define _USE_MATH_DEFINES
#include "math.h"
#include <memory>
#include <boost/shared_ptr.hpp>
#include <boost/make_shared.hpp>
#include <boost/enable_shared_from_this.hpp>
#include <queue>
#include <stack>
#include <string>
#include <vector>

#if defined( PS3 ) || defined( VITA )
	#define _T( x ) L##x
#else
	#include <tchar.h>
#endif

#if defined( VITA )
	#define M_E 2.71828182845904523536
	#define M_LOG2E 1.44269504088896340736
	#define M_LOG10E 0.434294481903251827651
	#define M_LN2 0.693147180559945309417
	#define M_LN10 2.30258509299404568402
	#define M_PI 3.14159265358979323846
	#define M_PI_2 1.57079632679489661923
	#define M_PI_4 0.785398163397448309616
	#define M_1_PI 0.318309886183790671538
	#define M_2_PI 0.636619772367581343076
	#define M_1_SQRTPI 0.564189583547756286948
	#define M_2_SQRTPI 1.12837916709551257390
	#define M_SQRT2 1.41421356237309504880
	#define M_SQRT_2 0.707106781186547524401
#endif

// Syntactic sugar
#define MakeMagic( classname, params ) \
	boost::make_shared<classname> params -> classname##_Construct params

namespace CloudberryKingdom
{
	typedef std::vector<boost::shared_ptr<Bob> > BobVec;
	typedef std::vector<boost::shared_ptr<ObjectBase> > ObjectVec;
	typedef std::vector<boost::shared_ptr<BlockBase> > BlockVec;
	typedef std::vector<boost::shared_ptr<GameObject> > GameObjVec;
}

// Jordan's unalphebatized shit. Suck it Oleg.
inline int Sign(int x) { return (x > 0) - (x < 0); }
inline int Sign(float x) { return (x > 0) - (x < 0); }
inline int Sign(double x) { return (x > 0) - (x < 0); }

// Increment an enumeration variable by one.
template<typename E>
inline void Incr( E &e )
{
	e = static_cast<E>( static_cast<int>( e ) + 1 );
}

struct Object
{


	virtual ~Object()
	{
	}

};

template<class T>
struct WrappedValue : public Object
{


	T MyValue;

	WrappedValue( T value ) : MyValue( value )
	{
	}

};

template<class T>
inline T Unbox( boost::shared_ptr<Object> o )
{
	return ( *boost::static_pointer_cast<WrappedValue<T> >( o ).get() ).MyValue;
}

template<class T>
inline boost::shared_ptr<Object> MakeSmartObject( T t )
{
	return boost::static_pointer_cast<Object>( boost::make_shared<WrappedValue<T> >( t ) );
}

template<class T>
inline boost::shared_ptr<Object> MakeSmartObject( boost::shared_ptr<T> ptr )
{
	return boost::static_pointer_cast<Object>( ptr );
}


// Core library.
#include <Graphics/Color.h>
#include <Math/Vectors.h>

// Cloudberry Kingdom converted files.
#include "Core/Input/ButtonCheck.h"
#include "Core/Particle Effects/Particle.h"
#include "Core/Particle Effects/ParticleEmitter.h"
#include "Core/Particle Effects/Specific Effects/CloudberryKingdom.ParticleEffects.h"
#include "Core/Song/EzSong.h"
#include "Core/Song/EzSongWad.h"
#include "Core/Sound/EzSound.h"
#include "Core/Sound/EzSoundWad.h"
#include "Core/Text/EzFont.h"
#include "Core/Text/EzText.h"
#include "Core/Texture/EzTextureWad.h"
#include "Core/Texture/EzTexture.h"
#include "Core/Texture/PackedTexture.h"
#include "Core/Texture/TextureOrAnim.h"
#include "Core/Tools/ColorHelper.h"
#include "Core/Tools/CoreMath.h"
#include "Core/Tools/Random.h"

#include "Game/Collision Detection/AABox.h"
#include "Game/Collision Detection/Circle.h"
#include "Game/Collision Detection/FloatRectangle.h"
#include "Game/Collision Detection/Line.h"
#include "Game/Collision Detection/Phsx.h"


#include "Game/Objects/ObjectBase.h"
#include "Game/Tilesets/TileSet.h"
#include "Game/Objects/In Game Objects/Blocks/Block.h"
#include "Game/Objects/In Game Objects/Blocks/Wall.h"

#include "Game/Objects/Game Objects/GameObject.h"

#include "Game/Objects/Game Objects/GameObjects/GUI_Panel.h"
#include "Game/Menus/CkBaseMenu.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Verify/VerifyBase.h"

#include "Game/Player/Buyable.h"
#include "Game/Player/ClrTextFx.h"

#include "Game/Games/GameType.h"
#include "Game/Games/ActionGame.h"
#include "Game/Games/CampaignHelper.h"
#include "Game/Games/NormalGame.h"
#include "Game/Games/Meta Games/StringWorlds/StringWorld.h"
#include "Game/Games/ScreenSaver.h"
#include "Game/Games/ToDoItem.h"
#include "Game/Games/TutorialHelper.h"
#include "Game/Games/Campaign/LevelSequence.h"
#include "Game/Games/Campaign/FadeIn.h"
#include "Game/Games/Meta Games/Challenges/Challenge_Base.h"
#include "Game/Games/Campaign/CampaignSequence.h"
#include "Game/Games/Meta Games/Arcade Games/Escalate/Escalation.h"
#include "Game/Games/Meta Games/Arcade Games/HeroFactory_Escalation.h"
#include "Game/Games/Meta Games/Arcade Games/Escalate/Escalation_Tutorial.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/CoinMod.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/Rush.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/Hero Rush/HeroRush.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/Hero Rush/HeroRush_Tutorial.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/Hero Rush 2/HeroRush2.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/Hero Rush 2/HeroRush2_Tutorial.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/Time Crisis/TimeCrisis.h"
#include "Game/Games/Meta Games/Arcade Games/Rush/Time Crisis/TimeCrisis_Tutorial.h"
#include "Game/Games/Meta Games/Challenges/_Regular.h"
#include "Game/Games/Meta Games/StringWorlds/LevelConnector.h"
#include "Game/Games/Meta Games/StringWorlds/StringWorld_Endurance.h"
#include "Game/Games/Meta Games/StringWorlds/StringWorld_Timed.h"
#include "Game/Level/ClosingCircle.h"
#include "Game/Level/LevelPiece.h"
#include "Game/Level/Make/LockableBool.h"
#include "Game/Level/Make/ComputerRecording.h"
#include "Game/Level/Make/DifficultyGroups.h"
#include "Game/Level/Make/DifficultyHelper.h"
#include "Game/Level/Make/Generators.h"
#include "Game/Level/Make/LevelSeedData.h"
#include "Game/Level/Make/PieceSeedData.h"
#include "Game/Level/Make/MakePiece/MakeThing.h"
#include "Game/Level/Make/MakePiece/MakeSingle/MakeFinalDoor.h"
#include "Game/Level/Make/MakePiece/MakeSingle/MakeFinalDoor_Float.h"
#include "Game/Level/Make/MakePiece/MakeVertical/MakeFinalDoor_Vertical.h"
#include "Game/Level/Make/MakePiece/MakeVertical/MakeDarkBottom.h"
#include "Game/Level/Make/Parameters/LevelGenData.h"
#include "Game/Level/Make/Parameters/Param.h"
#include "Game/Level/Make/Parameters/PresetDifficulties.h"
#include "Game/Level/Make/Parameters/RandomDifficulty.h"
#include "Game/Level/Make/Parameters/Upgrades.h"
#include "Game/Level/Make/Parameters/StyleData/StyleData.h"
#include "Game/Level/Make/Parameters/StyleData/BigData.h"
#include "Game/Level/Make/Parameters/StyleData/UpData.h"
#include "Game/Level/Make/Parameters/StyleData/DownData.h"
#include "Game/Level/Make/Parameters/StyleData/OneScreenData.h"
#include "Game/Level/Make/Parameters/StyleData/SingleData.h"
#include "Game/Level/Make/Tools/Tunnel.h"
#include "Game/Level/Replays/Recording.h"
#include "Game/Level/Replays/ReplayGUI.h"
#include "Game/Level/Replays/SwarmBundle.h"
#include "Game/Level/Replays/SwarmRecord.h"
#include "Game/Menus/Menu.h"
#include "Game/Menus/LongMenu.h"
#include "Game/Menus/MiniMenu.h"
//#include "Game/Menus/Concrete Menus/ShopMenu.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/ArrowMenu.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/Backdrop.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/CharacterSelect.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/CharSelectManager.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/ColorSelect.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/CustomizeMenu.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/Doll.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/GamerTag.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/HeroLevel.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/JoinText.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/SignInChoiceMenu.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/SimpleMenu.h"
#include "Game/Menus/Concrete Menus/CharacterSelect/Waiting.h"
#include "Game/Menus/Concrete Menus/Help/HelpBlurb.h"
#include "Game/Tools/EzStorage.h"
#include "Game/Player/PlayerManager.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/InGameStartMenu.h"
#include "Game/Menus/Menu Components/MenuItem.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Sub Menus/ControlScreen.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Sub Menus/CustomControls.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Sub Menus/LoadSeedAs.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Sub Menus/SaveLoadSeedMenu.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Sub Menus/SaveSeedAs.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Verify/AlertBase.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Verify/VerifyDeleteSeeds.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Verify/VerifyQuitLevel.h"
#include "Game/Menus/Concrete Menus/InGameStartMenus/Verify/VerifyRemove.h"
#include "Game/Menus/Concrete Menus/Loading Screen/ILoadingScreen.h"
#include "Game/Menus/Concrete Menus/Loading Screen/Loading.h"
#include "Game/Menus/Concrete Menus/Loading Screen/LoadingScreen.h"
#include "Game/Menus/Concrete Menus/Score Screens/ScoreDatabase.h"
#include "Game/Menus/Concrete Menus/Score Screens/ScoreEntry.h"
#include "Game/Menus/Concrete Menus/Score Screens/ScoreList.h"
#include "Game/Menus/Concrete Menus/Score Screens/ScoreScreen.h"
#include "Game/Menus/Concrete Menus/Score Screens/StatsScreen.h"
//#include "Game/Player/Leaderboard.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu_MW.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu_MW_Backpanel.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu_MW_Black.h"
#include "Game/Menus/Concrete Menus/Title Screen/Freeplay/CustomLevel_GUI.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu_MW_CustomLevel.h"
#include "Game/Menus/Concrete Menus/Title Screen/Sub Menus/VerifyQuitGame.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu_MW_Exit.h"
#include "Game/Menus/Concrete Menus/Title Screen/Sub Menus/SoundMenu.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu_MW_Options.h"
#include "Game/Menus/Concrete Menus/Title Screen/StartMenu_MW_PressStart.h"
#include "Game/Menus/Concrete Menus/Title Screen/TitleGameBase.h"
#include "Game/Menus/Concrete Menus/Title Screen/TitleGame_MW.h"
#include "Game/Menus/Concrete Menus/Title Screen/Arcade/ArcadeMenu.h"
#include "Game/Menus/Concrete Menus/Title Screen/Arcade/StartLevelMenu.h"
#include "Game/Menus/Concrete Menus/Title Screen/Arcade/StartMenu_MW_Arcade.h"
#include "Game/Menus/Concrete Menus/Title Screen/Arcade/Hero Select/HeroDoll.h"
#include "Game/Menus/Concrete Menus/Title Screen/Arcade/Hero Select/HeroSelectOptions.h"
#include "Game/Menus/Concrete Menus/Title Screen/Arcade/Hero Select/StartMenu_MW_HeroSelect.h"
#include "Game/Player/Hero Physics/Base.h"
#include "Game/Menus/Concrete Menus/Title Screen/Freeplay/CustomHero_GUI.h"
#include "Game/Menus/Concrete Menus/Title Screen/Freeplay/CustomUpgrades_GUI.h"
#include "Game/Menus/Menu Components/MenuSliderBase.h"
#include "Game/Menus/Concrete Menus/Title Screen/Freeplay/LengthSlider.h"
#include "Game/Menus/Concrete Menus/Title Screen/Freeplay/SavedSeedsGUI.h"
#include "Game/Menus/Concrete Menus/Title Screen/Story/StartMenu_MW_Campaign.h"
#include "Game/Menus/Concrete Menus/Title Screen/Story/StartMenu_MW_Cinematics.h"
#include "Game/Menus/Menu Components/MenuList.h"
#include "Game/Menus/Menu Components/MenuListAll.h"
#include "Game/Menus/Menu Components/MenuListExpand.h"
#include "Game/Menus/Menu Components/MenuSlider.h"
#include "Game/Menus/Menu Components/MenuScrollBar.h"
#include "Game/Menus/Concrete Menus/Title Screen/Freeplay/PhsxSlider.h"
#include "Game/Menus/Menu Components/MenuSliderNoSlide.h"
#include "Game/Menus/Menu Components/MenuToggle.h"
#include "Game/Menus/Menu Components/ScrollBar.h"
#include "Game/Objects/AutoGen.h"
#include "Game/Objects/IBounded.h"
#include "Game/Objects/Icon.h"
#include "Game/Objects/IPrepareToDraw.h"
#include "Game/Player/ColorScheme.h"
#include "Game/Objects/Bob/BobInput.h"
#include "Game/Objects/Bob/Bob.h"
#include "Game/Objects/Bob/BobLink.h"
#include "Game/Objects/Door/Door.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Text.h"
#include "Game/Objects/Door/PressNote.h"
#include "Game/Objects/Game Objects/Template_GameObject.h"
#include "Game/Objects/Game Objects/GameObjects/Cheer.h"
#include "Game/Objects/Game Objects/GameObjects/CoinScoreMultiplierObject.h"
#include "Game/Objects/Game Objects/GameObjects/DoorIcon.h"
#include "Game/Objects/Game Objects/GameObjects/ExplodeBobs.h"
#include "Game/Objects/Game Objects/GameObjects/Guide.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Blobs.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Level.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Lives.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_LivesLeft.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Multiplier.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_NextLife.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Score.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_TextBox.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Timer_Base.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Timer.h"
#include "Game/Objects/Game Objects/GameObjects/GUI_Timer_Simple.h"
#include "Game/Objects/Game Objects/GameObjects/LevelTitle.h"
#include "Game/Objects/Game Objects/GameObjects/Listener.h"
#include "Game/Objects/Game Objects/GameObjects/MultiplierUp.h"
#include "Game/Objects/Game Objects/GameObjects/NewHero.h"
#include "Game/Objects/Game Objects/GameObjects/PerfectScoreObject.h"
#include "Game/Objects/Game Objects/GameObjects/Region.h"
#include "Game/Objects/Game Objects/GameObjects/Rumble.h"
#include "Game/Objects/Game Objects/GameObjects/SlowMo.h"

#include "Game/Menus/Concrete Menus/Help/HelpMenu.h"
#include "Game/Menus/Concrete Menus/Help/HintBlurb.h"
#include "Game/Menus/Concrete Menus/Help/HintGiver.h"

#include "Game/Objects/Game Objects/GameObjects/SuperCheer.h"
#include "Game/Objects/Game Objects/GameObjects/TimerWarning.h"
#include "Game/Objects/Game Objects/GameObjects/End/GameOverPanel.h"
#include "Game/Objects/Game Objects/GameObjects/End/HighScorePanel.h"
#include "Game/Objects/In Game Objects/BaseClasses/_Obstacle.h"
#include "Game/Objects/In Game Objects/BaseClasses/_Death.h"
#include "Game/Objects/In Game Objects/BaseClasses/_BoxDeath.h"
#include "Game/Objects/In Game Objects/BaseClasses/_CircleDeath.h"
#include "Game/Objects/In Game Objects/BaseClasses/_LineDeath.h"
#include "Game/Objects/In Game Objects/Blocks/BouncyBlock.h"
#include "Game/Objects/In Game Objects/Blocks/BouncyBlock__Auto.h"
#include "Game/Objects/In Game Objects/Blocks/Ceiling__Auto.h"
#include "Game/Objects/In Game Objects/Blocks/Conveyor.h"
#include "Game/Objects/In Game Objects/Blocks/Conveyor__Auto.h"
#include "Game/Objects/In Game Objects/Blocks/FallingBlock.h"
#include "Game/Objects/In Game Objects/Blocks/FallingBlock__Auto.h"
#include "Game/Objects/In Game Objects/Blocks/GhostBlock.h"
#include "Game/Objects/In Game Objects/Blocks/GhostBlock__Auto.h"
#include "Game/Objects/In Game Objects/Blocks/Lava.h"
#include "Game/Objects/In Game Objects/Blocks/Lava_Castle.h"
#include "Game/Objects/In Game Objects/Blocks/MovingBlock.h"
#include "Game/Objects/In Game Objects/Blocks/MovingBlock__Auto.h"
#include "Game/Objects/In Game Objects/Blocks/MovingPlatform.h"
#include "Game/Objects/In Game Objects/Blocks/NormalBlock.h"
#include "Game/Objects/In Game Objects/Blocks/NormalBlockDraw.h"
#include "Game/Objects/In Game Objects/Blocks/NormalBlock__Auto.h"
#include "Game/Objects/In Game Objects/Blocks/Pendulum.h"
#include "Game/Objects/In Game Objects/Blocks/Pendulum__Auto.h"
#include "Game/Objects/In Game Objects/Grab/Checkpoint.h"
#include "Game/Objects/In Game Objects/Grab/MakeData.h"
#include "Game/Level/Level.h"
#include "Game/Objects/In Game Objects/Grab/Coin.h"
#include "Game/Objects/In Game Objects/Grab/Coin__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/BlockEmitter.h"
#include "Game/Objects/In Game Objects/Obstacles/BlockEmitter__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Boulder.h"
#include "Game/Objects/In Game Objects/Obstacles/Boulder__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Cloud.h"
#include "Game/Objects/In Game Objects/Obstacles/CloudberryKingdom.Fireball.h"
#include "Game/Objects/In Game Objects/Obstacles/CloudberryKingdom.Firesnake.h"
#include "Game/Objects/In Game Objects/Obstacles/Cloud__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Fireball__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Firesnake__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/FireSpinner.h"
#include "Game/Objects/In Game Objects/Obstacles/FireSpinner__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/FlyingBlob.h"
#include "Game/Objects/In Game Objects/Obstacles/FlyingBlob__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Laser.h"
#include "Game/Objects/In Game Objects/Obstacles/Laser__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/LavaDrip.h"
#include "Game/Objects/In Game Objects/Obstacles/LavaDrip__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Serpent.h"
#include "Game/Objects/In Game Objects/Obstacles/Serpent__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Spike.h"
#include "Game/Objects/In Game Objects/Obstacles/SpikeyGuy.h"
#include "Game/Objects/In Game Objects/Obstacles/SpikeyGuy__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/SpikeyLine.h"
#include "Game/Objects/In Game Objects/Obstacles/SpikeyLine__Auto.h"
#include "Game/Objects/In Game Objects/Obstacles/Spike__Auto.h"
#include "Game/Objects/Special/Arrow.h"
#include "Game/Objects/Special/ZoneTrigger.h"
#include "Game/Objects/Special/CameraZone.h"
#include "Game/Objects/Special/TextFloat.h"
#include "Game/Objects/Special/TextList.h"
#include "Game/Player/Cape.h"
#include "Game/Player/ColorSchemeManager.h"
#include "Game/Player/PlayerData.h"
#include "Game/Player/SavedSeeds.h"
#include "Game/Player/Stats.h"
#include "Game/Player/Awardments/Awardment.h"
#include "Game/Player/Awardments/AwardmentMessage.h"
#include "Game/Player/Hero Physics/Normal.h"
#include "Game/Player/Hero Physics/Big.h"
#include "Game/Player/Hero Physics/BobPhsxCharSelect.h"
#include "Game/Player/Hero Physics/Bouncy.h"
#include "Game/Player/Hero Physics/Box.h"
#include "Game/Player/Hero Physics/Double.h"
#include "Game/Player/Hero Physics/Invert.h"
#include "Game/Player/Hero Physics/Jetman.h"
#include "Game/Player/Hero Physics/Meat.h"
#include "Game/Player/Hero Physics/BobPhsxRandom.h"
#include "Game/Player/Hero Physics/Rocketbox.h"
#include "Game/Player/Hero Physics/Scale.h"
#include "Game/Player/Hero Physics/Small.h"
#include "Game/Player/Hero Physics/Spaceship.h"
#include "Game/Player/Hero Physics/Timeship.h"
#include "Game/Player/Hero Physics/Time.h"
#include "Game/Player/Hero Physics/Wheel.h"
#include "Game/Tilesets/BlockGroup.h"
#include "Game/Tilesets/SpriteInfo.h"


#include "Game/Tools/Camera.h"
#include "Game/Tools/CkColorHelper.h"
#include "Game/Tools/EzReader.h"
#include "Game/Tools/Globals.h"
#include "Game/Tools/Prototypes.h"
#include "Game/Tools/Recycler.h"
#include "Game/Tools/Resources.h"
#include "Game/Tools/Tools.h"
#include "Game/Tools/Unset.h"
#include "Game/Tools/WrappedFloat.h"

#include "Game/Tilesets/TileSetInfo.h"

#endif
