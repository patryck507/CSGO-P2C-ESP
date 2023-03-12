#include <iostream>
#include <windows.h>
#include <dwmapi.h>
#include <d3d9.h>

#include "../dep/imgui/imgui.h"
#include "../dep/imgui/imgui_impl_dx9.h"
#include "../dep/imgui/imgui_impl_win32.h"

#pragma comment(lib,"d3d9.lib")

namespace overlay
{
	inline bool menuShow = true;
	inline HWND _HWND = NULL;
	inline int ScreenHeight = NULL;
	inline int ScreenWidth = NULL;
	inline int ScreenLeft = NULL;
	inline int ScreenRight = NULL;
	inline int ScreenTop = NULL;
	inline int ScreenBottom = NULL;


	namespace OverlayWindow
	{
		inline WNDCLASSEX WindowClass;
		inline HWND Hwnd;
		inline LPCSTR Name;
	}

	namespace DirectX9Interface
	{
		inline IDirect3D9Ex* Direct3D9 = NULL;
		inline IDirect3DDevice9Ex* pDevice = NULL;
		inline D3DPRESENT_PARAMETERS pParams = { NULL };
		inline MARGINS Margin = { -1 };
		inline MSG Message = { NULL };
	}

	void InputHandler();

	void Render();


	void MainLoop();

	bool DirectXInit();

	//extern IMGUI_IMPL_API LRESULT ImGui_ImplWin32_WndProcHandler(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK WinProc(HWND hWnd, UINT Message, WPARAM wParam, LPARAM lParam);

	void SetupWindow();

}