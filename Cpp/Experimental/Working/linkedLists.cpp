#include <iostream>
using namespace std;

struct node {
    int val;
    struct node* next;
    
    node() {
        val = 0;
        next = nullptr;
    }
    node(int x) {
        val = x;
        next = nullptr;
    }
    node(int x, struct node* y) {
        val = x;
        next = y;
    }
};

struct circularLinkedList {
    struct node* head;
    struct node* tail;

    circularLinkedList() {
        head = new node();
        tail = new node();
        head->next = tail;
        tail->next = head;
    };

    circularLinkedList(int x) {
        head = new node(x);
        tail = new node();
        head->next = tail;
        tail->next = head;
    };

    circularLinkedList(int x, int y) {
        head = new node(x);
        tail = new node(y);
        head->next = tail;
        tail->next = head;
    };

    void append() {
        tail->next = new node();
        tail->next->next = head;
        tail = tail->next;
    }

    void append(int x) {
        tail->next = new node(x);
        tail->next->next = head;
        tail = tail->next;
    }

    void append(struct node* x) {
        tail->next = x;
        tail->next->next = head;
        tail = tail->next;
    }
};

int main() {
    circularLinkedList* list = new circularLinkedList(1);
    for (int j = 0; j < 10; ++j) {
        node* current = list->head;
        for (int i = 0; i < 10; ++i) {
            cout << current->val << ' ';
            current = current->next;
        } 
        cout << '\n';
        list->append(new node(j));
    }
}
