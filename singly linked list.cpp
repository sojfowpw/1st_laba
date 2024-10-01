#include <iostream>
#include <string>

using namespace std;
// односвязный список
struct Node { // узел связного списка
    string item; // значение узла
    Node* next; // указатель на следующий узел

    Node(string _item) : item(_item), next(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct List {
    Node* first; // указатель на 1 узел
    Node* last; // указатель на последний узел
    List() : first(nullptr), last(nullptr) {} // конструктор для создания пустого списка

    bool is_empty() { // проверка, пустой ли список
        return first == nullptr; // если 1 узел пустой - список пустой
    }

    void addToEnd(string _item) { // добавление нового узла в конец списка
        Node* newNode = new Node(_item); // создаём новый узел с заданным значением
        if (is_empty()) { // если список пустой
            first = newNode; // новый узел становится первым
            last = newNode; // и последним
            return;
        } // если список не пустой:
        last->next = newNode; // новый узел добавляется в конец
        last = newNode; // и становится последним (указатель на новый узел)
    }

    void addToHead(string _item) { // добавление нового узла в начало списка
        Node* newNode = new Node(_item); // создаём новый узел с заданным значением
        if (is_empty()) { // если список пустой
            first = newNode; //новый узел становится первым
            last = newNode; // и последним
            return;
        }
        newNode->next = first; // новый узел привязывается к старому первому элементу
        first = newNode; // новый узел становится первым
    }

    void delFromEnd() { // удаление с конца
        if (is_empty()) { // если список пуст
            cout << "Список пуст.\n";
            return;
        }
        if (first == last) { // если список содержит 1 элемент, указатель на первый элемент совпадает с указателем на последний
            delFromHead(); // удаление из начала
            return;
        }
        Node* newNode = first; // создаём указатель на первый узел
        while (newNode->next != last) { // ищем предпоследний узел
            newNode = newNode->next; // проходимся по узлам начало->конец
        }
        newNode->next = nullptr; // предпоследний указатель теперь указывает на nullptr
        delete last; // удаляем последний узел
        last = newNode; // предпоследний узел становится последним
    }

    void delFromHead() { // удаление первого узла
        if (is_empty()) { // проверка на пустоту 
            cout << "Список пуст.\n";
            return;
        }
        Node* newNode = first; // новый узел становится первым
        first = newNode->next; // голова теперь указывает на второй узел
        delete newNode; // удаляем старый первый узел
    }

    void delItem(string _item) { // удаление узла по значению
        if (is_empty()) { // если список пустой
            cout << "Список пуст.\n";
            return;
        }
        if (first->item == _item) { // если искомое значение первое
            delFromHead(); // удаляем первый узел
            return;
        }
        if (last->item == _item) { // если искомое значение последнее
            delFromEnd(); // удаляем последний узел
            return;
        }
        Node* newFirst = first; // создаём указатель на первый узел
        Node* newLast = first->next; // создаём указатель на второй узел
        while (newLast && newLast->item != _item) { // пока второй указатель не указывает на nullptr или не равен искомому значению
            newLast = newLast->next; // проходимся по узлам
            newFirst = newFirst->next; // проходимся по узлам
        }
        if (!newLast) { // если элемент не найден и указатель указывает на nullptr
            cout << "Такого элемента нет в списке.\n";
            return;
        }
        newFirst->next = newLast->next; // предыдущий узел теперь указывает на узел на следующий элемент, после удаляемого
        delete newLast; // удаляем искомый элемент
    }

    int findItem(string _item) { // поиск элемента по значению
        if (is_empty()) { // если список пуст
            cout << "Список пуст.\n";
            return -1;
        }
        Node* newNode = first; // новый указатель на первый узел
        int index = 0; // текущий индекс
        while (newNode && newNode->item != _item) { // пока указатель не nullptr или пока не равен искомому значению
            newNode = newNode->next; // проходимся по узлам
            index++; // увеличиваем текущий индекс
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в списке.\n";
            return -1;
        }
        return index; // возвращаем индекс
    }

    string findIndex(int index) { // поиск элемента по индексу
        if (is_empty()) { // если список пуст
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
        return newNode->item; // возвращаем искомый элемент
    }

    void printList() { // вывод всех элементов списка
        if(is_empty()) { // если список пуст
            cout << "Список пуст.\n";
            return;
        }
        Node* newNode = first; // начинаем с первого узла
        while (newNode) { // пока указатель не равен nullptr
            cout << newNode->item << " "; // выводим значения
            newNode = newNode->next; // переходим к следующему узлу
        }
        cout << endl;
    }
};

int main() {
    List newList; // создаём пустой односвязный список
    newList.addToHead("hello");
    newList.addToEnd("hi?");
    newList.addToHead("bye bye");
    cout << "Индекс: " << newList.findItem("bye bye") << endl;
    newList.printList();
    cout << "Значение: " << newList.findIndex(1) << endl;
    return 0;
}