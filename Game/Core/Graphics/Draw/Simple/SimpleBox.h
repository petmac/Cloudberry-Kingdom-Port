#ifndef SIMPLEBOX
#define SIMPLEBOX

#include <small_header.h>

//#include "Core/Graphics/Draw/Object/ObjectBox.h"
//#include "Core/Graphics/Draw/Simple/BasePoint.h"
#include "Core/Graphics/Draw/Simple/SimpleVector.h"


namespace CloudberryKingdom
{
	struct SimpleBox
	{
	
		bool Animated;
		SimpleVector BL, TR;

		void Release();

		void SetHold();

		void ReadAnim( int anim, int frame );

		void Record( int anim, int frame );

		void Transfer( int anim, float DestT, int AnimLength, bool Loop, bool Linear, float t );

		void Calc( int anim, float t, int AnimLength, bool Loop, bool Linear );

		SimpleBox( const boost::shared_ptr<SimpleBox> &box );

		SimpleBox( const boost::shared_ptr<ObjectBox> &box );

		/// <summary>
		/// Copy and shift the source boxes's vertex locations.
		/// </summary>
		/// <param name="SourceBox">The source box</param>
		/// <param name="shift">The amount to shift</param>
		void CopyUpdate( boost::shared_ptr<SimpleBox> &SourceBox, Vector2 &shift );

		void Update( BasePoint &Base );

		Vector2 Center();

		float Width( BasePoint &Base );

		Vector2 Size();

		/*        public void DrawExtra(QuadDrawer Drawer, Color clr)
		        {
		            Drawer.DrawLine(BL.Pos, new Vector2(TR.Pos.X, BL.Pos.Y), clr, .02f);
		            Drawer.DrawLine(BL.Pos, new Vector2(BL.Pos.X, TR.Pos.Y), clr, .02f);
		            Drawer.DrawLine(TR.Pos, new Vector2(TR.Pos.X, BL.Pos.Y), clr, .02f);
		            Drawer.DrawLine(TR.Pos, new Vector2(BL.Pos.X, TR.Pos.Y), clr, .02f);
		        }
		  */
	};
}


#endif	//#ifndef SIMPLEBOX
