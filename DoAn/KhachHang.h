#ifndef KHACHHANG_H
#define KHACHHANG_H

#include <string>

class KhachHang {
private:
    std::string maKhachHang;
    std::string hoTen;
    std::string soDienThoai;
    std::string email;

public:
    KhachHang(std::string ma, std::string ten, std::string sdt, std::string mail);
    std::string getMaKhachHang() const { return maKhachHang; }
    std::string getHoTen() const { return hoTen; }
    void hienThiThongTin() const;
};

#endif
