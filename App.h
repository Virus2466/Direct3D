#pragma once
#include "Window.h"
#include "FrostTimer.h"

class App
{
public:
	App();
	// master frame / message loop
	int Go();
private:
	void DoFrame();
private:
	Window wnd;
	FrostTimer timer;
};

