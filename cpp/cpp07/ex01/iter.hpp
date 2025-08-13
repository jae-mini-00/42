#ifndef  ITER_HPP
#define ITER_HPP

template <typename T>
void iter(T arr[], std::size_t len, void(*function)(const T&))
{
    for (std::size_t i = 0; i < len; i++)
        function(arr[i]);
}

#endif