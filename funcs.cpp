//https://contest.yandex.ru/contest/27665/problems/A/

#include "funcs.h"
#include <bits/stdc++.h>

void parseFile(std::istream & input, std::ostream & output){

    std::map<std::string, std::string> dict;
    int n;
    input >> n;
    std::string word1, word2;
    for(int i = 0; i<n; ++i){
        input >> word1 >> word2;
        dict[word1] = word2;
        dict[word2] = word1;
    }

    input >> word1;

    output << dict[word1];
}
