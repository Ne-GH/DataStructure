/*********************************************************************
 * Auther : yongheng
 * Date : 2022/10/19 15:46
*********************************************************************/
#ifndef DATASTRUCTURE_BINARYTREE_H
#define DATASTRUCTURE_BINARYTREE_H
#include <iostream>

template<typename T>
class TreeNode{
public:
    T _val;
    TreeNode *_left;
    TreeNode *_right;
    TreeNode(){  }
    TreeNode(T val){
        _val = val;
    }
    friend std::ostream & operator << (std::ostream &out,TreeNode node){
        out << node._val;
        return out;
    }
    friend std::ostream & operator << (std::ostream &out,TreeNode *pnode){
        out << pnode->_val;
        return out;
    }
};



template<typename T>
class BinaryTree{

    TreeNode<T> *_root;
public:
    BinaryTree(){
        _root = new TreeNode<T>();
        _root->_left = _root->_right = nullptr;
    }
    BinaryTree(T data){
        new (this)BinaryTree();
        _root->_val = data;
    }


    void Insert(T data){

        _Insert(_root,data);


    }
    void PreOrderTraversal(){
        _PreOrderTraversal(_root);
    }
    void LnOrderTraversal(){
        _LnOrderTraversal(_root);
    }
    void PostOrderTraversal(){
        _PostOrderTraversal(_root);
    }
    void Destroy(){
        _Destroy(_root);
        _root = nullptr;
    }
    ~BinaryTree(){
        Destroy();
    }

    void Output(){
        output(_root);
    }


    TreeNode<T> *Root(){
        return _root;
    }

    friend std::ostream & operator << (std::ostream &out,BinaryTree * bt){
        out << bt->_val;
        return out;
    }

};
template<typename T>
void _PreOrderTraversal(TreeNode<T> *root){
    if(root == nullptr)
        return;
    std::cout << root->_val << " ";
    _PreOrderTraversal(root->_left);
    _PreOrderTraversal(root->_right);
}

template<typename T>
void _LnOrderTraversal(TreeNode<T> *root){
    if(root == nullptr)
        return;

    _LnOrderTraversal(root->_left);
    std::cout << root->_val << " ";
    _LnOrderTraversal(root->_right);

}
template<typename T>
void _PostOrderTraversal(TreeNode<T> *root){
    if(root == nullptr)
        return;
    _PostOrderTraversal(root->_left);
    _PostOrderTraversal(root->_right);
    std::cout << root->_val << " ";
}

/* 带头节点一起销毁 */
template<typename T>
void _Destroy(TreeNode<T> *root){

    if(root != nullptr){
        if(root->_left != nullptr){
            _Destroy(root->_left);
        }
        if(root->_right != nullptr){
            _Destroy(root->_right);
        }

        delete root;
    }

    else{
        return;
    }
    return;
}
template<typename T>
void _Insert(TreeNode<T> *root,T data){
    if(root == nullptr)
        return;

    if(root->_val > data){
        if(root->_left == nullptr){
            TreeNode<T> *node = new TreeNode<T>(data);
            root->_left = node;
            node->_left = node->_right = nullptr;
        }
        else{
            _Insert(root->_left,data);
        }
    }
        /* root->val <= data */
    else{
        if(root->_right == nullptr){
            TreeNode<T> *node = new TreeNode<T>(data);
            root->_right = node;
            node->_left = node->_right = nullptr;
        }
        else{
            _Insert(root->_right,data);
        }
    }

}

template<typename T>
void output_impl(TreeNode<T> *n, bool left, std::string const& indent)
{
    if (n->_right)
    {
        output_impl(n->_right, false, indent + (left ? "|     " : "      "));
    }
    std::cout << indent;
    std::cout << (left ? '\\' : '/');
    std::cout << "-----";
    std::cout << n->_val << std::endl;
    if (n->_left)
    {
        output_impl(n->_left, true, indent + (left ? "      " : "|     "));
    }
}
template<typename T>
void output(TreeNode<T>* root)
{
    if (root->_right)
    {
        output_impl(root->_right, false, "");
    }
    std::cout << root->_val << std::endl;
    if (root->_left)
    {
        output_impl(root->_left, true, "");
    }

}



#endif //DATASTRUCTURE_BINARYTREE_H
