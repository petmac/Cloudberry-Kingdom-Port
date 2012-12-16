﻿#include <global_header.h>

namespace CloudberryKingdom
{

	const std::shared_ptr<Texture2D> &EzTexture::getTex() const
	{
		return _Tex;
	}

	void EzTexture::setTex( const std::shared_ptr<Texture2D> &value )
	{
		_Tex = value;
	}

	float EzTexture::getAspectRatio() const
	{
		return static_cast<float>( Width ) / static_cast<float>( Height );
	}

#if ! defined(EDITOR)
	bool EzTexture::Load()
	{
		if ( _Tex == 0 && Path != _T( "" ) )
		{
			_Tex = Tools::GameClass->getContent()->Load<Texture2D>(Path);
			/*Width = _Tex->Width;
			Height = _Tex->Height;*/
		}

		return _Tex != 0;
	}
#endif

	std::wstring EzTexture::ToString()
	{
		return Name;
	}

	void EzTexture::InitializeInstanceFields()
	{
		Width = 0; Height = 0;
	
		FromPacked = false;
		Dynamic = false;
		FromCode = false;
		BL = Vector2();
		TR = Vector2(1);
	}
}
