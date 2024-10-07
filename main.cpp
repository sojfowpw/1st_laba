#include <iostream>
#include <sstream> // работа с потоками строк
#include <fstream>

#include "singly linked list.hpp"
#include "double linked list.hpp"
#include "queue.hpp"

using namespace std;

singlyList sList; // создание односвзяного листа
doubleList dList; // создание двусвязного листа
Queue q; // создание очереди

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


    // двусвязный список
    else if (command == "DLPUSH_HEAD") { // добавление элемента в голову
        dList.loadFromFile("dlist.txt");
        string item; // добавляемый элемент
        ss >> item; // считываем элемент
        dList.addToHead(item);
        dList.saveToFile("dlist.txt"); 
    }
    else if (command == "DLPUSH_TAIL") { // добавление в хвост
        dList.loadFromFile("dlist.txt");
        string item;
        ss >> item;
        dList.addToEnd(item);
        dList.saveToFile("dlist.txt"); 
    }
    else if (command == "DLDEL_HEAD") { // удаление из головы
        dList.loadFromFile("dlist.txt");
        dList.delFromHead();
        dList.saveToFile("dlist.txt"); 
    }
    else if (command == "DLDEL_TAIL") { // удаление из хвоста
        dList.loadFromFile("dlist.txt");
        dList.delFromEnd();
        dList.saveToFile("dlist.txt"); 
    }
    else if (command == "DLDEL_VALUE") { // удаление по значению
        dList.loadFromFile("dlist.txt");
        string item;
        ss >> item;
        dList.delItem(item);
        dList.saveToFile("dlist.txt"); 
    }
    else if (command == "DLFIND_VALUE") { // поиск по значению
        string item;
        ss >> item;
        dList.findItem(item);
    }
    else if (command == "DLGET") { // поиск по индексу (чтение)
        int index;
        ss >> index;
        dList.findIndex(index);
    }
    else if (command == "DLPRINT") { // вывод списка
        dList.loadFromFile("dlist.txt");
        dList.printList();
    }


    // очередь
    else if (command == "QPUSH") { // добавление элемента в хвост
        q.loadFromFile("queue.txt");
        string item;
        ss >> item;
        q.push(item);
        q.saveToFile("queue.txt");
    }
    else if (command == "QPOP") { // удаление элемента из головы
        q.loadFromFile("queue.txt");
        q.pop();
        q.saveToFile("queue.txt");
    }
    else if (command == "QGET") { // поиск элемента по индексу (чтение)
        int index;
        ss >> index;
        q.findIndex(index);
    }
    else if (command == "QPRINT") {
        q.loadFromFile("queue.txt");
        q.printQueue();
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