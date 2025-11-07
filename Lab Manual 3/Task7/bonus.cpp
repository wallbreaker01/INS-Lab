#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define yes cout<<"YES"<<endl
#define no cout<<"NO"<<endl
#define pb push_back



string hexToBin(const string hex) {
    string bin;
    for (char character : hex) {
        int value;
        if (character >= '0' && character <= '9') value = character - '0';
        else if (character >= 'a' && character <= 'f') value = 10 + (character - 'a');
        else if (character >= 'A' && character <= 'F') value = 10 + (character - 'A');
        else continue;
        
        bitset<4> b(value);
        bin += b.to_string();
    }
    return bin;
}

int countSameBits(const string h1, const string h2) {
    string b1 = hexToBin(h1);
    string b2 = hexToBin(h2);
    int count = 0;
    for (int i = 0; i < b1.size() && i < b2.size(); i++) {
        if (b1[i] == b2[i]) count++;
    }
    return count;
}

int main() {
    string md5_1 = "3f500f75f9b98c467287eede5e2d0494";
    string md5_2 = "6c55a5cdd966347823fce46d26a99fda";
    string sha_1 = "1b28918dd1b7183d1d250d8f0b58a0f77b4cab66ed0caeee06b078843e407630";
    string sha_2 = "3c3d99bf07397db2dc423a7591d48a0db721873b5d2c46cacd2f0dad0b417e5d";

    int md5_same = countSameBits(md5_1, md5_2);
    int sha_same = countSameBits(sha_1, sha_2);

    cout<<"MD5: "<<md5_same<<"/"<<md5_1.size()*4<<" bits are the same"<<endl;
    cout<<"SHA256: "<<sha_same<<"/"<<sha_1.size()*4<< " bits are the same"<<endl;
}
