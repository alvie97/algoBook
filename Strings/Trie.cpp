#define MAXN 1000 //length of the greatest string possible

struct trie{
  map<char,int> sig;
  bool word;
};

trie t[MAXN];

int n;

void init(){
  n = 1;
  t[0].sig.clear();
  t[0].word = false;
}

void insetar(string &s){
  int pos = 0;
  
  for(int i = 0; i < s.size(); ++i){
    if(t[pos].sig.find() == t[pos].sig.end()){
      t[pos].sig[s[i]] = n;
      t[n].sig.clear();
      t[n].final = false;
      ++n;
    }
    pos = t[pos].sig[s[i]];
  }
  
  t[pos].word = true;
}
