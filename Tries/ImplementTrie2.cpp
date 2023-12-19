// IMPLEMENT TRIE 2

#include <bits/stdc++.h> 
class Node{
public:
    Node* linkings[26];
    int cp=0;
    int ew=0;
    
    void put(char ch, Node* node){
        linkings[ch-'a']=node;
    }
    Node* get(char ch){
        return linkings[ch-'a'];
    }
    bool containsKey(char ch){
        return linkings[ch-'a']!=NULL;
    }
    void setCp(){
        cp+=1;
    }
    void setEw(){
        ew+=1;
    }
    int getEw(){
        return ew;
    }
    int getCp(){
        return cp;
    }
    int decCp(){
        cp-=1;
    }
    int decEw(){
        ew-=1;
    }
};
class Trie{
    private: Node*root;
    public:

    Trie() {
        root=new Node(); 
    }

    void insert(string &word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
            node->setCp();
        }
        node->setEw();
    }

    int countWordsEqualTo(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getEw();
    }

    int countWordsStartingWith(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return 0;
            }
            node=node->get(word[i]);
        }
        return node->getCp();
    }

    void erase(string &word){
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return;
            }
            node=node->get(word[i]);
            node->decCp();
        }
        node->decEw();
    }
};
