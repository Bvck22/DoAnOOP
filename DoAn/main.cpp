#include <iostream>
#include <vector>
#include <iomanip>
#include "NhanVien.h"
#include "KhachHang.h"
#include "HoaDon.h"
#include "SanPham.h"
#include "Kho.h"

using namespace std;

void menu() {
    cout << "\n===== QUẢN LÝ CỬA HÀNG KÍNH =====\n";
    cout << "1. Thêm nhân viên\n";
    cout << "2. Xem danh sách nhân viên\n";
    cout << "3. Thêm khách hàng\n";
    cout << "4. Tìm kiếm khách hàng theo tên\n";
    cout << "5. Tạo hóa đơn\n";
    cout << "6. Xem hàng tồn kho\n";
    cout << "0. Thoát\n";
    cout << "Chọn chức năng: ";
}

int main() {
    Kho kho;  // Khởi tạo kho hàng
    vector<NhanVien> danhSachNhanVien;
    vector<KhachHang> danhSachKhachHang;
    vector<HoaDon> danhSachHoaDon;

    int choice;
    do {
        menu();
        cin >> choice;
        cin.ignore();

        switch (choice) {
            case 1: {  // Thêm nhân viên
                string ma, ten, sdt, email, chucVu;
                cout << "Nhập mã nhân viên: "; getline(cin, ma);
                cout << "Nhập họ và tên: "; getline(cin, ten);
                cout << "Nhập số điện thoại: "; getline(cin, sdt);
                cout << "Nhập email: "; getline(cin, email);
                cout << "Nhập chức vụ: "; getline(cin, chucVu);

                danhSachNhanVien.emplace_back(ma, ten, sdt, email, chucVu);
                cout << "Thêm nhân viên thành công!\n";
                break;
            }

            case 2: {  // Xem danh sách nhân viên
            cout << "\n=== DANH SÁCH NHÂN VIÊN ===\n";
            cout << left << setw(12) << "Mã NV"
                << setw(20) << "Họ và Tên"
                << setw(15) << "SĐT"
                << setw(25) << "Email"
                << setw(15) << "Chức vụ" << endl;
            cout << string(90, '-') << endl;  // Dòng kẻ ngang
            for (const auto& nv : danhSachNhanVien) {
                nv.hienThiThongTin();
            }
            break;
            }

            case 3: {  // Thêm khách hàng
                string ma, ten, sdt, email;
                cout << "Nhập mã khách hàng: "; getline(cin, ma);
                cout << "Nhập họ và tên: "; getline(cin, ten);
                cout << "Nhập số điện thoại: "; getline(cin, sdt);
                cout << "Nhập email: "; getline(cin, email);

                danhSachKhachHang.emplace_back(ma, ten, sdt, email);
                cout << "Thêm khách hàng thành công!\n";
                break;
            }

            case 4: {  // Tìm kiếm khách hàng theo tên
            std::string tenCanTim;
            std::cout << "Nhập tên khách hàng cần tìm: ";
            std::getline(std::cin, tenCanTim);  // Đọc toàn bộ tên khách hàng

            bool found = false;
            std::cout << "\n===== KẾT QUẢ TÌM KIẾM =====\n";
            for (const auto& kh : danhSachKhachHang) {
                if (kh.getHoTen() == tenCanTim) {  // So sánh với tên nhập vào
                    kh.hienThiThongTin();
                    found = true;
                }
            }
            if (!found) {
                std::cout << "Không tìm thấy khách hàng!\n";
            }
            break;
            }

            case 5: {  // Tạo hóa đơn
                string maHD, maNV, maKH;
                cout << "Nhập mã hóa đơn: "; getline(cin, maHD);
                cout << "Nhập mã nhân viên: "; getline(cin, maNV);
                cout << "Nhập mã khách hàng: "; getline(cin, maKH);

                // Tìm nhân viên
                NhanVien* nv = nullptr;
                for (auto& n : danhSachNhanVien) {
                   if (n.getMaNhanVien() == maNV) {
                        nv = &n;
                        break;
                    }
                }
                if (!nv) {
                    cout << "Không tìm thấy nhân viên!\n";
                    break;
                }

                // Tìm khách hàng
                KhachHang* kh = nullptr;
                for (auto& k : danhSachKhachHang) {
                    if (k.getMaKhachHang() == maKH) {
                        kh = &k;
                        break;
                    }
                }
                if (!kh) {
                    cout << "Không tìm thấy khách hàng!\n";
                    break;
                }

                // Tạo hóa đơn
                HoaDon hd(maHD, *nv, *kh);
                string tenSanPham;
                int giaSanPham = kho.layGiaSanPham(tenSanPham);
                
                int soLuong;
                char tiepTuc;

                do {
                cout << "Nhập tên sản phẩm (Kinh Can, Kinh Vien, Kinh Loan): ";
                getline(cin, tenSanPham);

                // Tìm sản phẩm trong kho để lấy giá chính xác
                SanPham* sanPhamTrongKho = nullptr;
                for (auto& sp : kho.getDanhSachSanPham()) {  // Bạn cần thêm phương thức này vào lớp Kho
                    if (sp.getTenSanPham() == tenSanPham) {
                        sanPhamTrongKho = &sp;
                        break;
                    }
                }

                // Kiểm tra tên sản phẩm có tồn tại không
                while (!kho.kiemTraSanPham(tenSanPham, 1)) {
                    cout << "Sản phẩm không hợp lệ! Vui lòng nhập lại: ";
                    getline(cin, tenSanPham);
                }

                cout << "Nhập số lượng: ";
                cin >> soLuong;
                cin.ignore();

                // Kiểm tra số lượng hợp lệ
                while (!kho.kiemTraSanPham(tenSanPham, soLuong)) {
                    cout << "⚠ Số lượng không đủ trong kho! Hãy nhập số lượng hợp lệ: ";
                    cin >> soLuong;
                    cin.ignore();
                }

                // Thêm sản phẩm vào hóa đơn với giá từ kho
                if (sanPhamTrongKho) {
                    hd.themSanPham(*sanPhamTrongKho, soLuong);
                    kho.capNhatKho(tenSanPham, soLuong);
                }

                cout << "Thêm sản phẩm khác? (y/n): ";
                cin >> tiepTuc;
                cin.ignore();
            } while (tiepTuc == 'y' || tiepTuc == 'Y');
                danhSachHoaDon.push_back(hd);
                cout << "Hóa đơn đã được tạo!\n";
                hd.hienThiHoaDon();
                break;
            }

            case 6: {  // Xem kho hàng
                cout << "\n=== HÀNG TỒN KHO ===\n";
                kho.hienThiKho();
                break;
            }

            case 0:
                cout << "Thoát chương trình!\n";
                break;

            default:
                cout << "Lựa chọn không hợp lệ, vui lòng thử lại!\n";
        }
    } while (choice != 0);

    return 0;
}
