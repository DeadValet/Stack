#include "list.h"
#include <iostream>

ForwardList::~ForwardList() {
    while (head != nullptr) { pop_front(); }
}

ForwardList::ForwardList(const ForwardList &yaList){
    if (this == &yaList) { return; }
    deepcopy(yaList.head);
}

ForwardList& ForwardList::operator=(const ForwardList &yaList){
    if (this != &yaList) { deepcopy(yaList.head); }
    return *this;
}

ForwardList::ForwardList(ForwardList &&yaList) : head(yaList.head) { yaList.head = nullptr; }

ForwardList& ForwardList::operator=(ForwardList &&yaList) {
    if (this != &yaList) { 
        clear();
        head = yaList.head;
        yaList.head = nullptr;
    }
    return *this;
}

void ForwardList::push_front( ValueType value ) {
    Node *newNode = new Node{value, head};
    head = newNode;
}

void ForwardList::pop_front() {
    if (head != nullptr) {
        Node *temp = head->_ref;
        delete head;
        head = temp;
    }
}

bool ForwardList::empty() const {
    return head == nullptr;
}

void ForwardList::display() {
    if (head == nullptr) {
        std::cout << std::endl;
        return;
    }
    std::cout << head->value << " ";
    display(head->_ref);
}

void ForwardList::clear() {
    while(head != nullptr) {
        Node *temp = head->_ref;
        delete head;
        head = temp;
    }
}

void ForwardList::display(ForwardList::Node *nextList) {
    if (nextList == nullptr) { 
        std::cout << std::endl;
        return ; 
    }
    std::cout << nextList->value << " ";
    display(nextList->_ref);
}

void ForwardList::deepcopy(const ForwardList::Node *yaList) {
    if (yaList == nullptr) { return; }

    clear();

    head = new Node{yaList->value, nullptr};
    Node *oldTail = yaList->_ref;
    Node *tail = head; 

    while (oldTail != nullptr) {
        tail->_ref = new Node{oldTail->value, nullptr}; 
        tail = tail->_ref; 
        oldTail = oldTail->_ref; 
    }
}


size_t ForwardList::size() const {
    size_t size = 0;
    Node *tail = head;

    while (tail != nullptr) {
        ++size;
        tail = tail->_ref;
    }

    return size;
}

