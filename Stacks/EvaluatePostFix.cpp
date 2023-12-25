//LEETCODE 150

class Solution {
public:
    int eval(int a,int b,char c){
        if(c=='+') return b+a;
        if(c=='-') return b-a;
        if(c=='*') return b*a;
        return b/a;
    }
    int evalRPN(vector<string>& v) {
        stack<int> s;
        for(int i=0;i<v.size();i++){
            string a=v[i];
            if(isdigit(a[0]) || (a.size()>1 && isdigit(a[1]))){
                int temp=0;
                int k=0;
                if(a[0]=='-') k=1;
                for(int i=k;i<a.size();i++){
                    temp=temp*10+a[i]-'0';
                }
                if(k==1) temp=-temp;
                s.push(temp);
            }
            else{
                int k=s.top();
                s.pop();
                int b=s.top();
                s.pop();
                int c=eval(k,b,a[0]);
                s.push(c);
            }
        }
        return s.top();
    }
};