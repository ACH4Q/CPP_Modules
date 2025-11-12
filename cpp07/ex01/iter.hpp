#ifndef ITER_HPP
#define ITER_HPP

template<typename T>
void iter(T *addr, int len, void (*F)(T &))
{
    if (addr == NULL || F == NULL)
        return;
    for (int i = 0; i < len; i++) 
    {
        F(addr[i]);
    }
}

template<typename T>
void iter(const T *addr, int len, void (*F)(const T &))
{
    if (addr == NULL || F == NULL)
        return;
    for (int i = 0; i < len; i++)
    {
        F(addr[i]);
    }
}

#endif