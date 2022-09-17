#include <bits/stdc++.h>
using namespace std;

template <typename T>
struct Node {
        T data;
        Node<T>* next;
        Node (const T& data) : data(data),next(nullptr) {}
        Node (){}
};

template <typename T>
class SinglyLinkedList {

    public : 
        SinglyLinkedList () : _head(nullptr), _tail(nullptr), _size(0) {}
        int size () { return _size; }
        void push_back();
        void push_front();
        void push_middle();
        void insert();
        void pop_back();
        void pop_front();
        void pop_middle();
        void pop_pos();
        T front();
        T back();
        void reverse();
        void print();

    private:
        void insertInternal(const T& val, const int& pos);
        void deleteInternal(const int& pos);
        Node<T>* reverse(Node<T>* node);

    private :
        Node<T>* _head;
        Node<T>* _tail;
        int _size;
};

template <typename T>
void SinglyLinkedList<T>::push_back() {
    cout << "Enter value to be inserted: \n";
    T val;
    cin>>val;
    insertInternal(val, size()+1);
}

template <typename T>
void SinglyLinkedList<T>::push_front() {
    cout << "Enter value to be inserted: \n";
    T val;
    cin>>val;
    insertInternal(val, 1);
}

template<typename T>
void SinglyLinkedList<T>::push_middle() {
    cout << "Enter value to be inserted: \n";
    T val;
    cin>>val;
    insertInternal(val, (size()/2) +1);
}

template<typename T>
void SinglyLinkedList<T>::insert() {
    cout << "Enter value to be inserted: \n";
    T val;
    cin>>val;

    cout<<"Enter position where the value "<<val<<" to be inserted : \n";
    int pos{0};
    cin>>pos;
    insertInternal(val, pos);
}

template <typename T>
void SinglyLinkedList<T>::insertInternal(const T& val, const int& pos) {
    if(pos > size()+1 || pos < 1) {
        cout<<"Please enter a valid position\n";
        return;
    }
    else if (pos == 1) {
        Node<T>* newnode = new Node(val);
        newnode->next = _head;
        _head = newnode;
        _size++;
        if(size() == 1) {
            _tail = _head;
        }
        return;
    }
    else if (pos == (size()+1)) {
        Node<T>* newnode = new Node(val);
        _tail->next = newnode;
        _tail = newnode;
        _size++;
        return;
    }
    else {
        int p = pos;
        Node<T>* curr_node = _head;
        p-=2;
        while (p--) {
            curr_node = curr_node->next;
        }
        Node<T>* newnode = new Node(val);
        newnode->next = curr_node->next;
        curr_node->next = newnode;
        _size++;
    }
}

template <typename T>
void SinglyLinkedList<T>::deleteInternal(const int& pos) {
    if (pos < 1 || pos > size()) {
        cout<<"Please enter a valid position\n";
    }
    else if (pos == 1) {
        Node<T>* newnode = _head;
        _head = _head->next;
        if(size()==1) _tail = _tail->next;
        _size--;
        delete newnode;
    }
    else if (pos == size()) {
        Node<T>* curr_node = _head;
        while(curr_node->next != _tail) {
            curr_node = curr_node->next;
        }
        _tail = curr_node;
        curr_node = curr_node->next;
        _tail->next = nullptr;
        _size--;
        delete curr_node;
    }
    else {
        int p = pos;
        Node<T>* curr_node = _head;
        p-=2;
        while(p--) {
            curr_node = curr_node->next;
        }
        Node<T>* newnode = curr_node->next;
        curr_node->next = newnode->next;
        _size--;
        delete newnode;
    }
}

template <typename T>
void SinglyLinkedList<T>::pop_back() {
    deleteInternal(size());
}

template <typename T>
void SinglyLinkedList<T>::pop_front() {
    deleteInternal(1);
}

template <typename T>
void SinglyLinkedList<T>::pop_middle() {
    deleteInternal((size()/2)+1);
}

template <typename T>
void SinglyLinkedList<T>::pop_pos() {
    cout<<"Enter the postion you want to delete : \n";
    int pos;
    cin>>pos;
    deleteInternal(pos);
}

template <typename T>
T SinglyLinkedList<T>::front() {
    return _head->data;
}

template <typename T>
T SinglyLinkedList<T>::back() {
    return _tail->data;
}

template<typename T>
void SinglyLinkedList<T>::print() {
    Node<T>* newnode = _head;
    while(newnode) {
        cout<<newnode->data<<" ";
        newnode = newnode->next;
    }
    cout<<"\n";
}

template<typename T>
Node<T>* SinglyLinkedList<T>::reverse(Node<T>* node) {

}

template<typename T>
void SinglyLinkedList<T>::reverse() {
}

int main () {
    int option{0};
    SinglyLinkedList<int>* list = new SinglyLinkedList<int>();
    while (true) {
        cout<<"Which operation you want to perform : \n";
        cout<<"1. push at the front : ";
        cout<<"2. push at the back : ";
        cout<<"3. insert in the middle : ";
        cout<<"4. insert at a position : ";
        cout<<"5. pop from the front : ";
        cout<<"6. pop from the end : ";
        cout<<"7. delete from the middle : ";
        cout<<"8. delete from a position : ";
        cout<<"9. Print front : ";
        cout<<"10. Print back : ";
        cout<<"11. Print Linked List : ";
        cout<<"12. Reverse the linked list : ";
        cout<<"13. Quit : ";

        cin>>option;

        switch (option) {
            case 1 :    list->push_front();
                        cout<<"Done\n";
                        break;
            case 2 :    list->push_back();
                        cout<<"Done\n";
                        break;
            case 3 :    list->push_middle();
                        cout<<"Done\n";
                        break;
            case 4 :    list->insert();
                        cout<<"Done\n";
                        break;
            case 5 :    list->pop_front();
                        cout<<"Done\n";
                        break;
            case 6 :    list->pop_back();
                        cout<<"Done\n";
                        break;
            case 7 :    list->pop_middle();
                        cout<<"Done\n";
                        break;
            case 8 :    list->pop_pos();
                        cout<<"Done\n";
                        break;
            case 9 :    list->front();
                        cout<<"Done\n";
                        break;
            case 10 :    list->back();
                        cout<<"Done\n";
                        break;
            case 11 :   list->print();
                        cout<<"Done\n";
                        break;
            case 12 :   list->reverse();
                        cout<<"Done\n";
                        break;
            case 13 :   return 0;
            default :   cout<<"This is an invalid option, Please run again.\n";
                        break;
        }
    }
    return 0;
}