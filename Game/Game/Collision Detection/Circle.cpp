#include <small_header.h>
#include "Game/Collision Detection/Circle.h"

#include "Core/WriteReadTools.h"
#include "Game/Collision Detection/AABox.h"
#include "Game/Collision Detection/FloatRectangle.h"
#include "Game/Objects/ObjectBase.h"
#include "Game/Objects/AutoGen.h"
#include "Game/Objects/Bob/Bob.h"
#include "Game/Tools/Tools.h"


namespace CloudberryKingdom
{

	const Vector2 &CircleBox::getCenter() const
	{
		return _Center;
	}

	void CircleBox::setCenter( const Vector2 &value )
	{
		_Center = value;
		Invalidate();
	}

	const float &CircleBox::getRadius() const
	{
		return _Radius;
	}

	void CircleBox::setRadius( const float &value )
	{
		_Radius = value;
		Invalidate();
	}

	void CircleBox::Invalidate()
	{
		Invalidated = true;
	}

	void CircleBox::MakeNew()
	{
		Invalidated = true;
	}

	CircleBox::CircleBox()
	{
		Invalidated = false;
		_Radius = 0;

		MakeNew();
	}

	CircleBox::CircleBox( Vector2 center, float radius )
	{
		Invalidated = false;
		_Radius = 0;

		Initialize( center, radius );
	}

	void CircleBox::Move( Vector2 shift )
	{
		setCenter( getCenter() + shift );

		CalcBounds();
	}

	void CircleBox::Clone( const boost::shared_ptr<CircleBox> &A )
	{
		setCenter( A->getCenter() );
		setRadius( A->getRadius() );

		TR = A->TR;
		BL = A->BL;
	}

	void CircleBox::Write( const boost::shared_ptr<BinaryWriter> &writer )
	{
		writer->Write( getCenter() );
		writer->Write( getRadius() );
	}

	void CircleBox::Read( const boost::shared_ptr<BinaryReader> &reader )
	{
		setCenter( reader->ReadVector2() );
		setRadius( reader->ReadSingle() );
	}

	void CircleBox::Draw( Color color )
	{
		Tools::QDrawer->DrawCircle( getCenter(), getRadius(), color );
		Tools::QDrawer->Flush();
	}

	void CircleBox::Initialize( Vector2 center, float radius )
	{
		setCenter( center );
		setRadius( radius );

		Invalidated = true;
	}

	Vector2 CircleBox::GetTR()
	{
		Validate();
		return TR;
	}

	Vector2 CircleBox::GetBL()
	{
		Validate();
		return BL;
	}

	void CircleBox::CalcBounds()
	{
		TR = getCenter() + Vector2(getRadius(), getRadius());
		BL = getCenter() - Vector2(getRadius(), getRadius());
	}

	void CircleBox::Validate()
	{
		if ( Invalidated )
		{
			CalcBounds();

			Invalidated = false;
		}
	}

	void CircleBox::Scale( float scale )
	{
		setRadius( getRadius() * scale );
	}

	bool CircleBox::BoxOverlap_Tiered( const boost::shared_ptr<ObjectData> &Core, const boost::shared_ptr<Bob> &bob, const boost::shared_ptr<AutoGen> &singleton )
	{
		boost::shared_ptr<AutoGen_Parameters> Params = Core->GetParams( singleton );
		int WidthLevel = static_cast<int>( Params->BobWidthLevel.GetVal( Core->Data.Position ) );

		bool col = BoxOverlap( bob->GetBox( WidthLevel ) );

		return col;
	}

	bool CircleBox::BoxOverlap( const boost::shared_ptr<AABox> &box )
	{
		Validate();

		if ( box->Target->BL.X >= TR.X )
			return false;
		if ( box->Target->TR.X <= BL.X )
			return false;

		if ( box->Target->BL.Y >= TR.Y )
			return false;
		if ( box->Target->TR.Y <= BL.Y )
			return false;

		boost::shared_ptr<FloatRectangle> rect = box->Target;

		return VerticalSegmentOverlap( rect->TR.X, rect->BL.Y, rect->TR.Y ) || VerticalSegmentOverlap( rect->BL.X, rect->BL.Y, rect->TR.Y ) || HorizontalSegmentOverlap( rect->TR.Y, rect->BL.X, rect->TR.X ) || HorizontalSegmentOverlap( rect->BL.Y, rect->BL.X, rect->TR.X ) || ContainedIn( box ); // Inside -  Bottom segment -  Top segment -  Left segment -  Right segment
	}

	bool CircleBox::ContainedIn( const boost::shared_ptr<FloatRectangle> &rect )
	{
		return TR.LE( rect->TR ) && BL.GE( rect->BL );
	}

	bool CircleBox::ContainedIn( const boost::shared_ptr<AABox> &box )
	{
		box->CalcBounds();
		return TR.LE( box->TR ) && BL.GE( box->BL );
	}

	bool CircleBox::VerticalSegmentOverlap( float x, float y1, float y2 )
	{
		// Get the height of the circle at x (relative to the center)
		float h = Height( x - getCenter().X );

		if ( h == 0 )
			return false;

		// Get the heights of the line segment (relative to the center)
		float h1 = y1 - getCenter().Y;
		float h2 = y2 - getCenter().Y;

		if ( h1 > h )
			return false;
		if ( h2 < -h )
			return false;

		return true;
	}

	bool CircleBox::HorizontalSegmentOverlap( float y, float x1, float x2 )
	{
		// Get the height of the circle at y (relative to the center)
		float h = Height( y - getCenter().Y );

		if ( h == 0 )
			return false;

		// Get the heights of the line segment (relative to the center)
		float h1 = x1 - getCenter().X;
		float h2 = x2 - getCenter().X;

		if ( h1 > h )
			return false;
		if ( h2 < -h )
			return false;

		return true;
	}

	float CircleBox::Height( float x )
	{
		if ( x > getRadius() || x < -getRadius() )
			return 0;
		return static_cast<float>( sqrt( getRadius() * getRadius() - x * x ) );
	}
}
