#include <small_header.h>
#include "Core/Graphics/VertexFormat.h"



namespace CloudberryKingdom
{

	MyOwnVertexFormat::MyOwnVertexFormat()
	{
	}

	MyOwnVertexFormat::MyOwnVertexFormat( Vector2 XY, Vector2 UV, Color color )
	{
		this->xy = XY;
		this->uv = UV;
		this->TheColor = color;
	}

	MyOwnVertexFormat::MyOwnVertexFormat( Vector2 XY, Vector2 UV, Color color, Vector3 depth )
	{
		this->xy = XY;
		this->uv = UV;
		this->TheColor = color;
	}

	/*
const boost::shared_ptr<Microsoft::Xna::Framework::Graphics::VertexDeclaration> MyOwnVertexFormat::VertexDeclaration = boost::make_shared<VertexDeclaration>( VertexElement( 0, VertexElementFormat::Vector2, VertexElementUsage::Position, 0 ), VertexElement( sizeof( float ) * 2, VertexElementFormat::Vector2, VertexElementUsage::TextureCoordinate, 0 ), VertexElement( sizeof( float ) * 4, VertexElementFormat::Color, VertexElementUsage::Color, 0 ) );

	const boost::shared_ptr<Microsoft::Xna::Framework::Graphics::VertexDeclaration> &MyOwnVertexFormat::getVertexDeclaration() const
	{
		return VertexDeclaration;
	}*/
}
