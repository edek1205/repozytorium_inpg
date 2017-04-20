#include <iostream>
using namespace std;
 
template<class T>
class list
{
private:
    struct node
    {
        T value;
        node *next;
        node(const T& value) : value(value), next(nullptr) {}
    };
 
    node *root;
    node *last;
 
public:
    list() : root(nullptr), last(nullptr) {}
 
    void addFirst(const T& value)
    {
        node *nd = new node(value);
        nd->next = this->root;
        this->root = nd;
 
        if (!last) this->last = nd;
    }
 
    void addLast(const T& value)
    {
        node *nd = new node(value);
 
        if (!last) this->root = this->last = nd;
        else
        {
            this->last->next = nd;
            this->last = nd;
        }
    }
 
    ~list()
    {
        node *temp = this->root;
        while (temp)
        {
            node *current = temp;
            temp = temp->next;
            delete current;
            current = nullptr;
        }
    }
};
 
int main()
{
    list<int> list;
    list.addLast(5);
    list.addFirst(10);
    list.addFirst(20);
    list.addFirst(30);
    list.addFirst(40);
    list.addLast(60);
    list.addFirst(70);
    list.addLast(80);
    list.addLast(90);
    return 0;
}