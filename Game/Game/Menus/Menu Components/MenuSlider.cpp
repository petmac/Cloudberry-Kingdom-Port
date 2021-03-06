#include <small_header.h>
#include "Game/Menus/Menu Components/MenuSlider.h"

#include "Core/Graphics/Draw/Quads/QuadClass.h"
#include "Core/Text/EzText.h"
#include "Game/Menus/Menu.h"
#include "Game/Menus/Menu Components/MenuSliderBase.h"
#include "Game/Tools/Camera.h"
#include "Game/Tools/Tools.h"

#include "Game/Tools/WrappedFloat.h"
#include "Game/Objects/Icon.h"

namespace CloudberryKingdom
{

	void MenuSlider::DoGrayOut()
	{
		MenuSliderBase::DoGrayOut();

		SliderBack->setAlpha( .5f );
		Slider->setAlpha( .5f );
	}

	void MenuSlider::DoDeGrayOut()
	{
		MenuSliderBase::DoDeGrayOut();

		SliderBack->setAlpha( 1 );
		Slider->setAlpha( 1 );
	}

	void MenuSlider::Reset()
	{
		setVal( getMyFloat()->DefaultValue );
	}

	MenuSlider::MenuSlider( const boost::shared_ptr<EzText> &Text )
	{
		InitializeInstanceFields();
	}
	boost::shared_ptr<MenuSlider> MenuSlider::MenuSlider_Construct( const boost::shared_ptr<EzText> &Text )
	{
		MenuSliderBase::MenuSliderBase_Construct( Text );

		Init( Text, Text->Clone() );
		InitializeSlider();

		return boost::static_pointer_cast<MenuSlider>( shared_from_this() );
	}

	MenuSlider::MenuSlider( const boost::shared_ptr<EzText> &Text, const boost::shared_ptr<EzText> &SelectedText )
	{
		InitializeInstanceFields();
	}
	boost::shared_ptr<MenuSlider> MenuSlider::MenuSlider_Construct( const boost::shared_ptr<EzText> &Text, const boost::shared_ptr<EzText> &SelectedText )
	{
		MenuSliderBase::MenuSliderBase_Construct( Text, SelectedText );

		Init( Text, SelectedText );
		InitializeSlider();

		return boost::static_pointer_cast<MenuSlider>( shared_from_this() );
	}

	void MenuSlider::InitializeSlider()
	{
		MenuSliderBase::InitializeSlider();

		SelectionOscillate = true;

	#if defined(PC_VERSION)
		BL_HitPadding.X += 40;
		TR_HitPadding.X += 40;
	#endif

		SliderBack = boost::make_shared<QuadClass>();
		SliderBack->Quad_Renamed.setMyTexture( Menu::DefaultMenuInfo::SliderBack_Texture );
		Vector2 Size = Vector2( 250, 35 ) * 1.35f;
		SliderBack->Base.e1 *= Size.X;
		SliderBack->Base.e2 *= Size.Y;

		Slider = boost::make_shared<QuadClass>();
		Slider->Quad_Renamed.setMyTexture( Menu::DefaultMenuInfo::Slider_Texture );
		Size = Vector2( 28, 55 ) * 1.35f;
		Slider->Base.e1 *= Size.X;
		Slider->Base.e2 *= Size.Y;
	}

	Vector2 MenuSlider::getSliderBackSize() const
	{
		return SliderBack->Base.GetScale();
	}

	void MenuSlider::setSliderBackSize( const Vector2 &value )
	{
		SliderBack->Base.SetScale( value );
	}

	Vector2 MenuSlider::getSliderSize() const
	{
		return Slider->Base.GetScale();
	}

	void MenuSlider::setSliderSize( const Vector2 &value )
	{
		Slider->Base.SetScale( value );
	}

	float MenuSlider::Height()
	{
		return.65f * 2 * SliderBack->Base.e2.Y;
	}

	float MenuSlider::Width()
	{
		return MyText->GetWorldWidth() + 2 * SliderBack->Base.e1.X;
	}

	void MenuSlider::CalcEndPoints()
	{
		CalcRelEndPoints();

		Start = RelStart + Pos + PosOffset + SliderShift;
		End = RelEnd + Pos + PosOffset + SliderShift;
	}

	void MenuSlider::CalcRelEndPoints()
	{
		if ( CustomEndPoints )
		{
			RelStart = CustomStart;
			RelEnd = CustomEnd;
		}
		else
		{
			float scale = getSliderBackSize().X / (250 * 1.35f);
			RelStart = Vector2( -210, 0 ) * 1.35f * scale;
			RelEnd = Vector2( 210, 0 ) * 1.35f * scale;
		}
	}

	void MenuSlider::Draw( bool Text, const boost::shared_ptr<Camera> &cam, bool Selected )
	{
		setMyCameraZoom( cam->getZoom() );

		if ( MyMenu->CurDrawLayer != 0 || !Show )
			return;

		GrayOut();

		// If just selected perfrom the OnSelect callback
		if ( Selected != this->Selected && Selected )
		{
			OnSelect();
		}
		this->Selected = Selected;

		SetTextSelection( Selected );

		SliderBack->Base.Origin = Pos + PosOffset + SliderShift;

		CalcEndPoints();

		Slider->Base.Origin = Start + ( getMyFloat()->getVal() - getMyFloat()->MinVal ) / (getMyFloat()->MaxVal - getMyFloat()->MinVal) * (End - Start) + TabOffset;

		if ( Text )
			DrawText( cam, Selected );

		if ( !Text )
		{
			if ( FancyPos != 0 )
			{
				FancyPos->RelVal = Pos + PosOffset;
				FancyPos->Update();
			}

			if ( Icon != 0 )
				Icon->Draw( Selected );

			SliderBack->Draw();
			Slider->Draw();
			Tools::QDrawer->Flush();

			if ( Tools::DrawBoxes )
			{
				Tools::QDrawer->DrawCircle( End, 5, Color::Red );
				Tools::QDrawer->DrawCircle( Start, 5, Color::Red );
			}
		}

		DeGrayOut();
	}

	void MenuSlider::InitializeInstanceFields()
	{
		SliderShift = Vector2( 716.666f, -172.2223f );
		TabOffset = Vector2( 0, 0 );
		CustomEndPoints = false;
	}
}
