#include <vector>
#include <algorithm>
typedef std::pair<int, int> PAIR;
int maximumSwap(int num) {
    int i = 0, j = 0, tmp = num; 
    std::vector<PAIR> swap;

    while (tmp / 10 != 0) {
        int t = tmp % 10;
        tmp /= 10;
        swap.push_back({t, i++});
    }

    auto cmp = [&swap](PAIR& a, PAIR& b){
        return a.first > b.first;
    };

    std::sort(swap.begin(), swap.end(), cmp);

    for (i = 1; i < swap.size(); i++) {
        if (swap[i].first != swap[i - 1].first) {
            break;
        }
    }

    for (j = 0; j < swap.size(); j++) {
        if (j != swap[j].second) {
            break;
        }
    }


}
