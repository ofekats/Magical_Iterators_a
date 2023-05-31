// MagicalContainer.cpp

#include "MagicalContainer.hpp"

namespace ariel {

// Implementation of MagicalContainer methods

MagicalContainer::MagicalContainer() {}

MagicalContainer::~MagicalContainer() {}

void MagicalContainer::addElement(int element) {
    elements.push_back(element);
}

void MagicalContainer::removeElement(int element) {
    for (auto it = elements.begin(); it != elements.end(); ++it) {
        if (*it == element) {
            elements.erase(it);
            break;
        }
    }
}

int MagicalContainer::size() const {
    return elements.size();
}

// Implementation of AscendingIterator methods

MagicalContainer::AscendingIterator::AscendingIterator()
    : container(nullptr), position(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const MagicalContainer& container)
    : container(&container), position(0) {}

MagicalContainer::AscendingIterator::AscendingIterator(const AscendingIterator& other)
    : container(other.container), position(other.position) {}

MagicalContainer::AscendingIterator::~AscendingIterator() {}

MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator=(const AscendingIterator& other) {
    if (this != &other) {
        container = other.container;
        position = other.position;
    }
    return *this;
}

bool MagicalContainer::AscendingIterator::operator==(const AscendingIterator& other) const {
    return (container == other.container) && (position == other.position);
}

bool MagicalContainer::AscendingIterator::operator!=(const AscendingIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::AscendingIterator::operator>(const AscendingIterator& other) const {
    return (container == other.container) && (position > other.position);
}

bool MagicalContainer::AscendingIterator::operator<(const AscendingIterator& other) const {
    return (container == other.container) && (position < other.position);
}

bool MagicalContainer::AscendingIterator::operator>=(const AscendingIterator& other) const {
    return !(*this < other);
}

bool MagicalContainer::AscendingIterator::operator<=(const AscendingIterator& other) const {
    return !(*this > other);
}

int MagicalContainer::AscendingIterator::operator*() const {
    return container->elements[position];
}

typename MagicalContainer::AscendingIterator& MagicalContainer::AscendingIterator::operator++() {
    ++position;
    return *this;
}

typename MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin() {
    return AscendingIterator(*container);
}

typename MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {
    AscendingIterator iter(*container);
    iter.position = container->elements.size();
    return iter;
}

MagicalContainer::SideCrossIterator::SideCrossIterator()
    : container(nullptr), position(0), reverse(false) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const MagicalContainer& container)
    : container(&container), position(0), reverse(false) {}

MagicalContainer::SideCrossIterator::SideCrossIterator(const SideCrossIterator& other)
    : container(other.container), position(other.position), reverse(other.reverse) {}

MagicalContainer::SideCrossIterator::~SideCrossIterator() {}

MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator=(const SideCrossIterator& other) {
    if (this != &other) {
        container = other.container;
        position = other.position;
        reverse = other.reverse;
    }
    return *this;
}

bool MagicalContainer::SideCrossIterator::operator==(const SideCrossIterator& other) const {
    return (container == other.container) && (position == other.position) && (reverse == other.reverse);
}

bool MagicalContainer::SideCrossIterator::operator!=(const SideCrossIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::SideCrossIterator::operator>(const SideCrossIterator& other) const {
    return (container == other.container) && (position > other.position) && (reverse == other.reverse);
}

bool MagicalContainer::SideCrossIterator::operator<(const SideCrossIterator& other) const {
    return (container == other.container) && (position < other.position) && (reverse == other.reverse);
}

bool MagicalContainer::SideCrossIterator::operator>=(const SideCrossIterator& other) const {
    return !(*this < other);
}

bool MagicalContainer::SideCrossIterator::operator<=(const SideCrossIterator& other) const {
    return !(*this > other);
}

int MagicalContainer::SideCrossIterator::operator*() const {
    if (reverse) {
        return container->elements[container->elements.size() - 1 - position];
    } else {
        return container->elements[position];
    }
}

typename MagicalContainer::SideCrossIterator& MagicalContainer::SideCrossIterator::operator++() {
    if (reverse) {
        --position;
    } else {
        ++position;
    }
    return *this;
}

typename MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin() {
    return SideCrossIterator(*container);
}

typename MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {
    SideCrossIterator iter(*container);
    iter.position = container->elements.size();
    return iter;
}

MagicalContainer::PrimeIterator::PrimeIterator()
    : container(nullptr), position(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const MagicalContainer& container)
    : container(&container), position(0) {}

MagicalContainer::PrimeIterator::PrimeIterator(const PrimeIterator& other)
    : container(other.container), position(other.position) {}

MagicalContainer::PrimeIterator::~PrimeIterator() {}

MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator=(const PrimeIterator& other) {
    if (this != &other) {
        container = other.container;
        position = other.position;
    }
    return *this;
}

bool MagicalContainer::PrimeIterator::operator==(const PrimeIterator& other) const {
    return (container == other.container) && (position == other.position);
}

bool MagicalContainer::PrimeIterator::operator!=(const PrimeIterator& other) const {
    return !(*this == other);
}

bool MagicalContainer::PrimeIterator::operator>(const PrimeIterator& other) const {
    return (container == other.container) && (position > other.position);
}

bool MagicalContainer::PrimeIterator::operator<(const PrimeIterator& other) const {
    return (container == other.container) && (position < other.position);
}

bool MagicalContainer::PrimeIterator::operator>=(const PrimeIterator& other) const {
    return !(*this < other);
}

bool MagicalContainer::PrimeIterator::operator<=(const PrimeIterator& other) const {
    return !(*this > other);
}

int MagicalContainer::PrimeIterator::operator*() const {
    return container->elements[position];
}

typename MagicalContainer::PrimeIterator& MagicalContainer::PrimeIterator::operator++() {
    ++position;
    return *this;
}

typename MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin() {
    return PrimeIterator(*container);
}

typename MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {
    PrimeIterator iter(*container);
    iter.position = container->elements.size();
    return iter;
}

} // namespace ariel