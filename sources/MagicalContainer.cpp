#include "MagicalContainer.hpp"

using namespace ariel;

MagicalContainer::MagicalContainer()
{
}
void MagicalContainer::addElement(const int num) {}
int MagicalContainer::size() const
{
    return 1;
}
void MagicalContainer::removeElement(const int elem)
{
}


//AscendingIterator
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer con){
}
MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator &iter){
}
MagicalContainer::AscendingIterator::~AscendingIterator(){
}
MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator &iter){
    return *this;
}
bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator &iter) const{
    return true;
}
bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator &iter) const{
    return true;
}
bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator &iter) const{
    return true;
}
bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator &iter) const{
    return true;
}
int& MagicalContainer::AscendingIterator::operator*() {
    // Access the element in the container using the iterator's internal state
    return this->conainer->con[0];
}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++(){
    return *this;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){
    return *this;
}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end(){
    return *this;
}


//SideCrossIterator
MagicalContainer::SideCrossIterator::SideCrossIterator(MagicalContainer con){
}
MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator &iter){
}
MagicalContainer::SideCrossIterator::~SideCrossIterator(){
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator &iter){
    return *this;
}
bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator &iter) const{
    return true;
}
bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator &iter) const{
    return true;
}
bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator &iter) const{
    return true;
}
bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator &iter) const{
    return true;
}
int& MagicalContainer::SideCrossIterator::operator*(){
    return this->conainer->con[0];
}
MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++(){
    return *this;
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){
    return *this;
}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end(){
    return *this;
}


//PrimeIterator
MagicalContainer::PrimeIterator::PrimeIterator(MagicalContainer con){
}
MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator &iter){
}
MagicalContainer::PrimeIterator::~PrimeIterator(){
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator &iter){
    return *this;
}
bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator &iter) const{
    return true;
}
bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator &iter) const{
    return true;
}
bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator &iter) const{
    return true;
}
bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator &iter) const{
    return true;
}
int& MagicalContainer::PrimeIterator::operator*(){
    return this->conainer->con[0];
}
MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++(){
    return *this;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){
    return *this;
}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end(){
    return *this;
}

