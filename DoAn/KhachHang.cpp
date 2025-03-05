#include "KhachHang.h"
#include <iostream>
#include <iomanip>  

using namespace std;

KhachHang::KhachHang(std::string ma, std::string ten, std::string sdt, std::string mail) 
    : maKhachHang(ma), hoTen(ten), soDienThoai(sdt), email(mail) {}

void KhachHang::hienThiThongTin() const {
    cout << left << setw(12) << maKhachHang
         << setw(20) << hoTen
         << setw(15) << soDienThoai
         << setw(25) << email << endl;
}