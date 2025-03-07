#include <iostream>
#include <string>
#include <utility>

using namespace std;

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

    for (int i = 0; i < playlist->jumlah; i++) {
      if (playlist->antrean[i].judul > playlist->antrean[i + 1].judul) {
        swap(playlist->antrean[i], playlist->antrean[i + 1]);
      }
    }
  } while (!swapped);
}

void tambah_lagu(Playlist *playlist, Lagu lagu) {
  playlist->antrean[playlist->jumlah] = lagu;
  playlist->jumlah++;

  sort_playlist(playlist);
}

int main() {
  Lagu lagu = {
      .judul = "halo",
      .penyanyi = "halo",
  };

  cout << lagu_to_string(&lagu) << endl;
}
