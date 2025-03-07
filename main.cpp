#include <iomanip>
#include <iostream>
#include <random>
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

Lagu *cari_lagu_dari_judul(Playlist playlist, string judul) {
  for (int i = 0; i <= playlist.jumlah; i++) {
    if (playlist.antrean[i].judul == judul) {
      return &playlist.antrean[i];
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

int main() {
  Playlist playlist = {};

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
      break;
    case '2':
      break;
    case '3':
      break;
    default:
      pilihan_menu = '\0';
      menu_tidak_valid = true;
      break;
    }
  } while (pilihan_menu == '\0');
}
