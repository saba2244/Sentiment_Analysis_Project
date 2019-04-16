#include <iostream>
#include <string>

#include "HashTableFunc.hpp"

using namespace std;

node *HashTable::createNode(string key)
{
    node *nw = new node;
    nw->word = key;
    return nw;
}
HashTable::HashTable(int bsize)
{
    this->tableSize = bsize;
    hashTable = new node *[tableSize];
    for (int i = 0; i < bsize; i++)
        hashTable[i] = nullptr;
}

HashTable::~HashTable()
{
    node *temp;
    node *temp_next;
    for (int i = 0; i < tableSize; i++)
    {
        temp = hashTable[i];
        while (NULL != temp)
        {
            temp_next = temp->next;
            delete temp;
            temp = temp_next;
        }
        hashTable[i] = NULL;
    }
}
bool HashTable::insertPos(string key)
{
    if (searchItem(key) != nullptr)
    {
        return false;
    }
    int index = hashFunction(key);

    node *newNode = new node;
    node *ptr = hashTable[index];
    newNode->word = key;
    newNode->con = 1;
    newNode->next = ptr;
    hashTable[index] = newNode;
    return true;
}
bool HashTable::insertItem(string key)
{
    if (searchItem(key) != nullptr)
    {
        return false;
    }
    int index = hashFunction(key);

    node *newNode = new node;
    node *ptr = hashTable[index];
    newNode->word = key;
    newNode->next = ptr;
    hashTable[index] = newNode;
    return true;
}
bool HashTable::insertNeg(string key)
{
    if (searchItem(key) != nullptr)
    {
        return false;
    }
    int index = hashFunction(key);

    node *newNode = new node;
    node *ptr = hashTable[index];
    newNode->word = key;
    newNode->con = -1;
    newNode->next = ptr;
    hashTable[index] = newNode;
    return true;
}
unsigned int HashTable::hashFunction(string key)
{
    unsigned int hashValue = 5381;
    int length = key.length();
    for (int i = 0; i < length; i++)
    {
        hashValue = ((hashValue << 5) + hashValue) + key[i];
    }
    hashValue %= tableSize;
    return hashValue;
}
void HashTable::printTable()
{
    for (int i = 0; i < tableSize; i++)
    {
        cout << i << "|| ";

        node *temp = hashTable[i];
        if (temp != nullptr)
        {
            while (temp != nullptr)
            {
                cout << temp->word;
                temp = temp->next;
                if (temp != nullptr)
                    cout << "-> ";
            }
        }
        cout << endl;
    }
}

node *HashTable::searchItem(string key)
{
    int index = hashFunction(key);
    if (hashTable[index] == nullptr)
        return nullptr;
    if (hashTable[index]->word == key)
        return hashTable[index];
    else
    {
        node *temp = hashTable[index];
        while (temp != nullptr)
        {
            if (temp->word == key)
            {
                return temp;
            }
            temp = temp->next;
        }
        return nullptr;
    }
}
