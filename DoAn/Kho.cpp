#include "Kho.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Khởi tạo danh sách sản phẩm mặc định
Kho::Kho() {
    danhSachSanPham.push_back(SanPham("SP001", "Kinh Can", 500.000, int(1000)));
    danhSachSanPham.push_back(SanPham("SP002", "Kinh Vien", 600.000, int(1000)));
    danhSachSanPham.push_back(SanPham("SP003", "Kinh Loan", 567.000, int(1000)));
}

// Hiển thị kho hàng
void Kho::hienThiKho() const {
    cout << left << setw(10) << "Mã SP"
         << setw(20) << "Tên sản phẩm"
         << setw(10) << "Giá"
         << setw(10) << "Số lượng" << endl;
    for (const auto& sp : danhSachSanPham) {
        sp.hienThiThongTin();
    }
}

// Kiểm tra sản phẩm có đủ hàng không
bool Kho::kiemTraSanPham(std::string tenSanPham, int soLuong) {
    for (auto& sp : danhSachSanPham) {
        if (sp.getTenSanPham() == tenSanPham) {
            return sp.getSoLuongTonKho() >= soLuong;
        }
    }
    return false;
}

int Kho::layGiaSanPham(std::string tenSanPham) const {
    for (const auto& sp : danhSachSanPham) {
        if (sp.getTenSanPham() == tenSanPham) {
            return sp.getGia();
        }
    }
    return 0;  // Trả về 0 nếu không tìm thấy sản phẩm
}

// Cập nhật kho khi bán hàng
void Kho::capNhatKho(std::string tenSanPham, int soLuong) {
    for (auto& sp : danhSachSanPham) {
        if (sp.getTenSanPham() == tenSanPham) {
            if (sp.giamSoLuong(soLuong)) {
                cout << "Cập nhật kho thành công!\n";
            } else {
                cout << "Không đủ hàng trong kho!\n";
            }
            return;
        }
    }
    cout << "Sản phẩm không tồn tại trong kho!\n";
}
