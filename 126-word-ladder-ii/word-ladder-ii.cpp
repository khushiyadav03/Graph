class Solution {
public:
    void dfs(string word, string beginWord, unordered_map<string, vector<string>>& parents, vector<string>& path, vector<vector<string>>& result){
        if(word == beginWord){
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            result.push_back(temp);
            return;
        }

        for(string parent : parents[word]){
            path.push_back(parent);
            dfs(parent, beginWord, parents, path, result);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st(wordList.begin(), wordList.end());
        if(st.find(endWord) == st.end()) return {};
        unordered_map<string, vector<string>> parents;
        unordered_map<string, int> level;
        queue<string> q;
        q.push(beginWord);
        level[beginWord] = 0;

        bool found = false;
        while(!q.empty() && !found){
            int size = q.size();
            for(int s = 0; s<size; s++){
                string word = q.front();
                q.pop();
                int currLevel = level[word];

                for(int i = 0; i<word.length(); i++){
                    string temp = word;
                    for(char ch = 'a'; ch <= 'z'; ch++){
                        if(ch == word[i]) continue;
                        temp[i] = ch;

                        if(st.find(temp) != st.end()){
                            if(level.find(temp) == level.end()){
                                level[temp] = currLevel+1;
                                parents[temp].push_back(word);
                                q.push(temp);

                                if(temp == endWord) found = true;
                            } else if(level[temp] == currLevel+1){
                                parents[temp].push_back(word);
                            }
                        }
                    }
                }
            }
        }
        if(level.find(endWord) == level.end()) return {};

        vector<vector<string>> result;
        vector<string> path;
        path.push_back(endWord);
        dfs(endWord, beginWord, parents, path, result);
        return result;
    }
};