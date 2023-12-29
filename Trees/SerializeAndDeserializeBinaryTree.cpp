// LEETCODE 297
// USE LEVEL ORDER TRAVERSAL

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(root==NULL) return "";
        string ans="";
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            TreeNode* f=q.front();
            q.pop();
            if(f==NULL){
                ans.append("#,");
            } else {
                ans.append(to_string(f->val) + ',');
                q.push(f->left);
                q.push(f->right);
            }
        }
        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size()==0){return NULL;}
        stringstream ss(data);
        string str;
        getline(ss,str,',');
        queue<TreeNode*> q;
        TreeNode* root = new TreeNode(stoi(str));
        q.push(root);
        while(!q.empty())
        {
            TreeNode* curr = q.front();
            q.pop();
            
            getline(ss,str,',');
            if(str=="#")
            {
                curr->left=NULL;
            }
            else
            {
                TreeNode* leftNode = new TreeNode(stoi(str));
                curr->left = leftNode;
                q.push(leftNode);
            }
            
            getline(ss,str,',');
            if(str=="#")
            {
                curr->right = NULL;
            }
            else
            {
                TreeNode* rightNode = new TreeNode(stoi(str));
                curr->right = rightNode;
                q.push(rightNode);
            }
        }
      return root;
    }
};