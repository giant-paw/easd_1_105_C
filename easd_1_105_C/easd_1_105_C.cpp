/*
JAWABAN :

1. Algoritma dibutuhkan dalam suatu penyelesaian masalah dikarenakan suatu masalah membutuhkan solusi yang efektif dan efisien dalam pengerjaannya.

2. Algoritma diklasifikasikan menjadi 2 struktur, yaitu :
		a. Statis (static)
		b. dinamis (dynamic)

3. Ada beberapa faktor yang mempengaruhi efisiensi suatu program algoritma, antara lain :
		a. Banyaknya data. jumlah dari banyaknya data jelas dapat mempengaruhi efisiensi suatu algoritma.
		b. pemilihan jenis algoritma. Dalam kasus persortiran data, maka pemilihan jenis algoritma adalah hal yang terpenting, dikarenakan setiap algoritma memiliki keunggulan dan kelemahan masing-masing, contohnya penggunaan memori yang membuat kurangnya efisiensi.

4. Algoritma quickSort, dikarenakan algoritma quickSort memakan ram yang tidak besar dan cara pengurutan data yang simpel, terlebih lagi pembuatan algoritma ini kebih mudah.

5.

*/

//6.

#include <iostream>
using namespace std;

int giant[35];				//nim = 20220140105
int n;
int compa_count = 0;
int move_count = 0;

void input() {
	while (true) {
		cout << "Masukkan Panjang Element Array : ";
		cin >> n;

		if (n <= 35)
			break;
		else
			cout << "\n\t~~~~ MAKSIMUM PANJANG ARRAY ADALAH 35! ~~~~\n" << endl;
	}

	cout << endl;
	cout << "\n=============================" << endl;
	cout << "\nMasukkan Element Array" << endl;
	cout << "\n=============================" << endl;

	for (int i = 0; i < n; i++) {
		cout << "Data ke-" << (i + 1) << " : ";
		cin >> giant[i];
	}
}

void swap(int x, int y) {
	int temp;

	temp = giant[x];
	giant[x] = giant[y];
	giant[y] = temp;
}

void quick_sort(int low, int high) {
	int pivot;
	int i;
	int gp;				//NAMA : Giant Prakoso

	if (low > high)
		return;

	pivot = giant[low];
	i = low + 1;
	gp = high;

	while (i <= gp) {

		//mencari element yang lebih besar dari pivot
		while ((giant[i] <= pivot) && (gp <= high)) {
			i++;
			compa_count++;
		}

		//mencari element yang kurang dari atau sama dengan pivot
		while ((giant[gp] > pivot) && (gp >= low)) {
			gp--;
			compa_count++;
		}
		compa_count++;

		if (i < gp) {
			swap(i, gp);
			move_count++;
		}
	}

	if (low < gp) {
		swap(low, gp);
		move_count++;
	}
	quick_sort(low, (gp - 1));

	quick_sort(gp + i, high);
}

void display() {
	cout << "\n=============================" << endl;
	cout << "\nArray yang Sudah Tersusun" << endl;
	cout << "\n=============================" << endl;
	cout << endl;

	for (int i = 0; i < n; i++) {
		cout << "[" << giant[i] << "] ";
	}

	cout << "\n\nNumber of Comparasions : " << compa_count << endl;
	cout << "Number of Movement : " << move_count << endl;
}

int main() {
	input();
	quick_sort(0, n - 1);
	display();
}