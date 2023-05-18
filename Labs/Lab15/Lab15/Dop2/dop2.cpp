#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    setlocale(LC_ALL, "rus");
    std::unordered_map<std::string, std::string> reserved_words{
        {"auto", "Defines automatic variables."},
        {"break", "Terminates the current loop or switch statement."},
        {"case", "Specifies a group of statements for a particular condition in a switch statement."},
        {"char", "Declares a character variable."},
        {"const", "Declares an unchangeable variable."},
        {"continue", "Jumps to the next iteration of the loop."},
        {"default", "Specifies the default case in a switch statement."},
        {"do", "Starts a do...while loop."},
        {"double", "Declares a double-precision floating-point variable."},
        {"else", "Specifies a statement to execute if the condition of an if...else statement is false."},
        {"enum", "Defines an enumeration type."},
        {"extern", "Declares a function or a variable as being available for use throughout the entire program."},
        {"float", "Declares a floating-point variable."},
        {"for", "Creates a loop that consists of three optional expressions: initialization, condition, and increment."},
        {"goto", "Transfers control to a labeled statement."},
        {"if", "Specifies a statement to execute if a condition is true."},
        {"int", "Declares an integer variable."},
        {"long", "Declares a long integer variable."},
        {"register", "Specifies that a variable should be stored in a register."},
        {"return", "Returns a value from a function."},
        {"short", "Declares a short integer variable."},
        {"signed", "Declares a signed variable."},
        {"sizeof", "Returns the size of a variable or data type in bytes."},
        {"static", "Declares a variable as static (it retains its value between function calls)."},
        {"struct", "Defines a structure."},
        {"switch", "Evaluates an expression, matches it to a case clause, and executes the statements associated with that case."},
        {"typedef", "Creates a new type definition."},
        {"union", "Defines a union."},
        {"unsigned", "Declares an unsigned variable."},
        {"void", "Specifies that a function does not return a value."},
        {"volatile", "Specifies that a variable's value may be changed unexpectedly."},
        {"while", "Starts a while loop."},
    };

    while (true) {
        // ввод слова
        std::string word;
        std::cout << "Input reserved word: ";
        std::cin >> word;
        if (word == "quit")
            return 0;

        // проверка наличия слова в таблице
        auto it = reserved_words.find(word);
        if (it != reserved_words.end()) {
            std::cout << it->second << std::endl; // вывод подсказки
        }
        else {
            // слово не найдено, запрашиваем HELP
            std::string help;
            std::cout << "Word \"" << word << "\" hasn't been reserved yet. Type ADD if you want to reserve it: ";
            std::cin >> help;
            if (help == "ADD") {
                std::string help_text;
                std::cout << "Input help for the word \"" << word << "\": ";
                std::cin.ignore(); // игнорируем символ новой строки во входном буфере
                std::getline(std::cin, help_text);
                reserved_words[word] = help_text; // добавляем слово и подсказку в таблицу
                std::cout << "Hepl for the word \"" << word << "\" has just been added." << std::endl;
            }
            else {
                std::cout << "Incorred input!." << std::endl;
            }
        }
    }

    return 0;
}
