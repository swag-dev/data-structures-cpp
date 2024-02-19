#include <iostream>
using std::cout, std::endl;

class Node
{
public:
  int value;
  Node* next;
  Node* prev;
  Node(int value)
  {
    this->value = value;
    next = nullptr;
    prev = nullptr;
  }
};
class DoublyLinkedList
{
private:
  Node* head;
  Node* tail;
  int length;
public:
  DoublyLinkedList(){
    head = nullptr;
    tail = nullptr;
    length = 0;
  }
  DoublyLinkedList(int value)
  {
    Node* newNode = new Node(value);
    head = newNode;
    tail = newNode;
    length = 1;
  }
  void printList()
  {
    Node* temp = head;
    while(temp)
    {
      cout << temp->value << endl;
      temp = temp->next;
    }
  }
  Node* getHead()
  {
    return head;
  }
  Node* getTail()
  {
    return tail;
  }
  int getLength()
  {
    return length;
  }
  void append(int value)
  {
    Node* newNode = new Node(value);
    if(length > 0)
    {
      tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;
    }
    else
    {
      head = newNode;
      tail = newNode;
    }
    length++;
  }
  void prepend(int value)
  {
    Node* newNode = new Node(value);
    if(length == 0)
    {
      head = newNode;
      tail = newNode;
    }
    else
    {
      newNode->next = head;
      head->prev = newNode;
      head = newNode;
    }
    length++;
  }
  void deleteLast()
  {
    if(length == 0) return;
    Node* temp = tail;
    if(length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      tail = tail->prev;
      tail->next = nullptr;
    }
    temp = nullptr;
    delete temp;
    length--;
  }
  void deleteFirst()
  {
    if(length == 0) return;
    Node* temp = head;
    if(length == 1)
    {
      head = nullptr;
      tail = nullptr;
    }
    else
    {
      head = head->next;
      head->prev = nullptr;
    }
    temp = nullptr;
    delete temp;
    length--;
  }
  Node* get(int index)
  {
    if(index < 0 || index >= length) return nullptr;
    Node* temp;
    if(index < length/2)
    {
      temp = head;
      for(int i = 0; i < index; ++i)
      {
        temp = temp->next;
      }
    }
    else
    {
      temp = tail;
      for(int i = length - 1; i > index; --i)
      {
        temp = temp->prev;
      }
    }
    return temp;
  }
  bool set(int index, int value)
  {
    Node* temp = get(index);
    if(temp)
    {
      temp->value = value;
      return true;
    }
    return false;
  }
  bool insert(int index, int value)
  {
    if(index < 0 || index > length) return false;
    if(index == 0)
    {
      prepend(value);
      return true;
    }
    if(index == length)
    {
      append(value);
      return true;
    }
      Node* newNode = new Node(value);
      Node* temp;
      temp = get(index - 1);
      newNode->next = temp->next;
      temp->next->prev = newNode;
      newNode->prev = temp;
      temp->next = newNode;
      length++;
      return true;
  }
  void deleteNode(int index)
  {
    if(index < 0 || index >= length) return;
    if(index == 0)
    {
      deleteFirst();
      return;
    }
    if(index == length - 1){
      deleteLast();
      return;
    }
    Node* temp = get(index - 1);
    temp->next->next->prev = temp;
    temp->next = temp->next->next;
    temp = nullptr;
    delete temp;
    length--;

  }
};
