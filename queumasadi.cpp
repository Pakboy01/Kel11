#include <iostream>
#define Max 10
using namespace std;

struct Biodata
{
	int nama;
	string alamat;
	int umur;
	
};

struct Antrian
{
	struct Biodata data[Max];
	int awal;
	int akhir;
} antri;

void init()
{
	antri.awal = -1;
	antri.akhir = -1;
}

bool isFull()
{
	bool penuh = false;

	if (antri.akhir == Max - 1)
		penuh = true;

	return penuh;
}

bool isEmpty()
{
	bool kosong = false;

	if (antri.akhir == -1)
		kosong = true;

	return kosong;
}

void inQueue()
{
string mobil,motor;
	string alamat;	
	int umur,nama;

	if (!isFull())
	{
		cout << "\nMasukkan Jenis Kendaraan (1. Mobil/ 2. Motor) : ";
		cin >> nama;
			switch(nama)
		{
			case 1  : 
			nama="mobil'";
			break;
		case 2  :
				nama="motor";
			break;
		default :
			cout << "Input Yang Anda Masukkan Salah";
			break;	
		}
		cout << "Masukkan alamat : ";
		cin >> alamat;
		cout << "Masukkan umur   : ";
		cin >> umur;

		antri.awal = 0;
		antri.akhir++;
		antri.data[antri.akhir].nama = nama;
		antri.data[antri.akhir].alamat = alamat;
		antri.data[antri.akhir].umur = umur;

		cout << "Data behasil ditambahkan!" << endl;
	}
	else
		cout << "\nMaaf, antrian sudah penuh!" << endl;
}

void deQueue()
{
	if (!isEmpty())
	{
		for(int i=antri.awal; i < antri.akhir; i++)
		{
			antri.data[i].nama = antri.data[i+1].nama;
			antri.data[i].alamat = antri.data[i+1].alamat;
			antri.data[i].umur = antri.data[i+1].umur;
		}

		antri.akhir--;
	}
	else
		cout << "\nMaaf, antrian kosong!" << endl;
}

void tampilData()
{
	if (!isEmpty())
	{
		cout << "\nData dalam antrian yaitu : " << endl;

		for(int i=antri.awal; i <= antri.akhir; i++)
		{
			cout << "\nNama   : " << antri.data[i].nama;
			cout << "\nAlamat : " << antri.data[i].alamat;
			cout << "\nUmur   : " << antri.data[i].umur;
		}

		cout << endl;
	}
	else
		cout << "\nMaaf, antrian kosong!" << endl;
}

void updateData()
{
	string nama, namaGanti;
	int isUpdate = 0;

	cout << "\nMasukkan nama yang akan diupdate : ";
	cin >> nama;
	cout << "Masukkan nama pengganti : ";
	cin >> namaGanti;

	for(int i=antri.awal; i <= antri.akhir; i++)
	{
		if (antri.data[i].nama == nama)
		{
			antri.data[i].nama = namaGanti;
			isUpdate = 1;
		}
	}

	if(isUpdate > 0)
		cout << "\nData berhasil diupdate!" << endl;
	else
		cout << "\nData gagal diupdate!" << endl;
}

int main()
{
	init();
	int pilihan;

	do
	{
		cout << "\nPilihan menu : " << endl;
		cout << "1. InQueue" << endl;
		cout << "2. DeQueue" << endl;
		cout << "3. Tampil Data" << endl;
		cout << "4. Update Data" << endl;
		cout << "5. Keluar" << endl;
		cout << "\nPilihan anda [1..5] : ";
		cin >> pilihan;

		switch(pilihan)
		{
			case 1:
				inQueue();
				break;
			case 2:
				deQueue();
				break;
			case 3:
				tampilData();
				break;
			case 4:
				updateData();
				break;
			case 5:
				break;
			default:
				cout << "\nMaaf, pilihan anda tidak valid!" << endl;
				break;
		}
	} while(pilihan != 5);

	return 0;
}
