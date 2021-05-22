#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> node;

vector<int> mergeSortedArrays(vector<vector<int>> arr) {
    vector<int> result;
    priority_queue<node, vector<node>, greater<node>> heap; //min heap;

    //insert 0th element of every array into heap
    for(int i = 0; i < arr.size(); i++) {
        heap.push({arr[i][0], {i, 0}});
    }

    while(!heap.empty()) {

        //get min element from heap
        node current = heap.top();
        heap.pop();
        int element = current.first;
        int i = current.second.first; //row in which element is present
        int j = current.second.second; //col in which element is present

        result.push_back(element);

        if(j + 1 < arr[i].size()) {
            heap.push({arr[i][j + 1], {i, j + 1}});
        }
            
    }

    return result;
}

int main() {
    vector<vector<int>> v = {{1,2,3,4,5}, {14,15,16,17}, {6,7,8,9}};
    vector<int> result = mergeSortedArrays(v);
    for(auto ele : result)
        cout<<ele<<" ";
}
