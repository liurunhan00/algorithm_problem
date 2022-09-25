#include <string>
#include <vector>

using namespace std;

int minOperations(vector<string>& logs) {
    int step = 0;
    for (auto &log: logs) {
        if (log == "./") {
            continue;
        } else if (log == "../") {
            step = step >= 1 ? step - 1: step;
            continue;
        } else {
            step++;
        }
    }
    return step;

}