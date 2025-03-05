#include "HoaDon.h"
#include <iostream>
#include <iomanip> 

using namespace std;

HoaDon::HoaDon(std::string maHD, NhanVien nv, KhachHang kh) 
    : maHoaDon(maHD), nhanVien(nv), khachHang(kh), tongTien(0) {}

void HoaDon::themSanPham(SanPham sp, int soLuong) {
    danhSachSanPham.push_back(std::make_pair(sp, soLuong));
    tongTien += sp.getGia() * soLuong;
    cout << "Đã thêm sản phẩm: " << sp.getTenSanPham() << " - Số lượng: " << soLuong << " - Giá: " << sp.getGia() << " VND" << endl;
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
    cout << setw(32) << "Tên sản phẩm"<< setw(30) << "Số lượng" << setw(30) << "Giá" << endl;
    for (const auto& sp : danhSachSanPham) {
        cout << setw(32) << sp.first.getTenSanPham() 
             << setw(30) << sp.second 
            << setw(30) << sp.first.getGia() << endl;
    }
    cout << "\nTổng tiền: " << tongTien << " VND\n";
}