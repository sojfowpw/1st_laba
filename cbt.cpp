#include <iostream>
#include <string>
#include <fstream>

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
        qTree Q; // очередь для дерева
        Q.enqueue(root); // добавляем в очередь корень, начинаем обход с него
        while (!Q.is_empty()) { 
            tNode* current = Q.dequeue(); // вытаскиваем значение из очереди
            if (current->left == nullptr) { // если левый узел пуст - записываем туда новое значение
                current->left = newNode;
                return;
            }
            else { // иначе отправляем его в очередь
                Q.enqueue(current->left);
            }
            if (current->right == nullptr) { // если правый узел пуст - записываем туда новое значение
                current->right = newNode;
                return;
            }
            else { // иначе отправляем его в очередь
                Q.enqueue(current->right);
            }
        }
    }

    void printCBT(tNode* current, int level) { // вывод дерева
        if (current) { // пока текущий указатель не указывает на nullptr
            printCBT(current->right, level + 1); // начинаем с правого узла
            for (int i = 0; i < level; i++) {
                cout << "   "; // вывод нужного количества табуляции
            }
            cout << current->digit << endl; 
            printCBT(current->left, level + 1); // обработка левых узлов
        }
    }
    
    void printTree() { // функция, вызываемая из main
        if (root == nullptr) {
            cout << "Дерево пустое.\n";
            return;
        }
        printCBT(root, 0);
    }

    bool isCBT() { // проверка на cbt
        if (root == nullptr) { // если дерево пустое
            cout << "Дерево пустое.\n";
            return false;
        }
        qTree Q; // очередь
        Q.enqueue(root); // начинаем обход с корня
        bool nonFullNode = false; // флаг - узел, у которого отсутствует хотя бы один потомок
        while (!Q.is_empty()) {
            tNode* current = Q.dequeue(); // указатель на текущее значение
            if (current->left) { // проверка левого потомка
                if (nonFullNode) { // если уже был найдет узел без потомка до этого - дерево не полное
                    return false;
                }
                Q.enqueue(current->left);
            }
            else {
                nonFullNode = true;
            }
            if (current->right) { // проверка правого потомка
                if (nonFullNode) { // если уже был найдет узел без потомка до этого - дерево не полное
                    return false;
                }
                Q.enqueue(current->right);
            }
            else {
                nonFullNode = true;
            }
        }
        return true;
    }

    bool findValue(tNode* current, int val) { // поиск элемента по значению
        if (current == nullptr) { // если узлы кончились и элемент не найден
            return false;
        }
        if (current->digit == val) { // если элемент найден
            return true;
        }
        return findValue(current->left, val) || findValue(current->right, val); // рекурсия
    }

    bool findVal(int val) { // функция для вызова из main
        if (root == nullptr) { // если дерево пустое
            cout << "Дерево пустое.\n";
            return false;
        }
        return findValue(root, val);
    }

    void findIndex(int index) { // чтение (поиск по индексу)
        if (index < 0) { // проверка на корректный индекс
            cout << "Некорректный индекс.\n";
            return;
        }
        if (root == nullptr) { // проверка на пустоту
            cout << "Дерево пустое.\n";
            return;
        }
        qTree Q; // очередь
        Q.enqueue(root); // начинаем обход с корня
        int currentIndex = 0; // текущий индекс
        while (!Q.is_empty()) {
            tNode* current = Q.dequeue(); // текущий узел
            if (currentIndex == index) { // индекс найден
                cout << "Элемент по индексу: " << current->digit << endl;
                return;
            }
            currentIndex++; // увеличиваем текущий индекс
            if (current->left) { // левый потомок
                Q.enqueue(current->left);
            }
            if (current->right) { // правый потомок
                Q.enqueue(current->right);
            }
        }
        cout << "Элемент не найден.\n";
    }

    void loadFromFile(const string& file) { // загрузка данных из файла
        clear(root);
        ifstream load(file);
        if (!load) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        int value;
        while (load >> value) {
            insert(value); // добавляем элементы
        }
        load.close();
    }

    void saveToFile(const string& file) { // сохранение в файл
        ofstream save(file);
        if (!save) {
            cout << "Не удалось открыть файл.\n";
            return;
        }
        qTree Q; // очередь
        Q.enqueue(root); // начинаем обход с корня
        while (!Q.is_empty()) {
            tNode* current = Q.dequeue(); // текущий узел
            save << current->digit << endl; 
            if (current->left) { // левый потомок
                Q.enqueue(current->left);
            }
            if (current->right) { // правый потомок
                Q.enqueue(current->right);
            }
        }
        save.close();
    }

    void clear(tNode*& node) { // рекурсивное удаление всех узлов
        if (node) {
            clear(node->left);
            clear(node->right);
            delete node;
            node = nullptr;
        }
    }
};

int main() {
    CBT tree;
    tree.insert(1);
    tree.insert(4);
    tree.insert(6);
    tree.insert(5);
    tree.insert(9);
    tree.printTree();
    tree.saveToFile("cbt.txt");
}