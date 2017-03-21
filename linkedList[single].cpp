#include<iostream>
#include<string> //just in case the input type is string...not required for other data types
#include<algorithm> //used in random_shuffle function

template<class T>
class Node {
private:
     T data;
     Node<T>* nextNode;
     Node<T>* prevNode;
public:
    Node();
    Node(T data, Node<T>* nextNode);
    Node(T data, Node<T>* nextNode, Node<T>* prevNode);
    void setData(T data);
    void setNextNode(Node<T>* nextNode);
    void setPrevNode(Node<T>* prevNode);
    T getData();
    Node<T>* getNextNode();
    Node<T>* getPrevNode();
};

template<class T>
Node<T>::Node() {
     nextNode = NULL;
     prevNode = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* nextNode) {
     this->data = data;
     this->nextNode = nextNode;
     prevNode = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* nextNode, Node<T>* prevNode) {
     this->data = data;
     this->nextNode = nextNode;
     this->prevNode = prevNode;
}

template<class T>
void Node<T>::setData(T data) {
     this->data = data;
}

template<class T>
void Node<T>::setNextNode(Node<T>* nextNode) {
     this->nextNode = nextNode;
}

template<class T>
void Node<T>::setPrevNode(Node<T>* prevNode) {
     this->prevNode = prevNode;
}

template<class T>
T Node<T>::getData() {
     return data;
}

template<class T>
Node<T>* Node<T>::getNextNode() {
     return nextNode;
}

template<class T>
Node<T>* Node<T>::getPrevNode() {
     return prevNode;
}


template<class T>
class LinkedList {
private:
     //private variables
     int count;
     int type;
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
     LinkedList(int type);
     bool isEmpty();
     void perform_operation(int op_code, T value);
};

template<class T>
LinkedList<T>::LinkedList(int type) {
     count = 0;
     this->type = type;
     head = NULL;
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
     append(n);
}

template<class T>
Node<T>* LinkedList<T>::pop() {
     Node<T> returnVal;
     returnVal.setData(NULL);
     if (!isEmpty()) {
          if (count == 1) {
               returnVal.setData(head->getData());
               delete head;
               head = tail = NULL;
          }
          else {
               Node<T>* temp = head;
               while (temp->getNextNode() != tail)
                    temp = temp->getNextNode();

               returnVal.setData(temp->getNextNode()->getData());
               delete temp->getNextNode();
               temp->setNextNode(NULL);
               tail = temp;
          }
          count--;
     }
     else
          std::cout << "\tthe list is empty!" << std::endl;

     return &returnVal;
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
bool LinkedList<T>::isEmpty(){
    if(count == 0)
        return true;
    else
        return false;
}

template<class T>
void LinkedList<T>::perform_operation(int op_code, T value) {
	 Node<T>* temp = new Node<T>;
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
          temp = pop();
          if(temp->getData() != NULL)
                std::cout << "\tpopped " << temp->getData() << std::endl;
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
          if(temp != NULL)
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

typedef int linkedListType;

int main(){
     int input;
	 linkedListType data;
     std::cout << "what type of linked list do you want to create?\n"
          << "\t1. singly linked\n"
          << "\t2. doubly linked\n"
          << "\t3. singly-circularly linked\n"
          << "\t4. double-circularly linked\n\t: ";
     std::cin >> input;

     LinkedList<linkedListType> llist(input);
     do{
          std::cout << "please select the operation you want to execute\n"
               << "\t1. append\t"
               << "\t2. remove tail\t"
               << "\t3. push\t"
               << "\t\t4. pop\n"
               << "\t5. remove i\t"
               << "\t6. get i\t"
               << "\t7. add i\t"
               << "\t8. print\n"
               << "\t9. delete\t"
               << "\t10. reverse\t"
               << "\t11. rotate\t"
               << "\t12. random shuffle\n"
               << "\t13. size\t"
               << "\t-1. exit\n\t: ";
          std::cin >> input;
		  if (input > 0 && input < 14) {
			  if (input == 1 || input == 3 || input == 7) {
				  std::cout << "\tplease enter the value to add: ";
				  std::cin >> data;
			  }
			  else
				  data = NULL;

			  llist.perform_operation(input, data);
			  std::cout << std::endl;
		  }
		  else if (input == -1)
			  return 0;
		  else
              std::cout << "\tplease enter a valid input\n" << std::endl;
     }while(input != -1);

     return 0;
}
