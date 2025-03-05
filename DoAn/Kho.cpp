#include "Kho.h"
#include <iostream>

Kho::Kho() {
    danhSachSanPham.push_back(SanPham("Kinh can", "SP001", 500.0, 1000));
    danhSachSanPham.push_back(SanPham("Kinh vien", "SP002", 600.0, 1000));
    danhSachSanPham.push_back(SanPham("Kinh loan", "SP003", 700.0, 1000));
}

void Kho::hienThiKho() {
    for (auto &sp : danhSachSanPham) {
        sp.hienThiThongTin();
    }
}

bool Kho::kiemTraSanPham(std::string tenSanPham, int soLuong) {
    for (auto &sp : danhSachSanPham) {
        if (sp.getTenSanPham() == tenSanPham) {  // Kiểm tra xem sản phẩm có tồn tại không
            return sp.getSoLuongTonKho() >= soLuong;  // Kiểm tra số lượng có đủ không
        }
    }   
    return false;  // Nếu sản phẩm không tồn tại, trả về false
}


void Kho::capNhatKho(std::string tenSanPham, int soLuong) {
    for (auto &sp : danhSachSanPham) {
        if (sp.getTenSanPham() == tenSanPham) {
            sp.capNhatTonKho(-soLuong);
            break;
        }
    }
}
