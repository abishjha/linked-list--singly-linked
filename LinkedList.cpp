#include<iostream>
#include<string> //just in case the input type is string...not required for other data types
#include<algorithm> //used in random_shuffle function
#include"Node.cpp"

template<class T>
class LinkedList {
private:
     //private variables
     int count;
     Node<T>* head;
     Node<T>* tail;

     //private functions
     void append(Node<T>* n);
     void remove_tail();
     void push(Node<T>* n);
     Node<T>* pop();
     void remove_i(int i);
     Node<T>* get_i(int i);
     void add_i(Node<T>* n, int i);
     void print();
     void deleteList();
     void reverse();
     void rotate(int rotations);
     void random_shuffle();
     int size();
public:
     LinkedList();
     bool isEmpty();
     void perform_operation(int op_code, T value);
};

template<class T>
LinkedList<T>::LinkedList() {
     count = 0;
     head = NULL;
     tail = NULL;
}

template<class T>
void LinkedList<T>::append(Node<T>* n) {
     if (!isEmpty()) {
          Node<T>* temp = head;
          while (temp->getNextNode() != NULL)
               temp = temp->getNextNode();

          temp->setNextNode(n);
          n->setNextNode(NULL);
          tail = n;
     }
     else {
          head = n;
          tail = n;
          n->setNextNode(NULL);
     }
     count++;
}

template<class T>
void LinkedList<T>::remove_tail() {
     if (!isEmpty()) {
          if (count == 1) {
               delete head;
               head = tail = NULL;
          }
          else {
               Node<T>* temp = head;
               while (temp->getNextNode() != tail)
                    temp = temp->getNextNode();

               delete temp->getNextNode();
               temp->setNextNode(NULL);
               tail = temp;
          }
          count--;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::push(Node<T>* n) {
     if (isEmpty()) {
          head = n;
          tail = n;
          tail->setNextNode(NULL);
     }
     else {
          n->setNextNode(head);
          head = n;
     }
     count++;
}

template<class T>
Node<T>* LinkedList<T>::pop() {
     Node<T>* returnVal = new Node<T>;
     if (!isEmpty()) {
          returnVal->setData(head->getData());
          if (count == 1) {
               delete head;
               head = tail = NULL;
          }
          else {
               Node<T>* temp = head->getNextNode();
               delete head;
               head = temp;
          }
          count--;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;

     return returnVal;
}

template<class T>
void LinkedList<T>::remove_i(int i) {
     if (!isEmpty()) {
          Node<T>* temp = head;
          if (i > 1 && i <= count) {
               for (int j = 1; j < i - 1; j++)
                    temp = temp->getNextNode();

               Node<T>* temp2 = temp->getNextNode()->getNextNode();
               delete temp->getNextNode();
               temp->setNextNode(temp2);
               count--;
          }
          else if (i == 1) {
               head = head->getNextNode();
               delete temp;
               count--;
          }
          else
               std::cout << "\tplease enter a valid index" << std::endl;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
Node<T>* LinkedList<T>::get_i(int i) {
     if (!isEmpty()) {
          if (i > 0 && i <= count) {
               Node<T>* temp = head;
               for (int j = 1; j < i; j++)
                    temp = temp->getNextNode();
               return temp;
          }
          else
               std::cout << "\tplease enter a valid index" << std::endl;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;

     return NULL;
}

template<class T>
void LinkedList<T>::add_i(Node<T>* n, int i) {
     if (!isEmpty()) {
          if (i > 1 && i <= count) {
               Node<T>* temp = head;
               for (int j = 1; j < i - 1; j++)
                    temp = temp->getNextNode();

               n->setNextNode(temp->getNextNode());
               temp->setNextNode(n);
               count++;
          }
          else if (i == 1) {
               n->setNextNode(head);
               head = n;
               count++;
          }
          else
               std::cout << "\tplease enter a valid index" << std::endl;
     }
     else if (count == 0 && i == 1) {
          head = n;
          n->setNextNode(NULL);
          count++;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::print() {
     if (!isEmpty()) {
          Node<T>* temp = head;
          while (temp != NULL) {
               std::cout << "\t" << temp->getData() << std::endl;
               temp = temp->getNextNode();
          }
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::deleteList() {
     Node<T>* temp = head;
     Node<T>* temp2;
     do {
          temp2 = temp->getNextNode();
          delete temp;
          temp = temp2;
          count--;
     } while (temp != NULL);
}

template<class T>
void LinkedList<T>::reverse() {
     if (!isEmpty()) {
          if (count > 1) {
               Node<T>* prev = NULL;
               Node<T>* current = head;
               Node<T>* next = NULL;

               tail = head;
               while (current != NULL) {
                    next = current->getNextNode();
                    current->setNextNode(prev);
                    prev = current;
                    current = next;
               }
               head = prev;
          }
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::rotate(int rotations) {
     if (!isEmpty()) {
          Node<T>* temp = head;
          T* ptr = new T[count];
          tail->setNextNode(head);

          for (int i = 0; i < count; i++) {
               ptr[i] = temp->getData();
               temp = temp->getNextNode();
          }
          temp = get_i(rotations + 1);

          for (int i = 0; i < count; i++) {
               temp->setData(ptr[i]);
               temp = temp->getNextNode();
          }
          tail->setNextNode(NULL);

          delete[] ptr;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
void LinkedList<T>::random_shuffle() {
     if (!isEmpty()) {
          int size = count;
          Node<T>* temp = head;
          T* ptr = new T[size];

          for (int i = 0; i < size; i++) {
               ptr[i] = temp->getData();
               temp = temp->getNextNode();
          }
          deleteList();

          std::random_shuffle(&ptr[0], &ptr[size]); //random shuffle
          for (int i = 0; i < size; i++) {
               temp = new Node<T>;
               temp->setData(ptr[i]);
               push(temp);
          }

          delete[] ptr;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;
}

template<class T>
int LinkedList<T>::size() {
     return count;
}

template<class T>
bool LinkedList<T>::isEmpty() {
     if (count == 0)
          return true;
     else
          return false;
}

template<class T>
void LinkedList<T>::perform_operation(int op_code, T value) {
     Node<T>* temp = new Node<T>;
     Node<T>* tempPop = NULL;
     int index;

     switch (op_code) {
     case 1: //append
          temp->setData(value);
          append(temp);
          break;
     case 2: //remove tail
          remove_tail();
          break;
     case 3: //push
          temp->setData(value);
          push(temp);
          break;
     case 4: //pop
          tempPop = pop();
          if (tempPop->getData() != NULL)
               std::cout << "\tpopped " << tempPop->getData() << std::endl;
          delete tempPop;
          break;
     case 5: //remove i
          std::cout << "\tplease enter the index: ";
          std::cin >> index;
          remove_i(index);
          break;
     case 6: //get i
          std::cout << "\tplease enter the index: ";
          std::cin >> index;
          temp = get_i(index);
          if (temp != NULL)
               std::cout << "\tvalue at " << index << " is " << temp->getData() << std::endl;
          break;
     case 7: //add i
          std::cout << "\tplease enter the index: ";
          std::cin >> index;
          temp->setData(value);
          add_i(temp, index);
          break;
     case 8: //print
          print();
          break;
     case 9: //delete list
          deleteList();
          break;
     case 10: //reverse
          reverse();
          break;
     case 11: //rotate
          std::cout << "\tplease enter number of rotations: ";
          std::cin >> index;
          rotate(index);
          break;
     case 12: //random shuffle
          random_shuffle();
          break;
     case 13: //size
          std::cout << "\tthe size is " << size() << std::endl;
          break;
     }
}