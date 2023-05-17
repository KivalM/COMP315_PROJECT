#ifndef GUI_H
#define GUI_H

#include "webview.h"
#include <memory>

class GUI
{
public:
    GUI();
    void show();
    void hide();

private:
    std::unique_ptr<webview::webview> w;
};

#endif
