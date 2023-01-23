#include <iostream>
using namespace std;

void tukarData(int *a, int*b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_short(int pendataan[], int n){
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            if (pendataan[i] < pendataan[j])
            {
                tukarData(&pendataan[i], &pendataan[j]);
            }
        }
    }
}

void insertion_short(int pendataan[], int n){
    int i, j, hasil;
    bool found;
    for (int i = 1; i < n; i++)
    {
        hasil = pendataan[i];
        j = i-1;
        found = false;
        while (j >= 0 && !found)
        {
            if (hasil > pendataan[j])
            {
                pendataan[j+1] = pendataan[j];
                j=j-1;
            }
            else
            {
                found = true;
            } 
        }
        pendataan[j+1] = hasil;
    }
    
}

void selection_sort(int pendataan[], int n){
    int temp, min;
    for (int i = 0; i < n-1; i++)
    {
        min = i;
        for (int j = i+1; j < n; j++)
        {
            if (pendataan[j] > pendataan[min])
            {
                min = j;
            }
        }
        temp = pendataan[i];
        pendataan[i] = pendataan[min];
        pendataan[min] = temp;
    }
    
}

int funcbinary (int data[], int n, int k)
{
 int atas,bawah,tengah,posisi;
 bool ada;

 ada    = false;
 bawah  = 0;
 atas   = n - 1;
 posisi = -1;

 while (bawah <= atas)
 {
  tengah = (atas + bawah) / 2;
  if (k == data[tengah])
  {
   posisi = tengah;
   break;
  }
 else if (k < data[tengah]) atas = tengah - 1;
 else if (k > data[tengah]) bawah= tengah + 1;
 }
 return posisi;
}

int main() {
  int pilihan, n, dataCari, hasilCari;
  int pendataan[5];
  int angka[] = {10, 3, 5, 8, 7, 1};
  int length = sizeof(angka)/sizeof(*angka);
  char z;

  do
  {
    system("cls");
    cout<<"1. Bubble Sort"<<endl;
    cout<<"2. Insertion Sort"<<endl;
    cout<<"3. Selection Sort"<<endl;
    cout<<"4. Binary Search"<<endl;
    cout<<"5. Keluar Dari Program"<<endl;
    cout<<"Masukan Data Yang Ingin Dipilih: ";
    cin>>pilihan;

    if(pilihan == 1){
        system("cls");
        cout<<"---------------"<<endl;
        cout<<"- Bubble Sort -"<<endl;
        cout<<"---------------"<<endl;
        cout<<"Masukan Banyak Data: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout<<"Masukan Data Ke-"<<i+1<<": ";
            cin >> pendataan[i];
        }
        cout<<"\n Data Sebelum Diurutkan: ";
        for (int i = 0; i < n; i++)
        {
            cout<< pendataan[i] << " ";
        }
        bubble_short(pendataan, n);
        cout<<"\n Data Setelah Diurutkan: ";
        for (int i = 0; i < n; i++)
        {
            cout<<pendataan[i]<<" ";
        }
        cout<<"\nTekan Tombol Apa Saja: ";
        cin>>z;
    }
    else if (pilihan == 2)
    {
        system("cls");
        cout<<"------------------"<<endl;
        cout<<"- Insertion Sort -"<<endl;
        cout<<"------------------"<<endl;
        cout<<"Masukan Banyak Data: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout<<"Masukan Data Ke-"<<i+1<<": ";
            cin >> pendataan[i];
        }
        cout<<"\n Data Sebelum Diurutkan: ";
        for (int i = 0; i < n; i++)
        {
            cout<< pendataan[i]<< " ";
        }
        insertion_short(pendataan, n);
        cout<<"\n Data Setelah Diurutkan: ";
        for (int i = 0; i < n; i++)
        {
            cout<< pendataan[i]<< " ";
        }
        cout<<"\nTekan Tombol Apa Saja: ";
        cin>>z;
    }
    else if(pilihan == 3){
        system("cls");
        cout<<"------------------"<<endl;
        cout<<"- Selection Sort -"<<endl;
        cout<<"------------------"<<endl;
        cout<<"Masukan Banyak Data: ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            cout<<"Masukan Data Ke-"<<i+1<<": ";
            cin >> pendataan[i];
        }
        cout<<"\n Data Sebelum Diurutkan: ";
        for (int i = 0; i < n; i++)
        {
            cout<< pendataan[i]<< " ";
        }
        selection_sort(pendataan, n);
        cout<<"\n Data Setelah Diurutkan: ";
        for (int i = 0; i < n; i++)
        {
            cout<< pendataan[i]<< " ";
        }
        cout<<"\nTekan Tombol Apa Saja: ";
        cin>>z;
    }
    else if (pilihan == 4)
    {   
        system("cls");
        cout<<"-----------------"<<endl;
        cout<<"- Binary Search -"<<endl;
        cout<<"-----------------"<<endl;
        int kk;
        int n= 10;
        int data[] = {20,28,34,52,54,60,73,80,91,100};
        cout<<"20,28,34,52,54,60,73,80,91,100"<<endl;
        cout << "Iput Angka Yang Ingin Dicari : "; cin >> kk;
        int posisi = funcbinary (data,n,kk);
        if (posisi != -1)
        {
        cout << "ANGKA " << kk << " ditemukan pada urutan ke-" << posisi << endl;
        cout<<"Ingin mengulang lagi? (y/t): ";cin>>z;
        }
        else
        {
        cout << "ANGKA " << kk << " tidak ditemukan" << endl;
        cout<<"\nTekan Tombol Apa Saja: ";
        cin>>z;
        }
    }
    else if (pilihan == 5)
    {
        system("cls");
        exit(0);
    }
    
    
  } while (pilihan);
  
  return 0;
}