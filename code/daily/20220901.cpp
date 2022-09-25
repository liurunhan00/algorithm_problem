#include <vector>
#include <stack>
using namespace std;
vector<int> finalPrices(vector<int>& prices) {
    int size = prices.size();
    if (size == 0 || size == 1) {
        return prices;
    }

    int j;
    for (int i = 0; i < size - 1; i++) {
        j = i + 1;
        while (j < size) {
            if (prices[j] <= prices[i]) {
                prices[i] -= prices[j];
                break;
            }
            j++;
        }
    }

    return prices;
}