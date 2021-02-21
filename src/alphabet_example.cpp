//
// Created by 徐元昌 on 2021/2/21.
//

#include "alphabet.h"
#include <iostream>
using namespace std;
using namespace algs4;


int main(int argc, const char *argv[])
{
    Alphabet alphabet;
    shared_ptr<int> encoded1 = alphabet.BASE64->toIndices("NowIsTheTimeForAllGoodMen");
    String decoded1 = alphabet.BASE64->toChars(encoded1);
    StdOut.println(decoded1);

    int[]  encoded2 = Alphabet.DNA.toIndices("AACGAACGGTTTACCCCG");
    String decoded2 = Alphabet.DNA.toChars(encoded2);
    StdOut.println(decoded2);

    int[]  encoded3 = Alphabet.DECIMAL.toIndices("01234567890123456789");
    String decoded3 = Alphabet.DECIMAL.toChars(encoded3);
    StdOut.println(decoded3);
}
