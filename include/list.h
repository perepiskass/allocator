#pragma once

template<typename T,typename Alloc = std::allocator<T>>
class List
{
private:

template<typename U>
class Node
{
    public:
    Node *add_next;                              
    U data;

    Node(U data, Node *add_next = nullptr)       
    {
        this->data = data;
        this->add_next = add_next;
    }
};

int size;                                       
Node<T> *head;                                  


public:

    using Allocator =typename Alloc::template rebind<Node<T>>::other;
    Allocator alloc;

    List()
    {
     this->size = 0;           
     this->head = nullptr;     
    }

   ~List()
   {
       while(size) pop_back();
   }

void push_back (T data)
{
   if (this->head == nullptr)  
   {
        this->head = alloc.allocate(1); 
        alloc.construct(this->head, data);
   }
   else
   {
       Node<T> *current = this->head; 
       while (current->add_next != nullptr)      
       {
           current = current->add_next;
       }
       current->add_next = alloc.allocate(1);
       alloc.construct(current->add_next, data);
   }
   ++size;
}

private:
void pop_back()
{
        Node<T> *current = this->head;           
        Node<T> *previous = this->head;
        while (current->add_next != nullptr)
        {
           previous = current;
           current = current->add_next;
        }
        alloc.destroy(current);
        alloc.deallocate(current,1);
        previous->add_next = nullptr;
        size--;
}

public:
T& operator[](const int index)
{
    if (index < size && index >= 0)
    {
        int count = 0;
        Node<T> *current = this->head;
        while (current!= nullptr)
        {
            if (count == index)
            {
                return current->data;
            }
            current = current->add_next;
            count++;
        }
    }

    throw std::out_of_range("Индекс за пределами диапазона контейнера");

}

int GetSize()
{
    return size;
}

};



















































