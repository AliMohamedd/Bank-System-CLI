#pragma once
#include <iostream>
#include"clsDate.h"

using namespace std;

class clsUtil
{
public:
    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        int randNum = rand() % (To - From + 1) + From;
        return randNum;
    }

    enum enCharType {
        SamallLetter = 1, CapitalLetter = 2,
        Digit = 3, MixChars = 4, SpecialCharacter = 5
    };

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return (char)RandomNumber(97, 122);
            break;
        }
        case enCharType::CapitalLetter:
        {
            return (char)RandomNumber(65, 90);
            break;
        }
        case enCharType::SpecialCharacter:
        {
            return (char)RandomNumber(33, 47);
            break;
        }
        case enCharType::Digit:
        {
            return (char)RandomNumber(49, 57);
            break;
        }
        default:
            return (char)RandomNumber(49, 57);
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string word = "";

        for (short i = 0; i < Length; i++)
        {
            word += GetRandomCharacter(CharType);
        }

        return word;
    }

    static string GenerateKey(enCharType CharType)
    {
        string Key = "";

        Key = GenerateWord(CharType, 4) + '-';
        Key += GenerateWord(CharType, 4) + '-';
        Key += GenerateWord(CharType, 4) + '-';
        Key += GenerateWord(CharType, 4);

        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKeys; i++)

        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }

    }

    static void FillArrayWithRandomNumbers(int Arr[100], short Length)
    {
        for (short i = 0; i < Length; i++)
        {
            Arr[i] = RandomNumber(1, 100);
        }
    }

    static void FillArrayWithRandomWords(string Arr[100], short ArrLength, enCharType CharType, short WordLength)
    {
        for (short i = 0; i < ArrLength; i++)
        {
            Arr[i] = GenerateWord(CharType, WordLength);
        }
    }

    static void FillArrayWithRandomKeys(string Arr[100], short ArrLength, enCharType CharType)
    {
        for (short i = 0; i < ArrLength; i++)
        {
            Arr[i] = GenerateKey(CharType);
        }
    }

    static void Swap(int& Num1, int& Num2)
    {
        int temp = Num1;
        Num1 = Num2;
        Num2 = temp;
    }

    static void Swap(double& Num1, double& Num2)
    {
        double temp = Num1;
        Num1 = Num2;
        Num2 = temp;
    }

    static void Swap(bool& A, bool& B)
    {
        bool Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char& A, char& B)
    {
        char Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string& A, string& B)
    {
        string Temp;

        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate& A, clsDate& B)
    {
        clsDate::SwapDates(A, B);

    }

    static void ShuffleArray(int Arr[], short ArrLength)
    {
        short rand1 = 0, rand2 = 0;

        for (short i = 0; i < ArrLength; i++)
        {
            rand1 = RandomNumber(0, ArrLength - 1);
            rand2 = RandomNumber(0, ArrLength - 1);
            Swap(Arr[rand1], Arr[rand2]);
        }

    }

    static void ShuffleArray(string Arr[], short ArrLength)
    {
        short rand1 = 0, rand2 = 0;

        for (short i = 0; i < ArrLength; i++)
        {
            rand1 = RandomNumber(0, ArrLength - 1);
            rand2 = RandomNumber(0, ArrLength - 1);
            Swap(Arr[rand1], Arr[rand2]);
        }

    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";

        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;

    }

    static void PrintTimesChar(short length, char c = '_')
    {
        for (short i = 0; i < length; i++)
        {
            cout << c;
        }
    }

    static string EncryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string DecryptText(string Text, short EncryptionKey)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }
};

