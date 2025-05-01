#include <iostream>
#include <vector>
using namespace std;

class MaxHeap
{
private:
    vector<int> heap;

    int parent(int i) { return (i - 1) / 2; }
    int leftChild(int i) { return 2 * i + 1; }
    int rightChild(int i) { return 2 * i + 2; }

    void heapifyUp(int index)
    {
        while (index > 0 && heap[index] > heap[parent(index)])
        {
            swap(heap[index], heap[parent(index)]);
            index = parent(index);
        }
    }

    void heapifyDown(int index)
    {
        int left = leftChild(index);
        int right = rightChild(index);
        int largest = index;

        if (left < heap.size() && heap[left] > heap[largest])
            largest = left;
        if (right < heap.size() && heap[right] > heap[largest])
            largest = right;

        if (largest != index)
        {
            swap(heap[index], heap[largest]);
            heapifyDown(largest);
        }
    }

public:
    void insert(int value)
    {
        heap.push_back(value);
        heapifyUp(heap.size() - 1);
    }

    int extractMax()
    {
        if (heap.empty())
            throw runtime_error("Heap is empty");

        int maxVal = heap[0];
        heap[0] = heap.back();
        heap.pop_back();
        heapifyDown(0);

        return maxVal;
    }

    int getMax()
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
    MaxHeap maxHeap;
    maxHeap.insert(10);
    maxHeap.insert(5);
    maxHeap.insert(3);
    maxHeap.insert(2);
    maxHeap.insert(8);

    cout << "Max Heap: ";
    maxHeap.printHeap();

    cout << "Extracted Max: " << maxHeap.extractMax() << endl;
    cout << "Max Heap after extraction: ";
    maxHeap.printHeap();

    return 0;
}
