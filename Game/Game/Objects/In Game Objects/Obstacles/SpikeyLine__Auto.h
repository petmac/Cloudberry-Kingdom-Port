﻿#ifndef SPIKEYLINE__AUTO
#define SPIKEYLINE__AUTO

#include <global_header.h>

namespace CloudberryKingdom
{
	class SpikeyLine_Parameters : public AutoGen_Parameters
	{
	public:
		class _Special
		{
		};
	public:
		Param LineStep, LinePeriod;
		bool Make;

		_Special Special;

		//public List<List<SpikeyLine>> Lines = new List<List<SpikeyLine>>();

		virtual void SetParameters( const std::shared_ptr<PieceSeedData> &PieceSeed, const std::shared_ptr<Level> &level );
	};

	class SpikeyLine_AutoGen : public AutoGen
	{
	private:
		static const std::shared_ptr<SpikeyLine_AutoGen> instance;
	public:
		const static std::shared_ptr<SpikeyLine_AutoGen> &getInstance();

	private:
		SpikeyLine_AutoGen();

	public:
		std::shared_ptr<AutoGen_Parameters> SetParameters( const std::shared_ptr<PieceSeedData> &data, const std::shared_ptr<Level> &level );

		void Cleanup_2( const std::shared_ptr<Level> &level, Vector2 BL, Vector2 TR );

		void CreateLine( const std::shared_ptr<Level> &level, Vector2 pos );

		std::shared_ptr<ObjectBase> CreateAt( const std::shared_ptr<Level> &level, Vector2 pos );

		void PreFill_2( const std::shared_ptr<Level> &level, Vector2 BL, Vector2 TR );
	};
}


#endif	//#ifndef SPIKEYLINE__AUTO