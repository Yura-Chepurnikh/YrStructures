#include "../inc/yr_forward_list.hpp"
#include <initializer_list>
#include <iostream>

template<typename T>
Node<T>::Node(const T& value, Node* next) : value(value), next(next) { }

template<typename T>
YrForwardList<T>::YrForwardList() : head(nullptr) { }

template<typename T>
YrForwardList<T>::YrForwardList(size_type count)
{
    if (count > 0) {
        head = new Node<T>();
        Node<T>* current = head;
        while ((count--) > 0) {
            current->next = new Node<T>();
            current = current->next;
        }
    } else {
        head = nullptr;
    }
}

template<typename T>
YrForwardList<T>::YrForwardList(size_type count, const T& value) 
{
    if (count > 0) {
        head = new Node<T>(value);
        Node<T>* current = head;
        while ((--count) > 0) {
            current->next = new Node<T>(value);
            current = current->next;
        } 
    } else {
        head = nullptr;
    }
}

template<typename T>
YrForwardList<T>::YrForwardList(std::initializer_list<T> init) { }

template<typename T>
YrForwardList<T>::YrForwardList(const YrForwardList<T>& other) 
{
    if (other.head) {
        head = new Node<T>(other.head->value);
        Node<T>* current = head;
        Node<T>* otherCurrent = other.head->next;

        while (otherCurrent) {
            current->next = new Node<T>(otherCurrent->value);
            current = current->next;
            otherCurrent = otherCurrent->next;
        }
    }
}

template<typename T>
YrForwardList<T>::YrForwardList(YrForwardList<T>&& other) noexcept 
{
    head = std::move(other.head);
    other.head = nullptr;
}

template<typename T>
YrForwardList<T>::~YrForwardList() 
{
    Node<T>* current = head;
    while (current) {
        Node<T>* temp = current;
        current = current->next;
        delete temp;
    }
    std::cout << "YrForwardList destroyed, memory freed." << std::endl;
}

template<typename T>
void YrForwardList<T>::Display() {
    Node<T>* current = head;
    while (current) {
        std::cout << current->value << " -> ";
        current = current->next;
    }
    std::cout << "nullptr" << std::endl;
}

int main() {
    YrForwardList<int> list(5, 1);

    list.Display();
    std::cout << "\n\n\n";

    YrForwardList<int> secondList(std::move(list));

    secondList.Display();
    std::cout << "\n\n\n";

    list.Display();
    std::cout << "\n\n\n";
}