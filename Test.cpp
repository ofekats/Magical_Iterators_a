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
    //remove element that doesnt exist- should throw
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
    //create with default, regular and copy costructors
    CHECK_NOTHROW(MagicalContainer::AscendingIterator());
    CHECK_NOTHROW(MagicalContainer::AscendingIterator asc_iter1(container));
    MagicalContainer::AscendingIterator asc_iter1(container);
    CHECK_NOTHROW(MagicalContainer::AscendingIterator asc_iter2(asc_iter1));
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
    MagicalContainer::AscendingIterator asc_iter2(container1);
    MagicalContainer::AscendingIterator asc_iter3(container2);
    //check if they equal
    CHECK(asc_iter1.operator==(asc_iter2));
    CHECK_THROWS(asc_iter1.operator==(asc_iter3));
    ++asc_iter1;
    CHECK(asc_iter1.operator==(asc_iter2) == false);
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
    CHECK(asc_iter1.operator==(asc_iter2));
    CHECK_THROWS(asc_iter1.operator==(asc_iter3));
    ++asc_iter1;
    CHECK(asc_iter1.operator==(asc_iter2) ==false);
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

TEST_CASE("AscendingIterator - operator>=")
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
    CHECK_NOTHROW(asc_iter1.operator>=(asc_iter2));
    CHECK(asc_iter1.operator>=(asc_iter2));
    ++asc_iter1;
    CHECK(asc_iter1.operator>=(asc_iter2));
    CHECK(asc_iter2.operator>=(asc_iter1) == false);
    CHECK_THROWS(asc_iter1.operator>=(asc_iter3));
    CHECK_THROWS(asc_iter3.operator>=(asc_iter2));
    CHECK_NOTHROW(asc_iter3.operator>=(asc_iter3));
}

TEST_CASE("AscendingIterator - operator<=")
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
    CHECK_NOTHROW(asc_iter1.operator>=(asc_iter2));
    CHECK(asc_iter1.operator<=(asc_iter2));
    ++asc_iter2;
    CHECK(asc_iter1.operator<=(asc_iter2));
    CHECK(asc_iter2.operator<=(asc_iter1) == false);
    CHECK_THROWS(asc_iter1.operator<=(asc_iter3));
    CHECK_THROWS(asc_iter3.operator<=(asc_iter2));
    CHECK_NOTHROW(asc_iter3.operator<=(asc_iter3));
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
    ++asc_iter1;
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
}

//SideCrossIterator
TEST_CASE("SideCrossIterator - constructors")
{
    //create SideCrossIterator
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(0);
    //create with default, regular and copy costructors
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator());
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator side_iter1(container));
    MagicalContainer::SideCrossIterator side_iter1(container);
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator side_iter2(side_iter1));
}

TEST_CASE("SideCrossIterator  - Assignment operator")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(0);
    //create SideCrossIterator 
    MagicalContainer::SideCrossIterator  side_iter1(container);
    //use Assignment operator
    CHECK_NOTHROW(MagicalContainer::SideCrossIterator side_iter2 = side_iter1);
}

TEST_CASE("SideCrossIterator  - Equality comparison (operator==)")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container2.addElement(0);
    //create 3 SideCrossIterator 
    MagicalContainer::SideCrossIterator side_iter1(container1);
    MagicalContainer::SideCrossIterator side_iter2(side_iter1);
    MagicalContainer::SideCrossIterator side_iter3(container2);
    //check if they equal
    CHECK(side_iter1.operator==(side_iter2));
    CHECK_THROWS(side_iter1.operator==(side_iter3));
    ++side_iter1;
    CHECK(side_iter1.operator==(side_iter2) == false);
}


TEST_CASE("SideCrossIterator  - Inequality comparison (operator!=)")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container2.addElement(0);
    //create 3 SideCrossIterator 
    MagicalContainer::SideCrossIterator side_iter1(container1);
    MagicalContainer::SideCrossIterator side_iter2(side_iter1);
    MagicalContainer::SideCrossIterator side_iter3(container2);
    //check if they not equal
    CHECK(side_iter1.operator==(side_iter2));
    //not the same container
    CHECK_THROWS(side_iter1.operator==(side_iter3));
    ++side_iter1;
    CHECK(side_iter1.operator==(side_iter2) == false);
}

TEST_CASE("SideCrossIterator  - operator>")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container1.addElement(1);
    container2.addElement(-17);
    //create 3 SideCrossIterator 
    MagicalContainer::SideCrossIterator side_iter1(container1);
    MagicalContainer::SideCrossIterator side_iter2(container1);
    MagicalContainer::SideCrossIterator side_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(side_iter1.operator>(side_iter2));
    CHECK(side_iter1.operator>(side_iter2) == false);
    ++side_iter1;
    CHECK(side_iter1.operator>(side_iter2));
    CHECK_THROWS(side_iter1.operator>(side_iter3));
    CHECK_THROWS(side_iter3.operator>(side_iter2));
    CHECK_NOTHROW(side_iter3.operator>(side_iter3));
}

TEST_CASE("SideCrossIterator  - operator<")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container1.addElement(1);
    container2.addElement(-17);
    //create 3 SideCrossIterator 
    MagicalContainer::SideCrossIterator side_iter1(container1);
    MagicalContainer::SideCrossIterator side_iter2(container1);
    MagicalContainer::SideCrossIterator side_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(side_iter1.operator>(side_iter2));
    CHECK(side_iter1.operator<(side_iter2) == false);
    ++side_iter2;
    CHECK(side_iter1.operator<(side_iter2));
    CHECK_THROWS(side_iter1.operator<(side_iter3));
    CHECK_THROWS(side_iter3.operator<(side_iter2));
    CHECK_NOTHROW(side_iter3.operator<(side_iter3));
}

TEST_CASE("SideCrossIterator - operator>=")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container1.addElement(1);
    container2.addElement(-17);
    //create 3 SideCrossIterator
    MagicalContainer::SideCrossIterator side_iter1(container1);
    MagicalContainer::SideCrossIterator side_iter2(container1);
    MagicalContainer::SideCrossIterator side_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(side_iter1.operator>=(side_iter2));
    CHECK(side_iter1.operator>=(side_iter2));
    ++side_iter1;
    CHECK(side_iter1.operator>=(side_iter2));
    CHECK(side_iter2.operator>=(side_iter1) == false);
    CHECK_THROWS(side_iter1.operator>=(side_iter3));
    CHECK_THROWS(side_iter3.operator>=(side_iter2));
    CHECK_NOTHROW(side_iter3.operator>=(side_iter3));
}

TEST_CASE("SideCrossIterator - operator<=")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(-17);
    container1.addElement(1);
    container2.addElement(-17);
    //create 3 SideCrossIterator
    MagicalContainer::SideCrossIterator side_iter1(container1);
    MagicalContainer::SideCrossIterator side_iter2(container1);
    MagicalContainer::SideCrossIterator side_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(side_iter1.operator<=(side_iter2));
    CHECK(side_iter1.operator<=(side_iter2));
    ++side_iter2;
    CHECK(side_iter1.operator<=(side_iter2));
    CHECK(side_iter2.operator<=(side_iter1) == false);
    CHECK_THROWS(side_iter1.operator<=(side_iter3));
    CHECK_THROWS(side_iter3.operator<=(side_iter2));
    CHECK_NOTHROW(side_iter3.operator<=(side_iter3));
}

TEST_CASE("SideCrossIterator  - Dereference operator (operator*)")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(1);
    container.addElement(17);
    //create SideCrossIterator 
    MagicalContainer::SideCrossIterator side_iter1(container);
    //check if they throw
    CHECK(*side_iter1 == -17);
    ++side_iter1;
    CHECK(*side_iter1 == 17);
    ++side_iter1;
    CHECK(*side_iter1 == 1);
}

TEST_CASE("SideCrossIterator  - Pre-increment operator (operator++)")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(17);
    //create SideCrossIterator 
    MagicalContainer::SideCrossIterator  side_iter1(container);
    //check if they throw
    CHECK_NOTHROW(++side_iter1);
    ++side_iter1;
    CHECK_THROWS(++side_iter1);
}

TEST_CASE("SideCrossIterator  - begin")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(17);
    container.addElement(-17);
    //create SideCrossIterator 
    MagicalContainer::SideCrossIterator  side_iter1(container);
    //check if they throw
    CHECK_NOTHROW(side_iter1.begin());
    CHECK(*side_iter1.begin() == -17);
}

TEST_CASE("SideCrossIterator  - end")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(17);
    container.addElement(-17);
    //create SideCrossIterator 
    MagicalContainer::SideCrossIterator  side_iter1(container);
    //check if they throw
    CHECK_NOTHROW(side_iter1.end());
}




//PrimeIterator

TEST_CASE("PrimeIterator - constructors")
{
    //create PrimeIterator
    MagicalContainer container;
    //add element
    container.addElement(-17);
    //create with default, regular and copy costructors
    CHECK_NOTHROW(MagicalContainer::PrimeIterator());
    CHECK_NOTHROW(MagicalContainer::PrimeIterator pri_iter1(container));
    MagicalContainer::PrimeIterator pri_iter1(container);
    CHECK_NOTHROW(MagicalContainer::PrimeIterator pri_iter2(pri_iter1));
}

TEST_CASE("PrimeIterator  - Assignment operator")
{
    //create MagicalContainer
    MagicalContainer container;
    //add element
    container.addElement(-17);
    //create PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container);
    //use Assignment operator
    CHECK_NOTHROW(MagicalContainer::PrimeIterator pri_iter2 = pri_iter1);
}

TEST_CASE("PrimeIterator  - Equality comparison (operator==)")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(17);
    container2.addElement(5);
    //create 3 PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container1);
    MagicalContainer::PrimeIterator pri_iter2(pri_iter1);
    MagicalContainer::PrimeIterator pri_iter3(container2);
    //check if they equal
    CHECK(pri_iter1.operator==(pri_iter2));
    CHECK_THROWS(pri_iter1.operator==(pri_iter3));
    ++pri_iter1;
    CHECK(pri_iter1.operator==(pri_iter2) == false);
}


TEST_CASE("PrimeIterator  - Inequality comparison (operator!=)")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(17);
    container2.addElement(5);
    //create 3 PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container1);
    MagicalContainer::PrimeIterator pri_iter2(pri_iter1);
    MagicalContainer::PrimeIterator pri_iter3(container2);
    //check if they not equal
    CHECK(pri_iter1.operator==(pri_iter2));
    //not the same container
    CHECK_THROWS(pri_iter1.operator==(pri_iter3));
    ++pri_iter1;
    CHECK(pri_iter1.operator==(pri_iter2) == false);
}

TEST_CASE("PrimeIterator  - operator>")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(17);
    container2.addElement(-17);
    //create 3 PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container1);
    MagicalContainer::PrimeIterator pri_iter2(container1);
    MagicalContainer::PrimeIterator pri_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(pri_iter1.operator>(pri_iter2));
    CHECK(pri_iter1.operator>(pri_iter2) == false);
    ++pri_iter1;
    CHECK(pri_iter1.operator>(pri_iter2));
    CHECK_THROWS(pri_iter1.operator>(pri_iter3));
    CHECK_THROWS(pri_iter3.operator>(pri_iter2));
    CHECK_NOTHROW(pri_iter3.operator>(pri_iter3));
}

TEST_CASE("PrimeIterator  - operator<")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(17);
    container2.addElement(-17);
    //create 3 PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container1);
    MagicalContainer::PrimeIterator pri_iter2(container1);
    MagicalContainer::PrimeIterator pri_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(pri_iter1.operator>(pri_iter2));
    CHECK(pri_iter1.operator<(pri_iter2) == false);
    ++pri_iter2;
    CHECK(pri_iter1.operator<(pri_iter2));
    CHECK_THROWS(pri_iter1.operator<(pri_iter3));
    CHECK_THROWS(pri_iter3.operator<(pri_iter2));
    CHECK_NOTHROW(pri_iter3.operator<(pri_iter3));
}

TEST_CASE("PrimeIterator - operator>=")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(17);
    container2.addElement(-17);
    //create 3 PrimeIterator
    MagicalContainer::PrimeIterator pri_iter1(container1);
    MagicalContainer::PrimeIterator pri_iter2(container1);
    MagicalContainer::PrimeIterator pri_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(pri_iter1.operator>=(pri_iter2));
    CHECK(pri_iter1.operator>=(pri_iter2));
    ++pri_iter1;
    CHECK(pri_iter1.operator>=(pri_iter2));
    CHECK(pri_iter2.operator>=(pri_iter1) == false);
    CHECK_THROWS(pri_iter1.operator>=(pri_iter3));
    CHECK_THROWS(pri_iter3.operator>=(pri_iter2));
    CHECK_NOTHROW(pri_iter3.operator>=(pri_iter3));
}

TEST_CASE("PrimeIterator - operator<=")
{
    //create 2 MagicalContainer
    MagicalContainer container1;
    MagicalContainer container2;
    //add elements
    container1.addElement(17);
    container2.addElement(-1);
    //create 3 PrimeIterator
    MagicalContainer::PrimeIterator pri_iter1(container1);
    MagicalContainer::PrimeIterator pri_iter2(container1);
    MagicalContainer::PrimeIterator pri_iter3(container2);
    //check if they throw
    CHECK_NOTHROW(pri_iter1.operator>=(pri_iter2));
    CHECK(pri_iter1.operator<=(pri_iter2));
    ++pri_iter2;
    CHECK(pri_iter1.operator<=(pri_iter2));
    CHECK(pri_iter2.operator<=(pri_iter1) == false);
    CHECK_THROWS(pri_iter1.operator<=(pri_iter3));
    CHECK_THROWS(pri_iter3.operator<=(pri_iter2));
    CHECK_NOTHROW(pri_iter3.operator<=(pri_iter3));
}

TEST_CASE("PrimeIterator  - Dereference operator (operator*)")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(11);
    container.addElement(4);
    container.addElement(17);
    //create PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container);
    //check if they throw
    CHECK(*pri_iter1 == 11);
    ++pri_iter1;
    CHECK(*pri_iter1 == 17);
    ++pri_iter1;
    //doesnt have more element because 4 not prime
    CHECK_THROWS(++pri_iter1);
}

TEST_CASE("PrimeIterator  - Pre-increment operator (operator++)")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(-17);
    container.addElement(17);
    //create PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container);
    //check if they throw
    CHECK_NOTHROW(++pri_iter1);
    CHECK_THROWS(++pri_iter1);
}

TEST_CASE("PrimeIterator  - begin")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(6);
    container.addElement(17);
    container.addElement(-17);
    //create PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container);
    //check if they throw
    CHECK_NOTHROW(pri_iter1.begin());
    //6 is not prime
    CHECK(*pri_iter1.begin() != 6);
    CHECK(*pri_iter1.begin() == 17);
}

TEST_CASE("PrimeIterator  - end")
{
    //create MagicalContainer
    MagicalContainer container;
    //add elements
    container.addElement(17);
    container.addElement(11);
    container.addElement(6);
    //create PrimeIterator 
    MagicalContainer::PrimeIterator pri_iter1(container);
    //check if they throw
    CHECK_NOTHROW(pri_iter1.end());
}