// PAT1037-MagicCoupon.cpp
// Ad
// Init: 19Jun08

// Score: 22/25
// Spent Time: 23 min
// Runtime: 49 ms

/* -----------------------------------------------------------------------------

1037 Magic Coupon (25 分)

The magic shop in Mars is offering some magic coupons. 
Each coupon has an integer N printed on it, meaning that when you use this coupon with a product, you may get N times the value of that product back! What is more, the shop also offers some bonus product for free. 
However, if you apply a coupon with a positive N to this bonus product, you will have to pay the shop N times the value of the bonus product... but hey, magically, they have some coupons with negative N's!

For example, given a set of coupons { 1 2 4 −1 }, and a set of product values { 7 6 −2 −3 } (in Mars dollars M$) where a negative value corresponds to a bonus product. 
You can apply coupon 3 (with N being 4) to product 1 (with value M$7) to get M$28 back; 
coupon 2 to product 2 to get M$12 back; 
and coupon 4 to product 4 to get M$3 back. 
On the other hand, if you apply coupon 3 to product 4, you will have to pay M$12 to the shop.

Each coupon and each product may be selected at most once. 
Your task is to get as much money back as possible.

### Input Specification:

Each input file contains one test case. 
For each case, the first line contains the number of coupons NC, followed by a line with NC coupon integers. 
Then the next line contains the number of products NP, followed by a line with NP product values. 
Here 1 ≤ NC, NP ≤ 10^5, and it is guaranteed that all the numbers will not exceed 2^30.

### Output Specification:

For each test case, simply print in a line the maximum amount of money you can get back.

----------------------------------------
Sample Input:
4
1 2 4 -1
4
7 6 -2 -3
Sample Output:
43
----------------------------------------

----------------------------------------------------------------------------- */

#include <iostream>
#include <set>

using namespace std;

set<long long> inputNumbers(int num);
unsigned long long getMaxAmount(const set<long long> &coupons, const set<long long> &products);

// Main ------------------------------------------------------------------------

int main()
{
    int numCoupons = 0;
    cin >> numCoupons;
    auto coupons = inputNumbers(numCoupons);
    int numProducts = 0;
    cin >> numProducts;
    auto products = inputNumbers(numProducts);

    cout << getMaxAmount(coupons, products) << endl;

    system("pause");
    return 0;
}

// Functions -------------------------------------------------------------------

set<long long> inputNumbers(int num)
{
    set<long long> ret;
    long long value = 0;

    for (int i = 0; i < num; ++i)
    {
        cin >> value;
        ret.insert(value);
    }

    return ret;
}

unsigned long long getMaxAmount(const set<long long> &coupons, const set<long long> &products)
{
    unsigned long long ret = 0;

    auto itr1 = coupons.begin(), itr2 = products.begin();
    while (itr1 != coupons.end() && itr2 != products.end())
    {
        if (*itr1 < 0 && *itr2 < 0)
            ret += *itr1++ * *itr2++;
        else
            break;
    }

    auto itr3 = coupons.rbegin(), itr4 = products.rbegin();
    while (itr3 != coupons.rend() && itr4 != products.rend())
    {
        if (*itr3 > 0 && *itr4 > 0)
            ret += *itr3++ * *itr4++;
        else
            break;
    }

    return ret;
}
