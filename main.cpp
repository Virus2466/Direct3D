#include <string>
#include <codecvt>
#include <locale>
#include "Window.h"

// Function to convert std::string to std::wstring
std::wstring ConvertToWideString(const std::string& str) {
    return std::wstring(str.begin(), str.end());
}

int CALLBACK WinMain(
    HINSTANCE hInstace,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nCmdShow
)  
{
    try {
        Window wnd(800, 300, L"The hell returns");

        MSG msg;
        BOOL gResult;
        while (gResult = GetMessage(&msg, nullptr, 0, 0) > 0)
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
            if (wnd.kbd.KeyIsPressed(VK_MENU)) {
                MessageBox(nullptr, L"Something Happendddd!", L"Space Key was pressed", MB_OK | MB_ICONEXCLAMATION | MB_HELP);
            }
        }

        if (gResult == -1) {
            return -1;
        }

        return msg.wParam;
    }
    catch (const ExpectionClass& e)
    {
        std::wstring errorMessage = ConvertToWideString(e.what());
        std::wstring errorType = ConvertToWideString(e.GetType());
        MessageBox(nullptr, errorMessage.c_str(), errorType.c_str(), MB_OK | MB_ICONEXCLAMATION);
    }
    catch (const std::exception& e)
    {
        std::wstring errorMessage = ConvertToWideString(e.what());
        MessageBox(nullptr, errorMessage.c_str(), L"Standard Exception", MB_OK | MB_ICONEXCLAMATION);

    }
    catch (...)
    {
        MessageBox(nullptr, L"No Details Available", L"Unknown Exception ", MB_OK | MB_ICONEXCLAMATION);
    }
}