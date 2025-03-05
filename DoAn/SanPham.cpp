#include "SanPham.h"
#include <iostream>

SanPham::SanPham(std::string ma, std::string ten, double g, int sl) 
    : maSanPham(ma), tenSanPham(ten), gia(g), soLuongTonKho(sl) {}

void SanPham::capNhatTonKho(int sl) {
    soLuongTonKho += sl;
}

void SanPham::hienThiThongTin() {
    std::cout << "San Pham: " << tenSanPham << " - " << maSanPham << " - Gia: " << gia << " - Ton kho: " << soLuongTonKho << "\n";
}

int SanPham::getSoLuongTonKho() const {
    return soLuongTonKho;
}

std::string SanPham::getTenSanPham() const {
    return tenSanPham;
}
