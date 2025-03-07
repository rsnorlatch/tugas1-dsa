#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <string>
#include <utility>

using namespace std;

// a->b adalah singkatan dari (*a).b

typedef struct {
  string judul;
  string penyanyi;
  string genre;
  int tahun_lagu;
} Lagu;

Lagu LAGU_KOSONG = {};

typedef struct {
  Lagu antrean[500];
  int jumlah;
} Playlist;

string lagu_to_string(Lagu *lagu) {
  return lagu->penyanyi + " - " + lagu->judul;
}

Lagu *cari_lagu_dari_judul(Playlist *playlist, string judul) {
  for (int i = 0; i <= playlist->jumlah; i++) {
    if (playlist->antrean[i].judul == judul) {
      return &playlist->antrean[i];
    }
  }

  return &LAGU_KOSONG;
}

void sort_playlist(Playlist *playlist) {
  bool swapped = false;

  do {
    swapped = false;

    for (int i = 0; i < playlist->jumlah - 1; i++) {
      if (playlist->antrean[i].judul > playlist->antrean[i + 1].judul) {
        swap(playlist->antrean[i], playlist->antrean[i + 1]);
        swapped = true;
      }
    }
  } while (swapped);
}

void display_playlist(Playlist *playlist) {
  for (int i = 0; i <= playlist->jumlah; i++) {
    cout << "---" << endl;
    cout << "lagu : " << lagu_to_string(&playlist->antrean[i]) << endl;
    cout << "genre : " << playlist->antrean[i].genre << endl;
    cout << "tahun lagu : " << playlist->antrean[i].tahun_lagu << endl;
  }
}

void tambah_lagu(Playlist *playlist, Lagu lagu) {
  playlist->antrean[playlist->jumlah] = lagu;
  playlist->jumlah++;
}

void display_home_menu(Playlist *playlist);

void display_tambah_lagu(Playlist *playlist) {
  system("clear");

  int jumlah_lagu;
  cout << "Masukkan jumlah lagu yang ingin diinputkan : ";
  cin >> jumlah_lagu;
  cout << endl;

  for (int i = 0; i < jumlah_lagu; i++) {
    Lagu input_lagu;
    cout << "Masukkan judul lagu : ";
    cin >> input_lagu.judul;

    cout << "Masukkan Penyanyi Lagu : ";
    cin >> input_lagu.penyanyi;

    cout << "Masukkan Genre Lagu : ";
    cin >> input_lagu.genre;

    cout << "Masukkan Tahun Lagu : ";
    cin >> input_lagu.tahun_lagu;

    tambah_lagu(playlist, input_lagu);
    cout << endl;
  }

  cout << "Tekan tombol sembarang untuk kembali ke menu" << endl;

  system("pause");
  display_home_menu(playlist);
}

void display_telusur_lagu(Playlist *playlist) {
  string query;

  cout << "Masukkan Judul Lagu yang Dicari : ";
  cin.ignore();
  getline(cin, query);

  Lagu *output_lagu = cari_lagu_dari_judul(playlist, query);

  if (output_lagu->judul == LAGU_KOSONG.judul) {
    cout << "Lagu tidak ditemukkan!" << endl;
    cout << "Tekan tombol sembarang untuk kembali ke menu" << endl;

    system("pause");

    display_home_menu(playlist);
    return;
  }

  cout << "Lagu ditemukkan!" << endl;
  cout << "data lagu : " << endl;
  cout << "Judul Lagu : " << output_lagu->judul << endl;
  cout << "Penyanyi : " << output_lagu->penyanyi << endl;
  cout << "Genre : " << output_lagu->genre << endl;
  cout << "Tahun Lagu : " << output_lagu->tahun_lagu << endl << endl;

  cout << "Tekan tombol sembarang untuk kembali ke menu" << endl;

  system("pause");

  display_home_menu(playlist);
}

void display_home_menu(Playlist *playlist) {
  char pilihan_menu;
  bool menu_tidak_valid = false;
  do {
    system("clear");

    if (menu_tidak_valid) {
      cout << "menu yang anda pilih tidak valid!" << endl << endl;
    }

    cout << "Playlist Lagu" << endl;
    cout << setfill('=') << setw(13) << "" << endl;
    cout << "1. tambah lagu" << endl;
    cout << "2. cari lagu" << endl;
    cout << "3. keluar" << endl;

    cout << "Pilih menu: ";
    cin >> pilihan_menu;

    switch (pilihan_menu) {
    case '1':
      display_tambah_lagu(playlist);
      break;
    case '2':
      display_telusur_lagu(playlist);
      break;
    case '3':
      cout << "Goodbye!" << endl;
      exit(0);
      break;
    default:
      pilihan_menu = '\0';
      menu_tidak_valid = true;
      break;
    }
  } while (pilihan_menu == '\0');
}

int main() {
  Playlist playlist = {};
  display_home_menu(&playlist);
}
