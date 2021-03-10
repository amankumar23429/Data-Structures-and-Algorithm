#include<iostream>
#include<string>
#include<set>
using namespace std;

// here set is used to set uniques permutations

void permute(char * in, int i, set<string> &s){
    if(in[i]=='\0'){
        string t(in);
        s.insert(t);
        return;
    }

    for(int j = i; in[j]!='\0'; j++){
        swap(in[i], in[j]);
        permute(in, i+1, s);
        swap(in[i], in[j]);
    }
}

int main(){
  char input[100];
  cin>>input;
  set<string> s;
  permute(input, 0, s);

  for(auto str:s){
      cout<<str<<" ";
  }
  return 0;
}