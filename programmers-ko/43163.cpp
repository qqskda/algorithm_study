#include <string>
#include <vector>

using namespace std;

bool convertible(const string& src, const string& target){
    int count = 0, sz = src.size();
    for (int i = 0; i < sz; ++i){
        if (src[i] != target[i]) count++;
        if (count > 1) return false;
    }
    return true;
}

//dfs
void dfs(int& farLeast, int count, string src, const string& target, const vector<string>& words, vector<int>& marker){
    if (src == target){
        if (farLeast != 0) farLeast = min(count, farLeast);
        else farLeast = count;
    }
    // stoping point
    if (farLeast != 0 && count > farLeast) return;
    // visiting others
    for (int i = 0; i < words.size(); ++i){
        if (!marker[i]) continue;
        if (!convertible(src, words[i])) continue;
        marker[i]--;
        dfs(farLeast, count+1, words[i], target, words, marker);
        marker[i]++;
    }
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    vector<int> marker(51, 1);
    dfs(answer, 0, begin, target, words, marker);
    return answer;
}
