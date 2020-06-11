// Author - Dvir Sadon


namespace itertools 
{
    template <typename FUNC, typename VAC>
    class filterfalse 
    {
        
        VAC data;
        FUNC func;

        public:

            filterfalse(FUNC f,VAC x) : data(x), func(f) { }
            class iterator
            {
                typename VAC::iterator _iter;
                typename VAC::iterator _it_end;
                FUNC _it_func;

                public:
                    explicit iterator(typename VAC::iterator it, typename VAC::iterator end, FUNC func): _iter(it), _it_end(end), _it_func(func)
                    {
                        while (_iter != _it_end && _it_func(*_iter))++_iter;
                    };

                    iterator(const iterator& other) = default;

                    iterator& operator=(const iterator& other) 
                    {
                        if (&other != this){
                            iterator(other._iter,other._it_end,other._it_func);
                        }
                        return *this;
                    }

                    iterator& operator++()
                    {
                        ++_iter;
                        while (_iter != _it_end && _it_func(*_iter)){
                            ++_iter;
                        }
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
                        return *_iter;
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