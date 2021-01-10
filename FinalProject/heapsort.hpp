class HeapSorting{

    private: //initialize variables
        int *heap; 
        int size;
        int index; 
        int i;

    public:
        HeapSorting(); //constructor
        void insertToTempArray(int arr[], int temparr[], int length); //write to testData
        int parent(int i); //int value of parent of i
        int leftChild(int i); //int value of left child of i
        int rightChild(int i); //int value of right child of i
        void swapArrValues(int* x,int* y); //swap by pointer and pass into function by reference
        void insert(int insertData); //insert into heap
        void maxHeapify(int arr[], int i, int heapSize); //heapify function
        void createHeap(int arr[], int heapSize); //build the heap
        void heapSort(int arr[], int heapSize); //sort heap from max to min
        void displayHeapArr(int arr[], int num); //print heap
};