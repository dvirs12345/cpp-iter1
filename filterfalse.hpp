// Author - Dvir Sadon


namespace itertools 
{
    template <typename FUNC, typename ff>
    class filterfalse 
    {

        ff data;
        FUNC func;

        public:

            filterfalse(FUNC f1,ff var) : data(var), func(f1) { }

            class iterator
            {
                typename ff::iterator iter;
                typename ff::iterator iter_end;
                FUNC iter_func;

                public:
                    /* Constructors */
                    iterator(typename ff::iterator iter, typename ff::iterator iter_end, FUNC iter_func): iter(iter), iter_end(iter_end), iter_func(iter_func)
                    {
                        while (iter != iter_end && iter_func(*iter))
                            ++iter;
                    };

                    iterator(iterator& other) = default;

                    /* Operators */
                    iterator& operator=(iterator& other) 
                    {
                        if (&other != this)
                            iterator(other.iter,other.iter_end,other.iter_func);
                        return *this;
                    }

                    iterator& operator++()
                    {
                        ++iter;
                        while (iter != iter_end && iter_func(*iter))
                            ++iter;
                        return *this;
                    }

                    iterator operator++(int)
                    {
                        iterator temp = *this;
                        ++(*this);
                        return temp;
                    }

                    bool operator==(iterator& other) 
                    {
                        return (iter == other._iter);
                    }

                    bool operator!=(iterator& other) 
                    {
                        return !(iter == other.iter);
                    }

                    auto operator*()
                    {
                        return *iter;
                    }
            };

            /* Begin and End for iterator */
            iterator begin()
            {
                return iterator(data.begin(), data.end(), func);
            }

            iterator end()
            {
                return iterator(data.end(), data.end(), func);
            }
    };
};