#include "btreenode.h"
#include <iostream>

BTreeNode::BTreeNode(int _t, bool _leaf) {
    t = _t;
    leaf = _leaf;
    keys = new int[2*t - 1];
    C = new BTreeNode *[2*t];
    n = 0;
}

void BTreeNode::traverse() {
    int i;
    for (i = 0; i < n; i++) {
        if (!leaf) {
            C[i]->traverse();
        }
        std::cout << " " << keys[i];
    }
    if (!leaf) {
        C[i]->traverse();
    }
}

BTreeNode* BTreeNode::search(int k) {
    int i = 0;
    while (i < n  && k > keys[i]) {
        i++;
    }
    if (keys[i] == k) {
        return this;
    }
    if (leaf) {
        return NULL;
    }
    return C[i]->search(k);
}
