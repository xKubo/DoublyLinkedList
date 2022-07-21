// DoublyLinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

#define BOOST_TEST_MODULE DoublyLinkedList
#include <boost/test/included/unit_test.hpp>

#include "LinkedList.h"

using namespace std;
using namespace LinkedList;

struct OneList {};
struct AnotherList {};

struct CTest : 
    CLinkedListItem<CTest>,
    CLinkedListItem<CTest, OneList>,
    CLinkedListItem<CTest, AnotherList>
{
    CTest(int num = 0)
    {
        n = num;
    }

    int n;
};


BOOST_AUTO_TEST_SUITE(LinkedList_Basics)

BOOST_AUTO_TEST_CASE(DefaultList_IsEmpty)
{
    LinkedList::CLinkedList<CTest> Ts;
    BOOST_REQUIRE(Ts.empty());
}

BOOST_AUTO_TEST_CASE(MultipleInsert)
{
    CTest t;
    LinkedList::CLinkedList<CTest> Ts;
    Ts.Insert(&t);
    Ts.Insert(&t);
    BOOST_REQUIRE(IsInList(t));
    BOOST_REQUIRE(Ts.size() == 1);
}

BOOST_AUTO_TEST_CASE(MultipleRemove)
{
    CTest t;
    LinkedList::CLinkedList<CTest> Ts;
    Ts.Remove(&t);
    BOOST_REQUIRE(!IsInList(t));
    Ts.Remove(&t);
    BOOST_REQUIRE(!IsInList(t));
    BOOST_REQUIRE(Ts.size() == 0);
}


BOOST_AUTO_TEST_CASE(ListIsEmptyAfterInsertAndRemove)
{
    CTest t;
    LinkedList::CLinkedList<CTest> Ts;
    Ts.Insert(&t);
    Ts.Remove(&t);
    BOOST_REQUIRE(Ts.empty());
}

BOOST_AUTO_TEST_CASE(ListIsNotEmptyAfterInsert)
{
    CTest t;
    LinkedList::CLinkedList<CTest> Ts;
    Ts.Insert(&t);
    BOOST_REQUIRE(!Ts.empty());
}

using CListOne = CLinkedList<CTest, OneList>;
using CListTwo = CLinkedList<CTest, AnotherList>;

BOOST_AUTO_TEST_CASE(InsertIntoTwoDifferentLists)
{
    CTest t1(1);
    CListOne o1;
    CListTwo o2;
    o1.Insert(&t1);
    o2.Insert(&t1);
    BOOST_REQUIRE(!o1.empty());
    BOOST_REQUIRE(!o2.empty());
    o1.Remove(&t1);
    o2.Remove(&t1);
    BOOST_REQUIRE(o1.empty());
    BOOST_REQUIRE(o2.empty());

}

BOOST_AUTO_TEST_CASE(IterateOverEmptyList)
{
    LinkedList::CLinkedList<CTest> Ts;
    for (CTest& T : Ts)
    {

    }

    for (const CTest& T : Ts)
    {

    }
}

BOOST_AUTO_TEST_CASE(IterateOverList)
{
    LinkedList::CLinkedList<CTest> Ts;
    std::vector<CTest> Tests{ 1,2 };
    for (CTest& t : Tests)
    {
        Ts.Insert(&t);
    }

    std::vector<int> Nums;

    for (CTest& T : Ts)
    {
        Nums.push_back(T.n);
    }

    sort(Nums.begin(), Nums.end());

    bool test = Nums == std::vector<int>{ 1, 2 };
    BOOST_REQUIRE(test);

    for (CTest& t : Tests)
    {
        Ts.Remove(&t);
    }

    BOOST_REQUIRE(Ts.empty());
    
}

BOOST_AUTO_TEST_SUITE_END()