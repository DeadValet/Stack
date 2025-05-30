
#include <cstddef>
#include <stddef.h>

#include "lab1.h"
#include "StackImpletation.h"
#include "list.h"


class VectorContainer : public IStackImplementation {
    private:
        Vector vector;

    public:
	VectorContainer()= default;
	VectorContainer(const ValueType* valueArray, const size_t arraySize) : vector(Vector(valueArray, arraySize)) {}
	VectorContainer (const VectorContainer& copy) {vector = copy.vector;}
	VectorContainer& operator=(const VectorContainer& copy) {
            if  ( this != &copy ) { vector = copy.vector;}
            return *this;
        }

	virtual void push(const ValueType& value) override { vector.pushBack(value); }

        virtual void pop() override { vector.popBack(); }

        virtual const ValueType& top() const override { return vector[size() - 1]; }

        virtual bool isEmpty() const override { return vector.size() == 0; }

        virtual size_t size() const override { return vector.size(); }


};

class ListContainer : public IStackImplementation {
    private:
        ForwardList l;

    public:
        ListContainer() = default;
        ListContainer(const ValueType* valueArray, const size_t arraySize) {
            for (size_t i = 0; i < arraySize; ++i) {
                l.push_front(valueArray[i]);
            }
        }

        ListContainer(const ListContainer& copyList) { l = copyList.l; }

        ListContainer& operator=(const ListContainer& copyList) { 
            if (this != &copyList) { l = copyList.l; }
            return  *this;
        }

        virtual void push(const ValueType& value) override { l.push_front(value); }

        virtual void pop() override { l.pop_front(); }

        virtual const ValueType& top() const override { return (*(l.front())).value;  }
        
        virtual bool isEmpty() const override { return l.empty(); };

        virtual size_t size() const override { return l.size(); };
};
