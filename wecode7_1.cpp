#include <iostream>
#include <string>
#include <vector>
using namespace std;

void StringReverse(string &s)
{
    vector<string> tokens;
    string token = "";
    bool inWord = false;

    for (size_t i = 0; i < s.size(); ++i)
    {
        token += s[i];

        if (s[i] != ' ')
        {
            inWord = true;
        }
        else if (inWord && s[i] == ' ')
        {
            // Sau khi có từ + khoảng trắng -> lưu token
            tokens.push_back(token);
            token.clear();
            inWord = false;
        }
    }

    // Nếu chuỗi kết thúc không có khoảng trắng
    if (!token.empty())
        tokens.push_back(token);

    // Đảo ngược
    string result = "";
    for (int i = tokens.size() - 1; i >= 0; --i)
    {
        result += tokens[i];
    }

    s = result;
}

int main()
{
    string s;
    getline(cin, s);

    if (s.empty())
        cout << "Chuoi rong." << endl;
    else
    {
        StringReverse(s);
        cout << s << endl;
    }

    return 0;
}
