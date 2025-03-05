#include <iostream>
#include <vector>
using namespace std;

class MinHeap
{
private:
    vector<int> heap;

    int parent(int i)
    {
        return (i - 1) / 2;
    }
    int leftChild(int i) 
    { 
        return 2 * i + 1; 
    }
    int rightChild(int i) 
    { 
        return 2 * i + 2; 
    }

    void heapifyUp(int index)
    {
        while (index > 0 && heap[index] < heap[parent(index)])
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    {
        int left = leftChild(index);
        int right = rightChild(index);
        int smallest = index;

        if (left < heap.size() && heap[left] < heap[smallest])
            smallest = left;
        if (right < heap.size() && heap[right] < heap[smallest])
            smallest = right;

        if (smallest != index)
        {
            swap(heap[index], heap[smallest]);
            heapifyDown(smallest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMin()
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        int minVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return minVal;
    }

    int getMin()
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");
        return heap[0];
    }

    bool isEmpty()
    {
        return heap.empty();
    }

    void printHeap()
    {
        for (int val : heap)
            cout << val << " ";
        cout << endl;
    }
};

int main()
{
    MinHeap minHeap;
    minHeap.insert(10);
    minHeap.insert(5);
    minHeap.insert(3);
    minHeap.insert(2);
    minHeap.insert(8);

    cout << "Min Heap: ";
    minHeap.printHeap();

    cout << "Extracted Min: " << minHeap.extractMin() << endl;
    cout << "Min Heap after extraction: ";
    minHeap.printHeap();

    return 0;
}
