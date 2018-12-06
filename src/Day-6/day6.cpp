#include <map>
#include <climits>
#include <iostream>
#include "day6.hpp"

void Day6::Execute() {
    printf("-=-=-=-=-=Executing Day 6-=-=-=-=-=\n");
    std::filesystem::path path = "src/Day-6/input.txt";

    std::ifstream fstr(path);
    std::stringstream strs;

    std::vector<std::string> input;
    std::vector<std::pair<int, int>> vals;


    if (!fstr) {
        printf("Bad input file!\n");
        return;
    }

    strs << fstr.rdbuf();

    std::string str;

    while (getline(strs, str))
        input.push_back(str);

    int biggestCoordinate = 0;
    int biggestx = 0;
    for (auto &p : input) {
        int x = stoi(p.substr(0, p.rfind(',')));
        int y = stoi(p.substr(p.rfind(',') + 1, p.rfind('\n')));
            if(y > biggestCoordinate)
                biggestCoordinate = y;
            if(x > biggestCoordinate)
                biggestCoordinate = x;

        vals.push_back(std::make_pair(x, y));
    }
    std::map<int, int> ids;

    int gridSize = biggestCoordinate;
    int index = 0;
    int resultDistance = 0;
    for (int x = -gridSize; x < gridSize; x++) { // grid loop 1
        for (int y = -gridSize; y < gridSize; y++) { // grid loop 2
            int totalDist = 0;
            int min = INT_MAX;
            bool isSmaller = false;
            for (int i = 0; i < vals.size(); i++) { // loop over input to get grid data
                int dist = abs(vals[i].first - x) + abs(vals[i].second - y);
                totalDist += dist;
                if (dist < min) {
                    //printf("Distance: %i\n",dist);
                    min = dist;
                    index = i;
                    isSmaller = true;
                } else if (dist == min)
                    isSmaller = false;
            }
            if(totalDist < 10000)
                resultDistance++;

            if (isSmaller)
                ids[index]++;
        }
    }
    std::vector<std::pair<int, int>> results;
    for (auto c : ids)
        results.push_back(std::make_pair(c.first, c.second));

    std::sort(results.begin(), results.end(), [](const std::pair<int, int> a, std::pair<int, int> b) -> bool { return a.second < b.second; });

    int max = 0;

    for (int v = 1; v < results.size() - 1; v++) {
        if (results.at(v).second +  results.at(v - 1).second < results.at(v + 1).second) {
            max = results.at(v).second;
            break;
        }
    }

    printf("Part 1: %i\n", max);
    printf("Part 2: %i\n", resultDistance);

}
