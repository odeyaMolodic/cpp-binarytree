#include <array>
#include "doctest.h"
#include "BinaryTree.hpp"

TEST_CASE("test"){

    ariel::BinaryTree<int> tree_of_ints;

    CHECK_NOTHROW(tree_of_ints.add_root(1));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 9));
    CHECK_NOTHROW(tree_of_ints.add_left(9, 4));
    CHECK_NOTHROW(tree_of_ints.add_right(9, 5));
    CHECK_NOTHROW(tree_of_ints.add_right(1, 3));
    CHECK_NOTHROW(tree_of_ints.add_left(1, 2));

    for (int i = 10; i < 100; i++) {
        CHECK_THROWS(tree_of_ints.add_right(10, 0));
        CHECK_THROWS(tree_of_ints.add_left(10, 0));
    }
    CHECK_THROWS(tree_of_ints.add_right(9, 0));

    std::array<int, 5> inorder_tree{4, 2, 5, 1, 3};
    std::array<int, 5> postorder_tree{4, 5, 2, 3, 1};
    std::array<int, 5> preorder_tree{1, 2, 4, 5, 3};

    unsigned long i = 0;
    for (auto it = tree_of_ints.begin_inorder(); it != tree_of_ints.end_inorder(); ++it){
        CHECK_EQ((*it), inorder_tree.at(i++));
    }

    i = 0;
    for (auto it = tree_of_ints.begin_postorder(); it != tree_of_ints.end_postorder(); ++it){
        CHECK_EQ((*it), postorder_tree.at(i++));
    }

    i = 0;
    for (auto it = tree_of_ints.begin_preorder(); it != tree_of_ints.end_preorder(); ++it){
        CHECK_EQ((*it), preorder_tree.at(i++));
    }

    ariel::BinaryTree<std::string> tree_of_strings;

    CHECK_NOTHROW(tree_of_strings.add_root("1"));
    CHECK_NOTHROW(tree_of_strings.add_left("1", "9"));
    CHECK_NOTHROW(tree_of_strings.add_left("9", "4"));
    CHECK_NOTHROW(tree_of_strings.add_right("9", "5"));
    CHECK_NOTHROW(tree_of_strings.add_right("1", "3"));
    CHECK_NOTHROW(tree_of_strings.add_left("1", "2"));

}