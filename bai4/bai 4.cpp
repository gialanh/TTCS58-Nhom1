#include <iostream>
#include <fstream>
#include <sstream>
#include <string.h>
#include <vector>

using namespace std;

int n, p, biendem;
vector<int> a, b;

void docfile();
bool kiemtra(vector<int> bin);
void quaylui(vector<int> bin, int n, int i = 0);
void trakq(vector<int> bin);

void ghifile();

void docfile() {
    ifstream f;
      f.open("input4.txt");

    if(f.is_open()) {
        string line;
        getline(f, line);
        stringstream ss(line);
        ss >> n >> p;

        getline(f, line);
        stringstream sss(line);
        a.resize(n);
        for(int i = 0; i < n; i++) {
            sss >> a[i];
        }
    } else {
        cout << "khong mo duoc file" << endl;
    }

      f.close();
}
bool kiemtra(vector<int> bin) {

    int chon = 0;
    for(int i = 0; i < n; i++) {
        chon += bin[i] * a[i];
    }
    if(chon == p)
        return true;
    return false;
}
void chenkq(vector<int> bin) {
       b.insert(b.begin(), bin.begin(), bin.end());
}
void quaylui(vector<int> bin, int n, int i) {
    for(int j = 0; j <= 1; j++) {
        bin[i] = j;
    
        if(i == n - 1) {
            if(kiemtra(bin)) {
                chenkq(bin);
                biendem++;
            }
        } else {
            quaylui(bin, n, i + 1);
        }
    }
}
void showkq() {
    int s = b.size();
    for(int i = 0; i < s; i++) {
        if(i % n == 0) {
            cout << endl;
        }
        cout << b[i] << " ";
    } cout << endl;
}
void ghifile() {
    ofstream f;
      f.open("output4.txt");

    if(biendem) {
        f << biendem;

        int tmp = b.size();
        for(int i = 0; i < tmp; i++) {
            if(i % n == 0) {
                f << endl;
            }
            f << b[i] << " ";
        }
    } else {
        f << "Khong chia duoc" << endl;
    }
    f.close();
    cout << "tra ket qua ve file output4.txt";
}
int main() {
  docfile();
    cout << n  <<  p << endl;
    cout<<"-------------" ;
    vector<int> bin;
    bin.resize(n);
   quaylui(bin, n);
    if(biendem) {
        cout << biendem;
        showkq();
    } else {
        cout << "Khong chia duoc" << endl;
    }
   ghifile();
}
