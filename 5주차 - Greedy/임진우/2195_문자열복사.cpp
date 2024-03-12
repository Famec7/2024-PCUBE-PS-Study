#include <iostream>
using namespace std;

string input;
string tomake;
int cur_index = 0;
int count = 0;

void Find_Match()
{
    int max_matched_number = 0;
    int cur_matched_number = 0;

    for(int i=0; i<input.length(); i++)
    {
        if(input[i] == tomake[cur_index])
        {
            for(int j=0; i + j<input.length(); j++)
            {
                if(input[i + j] != tomake[cur_index + j])
                {
                    cur_matched_number = j;
                    break;
                }
                else if(i + j == input.length() - 1)
                    cur_matched_number = j + 1;
            }
            if(max_matched_number < cur_matched_number)
                max_matched_number = cur_matched_number;
        }
    }
    cur_index += max_matched_number;
    count++;
}

int main()
{
    cin >> input;
    cin >> tomake;
    while(cur_index < tomake.length())
        Find_Match();
    cout << count;
}