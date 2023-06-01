// Copyright 2021 NNTU-CS
#include  <iostream>
#include  <fstream>
#include  <locale>
#include  <cstdlib>
#include  "bst.h"

BST<std::string> makeTree(const char* filename) {
  BST<std::string> tree;
  std::ifstream file(filename);
  std::string fail;
  while (!file.eof()) {
    int n1 = file.get();
    if (n1 >= 65 && n1 <= 90) {
      n1 += 32;
      fail += n1;
    } else if (n1 >= 97 && n1 <= 122) {
      fail += n1;
    } else {
      tree.add(fail);
      fail = "";
    }
  }
  file.close();
  return tree;
}
