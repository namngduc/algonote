#include<bits/stdc++.h>

std::string multiply(std::string s1, std::string s2) {
    int m=s1.size(), n=s2.size();
    std::vector<int> res(m+n, 0);
    for (int i=m-1; i>=0; i--) {
        for (int j=n-1; j>=0; j--) {
            int mul = (s1[i] - '0') * (s2[j] - '0');
            int p1=i+j, p2=i+j+1;
            int sum = mul + res[p2];
            res[p2] = sum % 10;
            res[p1] += sum / 10;
        }
    }
    int i=0;
    while(i < res.size() && res[i] == 0)
        i++;
    std::string str;
    for(;i < res.size(); i++) {
        str.push_back('0' + res[i]);
    }
    return str.size() == 0 ? "0" : str;
}

int main() {
    std::string s1="123", s2="45";
    std::string result = multiply(s1, s2);
    std::cout << result << "\n";
    return 0;
}