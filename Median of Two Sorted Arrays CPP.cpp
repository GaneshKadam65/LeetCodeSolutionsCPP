#include <vector>

double findMedianSortedArrays(const std::vector<int>& nums1, const std::vector<int>& nums2) {
    int m = nums1.size();
    int n = nums2.size();

    // Ensure nums1 is the smaller array
    if (m > n) {
        return findMedianSortedArrays(nums2, nums1);
    }

    int left = 0;
    int right = m;
    int halfLen = (m + n + 1) / 2;

    while (left <= right) {
        int partitionX = (left + right) / 2;
        int partitionY = halfLen - partitionX;

        int maxLeftX = (partitionX == 0) ? INT32_MIN : nums1[partitionX - 1];
        int minRightX = (partitionX == m) ? INT32_MAX : nums1[partitionX];
        int maxLeftY = (partitionY == 0) ? INT32_MIN : nums2[partitionY - 1];
        int minRightY = (partitionY == n) ? INT32_MAX : nums2[partitionY];

        if (maxLeftX <= minRightY && maxLeftY <= minRightX) {
            if ((m + n) % 2 == 0) {
                return (std::max(maxLeftX, maxLeftY) + std::min(minRightX, minRightY)) / 2.0;
            } else {
                return std::max(maxLeftX, maxLeftY);
            }
        } else if (maxLeftX > minRightY) {
            right = partitionX - 1;
        } else {
            left = partitionX + 1;
        }
    }

    // The code should never reach this point if the input is valid
    throw std::runtime_error("Invalid input");
}

int main() {
    std::vector<int> nums1 = {1, 3, 5};
    std::vector<int> nums2 = {2, 4, 6};

    double median = findMedianSortedArrays(nums1, nums2);
    std::cout << "Median: " << median << std::endl;

    return 0;
}
