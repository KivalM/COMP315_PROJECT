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

    // set bindings
    w->bind("start", {});
    w->bind("about", {});
    w->bind(
        "quit", [this](const std::string &r) -> std::string
        { w->terminate(); return ""; });
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

    for (int i = 1; i <= 14; i++)
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
    std::string base64_encoded = utils::base64_encode(file_data);

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