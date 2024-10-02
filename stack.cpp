#include <iostream>
#include <string>

using namespace std;
// стэк
struct Node { // узел связного списка
    string item; // значение узла
    Node* next; // указатель на следующий узел

    Node(string _item) : item(_item), next(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct Stack {
    Node* first; // указатель на 1 узел
    Node* last; // указатель на последний узел
    Stack() : first(nullptr), last(nullptr) {} // конструктор для создания пустого списка

    bool is_empty() { // проверка на пустоту
        return first == nullptr; // если первый указатель указывает на nullptr, список пуст
    }

    void push(string _item) { // добавление элемента в начало
        Node* newNode = new Node(_item); // создаём новый узел с заданным значением
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
        Node* newNode = first; // новый узел становится первым
        first = newNode->next; // голова теперь указывает на второй узел
        delete newNode; // удаляем старый первый узел
    }

    string findIndex(int index) { // поиск элемента по индексу
        if (is_empty()) { // проверка на пустоту
            cout << "Стэк пуст.\n";
            return "";
        }
        Node* newNode = first; // новый указатель на голову
        for (int i = 0; i < index && newNode; i++) { // проходимя по списку, пока текущий индекс не будет равен заданному
            newNode = newNode->next;
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в стэке.\n";
            return "";
        }
        return newNode->item; // возвращаем искомый элемент
    }

    void printStack() { // вывод всех элементов стэка (голова слева)
        if (is_empty()) { // проверка на пустоту
            cout << "Стэк пуст.\n";
            return;
        }
        Node* newNode = first; // начинаем с первого узла
        while (newNode) { // пока указатель не указывает на nullptr
            cout << newNode->item << " "; // выводим значения стэка
            newNode = newNode->next; // проходимся по узлам
        }
        cout << endl;
    }
};

int main() {
    Stack s; // создаём пустой стэк
    s.push("hello");
    s.push("???");
    s.push("goodbye");
    s.printStack();
    s.pop();
    s.printStack();
    cout << "Элемент: " << s.findIndex(1) << endl;
    return 0;
}