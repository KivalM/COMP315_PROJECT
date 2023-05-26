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
        if(cells[x][y].isFlipped || cells[x][y].isMatched)
        {
            return; 
        }
        if(first_cell == nullptr)
        {
            first_cell = &cells[x][y];
            first_cell->isFlipped = true;
            first_cell->isVisible = true;
        }else if(second_cell == nullptr)
        {
            second_cell = &cells[x][y];
            second_cell->isFlipped = true;
            second_cell->isVisible = true;
            //check for match
            if(chechForMatch())
            {
                // if matched, reset the cells
                first_cell = nullptr;
                second_cell = nullptr;
            }
        }
        // draw all cells
        draw();
        if(is_finished())
        {
            // end the game
        }
    }

    bool chechForMatch()
    {
        if(first_cell->value == second_cell->value)
        {
            first_cell->isMatched = true;
            second_cell->isMatched = true;
            return true;
        }else
        {
            first_cell->isFlipped = false;
            second_cell->isFlipped = false;
            return false;
        }
    }
    bool is_finished()
    {
        for (int i = 0; i < 4; i++)
        {
            for (int j = 0; i < 4; i++)
            {
                if (!cells[i][j].isMatched)
                {
                    return false;
                }
            }
        }
        return true;
    }
};
template <typename T>
Cell<T>::Cell(int x, int y, T value)
{
    this->value = value;
    this->isFlipped = false;
    this->isMatched = false;
    this->isVisible = false;
}
MemoryGame::MemoryGame(webview::webview *w,string images[])
{
    
    this->ui_context = w;
    // initialize the cells
    for(int i = 0;i < 9; i++)
    {
        this->images[i] = images[i];
    }
    int value = 1;
    for(int i = 0;i < 4; i++)
    {
        for(int j = 0;j < 4; j++)
        {
            cells[i][j] = Cell<int>(i, j, value);
            value = (value % 8) + 1;
            utils::set_image(ui_context, to_string(i) + to_string(j), images[0]);
        }
    }
}

MemoryGame::~MemoryGame()
{
}

#endif // MATCHING_H