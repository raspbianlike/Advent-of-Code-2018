#include "day4.hpp"

struct guard_t {
    int id = -1;
    int start = -1;

    int awake = -1, asleep = -1;
};

bool SortGuards(const guard_t &a, const guard_t &b) {
    return a.id < b.id;
}

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

    std::vector<guard_t> guards{};
    int previousId = 0;

    for (auto &x : input) {
        int start = stoi(x.substr(15, 2));
        int id = 0;

        if (x.find("Guard") != std::string::npos)
            previousId = id = stoi(x.substr(x.rfind('#') + 1, x.rfind("begins") - 1));
        else
            id = previousId;

        bool asleep = x.find("asleep") != std::string::npos;
        bool awake = x.find("up") != std::string::npos;
        guard_t guard{
                id,
                start,
                awake,
                asleep
        };

        guards.push_back(guard);
    }

    std::sort(guards.begin(), guards.end(), SortGuards);

    int guardSleepTime[3000] = {0};
    int guardSleepTimeAmount[3000][60] = {0};
    int maxSleepTime = 0;

    int guardMinuteId = 0;
    int guardId = 0;

    int guardId2 = 0;
    int guardMinuteId2 = 0;

    for (auto &c : guards) {
        static int prevId = 0;
        static int sleepTime = 0;
        static int max = 0;

        if (prevId != c.id) {
            if (guardSleepTime[prevId] > maxSleepTime) {
                guardId = prevId;
                maxSleepTime = guardSleepTime[prevId];
            }

            prevId = c.id;
            sleepTime = 0;
        }

        int tmp = 0;
        if (c.asleep == 1) {
            sleepTime = c.start;
        } else if (c.awake == 1) {
            tmp = c.start - sleepTime;
            guardSleepTime[c.id] += tmp;

            for (int i = sleepTime; i < c.start; i++) {
                guardSleepTimeAmount[c.id][i]++;
                if (guardSleepTimeAmount[c.id][i] > max) {
                    max = guardSleepTimeAmount[c.id][i];
                    guardId2 = c.id;
                    guardMinuteId2 = i;
                }
            }
        }
    }


    for (int x = 0; x < 60; x++) { // Put me in the upper loop so the code is even more unreadable!
        static int tmp = 0;
        if (guardSleepTimeAmount[guardId][x] > tmp) {
            guardMinuteId = x;
            tmp = guardSleepTimeAmount[guardId][x];
        }
    }

    int iD1 = guardMinuteId * guardId;
    int iD2 = guardMinuteId2 * guardId2;

    printf("Part 1: %i\n", iD1);
    printf("Part 2: %i\n", iD2);
}
