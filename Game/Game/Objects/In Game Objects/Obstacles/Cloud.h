#ifndef CLOUD
#define CLOUD

#define _USE_MATH_DEFINES
#include <small_header.h>

//#include "Core/Graphics/Draw/Quads/QuadClass.h"
//#include "Game/Collision Detection/AABox.h"
//#include "Game/Collision Detection/Phsx.h"
//#include "Game/Objects/ObjectBase.h"
#include "Game/Tilesets/TileSet.h"
//#include "Game/Objects/Bob/Bob.h"
#include "Game/Objects/In Game Objects/BaseClasses/_Obstacle.h"
//#include "Game/Objects/In Game Objects/Grab/MakeData.h"
//#include "Game/Level/Level.h"
//#include "Game/Tilesets/SpriteInfo.h"
//#include "Game/Tools/Recycler.h"
//#include "Game/Tools/Tools.h"
//#include "Game/Tilesets/TileSetInfo.h"


namespace CloudberryKingdom
{

	struct Cloud : public _Obstacle
	{

		virtual ~Cloud()
		{
#ifdef BOOST_BIN
			OnDestructor( "Cloud" );
#endif
		}

	
		struct CloudTileInfo : public TileInfoBase
		{
		
			boost::shared_ptr<SpriteInfo> Sprite;
			Vector2 BoxSize;

		
			void InitializeInstanceFields();


			CloudTileInfo()
			{
				InitializeInstanceFields();
			}
		};

	
		Vector2 Displacement;
		float Shiftiness;
		Vector2 Size;

		boost::shared_ptr<QuadClass> MyQuad;

		boost::shared_ptr<AABox> Box;

		Cloud();
		Cloud( bool BoxesOnly );

	
		int PeriodOffset;

	
		virtual void MakeNew();

		virtual void Init( Vector2 pos, const boost::shared_ptr<Level> &level );

		virtual void Construct( bool BoxesOnly );

	
		virtual void ActivePhsxStep();

	
		virtual void PhsxStep2();

	
		virtual void DrawGraphics();

		virtual void DrawBoxes();

	
		virtual void Move( Vector2 shift );

		virtual void Interact( const boost::shared_ptr<Bob> &bob );

		virtual void Reset( bool BoxesOnly );

		virtual void Clone( const boost::shared_ptr<ObjectBase> &A );

		virtual void Write( const boost::shared_ptr<BinaryWriter> &writer );
		virtual void Read( const boost::shared_ptr<BinaryReader> &reader );

	
		void InitializeInstanceFields();
	};

}


#endif	//#ifndef CLOUD
