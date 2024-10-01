#include <iostream>
#include <string>

using namespace std;
// двусвязный список
struct Node {
    string item; // значение узла
    Node* next; // указатель на следующий узел
    Node* prev; // указатель на предыдущий узел

    Node(string _item) : item(_item), next(nullptr), prev(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct List {
    Node* first; // указатель на первый узел
    Node* last; // указатель на последний узел
    List() : first(nullptr), last(nullptr) {} // конструктор для создания пустого списка

    bool is_empty() { // проверка, пустой ли список
        return first == nullptr; // если 1 узел пустой - список пустой
    }

    void addToEnd(string _item) { // добавление узла в конец списка
        Node* newNode = new Node(_item); // создаём новый узел с заданным значением
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
        Node* newNode = new Node(_item); // создаём новый узел с заданным значением
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
        Node* newNode = first; // новый указатель указывает на первый узел
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
        Node* newNode = last; // новый указатель на последний узел
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
        Node* newNode = first; // указатель на первый узел
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
        Node* newFirst = first; // создаём указатель на первый узел
        Node* newLast = first->next; // создаём указатель на второй узел
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

    int findItem(string _item) { // поиск элемента по значению
        if (is_empty()) { // если список пустой
            cout << "Список пуст.\n";
            return -1;
        }
        Node* newNode = first; // новый указатель на первый узел
        int index = 0; // текущий индекс
        while (newNode && newNode->item != _item) { // пока указатель не указывает на nullptr и пока не найдено искомое значение
            newNode = newNode->next; // проходимся по узлам
            index++; // увеличиваем текущий индекс
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в списке.\n";
            return -1;
        }
        return index; // возвращаем индекс
    }

    string findIndex(int index) { // поиск по индексу
        if (is_empty()) { // проверка на пустоту
            cout << "Список пуст.\n";
            return "";
        }
        Node* newNode = first; // новый указатель на первый узел
        for (int i = 0; i < index && newNode; i++) { // проходимся по списку, пока текущий индекс не будет равен заданному
            newNode = newNode->next; 
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в списке.\n";
            return "";
        }
        string _item = newNode->item; // переменная для искомого значения
        delete newNode; // освобождение памяти
        return _item; // возвращаем элемент
    }
};

int main() {
    List newList;
    newList.addToEnd("hello");
    newList.addToHead("hi");
    cout << "Индекс: " << newList.findItem("hello") << endl;
    newList.printList();
    cout << "Значение: " << newList.findIndex(1) << endl;
}