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

    int ar[1000][1000] = {0};


    for (auto &x : input) {
        int id = stoi(x.substr(1, x.rfind('@')));

        int posLeft = stoi(x.substr(x.rfind('@') + 1, x.rfind(',')));

        int posTop = stoi(x.substr(x.rfind(',') + 1, x.rfind(':')));


        int wide = stoi(x.substr(x.rfind(':') + 1, x.rfind('x')));


        int tall = stoi(x.substr(x.rfind('x') + 1, x.rfind('\n')));

        for (int i = 0; i < tall; i++) {
            //ar[posTOp+i][posLeft+i]++;
            for (int y = 0; y < wide; y++) {
                ar[posTop + i][posLeft + y] += 1;
                //mapa[id][posTOp + i][posLeft + y]++;
                //printf("incrementing\n");
            }
        }

    }
    int overlap = 0;
    int intact = 0;
    printf("r");
        for (size_t x = 0; x < 1000; ++x)
            for (size_t y = 0; y < 1000; ++y) {
                if (ar[x][y] > 1) {
                    overlap++;
                    //printf("%i, %i\n", x, ar[x][y]);
                }
                if (ar[x][y] == 0) {
                    //printf("intact\n");
                    intact = x;
                }
            }

    /*for(auto c : mapa) {
        for (auto &x : c.second) {
            for (int y : x) {
                if (y == 1)
                    intact = c.first;
                printf("y: %i, x: %i, id: %i\n", y,x, c.first);
            }
        }
    }*/
    printf("overlap : %i\n", overlap);
    printf("id : %i\n", intact);

}