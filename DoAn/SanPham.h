#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>

class SanPham {
private:
    std::string maSanPham;
    std::string tenSanPham;
    double gia;
    int soLuongTonKho;

public:
    SanPham(std::string ma, std::string ten, double g, int sl);
    void capNhatTonKho(int sl);
    void hienThiThongTin();
    int getSoLuongTonKho() const;
    std::string getTenSanPham() const;
};

#endif
