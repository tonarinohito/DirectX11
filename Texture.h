#pragma once
#include <d3d11.h>
#include <DirectXMath.h>
#include <atlbase.h>

/*! @class Texture
*   @brief  画像を使用するためのクラスです
*   @detail このクラスは単体では使用しません。MeshやSpriteで使用します
*/
class Texture
{
private:
	DirectX::XMINT2 size;
	ATL::CComPtr<ID3D11Texture2D> texture;
	ATL::CComPtr<ID3D11ShaderResourceView> shaderResourceView;
	ATL::CComPtr<ID3D11SamplerState> samplerState;
public:
	Texture();
	~Texture();
	Texture(const char* const filePath);
	Texture(const BYTE* const buffer, int width, int height);

	/*!
	* @brief 画像を読み込みます。
	* @param (filepath) ファイルパス
	*/
	void Load(const char* const filePath);
	/*!
	* @brief テクスチャを作成します
	* @param (buffer)　バッファ
	* @param (width)    幅
	* @param (height)   高さ
	*/
	void Create(const BYTE* const buffer, int width, int height);
	/*!
	* @brief  テクスチャのサイズを取得します。
	* @return XMINT2
	*/
	DirectX::XMINT2 GetSize() const;
	/*!
	* @brief テクスチャをグラフィックスAPIに設定します
	* @param (sloat) 
	*/
	void Attach(int slot);
	ID3D11Texture2D& GetInterface();
};