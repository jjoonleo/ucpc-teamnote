#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> get_pi(string pattern){

  int pattern_len = pattern.size(), j = 0;

  vector<int> pi(pattern_len, 0);

  for (int i = 1; i < pattern_len; ++i)
  {
    while (j > 0 && pattern[i] != pattern[j])
      j = pi[j - 1];
    if (pattern[i] == pattern[j])
      pi[i] = ++j;
  }

  return pi;
}

vector<int> kmp(string str, string pattern){
  int str_len = str.size(), pattern_len = pattern.size();
  int j = 0;

  vector<int> ans;  //Starting index of substring matching pattern

  vector<int> pi = get_pi(pattern);

  for(int i = 0; i < str_len; ++i){
    while(j > 0 && pattern[j] != str[i])
      j = pi[j-1];
    if(pattern[j] == str[i]){
      if(j == pattern_len - 1){
        ans.push_back(i - pattern_len + 1);
        j = pi[j];
      }
      else
        j++;
    }
  }
  return ans;
}
