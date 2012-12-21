#include <Input/GamePad.h>

#include <cafe/pad.h>
#include <cafe/vpad.h>
//#include <cafe/wpad.h>

GamePadState PAD_STATE[ PAD_MAX_CONTROLLERS ];
/*static void ConnectCallback( s32 chan, s32 reason )
{
	if( reason >= 0 )
		WPADSetDataFormat( chan, WPAD_FMT_CORE );
}*/

void GamePad::Initialize()
{
	PADInit();
	/*WPADInit();

	for( int i = 0; i < WPAD_MAX_CONTROLLERS; i++ )
		WPADSetConnectCallback( i, ConnectCallback );*/
}

void GamePad::Update()
{
	/*PADStatus status[ PAD_MAX_CONTROLLERS ];
	memset( status, 0, sizeof( status ) );

	for( int i = 0; i < WPAD_MAX_CONTROLLERS; i++ )
	{
		u32 type;
		s32 status = WPADProbe( i, &type );

		if( status != WPAD_ERR_NO_CONTROLLER )
		{
			WPADStatus      cr;
			WPADFSStatus    fs;
			WPADCLStatus    cl;

			u16 button;
			WPADRead( i, &cr );

			if( cr.err == WPAD_ERR_NONE
				|| cr.err == WPAD_ERR_CORRUPTED )
			{
			}
		}
	}*/

	PADStatus status[ PAD_MAX_CONTROLLERS ];
	memset( status, 0, sizeof( status ) );
	PADRead( status );
	static Vector2 textPos( 0, 0 );

	memset( PAD_STATE, 0, sizeof( PAD_STATE ) );

	for( int i = 0; i < PAD_MAX_CONTROLLERS; ++i )
	{
		if( status[ i ].err == PAD_ERR_NO_CONTROLLER
			&& status[ i ].err == PAD_ERR_NOT_READY )
		{
			PAD_STATE[ i ].IsConnected = false;
			continue;
		}

		PAD_STATE[ i ].IsConnected = true;

		PAD_STATE[ i ].Buttons.A = ( status[ i ].button & PAD_BUTTON_A ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.B = ( status[ i ].button & PAD_BUTTON_B ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.X = ( status[ i ].button & PAD_BUTTON_X ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.Y = ( status[ i ].button & PAD_BUTTON_Y ) ? ButtonState_Pressed : ButtonState_Released;

		PAD_STATE[ i ].Buttons.LeftShoulder = ( status[ i ].button & PAD_BUTTON_L ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.RightShoulder = ( status[ i ].button & PAD_BUTTON_R ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.Start = ( status[ i ].button & PAD_BUTTON_START ) ? ButtonState_Pressed : ButtonState_Released;

		PAD_STATE[ i ].DPad.Down = ( status[ i ].button & PAD_BUTTON_DOWN ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].DPad.Left = ( status[ i ].button & PAD_BUTTON_LEFT ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].DPad.Right = ( status[ i ].button & PAD_BUTTON_RIGHT ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].DPad.Up = ( status[ i ].button & PAD_BUTTON_UP ) ? ButtonState_Pressed : ButtonState_Released;
		/*PAD_STATE[ i ].Buttons.LeftStick = ( status[ i ].button & PAD_BUTTON_START ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.RightStick = ( status[ i ].button & PAD_BUTTON_START ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.Back = ( status[ i ].button & PAD_BUTTON_START ) ? ButtonState_Pressed : ButtonState_Released;
		PAD_STATE[ i ].Buttons.BigButton = ( status[ i ].button & PAD_BUTTON_MENU ) ? ButtonState_Pressed : ButtonState_Released;*/

		PAD_STATE[ i ].Triggers.Left = status[ i ].triggerLeft / 255.f;
		PAD_STATE[ i ].Triggers.Right = status[ i ].triggerRight / 255.f;

		PAD_STATE[ i ].ThumbSticks.Left = Vector2( status[ i ].stickX / 128.f, status[ i ].stickY / 128.f );
		PAD_STATE[ i ].ThumbSticks.Right = Vector2( status[ i ].substickX / 128.f, status[ i ].substickY / 128.f );
	}
}

GamePadState GamePad::GetState( PlayerIndex index )
{
	return PAD_STATE[ static_cast<int>( index ) ];
}

void GamePad::SetVibration( PlayerIndex index, float left, float right )
{
}

void GamePad::Shutdown()
{
}