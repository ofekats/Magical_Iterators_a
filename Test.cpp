#include "doctest.h"
#include "sources/MagicalContainer.hpp"

using namespace ariel;

TEST_CASE("MagicalContainer - addElement")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    CHECK_NOTHROW(container.addElement(17));
    //the same element twice
    CHECK_NOTHROW(container.addElement(17));
    //negative
    CHECK_NOTHROW(container.addElement(-17));
    //0
    CHECK_NOTHROW(container.addElement(0));
}

TEST_CASE("MagicalContainer - removeElement")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(0);
    //remove elements
    CHECK_NOTHROW(container.removeElement(-17));
    CHECK_NOTHROW(container.removeElement(0));
    //remove element that doesnt exist- should do nothing
    CHECK_NOTHROW(container.removeElement(-17));
    CHECK_NOTHROW(container.removeElement(7));
}

TEST_CASE("MagicalContainer - size")
{
    //create MagicalContainer
    MagicalContainer container;
    //size should be 0
    CHECK(container.size() == 0);
    //add element
    container.addElement(-17);
    //size should be 1
    CHECK(container.size() == 1);
    //remove element and add
    container.removeElement(-17);
    container.addElement(0);
    //size should be 1
    CHECK(container.size() == 1);
    //remove element
    container.removeElement(0);
    //size should be 0
    CHECK(container.size() == 0);
}

//AscendingIterator
TEST_CASE("AscendingIterator - constructors")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(0);
    //create with default, regular and copy costructors
    CHECK_NOTHROW(MagicalContainer::AscendingIterator());
    CHECK_NOTHROW(MagicalContainer::AscendingIterator asc_iter1(container));
    MagicalContainer::AscendingIterator asc_iter1(container);
    CHECK_NOTHROW(MagicalContainer::AscendingIterator asc_iter2(asc_iter1));
    MagicalContainer::AscendingIterator asc_iter2(asc_iter1);
    CHECK(asc_iter1 == asc_iter2);
}

TEST_CASE("AscendingIterator - Assignment operator")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(0);
    //create AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container);
    //use Assignment operator
    CHECK_NOTHROW(MagicalContainer::AscendingIterator asc_iter2 = asc_iter1);
    MagicalContainer::AscendingIterator asc_iter2 = asc_iter1;
    //should be equal
    CHECK(asc_iter1 == asc_iter2);
}

TEST_CASE("AscendingIterator - Equality comparison (operator==)")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container2.addElement(0);
    //create 3 AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container1);
    MagicalContainer::AscendingIterator asc_iter2(asc_iter1);
    MagicalContainer::AscendingIterator asc_iter3(container2);
    //check if they equal
    CHECK(asc_iter1.operator==(asc_iter2));
    CHECK(asc_iter1.operator==(asc_iter3) == false);
}


TEST_CASE("AscendingIterator - Inequality comparison (operator!=)")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container2.addElement(0);
    //create 3 AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container1);
    MagicalContainer::AscendingIterator asc_iter2(asc_iter1);
    MagicalContainer::AscendingIterator asc_iter3(container2);
    //check if they not equal
    CHECK(asc_iter1.operator!=(asc_iter2) == false);
    CHECK(asc_iter1.operator!=(asc_iter3));
}

TEST_CASE("AscendingIterator - operator>")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container2.addElement(-17);
    //create 3 AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container1);
    MagicalContainer::AscendingIterator asc_iter2(container1);
    MagicalContainer::AscendingIterator asc_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(asc_iter1.operator>(asc_iter2));
    CHECK(asc_iter1.operator>(asc_iter2) == false);
    ++asc_iter1;
    CHECK(asc_iter1.operator>(asc_iter2));
    CHECK_THROWS(asc_iter1.operator>(asc_iter3));
    CHECK_THROWS(asc_iter3.operator>(asc_iter2));
    CHECK_NOTHROW(asc_iter3.operator>(asc_iter3));
}

TEST_CASE("AscendingIterator - operator<")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container2.addElement(-17);
    //create 3 AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container1);
    MagicalContainer::AscendingIterator asc_iter2(container1);
    MagicalContainer::AscendingIterator asc_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(asc_iter1.operator>(asc_iter2));
    CHECK(asc_iter1.operator<(asc_iter2) == false);
    ++asc_iter2;
    CHECK(asc_iter1.operator<(asc_iter2));
    CHECK_THROWS(asc_iter1.operator<(asc_iter3));
    CHECK_THROWS(asc_iter3.operator<(asc_iter2));
    CHECK_NOTHROW(asc_iter3.operator<(asc_iter3));
}

TEST_CASE("AscendingIterator - Dereference operator (operator*)")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(17);
    //create AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container);
    //check if they throw
    CHECK(*asc_iter1 == -17);
    ++asc_iter1;
    CHECK(*asc_iter1 == 17);
}

TEST_CASE("AscendingIterator - Pre-increment operator (operator++)")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(17);
    //create AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container);
    //check if they throw
    CHECK_NOTHROW(++asc_iter1);
    CHECK_THROWS(++asc_iter1);
}

TEST_CASE("AscendingIterator - begin")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(17);
    container.addElement(-17);
    //create AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container);
    //check if they throw
    CHECK_NOTHROW(asc_iter1.begin());
    CHECK(*asc_iter1.begin() == -17);
}

TEST_CASE("AscendingIterator - end")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(17);
    container.addElement(-17);
    //create AscendingIterator
    MagicalContainer::AscendingIterator asc_iter1(container);
    //check if they throw
    CHECK_NOTHROW(asc_iter1.end());
    CHECK(*asc_iter1.end() == 17);
}