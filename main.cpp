/*  The program takes an integer as input and returns
*   the number of letters that make up the number
*/
#include<iostream>
#include<cstdio>
#include<cassert>
#include<cstring>

using std::cout;
using std::cin;
using std::endl;
//////////////////////////////////////////
const int hundred[10] = {
    0,
    strlen("hundred"),
    strlen("two hundred"),
    strlen("three hundred"),
    strlen("four hundred"),
    strlen("five hundred"),
    strlen("six hundred"),
    strlen("seven hundred"),
    strlen("eight hundred"),
    strlen("nine hundred")
    };
////////////////////////////////////////
const int tens[10] = {
    0,
    strlen("ten"),
    strlen("twenty"),
    strlen("thirty"),
    strlen("forty"),
    strlen("fifty"),
    strlen("sixty"),
    strlen("seventy"),
    strlen("eighty"),
    strlen("ninety")
};
//////////////////////////////////////////
const int units[20] = {
    0,
    strlen("one"),
    strlen("two"),
    strlen("three"),
    strlen("four"),
    strlen("five"),
    strlen("six"),
    strlen("seven"),
    strlen("eight"),
    strlen("nine"),
    strlen("ten"),
    strlen("eleven"),
    strlen("twelve"),
    strlen("thirteen"),
    strlen("fourteen"),
    strlen("fifteen"),
    strlen("sixteen"),
    strlen("seventeen"),
    strlen("eighteen"),
    strlen("nineteen")
};
////////////////////////////////////////////
int letterCount3(int n)
{
    assert(0 <= n && n <= 999);
    int ans = hundred[n/100];
    if(10 <= n % 100 && n % 100 <= 19)
    {
        ans += units[n % 100];
    }
    else
    {
        ans += tens[n / 10 % 10] + units[n % 10];
    }
    return ans;
}
//////////////////////////////////////////
int letterCount(int n)
{
    assert(0 <= n && n <= 1000 * 1000);
    if(n == 0)
    {
        return strlen("zero");
    }
    if (n == 1000 * 1000)
    {
        return strlen("million");
    }
    if (1 <= n && n <= 999)
    {
        return letterCount3(n);
    }
    if(1000 <= n && n <= 1999)
    {
        return strlen("thousand") + letterCount3(n % 1000);
    }
    assert(2000 <= n && n <= 999 * 1000 + 999);
    int up = n / 1000;
    int down = n % 1000;
    int ans = letterCount3(up) + strlen("thousands") + letterCount3(down);
    if(1 <= up % 10 && up % 10 <= 4 && !(11 <= up % 100 && up % 100 <= 14))
    {
        ans++;
    }
    return ans;
}
//////////////////////////////////////////
int main()
{
    int n, answer;
    char ch;
    do
    {
        cout << "Enter a non negative integer(Q - Exit): ";
        cin >> n;
        answer = letterCount(n);
        cout << answer << endl;
        cout << "Continue? (Y/Q): ";
        cin >> ch;
    }while(ch != 'Q');
    cout << "Good bye!" << endl;

    return 0;
}
