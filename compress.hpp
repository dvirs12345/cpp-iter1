// Author - Dvir Sadon


namespace itertools 
{
    template <typename VAC1, typename VAC2>
    class compress 
    {
        VAC1 data;
        VAC2 bool_data;

        public:
            compress(VAC1 x1, VAC2 x2) : data(x1), bool_data(x2) { }
            class iterator
            {
                typename VAC1::iterator _iter;
                typename VAC1::iterator _it_end;
                typename VAC2::iterator _bool_it;

                public:
                    iterator(typename VAC1::iterator it, typename VAC1::iterator end, typename VAC2::iterator _bool) : _iter(it), _it_end(end), _bool_it(_bool) 
                    {
                        while (_iter != _it_end && !(*_bool_it)) 
                        {
                            ++_iter;
                            ++_bool_it;
                        }
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
                        while (_iter != _it_end && !(*_bool_it)) 
                            ++_iter;
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

            iterator begin(){
                return iterator(data.begin(), data.end(), bool_data.begin());
            }
            iterator end(){
                return iterator(data.end(), data.end(), bool_data.begin());
            }


    };

};