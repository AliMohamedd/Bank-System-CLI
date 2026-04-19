#pragma once
#include<iostream>
#include<vector>

using namespace std;

class clsString
{
private:
    string _Value;

public:
    clsString()
    {
        _Value = "";
    }

    clsString(string Value)
    {
        _Value = Value;
    }

    void SetValue(string Value)
    {
        _Value = Value;
    }

    string GetValue()
    {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;

    static short Length(string S1)
    {
        return S1.length();
    };

    short Length()
    {
        return _Value.length();
    };

    static string UpperFirstLetterOfEachWord(string S1)
    {
        bool isFirstAfterSpace = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] == ' ')
                isFirstAfterSpace = true;
            else if (isFirstAfterSpace)
            {
                S1[i] = toupper(S1[i]);
                isFirstAfterSpace = false;
            }
        }
        return S1;
    }

    void UpperFirstLetterOfEachWord()
    {
        _Value = UpperFirstLetterOfEachWord(_Value);
    }

    static string LowerFirstLetterOfEachWord(string S1) // Fix function signature and spelling  
    {
        bool isFirstAfterSpace = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] == ' ')
                isFirstAfterSpace = true;
            else if (isFirstAfterSpace)
            {
                S1[i] = tolower(S1[i]);
                isFirstAfterSpace = false;
            }
        }
        return S1;
    }

    void LowerFirstLetterOfEachWord()
    {
        _Value = LowerFirstLetterOfEachWord(_Value);
    }

    static string UpperAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = toupper(S1[i]);
        }
        return S1;
    }

    void UpperAllString()
    {
        _Value = UpperAllString(_Value);
    }

    static string LowerAllString(string S1)
    {
        for (short i = 0; i < S1.length(); i++)
        {
            S1[i] = tolower(S1[i]);
        }
        return S1;
    }

    void LowerAllString()
    {
        _Value = LowerAllString(_Value);
    }

    static char InvertLetterCase(char Letter)
    {
        return isupper(Letter) ? tolower(Letter) : toupper(Letter);
    }

    static string InvertAllLetterCase(string S1)
    {
        for (int i = 0; i < S1.length(); i++)
        {
            S1[i] = InvertLetterCase(S1[i]);
        }
        return S1;
    }

    void InvertAllString()
    {
        _Value = InvertAllLetterCase(_Value);
    }

    static short CountUpperLetters(string S1)
    {
        short count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (isupper(S1[i]))
                count++;
        }
        return count;
    }

    short CountUpperLetters()
    {
        return CountUpperLetters(_Value);
    }

    static short CountLowerLetters(string S1)
    {
        short count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (islower(S1[i]))
                count++;
        }
        return count;
    }

    short CountLowerLetters()
    {
        return CountLowerLetters(_Value);
    }

    enum enWhatToCount
    {
        UpperCaseCount = 1,
        LowerCaseCount = 2,
        NumberCount = 3,
        SpecialCharCount = 4,
        SpaceCount = 5,
        AllCount = 6
    };

    static bool isSpecialCharacter(char ch)
    {
        return !isalnum(ch) && !isspace(ch);
    }

    static short CountLetters(string S1, enWhatToCount whatToCount = enWhatToCount::AllCount)
    {
        if (whatToCount == enWhatToCount::AllCount)
        {
            return S1.length();
        }

        short count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (whatToCount == UpperCaseCount && isupper(S1[i]))
                count++;
            else if (whatToCount == LowerCaseCount && islower(S1[i]))
                count++;
            else if (whatToCount == NumberCount && isdigit(S1[i]))
                count++;
            else if (whatToCount == SpaceCount && isspace(S1[i]))
                count++;
            else if (whatToCount == SpecialCharCount && isSpecialCharacter(S1[i]))
                count++;
        }
        return count;
    }

    static short  CountCapitalLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (isupper(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountCapitalLetters()
    {
        return CountCapitalLetters(_Value);
    }

    static short  CountSmallLetters(string S1)
    {

        short Counter = 0;

        for (short i = 0; i < S1.length(); i++)
        {

            if (islower(S1[i]))
                Counter++;

        }

        return Counter;
    }

    short  CountSmallLetters()
    {
        return CountSmallLetters(_Value);
    }

    static short CountSpecificLetter(string S1, char Letter, bool MatchCase = true)
    {
        int count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (MatchCase)
            {
                if (S1[i] == Letter)
                    count++;
            }
            else
            {
                if (tolower(S1[i]) == tolower(Letter))
                    count++;
            }

        }
        return count;
    }

    short CountSpecificLetter(char Letter, bool MatchCase = true)
    {
        return CountSpecificLetter(_Value, Letter, MatchCase);
    }

    static bool IsVowel(char Letter)
    {
        Letter = tolower(Letter);
        return (Letter == 'a' || Letter == 'e' || Letter == 'i' || Letter == 'o' || Letter == 'u');
    }

    static short CountVowels(string S1)
    {
        int count = 0;
        for (int i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
            {
                count++;
            }
        }
        return count;
    }

    short CountVowels()
    {
        return CountVowels(_Value);
    }

    static short CountWords(string S1)
    {
        string dlim = " ";
        short Pos = 0;
        short count = 0;

        while ((Pos = S1.find(dlim)) != string::npos)
        {
            count++;
            S1.erase(0, Pos + dlim.length());
        }

        if (!S1.empty())
        {
            count++;
        }

        return count;
    }

    short CountWords()
    {
        return CountWords(_Value);
    }

    static vector <string> Split(string S1, string Delim = " ")
    {
        short Pos = 0;
        string word;
        vector <string> Words;

        while ((Pos = S1.find(Delim)) != string::npos)
        {
            word = S1.substr(0, Pos);
            if (word != "")
            {
                Words.push_back(word);
            }
            S1.erase(0, Pos + Delim.length());
        }

        if (word != "")
        {
            Words.push_back(S1);
        }

        return Words;
    }

    vector <string> Split(string Delim = " ")
    {
        return Split(_Value, Delim);
    }

    static string TrimLeft(string S1)
    {

        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(i, S1.length() - 1);
            }
        }
        return "";
    }

    void TrimLeft()
    {
        _Value = TrimLeft(_Value);
    }

    static string TrimRight(string S1)
    {

        for (short i = S1.length() - 1; i >= 0; i--)
        {
            if (S1[i] != ' ')
            {
                return S1.substr(0, i + 1);
            }
        }
        return "";
    }

    void TrimRight()
    {
        _Value = TrimRight(_Value);
    }

    static string Trim(string S1)
    {
        return TrimLeft(TrimRight(S1));
    }

    void Trim()
    {
        _Value = Trim(_Value);
    }

    static string JoinString(vector <string> Strings, string dlim = " ")
    {
        string word;

        for (auto& str : Strings)
        {
            word += str + dlim;
        }

        return word.substr(0, word.length() - dlim.length());
    }

    static string JoinString(string Strings[], short length, string dlim = " ")
    {
        string word;

        for (short i = 0; i < length; i++)
        {
            word += Strings[i] + dlim;
        }

        return word.substr(0, word.length() - dlim.length());
    }

    static string ReversedWords(string S1)
    {
        vector<string> vString;
        string S2;

        vString = Split(S1, " ");

        // declare iterator
        vector<string>::iterator iter = vString.end();

        while (iter != vString.begin())
        {
            --iter;
            S2 += *iter + " ";
        }

        return S2.substr(0, S2.length() - 1);
    }

    void ReversedWords()
    {
        _Value = ReversedWords(_Value);
    }

    static string ReplaceWord(string S1, string
        StringToReplace, string StringReplaceTo, bool MatchCase = true)
    {
        vector<string> vString = Split(S1, " ");
        for (string& s : vString)
        {
            if (MatchCase)
            {
                if (s == StringToReplace)
                {
                    s = StringReplaceTo;
                }
            }
            else
            {
                if (LowerAllString(s) ==
                    LowerAllString(StringToReplace))
                {
                    s = StringReplaceTo;
                }
            }
        }

        return JoinString(vString, " ");
    }

    void ReplaceWord(string
        StringToReplace, string StringReplaceTo, bool MatchCase = true)
    {
        _Value = ReplaceWord(_Value, StringToReplace, StringReplaceTo, MatchCase);
    }

    static string RemovePunctuation(string S1)
    {
        string S2;
        for (char& c : S1)
        {
            if (!ispunct(c))
                S2 += c;
        }
        return S2;
    }

    void RemovePunctuation()
    {
        _Value = RemovePunctuation(_Value);
    }

    static void PrintVowelsInString(string S1)
    {
        short count = 0;
        for (short i = 0; i < S1.length(); i++)
        {
            if (IsVowel(S1[i]))
            {
                cout << S1[i] << " ";
            }
        }
    }

    void PrintVowelsInString()
    {
        PrintVowelsInString(_Value);
    }

    static void PrintEachWordInString(string S1)
    {
        string dlim = " ";
        short Pos = 0;
        string word;

        while ((Pos = S1.find(dlim)) != string::npos)
        {
            word = S1.substr(0, Pos);
            if (!word.empty())
            {
                cout << word << endl;
            }

            S1.erase(0, Pos + dlim.length());
        }

        if (S1 != "")
            cout << S1 << endl;
    }

    void PrintEachWordInString()
    {
        PrintEachWordInString(_Value);
    }

    static void PrintFirstLetterOfEachWord(string S1)
    {
        bool isFirstAfterSpace = true;
        for (short i = 0; i < S1.length(); i++)
        {
            if (S1[i] == ' ')
                isFirstAfterSpace = true;
            else if (isFirstAfterSpace)
            {
                cout << S1[i] << endl;
                isFirstAfterSpace = false;
            }
        }
    }

    void PrintFirstLetterOfEachWord()
    {
        PrintFirstLetterOfEachWord(_Value);
    }

};

