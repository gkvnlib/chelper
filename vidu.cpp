#include "helper.h"

void doc_va_viet_vao_file() {
    // Đọc một file theo đường dẫn
    List<string> input = readf("file ở đây");
    // In nội dung ra stdout
    for (const auto &line: input) {
        print("file có ", line); // PYTHON print()
    }

    /*
     * Viết vào file theo đường dẫn
     * NỘI DUNG sẽ được chèn vào cuối file
     */
    appendf("file ở đây", "NỘI DUNG");
}

void list_tien_loi() {
    /* Tạo list (có 3 cách tạo) */

    // Tạo 1 list trống, có thể đột biến
    List<int> list1;
    // Tạo 1 list có các giá trị cho trước
    List<int> list2 = {1, 2, 4, 3, 6, 8, 7, 10};
    // Tạo 1 list từ vector<T>
    vector<int> vector = {1,2,3,4,5};
    List<int> list3 = vector;

    /* Các cú pháp của Dãy tiện lợi */

    // Lấy phần tử thứ n
    list1.get(0);

    // Độ lớn của dãy
    list1.size();

    // Kiểm tra xem dãy có trống không
    bool empty = list1.isEmpty();

    // Thêm 1 phần tử cùng loại
    list1.add(100);

    // Kiểm tra nếu phần tử có tồn tại hay không
    bool a = list1.contains(100); // true

    // Xóa bỏ phần tử
    list1.remove(100);

    // Xáo tung dãy
    list1.shuffle();

    // Sắp xếp dãy theo thuật toán QUICKSORT (O(n log n))
    list1.quickSort();

    // Kiểm tra xem dãy có phải là dãy số không
    bool numeric = list1.isNumericList();

    /* Lặp qua dãy thông qua
     * toán tử lambda
     */
    list1.forEach([](auto i) {
       print(i);
    });

    /* Xóa bỏ nếu như điều kiện == true
     * Trong ví dụ dưới thì sẽ loại bỏ toàn bộ
     * các số chia hết cho 2
     */
    list1.removeIf([](int thanhphan) {
        return thanhphan % 2 == 0;
    });
}

void cac_chuc_nang_khac() {
    /*
     * Các hàm về LIST
     */

    // Kiểm tra nếu List 1 có giao với List 2 không
    List<int> list1 = {1,2,3};
    List<int> list2 = {4,5,6};
    bool intersec = hasIntersection(list1, list2); // false

    // Ghép 2 List vào nhau
    List<int> list3 = merge(list1, list2);

    /* Hàm sigma
     * Ví dụ bên dưới tính tổng của x chạy từ 0 đến 100
     */
    double ketqua = sigma(0, 100, [](int x) {
       return x;
    });

    /* Hàm print giống kiểu
     *  PYTHON
     */
    print("", 100, " abc");
    // bool thứ nhất sẽ quyết định nếu print có
    // xuống dòng hay không
    cprint(false, "", 100, " abc");
}