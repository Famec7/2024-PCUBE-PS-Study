#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int n;
string s[50];
long long sum_alphabet[10] = {0};
bool isFirst[10] = {false};
bool isUsed[10] = {false};
bool isDone[10] = {false};
long long sum = 0;

void Alpha_to_digit(string str)
{
    int length = str.length();
    for(int i=length - 1; i >= 0; i--)
    {
        sum_alphabet[(int)(str[i] - 'A')] += pow(10, length - i - 1);
    }
}

int Find_Min_Index_Dont_Used()
{
    int index = 0;
    long long min = 99999999999999;

    for(int i=0; i<10; i++)
    {
        if(min > sum_alphabet[i] && !isDone[i])
        {
            min = sum_alphabet[i];
            index = i;
        }
    }
    return index;
}

int main()
{
    cin >> n;
    for(int i=0; i<n; i++)
    {
        cin >> s[i];
        int alpha_index = (int)(s[i][0] - 'A');
        isFirst[alpha_index] = true;
        Alpha_to_digit(s[i]);
    }
    for(int i=0; i<10; i++)
    {
        int min_index;
        min_index = Find_Min_Index_Dont_Used();
        for(int j=0; j<10; j++)
        {
            if(isFirst[min_index] && j == 0)
                continue;
            if(!isUsed[j])
            {
                isUsed[j] = true;
                sum += sum_alphabet[min_index] * j;
                isDone[min_index] = true;
                break;
            }
        }
    }
    cout << sum;
}