#include "day2.hpp"

std::string GetMatchCount(std::string s1, std::string s2, long &result) {
    std::string ret;
    for (int i = 0; i < s1.length(); i++)
        if (s2.at(i) == s1[i])
            ret.push_back(s1[i]);

    result = ret.length();
    return ret;
}

void Day2::Execute() {
    std::filesystem::path path = "src/Day-2/input.txt";

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

    int three = 0;
    int two = 0;
    for (auto &x : input) {
        std::vector<std::string> tmp;
        for (unsigned long i = 0; i < x.length(); i++) {
            tmp.push_back(x.substr(i, 1));
        }

        bool hasThree = false;
        bool hasTwo = false;

        for (auto &p : tmp) {
            long c = std::count(tmp.begin(), tmp.end(), p);
            hasTwo |= c == 2;
            hasThree |= c == 3;
        }

        two += hasTwo;
        three += hasThree;
    }

    printf("Result 1: %i\n", three * two);

    for (auto &x : input) {
        long matchCount = 0;
        std::string result;
        for (auto &y : input) {
            result = GetMatchCount(x, y, matchCount);

            if (matchCount == x.length() - 1) {
                printf("Result 2: %s\n", result.c_str());
                return;
            }
        }
    }
}
