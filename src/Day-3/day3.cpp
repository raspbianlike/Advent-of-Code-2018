#include <map>
#include "day3.hpp"
#include <memory>

// Credit to ko1N for help on Part2

struct claim_t {
    int id = -1;
    int leftMargin = -1, topMargin = -1;
    int width = -1, height = -1;
};

void Day3::Execute() {
    printf("-=-=-=-=-=Executing Day 3-=-=-=-=-=\n");
    std::filesystem::path path = "src/Day-3/input.txt";

    std::ifstream fstr(path);
    std::stringstream strs;
    std::vector<std::string> input;

    if (!fstr) {
        printf("Bad input file!\n");
        return;
    }

    strs << fstr.rdbuf();

    std::string str;

    while (getline(strs, str))
        input.push_back(str);

    std::vector<claim_t> claims;

    for (auto &x : input) {
        int id = stoi(x.substr(1, x.rfind('@')));

        int leftMargin = stoi(x.substr(x.rfind('@') + 1, x.rfind(',')));

        int topMargin = stoi(x.substr(x.rfind(',') + 1, x.rfind(':')));

        int width = stoi(x.substr(x.rfind(':') + 1, x.rfind('x')));

        int height = stoi(x.substr(x.rfind('x') + 1, x.rfind('\n')));

        claim_t c{
                id,
                leftMargin,
                topMargin,
                width,
                height
        };

        claims.push_back(c);
    }

    int fabric[1000][1000] = {0};
    int overlap = 0;
    int intact = 0;

    for (auto &c : claims)
        for (int x = c.leftMargin; x < c.width + c.leftMargin; x++)
            for (int y = c.topMargin; y < c.height + c.topMargin; y++)
                if (fabric[x][y] != 0)
                    fabric[x][y] = -1;
                else
                    fabric[x][y] = 1;

    for (auto &x : fabric)
        for (int y : x)
            if (y == -1)
                overlap++;


    for (auto &c : claims) {
        bool valid = true;
        for (int x = c.leftMargin; x < c.width + c.leftMargin; x++)
            for (int y = c.topMargin; y < c.height + c.topMargin; y++)
                if (fabric[x][y] == -1)
                    valid = false;
        if (valid)
            intact = c.id;
    }

    printf("Part 1: %i\n", overlap);
    printf("Part 2: %i\n", intact);
}
