#include <iostream>
using namespace std;

int main() {
    
    char pesan_asli[1000];
    char pesan_sandi[1000];
    
    cout << "Masukkan pesan asli (Gunakan Huruf Kapital tanpa spasi): ";
    cin >> pesan_asli;
    
    int panjang = 0;
    while (pesan_asli[panjang] != '\0') {
        panjang++;
    }
    
    if (panjang == 0) {
        return 0;
    }
    
    pesan_sandi[0] = pesan_asli[0];
    
    for (int i = 1; i < panjang; i++) {
        
        int nilai_sekarang = pesan_asli[i] - 'A' + 1;
        int nilai_sebelumnya = pesan_asli[i - 1] - 'A' + 1;
        
        int nilai_baru = nilai_sekarang + nilai_sebelumnya;
        
        int nilai_sandi = ((nilai_baru - 1) % 26) + 1;
        
        pesan_sandi[i] = (char)(nilai_sandi - 1 + 'A');
    }
    
    pesan_sandi[panjang] = '\0';
    
    cout << "Pesan sandi: " << pesan_sandi << "\n";
    
    return 0;
}