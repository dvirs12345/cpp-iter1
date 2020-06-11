// Author - Dvir Sadon

#include <iterator>

namespace itertools
{
    class range
    {
        public:
            int first;
            int last;

            /* Constructors */
            range(int first, int last){ this->first = first; this->last = last; }

            /* Iterator */
            class iterator // inspireed by https://www.artificialworlds.net/blog/2017/05/11/c-iterator-example-and-an-iterable-range/
            {
                private:
                    int value;

                    class intholder
                    {
                        int value;
                        public:
                            intholder(int value) { this->value = value; }

                            int operator*() { return value; }
                    };

                public:
                    typedef int value_type;
                    typedef std::ptrdiff_t difference_type;
                    typedef int *pointer;
                    typedef int &reference;
                    typedef std::input_iterator_tag iterator_category;

                    iterator(int value) { this->value = value; }

                    int operator*() const { return value; }

                    bool operator==(const iterator &other) const { return value == other.value; }

                    bool operator!=(const iterator &other) const { return !(*this == other); }

                    intholder operator++(int)
                    {
                        intholder ret(value);
                        ++*this;
                        return ret;
                    }

                    iterator &operator++()
                    {
                        ++value;
                        return *this;
                    }
            };
            iterator begin() { return iterator(first); }

            iterator end() { return iterator(last); }

            typedef int	value_type;
    };
}