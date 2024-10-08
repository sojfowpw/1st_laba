#pragma once

#include "singly linked list.hpp"

using namespace std;
// стэк

struct Stack {
    singlyList stackList; // подключаем команды односвязного листа

    void push(string _item) { // добавление элемента в начало
        stackList.addToHead(_item);
    }

    void pop() { // удаление узла с головы
        stackList.delFromHead();
    }

    void findIndex(int index) { // поиск элемента по индексу
        stackList.findIndex(index);
    }

    void printStack() { // вывод всех элементов стэка (голова слева)
        stackList.printList();
    }

    void loadFromFile (const string& file) { // загрузка данных из файла
        stackList.loadFromFile(file);
    }

    void saveToFile (const string& file) { // сохранение в файл
        stackList.saveToFile(file);
    }
};