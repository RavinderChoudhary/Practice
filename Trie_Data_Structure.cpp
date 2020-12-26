#include <bits/stdc++.h>
using namespace std;
class TrieNode
{
  public: 
   char ch;
   TrieNode **children;
   bool isTerminal;
   TrieNode(char ch){
       this -> ch = ch;
       children = new TrieNode*[26];
       for(int i=0;i<26;i++)
         children[i] = NULL;
       this -> isTerminal = false;
   } 
};
class Trie
{
    public:
    TrieNode *root;
    
    Trie(){
        root = new TrieNode('\0');
    }
     void insertStr(string s,TrieNode *root){
       if(s.empty()){
           root -> isTerminal = true;
           return;
       }
       int ch = s[0] - 'a';
       
       TrieNode *child;
       if(root -> children[ch] == NULL){
           child = new TrieNode(ch);
           root -> children[ch] = child;
       }
       else child = root -> children[ch];
      
       insertStr(s.substr(1),child);
     }
     bool findStr(string s,TrieNode *root){
         if(s.empty()){
             if(root -> isTerminal == true)
               return true;
             else return false;
         }
         
         int ch = s[0] - 'a';
         TrieNode *child = root -> children[ch];
         if(child != NULL)
            return findStr(s.substr(1) , child);
         else return false;
     }
     bool empty(TrieNode *child){
          for(int i=0;i<26;i++)
            if(child -> children[i] != NULL)
              return false;
          return true;
     }
     void removeEle(string s,TrieNode *root){
         if(s.empty()){
             root -> isTerminal = false;
             return;
         }
         
         int ch = s[0] - 'a';
         TrieNode *child = root -> children[ch];
         if(child != NULL){
            removeEle(s.substr(1),child);
         }
         else return;
         
         if(child -> isTerminal == false && empty(child)){
             delete(child);
             root -> children[ch] = NULL;
         }
     }
     void insert(string s){
         insertStr(s,this->root);
     }
     bool find(string s){
         return findStr(s,this->root);
     }
     void removeElement(string s){
         removeEle(s,root);
     }
};

int main()
{   
    Trie t;
    t.insert("ravi");
    t.insert("god");
    t.insert("ravinder");
    cout<<t.find("rav")<<endl;
    cout<<t.find("ravi")<<endl;
    cout<<t.find("ravinder")<<endl;
    t.removeElement("ravi");
    return 0;
}

class Trie {
private:
    struct TrieNode{
        TrieNode* children[26];
        bool isWord;
        TrieNode(){
            for(int i=0; i<26; i++){
                children[i] = NULL;
            }
            isWord = false;
        }
    };
    
    TrieNode* root;
    
public:
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        TrieNode* cur = root;
        for(int i=0; i < word.size(); i++){
            int idx = word[i] - 'a';
            if(!cur->children[idx]) cur->children[idx] = new TrieNode();
            cur = cur->children[idx];
        }
        cur->isWord = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        TrieNode* cur = root;
        for(int i=0; i<word.size(); i++){
            int idx = word[i] - 'a';
            if(cur->children[idx]){
                cur = cur->children[idx];
            } else {
                return false;
            }
        }
        return cur->isWord;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        TrieNode* cur = root;
        for(int i=0; i<prefix.size(); i++){
            int idx = prefix[i] - 'a';
            if(cur->children[idx]){
                cur = cur->children[idx];
            } else {
                return false;
            }
        }
        return true;
    }
};


