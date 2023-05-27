#include "utils.h"

vector<string> utils::load_backgrounds()
{
    string img_dir = "data\\img\\bg\\";
    vector<string> backgrounds;

    for (int i = 1; i <= 5; i++)
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

vector<string> utils::load_matching_game()
{
    string img_dir = "data\\img\\matching\\";
    vector<string> matching_game;

    for (int i = 1; i <= 9; i++)
    {
        string img_path = img_dir + to_string(i) + ".png";
        string base64_encoded = utils::load_img_to_base64(img_path);
        matching_game.push_back(base64_encoded);
    }

    return matching_game;
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

    // load memory game template
    string memory_game_path = img_dir + "memory_game.html";
    std::ifstream memory_game_file(memory_game_path);

    if (!memory_game_file)
    {
        std::cerr << "Failed to open the memory game template file: " << memory_game_path << std::endl;
        return html_templates;
    }

    std::ostringstream memory_game_oss;
    std::copy(std::istreambuf_iterator<char>(memory_game_file), {}, std::ostreambuf_iterator<char>(memory_game_oss));

    const std::string &memory_game_template = memory_game_oss.str();
    html_templates.push_back(memory_game_template);

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

void utils::set_width(webview::webview *w,
                      const std::string &id, int width)
{
    w->eval("document.getElementById('" + id + "').style.width = '" + std::to_string(width) + "%';");
}

void utils::set_color(webview::webview *w,
                      const std::string &id, int r, int g, int b, int a)
{
    w->eval("document.getElementById('" + id + "').style.color = 'rgba(" + std::to_string(r) + "," + std::to_string(g) + "," + std::to_string(b) + "," + std::to_string(a) + ")';");
}
