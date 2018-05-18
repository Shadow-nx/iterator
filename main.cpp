#include <iostream>
#include "tree.hpp"

using namespace BSTree;

int main() {

    Tree<int> tree = {5, 3, 4, 2, 7, 9, 6, 8};

    auto it = tree.begin();
    //auto end = tree.end();

    for (int i=0; i < 8; ++it,i++ ) {
          std::cout << *it << ' ';
      }

/*
    auto rit = tree.rbegin();
    auto rend = tree.rend();
    for(; rit != rend; ++rit) {
      std::cout << *it << ' ';
    }
    std::cout << std::endl;
    */
    return 0;

}
