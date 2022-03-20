#include <bits/stdc++.h>

using namespace std;

int rndrng(int l, int r) {
  return int(rand()*RAND_MAX)%(r-l) + l;
}

int main(int argc, char *argv[]){
  int seed = atoi(argv[1]);
  srand(seed);
  
  return 0;
}
