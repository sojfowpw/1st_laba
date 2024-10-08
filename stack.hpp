#pragma once
#include <iostream>
#include <string>

using namespace std;
// стэк
struct sNode { // узел связного списка
    string item; // значение узла
    sNode* next; // указатель на следующий узел

    sNode(string _item) : item(_item), next(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct Stack {
    sNode* first; // указатель на 1 узел
    sNode* last; // указатель на последний узел
    Stack() : first(nullptr), last(nullptr) {} // конструктор для создания пустого списка

    bool is_empty() { // проверка на пустоту
        return first == nullptr; // если первый указатель указывает на nullptr, список пуст
    }

    void push(string _item) { // добавление элемента в начало
        sNode* newNode = new sNode(_item); // создаём новый узел с заданным значением
        if (is_empty()) { // если список пустой
            first = newNode; // новый узел становится первым
            last = newNode; // и последним
            return;
        }
        newNode->next = first; // иначе новый узел привязывается к старому первому элементу
        first = newNode; // новый узел становится первым
    }

    void pop() { // удаление узла с головы
        if (is_empty()) { // если стэк пуст
            cout << "Стэк пуст.\n";
            return;
        }
        sNode* newNode = first; // новый узел становится первым
        first = newNode->next; // голова теперь указывает на второй узел
        delete newNode; // удаляем старый первый узел
    }

    void findIndex(int index) { // поиск элемента по индексу
        if (is_empty()) { // проверка на пустоту
            cout << "Стэк пуст.\n";
            return;
        }
        sNode* newNode = first; // новый указатель на голову
        for (int i = 0; i < index && newNode; i++) { // проходимя по списку, пока текущий индекс не будет равен заданному
            newNode = newNode->next;
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в стэке.\n";
            return;
        }
        cout << "Элемент по индексу: " << newNode->item << endl; // возвращаем искомый элемент
    }

    void printStack() { // вывод всех элементов стэка (голова слева)
        if (is_empty()) { // проверка на пустоту
            cout << "Стэк пуст.\n";
            return;
        }
        sNode* newNode = first; // начинаем с первого узла
        while (newNode) { // пока указатель не указывает на nullptr
            cout << newNode->item << " "; // выводим значения стэка
            newNode = newNode->next; // проходимся по узлам
        }
        cout << endl;
    }
};