#include <iostream>
#include <sstream> // работа с потоками строк
#include <fstream>

#include "singly linked list.hpp"

using namespace std;

singlyList sList; // создание односвзяного листа

void commands(const string& query) { // обработка входящих команд
    stringstream ss(query); // создаём объект и инициализиурем его строкой
    string command; // переменная для команды
    ss >> command; // извлекаем слово из команды в переменную


    // односвязный список
    if (command == "SLPUSH_HEAD") { // добавление в голову
        sList.loadFromFile("slist.txt");
        string item; // добавляемый элемент
        ss >> item; // считываем элемент
        sList.addToHead(item);
        sList.saveToFile("slist.txt"); 
    }
    else if (command == "SLPUSH_TAIL") { // добавление в хвост
        sList.loadFromFile("slist.txt");
        string item;
        ss >> item;
        sList.addToEnd(item);
        sList.saveToFile("slist.txt"); 
    }
    else if (command == "SLDEL_HEAD") { // удаление из головы
        sList.loadFromFile("slist.txt");
        sList.delFromHead();
        sList.saveToFile("slist.txt"); 
    }
    else if (command == "SLDEL_TAIL") { // удаление из хвоста
        sList.loadFromFile("slist.txt");
        sList.delFromEnd();
        sList.saveToFile("slist.txt"); 
    }
    else if (command == "SLDEL_VALUE") { // удаление по значению
        sList.loadFromFile("slist.txt");
        string item;
        ss >> item;
        sList.delItem(item);
        sList.saveToFile("slist.txt"); 
    }
    else if (command == "SLFIND_VALUE") { // поиск по значению
        string item;
        ss >> item;
        sList.findItem(item);
    }
    else if (command == "SLGET") { // поиск по индексу (чтение)
        int index;
        ss >> index;
        sList.findIndex(index);
    }
    else if (command == "SLPRINT") { // вывод списка
        sList.loadFromFile("slist.txt");
        sList.printList();
    }
}

int main(int argc, char* argv[]) { // argc - количество аргументов команды, argv - массив указателей на строки
    /*string file; // имя файла
    for (int i = 0; i < argc; i++) {
        string arg = argv[i];
        if (arg == "--file" && i + 1 < argc) { // если аргумент равен --file и не последний
            file = argv[++i]; // присваиваем имя файла
        }
    }*/

    string query; // переменная для введенной команды
    while (true) {
        cout << "Введите команду: ";
        getline(cin, query); // ввод команды
        if (query == "EXIT") { // выход из цикла
            break;
        }
        commands(query); // обработка задач из входящих команд
    }
    return 0;
}