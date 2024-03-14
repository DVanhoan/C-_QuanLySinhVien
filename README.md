# C-_QuanLySinhVien
1. Phương thức addStudent:
Mục đích: Thêm một sinh viên mới vào danh sách.
Tham số:
name: Tên của sinh viên.
day, month, year: Ngày tháng năm sinh của sinh viên.
mathMark, physicMark, languageMark: Điểm môn Toán, Vật lý, và Ngôn ngữ của sinh viên.
Cách thức hoạt động:
Tạo một sinh viên mới với thông tin được cung cấp.
Nếu danh sách đang trống (không có sinh viên nào), thì sinh viên mới trở thành phần tử đầu tiên của danh sách.
Ngược lại, tìm phần tử cuối cùng trong danh sách và liên kết sinh viên mới vào sau phần tử cuối cùng.

2. Phương thức addStudentFromInput:
Mục đích: Nhập thông tin của sinh viên từ bàn phím và thêm vào danh sách.
Cách thức hoạt động:
Yêu cầu người dùng nhập tên, ngày tháng năm sinh và điểm của sinh viên.
Gọi phương thức addStudent để thêm sinh viên mới vào danh sách.

3. Phương thức printList:
Mục đích: In ra toàn bộ danh sách sinh viên.
Cách thức hoạt động:
Duyệt qua từng phần tử trong danh sách.
In ra thông tin của mỗi sinh viên, bao gồm tên, ngày tháng năm sinh và điểm các môn học.

4. Phương thức countStudentsInYear:
Mục đích: Đếm số lượng sinh viên sinh vào một năm cụ thể.
Tham số:
year: Năm cần đếm.
Cách thức hoạt động:
Duyệt qua từng sinh viên trong danh sách.
Tăng biến đếm nếu năm sinh của sinh viên trùng khớp với năm được cung cấp.
Trả về số lượng sinh viên được đếm.

5. Phương thức checkStudentExists:
Mục đích: Kiểm tra xem một sinh viên có tồn tại trong danh sách không.
Tham số:
name: Tên sinh viên cần kiểm tra.
Cách thức hoạt động:
Duyệt qua từng sinh viên trong danh sách.
So sánh tên của sinh viên với tên được cung cấp.
Trả về true nếu tìm thấy, ngược lại trả về false.

6. Phương thức deleteStudentByName:
Mục đích: Xóa sinh viên khỏi danh sách dựa trên tên.
Tham số:
name: Tên sinh viên cần xóa.
Cách thức hoạt động:
Nếu danh sách rỗng, thông báo và kết thúc.
Nếu sinh viên cần xóa là phần tử đầu tiên của danh sách, thì cập nhật con trỏ head để bỏ qua sinh viên này.
Nếu sinh viên cần xóa không phải là phần tử đầu tiên, duyệt qua danh sách để tìm và xóa sinh viên đó.
Nếu không tìm thấy sinh viên, thông báo không tìm thấy.
(Nhớ rằng mình đã thêm hàm hủy (destructor) vào StudentList để giải phóng bộ nhớ khi đối tượng bị hủy.)

7. Phương thức findHighestAverage:
Mục đích: Tìm sinh viên có điểm trung bình cao nhất.
Cách thức hoạt động:
Kiểm tra xem danh sách có rỗng không.
Duyệt qua từng sinh viên trong danh sách.
Tính điểm trung bình của mỗi sinh viên bằng cách lấy trung bình cộng của điểm các môn.
So sánh điểm trung bình với điểm trung bình cao nhất hiện tại.
Lưu lại sinh viên có điểm trung bình cao nhất.

8. Phương thức printMathLessThan5:
Mục đích: In ra danh sách sinh viên có điểm môn Toán dưới 5.
Cách thức hoạt động:
Kiểm tra xem danh sách có rỗng không.
Duyệt qua từng sinh viên trong danh sách.
Kiểm tra điểm môn Toán của mỗi sinh viên.
Nếu điểm môn Toán dưới 5, in ra thông tin của sinh viên đó.
Nếu không có sinh viên nào có điểm môn Toán dưới 5, thông báo không tìm thấy.

9. Phương thức writeToFile:
Mục đích: Ghi thông tin của danh sách sinh viên vào một tệp văn bản.
Tham số:
filename: Tên tệp để ghi vào.
Cách thức hoạt động:
Mở tệp để ghi.
Kiểm tra xem tệp có được mở thành công không.
Nếu danh sách rỗng, thông báo và kết thúc.
Duyệt qua từng sinh viên trong danh sách và ghi thông tin của mỗi sinh viên vào tệp.
Đóng tệp sau khi ghi xong.
