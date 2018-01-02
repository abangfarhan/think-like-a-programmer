#include <iostream>
#include "01-student-record-class.h"

// see http://www.algolist.net/Data_structures/Hash_table/Simple_example
class HashEntry {
  private:
    int _key;
    studentRecord _data;
  public:
    HashEntry(int newKey, studentRecord newData) {
        _key = newKey;
        _data = newData;
    }
    int key() {
        return _key;
    }
    studentRecord data() {
        return _data;
    }
};

const int TABLE_SIZE = 128;
class HashMap {
  private:
    HashEntry **table;
  public:
    HashMap() {
        table = new HashEntry*[TABLE_SIZE];
        for (int i = 0; i < TABLE_SIZE; i++)
            table[i] = NULL;
    }
    studentRecord get(int key) {
        int hash = (key % TABLE_SIZE);
        // conflict resolution below. see link provided on the beginning
        while (table[hash] != NULL && table[hash]->key() != key)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] == NULL) {
            studentRecord dummyRecord;
            return dummyRecord;
        } else {
            return table[hash]->data();
        }
    }
    void put(int newKey, studentRecord newData) {
        int hash = (newKey % TABLE_SIZE);
        // conflict resolution below. see link provided on the beginning
        while (table[hash] != NULL && table[hash]->key() != newKey)
            hash = (hash + 1) % TABLE_SIZE;
        if (table[hash] != NULL)
            delete table[hash];
        table[hash] = new HashEntry(newKey, newData);

    }
    ~HashMap() {
        for (int i = 0; i < TABLE_SIZE; i++)
            if (table[i] != NULL)
                delete table[i];
        delete[] table;
    }
};

int main() {
    HashMap records;
    records.put(1003, studentRecord(95, 1003, "Mike"));
    records.put(1001, studentRecord(91, 1001, "Abdul"));
    records.put(1002, studentRecord(95, 1002, "Steve"));

    records.get(1003).showStudentProperties();
    records.get(1001).showStudentProperties();
    records.get(1002).showStudentProperties();
}
