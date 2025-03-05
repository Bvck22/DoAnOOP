#ifndef NHANVIEN_H
#define NHANVIEN_H

#include <string>

class NhanVien {
private:
    std::string maNhanVien;
    std::string hoTen;
    std::string soDienThoai;
    std::string email;
    std::string chucVu;

public:
    NhanVien(std::string ma, std::string ten, std::string sdt, std::string mail, std::string cv);
    std::string getMaNhanVien() const { return maNhanVien; }
    std::string getHoTen() const {return hoTen;}
    void hienThiThongTin() const;
};

#endif
