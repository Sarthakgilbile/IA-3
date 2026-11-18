#include <iostream>
using namespace std;

// Division Method Hash Function
int hashFunction(int key) {
    return key % 23;
}

int main() {
    int S = 186;
    int values[20];

    cout << "Data Structures IA-3" << endl;
    cout << "PRN: 202501100186" << endl;
    cout << "Personalized Dataset:" << endl;

    for (int i = 0; i < 20; i++) {
        values[i] = (S + 13 * i) % 100;
        cout << values[i] << " ";
    }

// Hash Table Initialization
const int TABLE_SIZE = 23;
int hashTable[TABLE_SIZE];

// Initialize all slots as empty
for (int i = 0; i < TABLE_SIZE; i++) {
    hashTable[i] = -1;
}

cout << "\n\nInitial Hash Table:" << endl;

for (int i = 0; i < TABLE_SIZE; i++) {
    cout << "Index " << i << ": " << hashTable[i] << endl;
}
cout << "\nHash Function Test:" << endl;

for (int i = 0; i < 20; i++) {
    cout << "Key: " << values[i]
         << " -> Hash Index: " << hashFunction(values[i])
         << endl;
}
// Hash Table Insertion Using Linear Probing
cout << "\nHash Table Insertion Using Linear Probing:" << endl;

for (int i = 0; i < 20; i++) {
    int index = hashFunction(values[i]);
    int originalIndex = index;

    // Find the next empty slot if a collision occurs
    while (hashTable[index] != -1) {
        cout << "Collision for " << values[i]
             << " at index " << index << endl;

        index = (index + 1) % TABLE_SIZE;

        if (index == originalIndex) {
            cout << "Hash table is full!" << endl;
            break;
        }
    }

    if (hashTable[index] == -1) {
        hashTable[index] = values[i];

        cout << values[i] << " inserted at index "
             << index << endl;
    }
}
// Final Hash Table Display
cout << "\n===== FINAL HASH TABLE =====" << endl;

int insertedCount = 0;

for (int i = 0; i < TABLE_SIZE; i++) {
    cout << "Index " << i << " : ";

    if (hashTable[i] == -1) {
        cout << "Empty";
    } else {
        cout << hashTable[i];
        insertedCount++;
    }

    cout << endl;
}

// Final Testing
cout << "\n===== TEST RESULTS =====" << endl;
cout << "Total Values: 20" << endl;
cout << "Successfully Inserted: " << insertedCount << endl;
cout << "Empty Slots: " << TABLE_SIZE - insertedCount << endl;
    return 0;
}
