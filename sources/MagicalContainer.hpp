#include <vector>

using namespace std;

namespace ariel
{
    class MagicalContainer
    {
    private:
        vector<int> con;

    public:
        MagicalContainer();
        void addElement(const int num);
        int size() const;
        void removeElement(const int elem);
        class AscendingIterator
        {
        public:
            AscendingIterator() = default;
            AscendingIterator(MagicalContainer con);
            AscendingIterator(const AscendingIterator &iter);
            ~AscendingIterator();
            AscendingIterator &operator=(const AscendingIterator &iter);
            bool operator==(const AscendingIterator &iter) const;
            bool operator!=(const AscendingIterator &iter) const;
            bool operator>(const AscendingIterator &iter) const;
            bool operator<(const AscendingIterator &iter) const;
            int &operator*();
            AscendingIterator &operator++();
            AscendingIterator begin();
            AscendingIterator end();

        private:
            MagicalContainer *conainer;
            size_t index;
        };
        class SideCrossIterator
        {
        public:
            SideCrossIterator() = default;
            SideCrossIterator(MagicalContainer con);
            SideCrossIterator(const SideCrossIterator &iter);
            ~SideCrossIterator();
            SideCrossIterator &operator=(const SideCrossIterator &iter);
            bool operator==(const SideCrossIterator &iter) const;
            bool operator!=(const SideCrossIterator &iter) const;
            bool operator>(const SideCrossIterator &iter) const;
            bool operator<(const SideCrossIterator &iter) const;
            int &operator*();
            SideCrossIterator &operator++();
            SideCrossIterator begin();
            SideCrossIterator end();

        private:
            MagicalContainer *conainer;
            size_t index;
        };
        class PrimeIterator
        {
        public:
            PrimeIterator() = default;
            PrimeIterator(MagicalContainer con);
            PrimeIterator(const PrimeIterator &iter);
            ~PrimeIterator();
            PrimeIterator &operator=(const PrimeIterator &iter);
            bool operator==(const PrimeIterator &iter) const;
            bool operator!=(const PrimeIterator &iter) const;
            bool operator>(const PrimeIterator &iter) const;
            bool operator<(const PrimeIterator &iter) const;
            int &operator*();
            PrimeIterator &operator++();
            PrimeIterator begin();
            PrimeIterator end();

        private:
            MagicalContainer *conainer;
            size_t index;
        };
    };
}
