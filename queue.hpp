#pragma once
#include <iostream>
#include <string>

using namespace std;
// очередь
struct qNode { // узел связного списка
    string item; // значение узла
    qNode* next; // указатель на следующий узел

    qNode(string _item) : item(_item), next(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct Queue {
    qNode* front; // указатель на 1 узел
    qNode* rear; // указатель на последний узел
    Queue() : front(nullptr), rear(nullptr) {} // конструктор для создания пустого списка

    bool is_empty() { // проверка, пустой ли список
        return front == nullptr; // если 1 узел пустой, то список пустой
    }

    void push(string _item) { // добавление элементов в хвост
        qNode* newNode = new qNode(_item); // создаём новый узел с заданным значением
        if (rear == nullptr) { // если очередь пуста
            front = rear = newNode; // новый узел становится и началом, и концом очереди
        }
        else {
            rear->next = newNode; // новый узел становится последним
            rear = newNode; // хвост теперь является новым узлом
        }
    }

    void pop() { // удаление элемента из головы
        if (is_empty()) { // проверка на пустоту
            cout << "Очередь пуста.\n";
            return;
        }
        qNode* newNode = front; // новый узел становится первым
        front = newNode->next; // голова теперь указывает на второй узел
        delete newNode; // первый узел - новый удаляется
    }

    void findIndex(int index) { // поиск элемента по индексу
        if (is_empty()) { // проверка на пустоту
            cout << "Очередь пуста.\n";
            return;
        }
        qNode* newNode = front; // новый указатель на голову
        for (int i = 0; i < index && newNode; i++) { // проходимся по списку, пока текущий индекс не будет равен заданному
            newNode = newNode->next;
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в очереди.\n";
            return;
        }
        cout << "Элемент по индексу: " << newNode->item << endl; // возвращаем искомый элемент
    }

    void printQueue() { // вывод всех элементов очереди
        if (is_empty()) { // проверка на пустоту
            cout << "Очередь пуста.\n";
            return;
        }
        qNode* newNode = front; // начинаем с первого узла - головы
        while (newNode) { // пока указатель не равен nullptr
            cout << newNode->item << " "; // выводим значения
            newNode = newNode->next; // перемещаемся по узлам
        }
        cout << endl;
    }

    void loadFromFile(const string& file) { // загрузка данных из файла
        while (front) { // очищаем текущий лист
            pop();
        }
        ifstream load(file);
        if (!load) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        string str;
        while (getline(load, str)) {
            push(str); // добавляем элементы
        }
        load.close();
    }

    void saveToFile(const string& file) { // сохранение в файл
        ofstream save(file);
        if (!save) {
            cout << "Не удалось открыть файл.\n";
        }
        qNode* newNode = front; // начинаем с головы
        while (newNode) {
            save << newNode->item << endl; // записываем данные в файл
            newNode = newNode->next;
        }
        save.close();
    }
};