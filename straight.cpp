#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>

#define DUP(x) x x


int main()
{
    auto  fout = std::ofstream("straight.txt");
    auto  size = 1025;
    while (size < (1 << 19))
    {
        const auto volatile array = new int[size];
        for (auto j = 0; j < size - 1; ++j)
            array[j] = j + 1;
        array[size - 1] = 0;
        auto l = 0;
        auto sz = size / 64 / 16;
        auto startTime = std::chrono::high_resolution_clock::now();
        for (auto i = 0; i < sz; ++i)
            DUP(DUP(DUP(DUP(DUP(DUP(l = array[l];))))));
        auto endTime = std::chrono::high_resolution_clock::now();
        auto delta = std::chrono::duration_cast<std::chrono::
                nanoseconds>(endTime - startTime).count();
        fout << delta << "  " << size << std::endl;
        std::cout << delta << "  " << size << std::endl;
        delete[] array;
        size += 1024;
    }
    fout.close();
    return 0;
}
