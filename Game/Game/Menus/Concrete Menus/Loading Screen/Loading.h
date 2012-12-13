﻿#ifndef LOADING
#define LOADING

#include <global_header.h>

namespace CloudberryKingdom
{

	struct ProgressBar
	{
	
		enum BarType
		{
			BarType_SCALE,
			BarType_REVEAL
		};
	
		BarType MyType;

		const Vector2 &getFull_BL() const;
		const Vector2 &getFull_TR() const;
		const Vector2 getCurrent_TR() const;

		std::shared_ptr<DrawPile> MyPile;

		std::shared_ptr<QuadClass> Outline, Fill;

		float PercentDone;
		float Width;

		const Vector2 &getPos() const;
		void setPos( const Vector2 &value );

		ProgressBar();

	
		void Initialize();

	
		void InitStandardBar();

		ProgressBar( const std::wstring &FillName, const std::wstring &OutlineName, float Width );

		void InitCustomBar( const std::wstring &FillName, const std::wstring &OutlineName, float Width );

		void SetPercent( float Percent );

		void Draw();

		void Draw( bool Selected );

	
		void InitializeInstanceFields();
	};

	struct InitialLoadingScreen
	{
	
		static void InitializeStatics();
	
		bool IsDone;
	
		std::shared_ptr<SoundEffect> Whinney;

		std::shared_ptr<DrawPile> MyPile;
		std::shared_ptr<ProgressBar> MyProgressBar;

		int LogoCount;
		std::shared_ptr<WrappedFloat> ResourceCount;

		std::shared_ptr<QuadClass> BlackQuad, Splash;

	
		InitialLoadingScreen( const std::shared_ptr<ContentManager> &Content, const std::shared_ptr<WrappedFloat> &ResourceCount );

		static int TotalResources;

		bool Accelerate;
	
		int DoneCount;
	
		void PhsxStep();

	
		static const bool NoShow = true;

	
		void Draw();

	
		void InitializeInstanceFields();
	};
}


#endif	//#ifndef LOADING
