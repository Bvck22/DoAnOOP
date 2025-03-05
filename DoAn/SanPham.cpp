#include "SanPham.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Hàm khởi tạo sản phẩm
SanPham::SanPham(std::string ma, std::string ten, int gia, int soLuong)
    : maSanPham(ma), tenSanPham(ten), giaSanPham(gia), soLuongTonKho(soLuong) {}

// Getter
std::string SanPham::getMaSanPham() const { return maSanPham; }
std::string SanPham::getTenSanPham() const { return tenSanPham; }
int SanPham::getGia() const { return giaSanPham; }  // Lấy giá sản phẩm
int SanPham::getSoLuongTonKho() const { return soLuongTonKho; }

// Setter
void SanPham::setGia(int giaMoi) { giaSanPham = giaMoi; }
void SanPham::setSoLuongTonKho(int soLuongMoi) { soLuongTonKho = soLuongMoi; }

// Giảm số lượng sản phẩm khi bán hàng
bool SanPham::giamSoLuong(int soLuong) {
    if (soLuongTonKho >= soLuong) {
        soLuongTonKho -= soLuong;
        return true;
    }
    return false;
}

// Hiển thị thông tin sản phẩm
void SanPham::hienThiThongTin() const {
    cout << left << setw(10) << maSanPham
         << setw(20) << tenSanPham
         << setw(10) << giaSanPham
         << setw(10) << soLuongTonKho << endl;
}
