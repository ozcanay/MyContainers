#include "gtest/gtest.h"

#include "MyArray.h"
#include "MyVector.h"

/*
 * std::map is a sorted associative container that contains key-value pairs with unique keys.
 * Keys are sorted by using the comparison function
 * Compare. Search, removal, and insertion operations have logarithmic complexity.
 * Maps are usually implemented as red-black trees.
 * Red–black tree is a kind of self-balancing binary search tree.
 * Each node stores an extra bit representing "color" ("red" or "black"), used to ensure that the tree remains balanced during insertions and deletions.
 * When the tree is modified, the new tree is rearranged and "repainted" to restore the coloring properties that constrain how unbalanced the tree can become in the worst case.
 * The properties are designed such that this rearranging and recoloring can be performed efficiently.
 */

TEST(MyArrayTestSuite, MyArrayTests)
{
    constexpr int array_size = 10;
    MyArray<int, array_size> my_array;
    ASSERT_EQ(my_array.size(), 10);

    for(std::size_t i = 0; i < my_array.size(); ++i) {
        my_array[i] = static_cast<int>(i);
    }

    for(std::size_t i = 0; i < my_array.size(); ++i) {
        ASSERT_EQ(my_array[i], static_cast<int>(i));
    }

    /// test iterators.
    int counter = 0;
    for(const auto val : my_array) {
        ASSERT_EQ(val, counter++);
    }

    counter = 0;
    for(auto val : my_array) {
        ASSERT_EQ(val, counter++);
    }

    ASSERT_EQ(my_array.front(), 0);
//    ASSERT_EQ(my_array.back(), my_array.size() - 1);

}

TEST(MyVectorTestSuite, MyVectorTests)
{
    MyVector<int> m;
    m.push_back(1);
    m.push_back(2);
    m.push_back(3);
    m.push_back(4);

    ASSERT_EQ(m[0], 1);
    ASSERT_EQ(m[1], 2);
    ASSERT_EQ(m[2], 3);
    ASSERT_EQ(m[3], 4);
}
