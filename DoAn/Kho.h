#ifndef KHO_H
#define KHO_H

#include "SanPham.h"
#include <vector>

class Kho {
private:
    std::vector<SanPham> danhSachSanPham;

public:
    Kho();
    void hienThiKho();
    bool kiemTraSanPham(std::string tenSanPham, int soLuong);
    void capNhatKho(std::string tenSanPham, int soLuong);
};

#endif
