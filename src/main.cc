#include <iostream>
#include <format>
#include <fstream>
#include <string>
#include <optional>

#include "db.hpp"
#include "utils.hpp"

auto main(int argc, char *argv[]) -> int
{
    if (argc != 3)
    {
        std::cout << std::format("usage: {} <input_csv> <sequence>\n", argv[0]);
        std::exit(EXIT_FAILURE);
    }

    std::ifstream csvin(argv[1]);
    if (csvin.fail())
    {
        std::cerr << std::format("failed to open file \"{}\" for reading\n", argv[1]);
        std::exit(EXIT_FAILURE);
    }

    Db db;
    try
    {
        db = readDb(csvin);
    }
    catch (std::runtime_error &e)
    {
        std::cerr << std::format("{}: {}\n", argv[1], e.what());
        std::exit(EXIT_FAILURE);
    }
    catch (...)
    {
        std::cerr << std::format("unhandled exception wile reading \"{}\"\n", argv[1]);
        std::exit(EXIT_FAILURE);
    }

    std::ifstream sequencein(argv[2]);
    if (sequencein.fail())
    {
        std::cerr << std::format("failed to open file \"{}\" for reading\n", argv[2]);
        std::exit(EXIT_FAILURE);
    }

    std::string sequence;
    std::getline(sequencein, sequence);
    validateSequence(sequence);

    std::optional<std::string> match = db.findMatch(sequence);
    if (match)
        std::cout << *match << '\n';
    else
        std::cout << "No match\n";

    return EXIT_SUCCESS;
}
