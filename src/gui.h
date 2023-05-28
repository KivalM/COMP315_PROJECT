#ifndef GUI_H
#define GUI_H

#include "webview.h"
#include "game.h"
#include "utils.h"
using namespace std;

// forward declaration of the MemoryGame class
class MemoryGame;

class GUI
{
public:
    // constructor
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

    // a simple handler to handle the click events on the memory stage
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
    Game *game = nullptr;

    // pointer to matching game
    MemoryGame *mg = nullptr;
};

/*
    The following classes are used to implement the matching game.
    It consists of two classes, Cell and MemoryGame.
    Cell is a template class that holds the value of the cell and its position on the board.
    MemoryGame is the main class that holds the board and the logic of the game.

    The reason they are in the gui.h file is because they are tightly coupled with the gui, and will not really be used anywhere else.
    The other reason is that creating its own header file for them leads to a circular dependency between gui.h and utils.h


*/

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

    // 4x4 grid of cells
    Cell<int> cells[4][4];

    // pointers to the two flipped cells
    Cell<int> *first_cell = nullptr;
    Cell<int> *second_cell = nullptr;

    // first element is background, the following are the images of the cell
    std::string images[9];

    webview::webview *ui_context = nullptr;

    // this function checks if the two flipped cells match
    bool checkForMatch();

    // this function draws the initial state of the game
    void draw();

    // this function flips and redraws the cell
    void flip_cell(int x, int y, bool isFlipped);

public:
    MemoryGame(webview::webview *w, std::vector<std::string> images);
    ~MemoryGame();

    // this handles a click on cell (x, y), (-1, -1) means no cell was clicked
    void click(int x, int y);

    // this function checks if the game is finished
    // so the gui can move on to the next stage
    bool is_finished();
};

#endif
