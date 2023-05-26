#ifndef MATCHING_H
#define MATCHING_H

#include <webview.h>
#include <string>
#include "utils.h"
using namespace std;

enum State
{
    START,
    PLAYING,
    END
};

template <typename T>
class Cell
{
private:
    T value;
    bool isFlipped; // whether to display it as flipped or not
    bool isMatched; // whether it has been matched or not
    bool isVisible; // is it visible in the frontend
public:
    friend class MemoryGame;
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
    string images[9];

    webview::webview *ui_context = nullptr;

    void draw()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; i < 4; i++)
            {
                if (cells[i][j].isVisible)
                {
                    string id = to_string(i) + to_string(j);
                    utils::set_image(ui_context, id, images[cells[i][j].value]);
                }
            }
        }
    }

public:
    MemoryGame(webview::webview *w, string images[]);
    ~MemoryGame();

    void click(webview::webview *w, int x, int y)
    {

        // handle click logic

        // draw all cells
        draw();
    }

    bool is_finished()
    {
        // check if all cells are matched
        return false;
    }
};

MemoryGame::MemoryGame(
    webview::webview *w,
    string images[])
{

    // initialize the cells

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; i < 4; i++)
        {
            // cells[i][j] = nullptr;
            utils::set_image(ui_context, "00", images[5]);
        }
    }
}

MemoryGame::~MemoryGame()
{
}

#endif // MATCHING_H