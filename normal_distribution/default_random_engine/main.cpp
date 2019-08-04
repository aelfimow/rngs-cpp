#include <iostream>
#include <sstream>
#include <vector>
#include <random>

int main(int argc, char *argv[])
try
{
    if (argc != 3)
    {
        throw std::invalid_argument("Usage: maxSteps maxWords");
    }

    size_t maxSteps = 0;
    {
        std::stringstream ss { argv[1] };
        ss >> maxSteps;
    }

    std::cout << "Max. steps: " << maxSteps << std::endl;

    std::vector<size_t> data1(maxWords);

    for (size_t step = 0; step < maxSteps; ++step)
    {
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
