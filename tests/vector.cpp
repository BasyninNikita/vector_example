#include <catch.hpp>
#include <sstream>

#include "vector.hpp"

TEST_CASE("creating tree")
{
	tree_t<int> tree;
	REQUIRE(tree.root()==nullptr);
}

TEST_CASE("add")
{
	tree_t<int> tree;
	tree.insert(2);
	tree.insert(1);
	tree.insert(3);
	tree.insert(4);
	std::string output {
	        "------4\n"
		"---3\n"
		"2\n"
		"---1\n"
	};
	std::ostringstream ostream;
	tree.print(ostream,0,tree.root());
	REQUIRE( ostream.str() == output );
}

TEST_CASE("?")
{
	tree_t<int> tree;
	tree.insert(1);
	tree.insert(2);
	tree.insert(3);
	tree.insert(4);
	tree.insert(5);
	REQUIRE( tree.find(6)==false );
	REQUIRE( tree.find(2)==true );
}


TEST_CASE("op+?")
{
	tree_t<int> tree;
	tree.oper1('+',2);
	tree.oper1('+',1);
	tree.oper1('+',3);
	std::string output{
		"---3\n"
		"2\n"
		"---1"
	};
	std::ostringstream ostream;
	tree.oper2('?',2,ostream);
	REQUIRE( ostream.str()== "true" );
	std::ostringstream ostream1;
	tree.oper2('?',5,ostream1);
	REQUIRE( ostream1.str()== "false" );
}
TEST_CASE("op+=")
{
	tree_t<int> tree;
	tree.oper1('+',2);
	tree.oper1('+',1);
	tree.oper1('+',3);
	std::string output{
		"---3\n"
		"2\n"
		"---1\n"
	};
	std::ostringstream ostream;
	tree.oper2('=',0,ostream);
	REQUIRE( ostream.str()== output );
}
TEST_CASE("ravenstvo")
{
	tree_t<int> tree1;
	tree_t<int> tree2;
	tree_t<int> tree3;
	tree1.oper1('+',2);
	tree1.oper1('+',1);
	tree1.oper1('+',3);
	tree2.oper1('+',2);
	tree2.oper1('+',1);
	tree2.oper1('+',3);
	tree3.oper1('+',5);
	tree3.oper1('+',2);
	tree3.oper1('+',7);
	REQUIRE(tree1==tree2);
	REQUIRE(!(tree1==tree3));
}
TEST_CASE("deleting")
{
    	tree_t<int> tree{4, 5, 3, 2, 6, 11, 8, 9};
    	tree.remove(6);
    	std::string result1{"------11\n"
	                    "------------9\n"
                            "---------8\n"
                            "---5\n"
                            "4\n"
                            "---3\n"
                            "------2\n"};
	    std::ostringstream ostream1;
	    tree.oper2('=',0,ostream1);
	    REQUIRE( ostream1.str() == result1 ); 
	    tree.remove(2);
    	    std::string result2{"------11\n"
	                        "------------9\n"
                                "---------8\n"
                            	"---5\n"
                            	"4\n"
                            	"---3\n"};
	    std::ostringstream ostream2;
	    tree.oper2('=',0,ostream2);
	    REQUIRE( ostream2.str() == result2 );
}
SCENARIO("BST delete non inserted element", "[delete]") {
    BinarySearchTree<int> tree = {8};
    REQUIRE( !tree.remove(4) );
    REQUIRE( !tree.isEmpty() );
}
//                +----+
//                |-08-|                                               *
//                +----+
//
//
//                                          08
//                                         ---->
SCENARIO("BST delete root without children", "[delete]") {
    BinarySearchTree<int> tree = {8};
    REQUIRE( tree.remove(8) );
    REQUIRE( tree.isEmpty() );
}
//                +----+                                              +----+
//                |-08-|                                              | 04 |
//                +----+                                              +----+
//                  /                                                   /
//                 /                                                   /
//           +----+                                              +----+
//           | 04 |                                              | 03 |
//           +----+                                              +----+
//             /
//            /
//      +----+                              08
//      | 03 |                             ---->
//      +----+
SCENARIO("BST delete root with one child", "[delete]") {
    BinarySearchTree<int> tree = {8, 4, 3};
    REQUIRE( tree.remove(8) );
    REQUIRE( tree == BinarySearchTree<int>({4, 3}) );
}
//                +----+                                              +----+
//                |-08-|                                              | 09 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /          \
//            /         /  \                                      /            \
//      +----+    +----+    +----+          08              +----+              +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |              | 13 |
//      +----+    +----+    +----+                          +----+              +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete root with children", "[delete]") {
    BinarySearchTree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
    REQUIRE( tree.remove(8) );
    REQUIRE( tree == BinarySearchTree<int>({9, 4, 3, 10, 13, 11, 12}) );
}
//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                                  /\
//            /         /  \                                                /  \
//      +----+    +----+    +----+          03                        +----+    +----+
//      |-03-|    | 09 |    | 13 |         ---->                      | 09 |    | 13 |
//      +----+    +----+    +----+                                    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 11 |
//                     +----+                                              +----+
//                        \                                                   \
//                         \                                                   \
//                          +----+                                              +----+
//                          | 12 |                                              | 12 |
//                          +----+                                              +----+
SCENARIO("BST delete non root without children", "[delete]") {
    BinarySearchTree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
    REQUIRE( tree.remove(3) );
    REQUIRE( tree == BinarySearchTree<int>({8, 4, 10, 9, 13, 11, 12}) );
}
//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    | 10 |                                    | 04 |    | 10 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          11              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     |-11-|                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with one child", "[delete]") {
    BinarySearchTree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
    REQUIRE( tree.remove(11) );
    REQUIRE( tree == BinarySearchTree<int>({8, 4, 3, 10, 9, 13, 12}) );
}
//                +----+                                              +----+
//                | 08 |                                              | 08 |
//                +----+                                              +----+
//                  /\                                                  /\
//                 /  \                                                /  \
//           +----+    +----+                                    +----+    +----+
//           | 04 |    |-10-|                                    | 04 |    | 11 |
//           +----+    +----+                                    +----+    +----+
//             /         /\                                        /         /\
//            /         /  \                                      /         /  \
//      +----+    +----+    +----+          10              +----+    +----+    +----+
//      | 03 |    | 09 |    | 13 |         ---->            | 03 |    | 09 |    | 13 |
//      +----+    +----+    +----+                          +----+    +----+    +----+
//                            /                                                   /
//                           /                                                   /
//                     +----+                                              +----+
//                     | 11 |                                              | 12 |
//                     +----+                                              +----+
//                        \
//                         \
//                          +----+
//                          | 12 |
//                          +----+
SCENARIO("BST delete non root with children", "[delete]") {
    BinarySearchTree<int> tree = {8, 4, 3, 10, 9, 13, 11, 12};
    REQUIRE( tree.remove(10) );
    REQUIRE( tree == BinarySearchTree<int>({8, 4, 3, 11, 9, 13, 12}) );
}
