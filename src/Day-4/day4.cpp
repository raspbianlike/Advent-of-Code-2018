#include "day4.hpp"

struct g {
    int id;
    int month, day;
    int start, end;

    bool awake, asleep = false;
};

void Day4::Execute() {
    printf("-=-=-=-=-=Executing Day 4-=-=-=-=-=\n");
    std::filesystem::path path = "src/Day-4/input.txt";

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

    std::vector<g> guards;
    int previous = 0;
    for (auto &x : input) {
        int start = stoi(x.substr(15, 2));
        int id = 0;

        if (x.find("Guard") != std::string::npos) {
            id = stoi(x.substr(x.rfind('#') + 1, 2));
            previous = id;
        } else
            id = previous;


        bool asleep = x.find("asleep") != std::string::npos;
        g guard = g{};

        guard.asleep = asleep;
        guard.awake = !asleep;
        guard.id = id;

        printf("start: %i, asleep: %i, awake: %i\n", start, asleep, guard.awake);

        if (guard.awake)
            guard.end = start;
        else if (guard.asleep)
            guard.start = start;

        guards.push_back(guard);

    }

    int guardSleepTime[1000]= {0};
    for (auto c : guards) {
        if (c.asleep) {
            for(int i = 0; i < c.)
        }
            guardSleepTime[c.id] += c.end;
    }

    for (int i = 0; i < 101; i++) {
        printf("guard %i has %i minutes\n", i, guardSleepTime[i]);
    }
    int max[1000] = {0};

}