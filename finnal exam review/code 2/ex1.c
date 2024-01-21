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
//Bước 1: Base Case: r<l
// Bước 2: Trả về -1.
// Bước 3: với r=l thì mid = r=l  nếu arr[mid] == x thì return mid còn không thì không tìm thấy trả về 1
// Bước 4 với r = l+1 thì mid = r = l = (int) 8.5 =5 nếu arr[mid] = x thì return mid còn không thì không tìm thấy trả về 1
