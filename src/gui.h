#ifndef GUI_H
#define GUI_H

#include "webview.h"
#include "game.h"
#include "utils.h"
using namespace std;

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

    // update the meter on the screen
    void update_meter();

private:
    // smart pointer to the webview object
    std::unique_ptr<webview::webview> w;

    // vector of strings to hold the base64 encoded images
    vector<string> backgrounds;
    vector<string> character_sprites;

    // vector of strings to hold the html templates
    vector<string> html_templates;

    // pointer to the game object
    Game *game = new Game();
};

#endif
