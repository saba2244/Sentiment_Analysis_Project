#include <iostream>
#include <string>
#include <fstream>

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

void HashTable::printResult(int score, int viable)
{
  cout << "Overall Score: " << score << endl;
  cout << "Analysis:" << endl;
  int bucket = floor(score/10);
  string result;
  string note = "";

  switch (bucket) {
    case 0:
      result = "As a whole this text file is excessively negative in tone. The entire text is almost devoid of any positivity.";
      break;
    case 1:
      result = "As a whole the tone of the text is extremely negative. Any positivity is constrained to sparse sentences or paragraphs, depending upon the length of the text.";
      break;
    case 2:
      result = "Overall the text contains a very negative tone. Certain paragraphs, chapters, or sections may express positivity";
      break;
    case 3:
      result = "Overall the text is moderately negative in tone. Positive expression is more difficult to find but still present.";
      break;
    case 4:
      result = "The text as a whole is relatively neutral in tone. While negative aspects are slightly more prevalent, both moods are noticable.";
      break;
    case 5:
      result = "The text as a whole is relatively neutral in tone. While positive aspects are slightly more prevalent, both moods are noticable.";
      break;
    case 6:
      result = "Overall the text is moderately positive in tone. Negative expression is more difficult to find but still present.";
      break;
    case 7:
      result = "Overall the tone of this text is very positive. Certain paragraphs, chapters, or sections may contain negative expressions.";
      break;
    case 8:
      result = "As a whole the tone of the text is extremely positive. Any negativity is constrained to sparse sentences or paragraphs, depending upon the length of the text.";
      break;
    case 9:
      result = "As a whole this text file is excessively positive in tone. The entire text is almost devoid of any positivity.";
      break;
  }

  if(viable < 40)
    note = "Please note that the text was not long enough for the conclusions above to be considered accurate and they should be treated as such. For greater accuracy try a longer text file.";

  ofstream myfile;
  myfile.open("output.txt");
  myfile << "Overall Score: " << score<< endl;
  myfile << "Analysis: " << endl;
  myfile <<result<<endl << endl << note;
  myfile.close();


}
