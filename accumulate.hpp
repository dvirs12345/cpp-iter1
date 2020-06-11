// Author - Dvir Sadon


namespace itertools 
{
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

            accumulate(Acu x, FUNC f = Func1()) : data(x), func(f) { }
            class iterator
            {
                decltype (*(data.begin())) _it_data;
                typename Acu::iterator _iter;
                typename Acu::iterator _it_end;
                FUNC _it_func;

                public:

                    iterator(typename Acu::iterator it, typename Acu::iterator end, FUNC func): _iter(it), _it_end(end), _it_func(func), _it_data(*it){};
                    iterator(const iterator& other) = default;

                    iterator& operator=(const iterator& other) 
                    {
                        if (&other != this)
                            iterator(other._iter,other._it_end,other._it_func);
                        return *this;
                    }
                    iterator& operator++()
                    {
                        ++_iter;
                        if(_iter != _it_end)
                            _it_data = _it_func(_it_data, *_iter);
                        return *this;
                    }
                    iterator operator++(int)
                    {
                        iterator temp = *this;
                        ++(*this);
                        return temp;
                    }

                    bool operator==(const iterator& other) 
                    {
                        return (_iter == other._iter);
                    }

                    bool operator!=(const iterator& other) 
                    {
                        return (_iter != other._iter);
                    }

                    auto operator*()
                    {
                        return _it_data;
                    }
            };

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