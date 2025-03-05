#ifndef HOADON_H
#define HOADON_H

#include "NhanVien.h"
#include "KhachHang.h"
#include "SanPham.h"
#include <vector>

class HoaDon {
private:
    std::string maHoaDon;
    NhanVien nhanVien;
    KhachHang khachHang;
    std::vector<std::pair<SanPham, int>> danhSachSanPham;
    double tongTien;

public:
    HoaDon(std::string maHD, NhanVien nv, KhachHang kh);
    void themSanPham(SanPham sp, int soLuong);
    void hienThiHoaDon() const;
};

#endif
