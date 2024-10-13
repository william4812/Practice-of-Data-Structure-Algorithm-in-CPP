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
#include <regex>
#include <stdlib.h> /* atoi */
#include <string>
#include <typeinfo>
#include <unordered_map>
#include <utility> /* std::pair, std::make_pair, move */
#include <vector>

using namespace std;

#ifndef HEADER_H_SOLUTION
#define HEADER_H_SOLUTION



namespace DSALG {


  /* SLink for singly linked list 
   * This class also serves a base class
   * for doubly linked list */ 
  template <typename T>
  struct SLink {
    T _value;
    SLink* _next;
    /* ctor */
    SLink(const T& value=0):_value(value), _next(nullptr) {
      //printf("Resource Acquisition Is Initialization.\n");
      //cout << "SLink of value: " << _value << endl;
    };
    /* dtor */
    ~SLink() {
      //printf("Deallocation...\n");
      //cout << "SLink of value: " << _value << endl;
    }
  };


  /* DLink for doubly link derived from SLink */
  template <typename T>
  struct DLink : public SLink<T> {
    DLink* _prev;
    
    /* ctor */
    DLink(const T& value): SLink<T>(value) {
      _prev = nullptr;
      printf("Resource Acquisition Is Initialization.\n");
      cout << "DLink of value: " << SLink<T>::_value << endl;
    };
    /* dtor */
    ~DLink() {
      printf("Deallocation...\n");
      cout << "DLink of value: " << SLink<T>::_value << endl;
    }
  };


  /* doubly linked list */
  template <typename T>
  class DLinkedList {
  private:
    DLink<T>* _head;
  
  public:
    /* ctor */
    DLinkedList():_head(nullptr) {
      printf("Resource Acquisition Is Initialization.\n");
      cout << "DLinkedList" << endl;
    };
    /* dtor */
    ~DLinkedList() {
      printf("Deallocation of linkedlist\n");
    };
    
    DLink<T>* searchLink(const T& value);
    void prependLink(const T& value);
    void insertLink(const T& newValue, const T& refValue);
    void deleteLink(const T& deletedValue);
    void showKeys();
  };
 

  template <typename T>
  DLink<T>* DLinkedList<T>::searchLink(const T& value) {
    if (this->_head == nullptr) {
      printf("Empty linked list\n");
      return nullptr;
    }
    
    /* assign _head ptr to tempLink*/
    DLink<T>* tempLink = this->_head;

    while (tempLink != nullptr) {
      /* check if link of key is found */
      if (tempLink->_value == value) {
        cout << "found link of key of " << value << endl;
        return tempLink; // found a link with key value
      }
      tempLink = static_cast<DLink<T>*>(tempLink->_next);
    }
    /* found no link matching key*/     
    cout << "No link matching key of " << value << endl; 
    return nullptr;
  };

  template <typename T>
  void DLinkedList<T>::prependLink(const T& value) {
    DLink<T>* tempLink = new DLink<T>(value);
    //cout << tempLink->_value << endl;

    /* update what pointer points */
    
    /* assign original value pointed by _head to tempLink->_next */
    tempLink->_next = this->_head;
    
    /* assign nullptr as head of list to tempLink->_prev */
    tempLink->_prev = nullptr; 

    /* assign tempLink to this->_head->_prev*/
    if (this->_head!=nullptr) {
      this->_head->_prev = tempLink;
    }

    /* assign new tempLink to what _head points */
    this->_head = tempLink; // head pointing to a new DLink
  };

  template <typename T>
  void DLinkedList<T>::insertLink(const T& newValue,
      const T& refValue) {
    /*search link of refValue*/
    DLink<T>* refLink = this->searchLink(refValue);

    /* link of value not found */
    if (refLink==nullptr) return;

    /* create a new link of newValue */
    DLink<T>* newLink = new DLink<T>(newValue);

    /* update the _next and _prev of nearby links 
     * newLink is connected next to refLink */
    
    /* assign refLink's next to newLink's next */
    newLink->_next = refLink->_next; 
    
    /* assign refLink's next's prev to newLink's prev */
    newLink->_prev = refLink; 
    
    /* assigne newLink to refLink's _next's _prev*/
    if (refLink->_next!=nullptr) { 
      static_cast<DLink<T>*>(refLink->_next)->_prev = 
        newLink;
    }
    /* assign newLink to refLink's next */
    refLink->_next = newLink;
  }
  
  template <typename T>
  void DLinkedList<T>::deleteLink(const T& deletedValue) {
    
    DLink<T>* deletedLink = this->searchLink(deletedValue);
    
    /* no link of deletedValue is found*/
    if (deletedLink == nullptr) return;
      
    //cout << static_cast<DLink<T>*>(deletedLink->_next)->_prev->_value << endl;
    cout << deletedLink->_value << endl;

    /* update _prev and _next of nearby links */

    /* assign deletedLink's _prev's _next to deletedLink's _next */
    if (deletedLink->_prev != nullptr) {
      deletedLink->_prev->_next = deletedLink->_next;
    } /*deletedLink->_prev is pointed by _head*/ else {
      this->_head = static_cast<DLink<T>*>(deletedLink->_next);
    }

    /* assign deletedLink's _next's _prev to deletedLink's _prev */
    if (deletedLink->_next != nullptr) {
      static_cast<DLink<T>*>(deletedLink->_next)->_prev = 
        deletedLink->_prev;
    }
    
    /* deallocate the memory of deletedLink */
    delete deletedLink;
  }

  template <typename T>
  void DLinkedList<T>::showKeys() {
    if (this->_head == nullptr) {
      printf("Empty linked list\n");
      return;
    }

    /* assign _head ptr to tempLink*/
    DLink<T>* tempLink = this->_head;

    while (tempLink != nullptr) {
      cout << tempLink->_value << " ";
      
      /* assign _next to tempLink */
      tempLink = static_cast<DLink<T>*>(tempLink->_next);
    }
    cout << endl;
  }


/* The template class and functions are defined in 
 * the same .h file. 
 * More advanded setting is needed to separate defintion 
 * to .cpp for template class and functions */
  template <typename T>
  class ArrayLikeDsAlg {
  public:
    /* ctor */
    ArrayLikeDsAlg() {};

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
    
    void heapSort(T arr[], const int& arrSize);
    int parent(const int& curIndex) {return (curIndex>>1);};   
    int leftChild(const int& curIndex) {return (curIndex<<1);};   
    int rightChild(const int& curIndex) {return ((curIndex<<1)+1);};   
    void maxHeapify(T arr[], const int& curIndex, const int& arrSize);
    void buildMaxHeap(T arr[], const int& arrSize);

    void quickSort(T arr[], const int& arrSize);
    void runQuickSort(T arr[], 
        const int& leftIndex, 
        const int& rightIndex);
    int getPivotIndex(T arr[], 
        const int& leftIndex,
        const int& rightIndex);
    int getRandomizedNumber(const int& iniNum,
                            const int& endNum) {
      srand(time(NULL));
      auto randNum = [](int a, int b) {
        return (rand()%(b-a+1)+a);
      };
      
      return randNum(iniNum, endNum);
    };

    void countingSort();
    void radixSort();
    void bucketSort();

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
      
    /* O(log n) time complexity
     * Divide and conquer recurrsively subarrays */
    int midIndex = leftIndex + 0.5*(rightIndex-leftIndex);
    runMergeSort(arr, leftIndex, midIndex);
    runMergeSort(arr, midIndex+1, rightIndex);

    /* O(n) time complexity
     * Merge the subarrays */
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
  
  /* heap sort runs O(nlon n) time complexity i
   * O(n): buildMaxHeap
   * O(log n): maxHeapify */
  template <typename T>
  void ArrayLikeDsAlg<T>::heapSort(T arr[], const int& arrSize){
    /* converts an array arr[0:arrSize-1] into a max-heap */ 
    buildMaxHeap(arr, arrSize);
    
    /* In each iteration, moving root element (maximum at arr[0]) 
     * of arr[0:arrSize-1] to arr[arrSize-1], and then for next
     * iteration, heapify arr[0:arrSize-2] and move the next 
     * max or root to arr[arrSize-2] in recurrsive manner till 
     * arr[1] */
    for (auto i=arrSize-1; i>0; --i) {
      /* move root toward the end of heap*/
      swap(arr[0]/*root*/, arr[i]);
      
      /* heapify again for smaller arr[0:i]*/
      maxHeapify(arr, 0/*root index*/, i/*new heap size*/);
    }
  }

  /* O(n) time complexity 
   * helper function buildMaxHeap converts an array A[1 : n] or
   * arr[0:arrSize-1] into a max-heap by calling maxHeapify in 
   * a Bottom-Up manner.
   * 
   * Ouput: the maximum element of the array is stored at      
   * the root arr[0]
   *
   * A[ floor(n>>2)+1:n ] are leave nodes as 1-element heap
   * A[ 1:floor(n>>2) ] are internal nodes running maxHeapify
   * 
   * */
  template <typename T>  
  void ArrayLikeDsAlg<T>::buildMaxHeap(T arr[], 
      const int& arrSize /*size as one-based index*/) {
    
    for (auto i=(floor(arrSize>>1)-1)/*zero-based index*/; i>=0; --i ) {
      maxHeapify(arr, i, arrSize);
    }
  }

  /* O(log n) time complexity
   * helper function maintain max heap property
   * A[parent(index)]>=A[index] */  
  template <typename T>
  void ArrayLikeDsAlg<T>::maxHeapify(T arr[], 
      const int& curIndex,
      const int& arrSize) {
    //cout << arr[curIndex] << endl;
    
    /* indices is converted based on one-based index */
    //auto parentIndex = parent(curIndex+1) - 1;
    auto leftChildIndex = leftChild(curIndex+1) - 1;
    auto rightChildIndex = rightChild(curIndex+1) - 1;
    auto largestIndex = curIndex;

    /* check if
     * 1. left child index (one-based) within array/heap size 
     * 2. leftChild has larger value than curIndex */
    if ((leftChildIndex+1) <= arrSize and 
        arr[leftChildIndex] > arr[curIndex]) {
      largestIndex = leftChildIndex;
    } 
    
    /* check if 
     * 1. right child index (one-based) within array/heap size 
     * 2. rightChild has larger value than the updated 
     * largest value at largestIndex */
    if ((rightChildIndex+1) <= arrSize and 
        arr[rightChildIndex] > arr[largestIndex]) {
      largestIndex = rightChildIndex; 
    }

    /* check if the largest is not at curIndex */
    if (largestIndex!=curIndex) {
      
      /* swap the largest value with value at curIndex */
      swap(arr[curIndex], arr[largestIndex]);

      /* moving to the current largest index to heapify */
      maxHeapify(arr, largestIndex, arrSize);
    }
  }
   
  /* O(n^2) time complexity
   * quick sort has swap step in divide (partition) 
   * */ 
  template <typename T>
  void ArrayLikeDsAlg<T>::quickSort(T arr[], 
      const int& arrSize){
    runQuickSort(arr, 0, arrSize-1/*index*/);
  }
  
  template <typename T>
  void ArrayLikeDsAlg<T>::runQuickSort(T arr[],
     const int& leftIndex,
     const int& rightIndex) {
    
    if (leftIndex > rightIndex) return;

    /* get pivotIndex with 
     * elements arr[leftIndex: pivotIndex-1] <= arr[pivotIndex]
     * elements arr[pivotIndex+1:rightIndex] > arr[pivotIndex]*/
    int pivotIndex = getPivotIndex(arr, leftIndex, rightIndex);
    
    /* subarray Left to pivotIndex */
    runQuickSort(arr, leftIndex, pivotIndex-1);
    
    /* subarray Right to pivotIndex */
    runQuickSort(arr, pivotIndex+1, rightIndex);
  } 

  template <typename T>
  int ArrayLikeDsAlg<T>::getPivotIndex(T arr[],
     const int& leftIndex,
     const int& rightIndex) {
    /* Set initial  pivot index */
    // randomization
    auto j = getRandomizedNumber(leftIndex, rightIndex); // rightIndex may be changed 
    swap(arr[j], arr[rightIndex]);
    
    auto pivotIndex = rightIndex; // rightIndex may be changed 
    auto pivotLeft = leftIndex-1; // index left to pivot

    /* browse elements in arr[0:r-1] */
    for (auto i=leftIndex; i<rightIndex; ++i) {
      
      /* element smaller than pivot */
      if (arr[i]<=arr[pivotIndex]) {
        /*move smaller element right to pivotLeft*/
        swap(arr[i], arr[++pivotLeft]);
      }
    }

    /* move pivot to arr[pivotLeft+1] */
    swap(arr[pivotLeft+1], arr[pivotIndex]);
    return (pivotLeft+1); 
  }
    
  /* Show array elements */ 
  template <typename T>
  void ArrayLikeDsAlg<T>::showArray(T arr[], const int& arrSize) {
    for (auto i=0; i<arrSize; ++i) {
      cout << arr[i] << " ";
    }
    cout << "\n";
  }

  /* class Stack is LIFO data structure 
   * inheriting from vector class */
  template <typename T>
  class Stack : public vector<T> {
  public:
    /* ctor */
    Stack():_topIndex(-1), _vec(new vector<T>) {};
    ~Stack() {delete[] _vec;};
    void push(const T& value);
    void pop();
    T getTop();
    bool isEmpty();

  private:
   int _topIndex;
   vector<T>* _vec;
  };

  
  /* push a value, incrementing _topIndex, 
   * at the top of stack */
  template <typename T>
  void Stack<T>::push(const T& value) {
    ++_topIndex;
    //cout << "element " << value 
    //     << " is pushed at _topIndex " << (_topIndex) << endl;
    this->_vec->push_back(value);
  }
  
  /* pop a value from top of a stack, then decrementing _topIndex */
  template <typename T>
  void Stack<T>::pop() {
    /* pop only if stack is Not empty */
    if (!isEmpty()) {
     this-> _vec->pop_back();
      --_topIndex;
      return;
    }
    cout << "Empty stack! No element to pop...\n";
  }
  
  /* pop a value from top of a stack, then decrementing _topIndex */
  template <typename T>
  T Stack<T>::getTop() {
    /* getTop only if stack is Not empty */
    if (!isEmpty()) return (this->_vec->at(_topIndex));
    
    cout << "Empty stack! No element at top\n";
    exit(-1);
  }
  
  /* check if stack is empty */
  template <typename T>
  bool Stack<T>::isEmpty() {
    return ((_topIndex>-1)?false:true);
  }

  
  /* class Stack: implementation of LIFO data structure */
  template <typename T>
  class BrowseHistory  {
  public:
    BrowseHistory() : _urlHistoryStackPtr(new Stack<T>) {};
    void visit(const T& url) {_urlHistoryStackPtr->push(url);};
    void back() {_urlHistoryStackPtr->pop();};
    T current() const {
      if (_urlHistoryStackPtr->isEmpty() ) {
        cout << "No sites currently being viewed!\n";
        exit(-1);
      }
      return _urlHistoryStackPtr->getTop();
    };
  
  private:
    std::string _url;
    Stack<T>* _urlHistoryStackPtr;
  };

 
  /* class Queue: implementation of FIFO data structure */
  template <typename T>
  class Queue {
  private:
    int _headIndex;
    int _tailIndex;
    int _size;
    int _capacity;
    std::vector<T>* _vecPtr;

  public:
    /* ctor of one arg */
    Queue(const int& capacity=12): 
      _headIndex(0), _tailIndex(0), _size(0), _capacity(capacity),
      _vecPtr(new vector<T>(capacity)) {};
    
    bool isFull() {
      if (_size == _capacity) {
        return true;
      }
      return false;
    };

    bool isEmpty() {return ((_size==0)?true:false);};

    void enqueue(const T& value) {
      if (isFull()) {
        cout << "Queue is full\n";
        return;
      }
      _vecPtr->at(_tailIndex++)=value;
      cout << "value: " << value << " at " << _tailIndex-1 << endl;
      _tailIndex%=_capacity;
      ++_size;
      //cout << "_size: " << _size << endl;
    };
    
    T dequeue() {
      T dequeuedValue = _vecPtr->at(_headIndex++);
      _headIndex%=_capacity;
      --_size;
      cout << "_size: " << _size << endl;
      return dequeuedValue;
    };

    T getFront() {return _vecPtr->at(_headIndex);};
    
  };


  /* Priority Queue */
  template <typename T>
  struct TaskKey {
    std::string _task;
    T _key;
    /* ctor */
    TaskKey() {}; 
    TaskKey(const std::string& task, const T& key):_task(task), _key(key) {};
  };

  template <typename T>
  class PriorityQueue:public Queue<T> {
  public:
    PriorityQueue(const T& taskKey): _taskKey(taskKey) {};
    void insert(const T& taskKey);
    T getMaximum();
    void extractMaximum();
    void increaseMaximum();
  private:
    T  _taskKey;
  };

  
  template <typename T>
  T PriorityQueue<T>::getMaximum() {
    return _taskKey;
  }

  template <typename T>
  void PriorityQueue<T>::insert(const T& taskKey) {
    //Queue<T>::enqueue(taskKey);
  }


  /* A Node for Binary Search Tree
   * has attributes Parent, leftChild, and rightChild
   * */
  template <typename T>
  struct Node {
  T _key; // value store in a Node
  Node* _parent; // parent node pointer
  Node* _leftChild; // left-child node pointer
  Node* _rightChild; // right-child node pointer
  /* ctor */
  Node():_parent(nullptr), 
         _leftChild(nullptr), 
         _rightChild(nullptr) 
    { printf("RAII: a node is created\n"); };
  Node(const T& key):_key(key), 
                     _parent(nullptr), 
                     _leftChild(nullptr), 
                     _rightChild(nullptr) 
    { cout << "RAII: a node of key "
                                      << _key
                                      << " is allocated.\n"; };
  /* dtor */
  ~Node() { cout << "RAII: a node of key "
                 << _key
                 << " is de-allocated.\n"; };
  };


  /* Binary Search Tree (BST)
   * is a Organized data strcture
   *
   * binary-search-tree property:
   * Let x be a node in a binary search tree. 
   * If y is a node in the left subtree of x, then y.key ≤ x.key. 
   * If y is a node in the right, subtree of x, then y.key ≥ x.key.
   * */
  template <typename T>
  class BinarySearchTree {
  public:
    /* ctor */
    BinarySearchTree():_root(nullptr) {
      printf("RAII: a binary search tree is allocated\n");
    };
    BinarySearchTree(Node<T>* nodePtr):_root(nodePtr) {
      cout << "RAII: a binary search tree of root with key "
           << nodePtr->_key
           << " is allocated\n";
      _root->_parent = nullptr; // root's parent is nullptr
    };
    ~BinarySearchTree() {
      cout << "RAII: a binary search tree of root with key "
           << this->_root->_key
           << " is de-allocated\n"; 
      delete _root;
    };
    void runInOrderTreeWalk() const;
    void runPreOrderTreeWalk() const;
    void runPostOrderTreeWalk() const;
    void inOrderTreeWalk(const Node<T>* node) const;
    void preOrderTreeWalk(const Node<T>* node) const;
    void postOrderTreeWalk(const Node<T>* node) const;
    void treeInsert(Node<T>* node);
    void treeDelete(Node<T>* node);
    void relocate(
        Node<T>* deletedNode, Node<T>* substituteNode);
    
    const Node<T>* iterativeTreeSearch(const Node<T>* node) const; 
    Node<T>* getMaximum() const; 
    Node<T>* maximum(Node<T>* aRoot) const; 
    Node<T>* getMinimum() const; 
    Node<T>* minimum(Node<T>* aRoot) const; 
    Node<T>* getSuccessor(Node<T>* node) const; 
    Node<T>* getPredecessor(Node<T>* node) const; 
  
  private:
    Node<T>* _root; // root node pointer of BST

  };

  
  template <typename T>
  void BinarySearchTree<T>::runInOrderTreeWalk() const {
    inOrderTreeWalk(this->_root);
    cout << "\n"; 
  };
  
  template <typename T>
  void BinarySearchTree<T>::runPreOrderTreeWalk() const {
    preOrderTreeWalk(this->_root);
    cout << "\n"; 
  };
  
  template <typename T>
  void BinarySearchTree<T>::runPostOrderTreeWalk() const {
    postOrderTreeWalk(this->_root);
    cout << "\n"; 
  };
  
  template <typename T>
  void BinarySearchTree<T>::inOrderTreeWalk(
      const Node<T>* node) const {
    if (node != nullptr) {
      inOrderTreeWalk(node->_leftChild);
      cout << node->_key << " ";
      inOrderTreeWalk(node->_rightChild);
    }
  };
  
  template <typename T>
  void BinarySearchTree<T>::preOrderTreeWalk(
      const Node<T>* node) const {
    if (node != nullptr) {
      cout << node->_key << " ";
      preOrderTreeWalk(node->_leftChild);
      preOrderTreeWalk(node->_rightChild);
    }
  };
  
  template <typename T>
  void BinarySearchTree<T>::postOrderTreeWalk(
      const Node<T>* node) const {
    if (node != nullptr) {
      postOrderTreeWalk(node->_leftChild);
      postOrderTreeWalk(node->_rightChild);
      cout << node->_key << " ";
    }
  };

  template <typename T>
  void BinarySearchTree<T>::treeInsert(Node<T>* node) {
    Node<T>* curNode = _root;
    Node<T>* curParent = nullptr;
    
    /* descend from _root node*/
    while (curNode!=nullptr) {
      curParent = curNode; // curNode become new curParent
      
      /* check node's key with curNode's key*/
      if (node->_key < curNode->_key) {
        curNode = curNode->_leftChild;
      } else {
        curNode = curNode->_rightChild;
      }
    }

    /* node's parent is updated */
    node->_parent = curParent;
    
    if (curParent == nullptr) {
      _root = node;
    } else if (node->_key < curParent->_key) {
      curParent->_leftChild = node;
    } else {
      curParent->_rightChild = node;
    }
  };

  /*
   * 3 cases
   * 1. if curNode has No children, remove curNode simply
   * 2. if curNode has one child, elevate that child to 
   * take the position of curNode
   * 3. curNode has two children -> rightChild as the 
   * successor of curNode or -> successor of curNode
   * is at the right subtree*/
  template <typename T> 
  void BinarySearchTree<T>::treeDelete(Node<T>* node) {
    cout << "deleting node of " << node->_key << endl;
    
    // case 1. and case 2.
    // node's rightChild as nullptr
    if (node->_rightChild==nullptr) {
      this->relocate(node, node->_leftChild);
    } 
    // node's leftChild as nullptr
    else if (node->_leftChild==nullptr) {
      this->relocate(node, node->_rightChild);
    }
    // case 3.
    else if (Node<T>* successorNode=this->getSuccessor(node)) {
      // succeesor of node is Not its_rightChild
      if (successorNode!=node->_rightChild) {
      
        // frist, successor's Right Subtree takes its position
        relocate(successorNode, successorNode->_rightChild);
      
        // second, successor takes node's rightChild position 
        successorNode->_rightChild = node->_rightChild;
        successorNode->_rightChild->_parent = successorNode;
      }
      
      // relocate node's current _rightChild to node's position
      relocate(node, successorNode);
      
      // update successorNode's leftChild as node's leftChild
      successorNode->_leftChild = node->_leftChild;
      successorNode->_leftChild->_parent = successorNode;
    }

  };
  
  /* replaces one subtree as a child of its parent with 
   * another subtree*/ 
  template <typename T> 
  void BinarySearchTree<T>::relocate(
      Node<T>* replacedNode, Node<T>* substituteNode
      ) {
    cout << "Node of " << replacedNode->_key << " is " 
         << "replaced..." << endl; 
    // replacedNode as _root
    if (replacedNode->_parent==nullptr) {
      printf("root is replaced\n");
      this->_root = substituteNode;
    } 
    // replacedNode as _leftChild of a node 
    else if (replacedNode->_parent->_leftChild==replacedNode) {
      replacedNode->_parent->_leftChild = substituteNode;
    } 
    // replacedNode as _rightChild of a node 
    else if (replacedNode->_parent->_rightChild==replacedNode) {
      replacedNode->_parent->_rightChild = substituteNode;
    }

    // updated substituteNode's parent as replacedNode's parent
    // if it is non null node
    if (substituteNode != nullptr) {
      substituteNode->_parent = replacedNode->_parent;
    }
  };

  /* O(h) time complexity 
   * h is the height of the tree */
  template <typename T>
  const Node<T>* BinarySearchTree<T>::iterativeTreeSearch(
      const Node<T>* node) const {
    // start from _root
    Node<T>* curNode = _root; 
    
    while (curNode!=nullptr) {
      // check if the value is found in curNode 
      if (node->_key == curNode->_key) {
        return node; // found a node
      } // move down to left subtree
      else if (node->_key < curNode->_key) {
        curNode = curNode->_leftChild; 
      } // move down to right subtree
      else {
        curNode = curNode->_rightChild; 
      }
    }
    return nullptr; // found no matching node 
  }; 
  
  template <typename T>  
  Node<T>* BinarySearchTree<T>::getMaximum() const {
    return maximum(this->_root);
  }; 
 
  /* O(h) time complexity */ 
  template <typename T>
  Node<T>* BinarySearchTree<T>::maximum(
      Node<T>* aRoot) const {
    Node<T>* tempNode = aRoot;
    
    while (tempNode->_rightChild!=nullptr) {
      tempNode=tempNode->_rightChild;
    }
    return tempNode;
  };

  template <typename T>
  Node<T>* BinarySearchTree<T>::getMinimum() const {
    return minimum(this->_root);
  };

  template <typename T>
  Node<T>* BinarySearchTree<T>::minimum(
      Node<T>* aRoot) const {
    Node<T>* tempNode = aRoot;
    while (tempNode->_leftChild!=nullptr) {
      tempNode=tempNode->_leftChild;
    }
    return tempNode;
  }; 
    
  template <typename T>
  Node<T>* BinarySearchTree<T>::getSuccessor(
      Node<T>* node) const {
    if (node->_rightChild) {
      return minimum(node->_rightChild);  
    } else {
      Node<T>* tempNode=node->_parent;
      while (tempNode!=nullptr and node==tempNode->_rightChild) {
        node = tempNode;
        tempNode = tempNode->_parent;
      }
      return tempNode;
    }
    return nullptr;
  }; 
  
  template <typename T>
  Node<T>* BinarySearchTree<T>::getPredecessor(
      Node<T>* node) const {
    if (node->_leftChild) {
      return maximum(node->_leftChild);  
    } else {
      Node<T>* tempNode=node->_parent;
      while (tempNode!=nullptr and node==tempNode->_leftChild) {
        node = tempNode;
        tempNode = tempNode->_parent;
      }
      return tempNode;
    }
    return nullptr;
  }; 

  template <typename T>
  class HashTable {
  public:
    int indepUniformHashing(const int& key); // not implemented

    /* static hashing functions */
    int divHash(const int& k, const int& m) {return (k%m);};
    int multHash(const int& k, const int& m, const double& A) {
      return floor(m*((k*A) - floor(k*A)));
    };
    long int multShiftHash(const int& k, 
                      const int& wBits,
                      const int& lBits,
                      const long int& a);

    /* random hashing functions */

  private:
    int _key;
    T*  _valuePtr;
  };


  template <typename T>
  long int HashTable<T>::multShiftHash(const int& k,
      const int& wBits,
      const int& lBits,
      const long int& a) {
      //cout << ((k * a) % (long int)pow(2,wBits)) << endl;
    return ((k*a) % (long int)pow(2,wBits)) >> (wBits - lBits);
  };


} /* namespace DSALG */



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
    TreeNode* _left;
    TreeNode* _right;
    TreeNode() : val(0), _left(nullptr), _right(nullptr) {};
    TreeNode(int x) : val(x), _left(nullptr), _right(nullptr) {};
    TreeNode(int x, TreeNode *left, TreeNode *right) : \
      val(x), _left(left), _right(right) {};
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
    int _val;
    ListNode* _next;
    ListNode() : _val(0), _next(nullptr) {};
    ListNode(int x) : _val(x), _next(nullptr) {};
    ListNode(int x, ListNode *next) : _val(x), _next(next) {};
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
        int _val;
        TreeNode* _left;
        TreeNode* _right;
        TreeNode() : _val(0), _left(nullptr), _right(nullptr) {}
        TreeNode(int x) : _val(x), _left(nullptr), _right(nullptr) {}
        TreeNode(int x, TreeNode *left, TreeNode *right) : 
          _val(x), _left(left), _right(right) {}
    };

    class Solution {
    private:
        std::string sC;
        std::vector<int> iV;
        std::vector<std::vector<int>> _diff;
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
