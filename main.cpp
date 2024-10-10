#include <iostream>
#include <sstream> // работа с потоками строк
#include <fstream>

#include "array.hpp"
#include "singly linked list.hpp"
#include "double linked list.hpp"
#include "queue.hpp"
#include "stack.hpp"
#include "cbt.hpp"
#include "hashtable.hpp"

using namespace std;

Array a; // создание массива
singlyList sList; // создание односвзяного листа
doubleList dList; // создание двусвязного листа
Queue q; // создание очереди
Stack s; // создание стэка
CBT tree; // создание дерева
hashTable ht = hashTable(); // создание хэш-таблицы

void commands(const string& query) { // обработка входящих команд
    stringstream ss(query); // создаём объект и инициализиурем его строкой
    string command; // переменная для команды
    ss >> command; // извлекаем слово из команды в переменную


    // массив
    if (command == "MPUSH_IND") { // добавление по индексу
        a.loadFromFile("array.txt");
        string item;
        size_t index;
        ss >> item >> index;
        a.addByInd(item, index);
        a.saveToFile("array.txt");
    }
    else if (command == "MPUSH_BACK") { // добавление в конец
        a.loadFromFile("array.txt");
        string item;
        ss >> item;
        a.addToEnd(item);
        a.saveToFile("array.txt");
    }
    else if (command == "MFIND_INDEX") { // поиск по индексу
        a.loadFromFile("array.txt");
        size_t index;
        ss >> index;
        a.findByIndex(index);
    }
    else if (command == "MDEL") { // удаление по индексу
        a.loadFromFile("array.txt");
        size_t index;
        ss >> index;
        a.delByIndex(index);
        a.saveToFile("array.txt");
    }
    else if (command == "MREPLACE") { // замена элемента по индексу
        a.loadFromFile("array.txt");
        size_t index;
        string item;
        ss >> index >> item;
        a.replace(index, item);
        a.saveToFile("array.txt");
    }
    else if (command == "MSIZE") { // длина массива
        a.loadFromFile("array.txt");
        a.length();
    }
    else if (command == "MGET") { // чтение (поиск по значению)
        a.loadFromFile("array.txt");
        string item;
        ss >> item;
        a.findByItem(item);
    }
    else if (command == "MPRINT") { // вывод элементов массива
        a.loadFromFile("array.txt");
        a.printArray();
    }


    // односвязный список
    else if (command == "SLPUSH_HEAD") { // добавление в голову
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
        q.loadFromFile("queue.txt");
        int index;
        ss >> index;
        q.findIndex(index);
    }
    else if (command == "QPRINT") { // вывод элементов очереди
        q.loadFromFile("queue.txt");
        q.printQueue();
    }


    // стэк
    else if (command == "SPUSH") { // добавление в голову
        s.loadFromFile("stack.txt");
        string item;
        ss >> item;
        s.push(item);
        s.saveToFile("stack.txt");
    }
    else if (command == "SPOP") { // удаление из головы
        s.loadFromFile("stack.txt");
        s.pop();
        s.saveToFile("stack.txt");
    }
    else if (command == "SGET") { // чтение (поиск элемента по индексу)
        s.loadFromFile("stack.txt");
        int index;
        ss >> index;
        s.findIndex(index);
    }
    else if (command == "SPRINT") { // вывод элементов стэка
        s.loadFromFile("stack.txt");
        s.printStack();
    }


    // cbt
    else if (command == "TINSERT") { // добавление элемента
        tree.loadFromFile("cbt.txt");
        int item;
        ss >> item;
        tree.insert(item);
        tree.saveToFile("cbt.txt");
    }
    else if (command == "TFIND_VAL") { // поиск элемента
        tree.loadFromFile("cbt.txt");
        int item;
        ss >> item;
        cout << boolalpha << tree.findVal(item) << endl;
    }
    else if (command == "TGET") { // поиск по индексу (чтение)
        tree.loadFromFile("cbt.txt");
        int index;
        ss >> index;
        tree.findIndex(index);
    }
    else if (command == "IS_CBT") { // проверка на cbt
        tree.loadFromFile("cbt.txt");
        cout << boolalpha << tree.isCBT() << endl;
    }
    else if (command == "TPRINT") { // вывод дерева
        tree.loadFromFile("cbt.txt");
        tree.printTree();
    }


    //хэш-таблица
    else if (command == "HSET") { // добавление элемента
        ht.loadFromFile(ht, "ht.txt");
        string key;
        string item;
        ss >> key >> item;
        ht.insert(ht, key, item);
        ht.saveToFile(ht, "ht.txt");
    }
    else if (command == "HGET") { // поиск элемента
        ht.loadFromFile(ht, "ht.txt");
        string key;
        int index;
        ss >> key >> index;
        cout << ht.get(ht, key) << endl;
    }
    else if (command == "HDEL") { // удаление элемента
        ht.loadFromFile(ht, "ht.txt");
        string key;
        ss >> key;
        ht.del(ht, key);
        ht.saveToFile(ht, "ht.txt");
    }
    else if (command == "HPRINT") { // вывод хэш-таблицы
        ht.loadFromFile(ht, "ht.txt");
        ht.printHashTable(ht);
    }
    else {
        cout << "Неизвестная команда.\n";
    }
}

int main() {
    ht.initialisation(ht);
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