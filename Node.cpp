template<class T>
class Node {
private:
     T data;
     Node<T>* nextNode;
public:
    Node();
    Node(T data, Node<T>* nextNode);
    void setData(T data);
    void setNextNode(Node<T>* nextNode);
    T getData();
    Node<T>* getNextNode();
};

template<class T>
Node<T>::Node() {
     nextNode = NULL;
}

template<class T>
Node<T>::Node(T data, Node<T>* nextNode) {
     this->data = data;
     this->nextNode = nextNode;
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
T Node<T>::getData() {
     return data;
}

template<class T>
Node<T>* Node<T>::getNextNode() {
     return nextNode;
}