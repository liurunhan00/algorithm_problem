#include <iostream>
using namespace std;
int last_t(int n) {
    int last_t = 1, dir = 1, def = 1;
    while (n != 1) {
        if (dir == 1) {
            last_t += def;
        } else if(dir == -1) {
            if (n % 2 == 1) {
                last_t += def;
            }
        }
        dir *= -1;
        def *= 2;
        n /= 2;
    }
    return last_t;
}
int recursive_last_t(int n, int dir, int last_t, int def) {
    if (n == 1) return last_t; 
    if (dir == 1 || (dir == -1 && n/2 ==1)) last_t += def;
    return recursive_last_t(n/2, dir * (-1), last_t, def * 2);

}
int main() {
    int n ;
    cin >> n;
    last_t(3);
    //cout << recursive_last_t(n, 1, 1, 1) << endl; return 0; 
    int a[] = { 1, 2, 3, 4, 5 };
    cout << sizeof(a) << endl;    
}


    

