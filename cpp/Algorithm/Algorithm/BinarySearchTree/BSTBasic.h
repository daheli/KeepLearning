//
//  BSTBasic.h
//  Algorithm
//
//  Created by lidahe on 2018/1/17.
//  Copyright © 2018年 lidahe. All rights reserved.
//

#ifndef BSTBasic_h
#define BSTBasic_h

#include <queue>

template <typename Key, typename Value>
class BST{

private:
    // 二分搜索树中的节点为私有的结构体, 外界不需要了解二分搜索树节点的具体实现
    struct Node{
        Key key;
        Value value;
        Node *left;
        Node *right;
        
        Node(Key key, Value value){
            this->key = key;
            this->value = value;
            this->left = this->right = NULL;
        }
    };
    
    Node *root; // 根节点
    int count;  // 节点个数

public:
    // 构造函数, 默认构造一棵空二分搜索树
    BST(){
        root = NULL;
        count = 0;
    }
    ~BST(){
        destroy( root );
    }
    
    // 返回二分搜索树的节点个数
    int size(){
        return count;
    }
    
    // 返回二分搜索树是否为空
    bool isEmpty(){
        return count == 0;
    }
    
    // 查看二分搜索树中是否存在键key
    bool contain(Key key){
        return contain(root, key);
    }
    
    // 向二分搜索树中插入一个新的(key, value)数据对
    void insert(Key key, Value value){
        root = insert(root, key, value);
    }

    // 在二分搜索树中搜索键key所对应的值。如果这个值不存在, 则返回NULL
    Value *search(Key key){
        return search( root , key );
    }
    
    // 二分搜索树的前序遍历
    void preOrder(){
        preOrder(root);
    }
    
    // 二分搜索树的中序遍历
    void inOrder(){
        inOrder(root);
    }
    
    // 二分搜索树的后序遍历
    void postOrder(){
        postOrder(root);
    }
    
    // 二分搜索树的层序遍历
    void levelOrder(){
        queue<Node*> q;
        q.push(root);
        while( !q.empty() ){
            Node *node = q.front();
            q.pop();
            
            cout<<node->key<<endl;
            
            if( node->left )
                q.push( node->left );
            if( node->right )
                q.push( node->right );
        }
    }
    
private:
    // 向以node为根的二分搜索树中, 插入节点(key, value), 使用递归算法
    // 返回插入新节点后的二分搜索树的根
    Node *insert(Node *node, Key key, Value value) {
        if(node == NULL) {
            count++;
            return new Node(key, value);
        }
        if(key < node->key) {
            node->left = insert(node->left, key, value);
        } else if(key > node->key) {
            node->right = insert(node->right, key, value);
        } else {
            node->value = value;
        }
        
        return node;
    }
    
    // 查看以node为根的二分搜索树中是否包含键值为key的节点, 使用递归算法
    bool contain(Node* node, Key key){
        
        if( node == NULL )
            return false;
        
        if( key == node->key )
            return true;
        else if( key < node->key )
            return contain( node->left , key );
        else // key > node->key
            return contain( node->right , key );
    }
    
    Value *search(Node* node, Key key){
        if( node == NULL )
            return NULL;
        
        if( key == node->key )
            return &(node->value);
        else if( key < node->key )
            return search( node->left , key );
        else // key > node->key
            return search( node->right, key );
    }
    
    // 对以node为根的二叉搜索树进行前序遍历, 递归算法
    void preOrder(Node* node){
        
        if( node != NULL ){
            cout<<node->key<<endl;
            preOrder(node->left);
            preOrder(node->right);
        }
    }
    
    // 对以node为根的二叉搜索树进行中序遍历, 递归算法
    void inOrder(Node* node){
        
        if( node != NULL ){
            inOrder(node->left);
            cout<<node->key<<endl;
            inOrder(node->right);
        }
    }
    
    // 对以node为根的二叉搜索树进行后序遍历, 递归算法
    void postOrder(Node* node){
        
        if( node != NULL ){
            postOrder(node->left);
            postOrder(node->right);
            cout<<node->key<<endl;
        }
    }
    
    // 释放以node为根的二分搜索树的所有节点
    // 采用后续遍历的递归算法
    void destroy(Node* node){
        
        if( node != NULL ){
            destroy( node->left );
            destroy( node->right );
            
            delete node;
            count --;
        }
    }
    
    // 返回以node为根的二分搜索树的最小键值所在的节点, 递归算法
    Node* minimum(Node* node){
        if( node->left == NULL )
        return node;
        
        return minimum(node->left);
    }
    
    // 返回以node为根的二分搜索树的最大键值所在的节点, 递归算法
    Node* maximum(Node* node){
        if( node->right == NULL )
        return node;
        
        return maximum(node->right);
    }
    
    // 删除掉以node为根的二分搜索树中的最小节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* removeMin(Node* node){
        
        if( node->left == NULL ){
            
            Node* rightNode = node->right;
            delete node;
            count --;
            return rightNode;
        }
        
        node->left = removeMin(node->left);
        return node;
    }
    
    // 删除掉以node为根的二分搜索树中的最大节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* removeMax(Node* node){
        
        if( node->right == NULL ){
            
            Node* leftNode = node->left;
            delete node;
            count --;
            return leftNode;
        }
        
        node->right = removeMax(node->right);
        return node;
    }
    
    // 删除掉以node为根的二分搜索树中键值为key的节点, 递归算法
    // 返回删除节点后新的二分搜索树的根
    Node* remove(Node* node, Key key){
        
        if( node == NULL )
            return NULL;
        
        if( key < node->key ){
            node->left = remove( node->left , key );
            return node;
        }
        else if( key > node->key ){
            node->right = remove( node->right, key );
            return node;
        }
        else{   // key == node->key
            
            if( node->left == NULL ){
                Node *rightNode = node->right;
                delete node;
                count --;
                return rightNode;
            }
            
            if( node->right == NULL ){
                Node *leftNode = node->left;
                delete node;
                count--;
                return leftNode;
            }
            
            // node->left != NULL && node->right != NULL
            Node *successor = new Node(minimum(node->right));
            count ++;
            
            successor->right = removeMin(node->right);
            successor->left = node->left;
            
            delete node;
            count --;
            
            return successor;
        }
    }
    
    // 在以node为根的二叉搜索树中, 寻找key的floor值所处的节点, 递归算法
    Node* floor(Node* node, Key key){
        
        if( node == NULL )
            return NULL;
        
        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的floor节点
        if( node->key == key )
            return node;
        
        // 如果node的key值比要寻找的key值大
        // 则要寻找的key的floor节点一定在node的左子树中
        if( node->key > key )
            return floor( node->left , key );
        
        // 如果node->key < key
        // 则node有可能是key的floor节点, 也有可能不是(存在比node->key大但是小于key的其余节点)
        // 需要尝试向node的右子树寻找一下
        Node* tempNode = floor( node->right , key );
        if( tempNode != NULL )
            return tempNode;
        
        return node;
    }
    
    
    // 在以node为根的二叉搜索树中, 寻找key的ceil值所处的节点, 递归算法
    Node* ceil(Node* node, Key key){
        
        if( node == NULL )
            return NULL;
        
        // 如果node的key值和要寻找的key值相等
        // 则node本身就是key的ceil节点
        if( node->key == key )
            return node;
        
        // 如果node的key值比要寻找的key值小
        // 则要寻找的key的ceil节点一定在node的右子树中
        if( node->key < key )
            return ceil( node->right , key );
        
        // 如果node->key > key
        // 则node有可能是key的ceil节点, 也有可能不是(存在比node->key小但是大于key的其余节点)
        // 需要尝试向node的左子树寻找一下
        Node* tempNode = ceil( node->left , key );
        if( tempNode != NULL )
            return tempNode;
        
        return node;
    }
};

#endif /* BSTBasic_h */
