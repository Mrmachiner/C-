using System;
using System.Collections.Generic;
using System.IO;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace EditSringDataList
{
    class Program
    {
        #region Danh sách họ - biến static string strHo

        public static string strHo =
@"Ánh
Ân
Âu
Dương
Ấu
Bá
Bạc
Bạch
Bàn
Bàng
Bành
Bảo
Bửu
Bế
Bì
Biện
Bình
Bồ
Ca
Cái
Cam
Cảnh
Cao
Cáp
Cát
Cầm
Cấn
Chế
Chiêm
Chu
Châu
Chung
Trung
Chúng
Chương
Chử
Trử
Cồ
Cổ
Công
Cống
Cung
Cù
Cự
Dã
Danh
Diêm
Diệp
Doãn
Dư
Đồ
Đàm
Đan
Đào
Đậu
Điền
Đinh
Điêu
Đoàn
Đôn
Đồng
Đổng
Đới
Đức
Đường
Giả
Giao
Giang
Giàng
Giáp
Hà
Hạ
Hàn
Hán
Hề
Hè
Hi
Hình
Hoa
Hồng
Hùng
Hứa
Hướng
Kiểu
Kha
Khương
Khâu
Khưu
Khiếu
Khoa
Khổng
Khu
Khuất
Khúc
Kiều
Kim
La
Lạc
Lại
Lâm
Lều
Lãnh
Lăng
Liêu
Liễu
Lò
Lô
Lỗ
Luyện
Lục
Lư
Lữ
Lã
Lương
Lưu
Lỳ
Lý
Ma
Mã
Mạc
Mạch
Mai
Mang
Mâu
Mẫn
Mộc
Nhan
Ninh
Nhâm
Ngân
Nghiêm
Nghị
Ngọ
Ngọc
Ngụy
Nhữ
Nông
Ong
Ông
Phi
Phí
Phó
Phú
Phùng
Phương
Phường
Quản
Quàng
Quách
Sầm
Sơn
Sử
Thang
Tạ
Tào
Tán
Tăng
Thạch
Thái
Thành
Thào
Thẩm
Thân
Thập
Thi
Thiều
Thịnh
Thoa
Thôi
Tiêu
Tiếp
Tòng
Tô
Tôn
Tông
Tống
Trang
Trà
Trác
Tri
Triệu
Trịnh
Trình
Trưng
Trừng
Trương
Từ
Ti
Uông
Ung
Ưng
Ứng
Văn
Vi
Viên
Vưu
Vương
Vừ
Xung
Xa
Yên
Nguyễn
Trần
Lê
Phạm
Hoàng
Huỳnh
Phan
Vũ
Võ
Đặng
Bùi
Đỗ
Hồ
Ngô
Dương
Lý";
        #endregion

        #region Danh sách tên đệm + tên riêng - biến static string strTenDemRieng
        public static string strTenDemRieng =
@"Diệu Ái
Khả Ái
Ngọc Ái
Hoài An
Huệ An
Minh An
Phương An
Thanh An
Hải Ân
Huệ Ân
Bảo Anh
Diệp Anh
Diệu Anh
Hải Anh
Hồng Anh
Huyền Anh
Kiều Anh
Kim Anh
Lan Anh
Mai Anh
Minh Anh
Mỹ Anh
Ngọc Anh
Nguyệt Anh
Như Anh
Phương Anh
Quế Anh
Quỳnh Anh
Thục Anh
Thúy Anh
Thùy Anh
Trâm Anh
Trang Anh
Tú Anh
Tuyết Anh
Vân Anh
Yến Anh
Kim Ánh
Ngọc Ánh
Nguyệt Ánh
Nhật Ánh
Băng Băng
Lệ Băng
Tuyết Băng
Như Bảo
Gia Bảo
Xuân Bảo
Ngọc Bích
An Bình
Thái Bình
Sơn Ca
Ngọc Cầm
Nguyệt Cầm
Thi Cầm
Bảo Châu
Bích Châu
Diễm Châu
Hải Châu
Hoàn Châu
Hồng Châu
Linh Châu
Loan Châu
Ly Châu
Mai Châu
Minh Châu
Trân Châu
Diệp Chi
Diễm Chi
Hạnh Chi
Khánh Chi
Kim Chi
Lan Chi
Lệ Chi
Linh Chi
Mai Chi
Phương Chi
Quế Chi
Quỳnh Chi
Bích Chiêu
Hoàng Cúc
Kim Cương
Trang Ðài
Tâm Đan
Thanh Đan
Linh Ðan
Quỳnh Dao
Anh Ðào
Bích Ðào
Hồng Ðào
Ngọc Ðào
Thục Ðào
Trúc Ðào
An Di
Thiên Di
Hồng Diễm
Kiều Diễm
Phương Diễm
Thúy Diễm
Bích Diệp
Hồng Diệp
Ngọc Diệp
Bích Ðiệp
Hồng Ðiệp
Mộng Ðiệp
Ngọc Ðiệp
Huyền Diệu
Tâm Ðoan
Thục Ðoan
Hạnh Dung
Kiều Dung
Kim Dung
Mỹ Dung
Nghi Dung
Ngọc Dung
Phương Dung
Quỳnh Dung
Thùy Dung
Ánh Dương
Chiêu Dương
Thùy Dương
Hải Ðường
Bích Duyên
Kỳ Duyên
Linh Duyên
Minh Duyên
Mỹ Duyên
Thu Duyên
Hà Giang
Hoài Giang
Hương Giang
Kiều Giang
Linh Giang
Phương Giang
Quỳnh Giang
Thanh Giang
Thiên Giang
Thu Giang
Thùy Giang
Hồng Giang
Trà Giang
Khánh Giao
Quỳnh Giao
Bảo Hà
Bích Hà
Hoàng Hà
Hồng Hà
Khánh Hà
Lam Hà
Linh Hà
Mai Hà
Minh Hà
Ngân Hà
Ngọc Hà
Nguyệt Hà
Nhật Hà
Quỳnh Hà
Thái Hà
Thanh Hà
Thu Hà
Thúy Hà
Vân Hà
Việt Hà
An Hạ
Mai Hạ
Ngọc Hạ
Nhật Hạ
Bích Hải
Bảo Hân
Gia Hân
Ngọc Hân
Tuyết Hân
Bích Hằng
Diễm Hằng
Diệu Hằng
Minh Hằng
Thanh Hằng
Thu Hằng
Thúy Hằng
Bích Hạnh
Cẩm Hạnh
Diễm Hạnh
Hiếu Hạnh
Hồng Hạnh
Kiều Hạnh
Minh Hạnh
Mỹ Hạnh
Phương Hạnh
Thúy Hạnh
Bích Hảo
Thanh Hảo
Bích Hậu
Thu Hậu
Bích Hiền
Diệu Hiền
Mai Hiền
Minh Hiền
Ngọc Hiền
Phương Hiền
Tâm Hiền
Thanh Hiền
Thu Hiền
Thúy Hiền
Xuân Hiền
Ánh Hoa
Bạch Hoa
Diệu Hoa
Hồng Hoa
Kiều Hoa
Kim Hoa
Lệ Hoa
Liên Hoa
Mộng Hoa
Ngọc Hoa
Như Hoa
Phương Hoa
Quỳnh Hoa
Thanh Hoa
Tuyết Hoa
Xuân Hoa
Kim Hòa
Thu Hoài
Ngọc Hoan
Mỹ Hoàn
Ngọc Hoàn
Ái Hồng
Ánh Hồng
Bích Hồng
Diệu Hồng
Minh Hồng
Nguyên Hồng
Nguyệt Hồng
Nhã Hồng
Như Hồng
Thái Hồng
Thanh Hồng
Thảo Hồng
Thu Hồng
Tuyết Hồng
Vũ Hồng
Yến Hồng
Bích Hợp
Bảo Huệ
Bích Huệ
Minh Huệ
Mỹ Huệ
Ngọc Huệ
Thu Huệ
Anh Hương
Dạ Hương
Diễm Hương
Diệu Hương
Ðinh Hương
Hoài Hương
Huệ Hương
Kim Hương
Lan Hương
Liên Hương
Mai Hương
Minh Hương
Mộng Hương
Nhã Hương
Quỳnh Hương
Thanh Hương
Thảo Hương
Thiên Hương
Thúy Hương
Thu Hương
Tuyết Hương
Vân Hương
Việt Hương
Xuân Hương
Cẩm Hường
Thu Hường
Thanh Hường
Thúy Hường
Diệu Huyền
Khánh Huyền
Lệ Huyền
Minh Huyền
Mỹ Huyền
Ngọc Huyền
Thanh Huyền
Thu Huyền
Thúy Huyền
Minh Khai
Ái Khanh
Ðan Khanh
Gia Khanh
Hiếu Khanh
Hồng Khanh
Kiều Khanh
Lệ Khanh
Mai Khanh
Ngọc Khanh
Nhã Khanh
Phi Khanh
Thụy Khanh
Uyển Khanh
Vân Khanh
Kim Khánh
Ngọc Khánh
Thiên Khánh
Vân Khánh
Mai Khôi
Diễm Khuê
Hồng Khuê
Lan Khuê
Minh Khuê
Ngọc Khuê
Thục Khuê
Việt Khuê
Kim Khuyên
Mỹ Khuyên
Diễm Kiều
Mỹ Kiều
Thanh Kiều
Thúy Kiều
Thiên Kim
Bích Lam
Ngọc Lam
Quỳnh Lam
Thanh Lam
Thiên Lam
Trúc Lam
Vy Lam
Hồng Lâm
Huệ Lâm
Hương Lâm
Ngọc Lâm
Quế Lâm
Quỳnh Lâm
Thanh Lâm
Thư Lâm
Thụy Lâm
Tịnh Lâm
Trúc Lâm
Tuệ Lâm
Tuyết Lâm
Xuân Lâm
Bảo Lan
Chi Lan
Dạ Lan
Diệu Lan
Hoàng Lan
Huệ Lan
Hương Lan
Khúc Lan
Kim Lan
Linh Lan
Mai Lan
Mộng Lan
Mỹ Lan
Ngọc Lan
Nguyệt Lan
Nhật Lan
Phong Lan
Phương Lan
Thanh Lan
Thiên Lan
Trúc Lan
Tuyết Lan
Vy Lan
Xuân Lan
Ý Lan
Ánh Lệ
Mỹ Lệ
Ngọc Lệ
Diễm Lệ
Bích Liên
Cẩm Liên
Diễm Liên
Hà Liên
Hoa Liên
Hồng Liên
Hương Liên
Kim Liên
Mai Liên
Ngọc Liên
Phương Liên
Mộng Liễu
Thúy Liễu
Xuân Liễu
Ái Linh
Quỳnh Liên
Thu Liên
Thúy Liên
Trúc Liên
Ánh Linh
Bội Linh
Cẩm Linh
Đan Linh
Diệu Linh
Gia Linh
Hạnh Linh
Hồng Linh
Huệ Linh
Huyền Linh
Khánh Linh
Mai Linh
Ngọc Linh
Phương Linh
Quế Linh
Thảo Linh
Thu Linh
Thùy Linh
Trang Linh
Trúc Linh
Vân Linh
Xuân Linh
Bạch Loan
Bích Loan
Diệu Loan
Kiều Loan
Kim Loan
Mai Loan
Minh Loan
Mỹ Loan
Ngọc Loan
Như Loan
Phượng Loan
Phương Loan
Thanh Loan
Thu Loan
Thúy Loan
Tố Loan
Trúc Loan
Tuyết Loan
Xuân Loan
Yến Loan
Cẩm Ly
Hương Ly
Khánh Ly
Kim Ly
Lưu Ly
Mai Ly
Ngọc Ly
Thảo Ly
Trúc Ly
Tú Ly
Ngọc Lý
Nhã Lý
Ánh Mai
Ban Mai
Chi Mai
Hiền Mai
Hồng Mai
Hương Mai
Khánh Mai
Kiều Mai
Kim Mai
Ngọc Mai
Nhã Mai
Như Mai
Phương Mai
Thanh Mai
Thu Mai
Thủy Mai
Thúy Mai
Trúc Mai
Tuyết Mai
Xuân Mai
Yến Mai
Tuệ Mẫn
Hà Mi
Thùy Mi
Kiều Minh
Nguyệt Minh
Thu Minh
Thủy Minh
Thúy Minh
Uyên Minh
Diễm My
Duyên My
Hà My
Hải My
Hạnh My
Huệ My
Khánh My
Thảo My
Thúy My
Thùy My
Trà My
Uyên My
Uyển My
Yến My
Duyên Mỹ
Kiều Mỹ
Thiên Mỹ
Bích Nga
Diệu Nga
Hạnh Nga
Hồng Nga
Kiều Nga
Lệ Nga
Mỹ Nga
Nguyệt Nga
Quỳnh Nga
Thanh Nga
Thiên Nga
Thu Nga
Thúy Nga
Tố Nga
Tuyết Nga
Việt Nga
Bích Ngà
Thu Ngà
Thúy Ngà
Bích Ngân
Hồng Ngân
Khánh Ngân
Kim Ngân
Quỳnh Ngân
Thanh Ngân
Thu Ngân
Thúy Ngân
Ðông Nghi
Phương Nghi
Thảo Nghi
Uyển Nghi
Xuân Nghi
Ánh Ngọc
Bảo Ngọc
Bích Ngọc
Diệu Ngọc
Giáng Ngọc
Hồng Ngọc
Huyền Ngọc
Khánh Ngọc
Kim Ngọc
Lam Ngọc
Lan Ngọc
Minh Ngọc
Mỹ Ngọc
Như Ngọc
Phương Ngọc
Thanh Ngọc
Thu Ngọc
Thúy Ngọc
Vân Ngọc
Xuân Ngọc
Tâm Nguyên
Thanh Nguyên
Thảo Nguyên
Ánh Nguyệt
Dạ Nguyệt
Kiều Nguyệt
Minh Nguyệt
Mộng Nguyệt
Tâm Nguyệt
Thu Nguyệt
Triều Nguyệt
Tú Nguyệt
Thanh Nhã
Trang Nhã
Uyển Nhã
An Nhàn
Thanh Nhàn
Ái Nhi
Cẩm Nhi
Ðông Nhi
Gia Nhi
Hà Nhi
Hải Nhi
Hảo Nhi
Hiền Nhi
Hương Nhi
Huyền Nhi
Lâm Nhi
Lan Nhi
Lệ Nhi
Linh Nhi
Mai Nhi
Minh Nhi
Mộng Nhi
Mỹ Nhi
Ngọc Nhi
Phương Nhi
Quỳnh Nhi
Tâm Nhi
Thảo Nhi
Thục Nhi
Thùy Nhi
Tịnh Nhi
Tố Nhi
Tuệ Nhi
Tuyết Nhi
Uyên Nhi
Uyển Nhi
Vân Nhi
Xuân Nhi
Ý Nhi
Yên Nhi
Yến Nhi
An Nhiên
Thu Nhiên
Xuân Nhiên
Bích Như
Hồng Như
Quỳnh Như
Tâm Như
Thùy Như
Uyển Như
Cẩm Nhung
Hồng Nhung
Phi Nhung
Phương Nhung
Quỳnh Nhung
Thanh Nhung
Tuyết Nhung
Ngọc Nữ
Diệu Nương
Kiều Nương
Mỹ Nương
Thiên Nương
Thụy Nương
Xuân Nương
Hoàng Oanh
Hồng Oanh
Kim Oanh
Ngọc Oanh
Thu Oanh
Thục Oanh
Thùy Oanh
Trâm Oanh
Tuyết Oanh
Yến Oanh
Thu Phong
Diễm Phúc
Hồng Phúc
Mỹ Phụng
Ngọc Phụng
Diễm Phước
Bảo Phương
Diễm Phương
Hà Phương
Hạnh Phương
Hoài Phương
Hồng Phương
Huệ Phương
Lan Phương
Liên Phương
Linh Phương
Mai Phương
Minh Phương
Mỹ Phương
Như Phương
Quế Phương
Quỳnh Phương
Thanh Phương
Thiên Phương
Thu Phương
Trúc Phương
Uyên Phương
Vân Phương
Xuân Phương
Yến Phương
Bích Phượng
Diễm Phượng
Hải Phượng
Kim Phượng
Linh Phượng
Minh Phượng
Mỹ Phượng
Thu Phượng
Thúy Phượng
Xuân Phượng
Yến Phượng
Bích Quân
Lệ Quân
Như Quân
Phương Quân
Trúc Quân
Tùng Quân
Hồng Quế
Ngọc Quế
Nguyệt Quế
Phương Quế
Bảo Quyên
Bích Quyên
Diễm Quyên
Khánh Quyên
Lệ Quyên
Mai Quyên
Ngọc Quyên
Phương Quyên
Thảo Quyên
Thục Quyên
Tố Quyên
Tú Quyên
Vân Quyên
Vi Quyên
Bảo Quỳnh
Diễm Quỳnh
Gia Quỳnh
Khánh Quỳnh
Lê Quỳnh
Mộng Quỳnh
Ngọc Quỳnh
Như Quỳnh
Phương Quỳnh
Thúy Quỳnh
Trúc Quỳnh
Tú Quỳnh
Kim Sa
Quỳnh Sa
Bích San
Linh San
Ngọc San
San San
Ngọc Sương
Nhã Sương
Sương Sương
Thu Sương
Tú Sương
Bảo Uyên
Diễm Uyên
Duy Uyên
Giáng Uyên
Hạ Uyên
Hải Uyên
Lâm Uyên
Minh Uyên
Mỹ Uyên
Ngọc Uyên
Nhã Uyên
Phương Uyên
Phượng Uyên
Thanh Uyên
Thảo Uyên
Thục Uyên
Thùy Uyên
Thụy Uyên
Tố Uyên
Tú Uyên
Xuân Uyên
Ngọc Uyển
Nguyệt Uyển
Băng Tâm
Minh Tâm
Mỹ Tâm
Ngọc Tâm
Như Tâm
Phương Tâm
Thanh Tâm
Thục Tâm
Bảo Tiên
Cát Tiên
Giáng Tiên
Hà Tiên
Hạ Tiên
Hoa Tiên
Hương Tiên
Phượng Tiên
Quỳnh Tiên
Thiện Tiên
Thủy Tiên
Vân Tiên
Bạch Trà
Hương Trà
Phương Trà
Bảo Trâm
Bích Trâm
Huyền Trâm
Mỹ Trâm
Ngọc Trâm
Phương Trâm
Quỳnh Trâm
Thụy Trâm
Uyên Trâm
Yến Trâm
Hương Trầm
Bảo Trân
Huyền Trân
Ánh Trang
Bích Trang
Ðài Trang
Diễm Trang
Ðoan Trang
Hạnh Trang
Hoài Trang
Hương Trang
Huyền Trang
Khánh Trang
Kiều Trang
Kim Trang
Linh Trang
Minh Trang
Mỹ Trang
Nhã Trang
Phương Trang
Quỳnh Trang
Tâm Trang
Thanh Trang
Thảo Trang
Thiên Trang
Thu Trang
Thục Trang
Thủy Trang
Vân Trang
Xuân Trang
Yến Trang
Diễm Trinh
Kiết Trinh
Kiều Trinh
Mai Trinh
Ngọc Trinh
Phương Trinh
Thục Trinh
Thụy Trinh
Tú Trinh
Tuyết Trinh
Vân Trinh
Việt Trinh
Yến Trinh
Bảo Trúc
Hồng Trúc
Lan Trúc
Ngân Trúc
Nhã Trúc
Thanh Trúc
Khuê Trúc
Cẩm Tú
Khả Tú
Minh Tú
Ngọc Tú
Minh Tuệ
Kim Tuyến
Ðông Tuyền
Kim Tuyền
Lam Tuyền
Lâm Tuyền
Mộng Tuyền
Sơn Tuyền
Thanh Tuyền
Thiên Tuyền
Ánh Tuyết
Bạch Tuyết
Kim Tuyết
Minh Tuyết
Ngọc Tuyết
Thanh Tuyết
Cát Tường
Hồng Thắm
Ðoan Thanh
Giang Thanh
Hà Thanh
Kim Thanh
Lệ Thanh
Mai Thanh
Ngân Thanh
Nhã Thanh
Phương Thanh
Quỳnh Thanh
Thanh Thanh
Thiên Thanh
Vân Thanh
Xuân Thanh
Yến Thanh
Anh Thảo
Bích Thảo
Diễm Thảo
Hương Thảo
Kim Thảo
Mai Thảo
Minh Thảo
Nguyên Thảo
Như Thảo
Phương Thảo
Thạch Thảo
Thanh Thảo
Thiên Thảo
Thu Thảo
Xuân Thảo
Ái Thi
Dạ Thi
Mộng Thi
Ngọc Thi
Phương Thi
Khánh Thi
Uyên Thi
Tuệ Thi
Hoa Thiên
Anh Thơ
Ánh Thơ
Ngọc Thơ
Quỳnh Thơ
Uyên Thơ
Bảo Thoa
Bích Thoa
Kim Thoa
Bích Thu
Hồng Thu
Hương Thu
Kiều Thu
Kim Thu
Lệ Thu
Mai Thu
Minh Thu
Mộng Thu
Quế Thu
Thanh Thu
Xuân Thu
Anh Thư
Diễm Thư
Hồng Thư
Huyền Thư
Kim Thư
Minh Thư
Thanh Thư
Thiên Thư
Hiền Thục
Hoài Thương
Huệ Thương
Lan Thương
Minh Thương
Thương Thương
Bảo Thúy
Cẩm Thúy
Diễm Thúy
Diệu Thúy
Hồng Thúy
Minh Thúy
Thanh Thúy
Vân Thúy
Phương Thùy
Bích Thủy
Hồng Thủy
Hương Thủy
Khánh Thủy
Kim Thủy
Lệ Thủy
Minh Thủy
Phương Thủy
Thanh Thủy
Thu Thủy
Xuân Thủy
Ái Vân
Bạch Vân
Bảo Vân
Bích Vân
Cẩm Vân
Diệu Vân
Hải Vân
Hồng Vân
Khánh Vân
Mộng Vân
Mỹ Vân
Ngọc Vân
Quỳnh Vân
Thái Vân
Thanh Vân
Thảo Vân
Thu Vân
Thục Vân
Thụy Vân
Thúy Vân
Thùy Vân
Thy Vân
Trúc Vân
Tường Vân
Tuyết Vân
Xuân Vân
Hạnh Vi
Hoàn Vi
Khánh Vi
Mộng Vi
Thúy Vi
Tường Vi
Uyên Vi
Bảo Vy
Diệp Vy
Ðông Vy
Hạ Vy
Hải Vy
Khánh Vy
Lan Vy
Mai Vy
Minh Vy
Mộng Vy
Ngọc Vy
Phượng Vy
Thanh Vy
Thảo Vy
Thúy Vy
Trúc Vy
Tường Vy
Tuyết Vy
Ánh Xuân
Hồng Xuân
Hương Xuân
Kim Xuân
Minh Xuân
Mỹ Xuân
Nghi Xuân
Thanh Xuân
Thi Xuân
Tuyết Xuân
Kim Xuyến
Nhã Ý
Như Ý
Thái Yên
Bạch Yến
Cẩm Yến
Dạ Yến
Hải Yến
Hoàng Yến
Kim Yến
Minh Yến
Mỹ Yến
Ngọc Yến
Nhã Yến
Phụng Yến
Phương Yến
Thanh Yến
Thi Yến
Thu Yến
Bảo An
Bình An
Ðăng An
Duy An
Khánh An
Nam An
Phước An
Thành An
Thế An
Thiên An
Trường An
Việt An
Xuân An
Công Ân
Ðức Ân
Gia Ân
Hoàng Ân
Minh Ân
Phú Ân
Thành Ân
Thiên Ân
Thiện Ân
Vĩnh Ân
Ngọc Ẩn
Chí Anh
Ðức Anh
Dương Anh
Gia Anh
Hùng Anh
Huy Anh
Minh Anh
Quang Anh
Quốc Anh
Thế Anh
Thiếu Anh
Thuận Anh
Trung Anh
Tuấn Anh
Tùng Anh
Tường Anh
Việt Anh
Vũ Anh
Hồ Bắc
Hoài Bắc
Gia Bạch
Công Bằng
Ðức Bằng
Hải Bằng
Yên Bằng
Chí Bảo
Ðức Bảo
Duy Bảo
Gia Bảo
Hữu Bảo
Nguyên Bảo
Quốc Bảo
Thiệu Bảo
Tiểu Bảo
Ðức Bình
Gia Bình
Hải Bình
Hòa Bình
Hữu Bình
Khánh Bình
Kiên Bình
Kiến Bình
Phú Bình
Quốc Bình
Tân Bình
Tất Bình
Thái Bình
Thế Bình
Xuân Bình
Yên Bình
Quang Bửu
Thiên Bửu
Khải Ca
Gia Cần
Duy Cẩn
Gia Cẩn
Hữu Canh
Gia Cảnh
Hữu Cảnh
Minh Cảnh
Ngọc Cảnh
Đức Cao
Xuân Cao
Bảo Chấn
Bảo Châu
Hữu Châu
Phong Châu
Thành Châu
Tuấn Châu
Tùng Châu
Đình Chiến
Mạnh Chiến
Minh Chiến
Hữu Chiến
Huy Chiểu
Trường Chinh
Ðức Chính
Trọng Chính
Trung Chính
Việt Chính
Ðình Chương
Tuấn Chương
Minh Chuyên
An Cơ
Chí Công
Thành Công
Xuân Cung
Hữu Cương
Mạnh Cương
Duy Cương
Việt Cương
Bá Cường
Ðức Cường
Ðình Cường
Duy Cường
Hùng Cường
Hữu Cường
Kiên Cường
Mạnh Cường
Ngọc Cường
Phi Cường
Phúc Cường
Thịnh Cường
Việt Cường
Ngọc Đại
Quốc Ðại
Minh Dân
Thế Dân
Minh Ðan
Nguyên Ðan
Sỹ Ðan
Hải Ðăng
Hồng Ðăng
Minh Danh
Ngọc Danh
Quang Danh
Thành Danh
Hưng Ðạo
Thanh Ðạo
Bình Ðạt
Ðăng Ðạt
Hữu Ðạt
Minh Ðạt
Quang Ðạt
Quảng Ðạt
Thành Ðạt
Ðắc Di
Phúc Ðiền
Quốc Ðiền
Phi Ðiệp
Ðình Diệu
Vinh Diệu
Mạnh Ðình
Bảo Ðịnh
Hữu Ðịnh
Ngọc Ðoàn
Thanh Ðoàn
Thành Doanh
Thế Doanh
Ðình Ðôn
Quang Đông
Từ Ðông
Viễn Ðông
Lâm Ðông
Bách Du
Thụy Du
Hồng Đức
Anh Ðức
Gia Ðức
Kiến Ðức
Minh Ðức
Quang Ðức
Tài Ðức
Thái Ðức
Thiên Ðức
Thiện Ðức
Tiến Ðức
Trung Ðức
Tuấn Ðức
Hoàng Duệ
Anh Dũng
Chí Dũng
Hoàng Dũng
Hùng Dũng
Lâm Dũng
Mạnh Dũng
Minh Dũng
Nghĩa Dũng
Ngọc Dũng
Nhật Dũng
Quang Dũng
Tấn Dũng
Thế Dũng
Thiện Dũng
Tiến Dũng
Trí Dũng
Trọng Dũng
Trung Dũng
Tuấn Dũng
Việt Dũng
Hiếu Dụng
Ðại Dương
Ðình Dương
Ðông Dương
Hải Dương
Nam Dương
Quang Dương
Thái Dương
Việt Dương
Anh Duy
Bảo Duy
Ðức Duy
Khắc Duy
Khánh Duy
Nhật Duy
Phúc Duy
Thái Duy
Trọng Duy
Việt Duy
Thế Duyệt
Vương Gia
Bảo Giang
Chí Giang
Công Giang
Ðức Giang
Hải Giang
Hòa Giang
Hoàng Giang
Hồng Giang
Khánh Giang
Long Giang
Minh Giang
Thiện Giang
Trường Giang
Nguyên Giáp
Huy Kha
Anh Khải
Ðức Khải
Hoàng Khải
Quang Khải
Tuấn Khải
Việt Khải
An Khang
Chí Khang
Ðức Khang
Duy Khang
Hoàng Khang
Hữu Khang
Minh Khang
Ngọc Khang
Nguyên Khang
Như Khang
Phúc Khang
Tấn Khang
Việt Khang
Hữu Khanh
Tuấn Khanh
Bảo Khánh
Ðăng Khánh
Duy Khánh
Gia Khánh
Huy Khánh
Minh Khánh
Quốc Khánh
Trọng Khánh
Chí Khiêm
Ðức Khiêm
Duy Khiêm
Gia Khiêm
Huy Khiêm
Thành Khiêm
Thiện Khiêm
Anh Khoa
Ðăng Khoa
Việt Khoa
Xuân Khoa
Anh Khôi
Hoàng Khôi
Hữu Khôi
Minh Khôi
Ngọc Khôi
Nguyên Khôi
Việt Khôi
Đăng Khương
Ngọc Khương
Nhật Khương
Chí Kiên
Ðức Kiên
Gia Kiên
Trọng Kiên
Trung Kiên
Xuân Kiên
Gia Kiệt
Liên Kiệt
Minh Kiệt
Thường Kiệt
Tuấn Kiệt
Trọng Kim
Bá Kỳ
Cao Kỳ
Minh Kỳ
Trường Kỳ
Hiệp Hà
Huy Hà
Mạnh Hà
Quang Hà
Sơn Hà
Trọng Hà
Công Hải
Ðông Hải
Ðức Hải
Duy Hải
Hoàng Hải
Khánh Hải
Minh Hải
Nam Hải
Ngọc Hải
Phi Hải
Phú Hải
Quang Hải
Quốc Hải
Sơn Hải
Thanh Hải
Trung Hải
Tuấn Hải
Việt Hải
Vĩnh Hải
Xuân Hãn
Ðại Hành
Hữu Hạnh
Nguyên Hạnh
Quốc Hạnh
Công Hào
Hiệp Hào
Minh Hào
Thanh Hào
Trí Hào
Ðình Hảo
Công Hậu
Thanh Hậu
Duy Hiền
Quốc Hiền
Tạ Hiền
Bảo Hiển
Ngọc Hiển
Quốc Hiển
Gia Hiệp
Hòa Hiệp
Hoàng Hiệp
Hữu Hiệp
Phú Hiệp
Tiến Hiệp
Quốc Hiệp
Chí Hiếu
Công Hiếu
Duy Hiếu
Minh Hiếu
Tất Hiếu
Trọng Hiếu
Trung Hiếu
Xuân Hiếu
Bảo Hòa
Ðạt Hòa
Ðức Hòa
Gia Hòa
Hiệp Hòa
Khải Hòa
Minh Hòa
Nghĩa Hòa
Nhật Hòa
Phúc Hòa
Quang Hòa
Quốc Hòa
Tất Hòa
Thái Hòa
Xuân Hòa
Quốc Hoài
Công Hoán
Quốc Hoàn
Khánh Hoàn
Anh Hoàng
Bảo Hoàng
Duy Hoàng
Gia Hoàng
Hữu Hoàng
Huy Hoàng
Khánh Hoàng
Minh Hoàng
Phi Hoàng
Quốc Hoàng
Sỹ Hoàng
Tuấn Hoàng
Việt Hoàng
Tiến Hoạt
Khánh Hội
Nhật Hồng
Việt Hồng
Ðình Hợp
Hòa Hợp
Gia Huấn
Minh Huấn
Chấn Hùng
Duy Hùng
Gia Hùng
Hữu Hùng
Mạnh Hùng
Minh Hùng
Nhật Hùng
Phi Hùng
Phú Hùng
Quang Hùng
Quốc Hùng
Thế Hùng
Trí Hùng
Trọng Hùng
Tuấn Hùng
Việt Hùng
Chấn Hưng
Gia Hưng
Minh Hưng
Nam Hưng
Phú Hưng
Phúc Hưng
Quang Hưng
Quốc Hưng
Thiên Hưng
Vĩnh Hưng
Chính Hữu
Quang Hữu
Trí Hữu
Bảo Huy
Ðức Huy
Gia Huy
Khánh Huy
Minh Huy
Ngọc Huy
Nhật Huy
Quang Huy
Quốc Huy
Thanh Huy
Việt Huy
Xuân Huy
Bảo Huỳnh
Ân Lai
Bảo Lâm
Huy Lâm
Hoàng Lâm
Phúc Lâm
Quang Lâm
Sơn Lâm
Thế Lâm
Tùng Lâm
Tường Lâm
Hoàng Lân
Ngọc Lân
Quang Lân
Tường Lân
Công Lập
Gia Lập
Hữu Lễ
Tôn Lễ
Hiếu Liêm
Thanh Liêm
Hoàng Linh
Quang Linh
Tuấn Linh
Tùng Linh
Hồng Lĩnh
Huy Lĩnh
Tường Lĩnh
Bá Lộc
Công Lộc
Ðinh Lộc
Ðình Lộc
Nam Lộc
Nguyên Lộc
Phước Lộc
Quang Lộc
Xuân Lộc
Tấn Lợi
Thắng Lợi
Thành Lợi
Bá Long
Bảo Long
Ðức Long
Hải Long
Hoàng Long
Hữu Long
Kim Long
Phi Long
Tân Long
Thăng Long
Thanh Long
Thành Long
Thụy Long
Trường Long
Tuấn Long
Việt Long
Thiện Luân
Vĩnh Luân
Công Luận
Ðình Luận
Duy Luận
Công Luật
Hữu Lương
Thiên Lương
Công Lý
Minh Lý
Ðức Mạnh
Duy Mạnh
Quốc Mạnh
Thiên Mạnh
Thụy Miên
Anh Minh
Bình Minh
Cao Minh
Chiêu Minh
Ðăng Minh
Ðức Minh
Duy Minh
Gia Minh
Hoàng Minh
Hồng Minh
Hiểu Minh
Hữu Minh
Khắc Minh
Khánh Minh
Ngọc Minh
Nhật Minh
Quang Minh
Quốc Minh
Thái Minh
Thanh Minh
Thế Minh
Thiện Minh
Trí Minh
Tuấn Minh
Tùng Minh
Tường Minh
Văn Minh
Vũ Minh
Xuân Minh
Hoàng Mỹ
Quốc Mỹ
An Nam
Chí Nam
Ðình Nam
Giang Nam
Hải Nam
Hồ Nam
Hoài Nam
Hoàng Nam
Hữu Nam
Khánh Nam
Nhật Nam
Phương Nam
Tấn Nam
Trường Nam
Xuân Nam
Ngọc Ngạn
Gia Nghị
Hiếu Nghĩa
Hữu Nghĩa
Minh Nghĩa
Trọng Nghĩa
Trung Nghĩa
Mạnh Nghiêm
Cao Nghiệp
Hào Nghiệp
Ðại Ngọc
Hùng Ngọc
Tuấn Ngọc
Việt Ngọc
Duy Ngôn
Hoàng Ngôn
Thiện Ngôn
An Nguyên
Bình Nguyên
Ðình Nguyên
Ðông Nguyên
Hải Nguyên
Khôi Nguyên
Nhân Nguyên
Phúc Nguyên
Phước Nguyên
Thành Nguyên
Trung Nguyên
Tường Nguyên
Ðình Nhân
Ðức Nhân
Minh Nhân
Thiện Nhân
Phước Nhân
Quang Nhân
Thành Nhân
Thụ Nhân
Trọng Nhân
Trung Nhân
Trường Nhân
Việt Nhân
Thống Nhất
Hồng Nhật
Minh Nhật
Nam Nhật
Quang Nhật
Hạo Nhiên
An Ninh
Khắc Ninh
Quang Ninh
Xuân Ninh
Hoàng Phát
Hồng Phát
Tấn Phát
Trường Phát
Tường Phát
Ðức Phi
Khánh Phi
Nam Phi
Thanh Phi
Cao Phong
Chấn Phong
Chiêu Phong
Ðông Phong
Ðức Phong
Gia Phong
Hải Phong
Hiếu Phong
Hoài Phong
Hùng Phong
Huy Phong
Khởi Phong
Nguyên Phong
Quốc Phong
Thanh Phong
Thuận Phong
Uy Phong
Việt Phong
Ðình Phú
Ðức Phú
Kim Phú
Sỹ Phú
Thiên Phú
Ðình Phúc
Gia Phúc
Lạc Phúc
Thế Phúc
Trường Phúc
Xuân Phúc
Công Phụng
Bá Phước
Gia Phước
Hữu Phước
Tân Phước
Thiện Phước
Chế Phương
Ðông Phương
Lam Phương
Nam Phương
Quốc Phương
Thành Phương
Thế Phương
Thuận Phương
Viễn Phương
Việt Phương
Anh Quân
Bình Quân
Chiêu Quân
Ðông Quân
Hải Quân
Hoàng Quân
Long Quân
Minh Quân
Nhật Quân
Quốc Quân
Sơn Quân
Đăng Quang
Ðức Quang
Duy Quang
Hồng Quang
Huy Quang
Minh Quang
Ngọc Quang
Nhật Quang
Thanh Quang
Tùng Quang
Ðình Quảng
Ðức Quảng
Anh Quốc
Bảo Quốc
Minh Quốc
Nhật Quốc
Việt Quốc
Vinh Quốc
Hồng Quý
Minh Quý
Xuân Quý
Ðức Quyền
Lương Quyền
Sơn Quyền
Thế Quyền
Ngọc Quyết
Việt Quyết
Mạnh Quỳnh
Thái San
Ðình Sang
Thái Sang
Thành Sang
Quang Sáng
Ðức Siêu
Công Sinh
Ðức Sinh
Phúc Sinh
Tấn Sinh
Thiện Sinh
Anh Sơn
Bảo Sơn
Cao Sơn
Chí Sơn
Công Sơn
Danh Sơn
Ðông Sơn
Giang Sơn
Hải Sơn
Hồng Sơn
Hùng Sơn
Kim Sơn
Minh Sơn
Nam Sơn
Ngọc Sơn
Phước Sơn
Thái Sơn
Thanh Sơn
Thế Sơn
Trường Sơn
Vân Sơn
Viết Sơn
Việt Sơn
Xuân Sơn
Cao Sỹ
Tuấn Sỹ
Anh Tài
Ðức Tài
Hữu Tài
Lương Tài
Quang Tài
Tấn Tài
Tuấn Tài
Ðức Tâm
Duy Tâm
Hữu Tâm
Khải Tâm
Phúc Tâm
Thiện Tâm
Duy Tân
Hữu Tân
Minh Tân
Thái Tân
Mạnh Tấn
Nhật Tấn
Trọng Tấn
Cao Tiến
Minh Tiến
Nhật Tiến
Nhất Tiến
Quốc Tiến
Việt Tiến
Bảo Tín
Hoài Tín
Thành Tín
Bảo Toàn
Ðình Toàn
Ðức Toàn
Hữu Toàn
Kim Toàn
Minh Toàn
Thanh Toàn
Thuận Toàn
Vĩnh Toàn
Ðức Toản
Quốc Toản
Thanh Toản
Hữu Trác
Công Tráng
Ðức Trí
Dũng Trí
Hữu Trí
Minh Trí
Thiên Trí
Trọng Trí
Minh Triết
Phương Triều
Quang Triều
Vương Triều
Khắc Triệu
Minh Triệu
Quang Triệu
Vương Triệu
Tấn Trình
Ðắc Trọng
Khắc Trọng
Quang Trọng
Ngọc Trụ
Quốc Trụ
Ðình Trung
Ðức Trung
Hoài Trung
Hữu Trung
Kiên Trung
Minh Trung
Quang Trung
Quốc Trung
Thành Trung
Thanh Trung
Thế Trung
Tuấn Trung
Xuân Trung
Tấn Trương
Lâm Trường
Mạnh Trường
Quang Trường
Quốc Trường
Xuân Trường
Anh Tú
Minh Tú
Nam Tú
Quang Tú
Thanh Tú
Tuấn Tú
Hữu Từ
Anh Tuấn
Cảnh Tuấn
Công Tuấn
Ðình Tuấn
Ðức Tuấn
Huy Tuấn
Khắc Tuấn
Khải Tuấn
Mạnh Tuấn
Minh Tuấn
Ngọc Tuấn
Quang Tuấn
Quốc Tuấn
Thanh Tuấn
Ðức Tuệ
Anh Tùng
Bá Tùng
Sơn Tùng
Thạch Tùng
Thanh Tùng
An Tường
Ðức Tường
Hữu Tường
Huy Tường
Mạnh Tường
Thế Tường
Minh Thạc
Bảo Thạch
Duy Thạch
Ngọc Thạch
Quang Thạch
Anh Thái
Bảo Thái
Hòa Thái
Hoàng Thái
Minh Thái
Quang Thái
Triệu Thái
Việt Thái
Xuân Thái
Chiến Thắng
Ðình Thắng
Ðức Thắng
Duy Thắng
Hữu Thắng
Mạnh Thắng
Minh Thắng
Quang Thắng
Quốc Thắng
Quyết Thắng
Toàn Thắng
Trí Thắng
Vạn Thắng
Việt Thắng
Chí Thanh
Duy Thanh
Hoài Thanh
Nam Thanh
Thiện Thanh
Việt Thanh
Bá Thành
Chí Thành
Công Thành
Ðắc Thành
Danh Thành
Ðức Thành
Duy Thành
Huy Thành
Khắc Thành
Lập Thành
Quốc Thành
Tân Thành
Tấn Thành
Thuận Thành
Triều Thành
Trung Thành
Trường Thành
Tuấn Thành
Thanh Thế
Giang Thiên
Quang Thiên
Thanh Thiên
Ân Thiện
Bá Thiện
Ðình Thiện
Gia Thiện
Hữu Thiện
Mạnh Thiện
Minh Thiện
Ngọc Thiện
Phước Thiện
Quốc Thiện
Tâm Thiện
Thành Thiện
Xuân Thiện
Bá Thịnh
Cường Thịnh
Gia Thịnh
Hồng Thịnh
Hùng Thịnh
Kim Thịnh
Nhật Thịnh
Phú Thịnh
Phúc Thịnh
Quang Thịnh
Quốc Thịnh
Cao Thọ
Ðức Thọ
Hữu Thọ
Ngọc Thọ
Vĩnh Thọ
Duy Thông
Hiếu Thông
Huy Thông
Kim Thông
Minh Thông
Nam Thông
Quảng Thông
Quốc Thông
Vạn Thông
Việt Thông
Ðại Thống
Hữu Thống
Chính Thuận
Minh Thuận
Ngọc Thuận
Quang Thuận
Thanh Thuận
Hải Thụy
Hồng Thụy
Vĩnh Thụy
Xuân Thuyết
Cát Uy
Gia Uy
Vũ Uy
Danh Văn
Khánh Văn
Kiến Văn
Quốc Văn
Khôi Vĩ
Triều Vĩ
Lâm Viên
Anh Việt
Dũng Việt
Hoài Việt
Hoàng Việt
Hồng Việt
Huy Việt
Khắc Việt
Nam Việt
Phụng Việt
Quốc Việt
Trọng Việt
Trung Việt
Tuấn Việt
Vương Việt
Công Vinh
Gia Vinh
Hồng Vinh
Quang Vinh
Quốc Vinh
Thanh Vinh
Thành Vinh
Thế Vinh
Trọng Vinh
Trường Vinh
Tường Vinh
Hữu Vĩnh
Quý Vĩnh
Chí Vịnh
Long Vịnh
Tiến Võ
Anh Vũ
Hiệp Vũ";
        #endregion

        #region Dánh sách tên đường - biến static string strTenDuong

        public static string strTenDuong =
@"Nguyễn Trãi
Cầu Giấy
Minh Khai
Lạc Long Quân
Trần Duy Hưng
Đường Láng
Hoàng Quốc Việt
Đội Cấn
Tôn Đức Thắng
Lương Thế Vinh
Kim Mã
Tây Sơn
Lĩnh Nam
Láng Hạ
Hoàng Đạo Thúy
Chùa Láng
Đường Xuân Thủy
Cầu Mai Động
Khâm Thiên
Thái Hà
Xã Đàn
Quốc Tử Giám
Trường Chinh
Vũ Trọng Phụng
Bạch Mai
Bà Triệu
Cầu Giấy
Hồ Tùng Mậu
Tam Trinh
Giải Phóng
Đê La Thành
Phố Huế
Hoàng Cầu
Nguyễn Chí Thanh
Chùa Láng
Trung Kính
Đinh Lễ
Phố Vọng
Văn Cao
Phạm Ngọc Thạch
Chùa Bộc
Thái Thịnh
Lò Đúc
Kim Ngưu
Ngõ Tự Do
Trung Tự
Cầu Mai Động
Ngõ Gốc Đề
Cổ Linh
Hoàng Ngân
Trần Thái Tông
Tràng Tiền
Hào Nam
Ngõ Trạm
Doãn Kế Thiện
Nguyễn Thái Học
Cầu Vĩnh Tuy
Hoàng Hoa Thám
Núi Trúc
Giáp Bát
Phố Đông Các
Nguyễn Khang
Hàng Mã
Nguyễn Văn Cừ
Lạc Trung
Xã Đàn
Lĩnh Nam
Minh Khai
Nguyễn Ngọc Vũ
Hai Bà Trưng
Thái Thịnh
Phạm Văn Đồng
Đường Láng
Hoàng Hoa Thám
Hoàng Quốc Việt
Trần Đại Nghĩa
Lê Thanh Nghị
Văn Miếu
Trần Hưng Đạo
Phương Mai
Lê Văn Lương
Đào Tấn
Hồ Dắc Di
Phạm Hùng
Phố Huế
Cầu Đất
Kim Ngưu
Nguyên Hồng
Quán Thánh
Nguyễn Du
Lý Thường Kiệt
Ngọc Khánh
Đường Láng
Lê Đức Thọ
Khương Trung
Khuất Duy Tiến
Dương Quảng Hàm
Ngõ Huyện
Nguyễn Xiển
Pháo Đài Láng
Đê La Thành
Giảng Võ
Hào Nam
Hoàng Cầu
Mai Anh Tuấn
Ngõ 127
Nguyễn Phúc Lai
Phố Đông Các
Trần Quang Diệu
Vũ Thạnh
Đại Lộ Thăng Long
Lê Trọng Tấn
Giải Phóng
Hoa Lư
Đại Cồ Việt
Lê Duẩn
Lê Thanh Nghị
Đường Nội Bộ Bách Khoa
Ngõ 1 Tạ Quang Bửu
Ngõ 106 Lê Thanh Nghị
Ngõ 106 Lê Thanh Nghị
Ngõ 37 Lê Thanh Nghị
Ngõ 40 Tạ Quang Bửu
Ngo 30 Ta Quang Buu
Nguyễn Hiền
Tạ Quang Bửu
Trần Đại Nghĩa
Xã Đàn
Bạch Mai
Hồng Mai
Lê Thanh Nghị
Ngo Y Te
Tạ Quang Bửu
Thanh Nhàn
Bạch Đằng
Cảm Hội
Hồng Hà
Lò Đúc
Lương Yên
Nguyễn Huy Tự
Nguyễn Khoái
Tăng Bạt Hổ
Trần Hưng Đạo
Trần Khát Chân
Trần Thánh Tông
Vạn Kiếp
Bà Triệu
Bùi Thị Xuân
Nguyễn Du
Triệu Việt Vương
Trương Hán Siêu
Tuệ Tĩnh
Bồ Đề
Cầu Chương Dương
Long Biên
Ngo 154 Ngoc Lam
Ngo 158 Nguyen Son
Ngo 370 Nguyen Van Cu
Nguyễn Văn Cừ
Phú Viên
Hoàng Hoa Thám
Lạc Long Quân
Đường Bưởi
Ngõ 218 Lạc Long Quân
Ngõ 282 Lạc Long Quân
Ngõ 424 Thụy Khê
Ngõ 81 Lạc Long Quân
Thụy Khuê
Vĩnh Phúc
Chợ Việt Hưng
Hoa Lâm
Nguyễn Văn Cừ
Cửa Nam
Hai Bà Trưng
Hàng Bông
Điện Biên Phủ
Lê Duẩn
Nguyễn Khuyến
Đình Ngang
Phan Bội Châu
Tống Duy Tân
Trần Qúy Cáp
Tràng Thi
Bát Đàn
Cửa Đông
Hà Trung
Hàng Hương
Lý Nam Đế
Đường Thành
Nguyễn Quang Bích
Phùng Hưng
Tt 34a Trần Phú
Hồ Tùng Mậu
Nguyễn Đổng Chi
Chương Dương Độ
Cầu Đất
Hàm Tử Quan
Hồng Hà
Hàng Vôi
Lê Lai
Nguyễn Khoái
Tràng Tiền
Đội Cấn
Linh Lang
Đường Bưởi
Ngõ 101 Đào Tấn
Ngõ 113 Đào Tấn
Ngõ 118 Đào Tấn
Đại Cồ Việt
Chùa Hà
Cầu Giấy
Dịch Vọng
Duy Tân
Mễ Trì
Đường Xuân Thủy
Nguyễn Khánh Toàn
Nguyễn Phong Sắc
Tôn Thất Thuyết
Trần Đăng Ninh
Trần Quốc Hoàn
Trần Tử Bình
Trần Thái Tông
Đường Xuân Thủy
Phạm Tuấn Tài
Trần Quốc Hoàn
Gia Thụy
Ngõ 564 Nguyễn Văn Cừ
Ngọc Lâm
Ngo 109 Nguyen Son
Ngo 449 Ngoc Lam
Ngo 514 Nguyen Van Cu
Ngo 548 Nguyen Van Cu
Ngo 554 Nguyen Van Cu
Nguyễn Sơn
Nguyễn Văn Cừ
Nguyễn Văn Linh
Đê La Thành
Kim Mã
Nam Cao
Ngõ 105
Ngõ 112 Ngọc Khánh
Ngõ 612 Đê La Thành
Ngõ 84 Ngọc Khánh
Ngọc Khánh
Ngo 12 Núi Trúc
Nguyễn Công Hoan
Giải Phóng
Giáp Bát
Kim Đồng
Ngõ 24 Kim Đồng
Ngõ 4 Kim Đồng
Định Công
Ngõ 477 Nguyễn Trãi
Nguyễn Xiển
Cửa Đông
Hàng Bồ
Hàng Cót
Hàng Gà
Hàng Điếu
Hàng Thiếc
Hàng Vải
Lãn Ông
Cầu Gỗ
Gia Ngư
Hàng Bạc
Đinh Liệt
Lương Văn Can
Mã Mây
Tạ Hiển
Trung Yên
Bà Triệu
Hàm Long
Hàng Bài
Lý Thường Kiệt
Ngô Văn Sở
Phố Huế
Trần Quốc Toàn
Trương Hán Siêu
Vọng Đức
Hà Trung
Hội Vũ
Hàng Bông
Hàng Da
Ngõ Hội Vũ
Ngõ Trạm
Nguyễn Văn Tố
Phùng Hưng
Quán Sứ
Thợ Nhuộm
Tống Duy Tân
Trần Phú
Tràng Thi
Tôn Đức Thắng
Văn Hương
Chợ Gạo
Hàng Buồm
Hàng Chiếu
Hàng Chĩnh
Hàng Đường
Hàng Ngang
Lãn Ông
Lương Ngọc Quyến
Mã Mây
Nguyễn Siêu
Đào Duy Từ
Tạ Hiển
Trần Nhật Duật
Bát Sứ
Hàng Điếu
Hàng Nón
Hàng Quạt
Đường Thành
Ngõ Trạm
Nguyễn Văn Tố
Hàng Cót
Hàng Lược
Hàng Mã
Lý Nam Đế
Phùng Hưng
Hàng Bồ
Hàng Cân
Hàng Gai
Hàng Đường
Hàng Đào
Hàng Quạt
Lò Rèn
Lương Văn Can
Tô Tịch
Thuốc Bắc
Bảo Khánh
Chân Cầm
Hai Bà Trưng
Hàng Da
Hàng Gai
Hàng Hòm
Hàng Hành
Hàng Mành
Hàng Trống
Lý Quốc Sư
Lê Thái Tổ
Ngõ Bảo Khánh
Ngõ Huyện
Ngõ Tạm Thương
Nhà Chung
Nhà Thờ
Phủ Doãn
Thọ Xương
Tràng Thi
Ấu Triệu
Đại Từ
Hoàng Mai
Nguyễn Đức Cảnh
Tam Trinh
Tân Mai
Duong Trong Khu Lang Bac
Giang Văn Minh
Đội Cấn
Ngo 110 Ngoc Ha
100 Doi Can
Cầu Lủ
Đại Từ
Kim Giang
Ngõ 168 Kim Giang
Ngõ 192 Kim Giang
Ngõ 250 Kim Giang
Ngõ 282 Kim Giang
Ngách 168
Nguyễn Cảnh Dị
Nguyễn Xiển
Đại Lộ Thăng Long
Vạn Phúc
Cao Bá Quát
Chùa Một Cột
Duong Trong Khu Lang Bac
Giảng Võ
Hàng Cháo
Hùng Vương
Hoàng Diệu
Điện Biên Phủ
Khúc Hạo
Lê Hồng Phong
Ông Ích Kiêm
Ngọc Hà
Nguyễn Thái Học
Nguyễn Tri Phương
Tôn Thất Thịêp
Trần Phú
Tt 34a Trần Phú
Khâm Thiên
Ngõ Chợ Khâm Thiên
Ngõ Văn Chương
Tôn Thất Tùng
Trường Chinh
Tây Sơn
Lê Trọng Tấn
Ngõ 126 Hoàng Văn Thái
Ngõ 128 Hoàng Văn Thái
Ngõ 158 Hoàng Văn Thái
Nguyễn Ngọc Nại
Nguyễn Viết Xuân
Tô Vĩnh Diện
Trường Chinh
Bùi Xương Trạch
Khương Hạ
Ngõ 122 Kim Giang
Hòang Văn Thái
Khương Trung
Ngõ 132 Khương Trung
Ngõ 164 Vương Thừa Vũ
Ngõ 211 Khương Trung
Tô Vĩnh Diện
Vũ Tông Phan
Hoàng Tích Trí
Lương Đình Của
Đông Tác
Đặng Văn Ngữ
Ngõ 43 Phố Phạm Ngọc Thạch
Ngõ 65 Phố Phạm Ngọc Thạch
Phạm Ngọc Thạch
Phương Mai
Trung Tự
Giang Văn Minh
Kim Mã
Nam Cao
Ngõ Núi Trúc
Ngõ 290 Kim Mã
Nguyễn Thái Học
Núi Trúc
Sơn Tây
Vạn Bảo
Vạn Phúc
100 Doi Can
Bà Triệu
Hầm Kim Liên
Hoa Lư
Lê Duẩn
Lê Đại Hành
Ngõ Bà Triệu
Nguyễn Bỉnh Khiêm
Nguyễn Đình Chiểu
Tô Hiến Thành
Thái Phiên
Trần Bình Trọng
Trần Nhân Tông
Xã Đàn
Phố Lê Lai
Phố Phó Đức Chính
Phố Trưng Vương
Cầu Gỗ
Cầu Thê Húc
Hàng Bè
Hàng Bạc
Hàng Dầu
Hàng Mắm
Hàng Muối
Hàng Thùng
Hàng Tre
Hàng Vôi
Đinh Tiên Hoàng
Lò Sũ
Lý Thái Tổ
Nguyễn Hữu Huân
Tông Đản
Trần Nguyên Hãn
Lĩnh Nam
Đường Vành Đai 3 Trên Cao
Nguyễn Khoái
Đốc Ngữ
Hoàng Hoa Thám
Đội Cấn
Đội Nhan
Liễu Giai
Ngõ VạN PhúC
Van Cao
Vạn Bảo
Văn Cao
Chùa Láng
Hoàng Ngọc Phách
Huỳnh Thúc Kháng
Láng Hạ
Đường Láng
Ngõ 100 Nguyễn Chí Thanh
Ngõ 105 Láng Hạ
Ngõ 107 Nguyễn Chí Thanh
Ngõ 28 Nguyễn Hồng
Ngõ 55 Huỳnh Thúc Kháng
Nguyễn Chí Thanh
Nguyên Hồng
Nguyễn Ngọc Vũ
Pháo Đài Láng
Thái Thịnh
Trúc Khê
Trần Duy Hưng
Chùa Láng
Cầu 361
Kim Mã
Ngõ Chùa Nền
Đường Láng
Ngõ 100 Nguyễn Chí Thanh
Ngõ 121 Chùa Láng
Ngõ 157 Pháo Đài Láng
Ngõ 159 Pháo Đài Láng
Ngõ 80 Chùa Láng
Ngõ 82 Chùa Láng
Ngõ 850
Ngõ 933 Đê La Thành
Nguyễn Khang
Pháo Đài Láng
Vũ Phạm Hàm
Cổ Linh
Cầu Vĩnh Tuy
Khu Cn Sai Dong
Lâm Du Bồ Đề
Tư Đình
Chung Cư 789
Duy Tân
Hồ Tùng Mậu
Lê Đức Thọ
Nguyễn Cơ Thạch
Nguyễn Đổng Chi
Phạm Hùng
Tôn Thất Thuyết
Trần Bình
Trần Hữu Dục
Dương Đình Nghệ
Lê Đức Thọ
Lê Quang Đạo
Mễ Trì
Đường Làng";

        #endregion

        #region Danh sách tên thành phố - biến static string strThanhPho

        public static string strThanhPho =
@"An Giang
Bà Rịa -Vũng Tàu
Bắc Giang
Bắc Kạn
Bạc Liêu
Bắc Ninh
Bến Tre
Bình Định
Bình Dương
Bình Phước
Bình Thuận
Cà Mau
Cao Bằng
Đắk Lắk
Đắk Nông
Điện Biên
Đồng Nai
Đồng Tháp
Gia Lai
Hà Giang
Hà Nam
Hà Tĩnh
Hải Dương
Hậu Giang
Hòa Bình
Hưng Yên
Khánh Hòa
Kiên Giang
Kon Tum
Lai Châu
Lâm Đồng
Lạng Sơn
Lào Cai
Long An
Nam Định
Nghệ An
Ninh Bình
Ninh Thuận
Phú Thọ
Quảng Bình
Quảng Nam
Quảng Ngãi
Quảng Ninh
Quảng Trị
Sóc Trăng
Sơn La
Tây Ninh
Thái Bình
Thái Nguyên
Thanh Hóa
Thừa Thiên Huế
Tiền Giang
Trà Vinh
Tuyên Quang
Vĩnh Long
Vĩnh Phúc
Yên Bái
Phú Yên
Cần Thơ
Đà Nẵng
Hải Phòng
Hà Nội
TP HCM";

        #endregion

        #region Danh sách ngân hàng Việt Nam - biến static string strNganHang

        public static string strNganHang =
@"Ngân hàng Á Châu
Ngân hàng Tiên Phong
Ngân hàng Đông Á
Ngân hàng Đông Nam Á
Ngân hàng An Bình
Ngân hàng Bắc Á
Ngân hàng Bản Việt
Hàng Hải Việt Nam
Kỹ Thương Việt Nam
Kiên Long
Nam Á
Quốc Dân
Việt Nam Thịnh Vượng
Phát triển nhà Thành phố Hồ Chí Minh
Phương Đông
Quân đội
Đại chúng
Quốc tế
Sài Gòn
Sài Gòn Công Thương
Sài Gòn-Hà Nội
Sài Gòn Thương Tín
Việt Á
Bảo Việt
Việt Nam Thương Tín
Xăng dầu Petrolimex
Xuất Nhập khẩu Việt Nam
Bưu điện Liên Việt
Ngoại thương Việt Nam
Công Thương Việt Nam
Đầu tư và Phát triển Việt Nam";

        #endregion

        #region Danh sách tên viết tắt ngân hàng Việt Nam -  static string strVietTatNganHang

        public static string strVietTatNganHang =
@"ACB
TPBank
DAB
SeABank
ABBANK
BacABank
VietCapitalBank
MSB
TCB
KienLongBank
Nam A Bank
NCB
VPBank
HDBank
OCB
MB
PVcombank
VIB
SCB
SGB
SHB
STB
VAB
BVB
VietBank
PG Bank
EIB
LPB
VCB
CTG
BIDV";

        #endregion

        #region Danh sách các thể loại sách - static string strTheLoaiSach

        string strTheLoaiSach =
@"Chính trị
Pháp luật
Khoa học công nghệ
Kinh tế
Văn hóa xã hội
Lịch sử
Văn học nghệ thuật
Giáo trình
Truyện, tiểu thuyết
Alternate history
Autobiography
Anthology
Biography
Chick lit
Book review
Children's literature
Cookbook
Comic book
Diary
Coming-of-age
Dictionary
Crime
Encyclopedia
Drama
Guide
Fairytale
Health
Fantasy
History
Graphic novel
Journal
Historical fiction
Math
Horror
Memoir
Mystery
Prayer
Paranormal romance
Religion, spirituality, and new age
Picture book
Textbook
Poetry	Review
Political thriller
Science
Romance
Self help
Satire
Travel
Science fiction
True crime
Short story
Suspense
Thriller";

        #endregion

        #region Danh sách nhà xuất bản
        /*
NXB Công An
NXB Công An Nhân Dân
NXB Công Thương
NXB Dân Trí
NXB Đại Học Bách Khoa
NXB Đại Học Kinh Tế Quốc Dân
NXB ĐHSP
NXB Giao Thông Vận Tải
NXB Hà Nội
NXB Hội Nhà Văn
NXB Hồng Bàng
NXB Hồng Đức
NXB Khoa Học Xã Hội
NXB Kim Đồng
NXB Lao Động
NXB Lao Động Xã Hội
NXB Mũi Cà Mau Minh Hải
NXB Mỹ Thuật
NXB Nam Sơn
NXB Phụ Nữ
NXB Phương Đông
NXB Phương Nam books
NXB Quân Đội Nhân Dân
NXB Thanh Hóa
NXB Thanh Niên
NXB Thể Dục Thể thao
NXB Thế Giới
NXB Thời Đại
NXB Thông Tấn
NXB Thông Tin Và Truyền Thông
NXB Thuận Hóa
NXB Tôn Giáo
NXB Tổng hợp thành phố HCM
NXB Trẻ
NXB Tri Thức
NXB Từ Điển Bách Khoa
NXB Văn Hóa Dân Tộc
NXB Văn Hóa Sài Gòn
NXB Văn Hóa Thông Tin
NXB Văn Hóa Văn Nghệ
NXB Văn Hóa Văn Nghệ TPHCM
NXB Văn Học
NXB Văn Mới (Sài Gòn)
NXB Văn Nghệ
NXB Văn Nghệ TP.HCM
NXB Y học
Thể thao văn hóa
*/
        #endregion

        #region Danh sách các thể loại

        /*
Chính trị
Pháp luật
Khoa học công nghệ
Kinh tế
Văn hóa xã hội
Lịch sử
Văn học nghệ thuật

Giáo trình
Truyện, tiểu thuyết
Tâm lý
Tâm linh
Tôn giáo
Sách thiếu nhi

Alternate history
Autobiography
Anthology
Biography
Chick lit

Book review
Children's literature
Cookbook
Comic book
Diary
Coming-of-age

Dictionary
Crime
Encyclopedia
Drama
Guide
Fairytale
Health
Fantasy
History
Graphic novel
Journal
Historical fiction
Math
Horror
Memoir
Mystery
Prayer
Paranormal romance
Religion, spirituality, and new age
Picture book
Textbook
Poetry	Review
Political thriller
Science
Romance
Self help
Satire
Travel
Science fiction
True crime
Short story
Suspense
Thriller
*/

        #endregion
        
        
        public static Random r = new Random();

        public static string[] arrHo;

        public static string[] arrTenDemRieng;

        public static string[] arrTenDuong;

        public static string[] arrThanhPho;

        public static string[] arrNganHang;

        public static string[] arrVietTatNganHang;

        public static int namSinh, thangSinh, ngaySinh , imaxHo, imaxTenDemRieng, imaxTenDuong, imaxThanhPho, imaxNganHang, imaxTheLoaiSach;

        static void Main(string[] args)
        {
            Lazy();

            #region Chỉnh sửa data trong file
            //using (StreamReader sr = new StreamReader(@"C:\Users\kenn8007\OneDrive - K3v(1)\Máy tính\Data_LastName.txt", System.Text.Encoding.Unicode))
            //{
            //    string line = sr.ReadToEnd();
            //    strHo = line.Replace("\\\r\n", "\n");
            //    // Console.WriteLine(line + "\n" + strHo);

            //}
            //File.WriteAllText(@"C:\Users\kenn8007\OneDrive - K3v(1)\Máy tính\Data_LastName.txt", strHo, Encoding.Unicode);
            #endregion

            int soLuong = 0;

            Console.Write("Nhap so luong can sinh: ");
            try
            {
                soLuong = Convert.ToInt32(Console.ReadLine());
            }
            catch
            {
                Console.Write("\nNhap vao 1 so!");
                Console.ReadKey(false);
                return;
            }

            string strt;
            string wtf = "";


            while (soLuong-- >= 0)
            {
                 //strt = SQL_Data.Data.NguoiDung_NganHang() + ",\n";
                //strt = SQL_Data.Data.NhanVien() + ",\n";
                //strt = SQL_Data.Data.NhanVien() + ",\n";
                //wtf += strt;
                //Console.WriteLine(strt);
               
                Console.WriteLine(Program.RandomOneNumberPhone());

            }
            File.WriteAllText(@"C:nguoidung_nganhang.txt", wtf, Encoding.Unicode);


            // dm hà tấn
            Console.ReadKey();
        }
        public static bool CheckDate(int ngj,int thj,int namj)
        {
            if (ngj < 1 || ngj > 31 || thj < 1 || thj > 12 || namj < 1900 || namj > 2100) return false;
            else
            {
                if ((thj == 4 || thj == 6 || thj == 9 || thj == 11) && (ngj > 30)) return false;
                else if (thj == 2)
                {
                    if (ngj > 28 && (namj % 4 != 0 || ((namj % 100 == 0) && (namj % 400 != 0)))) return false; //nam ko nhuan
                    else if (ngj > 29 && ((namj % 4 == 0) && ((namj % 400 == 0) || (namj % 100 != 0)))) return false; //nam nhuan
                }
            }
            return true;
        }

        public static string RandomOneName()
        {
            return arrHo[r.Next(0, imaxHo)] + " " + arrTenDemRieng[r.Next(0, imaxTenDemRieng)];
        }

        public static string RandomOneDate()
        {
            namSinh = r.Next(1970, 2015);
            thangSinh = r.Next(1, 13);
            ngaySinh = r.Next(1, 32);

            /// Đoạn này sinh ngày ngẫu nhiên nè
            if (!CheckDate(ngaySinh, thangSinh, namSinh))
                ngaySinh = r.Next(1, 29);

            return  namSinh.ToString() + "-" + 
                    (thangSinh > 9 ? thangSinh.ToString() : "0" + thangSinh.ToString()) + "-" + 
                    (ngaySinh > 9 ? ngaySinh.ToString() : "0" + ngaySinh.ToString());
        }

        public static string RandomOneNumberPhone()
        {
            return "034 " + r.Next(1000, 9999) + " " + r.Next(100, 999);
        }

        public static string RandomOneAddress()
        {
            return "Số " + r.Next(1, 423) + " " + arrTenDuong[r.Next(0, imaxTenDuong)] + " Tp (tỉnh) " + arrThanhPho[r.Next(0, imaxThanhPho)];
        }

        public static string RandomOneBankFullName(ref int index)
        {
            if (index < 0 || index >= imaxNganHang)
            {
                index = r.Next(0, imaxNganHang);
            }
            return arrNganHang[index];
        }

        public static string RandomOneBankShortName(ref int index)
        {
            if (index < 0 || index >= imaxNganHang)
            {
                index = r.Next(0, imaxNganHang);
            }
            return arrVietTatNganHang[index];
        }

        private static void Lazy()
        {
            // \r\n -> \n
            strHo = strHo.Replace("\r\n", "\n");
            strTenDemRieng = strTenDemRieng.Replace("\r\n", "\n");
            strThanhPho = strThanhPho.Replace("\r\n", "\n");
            strTenDuong = strTenDuong.Replace("\r\n", "\n");
            strNganHang = strNganHang.Replace("\r\n", "\n");
            strVietTatNganHang = strVietTatNganHang.Replace("\r\n", "\n");
            
            // tách chuỗi ký tự thành mảng string
            arrHo = strHo.Split('\n');
            arrTenDemRieng = strTenDemRieng.Split('\n');
            arrTenDuong = strTenDuong.Split('\n');
            arrThanhPho = strThanhPho.Split('\n');
            arrNganHang = strNganHang.Split('\n');
            arrVietTatNganHang = strVietTatNganHang.Split('\n');

            // Tính số lượng mảng
            imaxHo = arrHo.Count<string>();
            imaxTenDemRieng = arrTenDemRieng.Count<string>();
            imaxTenDuong = arrTenDuong.Count<string>();
            imaxThanhPho = arrThanhPho.Count<string>();
            imaxNganHang = arrNganHang.Count<string>();
        }
    }
   
}

namespace SQL_Data
{
    using EditSringDataList;
    public class Data
    {
        static int ii = 1;
        static int soCMND = 100100100;
        public static string NguoiDung()
        {
            return  // số cmnd
                    "('0" + (soCMND++) + "'"

                    // tên tk
                    + ", 'TK" + (ii < 10 ? "0" + ii.ToString() : ii.ToString()) + "'"

                    // mật khẩu
                    + ", 'MK" + (ii < 10 ? "0" + ii++.ToString() : ii++.ToString()) + "'"

                    // tên
                    + ", N'" + Program.RandomOneName() + "'"

                    // số điện thoại
                    + ", '" + Program.RandomOneNumberPhone() + "'"

                    // địa chỉ thường trú
                    + ", N'" + Program.RandomOneAddress() + "'"

                    // giới tính (0-1)
                    + ", " + Program.r.Next(0, 2)

                    // ngày sinh
                    + ", '" + Program.RandomOneDate() + "'"

                    // tên người bảo hộ
                    + ", N'" + Program.RandomOneName() + "'"

                    // sdt người bảo hộ
                    + ", '" + Program.RandomOneNumberPhone() + "'"

                    // địa chỉ người bảo hộ
                    + ", N'" + Program.RandomOneAddress() + "')"
                    ;
        }

        static int sttNhanVien = 1;
        public static string NhanVien()
        {
            return  // mã nhân viên
                    "('NV1001" + (sttNhanVien < 10 ? "0" + sttNhanVien.ToString() : sttNhanVien.ToString()) + "'"

                    // mật khẩu
                    + ", 'MK" + (sttNhanVien < 10 ? "0" + sttNhanVien++.ToString() : sttNhanVien++.ToString()) + "'"

                    // Tên nhân viên
                    + ", N'" + Program.RandomOneName() + "'"

                    // số cmnd
                    + ", '0" + Program.r.Next(10101010, 98989898) + "'"

                    // địa chỉ
                    + ", N'" + Program.RandomOneAddress() + "'"

                    // số điện thoại
                    + ", '" + Program.RandomOneNumberPhone() +"'"

                    // giới tính
                    + ", " + Program.r.Next(0, 2)

                    // ngày sinh
                    + ", '" + Program.RandomOneDate() + "')";
        }

        static int sttNganHang = -1;
        public static string NganHang()
        {
            if (sttNganHang < Program.imaxNganHang - 1)
                ++sttNganHang;
            else
                return "";

            return  // mã ngân hàng
                    "(N'" + Program.RandomOneBankShortName(ref sttNganHang) + "'"
                    // tên ngân hàng
                    +", N'" + Program.RandomOneBankFullName(ref sttNganHang) + "'"
                    // địa chỉ ngân hàng
                    +", N'" + Program.RandomOneAddress() + "')";
        }

        static int sttSach = 1;
        public static string MuonSach()
        {
            int tam = Program.r.Next(1, 42);
            return  // số cmnd người mượn sách
                    "('0" + Program.r.Next(100100100, 100100141).ToString() + "'"

                    // mã sách
                    + ", 'S0" + (sttSach < 10 ? "0" + sttSach++.ToString() : sttSach++.ToString()) + "'"

                    // mã nhân viên
                    + ", 'NV1001" + (tam < 10 ? "0" + tam.ToString() : tam.ToString()) + "'"

                    // ngày mượn sách
                    + ", '" + Program.RandomOneDate() + "')";
        }

        static int iSoCMND = 0;
        static int iSoTaiKhoanNganHang = 0;
        public static string NguoiDung_NganHang()
        {
            if (sttNganHang < Program.imaxNganHang - 1)
                ++sttNganHang;
            else
                return "";

            return  // số cmnd
                    "('01001001" + (iSoCMND < 10 ? "0" + iSoCMND++.ToString() : iSoCMND++.ToString()) + "'"

                    // mã ngân hàng
                    + ", N'" + Program.RandomOneBankShortName(ref sttNganHang) + "'"

                    // số tài khoản ngân hàng
                    + ", 'TK01001001" + (iSoTaiKhoanNganHang < 10 ? "0" + iSoTaiKhoanNganHang++.ToString() : iSoTaiKhoanNganHang++.ToString()) + "')";
        }
        public static string NhanVien_NganHang()
        {
            if (sttNganHang < Program.imaxNganHang - 1)
                ++sttNganHang;
            else
                return "";

            return  // số thứ tự nhân viên
                    "('NV1001" + (sttNhanVien < 10 ? "0" + sttNhanVien++.ToString() : sttNhanVien++.ToString()) + "'"

                    // mã ngân hàng
                    + ", N'" + Program.RandomOneBankShortName(ref sttNganHang) + "'"

                    // số tài khoản ngân hàng
                    + ", 'TK01001002" + (iSoTaiKhoanNganHang < 10 ? "0" + iSoTaiKhoanNganHang++.ToString() : iSoTaiKhoanNganHang++.ToString()) + "')";
        }

        public static string NhanSach()
        {
            int tam = Program.r.Next(1, 42);
            return  // mã sách đã mượn
                    "('S0" + (sttSach < 10 ? "0" + sttSach++.ToString() : sttSach++.ToString()) + "'"

                    // mã nhân viên
                    + ", 'NV1001" + (tam < 10 ? "0" + tam.ToString() : tam.ToString()) + "'"

                    // ngày nhận sách
                    + ", '" + Program.RandomOneDate() + "')";
        }
    }
}