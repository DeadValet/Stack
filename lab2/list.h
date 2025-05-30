#pragma once

#include <stddef.h>

using ValueType = double;

class ForwardList {
    private:
        struct Node {
            ValueType value;
            Node *_ref;
        };
        Node *head = nullptr;

        void display(Node *nextList);

        void deepcopy(const Node *ya);

    public:
        ForwardList()=default;
        
        ~ForwardList();
        ForwardList(const ForwardList &yaList);
        ForwardList& operator=(const ForwardList &yaList);

        ForwardList(ForwardList &&yaList);
        ForwardList& operator=(ForwardList &&yaList);

        void push_front( ValueType value );
        void pop_front(); 
        bool empty() const; 
        void display();
        void clear();

        Node *front() { return head; }
        Node *front() const { return head; }

        size_t size() const;

};


