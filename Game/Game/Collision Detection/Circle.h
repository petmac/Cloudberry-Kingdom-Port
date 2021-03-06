#ifndef CIRCLE
#define CIRCLE

#include <small_header.h>

//#include "Core/WriteReadTools.h"
//#include "Game/Collision Detection/AABox.h"
//#include "Game/Collision Detection/FloatRectangle.h"
//#include "Game/Objects/ObjectBase.h"
//#include "Game/Objects/AutoGen.h"
//#include "Game/Objects/Bob/Bob.h"
//#include "Game/Tools/Tools.h"


namespace CloudberryKingdom
{
	struct CircleBox
	{
	
		bool Invalidated;

		Vector2 BL, TR;
	
		Vector2 _Center;
	
		const Vector2 &getCenter() const;
		void setCenter( const Vector2 &value );
	
		float _Radius;
	
		const float &getRadius() const;
		void setRadius( const float &value );

		void Invalidate();

		void MakeNew();

		CircleBox();

		CircleBox( Vector2 center, float radius );

		void Move( Vector2 shift );

		void Clone( const boost::shared_ptr<CircleBox> &A );

		void Write( const boost::shared_ptr<BinaryWriter> &writer );

		void Read( const boost::shared_ptr<BinaryReader> &reader );

		void Draw( Color color );

		void Initialize( Vector2 center, float radius );

		Vector2 GetTR();

		Vector2 GetBL();

		void CalcBounds();

		void Validate();

		void Scale( float scale );

		/// <summary>
		/// Performs a collision detection between the circle and a list of tiered boxes associated with the Bob.
		/// </summary>
		bool BoxOverlap_Tiered( const boost::shared_ptr<ObjectData> &Core, const boost::shared_ptr<Bob> &bob, const boost::shared_ptr<AutoGen> &singleton );

		/// <summary>
		/// Returns true if the box overlaps the circle
		/// </summary>
		bool BoxOverlap( const boost::shared_ptr<AABox> &box );

		/// <summary>
		/// Whether the circle is contained in the FloatRectangle
		/// </summary>
		bool ContainedIn( const boost::shared_ptr<FloatRectangle> &rect );

		/// <summary>
		/// Whether the circle is contained in the AABox
		/// </summary>
		bool ContainedIn( const boost::shared_ptr<AABox> &box );

		/// <summary>
		/// Checks if a vertical line segment from (x,y1) to (x,y2) intersects the circle.
		/// Requires that y1 is less than y2
		/// </summary>
		bool VerticalSegmentOverlap( float x, float y1, float y2 );

		/// <summary>
		/// Checks if a horizontal line segment from (x1,y) to (x2,y) intersects the circle.
		/// Requires that x1 is less than x2
		/// </summary>
		bool HorizontalSegmentOverlap( float y, float x1, float x2 );

		/// <summary>
		/// Returns the height of the circle at a distance x from the center.
		/// </summary>
		float Height( float x );
	};
}


#endif	//#ifndef CIRCLE
