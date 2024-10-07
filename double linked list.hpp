#pragma once
#include <iostream>
#include <string>

using namespace std;
// двусвязный список
struct dlNode {
    string item; // значение узла
    dlNode* next; // указатель на следующий узел
    dlNode* prev; // указатель на предыдущий узел

    dlNode(string _item) : item(_item), next(nullptr), prev(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct doubleList {
    dlNode* first; // указатель на первый узел
    dlNode* last; // указатель на последний узел
    doubleList() : first(nullptr), last(nullptr) {} // конструктор для создания пустого списка

    bool is_empty() { // проверка, пустой ли список
        return first == nullptr; // если 1 узел пустой - список пустой
    }

    void addToEnd(string _item) { // добавление узла в конец списка
        dlNode* newNode = new dlNode(_item); // создаём новый узел с заданным значением
        if (is_empty()) { // если список пустой
            first = newNode; // новый узел становится первым
            last = newNode; // и последним
            return;
        }
        last->next = newNode; // новый узел добавляется в конец
        newNode->prev = last; // новый узел связывается с предыдущим
        last = newNode; // новый узел становится последним
    }

    void addToHead(string _item) { // добавление узла в начало списка
        dlNode* newNode = new dlNode(_item); // создаём новый узел с заданным значением
        if (is_empty()) { // если список пустой
            first = newNode; // новый узел становится первым
            last = newNode; // и последним
            return;
        }
        newNode->next = first; // связываем новый узел с первым
        first->prev = newNode; // связываем первый узел с новым
        first = newNode; // новый узел становится первым
    }

    void delFromHead() { // удаление первого узла
        if (is_empty()) { // если список пустой
            cout << "Список пуст.\n";
            return;
        }
        dlNode* newNode = first; // новый указатель указывает на первый узел
        first = newNode->next; // первый узел теперь указывает за последующим за новым
        if (first) { // если новый первый узел существует
            first->prev = nullptr; // связываем первый узел с nullptr
        }
        else {
            last = nullptr; // иначе связываем последний узел с nullptr
        }
        delete newNode; // удаляем новый узел
    }

    void delFromEnd() { // удаление последнего узла
        if (is_empty()) { // если список пустой
            cout << "Список пуст.\n";
            return;
        }
        dlNode* newNode = last; // новый указатель на последний узел
        last = newNode->prev; // последний узел теперь связан с предыдущим нового 
        if (last) { // если новый последний узел существует
            last->next = nullptr; // связываем последний узел с nullptr
        }
        else {
            first = nullptr; // иначе связываем первый узел с nullptr
        }
        delete newNode; // удаляем новый узел
    }

    void printList() { // вывод всех элементов списка
        if (is_empty()) { // проверка на пустоту
            cout << "Список пуст.\n";
            return;
        }
        dlNode* newNode = first; // указатель на первый узел
        while (newNode) { // пока новый указатель не указывает на nullptr
            cout << newNode->item << " "; // выводим значения
            newNode = newNode->next; // новый узел указывает на следующий указатель
        }
        cout << endl;
    }

    void delItem(string _item) { // удаление элемента по значению
        if (is_empty()) { // проверка на пустоту
            cout << "Список пуст.\n";
            return;
        }
        if (first->item == _item) { // если первый узел искомый, вызываем функцию удаления из головы
            delFromHead();
            return;
        }
        if (last->item == _item) { // если последний узел искомый, вызываем функцию удаления с хвоста
            delFromEnd();
            return;
        }
        dlNode* newFirst = first; // создаём указатель на первый узел
        dlNode* newLast = first->next; // создаём указатель на второй узел
        while (newLast && newLast->item != _item) { // пока второй указатель не указывает на nullptr и пока не нашлось искомое значение
            newLast = newLast->next; // проходимся по узлам
            newFirst = newFirst->next; // проходимся по узлам
        }
        if (!newLast) { // если искомый элемент не найден
            cout << "Такого элемента нет в списке.\n";
            return;
        }
        newFirst->next = newLast->next; // предыдущий узел теперь указывает на узел на следующий элемент, после удаляемого
        newLast->prev = newFirst->prev; // и наоборот
        delete newLast; // удаляем искомый узел
    }

    void findItem(string _item) { // поиск элемента по значению
        if (is_empty()) { // если список пустой
            cout << "Список пуст.\n";
            return;
        }
        dlNode* newNode = first; // новый указатель на первый узел
        int index = 0; // текущий индекс
        while (newNode && newNode->item != _item) { // пока указатель не указывает на nullptr и пока не найдено искомое значение
            newNode = newNode->next; // проходимся по узлам
            index++; // увеличиваем текущий индекс
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в списке.\n";
            return;
        }
        cout << "Индекс элемента: " << index << endl; // возвращаем индекс
    }

    void findIndex(int index) { // поиск по индексу
        if (is_empty()) { // проверка на пустоту
            cout << "Список пуст.\n";
            return;
        }
        dlNode* newNode = first; // новый указатель на первый узел
        for (int i = 0; i < index && newNode; i++) { // проходимся по списку, пока текущий индекс не будет равен заданному
            newNode = newNode->next; 
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в списке.\n";
            return;
        }
        string _item = newNode->item; // переменная для искомого значения
        delete newNode; // освобождение памяти
        cout << "Элемент по индексу: " << _item << endl; // возвращаем элемент
    }

    void loadFromFile(const string& file) { // загрузка данных из файла
        while (first) { // очищаем текущий лист
            delFromHead();
        }
        ifstream load(file);
        if (!load) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        string str;
        while (getline(load, str)) {
            addToEnd(str); // добавляем элементы
        }
        load.close();
    }

    void saveToFile(const string& file) { // сохранение в файл
        ofstream save(file);
        if (!save) {
            cout << "Не удалось открыть файл.\n";
        }
        dlNode* newNode = first; // начинаем с головы
        while (newNode) {
            save << newNode->item << endl; // записываем данные в файл
            newNode = newNode->next;
        }
        save.close();
    }
};