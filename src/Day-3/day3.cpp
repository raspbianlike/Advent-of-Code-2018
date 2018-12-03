#include <map>
#include "day3.hpp"
#include <memory>

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

    //int ar[1000][1000] = {0};
    std::map<int, std::array<std::array<int, 1000>, 1000>> mapa = {{0, std::array<std::array<int, 1000>, 1000>{0}}};

    for (auto &x : input) {
        int id = stoi(x.substr(1, x.rfind('@')));

        int posLeft = stoi(x.substr(x.rfind('@') + 1, x.rfind(',')));

        int posTop = stoi(x.substr(x.rfind(',') + 1, x.rfind(':')));

        int wide = stoi(x.substr(x.rfind(':') + 1, x.rfind('x')));

        int tall = stoi(x.substr(x.rfind('x') + 1, x.rfind('\n')));

        for (int i = 0; i < tall; i++)
            for (int y = 0; y < wide; y++)
                mapa[id][posTop + i][posLeft + y]++;
    }

    int overlap = 0;
    int intact = 0;

    for (auto c : mapa) {
        for (auto &x : c.second) {
            bool valid = true;
            for (int y = 0; y < 1000; y++) {
                if (x[y] == 1)
                    intact = c.first;
                if (x[y] > 1) {
                    valid = false;
                    overlap++;
                }
            }
            if(valid)
                intact = c.first;
        }
    }
    printf("overlap : %i\n", overlap);
    printf("id : %i\n", intact);

}
