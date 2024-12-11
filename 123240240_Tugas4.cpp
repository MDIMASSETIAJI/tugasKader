#include <iostream>
using namespace std;


void inputNilai();
void lihatNilai();
void lihatRataRata();
void RataRataTertinggi();
void RataRataTerendah();

int main(){

    int pil;
    char ulang;

    do{
    cout<<"*** MENU ***"<<endl;
    cout<<"[1] Input Nilai "<<endl;
    cout<<"[2] Lihat Nilai  "<<endl;
    cout<<"[3] Lihat Rata-Rata "<<endl;
    cout<<"[4] Rata-Rata Tertinggi "<<endl;
    cout<<"[5] Rata-Rata Terendah "<<endl;
    cout<<"[6] Keluar "<<endl;
    cout<<"Masukkan pilihan (1-6) :";
    cin>>pil;

         switch (pil){

            case 1:
                inputNilai();
            break;

            case 2:
                lihatNilai();
            break;
               
            case 3:
                lihatRataRata();
            break;
                
            case 4:
                RataRataTertinggi();
            break;
        
            case 5:
                RataRataTerendah();
            break;

            case 6:
            cout<<"~~~ ANDA TELAH KELUAR DARI PROGRAM ~~~"<<endl<<endl;
            break;
    
            default:
            cout<<"Pilihan yang anda masukkan tidak valid! "<<endl<<endl;
            break;
        }
        cout<<"ulangi menu (y/n) : ";
        cin>>ulang;
        cout<<endl;

    } while (ulang == 'y' || ulang == 'Y');
}

const int maksimal_mahasiswa = 50;
const int jumlah_matkul = 4;
int jumlah_mahasiswa = 0;
int nilai_mahasiswa [maksimal_mahasiswa] [jumlah_matkul];
string nama_mahasiswa [maksimal_mahasiswa];

double hitungRataRata(int nilai[]){
    int total = 0;
    for(int i = 0; i < jumlah_matkul; i++){
        total += nilai[i];
    }return total / 4.0;
}




void inputNilai(){
    do{
        cout<<"Masukkan jumlah mahasiswa (maks "<<maksimal_mahasiswa<<") : ";
        cin>>jumlah_mahasiswa;

        if(jumlah_mahasiswa > maksimal_mahasiswa){
        cout<<"jumlah mahasiswa melebihi batas maksimal "<<endl;
        cout<<"silahkan masukkan jumlah yang valid!"<<endl;
        }

    }while(jumlah_mahasiswa > maksimal_mahasiswa);

    for(int i = 0; i < jumlah_mahasiswa; i++){
        cout<<"Masukkan nama mahasiswa "<< i + 1<< ": ";
        cin.ignore();
        getline(cin, nama_mahasiswa[i]);
        cout<<"Masukkan nilai untuk "<<nama_mahasiswa[i]<<": "<<endl;

        for(int j = 0; j < jumlah_matkul; j++){
            cout<<"Nilai Mata Kuliah "<<j + 1<<" : ";
            cin>>nilai_mahasiswa[i][j];
        }cout<<endl;
    }


}



void lihatNilai(){
    cout<<"~~~ Lihat Nilai ~~~"<<endl;
    for(int i = 0; i < jumlah_mahasiswa; i++){
        cout<<nama_mahasiswa[i]<<" : ";

        for(int j = 0; j < jumlah_matkul; j++){
        cout<<nilai_mahasiswa[i][j]<<" ";
        }cout<<endl;
    }
}


void lihatRataRata(){
    cout<<"~~~ Lihat Rata Rata ~~~"<<endl;
    for(int i = 0; i < jumlah_mahasiswa; i++){
        cout<<"Mahasiswa "<< i + 1 <<" "<<endl;
        cout<<"Nama      : "<<nama_mahasiswa[i]<<endl;
        cout<<"Rata-Rata : "<<hitungRataRata(nilai_mahasiswa[i])<<endl;
        cout<<endl;
    }
}


void RataRataTertinggi(){
    if(jumlah_mahasiswa == 0)return;

    double tertinggi = hitungRataRata(nilai_mahasiswa[0]);
    string namaTertinggi = nama_mahasiswa[0];

    for(int i = 0; i < jumlah_mahasiswa; i++){
        double rata = hitungRataRata(nilai_mahasiswa[i]);
        if(rata > tertinggi){
            tertinggi = rata;
            namaTertinggi = nama_mahasiswa[i];
        }
    }

    cout<<"~~~ Rata-Rata Tertinggi ~~~ "<<endl;
    cout<<"Mahasiswa denngan nilai tertinggi :"<<endl;
    cout<<"~ Nama      : "<<namaTertinggi<<endl;
    cout<<"~ Rata-Rata : "<<tertinggi<<endl;
}


void RataRataTerendah(){
    if(jumlah_mahasiswa == 0)return;

    double terendah = hitungRataRata(nilai_mahasiswa[0]);
    
    string namaTerendah = nama_mahasiswa[0];

    for(int i = 0; i < jumlah_mahasiswa; i++){
        double rata = hitungRataRata(nilai_mahasiswa[i]);
        if(rata < terendah){
            terendah = rata;
            namaTerendah = nama_mahasiswa[i];
        }
    }

    cout<<"~~~ Rata-Rata Terendah ~~~ "<<endl;
    cout<<"Mahasiswa denngan nilai terendah :"<<endl;
    cout<<"~ Nama      : "<<namaTerendah<<endl;
    cout<<"~ Rata-Rata : "<<terendah<<endl;
}