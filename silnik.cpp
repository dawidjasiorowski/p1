#include <iostream>

struct Silnik;

struct Samochod {
    Silnik* silnik;
    std::string marka_m;
    int rok_produkcji_m;
    Samochod(std::string marka, int rok_produkcji, Silnik* silnik_dany) {
        marka_m = marka;
        rok_produkcji_m = rok_produkcji;
        silnik = silnik_dany; 
    }
    Samochod() {
        marka_m = "Mercedes";
        rok_produkcji_m = 2020;
        silnik = nullptr;
    }
    void na_napis();
};

struct Silnik {
    Samochod* samochod;
    unsigned short moc_m;
    unsigned short zuzycie_paliwa_m;
    Silnik(unsigned short moc, unsigned short zuzycie_paliwa, Samochod* samochod_dany) {
        moc_m = moc;
        zuzycie_paliwa_m = zuzycie_paliwa;
        samochod = samochod_dany;
    }
    Silnik() {
        moc_m = 100;
        zuzycie_paliwa_m = 10;
        samochod = nullptr;
    }
    void na_napis();
};

void Samochod::na_napis() {
        if(silnik != nullptr) {
            std::cout << "Moc: " << silnik->moc_m << std::endl;
            std::cout << "Zuzycie paliwa: " << silnik->zuzycie_paliwa_m << std::endl;
        }
        std::cout << "Marka samochodu: " << marka_m << std::endl;
        std::cout << "Rok produkcji: " << rok_produkcji_m << std::endl;
}

void Silnik::na_napis() {
    std::cout << "Moc: " << moc_m << std::endl;
    std::cout << "Zuzycie paliwa: " << zuzycie_paliwa_m << std::endl;
    if(samochod != nullptr) {
        std::cout << "Marka samochodu: " << samochod->marka_m << std::endl;
        std::cout << "Rok produkcji: " << samochod->rok_produkcji_m << std::endl;
    }
}

int main() {

    Samochod car("Audi", 2020, nullptr);
    Silnik eng(12,6, &car);

    Silnik eng_2(15,20,nullptr);
    Samochod car_2("Toyoto", 123, &eng_2);

    car.silnik = &eng;

    eng_2.samochod = &car_2;

    eng_2.na_napis();

    car.na_napis();
}
