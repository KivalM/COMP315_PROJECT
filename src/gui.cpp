#include "gui.h"

GUI::GUI() : w(std::make_unique<webview::webview>(false, nullptr))
{
    w->set_title("Basic Example");
    w->set_size(480, 320, WEBVIEW_HINT_NONE);
    w->set_html("Thanks for using webview!");
}

void GUI::show()
{
    w->run();
}

void GUI::hide()
{
    // You can perform any necessary cleanup or additional actions
    // when hiding the GUI here.
}
