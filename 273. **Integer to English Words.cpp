class Solution {
public: 
    string numberToWords(int num) {
        vector<string> bigs = { "", " Thousand", " Million", " Billion" };
        int i = 0;
        string ans;
        while (num) {
            if (num % 1000) ans = numberWords(num % 1000) + bigs[i] + ans;
            i++, num /= 1000;
        }
        return ans.length() ? ans.substr(1) : "Zero";
    }
private:
    string numberWords(int num) {
        char* one[] = { "", " One", " Two", " Three", " Four", " Five", " Six", " Seven", " Eight", " Nine" };
        char* ones[] = { " Ten", " Eleven", " Twelve", " Thirteen", " Fourteen", " Fifteen", " Sixteen", " Seventeen", " Eighteen", " Nineteen" };
        char* tens[] = { "", "", " Twenty", " Thirty", " Forty", " Fifty", " Sixty", " Seventy", " Eighty", " Ninety" };
        string ans;
        if (num > 99) ans += string(one[num / 100]) + " Hundred";
        num %= 100;
        if (num > 9 && num < 20) ans += ones[num % 10];
        else {
            if (num > 19) ans += tens[num / 10];
            num %= 10;
            if (num) ans += one[num];
        }
        return ans;
    }
};
