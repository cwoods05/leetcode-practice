class Solution {
    public:
        unordered_map<string, string> parent;
        unordered_map<string, string> emailToName;
    
        string find(string x) {
            if (parent[x] == x) return x;
            parent[x] = find(parent[x]);
            return parent[x];
        }
    
        void unite(string a, string b) {
            string rootA = find(a);
            string rootB = find(b);
            parent[rootA] = rootB;
        }
    
        vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
            for (int i = 0; i < accounts.size(); i++) {
                for (int j = 1; j < accounts[i].size(); j++) {
                    string email = accounts[i][j];
                    parent[email] = email;
                    emailToName[email] = accounts[i][0];
                }
            }
    
            for (int i = 0; i < accounts.size(); i++) {
                string firstEmail = accounts[i][1];
    
                for (int j = 2; j < accounts[i].size(); j++) {
                    unite(firstEmail, accounts[i][j]);
                }
            }
    
            unordered_map<string, vector<string>> groups;
    
            for (auto& [email, _] : parent) {
                string root = find(email);
                groups[root].push_back(email);
            }
    
            vector<vector<string>> ans;
    
            for (auto& [root, emails] : groups) {
                sort(emails.begin(), emails.end());
    
                vector<string> account;
                account.push_back(emailToName[root]);
    
                for (string& email : emails) {
                    account.push_back(email);
                }
    
                ans.push_back(account);
            }
    
            return ans;
        }
    };