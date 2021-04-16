#include <string>
#include <vector>

using namespace std;

int net[201];

int find(int a){
    // find set of a
    // if a belongs to B -> find its parent
    if (net[a] != a) return net[a] = find(net[a]);
    else return a;
}

// merge the network if there is a connection
void merge(int a, int b){
    // find its parent node
    int pa = find(a);
    int pb = find(b);
    if (pa == pb) return;
    else net[pa] = pb;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    // Update net
    for (int i = 0; i < n; ++i) net[i] = i;

    // for each element in vector
    for (int i = 0; i < n; ++i){
        // connected computer with i is
        for (int j = 0; j < n; ++j){
            if (i == j) continue; // skip itself
            if (computers[i][j]) merge(i, j);
        }
    }
    // assume there are n separate networks
    answer = n;
    for (int i = 0; i < n; ++i){
        // value is not itself -> belongs to a network;
        if (net[i] != i) answer--;
    }
    return answer;
}

/*
Union-find : Disjoint set
*/
