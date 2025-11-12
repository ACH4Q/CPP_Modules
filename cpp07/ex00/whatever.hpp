#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template<typename T> void swap(T &x, T &y)
{
    T tmp;

    tmp = x;
    x = y;
    y = tmp;
}

template<typename Y> Y min(Y &x,Y &y)
{
    if (x < y)
        return x;
    else
        return y;
}

template<typename H> H max(H &x,H &y)
{
    if (x > y)
        return x;
    else
        return y;
}


#endif