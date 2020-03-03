#include "version_lib.h"
#include "allocator.h"
#include "list.h"
#include <iostream>
#include <map>
#include "factorial.h"
#include <string>


int main(int argc, char *argv[]) 
{
  if ( argc > 1)
  {
    const std::string ver = "-version";
    if(argv[1] == ver)
    std::cout << "version: " << version_major()<< '.'<< version_minor() << '.' << version_patch() << std::endl;
    else
    std::cout << "Type: -version, if you want to known programm version" << std::endl;    
  }

    
  try
  {
    constexpr int MaxElement = 10;

    // Cоздание и заполнение стандартного экземпляра map
    auto m = std::map<int, int>{};
    for (int i = 0; i < MaxElement; ++i) m[i] = my_factorial::factorial(i);

    // Вывод на экрна значений
    for(auto& i : m)    std::cout << i.first << ' ' << i.second << std::endl;
    std::cout << std::endl;

    // Создание и запонение экземпляра map с кастомным аллокатором
    using map_cust_alloc = my_allocator<std::pair<const int, int>, MaxElement>;
    auto castom_m = std::map<int, int, std::less<int>,map_cust_alloc>{};
    for (int i = 0; i < MaxElement; ++i) castom_m[i] = my_factorial::factorial(i);
    
    // Вывод на экрна значений
    for(auto& i : castom_m)     std::cout << i.first << ' ' << i.second << std::endl;
    std::cout << std::endl;

    // Создание и запонение экземпляра кастомного контейнера List со стандартным аллокатором
    List<int> lst;
    for (int i = 0; i < MaxElement; ++i)    lst.push_back(my_factorial::factorial(i));
    
    // Вывод на экрна значений
    for(int i = 0; i < lst.GetSize(); ++i)     std::cout << i << '-' << lst[i] << std::endl;
    std::cout << std::endl;

    // Создание и запонение экземпляра кастомного контейнера List с кастомным аллокатором
    using list_cust_alloc = my_allocator<int, MaxElement>;
    List<int,list_cust_alloc> my_list;
    for (int i = 0; i < MaxElement; ++i)    my_list.push_back(my_factorial::factorial(i));
    
    // Вывод на экрна значений
    for (int i=0;i<my_list.GetSize();i++)   std::cout << i << ' ' <<  my_list[i] << std::endl;

    // List<int> lst;
    // lst.push_back(9);
    // lst.push_back(8);
    // lst.push_back(7);
    // std::cout << 0 << '-' << lst[0] << std::endl;
    // std::cout << 1 << '-' << lst[1] << std::endl;
    // std::cout << 2 << '-' << lst[2] << std::endl;

  }
  
  catch(const std::exception& e)
  {
    std::cerr << e.what() << '\n';
  }

    return 0;
}
