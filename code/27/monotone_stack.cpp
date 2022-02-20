#include <bits/stdc++.h>
using namespace std;

// 直方图的最大矩形面积
int largestRectangleArea(vector<int>& heights) {
    stack<int> st;
    // 栈保存单调的下标值
    // 因为单调栈中保存的柱高是递增的，
    // 所以栈中位于栈顶柱子前面的柱子一定比栈顶柱子矮，
    // 同样当前扫描到的柱子也矮于位于栈顶的柱子，
    // 所以顶柱子为顶的最高矩阵的宽度就确定了，那么面积也就确定了。
    st.push(-1);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); ++i) {
        while (st.top() != -1 && heights[st.top()] >= heights[i]) {
            int height = heights[st.top()];
            st.pop();
            int width = i - st.top() - 1;
            // 单调增所以只计算到st.top()
            maxArea = max(maxArea, height*width);
        }
        st.push(i);
    }
    while (st.top() != -1) {
        int height = heights[st.top()];
        st.pop();
        // 相当于push height(0)进去 
        int width = heights.size() - st.top() - 1;
        maxArea = max(maxArea, height*width);
    }
    return maxArea;
}

        
        
// 矩阵中最大的矩形
// 核心就是把矩阵的每一行构造成上一题的“直方图最大矩形”。
// 每一行矩形的高度建立在是否同上一行都为“1”上
int maximalRectangle(vector<string>& matrix) {
    int m = matrix.size(), n = matrix[0].size();
    vector<int> heights(n, 0);
    int maxArea = 0;
    for (auto &str: matrix) {
        for (int j = 0; j < n; j++) {
            if (str[j] == '1') {
                heights[j]++;
            } else {
                heights[j] = 0;
            }
        }
        maxArea = max(maxArea, largestRectangleArea(heights)); 
    }
    return maxArea;
}

int monotone_stack(vector<int>& heights) {
    stack<int> st;
    st.push(-1);
    int maxArea = 0;
    for (int i = 0; i < heights.size(); i++) {
        while (st.top() != -1 && heights[i] >= st.top()) {
            int cur = st.top();
            st.pop();
            int width = i - cur - 1;
            maxArea = max(maxArea, width*cur);
        }
        st.push(i);
    }
    while (st.top() != -1) {
        int cur = st.top();
        st.pop();
        int width = heights.size() - cur - 1;
        maxArea = max(maxArea, width*cur);
    }
    return maxArea;
}
            
