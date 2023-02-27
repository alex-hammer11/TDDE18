#ifndef LINKED_LIST_H
#define LINKED_LIST_H

#include <string>
class Linked_list
{
public:
    Linked_list();

    Linked_list(Linked_list const &other);

    Linked_list(Linked_list &&other);

    ~Linked_list();

    Linked_list &operator=(Linked_list const &other);

    Linked_list &operator=(Linked_list &&other);

    bool operator==(Linked_list const &other) const;

    bool is_empty() const;

    int size() const;

    void insert(int const &value);

    void remove(int const &value);

    void empty_list();

    int get_index(int const &index) const;

    void print() const;

    std::string to_string() const;

private:
    struct Node
    {
        int data;
        Node *next;

        std::string to_string() const;
    };

    Node *first;
    Node *tail;
    int size_of_list;

    void insert_last(int const &value);

    std::string print_node(Node *node) const;
};
#endif
