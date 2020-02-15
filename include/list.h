#pragma once

template<typename T,typename Alloc = std::allocator<T>>
class List
{
private:

template<typename U>
class Node
{
    public:
    Node *addNext;                              
    U data;

    Node(U data, Node *addNext = nullptr)       
    {
        this->data = data;
        this->addNext = addNext;
    }
};

int size;                                       
Node<T> *head;                                  


public:

    using Allocator =typename Alloc::template rebind<Node<T>>::other;
    Allocator alloc;

    List()
    {
     size = 0;           
     head = nullptr;     
    }

   ~List()
   {
       while(size) pop_back();
   }
void push_back (T data)
{
   if (head == nullptr)  
   {
        head = alloc.allocate(1); 
        alloc.construct(head, data);
   }
   else
   {
       Node<T> *current = this->head; 
       while (current->addNext != nullptr)      
       {
           current = current->addNext;
       }
       current->addNext = alloc.allocate(1);
       alloc.construct(current->addNext, data);
   }
   size++;
}

private:
void pop_back()
{
        Node<T> *current = this->head;           
        Node<T> *previous = this->head;
        while (current->addNext != nullptr)
        {
           previous = current;
           current = current->addNext;
        }
        alloc.destroy(current);
        alloc.deallocate(current,1);
        previous->addNext = nullptr;
        size--;
}

public:
T& operator[](const int index)
{
    if (size == 0)
    {
        std::cout << "List is empty" << std::endl;
        exit (1);
    }
    else if (index < size && index >= 0)
    {
        int count = 0;
        Node<T> *current = this->head;
        while (current!= nullptr)
        {
            if (count == index)
            {
                return current->data;
            }
            current = current->addNext;
            count++;
        }
    }
    throw std::bad_alloc();
}

int GetSize()
{
    return size;
}

};



















































