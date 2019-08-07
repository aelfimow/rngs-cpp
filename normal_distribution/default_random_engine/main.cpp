#include <iostream>
#include <sstream>
#include <map>
#include <random>
#include <functional>

int main(int argc, char *argv[])
try
{
    if (argc != 2)
    {
        throw std::invalid_argument("Usage: maxNums");
    }

    size_t maxNums = 0;
    {
        std::stringstream ss { argv[1] };
        ss >> maxNums;
    }

    std::cout << "Max. numbers: " << maxNums << std::endl;


    auto rng = std::bind(std::normal_distribution<double>{}, std::default_random_engine{});

    std::map<ssize_t, size_t> histogram;

    for (size_t count = 0; count < maxNums; ++count)
    {
        ssize_t r = static_cast<ssize_t>(rng());
        ++histogram[r];
    }

    for (auto &h: histogram)
    {
        std::cout << h.first << ": " << h.second << std::endl;
    }

    return EXIT_SUCCESS;
}
catch (std::exception &exc)
{
    std::cerr << "Exception: " << exc.what() << std::endl;
    return EXIT_FAILURE;
}
catch (...)
{
    std::cerr << "Error: exception" << std::endl;
    return EXIT_FAILURE;
}
