// simple program to add the decimal numbers using binary addition.
#include <bits/stdc++.h>

using namespace std;

//functions
string toBinaryString(int n);
int binaryToDecimal(string s1);
void binaryAddition(string &s1, string &s2);

//main program
int main(int argc, char **argv)
{

    int n = 0, num = 0;
    string ans = "0", str = "0";
    //getting input from the user
    cout << "Enter the Number of terms" << endl;
    cin >> n;
    cout << "Please Enter the terms" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> num;
        str = toBinaryString(num);
        binaryAddition(ans, str);
    }
    //displaying the ouput
    cout << "Binary Equivalent is " << ans << endl;
    cout << "Decimal Equivalent is " << binaryToDecimal(ans) << endl;
    return 0;
}

// recursive function to convert any integer to its binary equivalent.
string toBinaryString(int n)
{
    if (n == 1)
        return "1";
    else if (n == 0)
        return "0";
    return toBinaryString(n / 2) + to_string(n % 2);
}

// function to convert binary to its decimal equivalent .
int binaryToDecimal(string s1)
{
    int ans = 0, leastSignificantBitIndex = s1.size() - 1, power = 0;
    while (leastSignificantBitIndex >= 0)
    {
        ans += (s1[leastSignificantBitIndex] - '0') * pow(2, power);
        leastSignificantBitIndex--;
        power++;
    }
    return ans;
}

//function to perform binaryAddition.
void binaryAddition(string &s1, string &s2)
{
    int len = max(s1.size(), s2.size());
    s1 = string(len - s1.size(), '0') + s1;
    s2 = string(len - s2.size(), '0') + s2;
    int carry = 0;
    string binaryequivalent = "";

    //binaryaddition
    while (len > 0)
    {
        len--;
        binaryequivalent += to_string((carry + (s1[len] - '0') + (s2[len] - '0')) % 2); //concatenation of the bits.
        carry = (carry + (s1[len] - '0') + (s2[len] - '0')) / 2;                        //storing the carry.
    }

    while (carry > 0)
    {
        binaryequivalent += to_string(carry % 2);
        carry /= 2;
    }
    reverse(binaryequivalent.begin(), binaryequivalent.end()); //reversing the obtained binary.
    s1 = binaryequivalent;                                     //updation of the ans variable in the main program .
}