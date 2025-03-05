#ifndef SANPHAM_H
#define SANPHAM_H

#include <string>

class SanPham {
private:
    std::string maSanPham;
    std::string tenSanPham;
    int giaSanPham;
    int soLuongTonKho;

public:
    // Constructor
    SanPham(std::string ma, std::string ten, int gia, int soLuong);

    // Getter
    std::string getMaSanPham() const;
    std::string getTenSanPham() const;
    int getGia() const; // Lấy giá sản phẩm
    int getSoLuongTonKho() const;

    // Setter
    void setGia(int giaMoi);
    void setSoLuongTonKho(int soLuongMoi);

    // Cập nhật kho khi bán hàng
    bool giamSoLuong(int soLuong);

    // Hiển thị thông tin sản phẩm
    void hienThiThongTin() const;
};

#endif
