#include <iostream>
using namespace std;

class QuadraticProbingHash {
private:
    int* table;
    int size;

    int hashFunction(int key) {
        return key % size;
    }

public:
    QuadraticProbingHash(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1;
    }

    void insertItem(int key) {
        int index = hashFunction(key);
        int i = 0;
        while (table[(index + i * i) % size] != -1)
            i++;
        table[(index + i * i) % size] = key;
    }

    void display() {
        for (int i = 0; i < size; i++)
            cout << i << " --> " << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
    }
};

int main() {
    QuadraticProbingHash h(7);
    h.insertItem(50);
    h.insertItem(700);
    h.insertItem(76);
    h.insertItem(85);
    h.insertItem(92);
    h.insertItem(73);
    h.insertItem(101);

    cout << "Hash Table using Quadratic Probing:\n";
    h.display();
}
