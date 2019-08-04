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
        throw std::invalid_argument("Usage: maxSteps");
    }

    size_t maxSteps = 0;
    {
        std::stringstream ss { argv[1] };
        ss >> maxSteps;
    }

    std::cout << "Max. steps: " << maxSteps << std::endl;


    auto rng = std::bind(std::uniform_int_distribution<>(1, 10), std::default_random_engine{});

    std::map<size_t, size_t> histogram;

    for (size_t step = 0; step < maxSteps; ++step)
    {
        auto r = rng();
        ++histogram[r];
    }

    for (auto it = histogram.begin(); it != histogram.end(); ++it)
    {
        std::cout << it->first << ": " << it->second << std::endl;
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
