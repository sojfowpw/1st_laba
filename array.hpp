#pragma once
#include <iostream>
#include <string>
#include <fstream>

using namespace std;
// массив
struct Array { // динамический массив строк
    string* arr; // указатель на массив
    size_t size; // текущий размер
    size_t capacity; // максимальный размер

    Array(size_t cap = 15) : size(0), capacity(cap) { // конструктор для создания
        arr = new string[capacity]; // выделение памяти
    }

    ~Array() {
        delete[] arr; // освобождение памяти
    }

    void resize() { // расширение
        capacity *= 2; // увеличиваем максимальный размер в 2 раза
        string* newArr = new string[capacity]; // выделяем память для нового массива
        for (size_t i = 0; i < size; ++i) {
            newArr[i] = arr[i]; // копируем элементы в новый массив
        }
        delete[] arr; // удаляем старый массив
        arr = newArr;
    }

    void addByInd(const string& item, size_t index) { // добавление элемента по индексу
        if (index >= size) { // проверка на недопустимый индекс
            cout << "Недопустимый индекс.\n";
            return;
        }
        if (size >= capacity) { // если текущий размер больше максимального, увеличиваем размер массива
            resize();
        }
        for (size_t i = size; i > index; --i) { // сдвигаем элементы с конца вправо
            arr[i] = arr[i - 1];
        }
        arr[index] = item; // вставляем новый элемент
        ++size; // увеличиваем текущий размер
    }

    void addToEnd(const string& item) { // добавление элемента в конец
        if (size >= capacity) { // если текущий размер больше максимального, увеличиваем размер массива
            resize();
        }
        arr[size++] = item; // добавляем элемент в конец
    }

    void findByIndex(size_t index) { // получение элемента по индексу
        if (size == 0) { // проверка на пустоту
            cout << "Массив пуст.\n";
            return;
        }
        if (index >= size) { // проверка на недопустимый индекс
            cout << "Недопустимый индекс.\n";
            return;
        }
        cout << "Элемент по индексу: " << arr[index] << endl;
    }

    void delByIndex(size_t index) { // удаление элемента по индексу
        if (size == 0) { // проверка на пустоту
            cout << "Массив пуст.\n";
            return;
        }
        if (index >= size) { // проверка на недопустимый индекс
            cout << "Недопустимый индекс.\n";
            return;
        }
        for (size_t i = index; i < size - 1; ++i) { // сдвигаем элементы влево на один
            arr[i] = arr[i + 1];
        }
        --size; // уменьшаем текущий размер
    }

    void replace(size_t index, const string& item) { // замена элемента по индексу
        if (size == 0) { // проверка на пустоту
            cout << "Массив пуст.\n";
            return;
        }
        if (index >= size) { // проверка на недопустимый индекс
            cout << "Недопустимый индекс.\n";
            return;
        }
        arr[index] = item; // замена
    }

    void length() { // длина массива
        cout << "Длина массива: " << size << endl;
    }

    void findByItem(const string& item) { // чтение (поиск элемента по значению)
        if (size == 0) { // проверка на пустоту
            cout << "Массив пуст.\n";
            return;
        }
        for (size_t i = 0; i < size; i++) { // проходимся по массиву
            if (arr[i] == item) {
                cout << "Индекс элемента: " << i << endl;
                return;
            }
        }
        cout << "Элемент не найден.\n";
    }

    void printArray() { // вывод элементов массива
        if (size == 0) { // проверка на пустоту
            cout << "Массив пуст.\n";
            return;
        }
        for (size_t i = 0; i < size; i++) { // проходимся по элементам массива
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    void loadFromFile(const string& file) { // загрузка данных из файла
        size = 0; // очищаем массив
        ifstream load(file);
        if (!load.is_open()) { // проверка
            cout << "Не удалось открыть файл.\n";
            return;
        }
        string str; // текущая строка данных
        while (getline(load, str)) {
            addToEnd(str); // добавляем в конец массива
        }
        load.close();
    }

    void saveToFile(const string& file) { // загрузка данных в файл
        ofstream save(file);
        if (!save.is_open()) { // проверка
            cout << "Не удалось открыть файл.\n";
            return;
        }
        for (size_t i = 0; i < size; ++i) { // запись в файл
            save << arr[i] << endl;
        }
        save.close();
        const_cast<Array*>(this)->size = 0; // очистка массива
    }
};