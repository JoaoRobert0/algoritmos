#ifndef __LINKED_LIST_IFRN__
#define __LINKED_LIST_IFRN__

#include <iostream>

class linked_list {
private:
    struct int_node {
        int value;
        int_node* next, * prev;
    };
    int_node* head, * tail;
    unsigned int size_;
public:
    linked_list() { //Constructor. O(1); verified
        this->head = 0;
        this->tail = 0;
        this->size_ = 0;
    }
    
    ~linked_list() { //Destructor. O(n);
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
        size_ = 0;
    }
    
    unsigned int size() { return size_; } //Return the current size of the list. O(1); verified
    
    unsigned int capacitty() { return size_; } //Return the current size of the list. O(1); verified
    
    double percent_occupied() { //Return the current capacitty of the list. O(1); verified
        if (size_ == 0) { return 0; }
        return 1;
    }
    
    bool insert_at(unsigned int index, int value) { //Insert an element at index in the list. O(n); verified
        if (index > size_){ return false; }
        if (index == 0){
            push_front(value);
            return true;
        }
        if (index == size_){
            push_back(value); 
            return true;
        }
        int_node* current = head;
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = current;
        new_node->prev = current->prev;
        new_node->prev->next = new_node;
        current->prev = new_node;
        size_++;
        return true;
    }
    
    bool remove_at(unsigned int index) { //Return if the index of list was removed. O(n); verified
        if (index >= size_){ return false; }
        if (index == 0){ 
            pop_front();
            return true;
        }
        if (index == size_ - 1) {
            pop_back();
            return true;
        }
        int_node* current = head;
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        current->next->prev = current->prev;
        current->prev->next = current->next;
        delete current;
        size_--;
        return true;
    }
    
    int get_at(unsigned int index) { //Return the value by index; O(n); verified
        if (index >= size_) return -1;
        int_node* current = head;
        for (int i = 0; i < index; i++){
            current = current->next;
        }
        return current->value;
    }
    
    void clear() { //Remove the all elemets in the list. O(n); verified
        int_node* current = this->head;
        while (current != nullptr) {
            int_node* to_remove = current;
            current = current->next;
            delete to_remove;
        }
        size_ = 0;
    }
    
    void push_back(int value) { //Add a element in the last position in the list. O(1); verifeid
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->next = nullptr; //Pointer to null because it's the last element in the list.
        if (size_ == 0){
            new_node->prev = nullptr;
            head = new_node;
        }else{
            new_node->prev = tail;
            tail->next = new_node;
        }
        tail = new_node;
        size_++;
    }
    
    void push_front(int value) { //Add a element in the first position in the list. O(1); verifeid
        int_node* new_node = new int_node;
        new_node->value = value;
        new_node->prev = nullptr; //Pointer to null because it's the first element in the list.
        if (this->size_ == 0){
            new_node->next = nullptr;
            tail = new_node;
        }else{
            new_node->next = head;
            head->prev = new_node;
        }
        head = new_node;
        size_++;
    }
    
    bool pop_back() { //Remove the last element in the list and return if removed. O(1); verified
        if(head == nullptr){ 
            return false; 
        }
        if(head == tail){
            delete head;
            head = nullptr; 
            tail = nullptr; 
            size_--;
            return true; 
        }
        tail = tail->prev;
        delete tail->next;
        tail->next = nullptr;
        size_--;
        return true;
    }
    
    bool pop_front() { //Remove the first element in the list and return if removed. O(1); verified
        if(head == nullptr){ 
            return false; 
        }
        if(head == tail){
            delete head;
            head = nullptr; 
            tail = nullptr; 
            size_--;
            return true; 
        }
        head = head->next;
        delete head->prev;
        head->prev = nullptr;
        size_--;
        return true;
    }
    
    int front() { return head->value; } //Return the first element. O(1); verified
    
    int back() { return tail->value; } //Return the last element. O(1); verified
    
    bool remove(int value) { //Remove the first apper of the value in the list. O(n); verified
        int_node* current = head;
        for (int i = 0; i < size_; i++){
            if (current->value == value){
                if (i == 0){
                    current->next->prev = nullptr;
                    head = current->next;
                    delete current;
                    size_--;
                    return true;
                }
                if (i == size_ - 1){
                    current->prev->next = nullptr;
                    tail = current->prev;
                    delete current;
                    size_--;
                    return true;
                }
                current->next->prev = current->prev;
                current->prev->next = current->next;
                delete current;
                size_--;
                return true;
            }
            current = current->next;
        }
        return false;
    }
    
    int find(int value) { //Return if the value be in list. O(n); verified
        int_node* current = head;
        for (int i = 0; i < size_; i++){
            if (current->value == value){ return 1; }
            current = current->next;
        }
        return -1;
    }
    
    int count(int value) { //Return how many times the value appear in list. O(n); verified
        int count = 0;
        int_node* current = head;
        for (int i = 0; i < size_; i++){
            if (current->value == value){ count++; }
            current = current->next;
        }
        return count;
    }
    
    int sum() { //Return the sum of all elements. O(n); verified
        int sum;
        int_node* current = this->head;
        for (int i = 0; i < size_; i++){
            sum += current->value;
            current = current->next;
        }
        return sum;
    }
    
    void show() { //Show the list formatted. O(n); verified
        int_node* current = head;
        if (size_ == 0){
            std::cout << "NULL <=> NULL" << std::endl;
            return;
        }
        std::cout << "NULL <- ";
        for (int i = 0; i < size_; i++){
            if (i == size_ - 1) {
                std::cout << current->value;
                break;
            }
            std::cout << current->value << " <=> ";
            current = current->next;
        }
        std::cout << " -> NULL" << std::endl;
    }
};

#endif // __LINKED_LIST_IFRN__