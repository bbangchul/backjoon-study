#include <bits/stdc++.h>
using namespace std;

void p8()
{
    string text;
    getline(cin, text);

    int alpha = 0, digit = 0, space = 0;

    for (int i = 0; i < text.size(); i++)
    {
        if ((text[i] >= 'a' && text[i] <= 'z') || (text[i] >= 'A' && text[i] <= 'Z'))
            alpha++;
        else if (text[i] >= '0' && text[i] <= '9')
            digit++;
        else if (text[i] == ' ')
            space++;
    }

    cout << "알파벳 : " << alpha << "\n";
    cout << "숫자 : " << digit << "\n";
    cout << "공백 : " << space << "\n";
}

void p9()
{
    string text;
    getline(cin, text);

    int count = 0;
    bool inWord = false;

    for (int i = 0; i < text.length(); i++)
    {
        if (text[i] != ' ')
        {
            if (!inWord)
            {
                count++;
                inWord = true;
            }
        }
        else
        {
            inWord = false;
        }
    }

    cout << "단어 개수: " << count << "\n";
}

void p13()
{
    string text, findStr, replaceStr;
    getline(cin, text);
    getline(cin, findStr);
    getline(cin, replaceStr);

    string result = "";

    for (int i = 0; i < text.length();)
    {
        bool match = true;

        for (int j = 0; j < findStr.length(); j++)
        {
            if (i + j >= text.length() || text[i + j] != findStr[j])
            {
                match = false;
                break;
            }
        }

        if (match)
        {
            result += replaceStr;
            i += findStr.length();
        }
        else
        {
            result += text[i];
            i++;
        }
    }

    cout << result << "\n";
}

int main()
{
    p8();
    p9();
    p13();

    return 0;
}