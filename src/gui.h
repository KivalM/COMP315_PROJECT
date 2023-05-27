#ifndef GUI_H
#define GUI_H

#include "webview.h"
#include "game.h"
#include "utils.h"
using namespace std;

class MemoryGame;

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
    void draw_memory_stage();
    void memory_stage_event_handler(int x, int y);

    // update the meter on the screen
    void update_meter();

private:
    // smart pointer to the webview object
    std::unique_ptr<webview::webview> w;

    // vector of strings to hold the base64 encoded images
    vector<string> backgrounds;
    vector<string> character_sprites;
    vector<string> matching_images;

    // vector of strings to hold the html templates
    vector<string> html_templates;

    // pointer to the game object
    Game *game = new Game();

    // pointer to matching game
    MemoryGame *mg = nullptr;
};

template <typename T>
class Cell
{
private:
    T value;
    bool isFlipped; // whether to display it as flipped or not
    bool isMatched; // whether it has been matched or not
    int x, y;       // position on the board

public:
    friend class MemoryGame;
    Cell(){}; // default constructor
    Cell(int x, int y, T value);
    ~Cell(){};
};

class MemoryGame
{
private:
    // Cell<int> will hold the index of the image in the images array,
    // which will double as a unique id
    // ranges from 1 to 8 eg. 2 of each value

    Cell<int> cells[4][4];
    Cell<int> *first_cell = nullptr;
    Cell<int> *second_cell = nullptr;

    // first element is background, the following are the images of the cell
    std::string images[9];

    webview::webview *ui_context = nullptr;

    void draw();
    void flip_cell(int x, int y, bool isFlipped);

public:
    MemoryGame(webview::webview *w, std::vector<std::string> images);
    ~MemoryGame();

    void click(int x, int y);

    bool checkForMatch();
    bool is_finished();
};

#endif
