#include <iostream>
using namespace std;

class LinearProbingHash {
private:
    int* table;
    int size;

    // Hash function with negative key adjustment
    int hashFunction(int key) {
        int index = key % size;
        if (index < 0)
            index += size; // map negative keys to valid index
        return index;
    }

public:
    LinearProbingHash(int s) {
        size = s;
        table = new int[size];
        for (int i = 0; i < size; i++)
            table[i] = -1; // -1 indicates empty
    }

    // Insert with linear probing and duplicate check
    void insertItem(int key) {
        int index = hashFunction(key);
        int startIndex = index;

        while (table[index] != -1) {
            if (table[index] == key) {
                cout << "⚠️ Duplicate " << key << " not inserted." << endl;
                return; // stop insertion for duplicate
            }
            index = (index + 1) % size;
            if (index == startIndex) {
                cout << "❌ Table is full!" << endl;
                return;
            }
        }

        table[index] = key;
        cout << "✅ Inserted " << key << " at index " << index << endl;
    }

    // Display table
    void display() {
        cout << "\n📋 Hash Table Contents:\n";
        for (int i = 0; i < size; i++)
            cout << i << " --> "
                 << (table[i] == -1 ? "Empty" : to_string(table[i])) << endl;
    }
};

int main() {
    LinearProbingHash hp(7);

    // Insert positive and negative keys
    hp.insertItem(50);
    hp.insertItem(700);
    hp.insertItem(76);
    hp.insertItem(85);
    hp.insertItem(92);
    hp.insertItem(73);
    hp.insertItem(101);
    hp.insertItem(-3);    // negative key
    hp.insertItem(85);    // duplicate

    cout << "\nHash Table using Linear Probing (Adjusted):\n";
    hp.display();
}
