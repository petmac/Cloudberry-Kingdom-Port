#ifndef _RESOURCES_ART_H_
#define _RESOURCES_ART_H_

#include <vector>
#include <string>

const wchar_t *TEXTURE_PATHS[] = {
	L"Art/Transparent",
	L"Art/Bob/Accesories/BoxAlone",
	L"Art/Bob/Accesories/cart",
	L"Art/Bob/Accesories/Castle_jet_pack",
	L"Art/Bob/Accesories/SingleWing",
	L"Art/Bob/Accesories/Spaceship_Paper",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Duck_0000",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Jump_0000",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Jump_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Jump_0002",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Jump_0003",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Jump_0004",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Jump_0005",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Land_0000",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Land_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Land_0002",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Land_0003",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Land_0004",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Land_0005",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0000",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0002",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0003",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0004",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0005",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0006",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0007",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0008",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0009",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0010",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0011",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0012",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0013",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0014",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0015",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0016",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0017",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0018",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0019",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0020",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0021",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0022",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0023",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0024",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0025",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0026",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0027",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0028",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0029",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0030",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0031",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0032",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0033",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0034",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0035",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0036",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0037",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0038",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0039",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0040",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0041",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0042",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0043",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0044",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0045",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0046",
	L"Art/Bob/Bob_Trimmed/Bob_Box_Stand_0047",
	L"Art/Bob/Bob_Trimmed/Bob_Dead_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Horse_0000",
	L"Art/Bob/Bob_Trimmed/Bob_Horse_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Horse_0002",
	L"Art/Bob/Bob_Trimmed/Bob_Jump_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Jump_0002",
	L"Art/Bob/Bob_Trimmed/Bob_Jump_0003",
	L"Art/Bob/Bob_Trimmed/Bob_Jump_0004",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0002",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0003",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0004",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0005",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0006",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0007",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0008",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0009",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0010",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0011",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0012",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0013",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0014",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0015",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0016",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0017",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0018",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0019",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0020",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0021",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0022",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0023",
	L"Art/Bob/Bob_Trimmed/Bob_Run_0024",
	L"Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0000",
	L"Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0001",
	L"Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0002",
	L"Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0003",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0001",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0002",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0003",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0004",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0005",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0006",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0007",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0008",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0009",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0010",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0011",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0012",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0013",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0014",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0015",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0016",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0017",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0018",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0019",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0020",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0021",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0022",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0023",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0024",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0025",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0026",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0027",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0028",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0029",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0030",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0031",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0032",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0033",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0034",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0035",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0036",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0037",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0038",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0039",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0040",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0041",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0042",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0043",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0044",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0045",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0046",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0047",
	L"Art/Bob/Bob_Trimmed/Bob_Stand_0048",
	L"Art/Bob/Cart/Bob_Cart_Duck_0001",
	L"Art/Bob/Cart/Bob_Cart_Jump_0001",
	L"Art/Bob/Cart/Bob_Cart_Stand_0001",
	L"Art/Bob/Cart/CartAlone",
	L"Art/Bob/Cart/CartIcon",
	L"Art/Bob/Cart/CartWheel",
	L"Art/Bob/FacialHair/Beard_Super",
	L"Art/Bob/FacialHair/Goatee_Black",
	L"Art/Bob/FacialHair/Moustache_Brown",
	L"Art/Bob/Wheelie/Bob_Wheel_0000",
	L"Art/Buttons/Keyboard/A_Key",
	L"Art/Buttons/Keyboard/Backspace_Key",
	L"Art/Buttons/Keyboard/B_Key",
	L"Art/Buttons/Keyboard/C_Key",
	L"Art/Buttons/Keyboard/D_Key",
	L"Art/Buttons/Keyboard/Enter_Key",
	L"Art/Buttons/Keyboard/Esc_Key",
	L"Art/Buttons/Keyboard/E_Key",
	L"Art/Buttons/Keyboard/F_Key",
	L"Art/Buttons/Keyboard/G_Key",
	L"Art/Buttons/Keyboard/H_Key",
	L"Art/Buttons/Keyboard/I_Key",
	L"Art/Buttons/Keyboard/J_Key",
	L"Art/Buttons/Keyboard/K_Key",
	L"Art/Buttons/Keyboard/LeftRight_Key",
	L"Art/Buttons/Keyboard/L_Key",
	L"Art/Buttons/Keyboard/M_Key",
	L"Art/Buttons/Keyboard/N_Key",
	L"Art/Buttons/Keyboard/O_Key",
	L"Art/Buttons/Keyboard/P_Key",
	L"Art/Buttons/Keyboard/Q_Key",
	L"Art/Buttons/Keyboard/R_Key",
	L"Art/Buttons/Keyboard/Space_Key",
	L"Art/Buttons/Keyboard/S_Key",
	L"Art/Buttons/Keyboard/T_Key",
	L"Art/Buttons/Keyboard/Up_Key",
	L"Art/Buttons/Keyboard/U_Key",
	L"Art/Buttons/Keyboard/V_Key",
	L"Art/Buttons/Keyboard/W_Key",
	L"Art/Buttons/Keyboard/X_Key",
	L"Art/Buttons/Keyboard/Y_Key",
	L"Art/Buttons/Keyboard/Z_Key",
	L"Art/Buttons/Xbox_360/Xbox_A",
	L"Art/Buttons/Xbox_360/Xbox_B",
	L"Art/Buttons/Xbox_360/Xbox_Dir",
	L"Art/Buttons/Xbox_360/Xbox_LB",
	L"Art/Buttons/Xbox_360/Xbox_LT",
	L"Art/Buttons/Xbox_360/Xbox_RB",
	L"Art/Buttons/Xbox_360/Xbox_RT",
	L"Art/Buttons/Xbox_360/Xbox_Start",
	L"Art/Buttons/Xbox_360/Xbox_X",
	L"Art/Buttons/Xbox_360/Xbox_Y",
	L"Art/Characters/Berries/Poses/cb_crying",
	L"Art/Characters/Berries/Poses/cb_enthusiastic",
	L"Art/Characters/Berries/Poses/cb_surprised",
	L"Art/Coins/Checkpoint_v2",
	L"Art/Coins/coin_blue",
	L"Art/Coins/CoinShimmer/Coin_00000",
	L"Art/Coins/CoinShimmer/Coin_00001",
	L"Art/Coins/CoinShimmer/Coin_00002",
	L"Art/Coins/CoinShimmer/Coin_00003",
	L"Art/Coins/CoinShimmer/Coin_00004",
	L"Art/Coins/CoinShimmer/Coin_00005",
	L"Art/Coins/CoinShimmer/Coin_00006",
	L"Art/Coins/CoinShimmer/Coin_00007",
	L"Art/Coins/CoinShimmer/Coin_00008",
	L"Art/Coins/CoinShimmer/Coin_00009",
	L"Art/Coins/CoinShimmer/Coin_00010",
	L"Art/Coins/CoinShimmer/Coin_00011",
	L"Art/Coins/CoinShimmer/Coin_00012",
	L"Art/Coins/CoinShimmer/Coin_00013",
	L"Art/Coins/CoinShimmer/Coin_00014",
	L"Art/Coins/CoinShimmer/Coin_00015",
	L"Art/Coins/CoinShimmer/Coin_00016",
	L"Art/Coins/CoinShimmer/Coin_00017",
	L"Art/Coins/CoinShimmer/Coin_00018",
	L"Art/Coins/CoinShimmer/Coin_00019",
	L"Art/Coins/CoinShimmer/Coin_00020",
	L"Art/Coins/CoinShimmer/Coin_00021",
	L"Art/Coins/CoinShimmer/Coin_00022",
	L"Art/Coins/CoinShimmer/Coin_00023",
	L"Art/Coins/CoinShimmer/Coin_00024",
	L"Art/Coins/CoinShimmer/Coin_00025",
	L"Art/Coins/CoinShimmer/Coin_00026",
	L"Art/Coins/CoinShimmer/Coin_00027",
	L"Art/Coins/CoinShimmer/Coin_00028",
	L"Art/Coins/CoinShimmer/Coin_00029",
	L"Art/Coins/CoinShimmer/Coin_00030",
	L"Art/Coins/CoinShimmer/Coin_00031",
	L"Art/Coins/CoinShimmer/Coin_00032",
	L"Art/Coins/CoinShimmer/Coin_00033",
	L"Art/Coins/CoinShimmer/Coin_00034",
	L"Art/Coins/CoinShimmer/Coin_00035",
	L"Art/Coins/CoinShimmer/Coin_00036",
	L"Art/Coins/CoinShimmer/Coin_00037",
	L"Art/Coins/CoinShimmer/Coin_00038",
	L"Art/Coins/CoinShimmer/Coin_00039",
	L"Art/Coins/CoinShimmer/Coin_00040",
	L"Art/Coins/CoinShimmer/Coin_00041",
	L"Art/Coins/CoinShimmer/Coin_00042",
	L"Art/Coins/CoinShimmer/Coin_00043",
	L"Art/Coins/CoinShimmer/Coin_00044",
	L"Art/Coins/CoinShimmer/Coin_00045",
	L"Art/Coins/CoinShimmer/Coin_00046",
	L"Art/Coins/CoinShimmer/Coin_00047",
	L"Art/Coins/CoinShimmer/Coin_00048",
	L"Art/Coins/CoinShimmer/Coin_00049",
	L"Art/Cursor/hand_closed",
	L"Art/Cursor/hand_open",
	L"Art/Effects/CoinCollect",
	L"Art/Effects/Fire",
	L"Art/Effects/Fireball",
	L"Art/Effects/Pop",
	L"Art/Effects/Smoke2",
	L"Art/Effects/Sparkle",
	L"Art/Environments/Rain",
	L"Art/Environments/Snow",
	L"Art/Environments/Castle/Background/v2/Castle_Backdrop_2",
	L"Art/Environments/Castle/Background/v2/castle_chandelier_close",
	L"Art/Environments/Castle/Background/v2/castle_chandelier_far",
	L"Art/Environments/Castle/Background/v2/castle_lava",
	L"Art/Environments/Castle/Background/v2/castle_pillar",
	L"Art/Environments/Castle/Background/v2/castle_wall",
	L"Art/Environments/Castle/Background/v2/castle_wall_p2",
	L"Art/Environments/Castle/Background/v2/Castle_Window_Center_Frame",
	L"Art/Environments/Castle/Background/v2/Castle_Window_Center_Mask",
	L"Art/Environments/Castle/Background/v2/Castle_Window_Left_Frame",
	L"Art/Environments/Castle/Background/v2/Castle_Window_Left_Mask",
	L"Art/Environments/Castle/Background/v2/Castle_Window_Right_Frame",
	L"Art/Environments/Castle/Background/v2/Castle_Window_Right_Mask",
	L"Art/Environments/Castle/Door/door_castle_1",
	L"Art/Environments/Castle/Door/door_castle_2",
	L"Art/Environments/Castle/Door/Wall_Castle",
	L"Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_1",
	L"Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_2",
	L"Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_3",
	L"Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_4",
	L"Art/Environments/Castle/Obstacles/Bouncy_Block/Bouncy_Castle_1",
	L"Art/Environments/Castle/Obstacles/Bouncy_Block/Bouncy_Castle_2",
	L"Art/Environments/Castle/Obstacles/Bouncy_Block/Bouncy_Castle_3",
	L"Art/Environments/Castle/Obstacles/Cloud/Cloud_Castle",
	L"Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_135",
	L"Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_190",
	L"Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_40",
	L"Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_80",
	L"Art/Environments/Castle/Obstacles/Falling_Block/Fblock_Castle_1",
	L"Art/Environments/Castle/Obstacles/Falling_Block/Fblock_Castle_2",
	L"Art/Environments/Castle/Obstacles/Falling_Block/Fblock_Castle_3",
	L"Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Base_Castle_2",
	L"Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_1",
	L"Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_2",
	L"Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_3",
	L"Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_4",
	L"Art/Environments/Castle/Obstacles/Floater/Floater_Buzzsaw_Yellow_Castle",
	L"Art/Environments/Castle/Obstacles/Floater/Floater_Chain_Castle",
	L"Art/Environments/Castle/Obstacles/Floater/Floater_Spikey_Castle_v1",
	L"Art/Environments/Castle/Obstacles/Floater/Floater_Spikey_Castle_v2",
	L"Art/Environments/Castle/Obstacles/Flow/Flow_Castle_1",
	L"Art/Environments/Castle/Obstacles/Flow/Flow_Castle_2",
	L"Art/Environments/Castle/Obstacles/Flow/Flow_Castle_3",
	L"Art/Environments/Castle/Obstacles/Flow/Flow_Icon_Castle",
	L"Art/Environments/Castle/Obstacles/Ghost_Block/Ghostblock_Castle",
	L"Art/Environments/Castle/Obstacles/Laser/Laser_Castle",
	L"Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle",
	L"Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_135",
	L"Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_190",
	L"Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_40",
	L"Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_80",
	L"Art/Environments/Castle/Obstacles/Pendulum/Pendulum_Icon_Castle",
	L"Art/Environments/Castle/Obstacles/Serpent/SerpentHead_Castle_1",
	L"Art/Environments/Castle/Obstacles/Serpent/SerpentHead_Castle_2",
	L"Art/Environments/Castle/Obstacles/Serpent/Serpent_Castle_1",
	L"Art/Environments/Castle/Obstacles/Serpent/Serpent_Castle_2",
	L"Art/Environments/Castle/Obstacles/Serpent/Serpent_Fish_Castle_1",
	L"Art/Environments/Castle/Obstacles/Serpent/Serpent_Fish_Castle_2",
	L"Art/Environments/Castle/Obstacles/Spike/spike_base_castle",
	L"Art/Environments/Castle/Obstacles/Spike/Spike_Castle",
	L"Art/Environments/Castle/Pillars/Pillar_Castle_100",
	L"Art/Environments/Castle/Pillars/Pillar_Castle_1000",
	L"Art/Environments/Castle/Pillars/Pillar_Castle_150",
	L"Art/Environments/Castle/Pillars/Pillar_Castle_250",
	L"Art/Environments/Castle/Pillars/Pillar_Castle_300",
	L"Art/Environments/Castle/Pillars/Pillar_Castle_50",
	L"Art/Environments/Castle/Pillars/Pillar_Castle_600",
	L"Art/Environments/Cave/Background/v3/cave_backdrop",
	L"Art/Environments/Cave/Background/v3/cave_backdrop_p2",
	L"Art/Environments/Cave/Background/v3/cave_bottom_1_p2_trim1",
	L"Art/Environments/Cave/Background/v3/cave_bottom_1_p2_trim2",
	L"Art/Environments/Cave/Background/v3/cave_bottom_1_trim1",
	L"Art/Environments/Cave/Background/v3/cave_bottom_1_trim2",
	L"Art/Environments/Cave/Background/v3/cave_bottom_2_p1",
	L"Art/Environments/Cave/Background/v3/cave_bottom_2_p2",
	L"Art/Environments/Cave/Background/v3/cave_lightshafts",
	L"Art/Environments/Cave/Background/v3/cave_lightshafts_p2",
	L"Art/Environments/Cave/Background/v3/cave_top_1",
	L"Art/Environments/Cave/Background/v3/cave_top_1_p2",
	L"Art/Environments/Cave/Background/v3/cave_top_2",
	L"Art/Environments/Cave/Background/v3/cave_top_2_p2",
	L"Art/Environments/Cave/Door/door_cave_1",
	L"Art/Environments/Cave/Door/door_cave_2",
	L"Art/Environments/Cave/Door/Wall_Cave",
	L"Art/Environments/Cave/Obstacles/Blob/Blob_Cave_1",
	L"Art/Environments/Cave/Obstacles/Blob/Blob_Cave_2",
	L"Art/Environments/Cave/Obstacles/Blob/Blob_Cave_3",
	L"Art/Environments/Cave/Obstacles/Blob/Blob_Cave_4",
	L"Art/Environments/Cave/Obstacles/Bouncy_Block/Bouncy_Cave_1",
	L"Art/Environments/Cave/Obstacles/Bouncy_Block/Bouncy_Cave_2",
	L"Art/Environments/Cave/Obstacles/Bouncy_Block/Bouncy_Cave_3",
	L"Art/Environments/Cave/Obstacles/Cloud/Cloud_Cave",
	L"Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_135",
	L"Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_190",
	L"Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_40",
	L"Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_80",
	L"Art/Environments/Cave/Obstacles/Falling_Block/Fblock_Cave_1",
	L"Art/Environments/Cave/Obstacles/Falling_Block/Fblock_Cave_2",
	L"Art/Environments/Cave/Obstacles/Falling_Block/Fblock_Cave_3",
	L"Art/Environments/Cave/Obstacles/Floater/Floater_Chain_Cave",
	L"Art/Environments/Cave/Obstacles/Floater/Floater_Rope_Cave",
	L"Art/Environments/Cave/Obstacles/Floater/Floater_Spikey_Cave",
	L"Art/Environments/Cave/Obstacles/Flow/Flow_Cave_1",
	L"Art/Environments/Cave/Obstacles/Flow/Flow_Cave_2",
	L"Art/Environments/Cave/Obstacles/Flow/Flow_Cave_3",
	L"Art/Environments/Cave/Obstacles/Ghost_Block/Ghostblock_Cave",
	L"Art/Environments/Cave/Obstacles/Laser/Laser_Cave",
	L"Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_135",
	L"Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_190",
	L"Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_40",
	L"Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_80",
	L"Art/Environments/Cave/Obstacles/Spike/Spike_Base_Cave_1",
	L"Art/Environments/Cave/Obstacles/Spike/spike_cave",
	L"Art/Environments/Cave/Pillars/Pillar_Cave_100",
	L"Art/Environments/Cave/Pillars/Pillar_Cave_1000",
	L"Art/Environments/Cave/Pillars/Pillar_Cave_150",
	L"Art/Environments/Cave/Pillars/Pillar_Cave_250",
	L"Art/Environments/Cave/Pillars/Pillar_Cave_300",
	L"Art/Environments/Cave/Pillars/Pillar_Cave_50",
	L"Art/Environments/Cave/Pillars/Pillar_Cave_600",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer1",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer2_1",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer2_2",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer2_3",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer3_1",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer3_2",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer3_3",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer4",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer4_p2",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer5",
	L"Art/Environments/Cloud/Background/v2/cloud_castle_layer5_p2",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_1",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_2",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_3",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_4",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer2_1",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_1",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_2",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_3",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_4",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_5",
	L"Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_6",
	L"Art/Environments/Cloud/Door/door_cloud_1",
	L"Art/Environments/Cloud/Door/door_cloud_2",
	L"Art/Environments/Cloud/Door/Wall_Cloud",
	L"Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_1",
	L"Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_2",
	L"Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_3",
	L"Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_4",
	L"Art/Environments/Cloud/Obstacles/Bouncy_Block/Bouncy_Cloud_1",
	L"Art/Environments/Cloud/Obstacles/Bouncy_Block/Bouncy_Cloud_2",
	L"Art/Environments/Cloud/Obstacles/Bouncy_Block/Bouncy_Cloud_3",
	L"Art/Environments/Cloud/Obstacles/Cloud/Cloud_Cloud",
	L"Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_135",
	L"Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_190",
	L"Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_40",
	L"Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_80",
	L"Art/Environments/Cloud/Obstacles/Falling_Block/Fblock_Cloud_1",
	L"Art/Environments/Cloud/Obstacles/Falling_Block/Fblock_Cloud_2",
	L"Art/Environments/Cloud/Obstacles/Falling_Block/Fblock_Cloud_3",
	L"Art/Environments/Cloud/Obstacles/Fire_Spinner/Firespinner_Base_Cloud",
	L"Art/Environments/Cloud/Obstacles/Fire_Spinner/Firespinner_Flame_Cloud_1",
	L"Art/Environments/Cloud/Obstacles/Fire_Spinner/Firespinner_Flame_Cloud_2",
	L"Art/Environments/Cloud/Obstacles/Fire_Spinner/Firespinner_Flame_Cloud_3",
	L"Art/Environments/Cloud/Obstacles/Fire_Spinner/Firespinner_Flame_Cloud_4",
	L"Art/Environments/Cloud/Obstacles/Floater/Cloud_Chain",
	L"Art/Environments/Cloud/Obstacles/Floater/Floater_Boulder_Cloud",
	L"Art/Environments/Cloud/Obstacles/Floater/Floater_Rope_Cloud",
	L"Art/Environments/Cloud/Obstacles/Floater/Floater_Spikey_Cloud",
	L"Art/Environments/Cloud/Obstacles/Ghost_Block/Ghostblock_Cloud",
	L"Art/Environments/Cloud/Obstacles/Laser/Laser_Cloud",
	L"Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_135",
	L"Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_190",
	L"Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_40",
	L"Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_80",
	L"Art/Environments/Cloud/Obstacles/Serpent/Serpent_Cloud_1",
	L"Art/Environments/Cloud/Obstacles/Serpent/Serpent_Cloud_2",
	L"Art/Environments/Cloud/Obstacles/Serpent/Serpent_Fish_Cloud_1",
	L"Art/Environments/Cloud/Obstacles/Serpent/Serpent_Fish_Cloud_2",
	L"Art/Environments/Cloud/Obstacles/Spike/Spike_Base_Cloud_1",
	L"Art/Environments/Cloud/Obstacles/Spike/Spike_Cloud",
	L"Art/Environments/Cloud/Pillars/Pillar_Cloud_100",
	L"Art/Environments/Cloud/Pillars/Pillar_Cloud_1000",
	L"Art/Environments/Cloud/Pillars/Pillar_Cloud_150",
	L"Art/Environments/Cloud/Pillars/Pillar_Cloud_250",
	L"Art/Environments/Cloud/Pillars/Pillar_Cloud_300",
	L"Art/Environments/Cloud/Pillars/Pillar_Cloud_50",
	L"Art/Environments/Cloud/Pillars/Pillar_Cloud_600",
	L"Art/Environments/Forest/Background/v2/forest_backhills_p2_trim",
	L"Art/Environments/Forest/Background/v2/forest_backhills_trim",
	L"Art/Environments/Forest/Background/v2/forest_backtrees",
	L"Art/Environments/Forest/Background/v2/forest_backtrees_p2",
	L"Art/Environments/Forest/Background/v2/forest_clouds",
	L"Art/Environments/Forest/Background/v2/forest_foretrees",
	L"Art/Environments/Forest/Background/v2/forest_foretrees_p2",
	L"Art/Environments/Forest/Background/v2/forest_mid_p2_trim",
	L"Art/Environments/Forest/Background/v2/forest_mid_trim",
	L"Art/Environments/Forest/Background/v2/forest_sky",
	L"Art/Environments/Forest/Door/door_forest_1",
	L"Art/Environments/Forest/Door/door_forest_2",
	L"Art/Environments/Forest/Door/Wall_Forest",
	L"Art/Environments/Forest/Obstacles/Blob/Blob_Forest_1",
	L"Art/Environments/Forest/Obstacles/Blob/Blob_Forest_2",
	L"Art/Environments/Forest/Obstacles/Blob/Blob_Forest_3",
	L"Art/Environments/Forest/Obstacles/Blob/Blob_Forest_4",
	L"Art/Environments/Forest/Obstacles/Bouncy_Block/Bouncy_Forest_1",
	L"Art/Environments/Forest/Obstacles/Bouncy_Block/Bouncy_Forest_2",
	L"Art/Environments/Forest/Obstacles/Bouncy_Block/Bouncy_Forest_3",
	L"Art/Environments/Forest/Obstacles/Cloud/Cloud_Forest",
	L"Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_135",
	L"Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_190",
	L"Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_40",
	L"Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_80",
	L"Art/Environments/Forest/Obstacles/Falling_Block/Fblock_Forest_1",
	L"Art/Environments/Forest/Obstacles/Falling_Block/Fblock_Forest_2",
	L"Art/Environments/Forest/Obstacles/Falling_Block/Fblock_Forest_3",
	L"Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Base_Forest_1",
	L"Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_1",
	L"Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_2",
	L"Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_3",
	L"Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_4",
	L"Art/Environments/Forest/Obstacles/Floater/Floater_Buzzsaw_Forest",
	L"Art/Environments/Forest/Obstacles/Floater/Floater_Chain_Forest",
	L"Art/Environments/Forest/Obstacles/Floater/Floater_Spikey_Forest",
	L"Art/Environments/Forest/Obstacles/Ghost_Block/Ghostblock_Forest_1",
	L"Art/Environments/Forest/Obstacles/Laser/Laser_Forest",
	L"Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_135_v2",
	L"Art/Environments/Forest/Obstacles/Moving_Block/movingblock_forest_150",
	L"Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_190_v2",
	L"Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_40_v2",
	L"Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_80_v2",
	L"Art/Environments/Forest/Obstacles/Serpent/Serpent_Fish_Forest_1",
	L"Art/Environments/Forest/Obstacles/Serpent/Serpent_Fish_Forest_2",
	L"Art/Environments/Forest/Obstacles/Serpent/Serpent_Forest_1",
	L"Art/Environments/Forest/Obstacles/Serpent/Serpent_Forest_2",
	L"Art/Environments/Forest/Obstacles/Spike/Spike_Base_Forest_1",
	L"Art/Environments/Forest/Obstacles/Spike/Spike_Forest",
	L"Art/Environments/Forest/Pillars/Pillar_Forest_100",
	L"Art/Environments/Forest/Pillars/Pillar_Forest_1000",
	L"Art/Environments/Forest/Pillars/Pillar_Forest_150",
	L"Art/Environments/Forest/Pillars/Pillar_Forest_250",
	L"Art/Environments/Forest/Pillars/Pillar_Forest_300",
	L"Art/Environments/Forest/Pillars/Pillar_Forest_50",
	L"Art/Environments/Forest/Pillars/Pillar_Forest_600",
	L"Art/Environments/Hills/Background/v3/hills_backcastles_p2_trim",
	L"Art/Environments/Hills/Background/v3/hills_backcastles_trim",
	L"Art/Environments/Hills/Background/v3/hills_backdrop",
	L"Art/Environments/Hills/Background/v3/hills_backdrop_p2",
	L"Art/Environments/Hills/Background/v3/hills_backhills",
	L"Art/Environments/Hills/Background/v3/hills_backhills2_p2_trim",
	L"Art/Environments/Hills/Background/v3/hills_backhills2_trim",
	L"Art/Environments/Hills/Background/v3/hills_backhills_p2",
	L"Art/Environments/Hills/Background/v3/hills_clouds",
	L"Art/Environments/Hills/Background/v3/hills_hill1",
	L"Art/Environments/Hills/Background/v3/hills_hill2",
	L"Art/Environments/Hills/Background/v3/hills_hillandtree",
	L"Art/Environments/Hills/Background/v3/hills_plants_1",
	L"Art/Environments/Hills/Background/v3/hills_plants_2",
	L"Art/Environments/Hills/Background/v3/hills_plants_3",
	L"Art/Environments/Hills/Background/v3/hills_plants_4",
	L"Art/Environments/Hills/Background/v3/hills_plants_5",
	L"Art/Environments/Hills/Background/v3/hills_plants_6",
	L"Art/Environments/Hills/Background/v3/hills_rock",
	L"Art/Environments/Hills/Door/door_hills_1",
	L"Art/Environments/Hills/Door/door_hills_2",
	L"Art/Environments/Hills/Door/Wall_Hills",
	L"Art/Environments/Hills/Obstacles/Blob/Blob_Hills_1",
	L"Art/Environments/Hills/Obstacles/Blob/Blob_Hills_2",
	L"Art/Environments/Hills/Obstacles/Blob/Blob_Hills_3",
	L"Art/Environments/Hills/Obstacles/Blob/Blob_Hills_4",
	L"Art/Environments/Hills/Obstacles/Bouncy_Block/Bouncy_Hills_1",
	L"Art/Environments/Hills/Obstacles/Bouncy_Block/Bouncy_Hills_2",
	L"Art/Environments/Hills/Obstacles/Bouncy_Block/Bouncy_Hills_3",
	L"Art/Environments/Hills/Obstacles/Cloud/Cloud_Hills",
	L"Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_135",
	L"Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_190",
	L"Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_40",
	L"Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_80",
	L"Art/Environments/Hills/Obstacles/Falling_Block/Fblock_Hills_1",
	L"Art/Environments/Hills/Obstacles/Falling_Block/Fblock_Hills_2",
	L"Art/Environments/Hills/Obstacles/Falling_Block/Fblock_Hills_3",
	L"Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Base_Hills",
	L"Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_1",
	L"Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_2",
	L"Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_3",
	L"Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_4",
	L"Art/Environments/Hills/Obstacles/Floater/Floater_Boulder_Hills",
	L"Art/Environments/Hills/Obstacles/Floater/Floater_Chain_Hills",
	L"Art/Environments/Hills/Obstacles/Floater/Floater_Rope_Hills",
	L"Art/Environments/Hills/Obstacles/Floater/Floater_Spikey_Hills",
	L"Art/Environments/Hills/Obstacles/Ghost_Block/Ghostblock_Hills",
	L"Art/Environments/Hills/Obstacles/Laser/Laser_Hills",
	L"Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_135",
	L"Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_190",
	L"Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_40",
	L"Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_80",
	L"Art/Environments/Hills/Obstacles/Spike/Spike_Base_Hills_1",
	L"Art/Environments/Hills/Obstacles/Spike/Spike_Hills",
	L"Art/Environments/Hills/Pillars/Pillar_Hills_100",
	L"Art/Environments/Hills/Pillars/Pillar_Hills_1000",
	L"Art/Environments/Hills/Pillars/Pillar_Hills_150",
	L"Art/Environments/Hills/Pillars/Pillar_Hills_250",
	L"Art/Environments/Hills/Pillars/Pillar_Hills_300",
	L"Art/Environments/Hills/Pillars/Pillar_Hills_50",
	L"Art/Environments/Hills/Pillars/Pillar_Hills_600",
	L"Art/Environments/Sea/Background/v2/sea_backdrop",
	L"Art/Environments/Sea/Background/v2/sea_backdrop_p2",
	L"Art/Environments/Sea/Background/v2/sea_behind_water_1",
	L"Art/Environments/Sea/Background/v2/sea_behind_water_2",
	L"Art/Environments/Sea/Background/v2/sea_behind_water_3",
	L"Art/Environments/Sea/Background/v2/sea_clouds",
	L"Art/Environments/Sea/Background/v2/sea_rock_1",
	L"Art/Environments/Sea/Background/v2/sea_rock_2",
	L"Art/Environments/Sea/Background/v2/sea_rock_3",
	L"Art/Environments/Sea/Background/v2/sea_rock_4",
	L"Art/Environments/Sea/Background/v2/sea_rock_5",
	L"Art/Environments/Sea/Background/v2/sea_seamonster",
	L"Art/Environments/Sea/Background/v2/sea_water_1",
	L"Art/Environments/Sea/Background/v2/sea_water_2",
	L"Art/Environments/Sea/Door/door_sea_1",
	L"Art/Environments/Sea/Door/door_sea_2",
	L"Art/Environments/Sea/Door/Wall_Sea",
	L"Art/Environments/Sea/Obstacles/Blob/Blob_Sea_1",
	L"Art/Environments/Sea/Obstacles/Blob/Blob_Sea_2",
	L"Art/Environments/Sea/Obstacles/Blob/Blob_Sea_3",
	L"Art/Environments/Sea/Obstacles/Blob/Blob_Sea_4",
	L"Art/Environments/Sea/Obstacles/Bouncy_Block/Bouncy_Sea_1",
	L"Art/Environments/Sea/Obstacles/Bouncy_Block/Bouncy_Sea_2",
	L"Art/Environments/Sea/Obstacles/Bouncy_Block/Bouncy_Sea_3",
	L"Art/Environments/Sea/Obstacles/Cloud/Cloud_Sea",
	L"Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_135",
	L"Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_190",
	L"Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_40",
	L"Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_80",
	L"Art/Environments/Sea/Obstacles/Falling_Block/Fblock_Sea_1",
	L"Art/Environments/Sea/Obstacles/Falling_Block/Fblock_Sea_2",
	L"Art/Environments/Sea/Obstacles/Falling_Block/Fblock_Sea_3",
	L"Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_1",
	L"Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_2",
	L"Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_3",
	L"Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_4",
	L"Art/Environments/Sea/Obstacles/Firespinner/firespinner_gear_dkpurp",
	L"Art/Environments/Sea/Obstacles/Floater/Floater_Chain_Sea",
	L"Art/Environments/Sea/Obstacles/Floater/Floater_Spikey_Sea",
	L"Art/Environments/Sea/Obstacles/Floater/Floater_Spikey_Sea_v2",
	L"Art/Environments/Sea/Obstacles/Flow/Flow_Sea_1",
	L"Art/Environments/Sea/Obstacles/Flow/Flow_Sea_2",
	L"Art/Environments/Sea/Obstacles/Flow/Flow_Sea_3",
	L"Art/Environments/Sea/Obstacles/Ghost_Block/Ghostblock_Sea",
	L"Art/Environments/Sea/Obstacles/Laser/Laser_Sea",
	L"Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_135",
	L"Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_190",
	L"Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_40",
	L"Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_80",
	L"Art/Environments/Sea/Obstacles/Serpent/Serpent_Fish_Sea_1",
	L"Art/Environments/Sea/Obstacles/Serpent/Serpent_Fish_Sea_2",
	L"Art/Environments/Sea/Obstacles/Serpent/Serpent_Sea_1",
	L"Art/Environments/Sea/Obstacles/Serpent/Serpent_Sea_2",
	L"Art/Environments/Sea/Obstacles/Spike/Spike_Base_Sea_1",
	L"Art/Environments/Sea/Obstacles/Spike/Spike_Sea_2",
	L"Art/Environments/Sea/Pillars/Pillar_Sea_100",
	L"Art/Environments/Sea/Pillars/Pillar_Sea_1000",
	L"Art/Environments/Sea/Pillars/Pillar_Sea_150",
	L"Art/Environments/Sea/Pillars/Pillar_Sea_250",
	L"Art/Environments/Sea/Pillars/Pillar_Sea_300",
	L"Art/Environments/Sea/Pillars/Pillar_Sea_50",
	L"Art/Environments/Sea/Pillars/Pillar_Sea_600",
	L"Art/HeroItems/Hats/HatPic_Horns",
	L"Art/HeroItems/Hats/hat_afro",
	L"Art/HeroItems/Hats/hat_antlers",
	L"Art/HeroItems/Hats/hat_arrow",
	L"Art/HeroItems/Hats/hat_bag",
	L"Art/HeroItems/Hats/hat_beard",
	L"Art/HeroItems/Hats/hat_brain",
	L"Art/HeroItems/Hats/hat_bubble",
	L"Art/HeroItems/Hats/hat_bunny",
	L"Art/HeroItems/Hats/hat_cone",
	L"Art/HeroItems/Hats/hat_disguise",
	L"Art/HeroItems/Hats/hat_fedora",
	L"Art/HeroItems/Hats/hat_gosu",
	L"Art/HeroItems/Hats/hat_halo",
	L"Art/HeroItems/Hats/hat_knight",
	L"Art/HeroItems/Hats/hat_miner",
	L"Art/HeroItems/Hats/hat_pirate",
	L"Art/HeroItems/Hats/hat_pope",
	L"Art/HeroItems/Hats/hat_pumkin",
	L"Art/HeroItems/Hats/hat_rastafari",
	L"Art/HeroItems/Hats/hat_rice",
	L"Art/HeroItems/Hats/hat_robinhood",
	L"Art/HeroItems/Hats/hat_santa",
	L"Art/HeroItems/Hats/hat_sombrero",
	L"Art/HeroItems/Hats/hat_tiki",
	L"Art/HeroItems/Hats/hat_tophat",
	L"Art/HeroItems/Hats/hat_viking",
	L"Art/HeroItems/Hats/hat_wizard",
	L"Art/HeroItems/Hats/LeftHorn",
	L"Art/HeroItems/Hats/RightHorn",
	L"Art/HeroItems/Hats/TestHat",
	L"Art/LoadScreen_Initial/LoadFill",
	L"Art/LoadScreen_Initial/LoadOutline",
	L"Art/LoadScreen_Level/LoadingStrip",
	L"Art/Menu/BackArrow2",
	L"Art/Menu/directionarrow",
	L"Art/Menu/Backplates/backplate_1080x840",
	L"Art/Menu/Backplates/backplate_1230x740",
	L"Art/Menu/Backplates/backplate_1500x900",
	L"Art/Menu/CharacterMenu/Arrow_Left",
	L"Art/Menu/CharacterMenu/Arrow_Right",
	L"Art/Menu/CharacterMenu/CharSelect",
	L"Art/Menu/CustomLevel/Length",
	L"Art/Menu/CustomLevel/LengthBack",
	L"Art/Menu/Icons/Icon_Checkpoint_v2",
	L"Art/Menu/Icons/Hero/HeroIcon_Custom",
	L"Art/Menu/Icons/Hero/HeroIcon_Double",
	L"Art/Menu/Icons/Hero/HeroIcon_Jetman",
	L"Art/Menu/Icons/Hero/HeroIcon_Phase",
	L"Art/Menu/Icons/Hero/HeroIcon_Random",
	L"Art/Menu/Icons/Upgrades/CeilingIcon",
	L"Art/Menu/Icons/Upgrades/Dodge",
	L"Art/Menu/Icons/Upgrades/Icon_Fireball",
	L"Art/Menu/Icons/Upgrades/Icon_FireSpinner",
	L"Art/Menu/Icons/Upgrades/Icon_Laser",
	L"Art/Menu/Icons/Upgrades/Jump",
	L"Art/Menu/Icons/Upgrades/SpeedIcon",
	L"Art/Menu/Icons/Upgrades/SpikeIcon",
	L"Art/Menu/Powerups/Powerup_Computer",
	L"Art/Menu/Powerups/Powerup_Path",
	L"Art/Menu/Powerups/Powerup_Slowmo",
	L"Art/Menu/Replay_GUI/End",
	L"Art/Menu/Replay_GUI/Paused",
	L"Art/Menu/Score/Bob_Dead",
	L"Art/Menu/Score/LevelCleared",
	L"Art/Menu/Score/Score_Screen",
	L"Art/Menu/Score/Stopwatch_Black",
	L"Art/Menu/Score/WidePlaque",
	L"Art/Menu/Widgets/ListSelect/ListLeftArrow",
	L"Art/Menu/Widgets/ListSelect/ListRightArrow",
	L"Art/Menu/Widgets/Slider/menuslider_bar",
	L"Art/Menu/Widgets/Slider/menuslider_slider",
	L"Art/Old_Art_Holdover/blob2_body",
	L"Art/Old_Art_Holdover/blob2_lwing",
	L"Art/Old_Art_Holdover/blob2_rwing",
	L"Art/Old_Art_Holdover/BlobGoo",
	L"Art/Old_Art_Holdover/BlobGoo2",
	L"Art/Old_Art_Holdover/BlobGoo3",
	L"Art/Old_Art_Holdover/BlobGoo4",
	L"Art/Old_Art_Holdover/BlobGoo5",
	L"Art/Old_Art_Holdover/BlobGoo6",
	L"Art/Old_Art_Holdover/BlobGoo7",
	L"Art/Old_Art_Holdover/BlobGoo8",
	L"Art/Old_Art_Holdover/blue_small",
	L"Art/Old_Art_Holdover/checkpoint3",
	L"Art/Old_Art_Holdover/cloud1",
	L"Art/Old_Art_Holdover/CoinBlue",
	L"Art/Old_Art_Holdover/Fading_Block",
	L"Art/Old_Art_Holdover/FallingBlock1",
	L"Art/Old_Art_Holdover/FallingBlock2",
	L"Art/Old_Art_Holdover/FallingBlock4Cape",
	L"Art/Old_Art_Holdover/Score_Screen_Grey",
	L"Art/Old_Art_Holdover/SpikeyGuy",
	L"Art/Title/BlackSwipe_Vertical",
	L"Art/Title/CopyRightSymbol",
	L"Art/Title/Title_Blur",
	L"Art/Title/Title_Screen",
	L"Art/Title/Title_Trim",
	L"Art/Title/Categories/Arcade/Arcade_Box",
	L"Art/Title/Categories/Arcade/Arcade_BoxLeft",
	L"Art/Title/Categories/Arcade/Scene_Kobbler",
	L"Art/Title/Categories/Arcade/Scene_Kobbler_Blur",
	L"Art/Title/Categories/Story/Scene_Princess"
};

const int TEXTURE_WIDTHS[] = {
	1,
	200,
	150,
	120,
	100,
	143,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	78,
	200,
	200,
	200,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	140,
	290,
	290,
	290,
	290,
	150,
	82,
	52,
	85,
	89,
	220,
	100,
	196,
	100,
	100,
	100,
	196,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	196,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	390,
	390,
	390,
	155,
	140,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	51,
	50,
	100,
	90,
	220,
	80,
	350,
	100,
	512,
	512,
	889,
	300,
	260,
	2048,
	418,
	1064,
	1064,
	238,
	80,
	161,
	67,
	170,
	71,
	350,
	350,
	680,
	92,
	92,
	92,
	92,
	110,
	110,
	110,
	238,
	135,
	190,
	40,
	80,
	85,
	85,
	85,
	70,
	27,
	27,
	27,
	27,
	117,
	30,
	164,
	164,
	150,
	150,
	150,
	166,
	78,
	64,
	194,
	135,
	190,
	40,
	80,
	113,
	164,
	164,
	164,
	164,
	73,
	73,
	155,
	27,
	120,
	1017,
	150,
	244,
	322,
	54,
	582,
	945,
	945,
	448,
	1181,
	287,
	467,
	650,
	1179,
	945,
	945,
	1890,
	1890,
	1179,
	1179,
	400,
	400,
	700,
	90,
	90,
	90,
	90,
	110,
	110,
	110,
	238,
	135,
	190,
	40,
	80,
	85,
	85,
	85,
	30,
	30,
	164,
	256,
	256,
	256,
	77,
	64,
	150,
	190,
	45,
	85,
	40,
	27,
	110,
	959,
	160,
	258,
	310,
	60,
	610,
	668,
	355,
	522,
	671,
	498,
	548,
	411,
	1350,
	1350,
	1350,
	1350,
	572,
	708,
	781,
	681,
	1694,
	207,
	198,
	272,
	192,
	401,
	170,
	250,
	250,
	700,
	90,
	90,
	90,
	90,
	110,
	110,
	110,
	238,
	135,
	190,
	40,
	74,
	85,
	85,
	85,
	70,
	27,
	27,
	27,
	27,
	30,
	164,
	30,
	164,
	77,
	64,
	135,
	190,
	40,
	80,
	164,
	164,
	73,
	73,
	40,
	27,
	110,
	1000,
	150,
	250,
	310,
	66,
	600,
	1416,
	1416,
	1425,
	1493,
	2048,
	1888,
	1699,
	1418,
	1418,
	58,
	250,
	250,
	700,
	113,
	113,
	113,
	113,
	110,
	110,
	110,
	238,
	135,
	180,
	40,
	79,
	85,
	85,
	85,
	62,
	27,
	27,
	27,
	27,
	113,
	30,
	164,
	77,
	64,
	130,
	144,
	190,
	40,
	80,
	73,
	73,
	164,
	164,
	40,
	27,
	97,
	835,
	126,
	244,
	271,
	58,
	468,
	1209,
	1132,
	1417,
	1417,
	1800,
	1654,
	1249,
	1800,
	2048,
	1705,
	1569,
	1836,
	414,
	462,
	466,
	574,
	431,
	628,
	1981,
	250,
	250,
	700,
	90,
	90,
	90,
	90,
	110,
	110,
	110,
	140,
	135,
	190,
	40,
	80,
	85,
	85,
	84,
	70,
	27,
	27,
	27,
	27,
	164,
	30,
	30,
	164,
	77,
	64,
	130,
	190,
	40,
	80,
	40,
	27,
	136,
	1017,
	170,
	253,
	343,
	69,
	582,
	1560,
	1560,
	292,
	367,
	959,
	2048,
	485,
	489,
	780,
	72,
	1205,
	486,
	2048,
	2048,
	250,
	250,
	700,
	87,
	87,
	87,
	87,
	110,
	110,
	110,
	238,
	135,
	190,
	40,
	78,
	85,
	85,
	85,
	27,
	27,
	27,
	27,
	70,
	30,
	164,
	164,
	256,
	256,
	256,
	77,
	64,
	135,
	190,
	35,
	80,
	73,
	73,
	164,
	164,
	40,
	27,
	92,
	863,
	127,
	202,
	302,
	57,
	516,
	200,
	113,
	157,
	157,
	157,
	157,
	157,
	100,
	157,
	157,
	157,
	106,
	157,
	123,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	87,
	157,
	100,
	100,
	113,
	192,
	192,
	1280,
	50,
	250,
	926,
	1197,
	1200,
	56,
	62,
	1280,
	512,
	512,
	155,
	212,
	140,
	150,
	200,
	140,
	200,
	200,
	2000,
	174,
	200,
	200,
	250,
	155,
	172,
	180,
	180,
	200,
	200,
	180,
	700,
	960,
	160,
	800,
	60,
	60,
	342,
	24,
	87,
	98,
	43,
	50,
	50,
	50,
	50,
	50,
	50,
	50,
	50,
	107,
	409,
	633,
	112,
	169,
	124,
	124,
	129,
	1440,
	150,
	2000,
	19,
	1280,
	1280,
	783,
	588,
	440,
	1280,
	1280,
	1280
};

const int TEXTURE_HEIGHTS[] = {
	1,
	200,
	118,
	167,
	161,
	147,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	200,
	168,
	271,
	271,
	271,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	181,
	383,
	383,
	383,
	383,
	170,
	86,
	61,
	107,
	32,
	220,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	94,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	512,
	526,
	526,
	526,
	162,
	140,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	100,
	50,
	54,
	147,
	91,
	165,
	80,
	350,
	122,
	512,
	512,
	500,
	256,
	709,
	128,
	1500,
	450,
	450,
	591,
	199,
	358,
	150,
	361,
	150,
	250,
	250,
	1234,
	90,
	90,
	90,
	90,
	110,
	110,
	110,
	134,
	37,
	39,
	39,
	39,
	85,
	85,
	84,
	64,
	45,
	45,
	45,
	45,
	118,
	674,
	164,
	164,
	149,
	148,
	149,
	150,
	90,
	64,
	171,
	135,
	190,
	40,
	80,
	111,
	166,
	166,
	1000,
	1000,
	82,
	82,
	91,
	56,
	936,
	909,
	940,
	972,
	933,
	935,
	943,
	400,
	400,
	362,
	677,
	384,
	223,
	180,
	584,
	400,
	400,
	800,
	800,
	500,
	500,
	286,
	286,
	1305,
	90,
	90,
	90,
	90,
	110,
	110,
	110,
	134,
	38,
	38,
	37,
	37,
	85,
	85,
	85,
	674,
	700,
	164,
	256,
	256,
	256,
	90,
	64,
	150,
	190,
	45,
	85,
	24,
	56,
	950,
	929,
	950,
	938,
	944,
	1129,
	944,
	1211,
	736,
	866,
	1123,
	484,
	782,
	863,
	600,
	600,
	600,
	600,
	314,
	369,
	303,
	448,
	421,
	117,
	120,
	152,
	114,
	169,
	119,
	211,
	211,
	1305,
	90,
	90,
	90,
	90,
	110,
	110,
	110,
	134,
	38,
	38,
	38,
	35,
	85,
	85,
	85,
	67,
	45,
	45,
	45,
	45,
	674,
	164,
	700,
	164,
	90,
	64,
	135,
	190,
	40,
	80,
	1000,
	1000,
	82,
	82,
	24,
	56,
	939,
	950,
	938,
	939,
	940,
	951,
	944,
	348,
	339,
	450,
	450,
	256,
	800,
	720,
	294,
	337,
	800,
	198,
	198,
	1305,
	120,
	120,
	120,
	120,
	110,
	110,
	110,
	134,
	35,
	32,
	32,
	33,
	85,
	84,
	85,
	93,
	45,
	45,
	45,
	45,
	115,
	674,
	205,
	91,
	64,
	130,
	146,
	190,
	40,
	80,
	82,
	82,
	1000,
	1000,
	23,
	56,
	792,
	747,
	765,
	962,
	782,
	800,
	757,
	350,
	350,
	600,
	600,
	762,
	319,
	418,
	762,
	512,
	426,
	571,
	675,
	312,
	400,
	420,
	314,
	350,
	500,
	399,
	186,
	186,
	1305,
	90,
	90,
	90,
	90,
	110,
	110,
	110,
	79,
	37,
	36,
	35,
	36,
	85,
	85,
	82,
	67,
	45,
	45,
	45,
	45,
	164,
	674,
	700,
	164,
	90,
	64,
	130,
	190,
	40,
	80,
	24,
	56,
	966,
	929,
	952,
	963,
	913,
	955,
	922,
	660,
	660,
	652,
	537,
	353,
	512,
	532,
	411,
	734,
	53,
	825,
	276,
	147,
	147,
	216,
	216,
	1305,
	85,
	85,
	85,
	85,
	110,
	110,
	110,
	134,
	37,
	37,
	38,
	37,
	85,
	85,
	85,
	45,
	45,
	45,
	45,
	64,
	674,
	164,
	164,
	256,
	256,
	256,
	90,
	64,
	135,
	190,
	35,
	80,
	82,
	82,
	1000,
	1000,
	24,
	56,
	815,
	822,
	820,
	804,
	826,
	812,
	825,
	200,
	105,
	157,
	157,
	157,
	157,
	157,
	100,
	157,
	157,
	157,
	81,
	157,
	84,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	157,
	116,
	157,
	100,
	100,
	105,
	32,
	32,
	720,
	43,
	204,
	720,
	720,
	720,
	53,
	45,
	720,
	71,
	71,
	162,
	213,
	177,
	210,
	221,
	183,
	222,
	187,
	2000,
	179,
	209,
	127,
	167,
	259,
	250,
	179,
	215,
	101,
	70,
	132,
	110,
	600,
	187,
	204,
	60,
	60,
	22,
	47,
	85,
	82,
	95,
	50,
	50,
	50,
	50,
	50,
	50,
	50,
	50,
	106,
	409,
	259,
	184,
	191,
	120,
	120,
	127,
	900,
	150,
	24,
	21,
	720,
	720,
	269,
	640,
	720,
	720,
	720,
	720
};

/*void ArtList( std::vector<std::wstring> &v, std::vector<int> &widths, std::vector<int> &heights )
{
	v.reserve( 800 );

	v.push_back( _T( "Art/Transparent" ) );
	v.push_back( _T( "Art/Bob/Accesories/BoxAlone" ) );
	v.push_back( _T( "Art/Bob/Accesories/cart" ) );
	v.push_back( _T( "Art/Bob/Accesories/Castle_jet_pack" ) );
	v.push_back( _T( "Art/Bob/Accesories/SingleWing" ) );
	v.push_back( _T( "Art/Bob/Accesories/Spaceship_Paper" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Duck_0000" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Jump_0000" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Jump_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Jump_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Jump_0003" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Jump_0004" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Jump_0005" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Land_0000" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Land_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Land_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Land_0003" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Land_0004" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Land_0005" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0000" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0003" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0004" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0005" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0006" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0007" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0008" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0009" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0010" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0011" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0012" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0013" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0014" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0015" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0016" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0017" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0018" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0019" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0020" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0021" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0022" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0023" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0024" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0025" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0026" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0027" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0028" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0029" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0030" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0031" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0032" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0033" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0034" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0035" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0036" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0037" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0038" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0039" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0040" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0041" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0042" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0043" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0044" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0045" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0046" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Box_Stand_0047" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Dead_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Horse_0000" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Horse_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Horse_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Jump_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Jump_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Jump_0003" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Jump_0004" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0003" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0004" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0005" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0006" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0007" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0008" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0009" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0010" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0011" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0012" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0013" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0014" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0015" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0016" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0017" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0018" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0019" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0020" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0021" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0022" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0023" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Run_0024" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0000" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_StandtoDuck_0003" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0001" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0002" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0003" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0004" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0005" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0006" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0007" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0008" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0009" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0010" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0011" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0012" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0013" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0014" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0015" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0016" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0017" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0018" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0019" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0020" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0021" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0022" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0023" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0024" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0025" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0026" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0027" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0028" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0029" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0030" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0031" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0032" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0033" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0034" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0035" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0036" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0037" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0038" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0039" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0040" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0041" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0042" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0043" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0044" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0045" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0046" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0047" ) );
	v.push_back( _T( "Art/Bob/Bob_Trimmed/Bob_Stand_0048" ) );
	v.push_back( _T( "Art/Bob/Cart/Bob_Cart_Duck_0001" ) );
	v.push_back( _T( "Art/Bob/Cart/Bob_Cart_Jump_0001" ) );
	v.push_back( _T( "Art/Bob/Cart/Bob_Cart_Stand_0001" ) );
	v.push_back( _T( "Art/Bob/Cart/CartAlone" ) );
	v.push_back( _T( "Art/Bob/Cart/CartIcon" ) );
	v.push_back( _T( "Art/Bob/Cart/CartWheel" ) );
	v.push_back( _T( "Art/Bob/FacialHair/Beard_Super" ) );
	v.push_back( _T( "Art/Bob/FacialHair/Goatee_Black" ) );
	v.push_back( _T( "Art/Bob/FacialHair/Moustache_Brown" ) );
	v.push_back( _T( "Art/Bob/Wheelie/Bob_Wheel_0000" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/A_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Backspace_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/B_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/C_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/D_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Enter_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Esc_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/E_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/F_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/G_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/H_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/I_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/J_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/K_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/LeftRight_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/L_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/M_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/N_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/O_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/P_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Q_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/R_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Space_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/S_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/T_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Up_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/U_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/V_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/W_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/X_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Y_Key" ) );
	v.push_back( _T( "Art/Buttons/Keyboard/Z_Key" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_A" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_B" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_Dir" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_LB" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_LT" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_RB" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_RT" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_Start" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_X" ) );
	v.push_back( _T( "Art/Buttons/Xbox_360/Xbox_Y" ) );
	v.push_back( _T( "Art/Characters/Berries/Poses/cb_crying" ) );
	v.push_back( _T( "Art/Characters/Berries/Poses/cb_enthusiastic" ) );
	v.push_back( _T( "Art/Characters/Berries/Poses/cb_surprised" ) );
	v.push_back( _T( "Art/Coins/Checkpoint_v2" ) );
	v.push_back( _T( "Art/Coins/coin_blue" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00000" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00001" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00002" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00003" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00004" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00005" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00006" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00007" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00008" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00009" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00010" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00011" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00012" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00013" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00014" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00015" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00016" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00017" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00018" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00019" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00020" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00021" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00022" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00023" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00024" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00025" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00026" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00027" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00028" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00029" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00030" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00031" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00032" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00033" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00034" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00035" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00036" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00037" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00038" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00039" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00040" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00041" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00042" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00043" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00044" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00045" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00046" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00047" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00048" ) );
	v.push_back( _T( "Art/Coins/CoinShimmer/Coin_00049" ) );
	v.push_back( _T( "Art/Cursor/hand_closed" ) );
	v.push_back( _T( "Art/Cursor/hand_open" ) );
	v.push_back( _T( "Art/Effects/CoinCollect" ) );
	v.push_back( _T( "Art/Effects/Fire" ) );
	v.push_back( _T( "Art/Effects/Fireball" ) );
	v.push_back( _T( "Art/Effects/Pop" ) );
	v.push_back( _T( "Art/Effects/Smoke2" ) );
	v.push_back( _T( "Art/Effects/Sparkle" ) );
	v.push_back( _T( "Art/Environments/Rain" ) );
	v.push_back( _T( "Art/Environments/Snow" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/Castle_Backdrop_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/castle_chandelier_close" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/castle_chandelier_far" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/castle_lava" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/castle_pillar" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/castle_wall" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/castle_wall_p2" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/Castle_Window_Center_Frame" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/Castle_Window_Center_Mask" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/Castle_Window_Left_Frame" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/Castle_Window_Left_Mask" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/Castle_Window_Right_Frame" ) );
	v.push_back( _T( "Art/Environments/Castle/Background/v2/Castle_Window_Right_Mask" ) );
	v.push_back( _T( "Art/Environments/Castle/Door/door_castle_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Door/door_castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Door/Wall_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_3" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Blob/Blob_Castle_v1_4" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Bouncy_Block/Bouncy_Castle_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Bouncy_Block/Bouncy_Castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Bouncy_Block/Bouncy_Castle_3" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Cloud/Cloud_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_135" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_190" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_40" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Elevator/Elevator_Castle_80" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Falling_Block/Fblock_Castle_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Falling_Block/Fblock_Castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Falling_Block/Fblock_Castle_3" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Base_Castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_3" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Firespinner/Firespinner_Flame_Castle_v1_4" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Floater/Floater_Buzzsaw_Yellow_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Floater/Floater_Chain_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Floater/Floater_Spikey_Castle_v1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Floater/Floater_Spikey_Castle_v2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Flow/Flow_Castle_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Flow/Flow_Castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Flow/Flow_Castle_3" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Flow/Flow_Icon_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Ghost_Block/Ghostblock_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Laser/Laser_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_135" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_190" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_40" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Moving_Block/Movingblock_Castle_80" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Pendulum/Pendulum_Icon_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Serpent/SerpentHead_Castle_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Serpent/SerpentHead_Castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Serpent/Serpent_Castle_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Serpent/Serpent_Castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Serpent/Serpent_Fish_Castle_1" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Serpent/Serpent_Fish_Castle_2" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Spike/spike_base_castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Obstacles/Spike/Spike_Castle" ) );
	v.push_back( _T( "Art/Environments/Castle/Pillars/Pillar_Castle_100" ) );
	v.push_back( _T( "Art/Environments/Castle/Pillars/Pillar_Castle_1000" ) );
	v.push_back( _T( "Art/Environments/Castle/Pillars/Pillar_Castle_150" ) );
	v.push_back( _T( "Art/Environments/Castle/Pillars/Pillar_Castle_250" ) );
	v.push_back( _T( "Art/Environments/Castle/Pillars/Pillar_Castle_300" ) );
	v.push_back( _T( "Art/Environments/Castle/Pillars/Pillar_Castle_50" ) );
	v.push_back( _T( "Art/Environments/Castle/Pillars/Pillar_Castle_600" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_backdrop" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_backdrop_p2" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_bottom_1_p2_trim1" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_bottom_1_p2_trim2" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_bottom_1_trim1" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_bottom_1_trim2" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_bottom_2_p1" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_bottom_2_p2" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_lightshafts" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_lightshafts_p2" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_top_1" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_top_1_p2" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_top_2" ) );
	v.push_back( _T( "Art/Environments/Cave/Background/v3/cave_top_2_p2" ) );
	v.push_back( _T( "Art/Environments/Cave/Door/door_cave_1" ) );
	v.push_back( _T( "Art/Environments/Cave/Door/door_cave_2" ) );
	v.push_back( _T( "Art/Environments/Cave/Door/Wall_Cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Blob/Blob_Cave_1" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Blob/Blob_Cave_2" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Blob/Blob_Cave_3" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Blob/Blob_Cave_4" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Bouncy_Block/Bouncy_Cave_1" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Bouncy_Block/Bouncy_Cave_2" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Bouncy_Block/Bouncy_Cave_3" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Cloud/Cloud_Cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_135" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_190" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_40" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Elevator/Elevator_Cave_80" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Falling_Block/Fblock_Cave_1" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Falling_Block/Fblock_Cave_2" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Falling_Block/Fblock_Cave_3" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Floater/Floater_Chain_Cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Floater/Floater_Rope_Cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Floater/Floater_Spikey_Cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Flow/Flow_Cave_1" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Flow/Flow_Cave_2" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Flow/Flow_Cave_3" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Ghost_Block/Ghostblock_Cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Laser/Laser_Cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_135" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_190" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_40" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Moving_Block/Movingblock_Cave_80" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Spike/Spike_Base_Cave_1" ) );
	v.push_back( _T( "Art/Environments/Cave/Obstacles/Spike/spike_cave" ) );
	v.push_back( _T( "Art/Environments/Cave/Pillars/Pillar_Cave_100" ) );
	v.push_back( _T( "Art/Environments/Cave/Pillars/Pillar_Cave_1000" ) );
	v.push_back( _T( "Art/Environments/Cave/Pillars/Pillar_Cave_150" ) );
	v.push_back( _T( "Art/Environments/Cave/Pillars/Pillar_Cave_250" ) );
	v.push_back( _T( "Art/Environments/Cave/Pillars/Pillar_Cave_300" ) );
	v.push_back( _T( "Art/Environments/Cave/Pillars/Pillar_Cave_50" ) );
	v.push_back( _T( "Art/Environments/Cave/Pillars/Pillar_Cave_600" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer2_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer2_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer2_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer3_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer3_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer3_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer4" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer4_p2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer5" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_castle_layer5_p2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer1_4" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer2_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_4" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_5" ) );
	v.push_back( _T( "Art/Environments/Cloud/Background/v2/cloud_cloud_layer3_6" ) );
	v.push_back( _T( "Art/Environments/Cloud/Door/door_cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Door/door_cloud_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Door/Wall_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Blob/Blob_Cloud_4" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Bouncy_Block/Bouncy_Cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Bouncy_Block/Bouncy_Cloud_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Bouncy_Block/Bouncy_Cloud_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Cloud/Cloud_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_135" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_190" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_40" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Elevator/Elevator_Cloud_80" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Falling_Block/Fblock_Cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Falling_Block/Fblock_Cloud_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Falling_Block/Fblock_Cloud_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Fire Spinner/Firespinner_Base_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Fire Spinner/Firespinner_Flame_Cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Fire Spinner/Firespinner_Flame_Cloud_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Fire Spinner/Firespinner_Flame_Cloud_3" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Fire Spinner/Firespinner_Flame_Cloud_4" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Floater/Cloud_Chain" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Floater/Floater_Boulder_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Floater/Floater_Rope_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Floater/Floater_Spikey_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Ghost_Block/Ghostblock_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Laser/Laser_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_135" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_190" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_40" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Moving_Block/MovingBlock_Cloud_80" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Serpent/Serpent_Cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Serpent/Serpent_Cloud_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Serpent/Serpent_Fish_Cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Serpent/Serpent_Fish_Cloud_2" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Spike/Spike_Base_Cloud_1" ) );
	v.push_back( _T( "Art/Environments/Cloud/Obstacles/Spike/Spike_Cloud" ) );
	v.push_back( _T( "Art/Environments/Cloud/Pillars/Pillar_Cloud_100" ) );
	v.push_back( _T( "Art/Environments/Cloud/Pillars/Pillar_Cloud_1000" ) );
	v.push_back( _T( "Art/Environments/Cloud/Pillars/Pillar_Cloud_150" ) );
	v.push_back( _T( "Art/Environments/Cloud/Pillars/Pillar_Cloud_250" ) );
	v.push_back( _T( "Art/Environments/Cloud/Pillars/Pillar_Cloud_300" ) );
	v.push_back( _T( "Art/Environments/Cloud/Pillars/Pillar_Cloud_50" ) );
	v.push_back( _T( "Art/Environments/Cloud/Pillars/Pillar_Cloud_600" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_backhills_p2_trim" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_backhills_trim" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_backtrees" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_backtrees_p2" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_clouds" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_foretrees" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_foretrees_p2" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_mid_p2_trim" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_mid_trim" ) );
	v.push_back( _T( "Art/Environments/Forest/Background/v2/forest_sky" ) );
	v.push_back( _T( "Art/Environments/Forest/Door/door_forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Door/door_forest_2" ) );
	v.push_back( _T( "Art/Environments/Forest/Door/Wall_Forest" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Blob/Blob_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Blob/Blob_Forest_2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Blob/Blob_Forest_3" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Blob/Blob_Forest_4" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Bouncy_Block/Bouncy_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Bouncy_Block/Bouncy_Forest_2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Bouncy_Block/Bouncy_Forest_3" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Cloud/Cloud_Forest" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_135" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_190" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_40" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Elevator/Elevator_Forest_80" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Falling_Block/Fblock_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Falling_Block/Fblock_Forest_2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Falling_Block/Fblock_Forest_3" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Base_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_3" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Firespinner/Firespinner_Flame_Forest_4" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Floater/Floater_Buzzsaw_Forest" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Floater/Floater_Chain_Forest" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Floater/Floater_Spikey_Forest" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Ghost_Block/Ghostblock_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Laser/Laser_Forest" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_135_v2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Moving_Block/movingblock_forest_150" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_190_v2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_40_v2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Moving_Block/Movingblock_Forest_80_v2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Serpent/Serpent_Fish_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Serpent/Serpent_Fish_Forest_2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Serpent/Serpent_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Serpent/Serpent_Forest_2" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Spike/Spike_Base_Forest_1" ) );
	v.push_back( _T( "Art/Environments/Forest/Obstacles/Spike/Spike_Forest" ) );
	v.push_back( _T( "Art/Environments/Forest/Pillars/Pillar_Forest_100" ) );
	v.push_back( _T( "Art/Environments/Forest/Pillars/Pillar_Forest_1000" ) );
	v.push_back( _T( "Art/Environments/Forest/Pillars/Pillar_Forest_150" ) );
	v.push_back( _T( "Art/Environments/Forest/Pillars/Pillar_Forest_250" ) );
	v.push_back( _T( "Art/Environments/Forest/Pillars/Pillar_Forest_300" ) );
	v.push_back( _T( "Art/Environments/Forest/Pillars/Pillar_Forest_50" ) );
	v.push_back( _T( "Art/Environments/Forest/Pillars/Pillar_Forest_600" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backcastles_p2_trim" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backcastles_trim" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backdrop" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backdrop_p2" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backhills" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backhills2_p2_trim" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backhills2_trim" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_backhills_p2" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_clouds" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_hill1" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_hill2" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_hillandtree" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_plants_1" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_plants_2" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_plants_3" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_plants_4" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_plants_5" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_plants_6" ) );
	v.push_back( _T( "Art/Environments/Hills/Background/v3/hills_rock" ) );
	v.push_back( _T( "Art/Environments/Hills/Door/door_hills_1" ) );
	v.push_back( _T( "Art/Environments/Hills/Door/door_hills_2" ) );
	v.push_back( _T( "Art/Environments/Hills/Door/Wall_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Blob/Blob_Hills_1" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Blob/Blob_Hills_2" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Blob/Blob_Hills_3" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Blob/Blob_Hills_4" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Bouncy_Block/Bouncy_Hills_1" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Bouncy_Block/Bouncy_Hills_2" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Bouncy_Block/Bouncy_Hills_3" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Cloud/Cloud_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_135" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_190" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_40" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Elevator/Elevator_Hills_80" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Falling_Block/Fblock_Hills_1" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Falling_Block/Fblock_Hills_2" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Falling_Block/Fblock_Hills_3" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Base_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_1" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_2" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_3" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Firespinner/Firespinner_Flame_Hills_4" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Floater/Floater_Boulder_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Floater/Floater_Chain_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Floater/Floater_Rope_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Floater/Floater_Spikey_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Ghost_Block/Ghostblock_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Laser/Laser_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_135" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_190" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_40" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Moving_Blocks/Movingblock_Hills_80" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Spike/Spike_Base_Hills_1" ) );
	v.push_back( _T( "Art/Environments/Hills/Obstacles/Spike/Spike_Hills" ) );
	v.push_back( _T( "Art/Environments/Hills/Pillars/Pillar_Hills_100" ) );
	v.push_back( _T( "Art/Environments/Hills/Pillars/Pillar_Hills_1000" ) );
	v.push_back( _T( "Art/Environments/Hills/Pillars/Pillar_Hills_150" ) );
	v.push_back( _T( "Art/Environments/Hills/Pillars/Pillar_Hills_250" ) );
	v.push_back( _T( "Art/Environments/Hills/Pillars/Pillar_Hills_300" ) );
	v.push_back( _T( "Art/Environments/Hills/Pillars/Pillar_Hills_50" ) );
	v.push_back( _T( "Art/Environments/Hills/Pillars/Pillar_Hills_600" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_backdrop" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_backdrop_p2" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_behind_water_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_behind_water_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_behind_water_3" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_clouds" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_rock_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_rock_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_rock_3" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_rock_4" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_rock_5" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_seamonster" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_water_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Background/v2/sea_water_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Door/door_sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Door/door_sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Door/Wall_Sea" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Blob/Blob_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Blob/Blob_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Blob/Blob_Sea_3" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Blob/Blob_Sea_4" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Bouncy_Block/Bouncy_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Bouncy_Block/Bouncy_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Bouncy_Block/Bouncy_Sea_3" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Cloud/Cloud_Sea" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_135" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_190" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_40" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Elevator/Elevator_Sea_80" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Falling_Block/Fblock_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Falling_Block/Fblock_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Falling_Block/Fblock_Sea_3" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_3" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Firespinner/Firespinner_Flame_Sea_4" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Firespinner/firespinner_gear_dkpurp" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Floater/Floater_Chain_Sea" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Floater/Floater_Spikey_Sea" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Floater/Floater_Spikey_Sea_v2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Flow/Flow_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Flow/Flow_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Flow/Flow_Sea_3" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Ghost_Block/Ghostblock_Sea" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Laser/Laser_Sea" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_135" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_190" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_40" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Moving_Block/Movingblock_Sea_80" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Serpent/Serpent_Fish_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Serpent/Serpent_Fish_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Serpent/Serpent_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Serpent/Serpent_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Spike/Spike_Base_Sea_1" ) );
	v.push_back( _T( "Art/Environments/Sea/Obstacles/Spike/Spike_Sea_2" ) );
	v.push_back( _T( "Art/Environments/Sea/Pillars/Pillar_Sea_100" ) );
	v.push_back( _T( "Art/Environments/Sea/Pillars/Pillar_Sea_1000" ) );
	v.push_back( _T( "Art/Environments/Sea/Pillars/Pillar_Sea_150" ) );
	v.push_back( _T( "Art/Environments/Sea/Pillars/Pillar_Sea_250" ) );
	v.push_back( _T( "Art/Environments/Sea/Pillars/Pillar_Sea_300" ) );
	v.push_back( _T( "Art/Environments/Sea/Pillars/Pillar_Sea_50" ) );
	v.push_back( _T( "Art/Environments/Sea/Pillars/Pillar_Sea_600" ) );
	v.push_back( _T( "Art/HeroItems/Hats/HatPic_Horns" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_afro" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_antlers" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_arrow" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_bag" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_beard" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_brain" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_bubble" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_bunny" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_cone" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_disguise" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_fedora" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_gosu" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_halo" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_knight" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_miner" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_pirate" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_pope" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_pumkin" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_rastafari" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_rice" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_robinhood" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_santa" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_sombrero" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_tiki" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_tophat" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_viking" ) );
	v.push_back( _T( "Art/HeroItems/Hats/hat_wizard" ) );
	v.push_back( _T( "Art/HeroItems/Hats/LeftHorn" ) );
	v.push_back( _T( "Art/HeroItems/Hats/RightHorn" ) );
	v.push_back( _T( "Art/HeroItems/Hats/TestHat" ) );
	v.push_back( _T( "Art/LoadScreen_Initial/LoadFill" ) );
	v.push_back( _T( "Art/LoadScreen_Initial/LoadOutline" ) );
	v.push_back( _T( "Art/LoadScreen_Level/LoadingStrip" ) );
	v.push_back( _T( "Art/Menu/BackArrow2" ) );
	v.push_back( _T( "Art/Menu/directionarrow" ) );
	v.push_back( _T( "Art/Menu/Backplates/backplate_1080x840" ) );
	v.push_back( _T( "Art/Menu/Backplates/backplate_1230x740" ) );
	v.push_back( _T( "Art/Menu/Backplates/backplate_1500x900" ) );
	v.push_back( _T( "Art/Menu/CharacterMenu/Arrow_Left" ) );
	v.push_back( _T( "Art/Menu/CharacterMenu/Arrow_Right" ) );
	v.push_back( _T( "Art/Menu/CharacterMenu/CharSelect" ) );
	v.push_back( _T( "Art/Menu/CustomLevel/Length" ) );
	v.push_back( _T( "Art/Menu/CustomLevel/LengthBack" ) );
	v.push_back( _T( "Art/Menu/Icons/Icon_Checkpoint_v2" ) );
	v.push_back( _T( "Art/Menu/Icons/Hero/HeroIcon_Custom" ) );
	v.push_back( _T( "Art/Menu/Icons/Hero/HeroIcon_Double" ) );
	v.push_back( _T( "Art/Menu/Icons/Hero/HeroIcon_Jetman" ) );
	v.push_back( _T( "Art/Menu/Icons/Hero/HeroIcon_Phase" ) );
	v.push_back( _T( "Art/Menu/Icons/Hero/HeroIcon_Random" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/CeilingIcon" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/Dodge" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/Icon_Fireball" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/Icon_FireSpinner" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/Icon_Laser" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/Jump" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/SpeedIcon" ) );
	v.push_back( _T( "Art/Menu/Icons/Upgrades/SpikeIcon" ) );
	v.push_back( _T( "Art/Menu/Powerups/Powerup_Computer" ) );
	v.push_back( _T( "Art/Menu/Powerups/Powerup_Path" ) );
	v.push_back( _T( "Art/Menu/Powerups/Powerup_Slowmo" ) );
	v.push_back( _T( "Art/Menu/Replay_GUI/End" ) );
	v.push_back( _T( "Art/Menu/Replay_GUI/Paused" ) );
	v.push_back( _T( "Art/Menu/Score/Bob_Dead" ) );
	v.push_back( _T( "Art/Menu/Score/LevelCleared" ) );
	v.push_back( _T( "Art/Menu/Score/Score_Screen" ) );
	v.push_back( _T( "Art/Menu/Score/Stopwatch_Black" ) );
	v.push_back( _T( "Art/Menu/Score/WidePlaque" ) );
	v.push_back( _T( "Art/Menu/Widgets/ListSelect/ListLeftArrow" ) );
	v.push_back( _T( "Art/Menu/Widgets/ListSelect/ListRightArrow" ) );
	v.push_back( _T( "Art/Menu/Widgets/Slider/menuslider_bar" ) );
	v.push_back( _T( "Art/Menu/Widgets/Slider/menuslider_slider" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/blob2_body" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/blob2_lwing" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/blob2_rwing" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo2" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo3" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo4" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo5" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo6" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo7" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/BlobGoo8" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/blue_small" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/checkpoint3" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/cloud1" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/CoinBlue" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/Fading_Block" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/FallingBlock1" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/FallingBlock2" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/FallingBlock4Cape" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/Score_Screen_Grey" ) );
	v.push_back( _T( "Art/Old_Art_Holdover/SpikeyGuy" ) );
	v.push_back( _T( "Art/Title/BlackSwipe_Vertical" ) );
	v.push_back( _T( "Art/Title/CopyRightSymbol" ) );
	v.push_back( _T( "Art/Title/Title_Blur" ) );
	v.push_back( _T( "Art/Title/Title_Screen" ) );
	v.push_back( _T( "Art/Title/Title_Trim" ) );
	v.push_back( _T( "Art/Title/Categories/Arcade/Arcade_Box" ) );
	v.push_back( _T( "Art/Title/Categories/Arcade/Arcade_BoxLeft" ) );
	v.push_back( _T( "Art/Title/Categories/Arcade/Scene_Kobbler" ) );
	v.push_back( _T( "Art/Title/Categories/Arcade/Scene_Kobbler_Blur" ) );
	v.push_back( _T( "Art/Title/Categories/Story/Scene_Princess" ) );
}*/

#endif
