class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == 'b') {
                b = true;
            } else if (s[i] == 'a' && b) {
                return false;
            }
        }

        return true;
    }
};