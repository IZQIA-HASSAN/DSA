#include <iostream>
using namespace std;

// ===============================
// 🌟 Node structure for Linked List
// ===============================
struct Node {
    int data;       // stores the key
    Node* next;     // pointer to next node in the chain

    // Constructor
    Node(int val) {
        data = val;
        next = NULL;
    }
};

// ===============================
// 🌟 Hash Table Class (Chaining)
// ===============================
class HashTable {
private:
    static const int TABLE_SIZE = 10; // fixed size for simplicity
    Node* table[TABLE_SIZE];          // array of pointers to linked lists

    // Hash function (simple modulus)
    int hash(int key) {
        // Handle negative numbers safely
        int index = key % TABLE_SIZE;
        if (index < 0)
            index += TABLE_SIZE;
        return index;
    }

public:
    // ===============================
    // 🌟 Constructor — initialize all heads as NULL
    // ===============================
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; i++) {
            table[i] = NULL;
        }
    }

    // ===============================
    // 🌟 Insert Function (with duplicate check)
    // ===============================
    void insert(int key) {
        int index = hash(key);
        Node* current = table[index];

        // 🔍 Step 1: Check for duplicate
        while (current != NULL) {
            if (current->data == key) {
                cout << "⚠️ Duplicate " << key << " found at index " << index
                     << ". Insertion skipped.\n";
                return; // stop insertion
            }
            current = current->next;
        }

        // ✅ Step 2: Insert at beginning of chain
        Node* newNode = new Node(key);
        newNode->next = table[index]; // existing chain linked after new node
        table[index] = newNode;       // new node becomes head
        cout << "✅ Inserted " << key << " at index " << index << endl;
    }

    // ===============================
    // 🌟 Delete Function (deletes all occurrences)
    // ===============================
    void deleteKey(int key) {
        int index = hash(key);
        Node* current = table[index];
        Node* prev = NULL;
        bool deleted = false;

        while (current != NULL) {
            if (current->data == key) {
                deleted = true;
                if (prev == NULL) {
                    table[index] = current->next;
                    delete current;
                    current = table[index];
                } else {
                    prev->next = current->next;
                    delete current;
                    current = prev->next;
                }
            } else {
                prev = current;
                current = current->next;
            }
        }

        if (deleted)
            cout << "🗑️ Deleted all occurrences of " << key << " from index " << index << endl;
        else
            cout << "❌ Key " << key << " not found in index " << index << endl;
    }

    // ===============================
    // 🌟 Display Function (shows full hash table)
    // ===============================
    void display() {
        cout << "\n==============================" << endl;
        cout << "📋 Hash Table Contents" << endl;
        cout << "==============================" << endl;
        for (int i = 0; i < TABLE_SIZE; i++) {
            cout << "Index " << i << ": ";
            Node* current = table[i];
            if (!current) {
                cout << "NULL";
            } else {
                while (current != NULL) {
                    cout << current->data << " -> ";
                    current = current->next;
                }
                cout << "NULL";
            }
            cout << endl;
        }
        cout << "==============================\n";
    }
};

// ===============================
// 🌟 Main Function — Test Cases
// ===============================
int main() {
    HashTable ht;

    // Insertion tests (with duplicates and negatives)
    ht.insert(-10);
    ht.insert(-20);
    ht.insert(-30);
    ht.insert(-10);  // duplicate (should be skipped)
    ht.insert(23);
    ht.insert(33);
    ht.insert(23);   // duplicate (should be skipped)
    ht.insert(44);
    ht.insert(54);

    // Display after insertion
    ht.display();

    // Delete some keys
    ht.deleteKey(-20); // existing
    ht.deleteKey(23);  // existing
    ht.deleteKey(100); // not found

    // Display after deletion
    ht.display();

    return 0;
}
