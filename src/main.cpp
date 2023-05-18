#include "gui.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInt, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow) {
#else
int main()
#endif

  {
    GUI gui;
    gui.show();
    return 0;
  }
