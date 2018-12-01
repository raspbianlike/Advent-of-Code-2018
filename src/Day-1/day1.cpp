#include "day1.hpp"

void Day1::Execute() {

    // load input into buffer

    std::filesystem::path p = "src/Day-1/input.txt";

    std::ifstream fstr(p);
    std::stringstream strs;
    std::vector<int> input;

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

    std::vector<int> freqs = {0};
    int frequency = 0;
    while (true) {
        for (auto &it : input) {
            frequency += it;

            if(std::find(freqs.begin(), freqs.end(), frequency) != freqs.end()) {
                printf("Part 2: %i\n", frequency);
                return;
            }

            freqs.push_back(frequency);
        }
    }
}
