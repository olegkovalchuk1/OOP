#include <iostream>
#include "BitStringPub.h"
#include "BitStringPriv.h"

using namespace std;

#pragma pack(push, 1)
struct BitStringPack {
    long high;
    long low;
};
#pragma pack(pop)

int main() {
    cout << "Size of BitStringBase: " << sizeof(BitStringBase) << " bytes" << endl;
    cout << "Size of struct (pack 1): " << sizeof(BitStringPack) << " bytes\n\n";

    // --- ÄÅÌÎÍÑÒÐÀÖ²ß Â²ÄÊÐÈÒÎÃÎ ÓÑÏÀÄÊÓÂÀÍÍß ---
    cout << "==== PUBLIC INHERITANCE (BitStringPub) ====" << endl;
    BitStringPub pub1;
    BitStringPub pub2(15, 255);
    BitStringPub pub3 = pub2;

    cout << "pub1 (default): " << pub1 << endl;
    cout << "pub2 (init)   : " << pub2 << endl;

    cout << "\nInput pub1:" << endl;
    cin >> pub1;
    cout << "pub1 is now   : " << pub1 << endl;

    cout << "\nOperations:" << endl;
    cout << "++pub2 : " << ++pub2 << endl;
    cout << "~pub2  : " << ~pub2 << endl;
    cout << "pub1 & pub2 : " << (pub1 & pub2) << endl;


    // --- ÄÅÌÎÍÑÒÐÀÖ²ß ÇÀÊÐÈÒÎÃÎ ÓÑÏÀÄÊÓÂÀÍÍß ---
    cout << "\n==== PRIVATE INHERITANCE (BitStringPriv) ====" << endl;
    BitStringPriv priv1;
    BitStringPriv priv2(10, 100);

    cout << "priv2 (init)  : " << priv2 << endl; // Ïðàöþº çàâäÿêè ÿâíîìó ïåðåâàíòàæåííþ <<

    cout << "\nInput priv1:" << endl;
    cin >> priv1; // Ïðàöþº çàâäÿêè ÿâíîìó ïåðåâàíòàæåííþ >>
    cout << "priv1 is now  : " << priv1 << endl;

    cout << "priv1 | priv2 : " << (priv1 | priv2) << endl;

    return 0;
}