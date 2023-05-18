#ifndef GUI_H
#define GUI_H

#include "webview.h"
#include <memory>
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iterator>
#include <algorithm>
using namespace std;

class GUI
{
public:
    GUI();
    void start();
    void hide();
    void main_menu();

private:
    std::unique_ptr<webview::webview> w;
    vector<string> backgrounds;
    vector<string> character_sprites;
    vector<string> html_templates;
};

namespace utils
{
    std::string load_img_to_base64(const std::string &path);
    std::string base64_encode(const std::string &input);

    vector<string> load_backgrounds();
    vector<string> load_character_sprites();
    vector<string> load_html_templates();
}

#endif
