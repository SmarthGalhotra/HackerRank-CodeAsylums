/*
class Node {
    public:
        int data;
        Node *left;
        Node *right;
        Node(int d) {
            data = d;
            left = NULL;
            right = NULL;
        }
};

*/
void topView(Node * root) {
    queue<pair<Node*, int>> q;
    q.push(make_pair(root,0));
    map<int,int> m;
    while(q.empty() == false){
        Node* node = q.front().first;
        int node_counter = q.front().second;

        int node_val = node->data;

        q.pop();

        if(m.find(node_counter) == m.end())
            m[node_counter] = node_val;

        if(node->left)
            q.push(make_pair(node->left,node_counter-1));
        if(node->right)
            q.push(make_pair(node->right, node_counter+1));

    }
    map<int,int> :: iterator itr;
    for(itr = m.begin(); itr!= m.end(); itr++){
        cout<<itr->second<<" ";
    }
}
