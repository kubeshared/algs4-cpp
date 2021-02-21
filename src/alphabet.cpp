//
// Created by 徐元昌 on 2021/2/20.
//

#include "alphabet.h"

using namespace algs4;

Alphabet::Alphabet() {
    _radix = 256;
    _alphabets = new char[_radix];
    _inverse = new int[_radix];
    initAlphabet();
}

Alphabet::~Alphabet() {
    delete [] _alphabets;
    delete [] _inverse;
    delete BIN;
    delete OCTAL;
    delete DECIMAL;
    delete HEXADECIMAL;
    delete DNA;
    delete LOWERCASE;
    delete UPPERCASE;
    delete PROTEIN;
    delete BASE64;
    delete ASCII;
    delete EXTENDED_ASCII;
    delete UNICODE16;
}

Alphabet::Alphabet(int radix) {
    _radix = radix;
    _alphabets = new char[_radix];
    _inverse = new int[_radix];
    initAlphabet();
}

Alphabet::Alphabet(const string &s) {
    // check that alphabet contains no duplicate chars
    bool * unicode = new bool[UNICODE];
    for (int i = 0; i < s.length(); i++) {
        char c = s[i];
        assert(!unicode[c]);
        unicode[c] = true;
    }

    _radix = s.length();
    _alphabets = new char [s.length()];
    for (int i = 0; i < s.length(); i++) {
        _alphabets[i] = s[i];
    }

    _inverse = new int [UNICODE];
    for (int i = 0; i < UNICODE; i++) {
        _inverse[i] = -1;
    }

    for (int c = 0; c < s.length(); c++) {
        _inverse[_alphabets[c]] = c;
    }
}

inline char Alphabet::toChar(int index) {
    assert(index >= 0 || index < _radix);
    return _alphabets[index];
}

inline int Alphabet::toIndex(char c) {
    return _inverse[c];
}

inline bool Alphabet::contains(char c) {
    return _inverse[c] != -1;
}

inline int Alphabet::R() {
    return _radix;
}

// 表示一个65536 = 2^16, 即需要16bit. 要求 x, lg^x = 65536, x = 16
inline int Alphabet::lgR() {
    int lgR = 0;
    for (int x = _radix - 1; x >= 1; x /= 2) {
        lgR++;
    }
    return lgR;
}

shared_ptr<int> Alphabet::toIndices(const string& s) {
    shared_ptr<int> indices(new int[s.length()]);
    for (int i = 0; i < s.length(); i++) {
        indices.get()[i] = toIndex(s[i]);
    }
    return indices;
}

string Alphabet::toChars(const int *indices, int n) {
    string s;
    for (int i = 0; i < n; i++) {
        s.push_back(_alphabets[indices[i]]);
    }

    return move(s);
}