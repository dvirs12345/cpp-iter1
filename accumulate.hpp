// Author - Dvir Sadon


namespace itertools 
{
    /* default function for accumliation */
    typedef struct 
    {
        template<typename T>
        T operator()(T a, T b) const 
        {
            return a+b;
        }
    }Func1;

    template <typename Acu, typename FUNC = Func1>
    class accumulate 
    {
        Acu data;
        FUNC func;

        public:

            accumulate(Acu var, FUNC fun = Func1()) : data(var), func(fun) { }
            class iterator
            {
                decltype (*(data.begin())) iter_data;
                typename Acu::iterator iter;
                typename Acu::iterator iter_end;
                FUNC iter_func;

                public:

                    /* Constructors */
                    iterator(typename Acu::iterator iter, typename Acu::iterator iter_end, FUNC my_func): iter(iter), iter_end(iter_end), iter_func(my_func), iter_data(*iter){};
                    iterator(const iterator& other) = default;

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
                        if(iter != iter_end)
                            iter_data = iter_func(iter_data, *iter);
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
                        return (iter == other.iter);
                    }

                    bool operator!=(iterator& other) 
                    {
                        return !(iter == other.iter);
                    }

                    auto operator*()
                    {
                        return this->iter_data;
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