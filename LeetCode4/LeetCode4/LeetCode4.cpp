// LeetCode4.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:

    // https://leetcode.com/problems/median-of-two-sorted-arrays/description/

    double findMedianSortedArrays1(vector<int>& nums1, vector<int>& nums2) {
        int n1 = 0;
        int n2 = 0;
        double med1 = 0;
        double med2 = 0;
        int n1l=0;
        int n1r=0;
        int n2l=0;
        int n2r=0;

        if (nums1.size() % 2 == 0)
        {
            n1l = nums1.size() / 2 - 1;
            n1r = nums1.size() / 2;
            med1 = (nums1[n1r] + nums1[n1l]) / 2;
        }
        else
        {
            n1l = nums1.size() / 2;
            n1r = nums1.size() / 2;
            med1 = nums1[nums1.size() / 2];
        }
        if (nums2.size() % 2 == 0)
        {
            n2l = nums2.size() / 2 - 1;
            n2r = nums2.size() / 2;
            med2 = (nums2[n2r] + nums2[n2l]) / 2;
        }
        else
        {
            n2l = nums2.size() / 2;
            n2r = nums2.size() / 2;
            med2 = nums2[nums2.size() / 2];
        }

        double med = (med1 + med2) / 2; // ориентировочная медиана
        // для начальных индексов поиска выбираю наибольший из левых и наименьший из правых
        if (nums1[n1l] < nums2[n2l]) { 
            n1 = n1r;
        }
        else
            n1 = n1l;

        if (nums2[n2r] < nums1[n1r]) {
            n2 = n2r;
        }
        else
            n2 = n2l;

        // размер итогового массива четный или нет

        bool even = false;
        if ((nums1.size() + nums2.size())%2==0) {
            even = true;
            int a = (nums1.size() + nums2.size()) / 2;//индекс медианы в итоговом отсортированном массиве
            int i;
            if (med1 < med2)// тогда я беру правую часть первого вектора и левую часть правого
            {                
                n1 = n1r;
                n2 = n2l;
                i = a-n1;
                if (i != 0) {
                    if (nums1[n1] < nums2[n2]) {
                        n1++;
                    }
                }
                
            }
        }


        


        return 0.0;
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        if (m == 0)
        {
            if (n % 2 == 1)
            {
                return nums2[n / 2];
            }
            else
            {
                return 1.0*(nums2[n / 2]+ nums2[n / 2 - 1]) / 2;
            }
        }
        if (n == 0)
        {
            if (m % 2 == 1)
            {
                return nums1[m / 2];
            }
            else
            {
                return 1.0 * (nums1[m / 2] + nums1[m / 2 - 1]) / 2;
            }
        }
        int tempm = m;
        int tempn = n;
        int med1ind= m / 2;
        int med2ind = n / 2;
        double med1 = 0.;
        double med2 = 0.;
        if (m % 2 == 1)
        {
            med1 = nums1[med1ind];
        }
        else
        {
            med1ind--;
            med1 = (nums1[med1ind] + nums1[med1ind + 1]) / 2;
        }
        if (n % 2 == 1)
        {
            med2 = nums2[med2ind];
        }
        else
        {
            med2ind--;
            med2= (nums2[med2ind] + nums2[med2ind + 1]) / 2;
        }

        int nm = m + n;
        bool even = false;

        int medind = nm / 2;
        int away1 = 0;
        int away2 = 0;

        if (nm % 2 == 0)
        {
            medind--; // index of median for end array
            even = true;
        }
        if (med1 <= med2) 
        {
            int tempind = min({ (medind + 1) / 2,tempm,tempn });
            while (tempind > 0 && tempm != 0 && tempn != 0)
            {
                medind -= tempind;                
                if (nums1[away1+tempind-1] <= nums2[away2+tempind-1])
                {         
                   away1 += tempind;
                   tempm -= tempind;
                }
                else
                {
                    away2 += tempind;
                    tempn -= tempind;
                }
                tempind = std::min({ (medind + 1) / 2,tempm,tempn });
            }
            if (tempm == 0 || tempn==0)
            {
                if (tempm == 0)
                {
                    tempind = std::min({ (medind + 1) / 2,tempn });
                    away2 += tempind;
                    tempind = 0;
                }
                else
                {
                    tempind = std::min({ (medind + 1) / 2,tempm });
                    away1 += tempind;
                }
            }
            int i = away1 + tempind;
            int j = away2 + tempind;
            if (!even) {
                if (tempm != 0 && tempn != 0)
                {
                    
                    if (nums1[i] < nums2[j])
                    {
                        return 1.0 * nums1[i];
                    }
                    else
                    {
                        return 1.0 * nums2[j];
                    }
                }
                else
                {
                    if (tempm == 0)
                    {
                        if (tempind == 0)//j==0
                        {
                            return 1.0 * nums2[j];
                        }
                        return 1.0 * nums2[j - 1];
                    }
                    else
                    {
                        return 1.0 * nums1[i-1];
                    }
                }
            }
            else
            {
                if (tempm != 0 && tempn != 0)
                {
                    if (nums1[i] > nums2[j] && j < n - 1)
                    {
                        if (nums2[j + 1] < nums1[i])
                        {
                            return 1.0 * (nums2[j] + nums2[j + 1]) / 2;
                        }
                    }
                    else
                    {
                        if (i < m - 1)
                        {
                            if (nums1[i + 1] < nums2[j])
                            {
                                return 1.0 * (nums1[i] + nums1[i + 1]) / 2;
                            }
                        }
                    }
                    return (nums1[i] + nums2[j]) * 1.0 / 2.0;
                }
                else
                {
                    if (tempm == 0)
                    {
                        return 1.0 * (nums2[j] + nums2[j + 1]) / 2;
                    }
                    else
                    {
                        return 1.0 * (nums1[i] + nums1[i + 1]) / 2;
                    }
                }
            }
        }
        else
        {
            return findMedianSortedArrays(nums2, nums1);
        }
        return 0.0;
    }
};

int main()
{
    Solution s;
    vector<int> nums1={2 };
    vector<int> nums2 = { 1,3,4,5};
    cout << s.findMedianSortedArrays(nums1, nums2)<<" = 3 "<<"\n";

    nums1 = { 1,2,3,4 };
    nums2 = { 5,6,7,8,9,10,11,12,13,14,15 };
    cout << s.findMedianSortedArrays(nums1, nums2) << " = 8" <<"\n";

    nums1 = { 1};
    nums2 = { 2,3,4,5,6 };
    cout << s.findMedianSortedArrays(nums1, nums2) << " = 3.5" <<"\n";
}
