#include <iostream>
#include <thread>
#include <bitset>

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
  DSA::ArrayLikeDsAlg<int> aLDAi;
   
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
  DSA::ArrayLikeDsAlg<double> aLDAd;
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
  DSA::DLinkedList<int> dLLi;
  
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
  
  
  DSA::DLinkedList<double> dLLr;
  
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
  DSA::Stack<int> S;
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
  
  DSA::Stack<char> strTemp;
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
  DSA::BrowseHistory<std::string> bH;
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

int testQueue() {
  DSA::Queue<int> q(12);
  
  cout << "Queue is " << (q.isEmpty()?"empty":"not empty") << endl;
  printf("Enqueue...\n");
  for (auto i=0; i<6; ++i) q.enqueue(i);
  q.enqueue(15);
  q.enqueue(6);
  q.enqueue(9);
  q.enqueue(8);
  q.enqueue(4);
  q.enqueue(17);
  cout << "Queue is " << (q.isFull()?"full":"not full") << endl;
 
  cout << "getFront(): " << q.getFront() << endl; 
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  cout << "Queue is " << (q.isFull()?"full":"not full") << endl;

  printf("Enqueue...\n");
  q.enqueue(3);
  cout << "Queue is " << (q.isFull()?"full":"not full") << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  printf("Dequeue...\n");
  cout << "Element at head: " << q.dequeue() << endl;
  cout << "Queue is " << (q.isEmpty()?"empty":"not empty") << endl;
  
  return 0;
}
  
int testBitwiseOperation() {
  uint8_t number = 15;
  cout << (unsigned int)number << endl;
  cout << number << endl;

  //number = (number >> 3);

  cout << "hex of " << number << ": " 
       << std::hex << number << endl;
  
  std::bitset<sizeof(int) * 8> binary(number);
  std::cout << "Binary representation of 42: " << binary << std::endl;
  
  number = (number << 6);

  cout << "hex of " << number << ": " 
       << std::hex << number << endl;
  
  std::bitset<sizeof(int) * 8> binary2(number);
  std::cout << "Binary representation of 42: " << binary2 << std::endl;

  return 0;
}

int testPriorityQueue() {
  DSA::TaskKey<int> tK1{"task 1", 100};
  //cout << tK1._task << endl; 
  DSA::PriorityQueue<DSA::TaskKey<int>> pQ{tK1};
  
  cout << pQ.getMaximum()._task << endl; 
  return 0;
}

int testBinarySearchTree() {
  //DSA::Node<int>* newNode = new DSA::Node<int>(12);
  DSA::BinarySearchTree<int> bST1;
  bST1.treeInsert(new DSA::Node<int>(6)); // root
  bST1.treeInsert(new DSA::Node<int>(5));
  bST1.treeInsert(new DSA::Node<int>(7));
  bST1.treeInsert(new DSA::Node<int>(5));
  bST1.treeInsert(new DSA::Node<int>(8));
  bST1.treeInsert(new DSA::Node<int>(2));
  
  printf("in order tree walk...\n"); 
  bST1.runInOrderTreeWalk();
  printf("pre order tree walk...\n"); 
  bST1.runPreOrderTreeWalk();
  printf("post order tree walk...\n"); 
  bST1.runPostOrderTreeWalk();
  
  DSA::BinarySearchTree<int> bST2;
  DSA::Node<int> testNode{8};
  bST2.treeInsert(new DSA::Node<int>(2));
  bST2.treeInsert(new DSA::Node<int>(5));
  bST2.treeInsert(new DSA::Node<int>(7));
  bST2.treeInsert(new DSA::Node<int>(6));
  //bST2.treeInsert(&testNode);
  bST2.treeInsert(new DSA::Node<int>(5));
  
  printf("in order tree walk...\n"); 
  bST2.runInOrderTreeWalk();
  cout << "iterative tree search for node with key " 
       << testNode._key << endl;
  //assert(bST2.iterativeTreeSearch(&testNode) == &testNode);
  printf("Found? %s\n", 
      bST2.iterativeTreeSearch(&testNode)?"True":"False");


  DSA::Node<int>* rootNode = new DSA::Node<int>(12);
  DSA::BinarySearchTree<int> bST(rootNode);
  
  DSA::Node<int>* tNode0 = new DSA::Node<int>(5);
  bST.treeInsert(tNode0);
  bST.treeInsert(new DSA::Node<int>(18));
  bST.treeInsert(new DSA::Node<int>(2));
  bST.treeInsert(new DSA::Node<int>(9));
  
  DSA::Node<int>* tNode1 = new DSA::Node<int>(15); 
  bST.treeInsert(tNode1);
 
  bST.treeInsert(new DSA::Node<int>(19));
  DSA::Node<int>* tNode2 = new DSA::Node<int>(13); 
  bST.treeInsert(tNode2);
  bST.treeInsert(new DSA::Node<int>(17));

  printf("in order tree walk...\n"); 
  bST.runInOrderTreeWalk(); 
  
  cout << "maximum of key is " << bST.getMaximum()->_key << endl; 
  cout << "minimum of key is " << bST.getMinimum()->_key << endl; 
  cout << "successor of key " << tNode1->_key 
       << " is " << bST.getSuccessor(tNode1)->_key << endl; 
  cout << "predecessor of key " << tNode2->_key 
       << " is " << bST.getPredecessor(tNode2)->_key << endl; 

  printf("\nbefore deleting...");
  printf("in order tree walk...\n"); 
  bST.runInOrderTreeWalk(); 
  
  //bST.relocate(tNode2, tNode); 
  bST.treeDelete(tNode0); 
  bST.treeDelete(tNode1); 
  bST.treeDelete(tNode2); 
  bST.treeDelete(rootNode); 
  printf("\nafter deleting...");
  printf("in order tree walk...\n"); 
  bST.runInOrderTreeWalk();
  return 0;
}

int testRandomizedNumber() {
  srand(time(NULL));
  auto getRandomizedNumber = 
    [](int a, int b) { 
      return (rand()%(b-a+1)+a);
    };
  
  for (auto i=0; i<10; ++i)
    cout << getRandomizedNumber(0,9) << endl;
  
  return 0;
}

int testHashTable() {
  DSA::HashTable<int> hT;

  cout << hT.divHash(6, 4) << endl;
  assert(hT.divHash(6, 4)==2);
  
  cout << hT.multHash(6, 4, 0.8) << endl;
  

  const int k = 123456; 
  const int wBits = 32; 
  const int lBits = 14;
  const int long a = 2654435769;
  cout << hT.multShiftHash(k, wBits, lBits, a) << endl;
  cout << hT.multShiftHash(123456 /* k */, 
                          32 /* wBits */, 
                          14 /* lBits*/,
                          2654435769 /* a */) << endl;
  
  return 0;
}

int testLEETCODE() {
  //vector<int> nums{1,2,3,4,5,6,7};
  //int k = 3;
  //vector<int> nums{-1,-100,3,99};
  //int k = 2;
  //vector<int> nums{-1};
  //int k = 2;
  vector<int> nums{1,2};
  int k = 3;
  LEETCODE::rotate(nums, k);
  for (const auto& c : nums) cout << c << " ";
  cout << endl;

  //vector<int> nums1 {1,2,3,0,0,0};
  //int m = 3;
  //vector<int> nums2 {2,5,6};
  //int n = 3;

  //vector<int> nums1 {1};
  //int m = 1;
  //vector<int> nums2 {};
  //int n = 0;
  
  //vector<int> nums1 {0};
  //int m = 0;
  //vector<int> nums2 {1};
  //int n = 1;
  
  //vector<int> nums1 {2,0};
  //int m = 1;
  //vector<int> nums2 {1};
  //int n = 1;
  //
  //for (auto t : nums1) cout << t << " ";
  //cout << "\n m: " << m << endl;
  //
  //for (auto t : nums2) cout << t << " ";
  //cout << "\n n: " << n << endl;

  //LEETCODE::merge(nums1, m, nums2, n);
  //for (const auto& i : nums1) {
  //  cout << i << " ";
  //}
  //cout << endl;
 
  //vector<int> nums {3,2,2,3};
  //int val {3};
  
  //vector<int> nums {0,1,2,2,3,0,4,2};
  //int val {2};

  //cout << " number of non-val elements: " 
  //     << LEETCODE::removeElement(nums, val) << endl;
  //
  //for (const auto& i : nums) {
  //  cout << i << " ";
  //}
  //cout << endl;
  
  //vector<int> nums {0,0,1,1,1,2,2,3,3,4};
  //int size = LEETCODE::removeDuplicates(nums);
  //for (auto i=0;i<size;++i) {
  //  cout << nums[i] << " ";
  //}
  //cout << endl;
  
  //vector<int> nums {1,1,1};
  //vector<int> nums {1,2,2};
  //vector<int> nums {1,1,2,2};
  //vector<int> nums {1,1,1,2,2,3};
  //vector<int> nums {0,0,1,1,1,1,2,3,3};
  //int size = LEETCODE::removeDuplicates2(nums);
  //for (auto i=0;i<size;++i) {
  //  cout << nums[i] << " ";
  //}
  //cout << endl;
  
  //vector<int> nums {3,2,3};
  //vector<int> nums {2,2,1,1,1,2,2};
  //vector<int> nums {1,3,1,1,4,1,1,5,1,1,6,2,2};
  //cout << "running majorityElement...\n" 
  //     << LEETCODE::majorityElement(nums) << endl;

  return 0;
}

int testRBBinarySearchTree() {
  
  DSA::RBNode<int>* rbNode1 = new DSA::RBNode<int>(1, DSA::Color::Black);
  DSA::RBNode<int>* rbNode2 = new DSA::RBNode<int>(2, DSA::Color::Red);
  DSA::RBNode<int>* rbNode3 = new DSA::RBNode<int>(5, DSA::Color::Black);
  DSA::RBNode<int>* rbNode4 = new DSA::RBNode<int>(7, DSA::Color::Black);
  DSA::RBNode<int>* rbNode5 = new DSA::RBNode<int>(8, DSA::Color::Black);
  DSA::RBNode<int>* rbNode6 = new DSA::RBNode<int>(14, DSA::Color::Black);
  DSA::RBNode<int>* rbNode7 = new DSA::RBNode<int>(15, DSA::Color::Red);
  DSA::RBNode<int>* rbNode8 = new DSA::RBNode<int>(4, DSA::Color::Red);

  //DSA::RBBinarySearchTree<int> rbBst; // empty root
  DSA::RBBinarySearchTree<int> rbBst {11}; // root with key 11
  rbBst.rbInsert(rbNode1);
  rbBst.rbInsert(rbNode2);
  rbBst.rbInsert(rbNode3);
  rbBst.rbInsert(rbNode4);
  rbBst.rbInsert(rbNode5);
  rbBst.rbInsert(rbNode6);
  rbBst.rbInsert(rbNode7);
  rbBst.rbInsert(rbNode8);

  printf("\nIn order tree walk...\n");
  rbBst.inOrderTreeWalkRoot();
  printf("\n\n");
 
  printf("get minimum...\n");
  cout << rbBst.getMinimum()->_key << endl;
  printf("get maximum...\n");
  cout << rbBst.getMaximum()->_key << endl;
  
  printf("Removing nodes\n");
  //rbBst.rbDelete(rbNode1);
  //rbBst.rbDelete(rbNode2);
  //rbBst.rbDelete(rbNode4);
  rbBst.rbDelete(rbNode5);
  //rbBst.rbDelete(rbNode7);
  //rbBst.rbDelete(rbNode8);
  
  printf("\nIn order tree walk...\n");
  rbBst.inOrderTreeWalkRoot();
  printf("\n\n");

  return 0;
}

int testPatternMatching(const std::string& compStr ) {
  std::regex email_regex("[\\w.-]+@[\\w.-]+\\.[a-zA-Z]{2,4}");
  if (std::regex_match(compStr, email_regex)) {
    printf("Valid email address\n");
    return 0;
  }
  
  printf("Invalid email address\n");
  return 1;
}

void testFactoryMethod() {
  CREATIONAL_DP::CoffeeMakerFactory coffeeMaker;
  CREATIONAL_DP::Coffee* coffeePtr = coffeeMaker.getCoffee();
  if (coffeePtr==nullptr) {
    printf("Invalid drink\n");
  } else {
    printf("The drink is %s.\n",coffeePtr->getType());
  }
}

void testAbstractFactory() {
  CREATIONAL_DP::CarMakerFactory* carMaker;

  int choice;
  cout << "Select type of car factory: " << endl;
  cout << "1: Gas factory" << endl;                                
  cout << "2: Electric factory" << endl;                               
  cin >> choice;                                                
                                                                  
  switch (choice) {                                             
  case(1):                                                      
    carMaker = new CREATIONAL_DP::GasCarMakerFactory();                          
    break;                                          
  case(2):                                          
    carMaker = new CREATIONAL_DP::ElectricCarMakerFactory();                          
    break;
  default:
    carMaker = nullptr;  
    break;
  }

  if (carMaker!=nullptr) {
    CREATIONAL_DP::Door* aDoor = carMaker->buildDoor();
    aDoor->open();
    
    CREATIONAL_DP::Powertrain* aPowertrain = 
      carMaker->buildPowertrain();
    aPowertrain->start();
  }
}
  
void testBuilder() {
  CREATIONAL_DP::MealBuilder* cooker;
  CREATIONAL_DP::Meal* meal;
  
  int choice;
  cout << "Select a meal: " << endl;
  cout << "1: Hamburger Meal" << endl;                                
  cout << "2: Hotdog Meal" << endl;                               
  cin >> choice;                                                
                                                                  
  switch (choice) {                                             
  case(1):                                                      
    cooker = new CREATIONAL_DP::HamburgerMealBuilder();                          
    break;                                          
  case(2):                                          
    cooker = new CREATIONAL_DP::HotdogMealBuilder();                          
    break;
  default:
    cooker = nullptr;  
    break;
  }
  // building a complex Meal object
  cooker->cookEntree();
  cooker->cookSide();
  cooker->fillDrink();
  meal = cooker->getMeal();
 
  // show what are inside the meal
  meal->showItems();
  cout << "meal: " << meal << endl;

  CREATIONAL_DP::Meal meal2(*meal);
  meal2.showItems();
  cout << "&meal2: " << &meal2 << endl;
}

void testPrototype() {
  //
  CREATIONAL_DP::Sheep* sheep0 = new CREATIONAL_DP::Sheep;
  sheep0->setHariColor("white");
  sheep0->setTail(5);
  sheep0->setWeight(90);
  sheep0->setHeight(1);
  sheep0->setAge(5);
  cout << "Sheep 0...\n"; 
  sheep0->printProperty();
  
  CREATIONAL_DP::Cow* cow0 = new CREATIONAL_DP::Cow();
  cow0->setHariColor("brown");
  cow0->setTail(20);
  cow0->setWeight(790);
  cow0->setHeight(2);
  cow0->setAge(8);
  cout << "Cow 0...\n"; 
  cow0->printProperty();
  
  CREATIONAL_DP::Animal* farm[3];
  //
  farm[0] = sheep0->clone();
  cout << "Sheep 0 clone...\n"; 
  farm[0]->printProperty();
  
  farm[1] = cow0->clone();
  farm[1]->setWeight(1000);
  cout << "Cow 0 clone...\n"; 
  farm[1]->printProperty();
  
  sheep0->shearing();
  farm[2] = sheep0->clone();
  cout << "Shared Sheep 0 clone...\n"; 
  farm[2]->printProperty();

}

// Definition of the static member outside the class
CREATIONAL_DP::Leader* CREATIONAL_DP::Leader::_instance = nullptr;

void testSingleton() {
  CREATIONAL_DP::Leader* leader = CREATIONAL_DP::Leader::getInstance();
  leader->giveSpeech();

  //CREATIONAL_DP::Leader::getInstance()->giveSpeech();
  //CREATIONAL_DP::Leader::getInstance();
};

int testCreationalDP() {
  // singleton method
  testSingleton();
  
  // prototype method
  //testPrototype();
  
  // builder method
  //testBuilder();

  // abstract factory method
  //testAbstractFactory();
  
  // factory method
  //testFactoryMethod();
  
  return 0;
}
  
void testAdapterMethod() {
  typedef STRUCTURAL_DP::Component Component;
  typedef STRUCTURAL_DP::ConcreteComponentA ConcreteComponentA;
  typedef STRUCTURAL_DP::ConcreteComponentB ConcreteComponentB;
  typedef STRUCTURAL_DP::LegacyAdapter LegacyAdapter;
  typedef STRUCTURAL_DP::LegacyClassAdapter LegacyClassAdapter;

  const unique_ptr<Component> components[] {
    make_unique<ConcreteComponentA>()
  , make_unique<ConcreteComponentB>()
  , make_unique<LegacyAdapter>()
  , make_unique<LegacyClassAdapter>()
  };

  for (const auto& it : components) {
    it->run();
  }
};
  
void testBridgeMethod() {
  typedef STRUCTURAL_DP::PlainTextHandler PlainTextHandler;
  PlainTextHandler plainThr = PlainTextHandler();
  typedef STRUCTURAL_DP::EncryptedTextHandler EncryptedTextHandler;
  EncryptedTextHandler encryptedThr = EncryptedTextHandler();


  // create array of ptr to CloudStorage objects
  typedef STRUCTURAL_DP::ITextSharer ITextSharer;
  typedef STRUCTURAL_DP::EmailShare EmailShare;
  typedef STRUCTURAL_DP::EmailShareEncrypted EmailShareEncrypted;
  const std::unique_ptr<ITextSharer> sharingServices[] {
    make_unique<EmailShare>(plainThr),
    make_unique<EmailShareEncrypted>(encryptedThr),
  };

  // iterate thourgh the array and invoke uploadContents and 
  // getFreeSpace methods on each object
  const std::string content = "Beam me up, Scotty!";
  for (const auto& service : sharingServices) {
    service->shareText(content);
    cout << endl;
  }
};

  
void testCompositeMethod() {
  // create some products
  STRUCTURAL_DP::Book book1{"Robinson Crusoe", 4.99};
  STRUCTURAL_DP::Toy toy1{"Star Trooper", 39.99};
  STRUCTURAL_DP::Toy toy2{"Barbie Dreamhouse", 59.99};

  // create some boxes
  STRUCTURAL_DP::Box smallBox{"Small Box"};

  smallBox.addProduct(book1);
  smallBox.addProduct(toy1); 
  STRUCTURAL_DP::Box bigBox{"Big Box"};

  bigBox.addProduct(toy2);
  bigBox.addProduct(smallBox);

  cout << "Calculating total price. " << endl
       << bigBox.price() << endl;
};
  
void testDecoratorMethod() {
  auto desktop = new STRUCTURAL_DP::Desktop();
  cout << desktop->description() << " costs $ " << desktop->price() << endl;
  
  auto laptop = new STRUCTURAL_DP::Laptop();
  cout << laptop->description() << " costs $ " << laptop->price() << endl;
  
  auto desktopMemoryUpgrade = 
    new STRUCTURAL_DP::MemoryUpgradeDecorator(desktop);
  cout << desktopMemoryUpgrade->description() << " costs $ " 
       << desktopMemoryUpgrade->price() << endl;

  auto laptopGraphicsUpgrade = 
    new STRUCTURAL_DP::GraphicsUpgradeDecorator(laptop);
  cout << laptopGraphicsUpgrade->description() << " costs $ " 
       << laptopGraphicsUpgrade->price() << endl;

  delete desktop;
  delete laptop;
  delete desktopMemoryUpgrade;
  delete laptopGraphicsUpgrade;
};
  
void testFacadeMethod() {
  STRUCTURAL_DP::ReservationSystemFacade reservationSystemFacade;
  reservationSystemFacade.makeReservation(
      "Room reservation info",
      "Payment info"
      );
  /*
  // Not using Facade method
  STRUCTURAL_DP::Database db; 
  STRUCTURAL_DP::PaymentGateway paymentGateway; 
  STRUCTURAL_DP::MessagingService messagingService;

  db.storeReservation("Room reservation info");
  paymentGateway.processPayment("Payment info");
  messagingService.sendConfirmation("Reservation confirmed.");
  */
};
  
void testFlyweightMethod() {
  typedef STRUCTURAL_DP::Sprite Sprite;
  typedef STRUCTURAL_DP::SpriteFactory SpriteFactory;
  
  vector<Sprite*> sprites;
  const int numSprite = 10;
  const string textureFile = "spaceship.png";

  SpriteFactory factory;

  for (int i = 0; i < numSprite; ++i) {
    // Non flyweight method
    //sprites.push_back(new Sprite(10, 10, i*10, i*10, textureFile) );
  
    auto sprite = factory.makeSprite(textureFile);
    sprite->setPositionSize(10, 10, i*10, i*10);
    sprites.push_back(sprite);
  }
  
  // render/draw all sprites
  for (const auto& it : sprites) {
    it->render();
  }

  // cleanup
  //for (const auto& it : sprites) {
  //  delete(it);
  //}
}; 

void testProxyMethod() {
  
  // non-Proxy 
  //STRUCTURAL_DP::RealConfigFile configFile("./config.txt");
  
  STRUCTURAL_DP::ConfigFileProxy configFile("./config.txt");
  
  bool useSettings = true;

  if (useSettings) {
    vector<string> settings = configFile.getSettings();
    string data{};

    for (const auto& setting : settings) {
      //cout << setting << endl;
      data+=(setting+"\n");
    }
  
    //STRUCTURAL_DP::SecureStorage secureStorage
    //  = STRUCTURAL_DP::SecureStorage(data);
    STRUCTURAL_DP::SecureStorageProxy secureStorage
      = STRUCTURAL_DP::SecureStorageProxy(data);
    cout << secureStorage.getContents() << endl;

  } else {
    cout << "Configuration not used." << endl;
  }

};

int testStructuralDP() {
  // flyweight  method
  testProxyMethod();
  
  // flyweight  method
  //testFlyweightMethod();
  
  // facade  method
  //testFacadeMethod();
  
  // decorator  method
  //testDecoratorMethod();
  
  // composite method
  //testCompositeMethod();
  
  // bridge method
  //testBridgeMethod();
  
  // adapter method
  //testAdapterMethod();
  
  return 0;
};

void testChainOfResponsibilityMethod() {
  typedef BEHAVIORIAL_DP::BaseValidator BaseValidator;
  typedef BEHAVIORIAL_DP::NotEmptyValidator NotEmptyValidator;
  typedef BEHAVIORIAL_DP::RegexValidator RegexValidator;
  typedef BEHAVIORIAL_DP::LengthValidator LengthValidator;
  typedef BEHAVIORIAL_DP::HistoryValidator HistoryValidator;

  std::vector<std::string> oldPasswords = { 
    "abc123", "123456", "hello", "hello@test.com" 
  };    

  BaseValidator* emailValidator = new BaseValidator;                          

  emailValidator->setNext(new NotEmptyValidator)
                ->setNext(new RegexValidator("email address", "^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"))
                ->setNext(new LengthValidator(10))
                ->setNext(new HistoryValidator(oldPasswords)); 
  
  std::cout << "Checking Emails ---------------\n";                       
  std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";     
  std::cout << "Input: hello\n" << emailValidator->validate("hello") << "\n\n";
  std::cout << "Input: hello@test.com\n" << emailValidator->validate("hello@test.com") << "\n\n";
  std::cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
  std::cout << "Input: shaun@test.com\n" << emailValidator->validate("shaun@test.com") << "\n\n";

  delete emailValidator;
};

std::string vectorToString(std::vector<std::string> v) {
  std::string result = "";
  for (const auto& i : v) {
    result.append(i + ", ");
  }
  return result;
};

void testCommandMethod() {
  typedef BEHAVIORIAL_DP::Canvas Canvas;
  typedef BEHAVIORIAL_DP::Button Button;
  typedef BEHAVIORIAL_DP::AddShapeCommand AddShapeCommand;
  typedef BEHAVIORIAL_DP::ClearCommand ClearCommand;
  
  Canvas* canvas = new Canvas;
  Button* addTriangleButton = new Button( new 
      AddShapeCommand("triangle", canvas));
  Button* addSquareButton = new Button( new 
      AddShapeCommand("square", canvas));
  Button* clearButton = new Button( new ClearCommand(canvas));

  addTriangleButton->click();
  std::cout << "Current canvas state: " <<
    vectorToString(canvas->getShapes()) << "\n";
  addSquareButton->click();
  addSquareButton->click();
  addTriangleButton->click();
  std::cout << "Current canvas state: " <<
    vectorToString(canvas->getShapes()) << "\n";
  clearButton->click();
  std::cout << "Current canvas state: " <<
    vectorToString(canvas->getShapes()) << "\n";
  delete canvas;
};
  
void testMediatorMethod() {
  typedef BEHAVIORIAL_DP::UserInterface UserInterface;
  UserInterface* ui = new UserInterface;
  
  BEHAVIORIAL_DP::InterfaceElement* elements[] = {
    ui->getNameTextBox(),
    ui->getIsMarriedCheckBox(),
    ui->getSpousesNameTextBox(),
    ui->getSubmitButton()
  };

  for (auto element: elements) {
    std::cout << element->getDescription() << "\n";
  }

  ui->getIsMarriedCheckBox()->setIsChecked(true);
  
  for (auto element: elements) {
    std::cout << element->getDescription() << "\n";
  }

};
  
void testObserverMethod() {
  typedef BEHAVIORIAL_DP::ChatUser ChatUser;
  ChatUser* user1 = new ChatUser("Jim");
  ChatUser* user2 = new ChatUser("Barb");
  ChatUser* user3 = new ChatUser("Hannah");

  typedef BEHAVIORIAL_DP::ChatGroup ChatGroup;
  ChatGroup* group1 = new ChatGroup("Gardening group");
  ChatGroup* group2 = new ChatGroup("Dog-lovers group");

  group1->subscribe(user1);
  group1->subscribe(user2);
  
  group2->subscribe(user2);
  group2->subscribe(user3);
  
  group1->publish("Special sale on gardening supplies!");
  group2->publish("It's national dog day everyong!");

  delete user1;
  delete user2;
  delete user3;
  delete group1;
  delete group2;
};
  
void testInterpreterMethod() {
  typedef BEHAVIORIAL_DP::NumberExpression NumberExpression;
  typedef BEHAVIORIAL_DP::OperationExpression OperationExpression;
  
  NumberExpression* five = new NumberExpression("5");
  NumberExpression* seven = new NumberExpression("7");
  OperationExpression* fivePlusSeven = new 
    OperationExpression("+", five, seven);

  cout << "Five plus seven is: " 
       << fivePlusSeven->evaluate()
       << "\n";

  NumberExpression* thirteen = new NumberExpression("13");
  OperationExpression* complexOp = new 
    OperationExpression("-", thirteen, fivePlusSeven);
  
  cout << "13 - ( 5 + 7) = " 
       << complexOp->evaluate()
       << "\n";
  
  OperationExpression* complexOp2 = new 
    OperationExpression("*", thirteen, fivePlusSeven);
  
  cout << "13 * ( 5 + 7) = " 
       << complexOp2->evaluate()
       << "\n";


  delete five;
  delete seven;
  delete fivePlusSeven;
};
  
void testStateMethod() {
  typedef BEHAVIORIAL_DP::DeliveredState DeliveredState;
  typedef BEHAVIORIAL_DP::InTransitState InTransitState;
  typedef BEHAVIORIAL_DP::PurchasedState PurchasedState;
  typedef BEHAVIORIAL_DP::Purchase Purchase;

  DeliveredState* deliveredState = new DeliveredState(nullptr);
  InTransitState* inTransitState = new InTransitState(deliveredState);
  PurchasedState* purchasedState = new PurchasedState(inTransitState);

  Purchase* purchase = new Purchase("Shoes", purchasedState);
  cout << purchase->getDescription() << "\n";

  purchase->goToNextState();
  cout << purchase->getDescription() << "\n";
  
  purchase->goToNextState();
  cout << purchase->getDescription() << "\n";

  delete deliveredState;
  delete inTransitState;
  delete purchasedState;
  delete purchase;
};

void testStrategyMethod() {
  typedef BEHAVIORIAL_DP::Person Person;
  typedef BEHAVIORIAL_DP::FormalGreetingStrategy FormalGreetingStrategy;
  typedef BEHAVIORIAL_DP::NormalGreetingStrategy NormalGreetingStrategy;
  typedef BEHAVIORIAL_DP::InformalGreetingStrategy InformalGreetingStrategy;

  Person businessPerson(new FormalGreetingStrategy());  
  Person normalPerson(new NormalGreetingStrategy());  
  Person coolPerson(new InformalGreetingStrategy());  
  Person politician(new FormalGreetingStrategy());

  const std::string& name = "Shaun";

  cout << "The businessperson says: ";
  businessPerson.greet(name);  
  
  cout << "The normal person says: ";
  normalPerson.greet(name);  
  
  cout << "The cool person says: ";
  coolPerson.greet(name);  
  
  cout << "The politician says: ";
  politician.greet(name);  

};
  
void testTemplateMethod() {
  typedef BEHAVIORIAL_DP::GreetingCardTemplate GreetingCardTemplate;
  typedef BEHAVIORIAL_DP::BirthdayCardTemplate BirthdayCardTemplate;
  typedef BEHAVIORIAL_DP::NewYearCardTemplate NewYearCardTemplate;

  GreetingCardTemplate gct;
  BirthdayCardTemplate bct;
  NewYearCardTemplate nct;

  const std::string addresseeName = "Michael";
  const std::string senderName = "Jordan";

  cout << "Here is a regular greeting card:\n\n" 
       << gct.generate(addresseeName, senderName);
  cout << "Here is a birthday card:\n\n" 
       << bct.generate(addresseeName, senderName);
  cout << "Here is a new year's card:\n\n" 
       << nct.generate(addresseeName, senderName);
};
  
void testVisitorMethod() {
  typedef BEHAVIORIAL_DP::DatabaseVisitor DatabaseVisitor;
  typedef BEHAVIORIAL_DP::TextFileVisitor TextFileVisitor;
  typedef BEHAVIORIAL_DP::PersonV PersonV;
  typedef BEHAVIORIAL_DP::LandmarkV LandmarkV;
  typedef BEHAVIORIAL_DP::CarV CarV;

  DatabaseVisitor* dBV = new DatabaseVisitor;
  TextFileVisitor* tFV = new TextFileVisitor;

  const std::string name = "Michael";
  const int age = 23;
  PersonV  player(name, age);
  player.accept(dBV);

  const std::string state = "Ohio";
  const std::string cityName = "Pickerington";
  LandmarkV  place(state, cityName);
  place.accept(tFV);

  const std::string make = "Porsche";
  const std::string model = "911 Turbo s";
  CarV  car(make, model);
  car.accept(dBV);

  delete dBV;
  delete tFV;
};
  
void testIteratorMethod() {
  typedef BEHAVIORIAL_DP::NumberIterator NumberIterator;
  typedef BEHAVIORIAL_DP::NumberCollection NumberCollection;

  std::vector<int> numbers {1,2,3,4,5,6,7};
  NumberCollection nc(numbers);
  NumberIterator* fi = nc.getForwardsIterator();
  NumberIterator* bi = nc.getBackwardsIterator();

  cout << "\n\nIterating through the numbers forwards:\n";
  while (!fi->isFinished()) cout << fi->next() << ",";
  cout << "\n\nIterating through the numbers backwards:\n";
  while (!bi->isFinished()) cout << bi->next() << ",";
  cout << "\n";

  delete fi;
  delete bi;
};
  
void testMementoMethod() {
  typedef BEHAVIORIAL_DP::CanvasM Canvas;
  Canvas* canvas = new Canvas;

  canvas->addShape("rhombus");
  canvas->addShape("triangle");
  canvas->addShape("square");
  canvas->addShape("circle");

  for (auto shape : canvas->getShapes()) {
    cout << shape << ", ";
  }
  cout << "\n"; 

  canvas->undo();

  for (auto shape : canvas->getShapes()) {
    cout << shape << ", ";
  }
  cout << "\n"; 
  
  canvas->addShape("rhombus");
  canvas->addShape("triangle");
  canvas->addShape("square");
  canvas->addShape("circle");
  canvas->undo();

  for (auto shape : canvas->getShapes()) {
    cout << shape << ", ";
  }
  cout << "\n"; 

  delete canvas;
};
  
void testNullObjectMethod() {
  typedef BEHAVIORIAL_DP::SomeTask SomeTask;
  typedef BEHAVIORIAL_DP::ConsoleLogger ConsoleLogger;
  typedef BEHAVIORIAL_DP::FileLogger FileLogger;
  typedef BEHAVIORIAL_DP::ApiLogger ApiLogger;

  SomeTask task1(new ConsoleLogger);
  SomeTask task2(new FileLogger("logs.txt"));
  SomeTask task3(new ApiLogger("loggingsite.com/api/logs"));
  SomeTask task4;

  task1.execute();
  task2.execute();
  task3.execute();
  task4.execute();
};

int testBehavioralDP() {
  // Null object method
  testNullObjectMethod();
  
  // Memento method
  //testMementoMethod();
  
  // Iterator method
  //testIteratorMethod();
  
  // Visitor method
  //testVisitorMethod();
  
  // Template method
  //testTemplateMethod();

  // Strategy method
  //testStrategyMethod();
  
  // State method
  //testStateMethod();
  
  // Interpreter  method
  //testInterpreterMethod();
  
  // Observer method
  //testObserverMethod();
  
  // Mediator method
  //testMediatorMethod();
  
  // Command method
  //testCommandMethod();
  
  // Chain of responsibility method
  //testChainOfResponsibilityMethod();
  
  return 0;
};

int main() {
  
  assert(testBehavioralDP()==0);
  
  //assert(testStructuralDP()==0);
  
  //assert(testCreationalDP()==0);
  
  //assert(testPatternMatching("williams19834812@gmail.com")==0);

  //assert(testRBBinarySearchTree()==0);
 
  //assert(testLEETCODE()==0);
  
  //assert(testRandomizedNumber()==0);
  
  //assert(testBinarySearchTree()==0);
  
  //assert(testPriorityQueue()==0);
  
  //assert(testBitwiseOperation()==0);

  //assert(testQueue()==0);

  //assert(testBrowseHistory()==0);

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
