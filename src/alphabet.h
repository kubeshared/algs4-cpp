//
// Created by 徐元昌 on 2021/2/20.
//

#ifndef SRC_ALPHABET_H
#define SRC_ALPHABET_H

#include <string>
#include <memory>

using namespace std;


namespace algs4 {
    class Alphabet;
    class Alphabet {
    public:
    /**
    *  The binary alphabet { 0, 1 }.
    */
    Alphabet * BIN = new Alphabet("01");

        /**
         *  The octal alphabet { 0, 1, 2, 3, 4, 5, 6, 7 }.
         */
     Alphabet * OCTAL = new  Alphabet("01234567");

        /**
         *  The decimal alphabet { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }.
         */
   Alphabet * DECIMAL = new  Alphabet("0123456789");

        /**
         *  The hexadecimal alphabet { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, A, B, C, D, E, F }.
         */
  Alphabet * HEXADECIMAL = new  Alphabet("0123456789ABCDEF");

        /**
         *  The DNA alphabet { A, C, T, G }.
         */
    Alphabet * DNA = new  Alphabet("ACGT");

        /**
         *  The lowercase alphabet { a, b, c, ..., z }.
         */
    Alphabet * LOWERCASE = new Alphabet("abcdefghijklmnopqrstuvwxyz");

        /**
         *  The uppercase alphabet { A, B, C, ..., Z }.
         */

    Alphabet * UPPERCASE = new Alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZ");

        /**
         *  The protein alphabet { A, C, D, E, F, G, H, I, K, L, M, N, P, Q, R, S, T, V, W, Y }.
         */
    Alphabet * PROTEIN = new Alphabet("ACDEFGHIKLMNPQRSTVWY");

        /**
         *  The base-64 alphabet (64 characters).
         */
    Alphabet * BASE64 = new Alphabet("ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/");

        /**
         *  The ASCII alphabet (0-127).
         */
    Alphabet * ASCII = new Alphabet(128);

        /**
         *  The extended ASCII alphabet (0-255).
         */
    Alphabet * EXTENDED_ASCII = new Alphabet(256);

        /**
         *  The Unicode 16 alphabet (0-65,535).
         */
    Alphabet * UNICODE16      = new Alphabet(65536);
    public:
        Alphabet();

        ~Alphabet();

        Alphabet(int radix);

        Alphabet(const string &s);

        inline char toChar(int index);

        inline int toIndex(char c);

        inline bool contains(char c);

        inline int R();

        inline int lgR();

        shared_ptr<int> toIndices(const string& s);

        string toChars(const int *indices, int n);

    private:
        void initAlphabet() {
            for (int i = 0; i < _radix; i++) {
                _alphabets[i] = static_cast<char>(i);
            }

            for (int i = 0; i < _radix; i++) {
                _inverse[i] = i;
            }
        };

        int _radix;
        char * _alphabets;
        int *_inverse;
        const int UNICODE = 65536;
    };
}



#endif //SRC_ALPHABET_H
