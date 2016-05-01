/**********************************************************************
用递归实现：
序列化二叉树，按照先序遍历二叉树的顺序，先左节点，后右节点，当到‘#’时
候，说明左节点或者右节点为NULL，同样反序列二叉树也一个道理，需要注意的
是在序列和反序列二叉树的时候，注意字符串与整数的转换，一般字符串转换为
整数，用迭代循环实现，整数转换为字符串可以用sprintf实现或者itoa实现
*********************************************************************/

/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
public:
    char* Serialize(TreeNode *root) 
    {    
        if(root == NULL)
            return NULL;
        string str;
        Serialize(root,str);
        return const_cast<char* >(str.c_str());
    }
    TreeNode* Deserialize(char *str) 
    {
    	if(str == NULL || *str == '\0')
            return NULL;
        int num = 0;
        return Deserialize(str,num);
    }
private:
    void Serialize(TreeNode *root,string &str)
    {
        if(root == NULL)
        {
            str += "#,";
            return;
        }
        char ch[10];
        sprintf(ch,"%d",root->val);
        str+=ch;
        str+=',';
        Serialize(root->left,str);
        Serialize(root->right,str);
    }
    TreeNode* Deserialize(char *str, int &num)
    {
       int val = 0;
      /* if(str[num] == '\0')
       {
          return NULL;
       }*/
       if(str[num] == '#')
       {
           num = num + 2;
           return NULL;
       }
       while(str[num] != ',' && str[num] != '\0')
       {
           val = 10*val + str[num] - '0';
           num++;
       }
        num++;
        TreeNode* root = new TreeNode(val);
        
        root->left = Deserialize(str,num);
        root->right = Deserialize(str,num);
        return root;
     }
};
