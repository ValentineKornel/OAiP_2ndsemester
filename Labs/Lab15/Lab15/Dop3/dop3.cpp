#include <iostream>
#include <fstream>
#include <unordered_map>
#include <string>

int main() {
    setlocale(LC_ALL, "RUS");
    std::unordered_map<std::string, int> hashtable;

    // Открытие файла и чтение слов из него
    std::ifstream input_file("text.txt");
    std::string word;
    while (input_file >> word) {
        hashtable[word]++;
    }
    input_file.close();

    // Вывод таблицы слов на экран
    std::cout << "Here is hash-table:\n";
    for (const auto& pair : hashtable) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Поиск слова в хеш-таблице
    std::string search_word;
    std::cout << "Input word to search: ";
    std::cin >> search_word;

    int num_of_compares = 0; // переменная для подсчета количества сравнений
    auto search_result = hashtable.find(search_word);
    if (search_result != hashtable.end()) {
        std::cout << "Word " << search_word << " was founded if hash-table.\n";
        num_of_compares = 1; // поиск успешен, 1 сравнение выполнено
    }
    else {
        std::cout << "Word " << search_word << " wasn't founded in hash-table\n";
        num_of_compares = hashtable.bucket_size(hashtable.bucket(search_word)); // подсчет количества сравнений для неудачного поиска

    }
    // Удаление слов, начинающихся на указанную букву
    char start_letter;
    std::cout << "Input the firts letter of words to delete: ";
    std::cin >> start_letter;
    std::cout << std::endl;

    for (auto it = hashtable.begin(); it != hashtable.end();) {
        if (it->first.front() == start_letter) {
            it = hashtable.erase(it);
        }
        else {
            ++it;
        }
    }

    // Вывод таблицы слов на экран после удаления
    std::cout << "Hash-table after deleting " << start_letter << ":\n";
    for (const auto& pair : hashtable) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
