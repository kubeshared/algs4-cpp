//
// Created by xuyc on 2021/1/20.
//

#include "directed_dfs_order.h"

int main(int argc, const char *argv[])
{
    if (argc != 2) {
        perror("Error no invalid input");
        exit(1);
    }

    string filename(argv[1]);
    fstream in(filename);
    Digraph dg(in);
    in.close();

    DepthFirstOrder order(dg);

    queue<int> pre = *order.pre();
    cout <<  "pre order: " << endl;
    while (!pre.empty()) {
        cout << pre.front() << " ";
        pre.pop();
    }
    cout << endl;

    queue<int> post = *order.post();
    cout <<  "post order: " << endl;
    while (!post.empty()) {
        cout << post.front() << " ";
        post.pop();
    }
    cout << endl;

    stack<int> reversePost = *order.reversePost();
    cout <<  "reverse post order: " << endl;
    while (!reversePost.empty()) {
        cout << reversePost.top() << " ";
        reversePost.pop();
    }
    cout << endl;
}