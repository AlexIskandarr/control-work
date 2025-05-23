#define _CRT_SECURE_NO_WARNINGS_
#include <iostream>
#include <cstring>
#include <stdexcept>


struct Entry {
    std::string original;
    int32_t key;
};

int32_t extract_key(const std::string& line) {
    size_t last_space = line.rfind(' ');
    if (last_space == std::string::npos) {
        throw std::invalid_argument("Invalid line format");
    }
    return std::stoi(line.substr(last_space + 1));
}

int main(){
    Entry* entries {nullptr};
    int32_t capacity {};
    int32_t size {};
 
    std::string line;
    std::cout << "enter u strings: \n";
    while (std::getline(std::cin, line)) {
        if (line.empty()) break;

        int32_t key = extract_key(line);

        if (size >= capacity) {
            int32_t new_capacity = (capacity == 0) ? 2 : capacity * 2;
            Entry* new_entries = new Entry[new_capacity];
            for (int32_t i = 0; i < size; i++) {
                new_entries[i] = entries[i];
            }
            delete[] entries;
            entries = new_entries;
            capacity = new_capacity;
        }

        entries[size].original = line;
        entries[size].key = key;
        ++size;
    }

    for (int32_t i = 1; i < size; ++i) {
        Entry current = entries[i];
        int32_t j = i - 1;
        while (j >= 0 && entries[j].key > current.key) {
            entries[j + 1] = entries[j];
            j--;
        }
        entries[j + 1] = current;
    }

    for (int32_t i = 0; i < size; ++i) {
        std::cout <<entries[i].original << '\n';
    }

    delete[] entries;
    return 0;
}
