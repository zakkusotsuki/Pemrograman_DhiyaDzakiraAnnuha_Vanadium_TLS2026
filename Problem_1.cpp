.#include <iostream>
using namespace std;

int main() {
    int N, K;
    
    
    cout << "Masukkan jumlah total astronot (N): ";
    cin >> N;
    cout << "Masukkan nilai awal K: ";
    cin >> K;
    
    if (N <= 0 || K <= 0) {
        cout << "Nilai N dan K harus bilangan positif lebih dari 0.\n";
        return 1;
    }
    
    int* astronot = new int[N];
    int* daftar_eliminasi = new int[N - 1]; 
    
    for (int i = 0; i < N; ++i) {
        astronot[i] = i + 1;
    }
    
    int ukuran_sekarang = N;
    int indeks_sekarang = 0;
    int jumlah_tereliminasi = 0;
    
    while (ukuran_sekarang > 1) {
        
        int indeks_gugur = (indeks_sekarang + K - 1) % ukuran_sekarang;
        
        int nomor_gugur = astronot[indeks_gugur];
        daftar_eliminasi[jumlah_tereliminasi] = nomor_gugur;
        jumlah_tereliminasi++;
        
        for (int i = indeks_gugur; i < ukuran_sekarang - 1; ++i) {
            astronot[i] = astronot[i + 1];
        }
        ukuran_sekarang--;
        
        indeks_sekarang = indeks_gugur;
        if (indeks_sekarang >= ukuran_sekarang) {
            indeks_sekarang = 0;
        }
        
        if (nomor_gugur % 2 == 0) {
            K = K + 2;
        } else {
            K = K - 1;
        }
        
        if (K < 2) {
            K = 2;
        }
    }
    
    cout << "Urutan astronot yang dieliminasi: ";
    for (int i = 0; i < jumlah_tereliminasi; ++i) {
        cout << daftar_eliminasi[i];
        if (i < jumlah_tereliminasi - 1) {
            cout << ", ";
        }
    }
    cout << "\n";
    
    cout << "Astronot terakhir yang bertahan (Pemenang): Astronot Nomor " << astronot[0] << "\n";
    
    delete[] astronot;
    delete[] daftar_eliminasi;
    
    return 0;
}
