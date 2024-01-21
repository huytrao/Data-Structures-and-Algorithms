// Hàm tìm kiếm nhị phân sử dụng giải thuật đệ quy
int binarySearch(int arr[], int l, int r, int x) {
  if (r >= l) {
    int mid = l + (r - l) / 2; // Tương đương (l+r)/2 nhưng ưu điểm tránh tràn số khi l,r lớn

    // Nếu arr[mid] = x, trả về chỉ số và kết thúc.
    if (arr[mid] == x)
      return mid;

    // Nếu arr[mid] > x, thực hiện tìm kiếm nửa trái của mảng
    if (arr[mid] > x)
      return binarySearch(arr, l, mid - 1, x);

    // Nếu arr[mid] < x, thực hiện tìm kiếm nửa phải của mảng
    return binarySearch(arr, mid + 1, r, x);
  }

  // Nếu không tìm thấy
  return -1;
}
// Phân tích hàm đệ quy theo quy trình bốn bước:
// 1. Xác định điểm dừng: Khi left > right (1), khi arr[mid] == val (2)
//   
//2. với (1)  Trong trường hợp này, trả về -1 để thể hiện không tìm thấy phần tử trong mảng, vói (2) trả về giá trị mid.
//3. với left == right 
//    Điều này áp dụng trong hai trường hợp:
//    - Nếu arr[mid] == target, trả về mid để thể hiện phần tử được tìm thấy.
//    - Nếu arr[mid] > target,  trả về -1
//    - Nếu arr[mid] < target, trả về -1
//4.với left >= right 
//    Điều này áp dụng trong hai trường hợp:
//    - Nếu arr[mid] == target, trả về mid để thể hiện phần tử được tìm thấy.
//    - Nếu arr[mid] > target,  gọi đệ quy tìm kiếm trong nửa trái của mảng
//    - Nếu arr[mid] < target,  gọi đệ quy tìm kiếm trong nửa phải của mảng.
