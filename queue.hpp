#pragma once

#include "singly linked list.hpp"

using namespace std;
// очередь

struct Queue {
    singlyList qList; // используем команды односвязного листа

    void push(string _item) { // добавление элементов в хвост
        qList.addToEnd(_item);
    }

    void pop() { // удаление элемента из головы
        qList.delFromHead();
    }

    void findIndex(int index) { // поиск элемента по индексу
        qList.findIndex(index);
    }

    void printQueue() { // вывод всех элементов очереди
        qList.printList();
    }

    void loadFromFile(const string& file) { // загрузка данных из файла
       qList.loadFromFile(file);
    }

    void saveToFile(const string& file) { // сохранение в файл
        qList.saveToFile(file);
    }
};