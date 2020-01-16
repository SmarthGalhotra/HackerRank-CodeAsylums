/*The tree node has data, left child and right child
class Node {
    int data;
    Node* left;
    Node* right;
};

*/
int getHeight(Node* root , int height){
    if(root == NULL){
        return height-1;
    }
    return (max(getHeight(root->left,height+1),getHeight(root->right,height+1)));
}
    int height(Node* root) {
        if(root->left == NULL && root->right == NULL) return 0;
        int h = getHeight(root,0);
        return h;
    }
