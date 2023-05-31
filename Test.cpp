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
    //remove element that doesnt exist
    CHECK_THROWS(container.removeElement(-17));
    CHECK_THROWS(container.removeElement(7));
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
    CHECK_NOTHROW(MagicalContainer::AscendingIterator());
    CHECK_NOTHROW(MagicalContainer::AscendingIterator asc_iter1(container));
    MagicalContainer::AscendingIterator asc_iter1(container);
    CHECK_NOTHROW(MagicalContainer::AscendingIterator asc_iter2(asc_iter1));
    MagicalContainer::AscendingIterator asc_iter2(asc_iter1);
    CHECK(asc_iter1 == asc_iter2);
}
//l