#include "Engine.h"
#include <memory>

std::string Engine::title = "";
int Engine::width = 0;
int Engine::height = 0;
bool Engine::isFullScreen = false;
Engine::Engine(std::string WindowTitle, int width, int height,bool isFullScreen)
{
	title = WindowTitle;
	this->width = width;
	this->height = height;
	this->isFullScreen = isFullScreen;
	COMInitialize();
}

Engine::~Engine()
{

}

void Engine::COMInitialize()
{
	static bool isInitialized = false;

	if (!isInitialized)
	{
		//COMの初期化
		CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);
		// メモリリーク検出
		_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
		isInitialized = true;
	}
}

bool Engine::Run()
{
	GetDirect3D().Run();
	GetWindow().Run();
	return true;
}

HWND Engine::GetWindowHandle()
{
	return GetWindow().GetHwnd();
}

int Engine::GetWindowWidth()
{
	return width;
}

int Engine::GetWindowHeight()
{
	return height;
}

DirectX::XMINT2 Engine::GetWindowSize()
{
	return GetWindow().GetSize();
}

ID3D11Device& Engine::GetDXDevice3D()
{
	return GetDirect3D().GetDevice3D();
}

ID3D11DeviceContext& Engine::GetDXContext3D()
{
	return GetDirect3D().GetContext3D();
}

ID2D1Device& Engine::GetDXDevice2D()
{
	return GetDirect3D().GetDevice2D();
}

ID2D1DeviceContext& Engine::GetDXContext2D()
{
	return GetDirect3D().GetContext2D();
}

IDXGISwapChain& Engine::GetDXSwapChain()
{
	return GetDirect3D().GetSwapChain();
}

IWICImagingFactory& Engine::GetTextureFactory()
{
	return GetDirect3D().GetTextureFactory();
}

IDWriteFactory& Engine::GetTextFactory()
{
	return  GetDirect3D().GetTextFactory();
}

System& Engine::GetWindow()
{
	static std::unique_ptr<System>window(new System(title,width,height));
	return *window.get();	
}

Direct3D & Engine::GetDirect3D()
{
	static std::unique_ptr<Direct3D> direct3D(new Direct3D(isFullScreen));
	return *direct3D.get();
}
