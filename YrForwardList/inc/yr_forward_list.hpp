#include <initializer_list>
#include <iostream>

using size_type = size_t;

template<typename T>
struct Node {
    T value;
    Node* next;

    Node(const T& value = T(), Node* next = nullptr);
};

template<typename T>
class YrForwardList {
private:
    Node<T>* head;
public:
    YrForwardList();
    YrForwardList(size_type count);
    YrForwardList(size_type count, const T& value);

    // !!! Помни, что должен написать свою реализацию для 
    // initializer_list !!!
    YrForwardList(std::initializer_list<T> init);
    YrForwardList(const YrForwardList<T>& other);
    YrForwardList(YrForwardList<T>&& other) noexcept;

    ~YrForwardList<T>();

    // my methods
    void Display();
};