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

#include "game.h"

class GUI
{
public:
    GUI();
    // function to start the GUI
    void start();

    // function to draw the main menu
    void main_menu();

    // function to draw the how to play screen
    void how_to_play();

    // function to draw the game settings screen
    void game_settings();

    // function to initialize game play systems and start the game
    void start_game();

    // function to draw the current stage
    void stage_handler();

    // functions to draw the different stages
    void draw_question_stage();
    void draw_answer_stage(int answer);
    void draw_dialogue_stage();

private:
    std::unique_ptr<webview::webview> w;
    vector<string> backgrounds;
    vector<string> character_sprites;
    vector<string> html_templates;
    Game *game = new Game();
};

namespace utils
{
    std::string load_img_to_base64(const std::string &path);
    std::string base64_encode(const std::string &input);

    vector<string> load_backgrounds();
    vector<string> load_character_sprites();
    vector<string> load_html_templates();

    std::string construct_img_url(const std::string &base64Data);
    std::string replace_placeholder(std::string text, const std::string &placeholder, const std::string &value);

    // function for manipulating the webview background and character sprites
    void set_image(webview::webview *w,
                   const std::string &id, const std::string &base64Data);

    void set_text(webview::webview *w,
                  const std::string &id, const std::string &text);
    void set_hidden(webview::webview *w,
                    const std::string &id, bool hidden);
}

#endif
