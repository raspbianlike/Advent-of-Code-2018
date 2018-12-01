#include "day1.hpp"

void Day1::Execute() {

    // load input into buffer

    std::filesystem::path p = "src/Day-1/input.txt";

    std::ifstream fstr(p);
    std::stringstream strs;
    std::vector<int> input;
    std::unordered_set<int> ipt;

    if (!fstr) {
        printf("Bad input file!\n");
        return;
    }

    strs << fstr.rdbuf();

    std::string str;

    int frequency1 = 0;

    while (getline(strs, str))
        input.push_back(std::stoi(str));

    for (auto &it : input)
        frequency1 += it;

    printf("Part 1: %i\n", frequency1);

    int frequency = 0;

    ssize_t prevSize = -1;

    while (true) {
        for (auto &it : input) {
            frequency += it;

            if (ipt.size() == prevSize) {
                printf("Part 2: %i\n", frequency);
                return;
            }
            prevSize = ipt.size();

            ipt.emplace(frequency);
        }
    }
}
