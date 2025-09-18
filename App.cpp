#include "App.h"

App::App()
	:
	wnd(800, 600, L"The Froster")
{}

int App::Go()
{
	while (true)
	{
		// process all pending messages
		if (const auto ecode = Window::ProcessMessages())
		{
			// if return option has a value , means we're quitting so return exit code
			return *ecode;
		}

		DoFrame();
	}
}

void App::DoFrame() 
{
	const float t = timer.Peek();
	std::wostringstream oss;
	oss << "Time Elapsed : " << std::setprecision(1) << std::fixed << t << "s";
	std::wstring title = oss.str();
	wnd.SetTitle(title);

}