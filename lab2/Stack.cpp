#include "Stack.h"
#include "list.h"
#include "ImpVector.h"
#include <cstddef>
#include <utility>


Stack::Stack(StackContainer container) : _containerType(container) {
	if (container == StackContainer::Vector) {
		_pimpl = new VectorContainer();
	}
	else if (container == StackContainer::List) {
		_pimpl = new ListContainer();
	}
}

Stack::Stack(const ValueType* valueArray, const size_t arraySize, StackContainer container) : _containerType(container) {
        if (container == StackContainer::Vector) {
                _pimpl = new VectorContainer(valueArray, arraySize);
        }
        else if (container == StackContainer::List) {
                _pimpl = new ListContainer(valueArray, arraySize);
        }
}

Stack::Stack(const Stack& copyStack) {
    *this = copyStack;
}

Stack& Stack::operator=(const Stack& copyStack) {
    if (this != &copyStack) {
        _containerType = copyStack._containerType;
        delete _pimpl;

        if (_containerType == StackContainer::Vector) {
                _pimpl = new VectorContainer(*dynamic_cast<VectorContainer*>(copyStack._pimpl));
        }
        else if (_containerType == StackContainer::List) {
                _pimpl = new ListContainer(*dynamic_cast<ListContainer*>(copyStack._pimpl));
        }


    }
    return *this;
}

Stack::Stack(Stack&& moveStack) noexcept {
    *this = std::move(moveStack);
}

Stack& Stack::operator=( Stack&& moveStack ) noexcept {
    if (this != &moveStack) {

	    delete _pimpl;

	    _containerType = moveStack._containerType;
	    _pimpl = moveStack._pimpl;
    	    moveStack._pimpl = nullptr;
    
    }

    return *this;
}

Stack::~Stack() { delete _pimpl;}

void Stack::push(const ValueType& value) { _pimpl->push(value); }

void Stack::pop() { _pimpl->pop(); }

const ValueType& Stack::top() const { return _pimpl->top(); }

bool Stack::isEmpty() const { return _pimpl->isEmpty(); }

size_t Stack::size() const { return _pimpl->size(); }


