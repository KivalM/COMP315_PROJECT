#include "gui.h"
#include "character.h"
#include "dialog.h"

#ifdef _WIN32
#include <Windows.h>
#endif

#ifdef _WIN32
int WINAPI WinMain(HINSTANCE hInt, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow)
#else
int main()
#endif

{
  Dialog *root = new Dialog;

  GUI gui;
  gui.show();
  return 0;
}
