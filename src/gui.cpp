#include "gui.h"
#include "game.h"

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
    w->set_title("WRATH");
    w->set_size(1280, 720, WEBVIEW_HINT_NONE);
    this->main_menu();
    cout << "Setup the UI!" << endl;
}

void GUI::main_menu()
{
    // load the main menu
    w->set_html(this->html_templates[0]);
    utils::set_image(w.get(), "background", this->backgrounds[11]);

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
    utils::set_image(w.get(), "background", this->backgrounds[10]);

    // set bindings
    w->bind("back", {[this](const std::string &r) -> std::string
                     { this->main_menu(); return ""; }});
}

void GUI::game_settings()
{
    // load the game settings menu
    w->set_html(this->html_templates[2]);
    utils::set_image(w.get(), "background", this->backgrounds[10]);

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

    draw();
}

void GUI::draw()
{
    // unbind all the buttons
    w->unbind("next");
    w->unbind("option_1");
    w->unbind("option_2");
    w->unbind("option_3");
    w->unbind("option_4");

    // set the background
    utils::set_image(w.get(), "background", this->backgrounds[this->game->current->bg]);

    if ((this->game->current->char_to_draw != -1))
    {
        if (this->game->characters[this->game->current->char_to_draw].image != -1)
        {
            // unhide the character
            utils::set_hidden(w.get(), "char-img", false);

            // set the character sprite
            Character *c = &this->game->characters[this->game->current->char_to_draw];
            utils::set_image(w.get(), "char-img", this->character_sprites[c->image]);
        }
    }
    else
    {
        utils::set_hidden(w.get(), "char-img", true);
    }

    if (this->game->current->speaking != -1)
    {
        Character *c = &this->game->characters[this->game->current->speaking];
        // set the character name
        utils::set_text(w.get(), "char-name", c->name);
    }

    // set the character text
    cout << "Setting text to: " << this->game->current->text << endl;
    // sleep for 1 second
    std::this_thread::sleep_for(std::chrono::milliseconds(150));
    utils::set_text(w.get(), "char-text", this->game->current->text);

    // set callbacks
    if (this->game->current->type == DialogType::DIALOG)
    {
        cout << "Drawing Dialog" << endl;
        // if it is not a choice, onclick we will go to the next dialog
        utils::set_hidden(w.get(), "options", true);

        w->bind("next", {[this](const std::string &r) -> std::string
                         { cout << "called next"<< endl;this->game->current = this->game->current->next;
            draw();
            return ""; }});
    }
    else if (this->game->current->type == DialogType::CHOICE)
    {
        cout << "Drawing Choice" << endl;
        utils::set_hidden(w.get(), "options", false);

        // if it is a choice, we ignore the call to next and instead

        utils::set_text(w.get(), "option_1", this->game->current->option1->text);

        // only handle the choice callbacks
        w->bind("option_1", {[this](const std::string &r) -> std::string
                             { this->game->current =this->game->current->option1->next;
                                    draw();
                                   return ""; }});

        utils::set_text(w.get(), "option_2", this->game->current->option2->text);
        w->bind("option_2", {[this](const std::string &r) -> std::string
                             { this->game->current =this->game->current->option2->next;
            draw();
            return ""; }});

        utils::set_text(w.get(), "option_3", this->game->current->option3->text);
        w->bind("option_3", {[this](const std::string &r) -> std::string
                             { this->game->current =this->game->current->option3->next;
            draw();
            return ""; }});

        utils::set_text(w.get(), "option_4", this->game->current->option4->text);
        w->bind("option_4", {[this](const std::string &r) -> std::string
                             { this->game->current =this->game->current->option4->next;
            draw();
            return ""; }});
    }
    else
    {
        cout << "Drawing End" << endl;
        utils::set_hidden(w.get(), "options", true);
        w->bind("next", {[this](const std::string &r) -> std::string
                         { this->game->current = this->game->current->next;
            draw();
            return ""; }});
    }
}

void GUI::start()
{
    w->run();
}

void GUI::hide()
{
    // You can perform any necessary cleanup or additional actions
    // when hiding the GUI here.
}

vector<string> utils::load_backgrounds()
{
    string img_dir = "data\\img\\bg\\";
    vector<string> backgrounds;

    for (int i = 1; i <= 15; i++)
    {
        string img_path = img_dir + to_string(i) + ".png";
        string base64_encoded = utils::load_img_to_base64(img_path);
        backgrounds.push_back(base64_encoded);
    }

    return backgrounds;
}

vector<string> utils::load_character_sprites()
{
    string img_dir = "data\\img\\char\\";
    vector<string> backgrounds;

    for (int i = 1; i <= 10; i++)
    {
        string img_path = img_dir + to_string(i) + ".png";
        string base64_encoded = utils::load_img_to_base64(img_path);
        backgrounds.push_back(base64_encoded);
    }

    return backgrounds;
}

vector<string> utils::load_html_templates()
{
    string img_dir = "data\\templates\\";
    vector<string> html_templates;

    // load menu template
    string menu_path = img_dir + "menu.html";
    std::ifstream menu_file(menu_path);

    if (!menu_file)
    {
        std::cerr << "Failed to open the menu template file: " << menu_path << std::endl;
        return html_templates;
    }

    std::ostringstream menu_oss;
    std::copy(std::istreambuf_iterator<char>(menu_file), {}, std::ostreambuf_iterator<char>(menu_oss));

    const std::string &menu_template = menu_oss.str();
    html_templates.push_back(menu_template);

    // load how to play template
    string how_to_play_path = img_dir + "how_to_play.html";
    std::ifstream how_to_play_file(how_to_play_path);

    if (!how_to_play_file)
    {
        std::cerr << "Failed to open the how to play template file: " << how_to_play_path << std::endl;
        return html_templates;
    }

    std::ostringstream how_to_play_oss;
    std::copy(std::istreambuf_iterator<char>(how_to_play_file), {}, std::ostreambuf_iterator<char>(how_to_play_oss));

    const std::string &how_to_play_template = how_to_play_oss.str();
    html_templates.push_back(how_to_play_template);

    // load game settings template
    string game_settings_path = img_dir + "game_settings.html";
    std::ifstream game_settings_file(game_settings_path);

    if (!game_settings_file)
    {
        std::cerr << "Failed to open the game settings template file: " << game_settings_path << std::endl;
        return html_templates;
    }

    std::ostringstream game_settings_oss;
    std::copy(std::istreambuf_iterator<char>(game_settings_file), {}, std::ostreambuf_iterator<char>(game_settings_oss));

    const std::string &game_settings_template = game_settings_oss.str();
    html_templates.push_back(game_settings_template);

    // load game template
    string game_path = img_dir + "game.html";
    std::ifstream game_file(game_path);

    if (!game_file)
    {
        std::cerr << "Failed to open the game template file: " << game_path << std::endl;
        return html_templates;
    }

    std::ostringstream game_oss;
    std::copy(std::istreambuf_iterator<char>(game_file), {}, std::ostreambuf_iterator<char>(game_oss));

    const std::string &game_template = game_oss.str();
    html_templates.push_back(game_template);

    return html_templates;
}

/*
 * Base64 encoding and decoding
 * https://stackoverflow.com/questions/180947/base64-decode-snippet-in-c
 */
std::string utils::load_img_to_base64(const std::string &path)
{
    std::ifstream image_file(path, std::ios::binary);
    if (!image_file)
    {
        std::cerr << "Failed to open the image file: " << path << std::endl;
        return "";
    }

    std::ostringstream oss;
    std::copy(std::istreambuf_iterator<char>(image_file), {}, std::ostreambuf_iterator<char>(oss));

    const std::string &file_data = oss.str();
    std::string base64_encoded = utils::construct_img_url(utils::base64_encode(file_data));

    return base64_encoded;
}

std::string utils::base64_encode(const std::string &input)
{
    const std::string base64_chars =
        "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
        "abcdefghijklmnopqrstuvwxyz"
        "0123456789+/";

    std::string encoded;
    int i = 0;
    int j = 0;
    unsigned char char_array_3[3];
    unsigned char char_array_4[4];

    for (const auto &c : input)
    {
        char_array_3[i++] = c;
        if (i == 3)
        {
            char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
            char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
            char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);
            char_array_4[3] = char_array_3[2] & 0x3f;

            for (int k = 0; k < 4; k++)
            {
                encoded += base64_chars[char_array_4[k]];
            }

            i = 0;
        }
    }

    if (i > 0)
    {
        for (int k = i; k < 3; k++)
        {
            char_array_3[k] = '\0';
        }

        char_array_4[0] = (char_array_3[0] & 0xfc) >> 2;
        char_array_4[1] = ((char_array_3[0] & 0x03) << 4) + ((char_array_3[1] & 0xf0) >> 4);
        char_array_4[2] = ((char_array_3[1] & 0x0f) << 2) + ((char_array_3[2] & 0xc0) >> 6);

        for (int k = 0; k < i + 1; k++)
        {
            encoded += base64_chars[char_array_4[k]];
        }

        while ((i++ < 3))
        {
            encoded += '=';
        }
    }

    return encoded;
}

std::string utils::replace_placeholder(std::string text, const std::string &placeholder, const std::string &value)
{

    std::size_t pos = text.find(placeholder);
    if (pos != std::string::npos)
    {
        std::string result = text;
        result.replace(pos, placeholder.length(), value);
        return result;
    }
    return text;
}

std::string utils::construct_img_url(const std::string &base64Data)
{
    return "data:image/png;base64," + base64Data;
}

void utils::set_image(webview::webview *w,
                      const std::string &id, const std::string &base64Data)
{
    // set background image css
    w->eval("document.getElementById('" + id + "').style.backgroundImage = 'url(" + base64Data + ")';");
}

void utils::set_text(webview::webview *w,
                     const std::string &id, const std::string &text)
{

    // escape single quotes
    std::string escaped_text = text;
    std::size_t pos = 0;
    while ((pos = escaped_text.find("'", pos)) != std::string::npos)
    {
        escaped_text.replace(pos, 1, "\\'");
        pos += 2;
    }

    // set text
    w->eval("document.getElementById('" + id + "').innerHTML = '" + escaped_text + "';");
}

void utils::set_hidden(webview::webview *w,
                       const std::string &id, bool hidden)
{
    // set hidden
    w->eval("document.getElementById('" + id + "').style.visibility = '" + (hidden ? "hidden" : "visible") + "';");
}