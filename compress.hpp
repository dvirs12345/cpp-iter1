// Author - Dvir Sadon


namespace itertools 
{
    template <typename VAC1, typename VAC2>
    class compress 
    {
        VAC1 data;
        VAC2 data_tf;

        public:

            compress(VAC1 var, VAC2 var1) : data(var), data_tf(var1) { }

            class iterator
            {
                typename VAC1::iterator iter;
                typename VAC1::iterator iter_end;
                typename VAC2::iterator iter_tf;

                public:
                    /* Constructors */
                    iterator(typename VAC1::iterator iter, typename VAC1::iterator iter_end, typename VAC2::iterator tf) : iter(iter), iter_end(iter_end), iter_tf(tf) 
                    {
                        while (!(iter == iter_end) && !(*iter_tf)) 
                        {
                            ++iter;
                            ++iter_tf;
                        }
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
                        while (iter != iter_end && !(*iter_tf)) 
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
                        return (iter == other.iter);
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
                return iterator(data.begin(), data.end(), data_tf.begin());
            }

            iterator end()
            {
                return iterator(data.end(), data.end(), data_tf.begin());
            }
    };

};