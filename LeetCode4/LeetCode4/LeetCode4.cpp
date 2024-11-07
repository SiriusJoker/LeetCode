// LeetCode4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

    // https://leetcode.com/problems/median-of-two-sorted-arrays/description/

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0;
        int n2 = 0;
        if ((nums1.size() % 2 == 1 && nums2.size() % 2 != 1) ||
            (nums2.size() % 2 == 1 && nums1.size() % 2 != 1)) {
            int j = (nums1.size() + nums2.size()) / 2;

            for (int count = 0; count <= j; count++) {
                if (count == j) {
                    if (nums1[n1] > nums2[n2]) {
                        return nums2[n2];
                    }
                    else
                        return nums1[n1];
                }
                if (nums1[n1] > nums2[n2]) {
                    n2++;
                }
                else
                    n1++;
            }
        }
        else {
            if (nums1.size() > 0 && nums2.size() > 0) {
                int i = (nums1.size() + nums2.size()) / 2;
                int j = i - 1;
                double sum = 0;
                for (int count = 0; count <= i; count++) {
                    if (count < i - 1) {
                        if (nums1[n1] > nums2[n2]) {
                            n2++;
                        }
                        else
                            n1++;
                    }
                    else {
                        if (count == j || count == i) {
                            if (n1 < nums1.size() && n2 < nums2.size())
                            {
                                if (n1 == nums1.size() || nums1[n1] > nums2[n2]) {
                                    sum += nums2[n2];
                                    n2++;
                                }
                                else {
                                    sum += nums1[n1];
                                    n1++;
                                }
                            }
                            else {
                            if (n1 == nums1.size()) {
                                sum += nums2[n2];
                                n2++;
                            }
                            if (n2 == nums2.size()) {
                                sum += nums1[n1];
                                n1++;
                            }
                        }
                        }
                    }
                }
                return sum / 2;
            }
        }
        return 0.0;
    }
};

int main()
{
    Solution s;
    vector<int> nums1={ 1,2 };
    vector<int> nums2 = { 3,4 };
    //cout << nums1.size() % 2 << "\n";
    //cout << nums2.size() % 2 << "\n";
    cout << s.findMedianSortedArrays(nums1, nums2);
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
