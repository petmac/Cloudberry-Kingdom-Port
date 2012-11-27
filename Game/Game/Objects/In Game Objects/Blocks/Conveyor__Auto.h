﻿#ifndef CONVEYOR__AUTO
#define CONVEYOR__AUTO

#include <global_header.h>

namespace CloudberryKingdom
{
	class PieceSeedData;
}

namespace CloudberryKingdom
{
	class Level;
}

namespace CloudberryKingdom
{
	class AutoGen_Parameters;
}

namespace CloudberryKingdom
{
	class ObjectBase;
}

namespace CloudberryKingdom
{
	class ConveyorBlock_Parameters : public AutoGen_Parameters
	{
	public:
		Param Width, KeepUnused, Speed;

		virtual void SetParameters( const std::shared_ptr<PieceSeedData> &PieceSeed, const std::shared_ptr<Level> &level );
	};

	class ConveyorBlock_AutoGen : public AutoGen
	{
	private:
		static const std::shared_ptr<ConveyorBlock_AutoGen> instance;
	public:
		const static std::shared_ptr<ConveyorBlock_AutoGen> &getInstance();

	private:
		ConveyorBlock_AutoGen();

	public:
		std::shared_ptr<AutoGen_Parameters> SetParameters( const std::shared_ptr<PieceSeedData> &data, const std::shared_ptr<Level> &level );

		void PreFill_2( const std::shared_ptr<Level> &level, Vector2 BL, Vector2 TR );

		void Cleanup_2( const std::shared_ptr<Level> &level, Vector2 BL, Vector2 TR );

		std::shared_ptr<ConveyorBlock_Parameters> GetParams( const std::shared_ptr<Level> &level );

		std::shared_ptr<ObjectBase> CreateAt( const std::shared_ptr<Level> &level, Vector2 pos, Vector2 BL, Vector2 TR );
	};
}


#endif	//#ifndef CONVEYOR__AUTO