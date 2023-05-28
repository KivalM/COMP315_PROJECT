#include "gui.h"

GUI::GUI()
{
    // load all the html templates, backgrounds, and character sprites
    cout << "Loading HTML templates, backgrounds, and character sprites..." << endl;

    this->html_templates = utils::load_html_templates();
    cout << "Loaded " << this->html_templates.size() << " HTML templates!" << endl;

    this->backgrounds = utils::load_backgrounds();
    cout << "Loaded " << this->backgrounds.size() << " backgrounds!" << endl;

    this->character_sprites = utils::load_character_sprites();
    cout << "Loaded " << this->character_sprites.size() << " character sprites!" << endl;

    this->matching_images = utils::load_matching_game();
    cout << "Loaded " << this->matching_images.size() << " matching game images!" << endl;

    // create the webview with the main menu
    w = std::make_unique<webview::webview>(false, nullptr);
    w->set_title("Shadows of Redemption");
    w->set_size(1280, 720, WEBVIEW_HINT_NONE);
    // resizable false

    this->main_menu();
    cout << "Setup the UI!" << endl;
}

void GUI::start()
{
    w->run();
}

void GUI::main_menu()
{
    // load the main menu
    w->set_html(this->html_templates[0]);

    // slight delay to allow the webview to load the html
    Sleep(100);

    utils::set_image(w.get(), "background", this->backgrounds[1]);

    // set bindings
    w->bind("start", {[this](const std::string &r) -> std::string
                      { this->game_settings(); return ""; }});
    w->bind("how_to_play", {[this](const std::string &r) -> std::string
                            { this->how_to_play(); return ""; }});
    w->bind("quit", [this](const std::string &r) -> std::string
            { w->terminate(); return ""; });
}

void GUI::how_to_play()
{
    // load the how to play menu

    w->set_html(this->html_templates[1]);
    utils::set_image(w.get(), "background", this->backgrounds[1]);

    // set bindings
    w->bind("back", {[this](const std::string &r) -> std::string
                     { this->main_menu(); return ""; }});
}

void GUI::game_settings()
{
    // clear any data at old game pointer
    delete this->game;
    this->game = nullptr;

    // create a new game object
    game = new Game();

    // load the game settings menu
    w->set_html(this->html_templates[2]);

    utils::set_image(w.get(), "background", this->backgrounds[1]);

    // set bindings
    w->bind("back", {[this](const std::string &r) -> std::string
                     { this->main_menu(); return ""; }});

    w->bind("easy", {[this](const std::string &r) -> std::string
                     {this->game->set_difficulty(0);
                      this->start_game(); 
                      return ""; }});

    w->bind("medium", {[this](const std::string &r) -> std::string
                       {this->game->set_difficulty(1);
                        this->start_game(); 
                        return ""; }});

    w->bind("hard", {[this](const std::string &r) -> std::string
                     {this->game->set_difficulty(2);
                        this->start_game(); 
                        return ""; }});
}

void GUI::start_game()
{
    // load the game
    w->set_html(this->html_templates[3]);
    utils::set_hidden(w.get(), "meter", true);

    // start the stage handler
    stage_handler();
}

void GUI::stage_handler()
{

    if (game->stage == Stage::END || game->stage == Stage::STAGE_FAIL_END)
    {
        main_menu();
        return;
    }

    if (game->stage == Stage::MATCHING)
    {
        draw_memory_stage();

        return;
    }

    cout << "Stage Handler" << endl;
    if (game->is_quiz())
    {
        draw_question_stage();
    }
    else
    {
        draw_dialogue_stage();
    }

    // update the stage number
    utils::set_text<int>(w.get(), "act-num", game->current_act());
}

void GUI::draw_question_stage()
{
    utils::set_hidden(w.get(), "meter", false);
    update_meter();
    Dialog *dialog = this->game->current;
    // unbind all the buttons
    w->unbind("next");
    w->unbind("option_1");
    w->unbind("option_2");
    w->unbind("option_3");
    w->unbind("option_4");

    // hide all the buttons
    utils::set_hidden(w.get(), "option_1", true);
    utils::set_hidden(w.get(), "option_2", true);
    utils::set_hidden(w.get(), "option_3", true);
    utils::set_hidden(w.get(), "option_4", true);

    // set the background
    utils::set_image(w.get(), "background", backgrounds[dialog->bg]);

    // set the character text
    cout << "Drawing Question" << endl;
    cout << "Setting text to: " << dialog->text << endl;
    utils::set_text(w.get(), "char-text", dialog->text);
    utils::set_text(w.get(), "char-name", "");

    // set callbacks
    if (dialog->type == DialogType::QUESTION)
    {
        cout << "Drawing Question" << endl;
        // onclick we will go to the next dialog
        utils::set_hidden(w.get(), "options", false);

        // set the options
        utils::set_text(w.get(), "option_1", dialog->options[0]);
        utils::set_text(w.get(), "option_2", dialog->options[1]);
        utils::set_text(w.get(), "option_3", dialog->options[2]);
        utils::set_text(w.get(), "option_4", dialog->options[3]);

        // bind the options
        utils::set_hidden(w.get(), "option_1", false);
        w->bind("option_1", {[this](const string &r) -> string
                             {draw_answer_stage(0);return ""; }});

        utils::set_hidden(w.get(), "option_2", false);
        w->bind("option_2", {[this](const string &r) -> string
                             {draw_answer_stage(1);return ""; }});

        if (dialog->options[2] != "")
        {
            utils::set_hidden(w.get(), "option_3", false);
            w->bind("option_3", {[this](const string &r) -> string
                                 {draw_answer_stage(2);return ""; }});
        }
        else
        {
            utils::set_hidden(w.get(), "option_3", true);
        }

        if (dialog->options[3] != "")
        {
            utils::set_hidden(w.get(), "option_4", false);
            w->bind("option_4", {[this](const string &r) -> string
                                 {draw_answer_stage(3);return ""; }});
        }
        else
        {
            utils::set_hidden(w.get(), "option_4", true);
        }
    }
    else
    {
        // pass the context back to the handler
        utils::set_hidden(w.get(), "options", true);

        if (game->stage != Stage::STAGE_FAIL)
        {
            game->next_stage();
        }

        w->bind("next", {[this](const string &r) -> string
                         {stage_handler();return ""; }});
    }
}

void GUI::draw_answer_stage(int answer)
{
    utils::set_hidden(w.get(), "meter", false);
    Dialog *dialog = this->game->current;
    // unbind all the buttons
    w->unbind("next");
    w->unbind("option_1");
    w->unbind("option_2");
    w->unbind("option_3");
    w->unbind("option_4");
    if (dialog->correct_option == answer)
    {
        utils::set_text(w.get(), "char-text", "Correct!");
        ++(*game);
    }
    else
    {
        utils::set_text(w.get(), "char-text", "Incorrect!");
        --(*game);
    }

    update_meter();

    // set callbacks
    if (game->stage == Stage::STAGE_FAIL)
    {
        // hide all the buttons
        utils::set_hidden(w.get(), "option_1", true);
        utils::set_hidden(w.get(), "option_2", true);
        utils::set_hidden(w.get(), "option_3", true);
        utils::set_hidden(w.get(), "option_4", true);

        w->bind("next", {[this](const string &r) -> string
                         {stage_handler();return ""; }});
    }
    else
    {
        w->bind("next", {[this](const string &r) -> string
                         {
                        game->current = game->current->next;
                        draw_question_stage();return ""; }});
    }
}

void GUI::draw_dialogue_stage()
{
    utils::set_hidden(w.get(), "meter", true);
    // unbind all the buttons
    w->unbind("next");
    w->unbind("option_1");
    w->unbind("option_2");
    w->unbind("option_3");
    w->unbind("option_4");

    // set the background
    utils::set_image(w.get(), "background", backgrounds[this->game->current->bg]);

    Dialog *dialog = this->game->current;

    if ((dialog->char_to_draw != -1))
    {
        if (this->game->characters[dialog->char_to_draw].image != -1)
        {
            // unhide the character
            utils::set_hidden(w.get(), "char-img", false);

            // set the character sprite
            Character *c = &game->characters[dialog->char_to_draw];
            utils::set_image(w.get(), "char-img", character_sprites[c->image]);
        }
    }
    else
    {
        utils::set_hidden(w.get(), "char-img", true);
    }

    if (dialog->speaking != -1)
    {
        Character *c = &game->characters[dialog->speaking];
        // set the character name
        utils::set_text(w.get(), "char-name", c->name);
    }

    // set the character text
    cout << "Setting text to: " << dialog->text << endl;
    utils::set_text(w.get(), "char-text", dialog->text);
    utils::set_hidden(w.get(), "options", true);

    // set callbacks
    if (dialog->type == DialogType::DIALOG)
    {
        cout << "Drawing Dialog" << endl;
        // onclick we will go to the next dialog
        w->bind("next", {[this](const string &r) -> string
                         {
                            cout << "Next" << endl;
                            game->current = game->current->next;
                            draw_dialogue_stage();return ""; }});
    }
    else
    {
        utils::set_hidden(w.get(), "char-img", true);
        utils::set_text(w.get(), "char-name", "");
        cout << "Stage handler binding" << endl;
        // pass the context back to the handler
        game->next_stage();
        w->bind("next", {[this](const string &r) -> string
                         {stage_handler();return ""; }});
    }
}

void GUI::draw_memory_stage()
{

    // unbind all the buttons
    w->unbind("next");
    w->unbind("option_1");
    w->unbind("option_2");
    w->unbind("option_3");
    w->unbind("option_4");

    // set the ui
    w->set_html(html_templates[4]);

    // set the background
    utils::set_image(w.get(), "grid", backgrounds[0]);

    // sets the callbacks
    w->bind("callback", {[this](const string &r) -> string
                         {memory_stage_event_handler(-1, -1);return ""; }});

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            string id = "callback_" + to_string(i) + to_string(j);
            w->bind(id, {[this, i, j](const string &r) -> string
                         {memory_stage_event_handler(i, j);return ""; }});
        }
    }

    // create the memory game
    mg = new MemoryGame(w.get(), matching_images);
}

void GUI::memory_stage_event_handler(int x, int y)
{
    mg->click(x, y);

    if (mg->is_finished())
    {
        w->set_html(html_templates[3]);
        draw_dialogue_stage();
    }
}

void GUI::update_meter()
{
    // update the meter
    utils::set_text(w.get(), "meter-percent", to_string(game->get_score()) + " %");
    utils::set_width(w.get(), "meter-fill", game->get_score());
}

template <typename T>
Cell<T>::Cell(int x, int y, T value)
{
    this->value = value;
    this->isFlipped = false;
    this->isMatched = false;
    this->x = x;
    this->y = y;
}

MemoryGame::MemoryGame(webview::webview *w, std::vector<std::string> images)
{

    this->ui_context = w;
    // initialize the cells
    for (int i = 0; i < 9; i++)
    {
        this->images[i] = images[i];
    }
    int values[16] = {1, 1, 2, 2, 3, 3, 4, 4,
                      5, 5, 6, 6, 7, 7, 8, 8};

    // shuffle the values
    random_device rd;
    mt19937 g(rd());
    shuffle(values, values + 16, g);

    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int value = values[i * 4 + j];
            cells[i][j] = Cell<int>(i, j, value);
            cout << "created cell " << i << " " << j << " with value " << value << endl;
        }
    }

    draw();
}

MemoryGame::~MemoryGame()
{
    cout << "Memory Game destructor called" << endl;

    // delete all the cells
    for (int i = 0; i < 4; i++)
    {
        delete[] cells[i];
    }
}

bool MemoryGame::is_finished()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!cells[i][j].isMatched)
            {
                return false;
            }
        }
    }
    return true;
}

bool MemoryGame::checkForMatch()
{
    if (first_cell == nullptr || second_cell == nullptr)
    {
        return false;
    }

    if (first_cell->value == second_cell->value)
    {
        first_cell->isMatched = true;
        second_cell->isMatched = true;

        return true;
    }
    else
    {
        first_cell->isFlipped = false;
        second_cell->isFlipped = false;
        return false;
    }
}

void MemoryGame::click(int x, int y)
{
    cout << "Clicked " << x << " " << y << endl;

    // both cells are flipped
    if (first_cell != nullptr && second_cell != nullptr)
    {
        if (checkForMatch())
        {

            // cells match

            first_cell->isMatched = true;
            second_cell->isMatched = true;

            first_cell = nullptr;
            second_cell = nullptr;

            cout << "Cells match" << endl;
        }
        else
        {
            // cells don't match
            flip_cell(first_cell->x, first_cell->y, false);
            flip_cell(second_cell->x, second_cell->y, false);

            first_cell = nullptr;
            second_cell = nullptr;

            cout << "Cells don't match" << endl;
        }

        return;
    }

    if (x == -1 && y == -1)
    {
        return;
    }

    if (cells[x][y].isFlipped || cells[x][y].isMatched)
    {
        cout << "Cell already flipped or matched" << endl;
        return;
    }

    if (first_cell == nullptr)
    {
        // flip the cell
        first_cell = &cells[x][y];
        flip_cell(x, y, true);

        cout << "First cell flipped" << endl;
    }
    else if (second_cell == nullptr)
    {
        second_cell = &cells[x][y];
        flip_cell(x, y, true);

        cout << "Second cell flipped" << endl;
    }
}

void MemoryGame::draw()
{
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            if (!cells[i][j].isMatched)
            {

                string id = to_string(i) + to_string(j);
                // cout << "drawing cell " << id << endl;
                if (cells[i][j].isFlipped)
                {
                    // set the image
                    cout << "setting image for " << i << ' ' << 'j' << cells[i][j].value << endl;
                    utils::set_image(ui_context, id, images[cells[i][j].value]);
                }
                else
                {
                    // set the image
                    cout << "setting image for " << i << ' ' << 'j' << 0 << endl;
                    utils::set_image(ui_context, id, images[0]);
                }
            }
        }
    }
}

void MemoryGame::flip_cell(int x, int y, bool isFlipped)
{
    cells[x][y].isFlipped = isFlipped;
    // set the image
    string id = to_string(x) + to_string(y);
    if (isFlipped)
    {
        utils::set_image(ui_context, id, images[cells[x][y].value]);
    }
    else
    {
        utils::set_image(ui_context, id, images[0]);
    }
}