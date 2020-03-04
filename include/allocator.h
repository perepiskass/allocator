#pragma once
#include <iostream>

template<typename T, int N = 0>
struct my_allocator 
{
    using value_type = T;
    using pointer = T*;
    using const_pointer = const T*;
    using reference = T&;
    using const_reference = const T&;

    private:
    int count = 0;              // Текущее значение выделенного места под объект из заданного пула
    void* head = nullptr;       
    pointer p = nullptr;        

    public:

    template<typename U>
    struct rebind 
    {
        using other = my_allocator<U,N>;
    };

    my_allocator()
    {
        
    }

    ~my_allocator()
    {
        free(head);
    }

    template<typename U> 
    my_allocator(const my_allocator<U>&) 
    {}

    pointer allocate(std::size_t n) 
    {
        if (head == nullptr)
        {
            head = std::malloc(N * sizeof(T));
            if (!head)
            throw std::bad_alloc();
        }
        if (count==0)
        {
            ++count;
            p = reinterpret_cast<pointer>(head);
            return p;
        }
        else if (count + n <= N)
        {
            ++count;
            p+=n;
            return p;
        }
        else 
        {
            throw std::bad_alloc();
        }
    }

    void deallocate(pointer p, std::size_t n=0) 
    {
        if(p && n>=0)--count;
        // if(count==0)
        // {
        //     free(head);
        //     head == nullptr;
        // }
    }

    template<typename U, typename ...Args>
    void construct(U *p, Args &&...args) 
    {
        new(p) U(std::forward<Args>(args)...);
    }

    template<typename U>
    void destroy(U* p) 
    {
        p->~U();
    }
};

