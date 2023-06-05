class Solution {
public:
    vector<string> removeSubfolders(vector<string>& folder) {
    sort(folder.begin(), folder.end()); // Sort the folders lexicographically
    vector<string> result;
    unordered_set<string> parentFolders;

    for (const string& f : folder) {
        bool isSubfolder = false;
        string path;
        for (int i = 1; i < f.length(); i++) {
            if (f[i] == '/') {
                path = f.substr(0, i);
                if (parentFolders.count(path)) {
                    isSubfolder = true;
                    break;
                }
            }
        }
        if (!isSubfolder) {
            result.push_back(f);
            parentFolders.insert(f);
        }
    }

    return result;
        
    }
};