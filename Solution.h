#include <algorithm> /* max_element, count, copy */
#include <assert.h> /* assert */
#include <cstdio> /* printf */
#include <cstdlib>
#include <bits/stdc++.h> /* MAX_INT ; MIN_INT */
#include <iostream>
#include <math.h> /* log10 */
#include <memory> /* auto_ptr */
#include <numeric> /* std::accumulate */
#include <queue> /* priority_queue */
#include <random> /* random_device */
#include <stdlib.h> /* atoi */
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <utility> /* std::pair, std::make_pair, move */
#include <vector>

using namespace std;

#ifndef HEADER_H_SOLUTION
#define HEADER_H_SOLUTION



namespace DSALG{


  template <typename T>
  class ArrayLikeDsAlg {
  public:
    void bubbleSort(T arr[], const int& arrSize);
    void insertionSort(T arr[], const int& arrSize);
    void mergeSort(T arr[], const int& arrSize);
    void runMergeSort(T arr[], 
        const int& leftIndex, 
        const int& rightIndex);
    void merge(T arr[], 
        const int& leftIndex, 
        const int& midIndex,
        const int& rightIndex);
    void heapSort(T arr[]);
    void quickSort(T arr[]);
    
    void showArray(T arr[], const int& arrSize);
  };

  /* Bubble sort runs O(n^2) time complexity */
  template <typename T>
  void ArrayLikeDsAlg<T>::bubbleSort(T arr[], const int& arrSize){
    /* empty of single element array */
    if (arrSize <= 1) return;
    
    for (auto i=0; i<arrSize-1; ++i) {
      for (auto j=i+1; j<arrSize; ++j) {
        if (arr[i] > arr[j]) swap(arr[i], arr[j]);
      }
    }
  };

  /* Insertion sort runs O(n^2) time complexity */
  template <typename T>
  void ArrayLikeDsAlg<T>::insertionSort(T arr[], const int& arrSize){
    /* empty of single element array */
    if (arrSize <= 1) return;

    for (auto i=1; i<arrSize; ++i) {
      T key = arr[i];
      auto j = i-1; // iniital index j for arr[0:i-1]
      /* check if key is smaller than arr[j] */
      while (j>=0 and arr[j] > key) {
        /* move arr[j] to the arr[j+1] next to j, 
         * then j-- means moving to j-1 for next iteration
         * */
        arr[j+1] = arr[j];
        --j; 
      }
      /* set key to final position at j, which yields
       * a Sorted subarray A[0:i] */
      arr[++j]=key; 
    }
  };
  
  /* Merge sort runs O(nlog n) time complexity */
  template <typename T>
  void ArrayLikeDsAlg<T>::mergeSort(T arr[], const int& arrSize){
    /* empty of single element array */
    if (arrSize <= 1) return;
      
    /* running merge sort algorithm */
    runMergeSort(arr, 0, arrSize-1);

  };
  
  /* helper function */
  template <typename T>
  void ArrayLikeDsAlg<T>::runMergeSort(T arr[],
     const int& leftIndex,
     const int& rightIndex) {
    /* Check index */
    if (leftIndex >= rightIndex) return;
      
    /* Divide and conquer recurrsively subarrays */
    int midIndex = leftIndex + 0.5*(rightIndex-leftIndex);
    runMergeSort(arr, leftIndex, midIndex);
    runMergeSort(arr, midIndex+1, rightIndex);

    /* Merge the subarrays */
    merge(arr, leftIndex, midIndex, rightIndex);
  };
  
  
  /* helper function of merging subarrays */
  template <typename T>
  void ArrayLikeDsAlg<T>::merge(T arr[],
     const int& leftIndex,
     const int& midIndex,
     const int& rightIndex) {
    
    auto leftArrSize = midIndex-leftIndex+1;
    auto rightArrSize = rightIndex-midIndex;

    /* allocate memory for subarrays */
    T* leftArr = new T[leftArrSize];
    T* rightArr = new T[rightArrSize];
    
    /* assign left subarray */
    std::copy(arr+leftIndex, arr+midIndex+1, leftArr);
    
    /* assign right subarray */
    std::copy(arr+(midIndex+1), arr+rightIndex+1, rightArr);

    auto arrIndex = leftIndex; // index for filling original arr
    auto tempLeftIndex = 0;
    auto tempRightIndex = 0;
    while (tempLeftIndex < leftArrSize and 
           tempRightIndex < rightArrSize ) {
      /* compare smaller element from both subarrays*/
      if (leftArr[tempLeftIndex] < rightArr[tempRightIndex]) {
        arr[arrIndex++] = move(leftArr[tempLeftIndex++]);
      } else {
        arr[arrIndex++] = move(rightArr[tempRightIndex++]);
      }
    }

    /* fill any elements left in subarrays */
    if (tempLeftIndex < leftArrSize) {
      copy(leftArr+tempLeftIndex,
           leftArr+leftArrSize,
           arr+arrIndex); 
    } 
    if (tempRightIndex < (rightIndex-midIndex)) { 
      copy(rightArr+tempRightIndex,
           rightArr+rightArrSize,
           arr+arrIndex); 
    }
    
    /* deallocate memory pointed by ptr */
    delete[] leftArr;
    delete[] rightArr;
  };
  
  /* Show array elements */ 
  template <typename T>
  void ArrayLikeDsAlg<T>::showArray(T arr[], const int& arrSize) {
    for (auto i=0; i<arrSize; ++i) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }
}



namespace T {
  bool uTest(vector<int>& vT, int& ans);
}


namespace T {
  class Thrd{
  public:
    void hello();
  };
}

namespace STREE {
  struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {};
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : \
      val(x), left(left), right(right) {};
  };

  class Tree {
  private:
    TreeNode* _root;
  public:
    Tree():_root(nullptr) {};
    Tree(TreeNode* rPtr):_root(rPtr) {};

    void printTree(TreeNode* root);
    int maxDepth(TreeNode* root);
  };
}

namespace STHREE {
 //* Definition for singly-linked list.
  struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x):val(x), next(nullptr) {};
  };
 
  bool hasCycle(ListNode* head);
  
  class LinkedList {
  private:
     ListNode* first;

   public:
     LinkedList():first(nullptr) {};
     void addNode(ListNode* node);
     void printNode();
     void deleteNode(ListNode* node);
   };
}

namespace STWO {
  struct ListNode {
    int val;
    ListNode* next;
    ListNode() : val(0), next(nullptr) {};
    ListNode(int x) : val(x), next(nullptr) {};
    ListNode(int x, ListNode *next) : val(x), next(next) {};
  };

  class LinkedList {
    private:
        ListNode* first;
    public:
        LinkedList():first(nullptr) {};   //constructor
        ~LinkedList() {delete first;};   //destructor
        void addNode(int v);
        void displayAll();
        ListNode* getFirstNodePtr();
        ListNode* reverseList(ListNode* head);
        ListNode* reverseList(ListNode* head,\
                              ListNode* prev);
        ListNode* reverseNode(ListNode* cur);
  }; 
} // namespace STWO

namespace SHUFFLE {
  class Sol {
  private:
    vector<int> _nums;

  public:
    Sol(vector<int>& nums):_nums(nums) {};
    
    vector<int> reset();
    vector<int> shuffle();

    void print1Dvector();
  };
}

namespace S {
    struct ListNode {
        int val;
        ListNode* nxt;
        ListNode(int v): val(v), nxt(nullptr) {};
        
    };

    class LinkedList {
    private:
        ListNode* first;
    public:
        LinkedList():first(nullptr) {};   //constructor
        ~LinkedList() {delete first;};   //destructor
        void addNode(int v);
        void displayAll();
        void deleteNode(ListNode* node);
        ListNode* findNode(int v, LinkedList iL);
    };

    struct TreeNode {
        int val;
        TreeNode* left;
        TreeNode* right;
        TreeNode() : val(0), left(nullptr), right(nullptr) {}
        TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };

    class Solution {
    private:
        std::string sC;
        std::vector<int> iV;
        std::vector<std::vector<int>>  diff;
    public:
        Solution(): sC("") {};   // constructor
        ~Solution() {};         // destructor
            
        // method declaration
        std::string reverseVowelOfAString(std::string sRef);
        bool containVowel(char& ctmp);
        void swap(int& i, int& j);
        void swapInt(int& i, int& j);
        void swap(char* a, char* b);
        void swap(char& a, char& b);
        void setValue(std::string& sRef);
        void setIntValue(std::vector<int> src);        
        void getValue(); 
        void getVecValue(); 
        int hammingDistance(const std::vector<int>& a, const std::vector<int>& b);    

        bool containsNearbyAlmostDuplicate(std::vector<int>& nums, int indexDiff, int valueDiff);   
        int reverse(int& x);
        int numDigit(const int& x);
        int slicing(const int& x, const int& dig);

        int getWinner(std::vector<int>& arr, int k);
           
        std::vector<std::vector<int>> onesMinusZeros(std::vector<std::vector<int>>& grid );
        int onesRowi(std::vector<std::vector<int>>& g, const int& i);
        int onesColj(std::vector<std::vector<int>>& g, const int& j);

        //static bool mycmp(pair<int,int> a,pair<int,int> b);
        int carFleet(int target, vector<int>& position, vector<int>& speed);
        void sortBasedPst(vector<int>& position, vector<int>& speed);  
        int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers);

        int getLastMoment(int n, vector<int>& left, vector<int>& right);

        bool hasAllCodes(std::string& s, int& k);
        int biToInt(std::string& s, int& k, int& ini);
        int biToInt(vector<char>::iterator& i, vector<char>::iterator& e);

        int scoreOfParentheses(string& s);

        int maximumScore(vector<int>& nums, int k);

        bool isIdealPermutation(vector<int>& nums);

        int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps);
        int maxResult(vector<int>& nums, int k);
        
        int mySqrt(int& x);
        double newtonRaphsonMethod(int& x, double& rootGuess, int nth=2);
        double nthX(int nth, double x);

        int minimumDifference(vector<int>& nums); //To be done
                                                  
        TreeNode* pruneTree(TreeNode* root);

        vector<int> distributeCandies(int candies, int num_people);

        int maxProfit(vector<int>& prices);

        double champagneTower(int poured, int query_row, int query_glass);

        int uniquePathsIII(vector<vector<int>>& grid);
        bool isValid(int& i,int& j, int& m,int& n);
        //backtracking algorithm
        int dfs(int i, int j, int left, \
                pair<int, int> dest, vector<vector<int>>& grid, \
                int& m, int&n); 
    
        vector<int> numberGame(vector<int>& nums);
        bool compareNums(const int& ix, const int& iy);

        int numSubarrayProductLessThanK(vector<int>& v, int& k);

        unsigned long long Fibo(int n /*nth term in fibo*/);

        void rotateCW(vector<vector<int>>& m);
        void rotateCCW(vector<vector<int>>& m);
        void print2Dvector(vector<vector<int>>& m);

        int countPrimes(int n);
        bool isPrime(int& n);

        void reverseString(vector<char>& s);
        void print1Dvector(vector<char>& v);

        void merge(vector<int>& nums1, int m, \
                   vector<int>& nums2, int n);
        void print1Dvector(vector<int>& v);

        int maxSubArray(vector<int>& nums);

        int romanToInt(string s);

        int hammingWeight(int n);
    
        int missingNumber(vector<int>& v);
        vector<int> twoSum(vector<int>& nums, \
                           int target);
        string longestCommonPrefix(vector<string>& strs);

        int firstBadVersion(int n);
        bool isBadVersion(const int n);

        vector<int> searchRange(vector<int>& nums, int target);

        vector<int> inorderTraversal(TreeNode* root);
    }; // class Solution
}

#endif // HEADER_H_SOLUTION
