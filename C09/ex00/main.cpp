#include "BitcoinExchange.hpp"

// Entry point: takes the input file as argument, loads the bitcoin price
// database (data.csv) and prints the converted value of each valid line.
int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    std::ifstream input(argv[1]);
    if (!input.is_open())
    {
        std::cerr << "Error: could not open file." << std::endl;
        return 1;
    }

    try
    {
        BitcoinExchange btc;
        std::string line;

        // skip the header line ("date | value")
        if (std::getline(input, line) && line != "date | value")
        {
            input.clear();
            input.seekg(0);
        }

        // each line is validated and printed on its own, so one bad line
        // doesn't stop the processing of the rest of the file
        while (std::getline(input, line))
        {
            try
            {
                btc.validFileLine(line);
            }
            catch (const std::exception &e)
            {
                std::cerr << "Error: " << e.what() << std::endl;
            }
        }
    }
    catch (const std::exception &e)
    {
        // data.csv could not be loaded
        std::cerr << "Error: " << e.what() << std::endl;
        return 1;
    }
    return 0;
}
