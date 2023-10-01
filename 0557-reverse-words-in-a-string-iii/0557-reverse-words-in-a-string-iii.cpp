class Solution {
public:
    string reverseWords(string s) {
        istringstream stream(s);
        string word, result;
        
        while (stream >> word) {
            reverse(word.begin(), word.end());
            result += word + " ";
        }
        
        if (!result.empty()) {
            result.pop_back();  // Remove trailing space
        }
        
        return result;
    }
};