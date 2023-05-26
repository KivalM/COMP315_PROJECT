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
    utils::set_image(w.get(), "background", this->backgrounds[1]);

    // set bindings
    w->bind("start", {[this](const std::string &r) -> std::string
                      { this->game_settings(); return ""; }});
    w->bind("how_to_play", {[this](const std::string &r) -> std::string
                            { this->how_to_play(); return ""; }});
    w->bind(
        "quit", [this](const std::string &r) -> std::string
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
        game->next_stage();
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
        // increment inner to game pointer
        game->correct_answer();
    }
    else
    {
        utils::set_text(w.get(), "char-text", "Incorrect!");
        game->incorrect_answer();
    }

    update_meter();

    // set callbacks
    w->bind("next", {[this](const string &r) -> string
                     {
                        game->current = game->current->next;
                        draw_question_stage();return ""; }});
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

    // set callbacks
    if (dialog->type == DialogType::DIALOG)
    {
        cout << "Drawing Dialog" << endl;
        // onclick we will go to the next dialog
        utils::set_hidden(w.get(), "options", true);
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

void GUI::update_meter()
{
    // update the meter
    utils::set_text(w.get(), "meter-percent", to_string(game->get_score()) + " %");
    utils::set_width(w.get(), "meter-fill", game->get_score());
}
