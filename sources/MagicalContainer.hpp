/* during the preparation of this assignment i got help from Roy Simanovich & chat GPT*/
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

namespace ariel
{

    class MagicalContainer
    {
    private:
        vector<int> elements;
        vector<int*> elementsSideCross;
        vector<int*> elementsPrime;

        static bool isPrime(int num);

    public:
        /* constructor & destructor: */
        MagicalContainer(){};

        /* METHODS: */
        void addElement(int element);

        void removeElement(int index);

        size_t size() const;

        vector<int>& getElements();

        /********************** Iterators - nested classes **********************/

        class Iterator
        {
            /* constuctor & destructor: */
        public:
            Iterator() = default;
			virtual ~Iterator() = default;
			Iterator(const Iterator& other) = default;
			Iterator(Iterator&& other) = default;

            virtual bool operator==(const Iterator &other) const = 0;

            virtual bool operator!=(const Iterator &other) const = 0;

            virtual bool operator>(const Iterator &other) const = 0;

            virtual bool operator<(const Iterator &other) const = 0;

            virtual int operator*() const = 0;
        };

        /* Ascending Iterator*/
        class AscendingIterator : public Iterator
        {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            /* constructors & destructor: */
            AscendingIterator(MagicalContainer& container, size_t index): container(container), index(index){} // main constructor
            AscendingIterator(MagicalContainer& container): container(container), index(0){}; //default constructor
            AscendingIterator(AscendingIterator& other): container(other.container), index(other.index){}; // deep copy constructor
            ~AscendingIterator() override = default; // default destructor



            /* METHODS: */
            AscendingIterator& operator=(const AscendingIterator& other);

            AscendingIterator& operator++();

            AscendingIterator begin();

            AscendingIterator end() const;

            /* OVERRIDE METHODS: */
            bool operator==(const Iterator &other) const override;

            bool operator!=(const Iterator &other) const override;

            bool operator>(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            bool operator==(const AscendingIterator &other) const;

            bool operator!=(const AscendingIterator &other) const;

            int operator*() const override;

        };

        /* Side Cross Iterator*/
        class SideCrossIterator : public Iterator
        {
        private:
            MagicalContainer& container;
            size_t index;

        public:
            
            /* constructors & destructor: */
            SideCrossIterator(MagicalContainer& container, size_t index): container(container), index(index){} // main constructor
            SideCrossIterator(MagicalContainer& container): container(container), index(0){}; //default constructor
            SideCrossIterator(SideCrossIterator& other): container(other.container), index(other.index){}; // deep copy constructor
            ~SideCrossIterator() override = default; // default destructor

            /* METHODS: */
            SideCrossIterator& operator=(const SideCrossIterator &other);

            SideCrossIterator& operator++();

            SideCrossIterator begin();

            SideCrossIterator end() const;

            /* OVERRIDE METHODS: */
            bool operator==(const Iterator &other) const override;

            bool operator!=(const Iterator &other) const override;

            bool operator>(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            bool operator==(const SideCrossIterator &other) const;

            bool operator!=(const SideCrossIterator &other) const;

            int operator*() const override;
        };

        /* Prime Iterator */
        class PrimeIterator : public Iterator
        {
        private:
            MagicalContainer& container;
            size_t index;

        public:

            /* constructor & destructor: */

            PrimeIterator(MagicalContainer& container, size_t index): container(container), index(index){} // main constructor
            PrimeIterator(MagicalContainer& container): container(container), index(0){}; // default constructor
            PrimeIterator(PrimeIterator& other): container(other.container), index(other.index){}; // deep copy constructor
            ~PrimeIterator() override = default; // default destructor
            
            /* METHODS: */
            PrimeIterator &operator=(const PrimeIterator &other);

            PrimeIterator& operator++();

            PrimeIterator begin();

            PrimeIterator end() const;

            /* OVERRIDE METHODS: */
            bool operator==(const Iterator &other) const override;

            bool operator!=(const Iterator &other) const override;

            bool operator>(const Iterator &other) const override;

            bool operator<(const Iterator &other) const override;

            bool operator==(const PrimeIterator &other) const;

            bool operator!=(const PrimeIterator &other) const;

            int operator*() const override;
        };
    };
}
