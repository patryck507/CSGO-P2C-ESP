#include "memory/memory.h"
#include "overlay/overlay.h"




int main()
{
	overlay::_HWND = FindWindow(NULL, "Counter-Strike: Global Offensive - Direct3D 9");

	bool WindowFocus = false;
	while (WindowFocus == false)
	{

		HWND hwnd_active = GetForegroundWindow();

		if (overlay::_HWND == hwnd_active) {
			overlay::_HWND = GetForegroundWindow();

			RECT TempRect;
			GetWindowRect(overlay::_HWND, &TempRect);
			overlay::ScreenWidth = TempRect.right - TempRect.left;
			overlay::ScreenHeight = TempRect.bottom - TempRect.top;
			overlay::ScreenLeft = TempRect.left;
			overlay::ScreenRight = TempRect.right;
			overlay::ScreenTop = TempRect.top;
			overlay::ScreenBottom = TempRect.bottom;

			WindowFocus = true;
		}
	}

	overlay::OverlayWindow::Name = "overlay";
	overlay::SetupWindow();
	overlay::DirectXInit();

	memory::process("csgo.exe");

	memory::client = memory::module_address("client.dll");

	memory::open_handle();


	while (TRUE)
	{
		overlay::MainLoop();
	}

	memory::close_handle();
}