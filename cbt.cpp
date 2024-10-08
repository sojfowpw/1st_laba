#include <iostream>

using namespace std;

// complete binary tree
struct tNode { 
    int digit; // значение
    tNode* left; // указатель на левый узел
    tNode* right; // указатель на правый узел

    tNode(int dig) : digit(dig), left(nullptr), right(nullptr) {} // конструктор для создания нового узла с заданным значением
};

struct queueNode {
    tNode* tree; // указатель на узел дерева
    queueNode* next; // указатель на следующий узел
};

struct qTree { // очередь для дерева
    queueNode* front; // указатель на голову
    queueNode* rear; // указатель на хвост
    int count; // количество узлов в очереди

    qTree() : front(nullptr), rear(nullptr), count(0) {} // конструктор для создания очереди

    bool is_empty() {
        return count == 0;
    }

    void enqueue(tNode* node) { // добавление узла в очередь
        queueNode* newNode = new queueNode(); // создаём новый узел
        newNode->tree = node; // устанавливаем указатель на новый узел дерева в новом узле очереди
        newNode->next = nullptr; // следующий узел в новом узле указывает на nullptr
        if (rear == nullptr) { // если очередь пуста
            front = rear = newNode; // новый узел становится и началом, и концом
        }
        else {
            rear->next = newNode; // иначе новый узел добавляется в конец
            rear = newNode; // конец = новый узел
        }
        count++; // увеличиваем счетчик
    }

    tNode* dequeue() { // удаление из очереди
        if (is_empty()) { // проверка на пустоту
            return nullptr;
        }
        queueNode* newNode = front; // новый узел указывает на первый
        tNode* res = front->tree; // результат указывает на узел дерева в первом узле очереди
        front = front->next; // фронт теперь указывает на следующий узел
        if (front == nullptr) { // если очередь стала пуста
            rear = nullptr;
        }
        delete newNode; // удаляем новый узел
        count--; // уменьшаем счетчик
        return res;
    }
};

struct CBT {
    tNode* root; // указатель на корень
    CBT() : root(nullptr) {} // конструктор для создания пустого корня

    void insert(int digit) { // добавление нового узла
        tNode* newNode = new tNode(digit); // указатель на новый узел с заданным значением
        if (root == nullptr) { // если дерево пустое, новый узел становится корнем
            root = newNode;
            return;
        }
        qTree Q;
        Q.enqueue(root);
        
    }
};