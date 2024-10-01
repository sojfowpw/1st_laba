#include <iostream>
#include <string>

using namespace std;
// очередь
struct Node { // узел связного списка
    string item; // значение узла
    Node* next; // указатель на следующий узел

    Node(string _item) : item(_item), next(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct Queue {
    Node* front; // указатель на 1 узел
    Node* rear; // указатель на последний узел
    Queue() : front(nullptr), rear(nullptr) {} // конструктор для создания пустого списка

    bool is_empty() { // проверка, пустой ли список
        return front == nullptr; // если 1 узел пустой, то список пустой
    }

    void push(string _item) { // добавление элементов в хвост
        Node* newNode = new Node(_item); // создаём новый узел с заданным значением
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
        Node* newNode = front; // новый узел становится первым
        front = newNode->next; // голова теперь указывает на второй узел
        delete newNode; // первый узел - новый удаляется
    }

    string findIndex(int index) { // поиск элемента по индексу
        if (is_empty()) { // проверка на пустоту
            cout << "Очередь пуста.\n";
            return "";
        }
        Node* newNode = front; // новый указатель на голову
        for (int i = 0; i < index && newNode; i++) { // проходимся по списку, пока текущий индекс не будет равен заданному
            newNode = newNode->next;
        }
        if (!newNode) { // если элемент не найден
            cout << "Такого элемента нет в очереди.\n";
            return "";
        }
        return newNode->item; // возвращаем искомый элемент
    }

    void printQueue() { // вывод всех элементов очереди
        if (is_empty()) { // проверка на пустоту
            cout << "Очередь пуста.\n";
            return;
        }
        Node* newNode = front; // начинаем с первого узла - головы
        while (newNode) { // пока указатель не равен nullptr
            cout << newNode->item << " "; // выводим значения
            newNode = newNode->next; // перемещаемся по узлам
        }
        cout << endl;
    }
};

int main() {
    Queue q;
    q.push("aaa");
    q.push("bbb");
    q.push("ccc");
    q.push("sdfgh");
    q.pop();
    q.pop();
    q.printQueue();
    cout << "Элемент: " << q.findIndex(1) << endl;
    return 0;
}