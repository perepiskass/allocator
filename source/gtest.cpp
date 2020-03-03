#include <gtest/gtest.h>
#include "version_lib.h"
#include "factorial.h"
#include "allocator.h"
#include "list.h"


// Тест кейсы на проверку версий
TEST(version_test_case, version_test_patch)
{
    ASSERT_GE(version_patch(), 1);
}
TEST(version_test_case, version_test_minor)
{
    EXPECT_EQ(version_minor(), 1);
}
TEST(version_test_case, version_test_major)
{
    EXPECT_EQ(version_major(), 1);
}

// Тест кейсы функции факториала
TEST(factorial_test_case, factorial_test) 
{
  EXPECT_EQ(my_factorial::factorial(0), 1);
  EXPECT_EQ(my_factorial::factorial(1), 1);
  EXPECT_EQ(my_factorial::factorial(2), 2);
  EXPECT_EQ(my_factorial::factorial(3), 6);
  EXPECT_EQ(my_factorial::factorial(9), 362880);
  EXPECT_EQ(my_factorial::factorial(10), 3628800);
}

// Тест кейсы аллокатора my_allocator
TEST(allocator_test_case, allocate_test)
{
  constexpr int N = 1;
  my_allocator<int, N> allocator;
  int* ptr = nullptr;
  ptr = allocator.allocate(N);
  
  ASSERT_NE(ptr, nullptr);
}

TEST(allocator_test_case, allocate_bad_test)
{
  constexpr int N = 3;
  my_allocator<int, N> allocator;

  EXPECT_THROW ({for(int i = 0; i < N+1;++i)    allocator.allocate(1);},std::bad_alloc);
}

TEST(allocator_test_case, allocate_construct_test)
{
  constexpr int N = 1;
  my_allocator<int, N> allocator;
  int* ptr = allocator.allocate(N);
  allocator.construct(ptr, 7);
  EXPECT_EQ(*ptr, 7);
}

// Тест кейсы контейнера List
TEST(list_test_case, list_push_back_test)
{
  List<int> lst;
  lst.push_back(1);
  lst.push_back(2);
  lst.push_back(3);

  EXPECT_EQ(lst[0],1);
  EXPECT_EQ(lst[1],2);
  EXPECT_EQ(lst[2],3);
}

TEST(list_test_case, out_of_range_test)
{
  List<int> lst;
  lst.push_back(9);
  lst.push_back(8);
  lst.push_back(7);
  EXPECT_THROW ({for(int i = 0; i < 4;++i)   lst[i];},std::out_of_range);
}

TEST(list_test_case, index_minus_sign_test)
{
  List<int> lst;
  lst.push_back(9);
  EXPECT_THROW (lst[-1],std::out_of_range);
}

TEST(list_test_case, get_size_test)
{
  List<int> lst;
  lst.push_back(9);
  lst.push_back(8);
  lst.push_back(7);
  
  EXPECT_EQ(lst.GetSize(), 3);

}


int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}