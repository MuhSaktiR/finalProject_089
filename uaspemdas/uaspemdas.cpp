#include <iostream>
using namespace std;

class bidangDatar {
private:
	int x, y;

public:
	bidangDatar() {
		x = 0;
		y = 0;
	}

	virtual void input() {}
	virtual float Luas(int a) { return 0; }
	virtual float Keliling(int a) { return 0; }
	virtual void cekUkuran() { return; }
	void setX(int a) { // untuk memberi nilai pada private member x
		this->x = a;
	}
	int getX() {
		return x;
	}
	void setY(int a) { // untuk memberi nilai pada private member y
		this->y = a;
	}
	int getY() {
		return y;
	}
};

class Lingkaran :public bidangDatar {
public:

	void input() {

		cout << "Lingkaran dibuat" << endl;
		cout << "Masukkan jejari : ";
		int r;
		cin >> r;
		setX(r); // untuk memasukkan input r kedalam setX

	}

	float Luas(int r) {
		return 3.14 * r * r;
	}

	float Keliling(int r) {
		return 2 * 3.14 * r;
	}
	

	void cekUkuran() {
		float hasilLuas = Luas(getX());
		float hasilKeliling = Keliling(getX());

		cout << "Luas lingkaran = " << hasilLuas << endl;
		cout << "Keliling lingkaran = " << hasilKeliling << endl;

		if (hasilKeliling >= 40) {
			cout << "Ukuran lingkaran adalah besar" << endl;
		}
		else if (hasilKeliling > 20) {
			cout << "Ukuran lingkaran adalah sedang" << endl;			
		}
		else {
			cout << "Ukuran lingkaran adalah kecil" << endl;
		}

	}
};

class Persegipanjang :public bidangDatar {
public:
	void input() {
		cout << "Persegipanjang dibuat" << endl;
		cout << "Masukan Panjang : ";
		int p;
		cin >> p;
		setX(p); // Untuk memasukkan input p kedalam set x

		cout << "Masukan Lebar : ";
		int l;
		cin >> l;
		setY(l); // Untuk memasukkan input l kedalam set x

	}

	float Luas(int p, int l) {
			return p * l;
	}

	float Keliling(int p, int l) {
			return 2 * (p + l);
	}


	void cekUkuran() {
		float hasilLuas = Luas(getX(), getY());
		float hasilKeliling = Keliling(getX(), getY());

		cout << "Luas lingkaran = " << hasilLuas << endl;
		cout << "Keliling lingkaran = " << hasilKeliling << endl;

		if (hasilKeliling >= 40) {
			cout << "Ukuran lingkaran adalah besar" << endl;
		}
		else if (hasilKeliling > 20) {
			cout << "Ukuran lingkaran adalah sedang" << endl;
		}
		else {
			cout << "Ukuran lingkaran adalah kecil" << endl;
		}
	}
};

int main() {
	bidangDatar* o;
	
	char ulangi;

	//objek Lingkaran
	o = new Lingkaran();
	o->input();
	int r = o->getX();
	o->cekUkuran();

	cout << endl;

	//objek Persegipanjang
	do {
	o = new Persegipanjang();
	o->input();
	int p = o->getX();
	int l = o->getY();
	o->cekUkuran();

	cout << "\nApakah ingin mengulangi? (y/n): ";
	cin >> ulangi;
	} while (ulangi == 'y' || ulangi == 'Y');

	delete o;

	return 0;
}