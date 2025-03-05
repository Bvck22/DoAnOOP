#include "HoaDon.h"
#include <iostream>
#include <iomanip> 

using namespace std;

HoaDon::HoaDon(std::string maHD, NhanVien nv, KhachHang kh) 
    : maHoaDon(maHD), nhanVien(nv), khachHang(kh), tongTien(0) {}

void HoaDon::themSanPham(SanPham sp, int soLuong) {
    danhSachSanPham.push_back(std::make_pair(sp, soLuong));
    tongTien += sp.getSoLuongTonKho() * soLuong;
}

void HoaDon::hienThiHoaDon() const {
    cout << "\n===== HÓA ĐƠN =====\n";
    cout << left << setw(15) << "Mã hóa đơn" 
         << setw(20) << "Nhân viên"
         << setw(20) << "Khách hàng" << endl;
    cout << setw(15) << maHoaDon 
         << setw(20) << nhanVien.getHoTen() 
         << setw(20) << khachHang.getHoTen() << endl;

    cout << "\n=== Danh sách sản phẩm ===\n";
    cout << setw(20) << "Tên sản phẩm"
         << setw(10) << "Số lượng" << endl;
    for (const auto& sp : danhSachSanPham) {
        cout << setw(20) << sp.first.getTenSanPham() 
             << setw(10) << sp.second << endl;
    }
}