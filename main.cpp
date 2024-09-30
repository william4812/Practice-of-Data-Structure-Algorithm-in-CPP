#include <iostream>
#include <thread>

#include "Solution.h"

using namespace std;
using S::Solution;
using S::LinkedList;
using S::ListNode;
using T::Thrd;
using namespace STWO;
using namespace STREE;
using namespace SHUFFLE;
void hello();

int (*funPtr)(int a, int b);  //function pointer

void funPtrTest(void) {
  cout << " This fPtrTest!!\n";
}

void callback(void (*funPtrTmp)()) {
  cout << "callback returns\n";
  funPtrTmp();
}

int sum(int a, int b) {
  return a+b;
}

int diff(int a, int b) {
  return a-b;
}

int testArrayLikeDsAlg() {
  DSALG::ArrayLikeDsAlg<int> aLDAi;
   
  //int arrI[] {1, 22, 321, 4567, -4, -15};
  int arrI[] {2, 8, 7, 1, 3, 5, 6, 4};
  int arrSize = sizeof(arrI)/sizeof(int);
  printf("Array of integers\n");
  printf("before sort...\n");
  aLDAi.showArray(arrI, arrSize);
  //aLDAi.bubbleSort(arrI, arrSize);
  //aLDAi.insertionSort(arrI, arrSize);
  //aLDAi.mergeSort(arrI, arrSize);
  //aLDAi.heapSort(arrI, arrSize);
  //cout << aLDAi.getPivotIndex(arrI, 0, arrSize-1) << endl;
  //cout << aLDAi.getPivotIndex(arrI, 0, 2) << endl;
  aLDAi.quickSort(arrI, arrSize);

  /*
  //int arrIH[] {16, 4, 10, 14, 7, 9, 3, 2, 8, 1};
  int arrIH[] {4, 1, 3, 2, 16, 9, 10, 14, 8, 7};
  int arrSizeH = sizeof(arrIH)/sizeof(int);
  aLDAi.showArray(arrIH, arrSizeH);
  */
  //aLDAi.heapSort(arrIH, arrSizeH);
  //aLDAi.maxHeapify(arrIH, 1/*zero-based index*/, arrSizeH);
  //aLDAi.buildMaxHeap(arrIH, arrSizeH);
  //aLDAi.heapSort(arrIH, arrSizeH);
  

  printf("after sort...\n");
  aLDAi.showArray(arrI, arrSize); // -15 -4 1 22 321 4567
 
  /* 
  DSALG::ArrayLikeDsAlg<double> aLDAd;
  double arrD[] {1.9, 3.1, 1.99, -321.3, 4567.6, -4.001, 15.56};
  arrSize = sizeof(arrD)/sizeof(double);
  printf("Array of doubles\n");
  printf("before sort...\n");
  aLDAd.showArray(arrD, arrSize);
  //aLDAd.bubbleSort(arrD, arrSize);
  //aLDAd.insertionSort(arrD, arrSize);
  //aLDAd.mergeSort(arrD, arrSize);
  aLDAd.heapSort(arrD, arrSize);
  printf("after sort...\n");
  aLDAd.showArray(arrD, arrSize); // -321.3 -4.001 1.9 1.99 3.1 15.56 4567.6
  */

  return 0;
}

int testDLinkedList() {
  DSALG::DLinkedList<int> dLLi;
  
  dLLi.showKeys();

  printf("\nprepending...\n");
  dLLi.prependLink(1);
  dLLi.prependLink(4);
  dLLi.prependLink(16);
  dLLi.prependLink(9);
  dLLi.showKeys();
  dLLi.prependLink(25);

  printf("\nsearching...\n");
  assert((dLLi.searchLink(4)->_value)==4);
  assert(dLLi.searchLink(5)==nullptr);
  
  dLLi.showKeys();
  printf("\ninserting...\n");
  dLLi.insertLink(36/*newLink*/, 9/*refLink*/);
  
  dLLi.showKeys();
  printf("\ndeleting...\n");
  dLLi.deleteLink(4);
  
  dLLi.showKeys();
  
  
  DSALG::DLinkedList<double> dLLr;
  
  dLLr.showKeys();

  printf("\nprepending...\n");
  dLLr.prependLink(1.1);
  dLLr.prependLink(4.9);
  dLLr.prependLink(16.4);
  dLLr.prependLink(9.3);
  dLLr.showKeys();
  dLLr.prependLink(25.7);

  printf("\nsearching...\n");
  assert((dLLr.searchLink(4.9)->_value)==4.9);
  assert(dLLr.searchLink(5)==nullptr);
  
  dLLr.showKeys();
  printf("\ninserting...\n");
  dLLr.insertLink(36.2/*newLink*/, 9.3/*refLink*/);
  
  dLLr.showKeys();
  printf("\ndeleting...\n");
  dLLr.deleteLink(4.9);
  
  dLLr.showKeys();

  return 0;
}
  
int testStack() {
  DSALG::Stack<int> S;
  assert(S.isEmpty()==true);
  cout << "Stack is " 
       << (S.isEmpty()?"empty":"not empty")
       << "!\n";

  printf("push elements...\n");
  S.push(15);
  S.push(6);
  S.push(2);
  S.push(9);
  
  cout << "Stack is " 
       << (S.isEmpty()?"empty":"not empty")
       << "!\n";

  cout << "get top element " << S.getTop() << endl;
  
  printf("push two more elements...\n");
  S.push(17);
  S.push(3);
  cout << "get top element " << S.getTop() << endl;
  
  cout << "pop top element... " << endl;
  S.pop();
  cout << "get top element " << S.getTop() << endl;
  cout << "pop top element... " << endl;
  S.pop();
  cout << "get top element " << S.getTop() << endl;
  cout << "pop top element... " << endl;
  S.pop();
  cout << "get top element " << S.getTop() << endl;
  cout << "pop top element... " << endl;
  S.pop();
  cout << "get top element " << S.getTop() << endl;
  cout << "pop top element... " << endl;
  S.pop();
  cout << "get top element " << S.getTop() << endl;
  
  cout << "Stack is " 
       << (S.isEmpty()?"empty":"not empty")
       << "!\n";
  cout << "pop top element... " << endl;
  S.pop();
  
  return 0;
}

std::string reverseString(const std::string& strInput) {
  
  DSALG::Stack<char> strTemp;
  for (const auto& s: strInput) {
    strTemp.push(s);
  }
   
  std::string reversedString;
  while (!strTemp.isEmpty()) {
    reversedString+=(strTemp.getTop());
    strTemp.pop();
  }

  return reversedString;
}

int testReversedString() {
  std::string originalString{"Hello, World!"}; 
  assert(reverseString(originalString) == "!dlroW ,olleH");
  printf("The revere of original string \"%s\" is \"%s\".\n", 
      originalString.c_str(),
      reverseString(originalString).c_str());
  return 0;
}

int testBrowseHistory() {
  DSALG::BrowseHistory<std::string> bH;
  bH.visit("explorecalifornia.org");
  bH.visit("pixelford.com");
  bH.visit("landonotel.com");
  
  cout << "current site: " << bH.current() << endl;
  
  bH.back();
  cout << "current site: " << bH.current() << endl;

  bH.back();
  cout << "current site: " << bH.current() << endl;
  
  bH.back();
  cout << "current site: " << bH.current() << endl;
  
  return 0;
} 


int main() {
  
  assert(testBrowseHistory()==0);

  //assert(testReversedString()==0);

  //assert(testDLinkedList()==0);
  
  //assert(testStack()==0);

  //assert(testArrayLikeDsAlg()==0);

  //Solution s;
  /*
  Solution s;
  //vector<int> n{5,7,7,8,8,10}; int t = 8; //test 1, {3, 4}
  //vector<int> n{5,7,7,8,8,10}; int t = 6; //test 2, {-1, -1}
  //vector<int> n{}; int t = 0; //test 3, {-1, -1}
  vector<int> n{1}; int t = 1; //test 3, {0, 0}
  cout << "testing..." << endl;
  vector<int> ans = s.searchRange(n, t);
  s.print1Dvector(ans); 
  */
  
  /*
  Solution s;
   
  //int n = 5; // bad = 4
  //int n = 4; // bad = 1
  //int n = 400000; // bad = 399
  //long int n = 2126753390; // bad = 1702766719
  long int n = 2147483647; // bad = 2147483647
  cout << s.isBadVersion(2147483647) << endl;;
  //cout << s.isBadVersion(2147483647) << endl;;
  cout << s.firstBadVersion(n) << endl;;
  */

  /*
  STHREE::ListNode* head = new STHREE::ListNode{3};
  head->next=new STHREE::ListNode{2};
  STHREE::ListNode* ref = head->next;
  head->next->next=new STHREE::ListNode{0};
  head->next->next->next=new STHREE::ListNode{-4};
  head->next->next->next->next=ref;

  cout << STHREE::hasCycle(head) << endl;;   
  
  delete head;
  */

  /*
  Solution s;
  //vector<string> strs = {"flower","flow","flight"};
  vector<string> strs = {"dog","racecar","car"};
  cout << s.longestCommonPrefix(strs) << endl;
  */

  /*
  Solution s;
  vector<int> v{2,7,11,15}; int target = 9;
  //vector<int> v{3,2,4}; int target = 6;
  
  vector<int> result=s.twoSum(v, target);
  s.print1Dvector(result);
  */
  /*
  Solution s;
  //vector<int> v{0,1}; // output 2
  //vector<int> v{3,0,1}; // output 2
  vector<int> v{9,6,4,2,3,5,7,0,1}; // output 8 
  cout << s.missingNumber(v) << endl;
  */

  /*
  Solution s;
  int n = 2147483645;
  cout << s.hammingWeight(n) << endl;
  */
  /*
  vector<int> v{1,2,3};
  Sol* s = new Sol(v);
  s->print1Dvector(); 

  vector<int> v2 = s->shuffle();
  for (auto it=v2.begin(); it<v2.end(); ++it) {
    cout <<  *it << " ";
  }
  cout << "\n";
  

  vector<int> v3 = s->reset();
  for (auto it=v3.begin(); it<v3.end(); ++it) {
    cout <<  *it << " ";
  }
  cout << "\n";
  */

  //s2.sh
  /*
  Solution s;
  //string st{"III"}; 
  //string st{"LVIII"};
  string st{"MCMXCIV"}; //1994
  //string st{"IV"};
  cout << s.romanToInt(st) << endl;
  */

  /*
  Solution s;
  //vector<int> v={1};
  vector<int> v={5,4,-1,7,8}; // ->23 
  //vector<int> v={-2,1,-3,4,-1,2,1,-5,4}; // -> 6
  //vector<int> v={-1,8};
  //cout << *max_element(v.begin(),v.end()) << endl;
  cout << s.maxSubArray(v) << endl;
  */

  /*
  Solution s;

  // nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
  //vector<int> v2 = {2,5,6}; int n_2 = v2.size();
  //vector<int> v1 = {1,2,3}; int n_1 = v1.size();
  
  // nums1 = [1], m = 1, nums2 = [], n = 0
  //vector<int> v2; int n_2 = v2.size();
  //vector<int> v1 = {1}; int n_1 = v1.size();
  
  // nums1 = [0], m = 0, nums2 = [1], n = 1
  //vector<int> v2 = {1}; int n_2 = v2.size();
  //vector<int> v1 = {}; int n_1 = v1.size();
  
  // [4,0,0,0,0,0], 1, [1,2,3,5,6], 5
  vector<int> v2 = {1,2,3,5,6}; int n_2 = v2.size();
  vector<int> v1 = {4}; int n_1 = v1.size();

  //[1,2,4,5,6,0], 5, [3], 1
  //vector<int> v2 = {3}; int n_2 = v2.size();
  //vector<int> v1 = {1,2,4,5,6}; int n_1 = v1.size();
  

  vector<int> v2zero(n_2,0);
  v1.insert(v1.end(),v2zero.begin(),v2zero.end());

  s.print1Dvector(v1);
  s.merge(v1,n_1,v2,n_2);
  s.print1Dvector(v1);
  */

  //
  /*
  // root = [3,9,20,null,null,15,7]
  STREE::TreeNode* root = new TreeNode(3);
  root->left = new TreeNode(9);
  root->right = new TreeNode(20);
  root->right->left = new TreeNode(15);
  root->right->right = new TreeNode(7);

  cout << root->val << "\n";
  cout << root->left->val << "\n";
  cout << root->right->val << "\n";
  cout << root->right->left->val << "\n";
  cout << root->right->right->val << "\n";
    
  // root = [1,null,2]
  STREE::TreeNode* root = new TreeNode(1);
  root->right = new TreeNode(2);
  
  cout << root->val << "\n";
  cout << root->right->val << "\n";
   

  STREE::Tree tPtr(root);
  //tPtr.printTree(root);
  printf( "maxDepth is %d.\n", tPtr.maxDepth(root));
  */

  /*
  char str1[] = "Defined as an array"; // str1 as ptr constant, address
  //char* str2 = "Defined as a pointer"; //Error  str2 as ptr variable causing error because string literals are constant character arrays
  char* str2 = str1; // works,  str2 as ptr variable assigned str1 as address literal

  cout << str1 << endl;
  cout << ++str2 << endl;
  */
  /*
  int array[] = {1,2,3,4,5};
  printf("sizeof(X) operator returns the size of X in bytes in long unsigned integer.\n");
  printf("sizeof(array) is %ld bytes.\n", sizeof(array));
  printf("sizeof(int) is %ld bytes.\n", sizeof(int));
  for (auto i=0;i<5;++i){
    cout << array[i] << " ";
  }
  cout << "\n";
  */
  /*
  STHREE::LinkedList head;
  //STHREE::ListNode n1(4),n2(5),n3(1),n4(9);
  STHREE::ListNode* n1 = new STHREE::ListNode(4);
  STHREE::ListNode* n2 = new STHREE::ListNode(5);
  STHREE::ListNode* n3 = new STHREE::ListNode(1);
  STHREE::ListNode* n4 = new STHREE::ListNode(9);
  
  head.addNode(n4);
  head.addNode(n3);
  head.addNode(n2);
  head.addNode(n1);
  head.printNode();
  //cout << n2->next->val;
  head.deleteNode(n2);
  head.printNode();
  */

  /*
  Solution s;
  //vector<char> sV = {'h','e','l','l','o'};
  vector<char> sV = {'h','a','n','n','a','h'};
  s.print1Dvector(sV);
  s.reverseString(sV);
  s.print1Dvector(sV);
  */
  /*
  Solution s;
  int n = 10000;
  cout << n << " is Prime: " << boolalpha << s.isPrime(n) << endl;
  printf("The number of primes less than %d is %d.\n",
      n, s.countPrimes(n));
  */
  /*
  Solution s;
  //vector<vector<int>> m = {{1,2,3},{4,5,6},{7,8,9}};
  vector<vector<int>> m = {{5,1,9,11},\
                           {2,4,8,10},\
                           {13,3,6,7},\
                           {15,14,12,16}};
  
  s.print2Dvector(m);
  //s.rotateCW(m);
  s.rotateCCW(m);
  cout << "------------------" << endl;
  s.print2Dvector(m);
  */

  /*
  Solution s;
  int n = 50;
  printf("The %dth term of Fibonacci is %lld.", n, s.Fibo(n));
  */
  
  /*
  Solution s;
  vector<int> x = {10,5,2,6};
  int k = 100;
  //vector<int> x = {1,2,3};
  //int k = 0;
  
  cout << "output is " << s.numSubarrayProductLessThanK(x, k) << ".\n";
  */

  /*
  vector<int> x = {5,4,2,3};
  for (auto it=x.begin(); it<x.end(); ++it) {
    cout << "*it " << *it << "\n";
  }

  Solution s;
  vector<int> y = s.numberGame(x);
  for (auto it=y.begin(); it<y.end(); ++it) {
    cout << "*it " << *it << "\n";
  }
  */

  /*
  STWO::LinkedList lkList;
  vector<int> list = {1,2,3,4,5};

  for (auto it=list.end()-1; it>=list.begin(); --it) {
    //cout << "list: " << *it << "\n";
    lkList.addNode(*it);
  }
  lkList.displayAll();
  
  //STWO::ListNode* head = lkList.reverseList(lkList.getFirstNodePtr());
  
  lkList.reverseList(lkList.getFirstNodePtr());
  cout << "reversed head->val " << \
    lkList.getFirstNodePtr()->val << endl;
  lkList.displayAll();
  */

  /*
  Solution s;  
  //vector<vector<int>> grid = {{0,1},{2,0}};
  vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,2,-1}};
  //vector<vector<int>> grid = {{1,0,0,0},{0,0,0,0},{0,0,0,2}};
  printf("The number of unique path is %d.\n", \
         s.uniquePathsIII(grid));
  */
  /*
  callback(&funPtrTest);

  funPtr = &sum;
  cout << "fPtr of sum is " << funPtr(3, 5) << "\n";
  funPtr = &diff;
  cout << "fPtr of diff is " << funPtr(100, 5) << "\n";
  */
    /*
    //multithread   
    Thrd trd;
    trd.hello();
    std::thread t(hello);
    t.join();   
    */

    /*
    LinkedList iL;

    iL.addNode(6);
    iL.addNode(4);
    iL.addNode(5);
    iL.addNode(1);
    iL.addNode(9);
    iL.addNode(10);
   
    ListNode* nd = iL.findNode(5, iL);

    iL.displayAll();

    iL.deleteNode(nd);

    iL.displayAll(); 
    */
    
    /*
    Solution s;
    vector<int> prices = {7,1,5,3,6,4};
    cout << "the profit is " << s.maxProfit(prices) << endl; 
    prices = {1,2,3,4,5};
    cout << "the profit is " << s.maxProfit(prices) << endl;
    prices = {7,6,4,3,1};
    cout << "the profit is " << s.maxProfit(prices) << endl;
    */

    //prices = {7,6,4,3,1};
    //s.maxProfit(prices);
    //int x = 4;
    //int x = 19;
    //cout << s.mySqrt(x) << endl;
    /*    
    vector<int> src = {1,2,3,4};
    vector<int> tgt = {2,1,4,5};
    vector<vector<int>> aSwaps = {{0,1},{2,3}};
    s.minimumHammingDistance(src, tgt, aSwaps);
    */
    /* 
    //std::vector<int> nums = {1,0,2};
    //std::vector<int> nums = {2, 0, 1};
    std::vector<int> nums = {0};
    //std::vector<int> nums = {1,2,0};
    cout << boolalpha << s.isIdealPermutation(nums) << endl;
    */
    
    /*
    std::vector<int> nums = {5,5,4,5,4,1,1,1};
    int k = 0;
    //std::vector<int> nums = {1,4,3,7,4,5};
    //int k = 3;
    cout << s.maximumScore(nums, k) << endl;
    */
    /*
    //std::string st = "()";
    //std::string st = "(())";
    //std::string st = "()()";
    std::string st = "(()(()))";
    
    cout << s.scoreOfParentheses(st) << endl;
    */

    /*
    //std::string st = "00110110";
    std::string st = "00110";
    int k = 2;
    
    cout << s.hasAllCodes(st, k) << endl;
    */

    /* 
    //getLastMoment
    //int n = 4;
    //std::vector<int> left = {4, 3};
    //std::vector<int> right = {0, 1};

    //int n = 7;
    //std::vector<int> left = {};
    //std::vector<int> right = {0, 1, 2, 3, 4, 5, 6, 7};
    
    int n = 1000;
    std::vector<int> left = {0};
    std::vector<int> right = {};
    s.getLastMoment(n, left, right);
    */
    
    /*
    std::vector<int> players = {4, 7, 9};
    std::vector<int> trainers = {8, 2, 5, 8};
    //std::vector<int> players = {1, 1, 1};
    //std::vector<int> trainers = {10};
    s.matchPlayersAndTrainers(players, trainers);
    */
    /*
    //int tgt = 12;
    //std::vector<int> pst = {10, 8, 0, 5, 3};
    //std::vector<int> spd = {2, 4, 1, 1, 3};
    
    //int tgt = 10;
    //std::vector<int> pst = {3};
    //std::vector<int> spd = {3};
    
    //int tgt = 100;
    //std::vector<int> pst = {0, 2, 4};
    //std::vector<int> spd = {4, 2, 1};
   
    int tgt = 10;
    std::vector<int> pst = {0, 4, 2};
    std::vector<int> spd = {2, 1, 3};
    cout << s.carFleet(tgt, pst, spd) << endl;
    */

    /*
    std::vector<std::vector<int>> grid = {{0,1,1},{1,0,1},{0,0,1}};
    
    std::vector<std::vector<int>> diff = s.onesMinusZeros(grid);
    for (int i = 0; i < diff.size(); ++i) {
        for (int j = 0; j < diff[i].size(); ++j) {
            cout<< "diff[" << i << "][" << j << "]:" << \
                    diff[i][j] << " ";          
        }
        cout << endl;
    }
    */


    /*
    std::vector<int> arr = {2,1,3,5,4,6,7};
    int k = 2;
    //std::vector<int >arr = {3,2,1}; 
    //unsigned int k = 10;
    cout << "The winner is " << s.getWinner(arr, k) << "." <<  endl;
    */

    /*
    //int32_t x = 123; //321
    int32_t x = -123; //-321
    //int32_t x = 120; //21
    //cout << x << endl;
    s.reverse(x);
    */

    /* 
    std::vector<int> ns{1, 2, 3, 1};
    int iDiff = 3;
    int vDiff = 0;
    */
    /*
    std::vector<int> ns = {1,5,9,1,5,9};
    int iDiff = 2;
    int vDiff = 3;
    */
    /*
    std::vector<int> ns = {2,2};
    int iDiff = 2;
    int vDiff = 0;
    
    std::vector<int> ns = {3, 5, 6, 7};
    int iDiff = 2;
    int vDiff = 3;
    
    s.containsNearbyAlmostDuplicate(ns, iDiff, vDiff);
    */

    /*
    s.reverseVowelOfAString("hello");
    s.getValue();  
    s.reverseVowelOfAString("aeiou");
    s.getValue();
    s.reverseVowelOfAString("aeioua");
    s.getValue();
    */
    return 0;
}

void hello() {
    cout << "hello thread here" << endl;
}
