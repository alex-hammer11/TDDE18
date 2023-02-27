#include "linked_list.h"
#include <iostream>
#include <string>

using namespace std;

Linked_list::Linked_list()
    : first{nullptr}, tail{nullptr}, size_of_list{0}
{
}

Linked_list::Linked_list(Linked_list const &other)
    : first{nullptr}, tail{nullptr}, size_of_list{0}
{
    Node *tmp{other.first};
    if (!other.is_empty())
    {
        for (int i{0}; i < other.size_of_list; ++i)
        {
            insert_last(tmp->data);
            tmp = tmp->next;
        }
    }
}

Linked_list::Linked_list(Linked_list &&other)
    : first{(Node * &&) other.first}, tail{(Node * &&) other.tail}, size_of_list{(int &&)other.size_of_list}
{
    other.first = nullptr;
    other.size_of_list = 0;
}

Linked_list::~Linked_list()
{
    Node *tmp{first};
    if (first != nullptr)
    {
        for (int i{0}; i < size_of_list; ++i)
        {
            if (first->next != nullptr)
            {
                tmp = first->next;
                delete (first);
                first = tmp;
            }
        }
        delete (first);
    }
}

Linked_list &Linked_list::operator=(Linked_list const &other)
{
    Linked_list tmp{other};
    Node *this_first{this->first};
    int size_of_this{this->size_of_list};
    if (this->first != nullptr)
    {
        this->first = tmp.first;
        this->size_of_list = tmp.size_of_list;
        tmp.first = this_first;
        tmp.size_of_list = size_of_this;
    }
    return *this;
}

Linked_list &Linked_list::operator=(Linked_list &&other)
{
    this->empty_list();
    this->first = other.first;
    this->size_of_list = other.size_of_list;
    other.first = nullptr;
    other.size_of_list = 0;
    return *this;
}

bool Linked_list::operator==(Linked_list const &other) const
{
    Node *this_pointer{this->first};
    Node *other_pointer{other.first};

    if (this->size_of_list == other.size_of_list)
    {
        for (int i{0}; i < this->size_of_list; ++i)
        {
            if (this_pointer->data != other_pointer->data)
            {
                return false;
            }
            if (this_pointer->next != nullptr && other_pointer->next != nullptr)
            {
                this_pointer = this_pointer->next;
                other_pointer = other_pointer->next;
            }
        }
        return true;
    }
    return false;
}

bool Linked_list::is_empty() const
{
    return (first == nullptr);
}

int Linked_list::size() const
{
    return size_of_list;
}

void Linked_list::insert(int const &value)
{
    Node *tmp{new Node{value, nullptr}};
    Node *next_node{first};
    Node *previous_node{first};
    if (first == nullptr)
    {
        tmp->next = first;
        first = tmp;
    }
    else
    {
        for (int i{0}; i < size_of_list; ++i)
        {
            if (value <= next_node->data)
            {
                tmp->next = next_node;
                if (first->data > tmp->data)
                {
                    first = tmp;
                }
                else
                {
                    previous_node->next = tmp;
                }
                break;
            }
            else if (next_node->next == nullptr)
            {
                next_node->next = tmp;
                tail = next_node->next;
                tmp->next = nullptr;
                break;
            }
            else
            {
                previous_node = next_node;
                next_node = next_node->next;
            }
        }
    }
    ++size_of_list;
}

void Linked_list::remove(int const &value)
{
    if (!this->is_empty())
    {
        Node *next_node{first};
        Node *previous_node{first};
        for (int i{0}; i < size_of_list; ++i)
        {
            if (next_node->data == value)
            {
                if (value == first->data)
                {
                    first = next_node->next;
                }
                else if (next_node->next == nullptr)
                {
                    previous_node->next = nullptr;
                }
                else
                {
                    previous_node->next = next_node->next;
                }
                delete (next_node);
                break;
            }
            else
            {
                previous_node = next_node;
                next_node = next_node->next;
            }
        }
        --size_of_list;
    }
}

void Linked_list::empty_list()
{
    Node *tmp{first};
    if (first != nullptr)
    {
        for (int i{0}; i < size_of_list; ++i)
        {
            if (first->next != nullptr)
            {
                tmp = first->next;
                delete (first);
                first = tmp;
            }
        }
        if (first != nullptr)
        {
            delete (first);
        }
        first = nullptr;
        size_of_list = 0;
    }
}

int Linked_list::get_index(int const &index) const
{
    if (index > size_of_list)
    {
        cout << "Index larger than size of list" << endl;
        return 0;
    }
    Node *tmp{first};
    for (int i{0}; i < index; ++i)
    {
        tmp = tmp->next;
    }
    return tmp->data;
}

void Linked_list::print() const
{
    cout << this->to_string() << endl;
}

std::string Linked_list::to_string() const
{
    return ("List: " + print_node(this->first));
}

std::string Linked_list::print_node(Node *node) const
{
    std::string list{};
    if (node->next != nullptr)
    {
        list += node->to_string();
        list += print_node(node->next);
    }
    else
    {
        list += std::to_string(node->data);
    }
    return list;
}

void Linked_list::insert_last(int const &value)
{
    Node *tmp{new Node{value, nullptr}};
    if (is_empty())
    {
        tmp->next = first;
        first = tmp;
        tail = first;
    }
    else
    {
        tmp->next = nullptr;
        tail->next = tmp;
        tail = tmp;
    }
    ++size_of_list;
}

std::string Linked_list::Node::to_string() const
{
    return (std::to_string(this->data) + " -> ");
}
