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
    CTest(int num)
    {
        n = num;
    }

    int n;
};

vector<CTest> Tests = { 1,2,3,4,5,6,7 };


BOOST_AUTO_TEST_SUITE(LinkedList_Basics)

BOOST_AUTO_TEST_CASE(DefaultList_IsEmpty)
{
    LinkedList::CLinkedList<CTest> Ts;
    BOOST_REQUIRE(Ts.empty());
}


BOOST_AUTO_TEST_CASE(ListIsEmptyAfterInsertAndRemove)
{
    LinkedList::CLinkedList<CTest> Ts;
    Ts.Insert(&Tests[2]);
    Ts.Remove(&Tests[2]);
    BOOST_REQUIRE(Ts.empty());
}

BOOST_AUTO_TEST_CASE(ListIsNotEmptyAfterInsert)
{
    LinkedList::CLinkedList<CTest> Ts;
    Ts.Insert(&Tests[2]);
    BOOST_REQUIRE(!Ts.empty());
}

using CListOne = CLinkedList<CTest, OneList>;
using CListTwo = CLinkedList<CTest, AnotherList>;

BOOST_AUTO_TEST_CASE(InsertIntoTwoDifferentLists)
{
    CListOne o1;
    CListTwo o2;
    o1.Insert(&Tests[2]);
    o2.Insert(&Tests[3]);
    BOOST_REQUIRE(!o1.empty());
    BOOST_REQUIRE(!o2.empty());
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


BOOST_AUTO_TEST_SUITE_END()