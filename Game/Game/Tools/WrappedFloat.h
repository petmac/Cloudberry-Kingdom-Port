﻿#ifndef WRAPPEDFLOAT
#define WRAPPEDFLOAT

#include <global_header.h>

namespace CloudberryKingdom
{
	class WrappedBool
	{
	public:
		bool MyBool;

		WrappedBool( bool val );
	};

	class WrappedInt
	{
	public:
		int MyInt;

		WrappedInt( int val );
	};

	class WrappedFloat
	{
	public:
		float MyFloat;
		float MinVal, MaxVal;

		const float &getVal();
		void setVal( const float &value );

		std::shared_ptr<Lambda> SetCallback;
		std::shared_ptr<LambdaFunc<float> > GetCallback;

		WrappedFloat();

		float DefaultValue;
		WrappedFloat( float Val, float MinVal, float MaxVal );

		void Set( float val );

		float getSpread() const;
		float getRatio();
		float getPercent();

		void Release();

	private:
		void InitializeInstanceFields();
	};
}


#endif	//#ifndef WRAPPEDFLOAT
