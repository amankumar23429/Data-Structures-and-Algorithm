#include<iostream>
#include<climits>
#include<string>

using namespace std;

string find_window(string s, string pattern){
    int pat_size = pattern.length();
    int s_size = s.length();

    if(pat_size>s_size){
        return "None";
    }

    int FS[256] = {0};
    int FP[256] = {0};
    for(int i = 0 ; i<pat_size; i++){
        char ch = pattern[i];
        FP[ch]++;
    }

    int count = 0;
    int start = 0;
    int start_min_index = -1;
    int min_window_len = INT_MAX;

    for(int i = 0 ; i<s_size; i++){
        char ch = s[i];
        FS[ch]++;
        
        if(FP[ch]!=0 and FS[ch]<=FP[ch]){
            count++;
        }

        if(count==pat_size){
            char temp = s[start];

            while(FP[temp]==0 or FS[temp]>FP[temp]){
                FS[temp]--;
                start++;
                temp = s[start];
            }

            int current_window_size = i-start+1;

            if(current_window_size<min_window_len){
                min_window_len = current_window_size;
                start_min_index = start;
            }
        }
    }

    if(start_min_index==-1){
        return "NONE";
    }
    string ans = s.substr(start_min_index, min_window_len);
    return ans;
}


int main(){
    string s = "hllloeaeo world";
    string p = "eelo";
    cout<<find_window(s,p);
    return 0;
}