#include <iostream>
#include <algorithm>
#include <chrono>
#include <fstream>
#include <time.h>

#define DUP(x) x x


int main()
{
    srand(time(0));
    auto  fout = std::ofstream("random.txt");
    auto  size = 1025;
    while (size < (1 << 19))
    {
        const auto volatile array = new int[size];
        for (auto j = 0; j < size; ++j)
            array[j] = rand() % size;
        auto l = 0;
        auto sz = size / 64 / 16;
        auto startTime = std::chrono::high_resolution_clock::now();
        for (auto i = 0; i < sz; ++i)
        DUP(DUP(DUP(DUP(DUP(DUP(l = array[l];))))));
        auto endTime = std::chrono::high_resolution_clock::now();
        fout << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count()
             << "  " << size << std::endl;
        std::cout << std::chrono::duration_cast<std::chrono::nanoseconds>(endTime - startTime).count()
                  << "  " << size << std::endl;
        delete[] array;
        size += 1024;
    }
    fout.close();
    return 0;
}
