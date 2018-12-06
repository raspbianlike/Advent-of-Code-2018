#include <iostream>
#include "day5.hpp"

bool caseInsensitiveStringCompare(const std::string &str1, const std::string &str2) {
    std::string str1Cpy(str1);
    std::string str2Cpy(str2);
    std::transform(str1Cpy.begin(), str1Cpy.end(), str1Cpy.begin(), ::tolower);
    std::transform(str2Cpy.begin(), str2Cpy.end(), str2Cpy.begin(), ::tolower);
    return (str1Cpy == str2Cpy);
}

std::string ReactInput(std::string &str1) {
    for (long i = 0; i < str1.size() - 1; i++) {
        if (islower(str1[i]) || isupper(str1[i])) {
            if ((isupper(str1[i]) && isupper(str1[i + 1])) || (islower(str1[i]) && islower(str1[i + 1])))
                continue;
            std::string one = std::string(1, str1[i]);
            std::string two = std::string(1, str1[i + 1]);
            if (caseInsensitiveStringCompare(one, two)) {
                str1.erase(i, 1);
                str1.erase(i, 1);
                return ReactInput(str1);
            }
        }
    }
    return str1;
}

int GetShortestPoly(std::string &str1) {
    char alph[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    int bestLength = 99999999;
    for(int i = 0; i < 25; i++) {
        std::string str = str1;
        str.erase(std::remove(str.begin(), str.end(), alph[i]), str.end());
        str.erase(std::remove(str.begin(), str.end(), toupper(alph[i])), str.end());

        std::string res = ReactInput(str);

        if(res.length() < bestLength)
            bestLength = res.length();
    }
    return bestLength;
}

void Day5::Execute() {
    printf("-=-=-=-=-=Executing Day 5-=-=-=-=-=\n");
    std::filesystem::path path = "src/Day-5/input.txt";

    std::ifstream fstr(path);
    std::stringstream strs;
    std::vector<std::string> input;

    if (!fstr) {
        printf("Bad input file!\n");
        return;
    }

    strs << fstr.rdbuf();

    std::string str;

    std::vector<std::string> input2;

    while (getline(strs, str)) {
        input.push_back(str);
    }

    input2 = input;
    std::string result;
    /*for (auto i = input.begin(); i != input.end(); i++) {
        bool didCompare = false;
        for (unsigned long p = 0; p < i.base()->length(); p++) {
            if (p + 1 < i.base()->length()) {
                if ((std::isupper(i.base()->at(p)) && std::islower(i.base()->at(p + 1))) || (std::islower(i.base()->at(p)) && std::isupper(i.base()->at(p + 1)))) {
                    //printf("we have match\n");
                    std::string one = std::string(1, i.base()->at(p));
                    std::string two = std::string(1, i.base()->at(p + 1));
                    if (caseInsensitiveStringCompare(one, two)) {
                        didCompare = true;
                        //printf("we have cC: %s, %s\n", one.c_str(), two.c_str());
                        i.base()->erase(p, 1);
                        i.base()->erase(p, 1);
                        p = 0;
                    }
                }
            }
            result = *i;
            //printf("current result %s\n", result.c_str());
        }
        if (!didCompare) {
            break;
        } else {
            i = input.begin();
        }
    }*/
    result = ReactInput(*input.begin());

    int best = GetShortestPoly(*input.begin());
    //printf("result: %s, length %lu, 2: %i\n", result.c_str(), result.length(), best);
}
