#include "day2.hpp"

std::string GetMatchCount(std::string const &s1, std::string const &s2, long &result) {
    std::string ret;
    for (int i = 0; i < s1.length(); i++)
        if (s2.at(i) == s1[i])
            ret.push_back(s1[i]);

    result = ret.length();
    return ret;
}

void Day2::Execute() {
    printf("-=-=-=-=-=Executing Day 2-=-=-=-=-=\n");
    std::filesystem::path path = "src/Day-2/10000.txt";

    std::ifstream fstr(path);
    std::stringstream strs;
    std::vector<std::string> input;

    if (!fstr) {
        printf("Bad input file!\n");
        return;
    }

    strs << fstr.rdbuf();

    std::string str;
    input.reserve(fstr.tellg());

    while (getline(strs, str))
        input.push_back(str);


    int three = 0;
    int two = 0;
    std::string partTwo;

    for (int x = 0; x < input.size(); x++) {
        bool hasThree = false;
        bool hasTwo = false;

        for (int p = 0; p < input.at(x).length(); p++) {
            long c = std::count(input.at(x).begin(), input.at(x).end(), input.at(x)[p]);
            hasTwo |= c == 2;
            hasThree |= c == 3;
        }
        two += hasTwo;
        three += hasThree;

        if(!partTwo.empty())
            continue;

        for (int y = x + 1; y < input.size(); y++) {
            std::string result;

            long matchCount = 0;
            result = GetMatchCount(input.at(x), input.at(y), matchCount);

            if (matchCount == input.at(x).length() - 1) {
                partTwo = result;
            }
        }
    }

    printf("Part 1: %i\n", three * two);
    printf("Part 2: %s\n", partTwo.c_str());
}
