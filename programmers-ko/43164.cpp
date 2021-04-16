#include <string>
#include <vector>
#include <map>

using namespace std;

// DFS
// add ticket -> if fully used stop

bool dfs(const string& src, int sz, map<string, map<string, int>>& adj, vector<string>& answer){
    answer.push_back(src);
    // Fully used tickets
    if (answer.size() == sz) return true;

    // Visit src's adj
    for (auto itr = adj[src].begin(); itr != adj[src].end(); ++itr){
        // if already visited - skip
        if (itr->second == 0) continue;
        itr->second--;
        if (dfs(itr->first, sz, adj, answer)) return true;
        answer.pop_back();
        itr->second++;
    }

    return false;
}

vector<string> solution(vector<vector<string>> tickets) {
    vector<string> answer;
    map<string, map<string, int>> mp;
    // Used map as tickets should be in alphabetic
    for (auto& ticket : tickets){
        // update map - mark availble site
        mp[ticket[0]][ticket[1]]++;
    }
    // if ticket : n -> cities : n+1
    dfs("ICN", tickets.size()+1, mp, answer);
    return answer;
}
