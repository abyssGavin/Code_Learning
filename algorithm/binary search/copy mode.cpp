// template<typename T>
// int binarySearch(T arr[], int l, int r, T x)
// {
//     while(l <= r) {
//         int mid = l + (r - l) / 2;

//         if (arr[mid] == x) {
//             return mid;  // element found
//         }
//         else if (arr[mid] < x) {
//             l = mid + 1;  // narrow down to the right half
//         }
//         else {
//             r = mid - 1;  // narrow down to the left half
//         }
//     }
//     return -1;  // element not found
// }



// template<typename T>
// int binarySearch(T arr[], int l, int r, T x)
// {
//     while(l <= r) {
//         int mid = l + (r - l) / 2;

//         if (arr[mid] == x) {
//             return mid;  // element found
//         }
//         else if (arr[mid] < x) {
//             l = mid + 1;  // narrow down to the right half
//         }
//         else {
//             r = mid - 1;  // narrow down to the left half
//         }
//     }
//     return -1;  // element not found
// }

// int upper_bound(int arr[], int l, int r, int x)
// {
//     int mid;
//     while (l < r)
//     {
//         mid = l + r + 1 >> 1;
//         if (arr[mid] <= x) l = mid;
//         else r = mid - 1;
//     }
//     return l;
// }

