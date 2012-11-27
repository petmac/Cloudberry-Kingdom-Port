﻿#include <global_header.h>



namespace CloudberryKingdom
{

	void BobPhsxBig::Set( const std::shared_ptr<BobPhsx> &phsx )
	{
		if ( dynamic_cast<BobPhsxWheel*>( phsx ) != 0 )
			phsx->ModInitSize = Vector2( 1.45f );
		else
			phsx->ModInitSize = Vector2( 1.7f, 1.4f );

		phsx->CapePrototype = Cape::CapeType_NORMAL;
		phsx->CapeOffset += Vector2( 0, -20 );

		std::shared_ptr<BobPhsxNormal> normal = dynamic_cast<BobPhsxNormal*>( phsx );
		if ( 0 != normal )
		{
			normal->Gravity *= 1.55f;
			normal->SetAccels();

			normal->Gravity *= .935f;
			normal->MaxSpeed *= 1.5f;
			normal->XAccel *= 1.5f;
		}
	}

	void BobPhsxBig::InitSingleton()
	{
		BobPhsxNormal::InitSingleton();

		Specification = HeroSpec( 0, 3, 0, 0 );
		Name = Localization::Words_FAT_BOB;
		Adjective = _T( "Fatty" );

		Icon = std::make_shared<PictureIcon>( Tools::TextureWad->FindByName( _T( "Bob_Run_0024" ) ), Color::White, DefaultIconWidth * 1.55f );
	}

const std::shared_ptr<BobPhsxBig> BobPhsxBig::instance = std::make_shared<BobPhsxBig>();

	const std::shared_ptr<BobPhsxBig> &BobPhsxBig::getInstance()
	{
		return instance;
	}

	BobPhsxBig::BobPhsxBig()
	{
		Set( this );
	}
}