#include "gui.h"
#include "character.h"
#include "dialog.h"
#include <iostream>
#include <Windows.h>

/*
 * Redirects the standard input/output streams to the console window.
 * This is useful for debugging purposes.
 */

void RedirectIOToConsole()
{
  // Allocate a console for the process
  AllocConsole();

  // Redirect stdout to the console
  FILE *pConsoleStream;
  freopen_s(&pConsoleStream, "CONOUT$", "w", stdout);
  *stdout = *pConsoleStream;

  // Redirect stderr to the console
  FILE *pConsoleErrorStream;
  freopen_s(&pConsoleErrorStream, "CONOUT$", "w", stderr);
  *stderr = *pConsoleErrorStream;

  // Redirect stdin to the console (optional)
  FILE *pConsoleInputStream;
  freopen_s(&pConsoleInputStream, "CONIN$", "r", stdin);
  *stdin = *pConsoleInputStream;

  // Clear the error state for cin and tie it to the console (optional)
  std::cin.clear();
  std::cin.tie(&std::cout);
}

int WINAPI WinMain(HINSTANCE hInt, HINSTANCE hPrevInst, LPSTR lpCmdLine,
                   int nCmdShow)
{
  RedirectIOToConsole();

  std::cout << "Starting Silent Shadows..." << std::endl;

  // initialize the GUI
  GUI gui;

  // start the GUI
  gui.start();
  return 0;
}
