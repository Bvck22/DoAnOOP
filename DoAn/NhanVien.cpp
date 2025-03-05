#include "NhanVien.h"
#include <iomanip>
#include<iostream>

using namespace std;

NhanVien::NhanVien(std::string ma, std::string ten, std::string sdt, std::string mail, std::string cv) 
    : maNhanVien(ma), hoTen(ten), soDienThoai(sdt), email(mail), chucVu(cv) {}

void NhanVien::hienThiThongTin() const {
    cout << left << setw(12) << maNhanVien
         << setw(20) << hoTen
         << setw(15) << soDienThoai
         << setw(25) << email
         << setw(15) << chucVu << endl;
}