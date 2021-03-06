#include <small_header.h>
#include "Game/Menus/Menu Components/MenuItem.h"

#include "Core/FancyVector2.h"
#include "Game/Localization.h"
#include "Game/Tools/Oscillate.h"
#include "Core/Input/ButtonCheck.h"
#include "Core/Sound/EzSound.h"
#include "Core/Text/EzFont.h"
#include "Core/Text/EzText.h"
#include "Game/Menus/Menu.h"
#include "Game/Player/PlayerManager.h"
#include "Game/Objects/Icon.h"
#include "Game/Player/PlayerData.h"
#include "Game/Tools/Camera.h"
#include "Game/Tools/Resources.h"
#include "Game/Tools/Tools.h"

#include "Game/Level/Level.h"

#include "Hacks/List.h"

namespace CloudberryKingdom
{

	void MenuItem::InitializeStatics()
	{
		MenuItem::ActivatingPlayer = -1;
	}

	// Statics
	int MenuItem::ActivatingPlayer;


	boost::shared_ptr<MenuItem> MenuItem::Clone()
	{
		boost::shared_ptr<MenuItem> clone = MakeMagic( MenuItem, ( MyText->Clone(), MySelectedText->Clone() ) );
		if ( Icon != 0 )
		{
			clone->Icon = Icon->Clone();
			clone->Icon->FancyPos->SetCenter( clone->FancyPos );
		}
		return clone;
	}

	void MenuItem::SetSelectedPos( Vector2 selectedpos )
	{
		SelectedPos = selectedpos;

		if ( SelectedPos.Y == -1 )
			SelectedPos.Y = Pos.Y;
	}

	const Vector2 &MenuItem::getSetPos() const
	{
		return Pos;
	}

	void MenuItem::setSetPos( const Vector2 &value )
	{
		Pos = SelectedPos = value;
	}

	void MenuItem::Shift( Vector2 shift )
	{
		Pos += shift;
		SelectedPos += shift;
	}

	void MenuItem::SetIcon( const boost::shared_ptr<ObjectIcon> &Icon )
	{
		this->Icon = Icon;
		Icon->FancyPos->SetCenter( FancyPos );
	}

	void MenuItem::SubstituteText( Localization::Words text )
	{
		MyText->SubstituteText( text );
		MySelectedText->SubstituteText( text );
	}

	void MenuItem::SubstituteText( const std::wstring &text )
	{
		MyText->SubstituteText( text );
		MySelectedText->SubstituteText( text );
	}

	void MenuItem::setGo( const boost::shared_ptr<Lambda_1<boost::shared_ptr<MenuItem> > > &value )
	{
		_Go = value;
		if ( _Go != 0 )
			setOverrideA( true );
	}

	const boost::shared_ptr<Lambda_1<boost::shared_ptr<MenuItem> > > &MenuItem::getGo() const
	{
		return _Go;
	}

	const bool &MenuItem::getOverrideA() const
	{
		return _OverrideA;
	}

	void MenuItem::setOverrideA( const bool &value )
	{
		_OverrideA = value;
		//if (value && this is MenuSliderBase)
		//    Tools::Write("");
	}

	const std::wstring MenuItem::getMyString() const
	{
		if ( MyText == 0 )
			return std::wstring( L"" );
		else
			return MyText->MyString;
	}

	void MenuItem::Release()
	{
		MyObject.reset();
		MyMenu.reset();

		if ( MyText != 0 ) MyText->Release(); MyText.reset();
		if ( MySelectedText != 0 ) MySelectedText->Release(); MySelectedText.reset();

		SelectSound.reset(); SlideSound.reset(); ListScrollSound.reset();
		if ( FancyPos != 0 ) FancyPos->Release(); FancyPos.reset();
		Icon.reset();
		OnClick.reset();
		AdditionalOnSelect.reset();
		MySelectedFont.reset(); MyFont.reset();

		_Go.reset();
	}

	void MenuItem::SetFade( bool Fade )
	{
		if ( FadedOut != Fade )
		{
			if ( Fade )
				FadeOut();
			else
				FadeIn();

			FadedOut = Fade;
		}
	}

	void MenuItem::FadeOut()
	{
		MyText->MyFloatColor.W = .3f;
		MyText->OutlineColor.W = .3f;
	}

	void MenuItem::FadeIn()
	{
		MyText->MyFloatColor.W = 1;
		MyText->OutlineColor.W = 1;
	}

	MenuItem::MenuItem()
	{
		InitializeInstanceFields();
	}

	boost::shared_ptr<MenuItem> MenuItem::MenuItem_Construct()
	{
		SetToDefaultColors();

		setOverrideA( false );

		return boost::static_pointer_cast<MenuItem>( shared_from_this() );
	}

	void MenuItem::SetToDefaultColors()
	{
		MySelectedColor = ( bColor( 255, 255, 255, 255 ) ).ToVector4();
		MyColor = ( bColor( 220, 220, 220, 200 ) ).ToVector4();

		MySelectedFont = Resources::Font_Grobold42;
		MyFont = Resources::Font_Grobold42;
	}

	Vector2 MenuItem::Size()
	{
		return Vector2( Width(), Height() );
	}

	float MenuItem::Height()
	{
		if ( MyText == 0 )
			return 50;
		else
			return MyText->GetWorldHeight();
	}

	float MenuItem::Width()
	{
		if ( MyText == 0 )
			return 50;
		else
			return __max( MyText->GetWorldWidth(), MySelectedText->GetWorldWidth() );
	}

	MenuItem::MenuItem( const boost::shared_ptr<EzText> &Text )
	{
		InitializeInstanceFields();
	}
	boost::shared_ptr<MenuItem> MenuItem::MenuItem_Construct( const boost::shared_ptr<EzText> &Text )
	{
		Init( Text, Text->Clone() );

		return boost::static_pointer_cast<MenuItem>( shared_from_this() );
	}

	MenuItem::MenuItem( const boost::shared_ptr<EzText> &Text, const std::wstring &Name )
	{
		InitializeInstanceFields();
	}
	boost::shared_ptr<MenuItem> MenuItem::MenuItem_Construct( const boost::shared_ptr<EzText> &Text, const std::wstring &Name )
	{
		Init( Text, Text->Clone() );
		this->Name = Name;

		return boost::static_pointer_cast<MenuItem>( shared_from_this() );
	}

	MenuItem::MenuItem( const boost::shared_ptr<EzText> &Text, const boost::shared_ptr<EzText> &SelectedText )
	{
		InitializeInstanceFields();
	}
	boost::shared_ptr<MenuItem> MenuItem::MenuItem_Construct( const boost::shared_ptr<EzText> &Text, const boost::shared_ptr<EzText> &SelectedText )
	{
		Init( Text, SelectedText );

		return boost::static_pointer_cast<MenuItem>( shared_from_this() );
	}

	void MenuItem::ScaleText( float scale )
	{
		MyText->setScale( MyText->getScale() * scale );
		MySelectedText->setScale( MySelectedText->getScale() * scale );
	}

	void MenuItem::Init( const boost::shared_ptr<EzText> &Text, const boost::shared_ptr<EzText> &SelectedText )
	{
		//MyOscillateParams.Set(2f, 1.03f, .05f);
		MyOscillateParams.Set( 2.05f, 1.0295f,.045f );

		Selectable = true;

		MyText = Text;
		MySelectedText = SelectedText;
	}

	void MenuItem::setFixedToCamera( const bool &value )
	{
		if ( MyText != 0 )
			MyText->FixedToCamera = value;
		if ( MySelectedText != 0 )
			MySelectedText->FixedToCamera = value;
	}

	const bool MenuItem::getFixedToCamera() const
	{
		if ( MyText != 0 )
			return MyText->FixedToCamera;
		else
			return false;
	}

	void MenuItem::SetTextSelection( bool Selected )
	{
		if ( !Selectable )
			Selected = false;
	}

	void MenuItem::UpdatePos()
	{
		MyText->_Pos = Pos + PosOffset;
		MySelectedText->_Pos = SelectedPos + PosOffset;
	}

	void MenuItem::DrawBackdrop( bool Selected )
	{
		if ( Selected )
		{
			if ( MySelectedText != 0 )
				MySelectedText->_Pos = SelectedPos + PosOffset;
		}
		else
		{
			if ( MyText != 0 )
				MyText->_Pos = Pos + PosOffset;
		}
	}

	const bool MenuItem::getOnScreen() const
	{
		if ( getFixedToCamera() )
			return true;

		if ( MyText->getPos().Y > Tools::CurLevel->getMainCamera()->TR.Y + 500 )
			return false;
		if ( MyText->getPos().Y < Tools::CurLevel->getMainCamera()->BL.Y - 500 )
			return false;
		return true;
	}

	void MenuItem::DrawText( const boost::shared_ptr<Camera> &cam, bool Selected )
	{
		if ( !getOnScreen() )
			return;

		if ( MyMenu->CurDrawLayer != MyDrawLayer || !Show )
			return;

		GrayOut();

	#if defined(PC_VERSION)
		if ( Selected && ( ButtonCheck::MouseInUse || !MyMenu->MouseOnly ) || AlwaysDrawAsSelected && MyOscillateParams.MyType != OscillateParams::Type_OSCILLATE )
	#else
		if ( Selected || AlwaysDrawAsSelected && MyOscillateParams.MyType != OscillateParams::Type_OSCILLATE )
	#endif
		{
			// The selected text of the current menu item may not ever have been drawn,
			// so update its CameraZoom manually
			MySelectedText->setMyCameraZoom( getMyCameraZoom() );

			// Oscillate
			float HoldScale = MySelectedText->getScale();
			Vector2 HoldPos = MySelectedText->getPos();
			Vector2 HoldShadowOffset = MySelectedText->ShadowOffset;
			if ( SelectionOscillate )
			{
				float scale = MyOscillateParams.GetScale();

                Vector2 PosShift = Vector2(0);
                if ( !MySelectedText->Centered )
                {
                    PosShift = Vector2(.5f * (scale - 1.f) * MySelectedText->GetWorldWidth(), 0);
                    MySelectedText->setPos( MySelectedText->getPos() - PosShift );
                }

				MySelectedText->setScale( MySelectedText->getScale() * scale );
				MySelectedText->ShadowScale = 1 / ( .9f * ( scale - 1 ) + 1 );
				MySelectedText->ShadowOffset *= 15 * ( scale - 1 ) + 1;
				MySelectedText->ShadowOffset -= .7f * PosShift;
				MySelectedText->ShadowOffset.X = .5f * ( MySelectedText->ShadowOffset.X + HoldShadowOffset.X - PosShift.X );
				//MySelectedText.ShadowOffset.Y *= 6f * (scale - 1) + 1;
			}

			// Draw the selected text
			MySelectedText->Draw( cam, false );

			if ( SelectionOscillate )
			{
				MySelectedText->setScale( HoldScale );
				MySelectedText->setPos( HoldPos );
				MySelectedText->ShadowOffset = HoldShadowOffset;
			}

			PrevSelected = true;
		}
		else
		{
			MyOscillateParams.Reset();

			// Draw the unselected text
			MyText->Draw( cam, false );

			PrevSelected = false;
		}

		DeGrayOut();
	}

	void MenuItem::GrayOut()
	{
		if ( !Selectable && GrayOutOnUnselectable )
			DoGrayOut();
	}

	void MenuItem::DeGrayOut()
	{
		if ( !Selectable && GrayOutOnUnselectable )
			DoDeGrayOut();
	}

	void MenuItem::DoGrayOut()
	{
		MyText->MyFloatColor.W = .5f;
		if ( Icon != 0 && boost::dynamic_pointer_cast<PictureIcon>( Icon ) != 0 )
			( boost::static_pointer_cast<PictureIcon>( Icon ) )->IconQuad->setAlpha( .5f );
	}

	void MenuItem::DoDeGrayOut()
	{
		MyText->MyFloatColor.W = 1;
		if ( Icon != 0 && boost::dynamic_pointer_cast<PictureIcon>( Icon ) != 0 )
			( boost::static_pointer_cast<PictureIcon>( Icon ) )->IconQuad->setAlpha( 1 );
	}

	void MenuItem::setInclude( const bool &value )
	{
		Show = Selectable = value;
	}

	void MenuItem::OnSelect()
	{
		if ( AdditionalOnSelect != 0 )
			AdditionalOnSelect->Apply();

		// Stop jiggling
		if ( JiggleOnGo )
		{
			MyOscillateParams.SetType( OscillateParams::Type_OSCILLATE );
			if ( Icon != 0 )
				Icon->MyOscillateParams.SetType( OscillateParams::Type_OSCILLATE );
		}
	}

	const Vector2 &MenuItem::getMyCameraZoom() const
	{
		return _MyCameraZoom;
	}

	void MenuItem::setMyCameraZoom( const Vector2 &value )
	{
		_MyCameraZoom = value;
	}

	void MenuItem::Draw()
	{
		this->Draw( false, Tools::getCurCamera(), false );
		this->Draw( true, Tools::getCurCamera(), false );
	}

	bool MenuItem::DrawBase( bool Text, const boost::shared_ptr<Camera> &cam, bool Selected )
	{
		setMyCameraZoom( cam->getZoom() );

		if ( MyDrawLayer != MyMenu->CurDrawLayer || !Show )
			return true;

		if ( !Selectable )
			Selected = false;

		if ( FancyPos != 0 )
		{
			FancyPos->RelVal = Pos + PosOffset;
			FancyPos->Update();
		}

		// If just selected perfrom the OnSelect callback
		if ( Selected != this->Selected && Selected )
		{
			OnSelect();
		}
		this->Selected = Selected;

		return false;
	}

	void MenuItem::Draw( bool Text, const boost::shared_ptr<Camera> &cam, bool Selected )
	{
		if ( DrawBase( Text, cam, Selected ) )
			return;

		GrayOut();

		SetTextSelection( Selected );

		if ( Text )
		{
			if ( Selected || !CustomSelectedPos )
			{
				MyText->_Pos = Pos + PosOffset;
				MySelectedText->_Pos = SelectedPos + PosOffset;
			}
			else
			{
				MyText->_Pos = SelectedPos + PosOffset;
				MySelectedText->_Pos = SelectedPos + PosOffset;
			}

			DrawText( cam, Selected );
		}
		else
		{
			if ( Icon != 0 )
				Icon->Draw( Selected );
		}

		DeGrayOut();
	}

#if defined(WINDOWS)
	bool MenuItem::HitTest()
	{
		return HitTest( Tools::MouseGUIPos( getMyCameraZoom() ) );
	}
#endif

#if defined(WINDOWS)
	bool MenuItem::HitTest( Vector2 pos )
	{
		return HitTest( pos, Vector2() );
	}
#endif

#if defined(WINDOWS)
	bool MenuItem::HitTest( Vector2 pos, Vector2 padding )
	{
		return ColWithIcon && Icon != 0 && Icon->HitTest( pos ) || MyText->HitTest( pos, Padding + padding );
	}
#endif

    PlayerIndex MenuItem::ActivatingPlayerIndex()
    {
        int p = MenuItem::ActivatingPlayer;
        if (p < 0) return PlayerIndex_One;

        return (PlayerIndex)p;
    }

	boost::shared_ptr<PlayerData> MenuItem::GetActivatingPlayerData()
	{
		int p = MenuItem::ActivatingPlayer;
		if ( p < 0 )
			p = PlayerManager::FirstPlayer;
		return PlayerManager::Get( p );
	}

	void MenuItem::PhsxStep( bool Selected )
	{
		// When a select jiggle animation is done, go back to oscillating
		if ( MyOscillateParams.MyType == OscillateParams::Type_JIGGLE && MyOscillateParams.Done )
			MyOscillateParams.SetType( OscillateParams::Type_OSCILLATE );

		FancyPos->RelVal = Pos + PosOffset;
		FancyPos->Update();

		if ( MyMenu != 0 )
		{
			Control = MyMenu->getControl();
			setFixedToCamera( MyMenu->FixedToCamera );
		}

	#if defined(PC_VERSION)
		// Mouse interact
		bool SelectThis = false;
		if ( ButtonCheck::MouseInUse && ( Tools::MouseNotDown() || MyMenu->SlipSelect ) && !MyMenu->HasSelectedThisStep && Selectable )
			if ( HitTest() )
			{
				SelectThis = true;
				MyMenu->HasSelectedThisStep = true;
			}
	#endif

		if ( !Selected )
		{
	#if defined(PC_VERSION)
			// Mouse interact
			if ( SelectThis )
				MyMenu->SelectItem( shared_from_this() );
	#endif
			return;
		}

		bool Activate = false;

		ButtonData data = ButtonCheck::State( ControllerButtons_A, Control );
		if ( data.Pressed )
		{
			ActivatingPlayer = data.PressingPlayer;
			Activate = true;
		}

		// Don't activate the item if it isn't being drawn as selected
		if ( MyMenu->NoneSelected )
			Activate = false;

	#if defined(PC_VERSION)
		// Don't activate the item if the menu is mouse only and the mouse isn't in use
		if ( MyMenu->MouseOnly && !ButtonCheck::MouseInUse )
			Activate = false;

		// Don't activate the itme if the mouse is in use and isn't over the item
		if ( ButtonCheck::MouseInUse && !HitTest() )
			Activate = false;
	#else
		if ( MyMenu->MouseOnly )
			Activate = false;
	#endif

		// Mouse down over the item
	#if defined(PC_VERSION)
		if ( OnClick != 0 && ButtonCheck::MouseInUse && Tools::CurMouseDown() && HitTest() )
			OnClick->Apply( shared_from_this() );
	#endif
		// Go function
		if ( Activate && getGo() != 0 )
		{
			DoActivationAnimation();

			if ( SelectSound != 0 )
				SelectSound->Play();
			getGo()->Apply( shared_from_this() );
			MyMenu->LastActivatedItem = IndexOf( MyMenu->Items, shared_from_this() );
			ButtonCheck::PreventInput();
		}
	}

	void MenuItem::DoActivationAnimation()
	{
		if ( JiggleOnGo )
		{
			MyOscillateParams.Reset();
			MyOscillateParams.SetType( OscillateParams::Type_JIGGLE );
			if ( Icon != 0 )
				Icon->MyOscillateParams.SetType( OscillateParams::Type_JIGGLE );
		}
	}

	void MenuItem::InitializeInstanceFields()
	{
		Code = 0;
		Name = std::wstring( L"" );
		UnaffectedByScroll = false;
		MyObject = 0;
		MyInt = 0;
		FancyPos = boost::make_shared<FancyVector2>();
		CustomSelectedPos = false;
		SelectionOscillate = true;
		AlwaysDrawAsSelected = false;
		ColWithIcon = true;
		TextWidth = 0;
		Control = 0;
		Selectable = false;
		FadedOut = false;
		Selected = false;
		PrevSelected = false;
		_OverrideA = false;
		MyDrawLayer = 0;
		GrayOutOnUnselectable = false;
		Show = true;
		JiggleOnGo = true;
		_MyCameraZoom = Vector2(1);
#if defined(WINDOWS)
		Padding = Vector2( -22, -7 );
#endif
	}
}
