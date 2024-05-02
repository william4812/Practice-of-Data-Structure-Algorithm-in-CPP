#include <string>
#include <iostream>
#include <cstdlib>
#include <unordered_map>
#include <math.h>       /* log10 */
#include <bits/stdc++.h> /*MAX_INT ; MIN_INT*/
#include <numeric>      // std::accumulate
#include <vector>
#include "Solution.h"
#include <utility>      // std::pair, std::make_pair
#include <stdlib.h>     /* atoi */ 
#include <typeinfo>
#include <assert.h>     /* assert */
#include <cstdio>       // printf
#include <queue>        // priority_queue
#include <algorithm>    // max_element, count
#include <random>       // random_device

using namespace std;
/*S: Solution*/
using S::Solution;
using S::LinkedList;
using S::ListNode;
using S::TreeNode;
/*T: Thread*/
using T::Thrd;
/*C: Callback*/
//using C::Functor;

/*S2: Callback*/
using namespace STWO;
using namespace STHREE;
using namespace STREE;
using namespace SHUFFLE;

bool STHREE::hasCycle(STHREE::ListNode* head) {
  if (!head /*empty node*/ || !(head->next) /*single node*/)
    return false;

  ListNode* tmp1 = head;
  ListNode* tmp2 = head;
  
  while (tmp2 && tmp2->next) {
    tmp1 = tmp1->next;
    tmp2 = tmp2->next->next;

    if (tmp1 == tmp2)
      return true;
  }
  return false;
  /*
  ListNode* tmp = head;

  int max=0;
  while (max < 10) {
    cout << tmp->val << endl;
    tmp = tmp->next;
    ++max;
  }
  */
}

void STHREE::LinkedList::addNode(ListNode* tmp) {
  //ListNode* newNode = new ListNode(0);
  //newNode->val = tmp->val;
  //newNode->next = this->first;
  //this->first = newNode;
  
  tmp->next = this->first;
  this->first = tmp;
}

void STHREE::LinkedList::deleteNode(ListNode* tmp) {
  tmp->val = tmp->next->val;
  tmp->next = tmp->next->next;
}

void STHREE::LinkedList::printNode() {
  ListNode* it = this->first;
  do {
    cout << it->val << " ";
    it = it->next;
  } while  (it != nullptr);
  cout << "\n";
}

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
/*
ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
        return head ? reverseList(head->next, (head->next = prev, head)) : prev;
*/
/*
STWO::ListNode* STWO::LinkedList::reverseList(ListNode* head, ListNode* prev=nullptr) {
  
  return head ? reverseList(head->next, (head->next = prev, head)) : prev ;
}
*/

STWO::ListNode* STWO::LinkedList::reverseList(ListNode* head) {
  ListNode* nextN;
  ListNode* prevN=nullptr;
  while (head != nullptr) {
    nextN = head->next;
    head->next = prevN;
    
    prevN = head;
    cout << prevN->val << "\n";
    head = nextN;
    
    //cout << head->val << "\n";
  }
  this->first = prevN;
  return prevN;
  //ListNode* revHead = reverseNode(head);
  //revHead->next = nullptr;
  //return revHead;
}

STWO::ListNode* STWO::LinkedList::reverseNode(ListNode* cur) {
  ListNode* tmp = cur->next;
  ListNode* prev;
  if (tmp->next == nullptr) {
    this->first = tmp;
    first->next = cur;
    cout << "this->first " << this->first->val << endl;
    cout << "first->next " << first->next->val << endl;
    return first->next;
  } 
  else {
    prev = cur;
    cur = reverseNode(tmp);
    cur->next = prev;
    cout << "cur-value " << cur->val<<"\n";
    cout << "cur-next->value " << cur->next->val<<"\n";
  }
  return cur->next;
}

STWO::ListNode* STWO::LinkedList::getFirstNodePtr() {
  return first;
}

void STWO::LinkedList::addNode(int v) {
    ListNode* newLink = new ListNode(0); //initialize pointer with val as 0
    newLink->val = v;
    newLink->next = first;
    first = newLink; 
    //delete newLink;
}

void STWO::LinkedList::displayAll() {
    ListNode* cur = first; //from the first, or head of the list
    //cout << "current address / current data:  \n";
    cout << " current data:  \n";
    while (cur != nullptr) {
        //cout << cur << " " <<  cur->val << " " << endl;
        cout << cur->val << " " << endl;
        cur = cur->next; //point to the next pointer for accessing data in the next Node
    }
}

void T::Thrd::hello() {
    cout << "Hello! Thread" << endl;
}
/*
vector<int> S::Solution::distributeCandies(int candies, int num_people) {

}
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
S::TreeNode* S::Solution::pruneTree(TreeNode* root) {
    return nullptr;        
}

double S::Solution::champagneTower(int poured, int query_row, int query_glass) {
/*--------------------------------------
We stack glasses in a pyramid, where the first row has 1 glass, the second row has 2 glasses, and so on until the 100th row.  Each glass holds one cup of champagne.

Then, some champagne is poured into the first glass at the top.  When the topmost glass is full, any excess liquid poured will fall equally to the glass immediately to the left and right of it.  When those glasses become full, any excess champagne will fall equally to the left and right of those glasses, and so on.  (A glass at the bottom row has its excess champagne fall on the floor.)

For example, after one cup of champagne is poured, the top most glass is full.  After two cups of champagne are poured, the two glasses on the second row are half full.  After three cups of champagne are poured, those two cups become full - there are 3 full glasses total now.  After four cups of champagne are poured, the third row has the middle glass half full, and the two outside glasses are a quarter full, as pictured below.
-------------------------------------- */
    return 0.0;
}

int S::Solution::maxProfit(vector<int>& prices) {
/*-----------------------------------------------
    You are given an integer array prices where prices[i] is the price of a given stock on the ith day.
On each day, you may decide to buy and/or sell the stock. You can only hold at most one share of the stock at any time. However, you can buy it then immediately sell it on the same day.
Find and return the maximum profit you can achieve.
------------------------------------------------*/
    unsigned int prof = 0;
    for (auto it = prices.begin()+1; it != prices.end(); ++it) {
        // the profit is sum of postive difference of values between two consecutive days.
        if (*it - *(it-1) > 0) prof += (*it - *(it-1));
    }
    return prof;
}

int S::Solution::minimumDifference(vector<int>& nums) {
    return 1;
}

int S::Solution::mySqrt(int& x) {
    int nth = 2; //for square root
    //cout << nthX(10, 2.0) << endl;
    double rIni = 1;
    //cout << newtonRaphsonMethod(x, rIni, nth) << endl;
    double diff = 0;

    do {
        double rTmp = newtonRaphsonMethod(x, rIni, nth);
        diff = abs( rTmp  -  rIni );
        cout << "rIni: " << rIni << " rTmp: " << rTmp << " diff: " << diff << endl;
        rIni = rTmp;
    } while (diff>1);

    //cout << int(rIni) << int(2.6) << endl;
    return int(rIni);

/*
Given a non-negative integer x, return the square root of x rounded down to the nearest integer. The returned integer should be non-negative as well.

You must not use any built-in exponent function or operator.

For example, do not use pow(x, 0.5) in c++ or x ** 0.5 in python.
*/
}


double S::Solution::newtonRaphsonMethod(int& x, double& rG, int nth/*=2*/) {
    double rTmp = rG - ( nthX(nth, rG) - x ) / ( nth * nthX(nth-1, rG) );
    //cout << rG << ( nthX(nth, rG) - x ) / ( nth * nthX(nth-1, rG) ) <<  rTmp << endl;
    return rTmp;
}

double S::Solution::nthX(int nth, double x) {
    if (nth == 1) 
        return x;
    return x*nthX(nth-1, x);
}

int S::Solution::maxResult(vector<int>& nums, int k) {
    return nums.size();
}
int S::Solution::minimumHammingDistance(vector<int>& src, vector<int>& tgt, vector<vector<int>>& aSwaps /*allowed swap*/) {
    assert(src.size() == tgt.size());
    //cout << boolalpha <<  (src.size() == tgt.size()) << endl;
    cout << hammingDistance(src, tgt) << endl;
    iV = src;
    swapInt(iV[aSwaps[0][0]], iV[aSwaps[0][1]]);    
    getVecValue();
    
    //int minHD = 0;
    cout << aSwaps.size() << endl;
using namespace STREE;
    
    cout << aSwaps[0][0] << endl; 

    return 1;

/*
The idea is that allowedSwaps form one or more cycles. Elements within a cycle can be freely moved to any position.

A HashSet is a collection of items where every item is unique

Key Notes:

The detail of how it swaps does not matter
If we can swap [0, 1] and [1, 2], then we can rearrange [0, 1, 2] to everything we want.
Similar question: 1202. Smallest String With Swaps
Thus, union-find would be a good fit
Steps:
Union-find all connected indexes
Count elements for each union-find group (we use Map<Integer, Map<Integer, Integer>> here)
Scan the target, try to find the element in that union-find group greedily
if found: count - 1
if not: diff + 1
*/

/*
You are given two integer arrays, source and target, both of length n. You are also given an array allowedSwaps where each allowedSwaps[i] = [ai, bi] indicates that you are allowed to swap the elements at index ai and index bi (0-indexed) of array source. Note that you can swap elements at a specific pair of indices multiple times and in any order.

The Hamming distance of two arrays of the same length, source and target, is the number of positions where the elements are different. Formally, it is the number of indices i for 0 <= i <= n-1 where source[i] != target[i] (0-indexed).

Return the minimum Hamming distance of source and target after performing any amount of swap operations on array source.
*/
}

int S::Solution::hammingDistance(const std::vector<int>& a, const std::vector<int>& b) {
    int nDiff = 0;
    for (auto i = 0; i < int(a.size()); ++i) {
        if (a[i] != b[i])
                ++nDiff;
    }
    return nDiff;
}

void S::Solution::getVecValue() {
    for (auto i : iV) {
        cout << "value: " << i << endl;
    }
}

bool S::Solution::isIdealPermutation(vector<int>& nums) {
    int i = 0;
    while (  abs(i - nums[i]) <= 1  ) {
        cout << i << " " << nums[i] << endl;
        ++i;
        if (i == int(nums.size())) break;
    }
    cout << i << " " << nums.size() << endl;
    return i == int(nums.size());

/*
So the critical thing to understand here is that every local inversion is also, by definition, a global inversion. Any number that represents part of a global inversion, however, could represent more than one global inversion.

So then we should consider that the ideal version of A without any inversions would be one which is strictly increasing, which means that for all i, A[i] = i. Any deviation from this results in an inversion.

Also, the further A[i] deviates from i, the more global inversions are ultimately triggered. In fact, the only possible way for the number of global inversions to be equal to the number of local inversions is if each number has a maximum deviation from ideal of only 1, meaning that it represents only a single global inversion and a single local inversion.

Consider the two cases:

Case A) A number is more than one higher than the ideal; for example, i = 3, A[i] = 5.

When i is 3, that means we've seen 3 numbers already, yet there are 5 numbers that are less than 5. That then means that there are at least 2 numbers that are less than 5 that we have not yet seen, which in turn means that there are at least 2 global inversions triggered by this one deviation.

Case B) A number is more than one lower than the ideal; for example, i = 3, A[i] = 1.

When i is 3, that means we've seen 3 numbers already, yet only 1 number is less than 1. That then means that at least 2 of the numbers we've seen are higher than 1, which in turn means that we've already triggered at least 2 gobal inversions because of this one deviation.

Any move to offset these extra global inversions with additional local inversions would only trigger at least as many more global inversions.

So if we iterate through A and find any number that deviates more than 1 from its ideal, we can immediately return false. If we reach the end without triggering this, we can return true.
*/


    /* Time complexity is O(n^2), too slow
    unsigned int lInv = 0, GInv = 0;
    
    for (auto i=0; i < nums.size()-1; ++i) {
        for (auto j=i+1; j<nums.size(); ++j ) {
            if (nums[i] > nums[j]) {
                ++GInv;
                if (j == i+1)
                    ++lInv;
            }
        }
    }
    cout << "lInv: " << lInv << endl;
    cout << "GInv: " << GInv << endl;

    return (lInv == GInv);
    */
/*
You are given an integer array nums of length n which 
represents a permutation of all the integers in the range [0, n - 1].

The number of global inversions is the number of the different pairs (i, j) where:

0 <= i < j < n
nums[i] > nums[j]
The number of local inversions is the number of indices i where:

0 <= i < n - 1
nums[i] > nums[i + 1]
Return true if the number of global inversions is equal to the number of local inversions.
*/
}

int S::Solution::maximumScore(vector<int>& nums, int k) {
    int score = nums[k], i = k, j = k, mini = nums[k], sZ = nums.size();
    
    cout << i << " " << j << " " << sZ <<  endl;
    while ( i>0 || j < sZ-1) {
        if ( ( (i > 0) ? nums[i-1] : 0 ) > ( (j < sZ-1 ) ? nums[j+1] : 0 ) )
            mini = min(mini, nums[--i]); 
        else 
            mini = min(mini, nums[++j]);
        score = max(score, mini*(j-i+1));
    }
    return score;
    /*
i = j = k, the score = A[k]., A = nums
When increment the size of window, we want to reduce the min(A[i]..A[j]) slowly.

To do this, we can check the values on both sides of the window.
If A[i - 1] < A[j + 1], we do j = j + 1
If A[i - 1] >= A[j + 1], we do i = i - 1
    */



    /* Space complexity O(1), Time complexity O(k*(n-k)), too slow    
    std::vector<int>::iterator iB = nums.begin();

    int score = 0;
    for (int i=0; i <= k; ++i) {
        for (int j=nums.size()-1; j >= k; --j) {
            cout << "i " << i << ", j: " << j << endl;
            cout << "min between i and j: " << *std::min_element(iB+i, iB+j+1) << endl;
            cout << "j - i + 1: : " <<  (j - i + 1) << endl;
            int scTmp = (*std::min_element(iB+i, iB+j+1)) * (j - i + 1);
            cout << scTmp << endl;
            if ( scTmp > score) score = scTmp;
        }
    }
    cout << score << endl;
    return score;
    //cout << "max between i and j: " << *std::max_element(iB, iE) << endl; 
    */
        
    /*
    int pd = 0;
    int idL = 0;
    int idR = nums.size()-1;
    for (std::vector<int>::iterator  itL=iB; itL <= iB+k; ++itL) {
        for (std::vector<int>::iterator itR = iE-1; itR >= iE-k; --itR) {
            cout << "idL " << idL << ", idR: " << idR << endl;        
            cout << "max between i and j: " << *std::max_element(itL, itR) << endl;
            cout << "j - i + 1: : " <<  (idR - idL + 1) << endl;
            int pdTmp = (*std::max_element(itL, itR)) * (idR - idL + 1);
            if ( pdTmp > pd) pd = pdTmp;
            --idR;
        } 
        ++idL;
    }
    */
/*
You are given an array of integers nums (0-indexed) and an integer k.

The score of a subarray (i, j) is defined as min(nums[i], nums[i+1], ..., nums[j]) * (j - i + 1). A good subarray is a subarray where i <= k <= j.

Return the maximum possible score of a good subarray.

Example 1:

Input: nums = [1,4,3,7,4,5], k = 3
Output: 15
Explanation: The optimal subarray is (1, 5) with a score of min(4,3,7,4,5) * (5-1+1) = 3 * 5 = 15.

Example 2:
Input: nums = [5,5,4,5,4,1,1,1], k = 0
Output: 20
Explanation: The optimal subarray is (0, 4) with a score of min(5,5,4,5,4) * (4-0+1) = 4 * 5 = 20.
*/
}

int S::Solution::scoreOfParentheses(string& s) {

    stack<int> p;
    std::string::iterator itB = s.begin();
    std::string::iterator itE = s.end();
    int score = 0;

    for (std::string::iterator it = itB; it < itE; ++it) {
        switch (*it) {
            case '(':
                p.push(score);
                score = 0;
                break;
            case ')':
                score = p.top() + max(2*score, 1);
                p.pop();
                break;
        }
    }    
    return score;
    /*
    std::string::iterator itB = s.begin();
    std::string::iterator itE = s.end();

    cout << std::count(itB, itE, '(') << endl;
    cout << std::count(itB, itE, ')') << endl;


    int nPair = 0;
    int lC = 0;
    int rC = 0;
    for (std::string::iterator it = itB; it < itE; ++it) {
        switch (*it) {
            case '(': ++lC; break;
            case ')': ++rC; break;
        }
        int cc = 0
        while (lC>0 && rC>0) {
            nCC = pow(2, cc);
            --lC;
            --rC;
            ++cc;
        }
        nPair = nPair + nCC;
    }
    return  nPair;//std::min(std::count(itB, itE, '('), std::count(itB, itE, ')') );
    */
}

bool S::Solution::hasAllCodes(std::string& s, int& k) { //time out in leetcode, too slow
    if (int(s.size()) < k) return false;

    int r = s.size() % k;
    size_t const sizeSub = s.size() / k;
    cout << "remainder " << r << endl;
    cout << "quotient " << sizeSub << endl;

    int maxInt = pow(2, k);

    //std::vector<char> sCV(s.begin(), s.end());
    //std::vector<char>::iterator it = sCV.begin();
    //sCV.erase(it+2);
    
    //for (vector<char>::iterator it=sCV.begin(); it < sCV.end() ; it = it+k ) {
    //    cout << *it << " " << endl;
    //}

    
    int cFd = 0; 
    for (auto tgt = 0; tgt < maxInt ; ++tgt) {
        for (auto i = 0; i < int(s.size())-k+1 ; ++i ) {
            cout << "i: " << s[i] << s[i+1] << endl;
            if (tgt == biToInt(s, k, i)) {
                cout << "found: " << biToInt(s, k, i) << endl;
                ++cFd;
                if (cFd == maxInt) return true;
            }
        //    cout << "\n";
        }
    }
    
    cout << "cFd: " << cFd << endl;
     
    return false;
}

int S::Solution::biToInt(vector<char>::iterator& i, vector<char>::iterator& e) {
    //for (vector<char>::iterator& it=i; it < e ; ++it) {
    //    cout << *it << endl; 
    //}
    return 1;
}

int S::Solution::biToInt(std::string& s, int& k, int& ini) {
    int tmp = 0;
    int pwr = k-1;
    for (auto i = ini; i < ini+k; ++i) {
        std::string stTmp(1, s[i]);
        int numTmp = stoi(stTmp);
        /*
        cout << "s["<< i << "]: " << numTmp << ", " << " 2**"\
             << pwr << ": " << pow(2, pwr) << endl;
        */
        tmp = tmp + (numTmp * pow(2, pwr));
        //cout << "tmp: " << tmp << endl;
        --pwr;
    }
    cout << "tmp: " << tmp << "\n";


    return tmp; 
}


int S::Solution::getLastMoment(int n, vector<int>& lt, vector<int>& rt) {
    //std::deque<int> lt(left.begin(), left.end());
    //std::deque<int> rt(right.begin(), right.end());
    
    int ltmax = (lt.empty()) ? 0 : *std::max_element(lt.begin(), lt.end());
    int rtmin = (rt.empty()) ? n : *std::min_element(rt.begin(), rt.end());
    cout << std::max(ltmax, n - rtmin) << endl;
    return std::max(ltmax, n - rtmin);
/*
 Plank
 0-------n
 - a wooden plank of the length n units. 
 - Some ants are walking on the plank, each ant moves with a speed of 1 unit per second. 
 - Some of the ants move to the left, the other move to the right.
 - When two ants moving in two different directions meet at some point, they change their directions and continue moving again. Assume changing directions does not take any additional time.

 - When an ant reaches one end of the plank at a time t, it falls out of the plank immediately.

Given an integer n and two integer arrays left and right, the positions of the ants moving to the left and the right, return the moment when the last ant(s) fall out of the plank.
*/
}
int S::Solution::matchPlayersAndTrainers(vector<int>& plys, vector<int>& trns) {
    /*
    sort(plys.begin(), plys.end());
    sort(trns.begin(), trns.end());
    for (auto i : plys) {
        cout << i << " ";
    }
    cout << "\n";
    for (auto i : trns) {
        cout << i << " ";
    }
    cout << "\n";
    
    
    int nPlys = plys.size();
    int nTrns = trns.size();
    int i = nPlys-1;
    int j = nTrns-1;

    int cnt = 0;
    while (cnt <= std::min(nPlys, nTrns) && i>=0 && j>=0 ) {
        cout << i << ", " << j << ", " << cnt << endl;
        cout << plys[i] << ", " << trns[j] << endl;
        if (trns[j] >= plys[i]) {
            ++cnt;
            --j;
            --i;
        }
        else if (trns[j] < plys[i]) {
            --i;
        }
    }
    cout << "cnt: " << cnt <<  "\n";
    */ 
    /*
    In a priority queue, you push data in the front in random order, but when you pop the data off the other end, you always pop the largest item stored: the priority queue automatically sorts the data for you.
    syntax of min heap in a priority_queue
    priority_queue <int, vector<int>, greater<int>> gq;
    */

    // trainers until we find a trainer capacity>=player,
    //if found res increased by one pop that trainer cause one player one trainer.
    priority_queue< int,vector<int>,greater<int> >p(plys.begin(),plys.end());
    priority_queue< int,vector<int>,greater<int> >q(trns.begin(),trns.end());
    int cnt=0;
    while(!p.empty() && !q.empty()){
        if(p.top()>q.top())q.pop();
        else if(p.top()<=q.top()){
            cnt++;
            p.pop();
            q.pop();
        }
    }
    cout << "cnt: " << cnt <<  "\n";
    return cnt;
/*
You are given a 0-indexed integer array players, where players[i] represents the ability of the ith player. 
You are also given a 0-indexed integer array trainers, where trainers[j] represents the training capacity of the jth trainer.

The ith player can match with the jth trainer if the player's ability is less than or equal to the trainer's training capacity. 
Additionally, the ith player can be matched with at most one trainer, and the jth trainer can be matched with at most one player.

Return the maximum number of matchings between players and trainers that satisfy these conditions.
*/
}

void S::Solution::sortBasedPst(vector<int>& pst, vector<int>& spd) {
    for (auto i = 0; i < int(pst.size()); ++i) {
        for (auto j = i; j < int(pst.size()); ++j ) {
            if (pst[i] < pst[j]) {
                swapInt(pst[i], pst[j]);
                swapInt(spd[i], spd[j]);
            }
        }
    }
}

static bool mycmp(pair<int,int> a,pair<int,int> b) {
    return a.first>b.first;
}


int S::Solution::carFleet(int tgt, vector<int>& pst, vector<int>& spd) {
    
    vector<pair<int,int>> car;
    for(int i = 0; i < int(pst.size()); i++) {
        car.push_back(make_pair(pst[i],spd[i]));
    }
    sort(car.begin(),car.end(),mycmp);

    float time = (float)(tgt - car[0].first)/car[0].second;
    int ans=1;
    for(int i = 1; i < int(car.size()); i++) {
        float tempTime = (float)(tgt - car[i].first)/car[i].second;
        if(tempTime>time){
            ans++;
            time = tempTime;
        }
    }
    return ans;
    
    
/*
There are n cars going to the same destination along a one-lane road. 
The destination is target miles away.
You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).

A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. 
The faster car will slow down to match the slower car's speed. 
The distance between these two cars is ignored (i.e., they are assumed to have the same position).

A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.

If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.

Return the number of car fleets that will arrive at the destination.
 */
}

S::ListNode* S::LinkedList::findNode(int v, LinkedList iL) {
    ListNode* nTemp = first;
    
    while (nTemp != nullptr) {
        //cout << "nTemp->val:  " << nTemp->val << " " << endl;
        if (nTemp->val == v) {
            cout << "Pointer with value " << nTemp->val << " is found!" << endl;
            return nTemp;
        }
        nTemp = nTemp->nxt;
    }
    return nullptr;
}

void S::LinkedList::deleteNode(ListNode* node) {
    ListNode* p = node->nxt;
    cout << "deleting node at " << node << endl;
    while (p != nullptr /*the next node to "node" is not null */) {
        if (p->nxt == nullptr) { /*the second next node is the last node of the linked list*/
            node->val = p->val;
            node->nxt = nullptr; //place nullptr at node nxt pointer as a show stopper
            p = nullptr; //to end while loop
        } 
        else {
            //cout << "node: " << node << "  p: " << p << endl;
            node->val = p->val;     //replace the value of node with the value of p 
            //existing p move downward for next loop
            node = p;               //address of node is replace with p
            p = p->nxt;             //existing p move downward for next loop
            //cout << "node: " << node << "  p: " << p << endl;

        }
    }
    /* This is a solution when the head "first" of linkedlist is known
    cout << "node->val: " << node->val << endl;   
    ListNode* temp = first;
    cout << "first->val: " << first->val << "\n";
    while (temp != nullptr) { 
        cout << "temp->val: " << temp->val << endl;
        if (temp->nxt == node) {
            cout << "node found, temp->nxt->val:" << temp->nxt->val << endl;
            temp->nxt = node->nxt; //skip pointer "node" and point to node->nxt
            cout << "After removing node, temp->nxt->val " << temp->nxt->val << endl;
            break;
        }
        temp = temp->nxt;
    }
    cout << "No node is found\n";
    */
}

void S::LinkedList::addNode(int v) {
    ListNode* newLink = new ListNode(0); //initialize pointer with val as 0
    newLink->val = v;
    newLink->nxt = first;
    first = newLink; 
    //delete newLink;
}

void S::LinkedList::displayAll() {
    ListNode* cur = first; //from the first, or head of the list
    //cout << "current address / current data:  \n";
    cout << " current data:  \n";
    while (cur != nullptr) {
        //cout << cur << " " <<  cur->val << " " << endl;
        cout << cur->val << " " << endl;
        cur = cur->nxt; //point to the next pointer for accessing data in the next Node
    }
}

std::vector<std::vector<int>> S::Solution::onesMinusZeros(std::vector<std::vector<int>>& grid) {
    int m = grid.size();        //num of rows
    int n = grid[0].size();     //num of cols
    //cout << m << endl;        
    //cout << n << endl;  
        
    std::vector<int> rowSum(m);
    std::vector<int> colSum(n);

    std::vector<std::vector<int>>  diff(m, std::vector<int> (n, 0));
    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << grid[i][j] << " " << (grid[i][j] / 1) << " " << (grid[i][j] / 1 -1) << " " << endl;
            rowSum[i] +=  (grid[i][j] / 1) + (grid[i][j] / 1 -1); 
            cout << "i = " << i << " j = " << j << " rowSum[i] " << rowSum[i] << endl; 
        }
    }        
        
    for (int j = 0; j < n; ++j) {
        for (int i = 0; i < m; ++i) {
            colSum[j] += (grid[i][j] / 1) + (grid[i][j] / 1 -1);
        }
    }       

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            diff[i][j] = rowSum[i] + colSum[j];       
        }
    }
        /* Space complexity n*m, time complexity (n*m)^(n*m)
        std::vector<std::vector<int>>  diff(m, std::vector<int> (n));
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                int oRowi = 0;
                for (auto& it : grid[i]) {
                    oRowi += it;
                }
                int zRowi = grid[i].size() - oRowi;
                
                int oColj = 0;
                for (auto it=0; it < grid.size(); it++){
                    oColj += grid[it][j];
                }
                int zColj = grid.size() - oColj;
                
                diff [i][j] = oRowi + oColj - zRowi - zColj;
                //diff[i][j] = onesRowi(grid, i) + onesColj(grid, j) ;
                //cout << onesColj(grid, j) << endl;
            }
        }
        */
    return diff;
}

int S::Solution::onesRowi(std::vector<std::vector<int>>& g, const int& i) {
    int sumOnes = 0;
    for (auto& it : g[i]) {
        sumOnes += it;
    }
    int sumZeros = g[i].size() - sumOnes;
    return sumOnes - sumZeros; //This is equal to ones minus zeros in a row
}
int S::Solution::onesColj(std::vector<std::vector<int>>& g, const int& j) {
    int sumOnes = 0;
    for (auto it = 0; it < int(g.size()); it++){
        sumOnes += g[it][j];
    }
    int sumZeros = g.size() - sumOnes;
    return sumOnes - sumZeros;
}

int S::Solution::getWinner(std::vector<int>& arr, int k) {
    int cWin = 0;
    for (auto i = 1; i < int(arr.size()); ++i) {
        if (arr[i] > arr[0]) {
            arr[0] = arr[i]; // ith element arr[i]>arr[0] replace arr[0], the value of replaced arr[0] is gone and not used in the loop 
            cWin = 0;   //the consercutive count of winning is reset here.
        }
        if (++cWin == k) break;
    }

    return arr[0];

 /*This is too slow and fails in leetcode        
        //for (auto& i: arr) cout << i <<" ";
        //cout << "\n\n";
        
        unsigned int wCnt = 0;
        //for (auto i = 1; i < arr.size(); ++i ) {
        int tmp0 = arr[0];
        int tmp1 = arr[1];
        while (tmp0 != tmp1) {
            //cout << tmp0 << " " << tmp1 << endl;    
            if (arr[0] < arr[1]) {
                cout << " " << arr[0] << " <  " << arr[1] << endl; 
                swapInt(arr[0], arr[1]);   
                wCnt = 0;
            }
            //cout << tmp0 << " " << arr[0] << " " << wCnt << " " << endl;
            if (tmp0 == arr[0] and wCnt == k-1) {
                cout << "winner number is " << arr[0] << endl;
                return arr[0];
            }
            ++wCnt; 
            //updating first two elements
            
            //for (auto& i: arr) cout << i <<" ";
            //    cout << "\n\n";
            for (auto i = 1; i < arr.size()-1; ++i ) {
                swapInt(arr[i],arr[i+1]);
            //    for (auto& i: arr) cout << i <<" ";
            //    cout << "\n";
            }
            tmp0 = arr[0];
            tmp1 = arr[1];
            for (auto& i: arr) cout << i <<" ";
                cout << "\n\n";
        }
        return 0;
*/
/*
Given an integer array arr of distinct integers and an integer k.

A game will be played between the first two elements of the array (i.e. arr[0] and arr[1]).
In each round of the game, we compare arr[0] with arr[1], the larger integer wins and remains at position 0, 
and the smaller integer moves to the end of the array. The game ends when an integer wins k consecutive rounds.

Return the integer which will win the game.


It is guaranteed that there will be a winner of the game.

Output: 5
Explanation: Let's see the rounds of the game:
Round |       arr       | winner | win_count
  1   | [2,1,3,5,4,6,7] | 2      | 1
  2   | [2,3,5,4,6,7,1] | 3      | 1
  3   | [3,5,4,6,7,1,2] | 5      | 1
  4   | [5,4,6,7,1,2,3] | 5      | 2
So we can see that 4 rounds will be played and 5 is the winner because it wins 2 consecutive games.
*/
    //return -1;
}

int S::Solution::reverse(int& x) {
//Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.
   
    int n=-2147483648;
    int p=2147483647; 
    long r = 0;
    
    while (x) {
        //cout << "r: " << r << "x: " << x << endl;
        r = r*10 + x%10;    //taking each digit from the lowest
        x = x/10;           //update x, using quotient of divison by 10, for the slicing next digit
    }    
    //if (r > INT_MAX || r < INT_MIN) return x;
    if (r > p || r < n) return 0;
    
    
    /*
    unsigned int xD= numDigit(abs(x));
    cout << "Number of digit of " << x << " : " << xD << endl;

    int32_t xtmp = 0;
    int dig = 0;
    //cout << mid << endl;
    for (auto j=0; j < xD; ++j) {
        dig = xD - j;
        //cout << " " << slicing(abs(x), dig) << " " << endl;
        xtmp = xtmp + slicing(abs(x), dig) * int(pow(10, j));
    }
    cout << x << endl;
    xtmp = (x>0) ? xtmp : -1*xtmp ;
    */
    cout << "reversed: " << r << "\n" << endl;
    
    return r;
}

int S::Solution::numDigit(const int& x) {
    return floor(log10(x)) + 1;
}

int S::Solution::slicing(const int& x, const int& dig) {
    return int(floor(x/pow(10,dig-1)) - floor(x/pow(10,dig))*10) ;
}

std::string S::Solution::reverseVowelOfAString(std::string s) {
    //accepted
    setValue(s); //sC = s
    //for (auto it=s.begin(); it!=s.end(); ++it)
    //    	cout << *it << " vowel contained: " << containVowel(*it) << "\n";

    int i = 0;
    int j = sC.length()-1;
    while (i < j) {
        while (!containVowel(sC[i]) && i < j) {
            // cout << "Not containVowel: " << sC[i] << " i increment: " << ++i << endl;            
            ++i;
        }
        
        while (!containVowel(sC[j]) && i < j) {
            //cout << "Not containVowel: " << sC[j] << " j reduction: " << --j << endl;
            --j;

        }
        
        if ( i < j && containVowel(sC[i]) && containVowel(sC[j]) ) {
                cout << "swap at i=" << i << ", j=" << j << endl;
                swap(i,j);
                ++i;
                --j;
        }
        cout << "i, j for next run :" <<  i << j << endl;
                        
    }
    return "test"; 
}

bool S::Solution::containVowel(char& stmp) {
    //cout << "letter: " << stmp << endl;
    switch(stmp) {
        case 'a': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'e': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'i': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'o': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'u': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'A': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'E': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'I': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'O': /*cout<<" found: "<< stmp << endl;*/ return true; break;
        case 'U': /*cout<<" found: "<< stmp << endl;*/ return true; break;
    }
    return false;
}

void S::Solution::swapInt(int& i, int& j) {
    //cout << i << " " << j << endl;
    int tmp = i;
    i = j;
    j = tmp;
}

void S::Solution::swap(int& i, int& j) {
    char tmp = sC[i];
    sC[i] = sC[j];
    sC[j] = tmp;
}

void S::Solution::swap(char* a, char* b) {
    cout << "before: " << a << b << endl;
    char* tmp = a;
    a = b;
    b = tmp;
    cout << "after: " << a << b << endl;
}

void S::Solution::swap(char& a, char& b) {
    cout << "before: " << a << b << endl;
    char tmp = a;
    a = b;
    b = tmp;
    cout << "after: " << a << b << endl;
}

bool S::Solution::containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff/*k*/, int valueDiff/*t*/) {
    // Unordered maps are associative containers that store elements formed by the combination of a key value and a mapped value, and which allows for fast retrieval of individual elements based on their keys.

    int n = nums.size();
        
    if(n == 0 || indexDiff < 0  || valueDiff < 0) return false;
        
    unordered_map<int,int> buckets; // the key value, bucket, and the mapped value, num[i]

    for(int i=0; i<n; ++i) {
        int bucket = nums[i] / ((long)valueDiff + 1);
            
        cout << bucket << " " << nums[i] << " " <<  "\n";
        cout << buckets.bucket_count() << endl;
		// For negative numbers, we need to decrement bucket by 1
		// to ensure floor division.
		// For example, -1/2 = 0 but -1 should be put in Bucket[-1].
		// Therefore, decrement by 1.
        if(nums[i] < 0) --bucket;

        if(buckets.find(bucket) != buckets.end()) { //see if find any key mathcing value of "bucket", if not finding the key, (buckets.find(bucket) returns the iterator as buckets.end()
            for (unsigned i=0; i<buckets.bucket_count(); ++i) {
                std::cout << "bucket #" << i << " contains: ";
                for (auto it = buckets.begin(i); it!=buckets.end(i); ++it) {
                    std::cout << "[" << it->first << ":" << it->second << "] ";
                    std::cout << "\n";
                }
            }
            return true;
        }
        else {
            buckets[bucket] = nums[i]; //assign nums[i] to a key value of bucket
            for (unsigned i=0; i<buckets.bucket_count(); ++i) {
                std::cout << "bucket #" << i << " contains: ";
                for (auto it = buckets.begin(i); it!=buckets.end(i); ++it) {
                    std::cout << "[" << it->first << ":" << it->second << "] ";
                    std::cout << "\n";
                }
            }
            if(buckets.find(bucket-1) != buckets.end() && (long) nums[i] - buckets[bucket-1] <= valueDiff) return true;
            if(buckets.find(bucket+1) != buckets.end() && (long) buckets[bucket+1] - nums[i] <= valueDiff) return true;
                
            if(int(buckets.size()) > indexDiff) {
                int key_to_remove = nums[i-indexDiff] / ((long)valueDiff + 1);
                if(nums[i-indexDiff] < 0) --key_to_remove;
                buckets.erase(key_to_remove);
            }
        }
    }
    return false;
    
    /*
    if (nums.size() < indexDiff+1) {
            cout << "max value of indexDiff+1 > vector size\n";
            indexDiff = nums.size() - 1; //max value of indexDiff <= nums.size()-1
    }

    for (auto i=0; i<(nums.size()-indexDiff); ++i) {
         int j = i + indexDiff; //abs(i-j) <=indexDiff
        while (i < j) { // abs(i-j) <=indexDiff
            cout << " nums[i]: " << nums[i] << ", nums[j]: " << nums[j] << ", valueDiff: " <<  valueDiff << endl;
            if ( abs( nums[i] -  nums[j] ) <=  valueDiff )  {
                cout << "duplicate is found at i=" << i << " j=" << j << endl;
             return true; //duplicate is found.
            }
            if (j >= nums.size()-1 ) //j hit the last index of nums, update indexDiff
                indexDiff -= 1;
            --j;
        }
    }
    cout << "no duplicate is found.\n";
    return false; //no duplicate is found
    */
/*
i != j,
abs(i - j) <= indexDiff.
abs(nums[i] - nums[j]) <= valueDiff, and
Input: nums = [1,2,3,1], indexDiff = 3, valueDiff = 0
Output: true
Explanation: We can choose (i, j) = (0, 3).
We satisfy the three conditions:
i != j --> 0 != 3
abs(i - j) <= indexDiff --> abs(0 - 3) <= 3
abs(nums[i] - nums[j]) <= valueDiff --> abs(1 - 1) <= 0
*/ 
    
}

void S::Solution::setValue(std::string& s) {
    sC = s;
}

void S::Solution::getValue() {
    cout << "s:" << sC << endl;
}

int S::Solution::uniquePathsIII(vector<vector<int>>& grid) {
/*
1 representing the starting square. There is exactly one starting square.
2 representing the ending square. There is exactly one ending square.
0 representing empty squares we can walk over.
-1 representing obstacles that we cannot walk over.
*/
  int nR = grid.size();
  int nC = grid[0].size();
  printf("%d, %d\n", nR, nC);
  
  int empty = 0;
  pair<int, int> src, dest;

  for (auto i=0; i<nR; ++i) {
    for (auto j=0; j<nC; ++j) {
      if (grid[i][j] == 0) {
        ++empty;
      }
      if (grid[i][j] == 1) {
        src = {i, j};
      }
      if (grid[i][j] == 2) {
        dest = {i, j};
      }
    }
  }

  printf("Empty = %d\n", empty);
  printf("src = (%d,%d)\n", src.first, src.second);
  printf("dest = (%d,%d)\n", dest.first, dest.second);

  //int i = 0;
  //int j = 0;
  //printf("Valid: %d\n", isValid(i,j,nR,nC));

  return dfs(src.first,src.second, empty, dest, grid, nR, nC);

}

bool S::Solution::isValid(int& i,int& j,int& m,int& n) {
  return (i>=0 and j>=0 and i<m and j<n);
}

int S::Solution::dfs(int i, int j, int left, \
                     pair<int, int> dest, vector<vector<int>>& grid, \
                     int& m, int&n) {
  
  if ((left == -1) and (pair<int,int>(i,j)==dest)) {
    return 1;
  }

  vector<int> di = {-1,1,0,0};
  vector<int> dj = {0,0,-1,1};

  grid[i][j]=-1; // visited
  int ans = 0;
  
  for (auto k=0; k<4; ++k) {
    int x = i + di[k];
    int y = j + dj[k];
    if (isValid(x,y,m,n) and grid[x][y]!=-1) {
      ans+=dfs(x,y,left-1,dest,grid,m,n);
    }
  }

  grid[i][j]=0;
  return ans;

}

bool S::Solution::compareNums(const int& ix, const int& iy) {
  return true;
}

vector<int> S::Solution::numberGame(vector<int>& nums) {
  if (nums.size() % 2 != 0 /*odd number of elements*/) {
    return vector<int> {-1};
  }

  sort(nums.begin(),nums.end()); // asending order
  vector<int> arr = {};

  for (unsigned int i=0; i<nums.size(); i+=2) {
    arr.push_back(nums[i+1]);
    arr.push_back(nums[i]);
    cout << nums[i] << " " <<  i << "\n";
  }

  //return vector<int>{0};
  return arr;
}

int S::Solution::numSubarrayProductLessThanK(vector<int>& v, int& k) {
    
  int result = 0, left = 0, right = 0, ansTmp = 1;
  int vSize = v.size();
  while (right < vSize) {
    ansTmp *= v[right];
    while (ansTmp >= k) ansTmp /= v[left++];
    // 1 below is for v[right]
    // (right - left) is for # of subarrays ending at v[...right-1]
    result += ( (right - left) + 1 ); 
    ++right;
  }
  return result;
  /*  
  int result = 0;
  for (unsigned int i=0; i<v.size(); ++i) {
    unsigned int ansTmp = 1;
    for (unsigned int j=i; j < v.size(); ++j) {
      ansTmp *= v[j];
      if (ansTmp >= static_cast<unsigned int>(k)) {
        break;
      }            
      result += 1;
    } 
  }    
  return result;
  */
}

unsigned long long S::Solution::Fibo(int n) {
  if (n <= 2) {
    return 1;
  } 
  else {
    return Fibo(n-2) + Fibo(n-1);
  }
}

// n x n 2D matrix representing an image, 
// rotate the image by 90 degrees (clockwise).
// in-place, which means you have to modify the input 
// 2D matrix directly. DO NOT allocate another 2D matrix and do the rotation.
void S::Solution::rotateCW(vector<vector<int>>& m) {
  int m_size = m.size();
  for (auto i=0; i<m_size; ++i) {
    for (auto j=i; j<m_size; ++j) {
      std::swap(m[i][j], m[j][i]);
    }
  }
  int mid = int(floor(double(m_size-1)/2));
  //cout << "m = " << mid << endl;
  
  for (auto j = 0; j <= mid; ++j ) {
    for (auto i = 0; i<m_size; ++i) {
      std::swap(m[i][j], m[i][m_size-1-j]);
    }
  }
}

void S::Solution::rotateCCW(vector<vector<int>>& m) {
  int m_size = m.size();
  int mid = int(floor(double(m_size-1)/2));
  
  for (auto j = 0; j <= mid; ++j ) {
    for (auto i = 0; i<m_size; ++i) {
      std::swap(m[i][j], m[i][m_size-1-j]);
    }
  }
  
  for (auto i=0; i<m_size; ++i) {
    for (auto j=i; j<m_size; ++j) {
      std::swap(m[i][j], m[j][i]);
    }
  }
}


void S::Solution::print2Dvector(vector<vector<int>>& m){
  
  for (auto ix=m.begin(); ix<m.end(); ++ix) {
    for (auto num: *ix) {
      cout << "|" << num;
    } 
    cout << "|\n";
  }
  /*
  for (unsigned int i=0; i<m.size(); ++i) {
    for (unsigned int j=0; j<m[0].size(); ++j) {
      printf("m(i=%d,j=%d)=%d\n", i, j, m[i][j]);
    }
  }
  */
}

// Given an integer n, return the number 
// of prime numbers that are strictly less than n
int S::Solution::countPrimes(int n) {
  if (n<=1) { // necessary condition
    return 0; // a prime number is a natural number greater than 1
  }
  // Any composite number can be expressed as the product of two factors, both of which must be less than or equal to its square root.
  // Sieve of Eratosthenes
  vector<bool> nPrime(n+1, true); // set all default as prime 
  nPrime[0] = false;
  nPrime[1] = false;
  nPrime[n] = false; // strictly less than n
  int sqN = int(sqrt(n));
  for (auto i=2; i<sqN+1; ++i) {
    if (nPrime[i]==true) {
      //cout << "Prime: " << i << endl;
      int j = 2*i;
      while (j < n) {
        nPrime[j] = false;
        j+=i;
      }
    }

  }
  
  // count prime number
  int count = 0;
  for (unsigned int i=0; i < nPrime.size(); ++i) {
    if (nPrime[i] == true) {
      cout << "i = " << i << endl;
      ++count;
    }
  }

  return count;
} 

bool S::Solution::isPrime(int& n) {
  // Primality Tests rules
  // divisibility by 2 (even numbers are not prime Except for 2).
  // If the number is odd, check for divisibility by 3, then 5, and so on, only considering prime numbers less than the square root of the number being tested.
  if (n <= 3) {
    return n>1;    // return true for 2 and 3
  }
  else if (n%2==0 || n%3==0) {
    return false;  // multiple of 2 and 3 except 2 and 3
  }
  // 6k + 1 rule
  int limit = int(sqrt(n));
  for (auto k = 5; k<(limit+1); k+=6) {
    if (n%k==0 || n%(k+2)==0) {
      return false;
    } 
  }

  return true;
}


// using the opposite directional two-pointer approach
void S::Solution::reverseString(vector<char>& s) {
  for (auto i=0; i<int(floor(double(s.size()))/2); ++i)
    std::swap(*(s.begin()+i), *(s.end()-1-i));
}

void S::Solution::print1Dvector(vector<char>& s) {
  for (auto it=s.begin(); it<s.end(); ++it) {
    cout <<  *it << " ";
  }
  cout << "\n";
}


void STREE::Tree::printTree(STREE::TreeNode* node) {
   if (node->left!=nullptr and node->right!=nullptr) {
     printf("   %d   \n", node->val);
     printf("  / \\  \n");
     printTree(node->left);
     printTree(node->right);
   }
   
   if (node->left==nullptr and node->right==nullptr) {
     printf("   %d    \n", node->val);
     printf("  / \\   \n");
     printf(" NIL NIL \n");
     return;
   }
}

int STREE::Tree::maxDepth(STREE::TreeNode* root) {
  if (root==nullptr)
    return 0;
  
  int dL = maxDepth(root->left); 
  int dR = maxDepth(root->right);
 
  return std::max(dL, dR)+1;
  /*
  if (root==nullptr)
    return 0;
  
  if (root->left==nullptr and root->right==nullptr)
    return 1;
  
  int dL=0; // depth count of left subtree 
  int dR=0; // depth count of right subtree
  if (root->left != nullptr)
    dL += maxDepth(root->left);
  if (root->right != nullptr)
    dR += maxDepth(root->right);
 
  if (dL > dR)
    return dL+1;
  return dR+1;
  */
}

void S::Solution::merge(vector<int>& nums1, int m, \
                        vector<int>& nums2, int n) {
  if (n==0)
    return;
  if (m==0) {
    nums1.clear();
    nums1.insert(nums1.end(),nums2.begin(),nums2.end());
  }

  int i = 0;
  for (auto j=0;j<n;++j){
    while (nums2[j]>=nums1[i] and i<m+j) {
      ++i;
      //cout << "i " << i <<  " j " << j << "\n"; 
      //cout << "nums1[i] " << nums1[i] <<  " nums[j] " << nums2[j] << "\n"; 
    }
    nums1.insert(nums1.begin()+i,nums2[j]);
    nums1.pop_back();
    //nums1[m+j] = nums2[j];
    //std::swap(nums1[i],nums1[m+j]);
    
    //cout << "i " << i <<  " j " << j << "\n"; 
    //print1Dvector(nums1);
  }
  for (auto j=n-1;j>=0;--j){
    
  }

}

void S::Solution::print1Dvector(vector<int>& v) {
  for (auto it=v.begin(); it<v.end(); ++it) {
    cout <<  *it << " ";
  }
  cout << "\n";
}

// Given an integer array nums, find the subarray 
// with the largest sum, and return its sum.
int S::Solution::maxSubArray(vector<int>& nums) {
  // O(n) 
  typedef unsigned int uint;
  uint nSize = nums.size();
  vector<int> maxSum(nSize,0);
  maxSum[0]=nums[0];
  //uint i=0; //tracking start index
  //uint k;   //tracking end index

  for (uint j=1; j<nSize; ++j) {
    // find max at j between maxSum[0;j]+nums[j] and nums[j]
    // this ensure nums[j] makes maxSum at j larger than maxSum[j-1]
    maxSum[j]=std::max(maxSum[j-1]+nums[j],nums[j]);
    /*if (maxSum[j]==nums[j])
      i=j;
    if (maxSum[j]<maxSum[j-1])
      k=j;*/
  }
  /*
  vector<int> tmp(nums.begin()+i,nums.begin()+k);
  print1Dvector(tmp);
  */

  return *max_element(maxSum.begin(), maxSum.end());
  
  /* O(n^2) solution -> very inefficient
  if (nums.size()==1)
    return nums[0];

  typedef unsigned int uint;
  uint nSize = nums.size();
  vector<int> maxSumPerSize(nSize,0);
  int maxTemp;
  
  for (uint i=1; i<nSize+1; ++i) {
    for (uint j=0; j<nSize+1-i;++j) {
      if (j==0)
        maxTemp = reduce(nums.begin()+j,nums.begin()+j+i);
      
      if (reduce(nums.begin()+j,nums.begin()+j+i,0)>maxTemp)
        maxTemp = reduce(nums.begin()+j,nums.begin()+j+i,0);

    }
    
    maxSumPerSize[i-1]=maxTemp;
  }

  //print1Dvector(maxSumPerSize);

  return *max_element(maxSumPerSize.begin(),maxSumPerSize.end());
  */
}

int S::Solution::hammingWeight(int n) {
  if (n/2 == 0) {
    return n%2;
  }
  //int q = n/2; // quotient
  //int r = n%2; // remainder
  //cout << q << " "  << r << endl;
  return n%2 + hammingWeight(n/2);
}

int S::Solution::romanToInt(string s) {
/*
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
*/
  //map<string, int> mpSI;
  //mpSI["I"] = 1;  mpSI["V"] = 5;   mpSI["X"] = 10;
  //mpSI["L"] = 50; mpSI["C"] = 100; mpSI["D"] = 500;
  //mpSI["M"] = 1000;
   
  unordered_map<char, int> mpSI = {
    {'I', 1},
    {'V', 5},
    {'X', 10},
    {'L', 50},
    {'C', 100},
    {'D', 500},
    {'M', 1000}
  };

  int sum=0;
  for (auto is=s.begin(); is<s.end(); ++is) {
    char cur = *is;
    char nxt = *(is+1);
    //string cur; cur += *is;
    //string nxt; nxt += *(is+1);
    /*
    cout << mpSI[cur] << endl;
    cout << mpSI[nxt] << endl;
    cout << boolalpha << (mpSI[cur] > mpSI[nxt]) << endl;
    cout << (is+1 == s.end()) << endl;
    */
    
    if (is+1 == s.end()) {
      sum+=mpSI[cur];
      break;
    }

    sum = (mpSI[cur] >= mpSI[nxt]) ? \
          sum+mpSI[cur] : sum-mpSI[cur];
  }
  
  return sum; //s.size();
}

vector<int> SHUFFLE::Sol::reset() {
  return _nums;
}

vector<int> SHUFFLE::Sol::shuffle() {
  vector<int> tmp = _nums;

  std::random_device rd; // a random number generator seed
  std::default_random_engine gen{rd()};
  //std::mt19937 gen(rd()); // Seed the Mersenne Twister engine
  std::uniform_int_distribution<int> dist(0, _nums.size() - 1);   // Distribution for random index selection

  for (int i = tmp.size() - 1; i > 0; --i) {
    int j = dist(gen); // Generate a random index within the unshuffled portion
      std::swap(tmp[i], tmp[j]); // Swap the current element with the randomly selected element
    }
  return tmp;
}

void SHUFFLE::Sol::print1Dvector() {
  for (auto it=_nums.begin(); it<_nums.end(); ++it) {
    cout <<  *it << " ";
  }
  cout << "\n";
}

// Given an array nums containing n distinct 
// numbers in the range [0, n], return the 
// only number in the range that is missing from the array.
int S::Solution::missingNumber(vector<int>& v) {
  int n = v.size();
  int ariSum = n*(n+1)/2;
  int vSum = std::accumulate(v.begin(), v.end(), 0);
  return (ariSum-vSum);
  
  /* slow in O(n**2), time complexity of the std::count O(n),
  int uLim = v.size() + 1;
  int i;
  for (i=0;i<uLim;++i) {
    if (!count(v.begin(), v.end(), i)) {
      cout << "here" << endl;
      break;
    }
  }
  return i;
  */
}

vector<int> S::Solution::twoSum(vector<int>& nums, int target) {
  
  int nSize=nums.size();
  unordered_map<int, int> uMap;
  int complement;
  
  for (auto i=0; i<nSize; ++i) {
    complement = target - nums[i];
    if (uMap.count(complement)) 
       return {uMap[complement], i};
    uMap.insert({nums[i],i});
  }
  return {};
  
  //for (auto itr = subSet.begin(); itr != subSet.end(); itr++)
  //      cout << (*itr) << endl;
  

  /*
  //O(n^2) runtime solution
  int nSize=nums.size();
  vector<int> tmp;
  int i,j;
  for (i=0; i<nSize-1; ++i) {
    for (j=i+1;j<nSize;++j) {
      if (nums[i]+nums[j]==target) {
        tmp.push_back(i);
        tmp.push_back(j);
      }
    }
  }
  return tmp;
  */
}

// Write a function to find the longest common prefix string amongst an array of strings.
// If there is no common prefix, return an empty string "".
string S::Solution::longestCommonPrefix(vector<string>& strs) { 
  /*
  if (strs.empty())
    return "";
  
  typedef unsigned int uint;
  uint sMinSize=strs[0].size(); // for minimal size of strings
  for (auto it=strs.begin()+1; it!=strs.end(); ++it) {   
    // checking if smaller size is found to replace sMinSize
    sMinSize = sMinSize>(*it).size() ? \
               (*it).size() : sMinSize;
  }
 
  string ans = "";
  // Runtime complexity O(n^2), Space complexity O(1)
  for (uint j=0;j<sMinSize;++j) {
    char sTmp = strs[0][j]; //jth char in 0th string
    for (uint i=1;i<strs.size();++i) {
      if (strs[i][j]!=sTmp) 
        //different jth char in ith string found
        return ans;
    }
    ans+=sTmp;
  }

  return ans;
  */
  if (strs.empty()) {
    return "";
  }
  std::string prefix = strs[0];
  for (unsigned int i = 1; i < strs.size(); ++i) {
    while (strs[i].find(prefix) != 0 && !prefix.empty()) {
      prefix = prefix.substr(0, prefix.size() - 1);
    }
  }
  return prefix;
}

bool S::Solution::isBadVersion(const int n) {
  //return (n>=4);
  //return (n>=1);
  //return (n>=39900);
  return (n>=2147483647);
}


int S::Solution::firstBadVersion(int n) {
/*
  for (auto i=n; i>0;--i) {
    // n-1 is good, n and n+1 is bad 
    if (!isBadVersion(i-1) and \
         isBadVersion(i) and \
         isBadVersion(i+1) )
        return i;
  }

  return -1; // finding no bad version
*/
  //int foundBad = 0;
  int ni=1;
  int ne=n;
  
  while (ni < ne) {
     int mid = ni+(ne-ni)/2;

    // mid is bad
    if (isBadVersion(mid)) {
      ne = mid; // update ne with mid
    }
    // n is good
    else /* if (!isBadVersion(mid) )*/ {
      ni = mid+1; // update ni with mid+1
    }
  }

  //return foundBad;
  return ni;
} 

vector<int> S::Solution::searchRange(vector<int>& nums, int target) {
  //if (!nums.size())
  //  return {-1,1};
  // input 1: nums sorted in non-decreasing order, 
  // input 2: target value, 
  // output: return starting and ending position in 
  //nums matching target as a vector {left, right}, or 
  //return [-1, -1] if target is found
  
  // O(log n) runtime complexity.
  //int nSize = nums.size();
  int left = 0;
  int right = nums.size()-1;
  int nSize = nums.size();

  // binary search 
  while (left<=right) {
    int mid = left + (right-left)/2; // latest middle index
    if (nums[mid] == target){
      // search from middle to both sides to see how far
      // target occupies nums
      //left to the mid
      int lRef  = mid -1;
      while ( lRef >= 0 && nums[lRef] == target )
        --lRef;
      int rRef = mid + 1;
      while ( rRef < nSize && nums[rRef] == target )
        ++rRef;

      return {++lRef, --rRef};
    }
    else if (nums[mid] > target /*update right*/)
      right = mid - 1;
    else if (nums[mid] < target /*update left*/)
      left = mid + 1;
  }
    
  /* 
  // O(n) runtime
  bool leftFound = false;
  for (auto i=0; i<nSize; ++i) {
    if (nums[i] == target && !leftFound) {
      ans[0] = i;
      leftFound = true;
    }
    if (leftFound && nums[i]>target) {
      ans[1] = i-1;
      return ans;
    }
  }
  */

  // return [-1, -1] if target is found
  return {-1,1};
}
