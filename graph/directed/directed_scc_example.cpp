//
// Created by xuyc on 2021/1/18.
//

#include "digraph.h"
#include "directed_scc.h"
#include <vector>

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

    // compute the strongly connected component
    KosarajuSCC scc(dg);

    // show all connected components
    cout << "strong components: " << scc.count() << endl;
    vector<vector<int>> components(scc.count());
    for (int v = 0; v < dg.V(); v++) {
        components[scc.id(v)].push_back(v);
    }

    for (int i = 0; i < scc.count(); i++) {
        cout << i << ": ";
        for (auto v : components[i]) {
            cout << v << " ";
        }
        cout << endl;
    }

    cout << endl;
}