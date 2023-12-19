// LEETCODE 208 (IMPLEMENT TRIE (PREFIX TREE))

class Node{
public:
    Node* linkings[26];
    bool isEnd;
    
    void put(char ch, Node* node){
        linkings[ch-'a']=node;
    }
    Node* get(char ch){
        return linkings[ch-'a'];
    }
    bool containsKey(char ch){
        return linkings[ch-'a']!=NULL;
    }
    void setEnd(){
        isEnd=true;
    }
    bool isEnding(){
        return isEnd;
    }
};
class Trie {
private: Node*root;
public:
    Trie() {
        root=new Node(); 
    }
    
    void insert(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                node->put(word[i],new Node());
            }
            node=node->get(word[i]);
        }
        node->setEnd();
    }
    
    bool search(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return node->isEnding();
    }
    
    bool startsWith(string word) {
        Node*node=root;
        for(int i=0;i<word.size();i++){
            if(!node->containsKey(word[i])){
                return false;
            }
            node=node->get(word[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */