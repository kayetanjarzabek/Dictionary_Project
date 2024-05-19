#pragma once
#include <string>

using namespace std;

//Creating a namespace for colors to be used in the console in other files, such as in main and makes sure the code for the enduser is clean
namespace Colors
{
    //Foreground Colors
    const string BLACK = "\033[30m";
    const string RED = "\033[31m";
    const string GREEN = "\033[32m";
    const string YELLOW = "\033[33m";
    const string BLUE = "\033[34m";
    const string MAGENTA = "\033[35m";
    const string CYAN = "\033[36m";
    const string WHITE = "\033[37m";

    //Bright Foreground Colors
    const string BRIGHT_BLACK = "\033[90m";
    const string BRIGHT_RED = "\033[91m";
    const string BRIGHT_GREEN = "\033[92m";
    const string BRIGHT_YELLOW = "\033[93m";
    const string BRIGHT_BLUE = "\033[94m";
    const string BRIGHT_MAGENTA = "\033[95m";
    const string BRIGHT_CYAN = "\033[96m";
    const string BRIGHT_WHITE = "\033[97m";

    //Alternative shades (Foreground)
    const string DARK_RED = "\033[38;5;52m";
    const string DARK_GREEN = "\033[38;5;22m";
    const string DARK_YELLOW = "\033[38;5;58m";
    const string DARK_BLUE = "\033[38;5;17m";
    const string DARK_MAGENTA = "\033[38;5;53m";
    const string DARK_CYAN = "\033[38;5;23m";
    const string DARK_WHITE = "\033[38;5;250m";

    //Background Colors
    const string BG_BLACK = "\033[40m";
    const string BG_RED = "\033[41m";
    const string BG_GREEN = "\033[42m";
    const string BG_YELLOW = "\033[43m";
    const string BG_BLUE = "\033[44m";
    const string BG_MAGENTA = "\033[45m";
    const string BG_CYAN = "\033[46m";
    const string BG_WHITE = "\033[47m";

    //Bright Background Colors
    const string BG_BRIGHT_BLACK = "\033[100m";
    const string BG_BRIGHT_RED = "\033[101m";
    const string BG_BRIGHT_GREEN = "\033[102m";
    const string BG_BRIGHT_YELLOW = "\033[103m";
    const string BG_BRIGHT_BLUE = "\033[104m";
    const string BG_BRIGHT_MAGENTA = "\033[105m";
    const string BG_BRIGHT_CYAN = "\033[106m";
    const string BG_BRIGHT_WHITE = "\033[107m";

    //Text Formatting
    const string BOLD = "\033[1m";
    const string DIM = "\033[2m";
    const string UNDERLINE = "\033[4m";
    const string BLINK = "\033[5m";
    const string REVERSE = "\033[7m";
    const string HIDDEN = "\033[8m";

    //Reset formatting
    const string RESET_BOLD = "\033[21m";
    const string RESET_DIM = "\033[22m";
    const string RESET_UNDERLINE = "\033[24m";
    const string RESET_BLINK = "\033[25m";
    const string RESET_REVERSE = "\033[27m";
    const string RESET_HIDDEN = "\033[28m";

    //Reset all
    const string RESET = "\033[0m";
}

/* Examples:
    std::cout << "Foreground Colors:" << std::endl;
    std::cout << BLACK << "Black" << RESET << std::endl;
    std::cout << RED << "Red" << RESET << std::endl;
    std::cout << GREEN << "Green" << RESET << std::endl;
    std::cout << YELLOW << "Yellow" << RESET << std::endl;
    std::cout << BLUE << "Blue" << RESET << std::endl;
    std::cout << MAGENTA << "Magenta" << RESET << std::endl;
    std::cout << CYAN << "Cyan" << RESET << std::endl;
    std::cout << WHITE << "White" << RESET << std::endl;

    std::cout << "Bright Foreground Colors:" << std::endl;
    std::cout << BRIGHT_BLACK << "Bright Black" << RESET << std::endl;
    std::cout << BRIGHT_RED << "Bright Red" << RESET << std::endl;
    std::cout << BRIGHT_GREEN << "Bright Green" << RESET << std::endl;
    std::cout << BRIGHT_YELLOW << "Bright Yellow" << RESET << std::endl;
    std::cout << BRIGHT_BLUE << "Bright Blue" << RESET << std::endl;
    std::cout << BRIGHT_MAGENTA << "Bright Magenta" << RESET << std::endl;
    std::cout << BRIGHT_CYAN << "Bright Cyan" << RESET << std::endl;
    std::cout << BRIGHT_WHITE << "Bright White" << RESET << std::endl;

    std::cout << "Alternative Shades:" << std::endl;
    std::cout << DARK_RED << "Dark Red" << RESET << std::endl;
    std::cout << DARK_GREEN << "Dark Green" << RESET << std::endl;
    std::cout << DARK_YELLOW << "Dark Yellow" << RESET << std::endl;
    std::cout << DARK_BLUE << "Dark Blue" << RESET << std::endl;
    std::cout << DARK_MAGENTA << "Dark Magenta" << RESET << std::endl;
    std::cout << DARK_CYAN << "Dark Cyan" << RESET << std::endl;
    std::cout << DARK_WHITE << "Dark White" << RESET << std::endl;

    std::cout << "Background Colors:" << std::endl;
    std::cout << BG_BLACK << "Black Background" << RESET << std::endl;
    std::cout << BG_RED << "Red Background" << RESET << std::endl;
    std::cout << BG_GREEN << "Green Background" << RESET << std::endl;
    std::cout << BG_YELLOW << "Yellow Background" << RESET << std::endl;
    std::cout << BG_BLUE << "Blue Background" << RESET << std::endl;
    std::cout << BG_MAGENTA << "Magenta Background" << RESET << std::endl;
    std::cout << BG_CYAN << "Cyan Background" << RESET << std::endl;
    std::cout << BG_WHITE << "White Background" << RESET << std::endl;

    std::cout << "Bright Background Colors:" << std::endl;
    std::cout << BG_BRIGHT_BLACK << "Bright Black Background" << RESET << std::endl;
    std::cout << BG_BRIGHT_RED << "Bright Red Background" << RESET << std::endl;
    std::cout << BG_BRIGHT_GREEN << "Bright Green Background" << RESET << std::endl;
    std::cout << BG_BRIGHT_YELLOW << "Bright Yellow Background" << RESET << std::endl;
    std::cout << BG_BRIGHT_BLUE << "Bright Blue Background" << RESET << std::endl;
    std::cout << BG_BRIGHT_MAGENTA << "Bright Magenta Background" << RESET << std::endl;
    std::cout << BG_BRIGHT_CYAN << "Bright Cyan Background" << RESET << std::endl;
    std::cout << BG_BRIGHT_WHITE << "Bright White Background" << RESET << std::endl;

    std::cout << "Text Formatting:" << std::endl;
    std::cout << BOLD << "Bold" << RESET << std::endl;
    std::cout << DIM << "Dim" << RESET << std::endl;
    std::cout << UNDERLINE << "Underline" << RESET << std::endl;
    std::cout << BLINK << "Blink" << RESET << std::endl;
    std::cout << REVERSE << "Reverse" << RESET << std::endl;
    std::cout << HIDDEN << "Hidden" << RESET << std::endl;

    std::cout << "Reset Formatting:" << std::endl;
    std::cout << RESET_BOLD << "Reset Bold" << RESET << std::endl;
    std::cout << RESET_DIM << "Reset Dim" << RESET << std::endl;
    std::cout << RESET_UNDERLINE << "Reset Underline" << RESET << std::endl;
    std::cout << RESET_BLINK << "Reset Blink" << RESET << std::endl;
    std::cout << RESET_REVERSE << "Reset Reverse" << RESET << std::endl;
    std::cout << RESET_HIDDEN << "Reset Hidden" << RESET << std::endl;
*/