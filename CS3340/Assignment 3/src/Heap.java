/**
 * @author name - Student ID: xxxxxxxxx
 * CS3340 Assignment 3**/
public class Heap {
	
	private Element[] heap;
	private int size;
	private int curr = 0;
	
	public Heap(int[] keys, int n) {
		heap = new Element[n];
		size = n;
		
		heap[0] = new Element(0, 0);
	}
	
	public boolean in_heap(int id) {
		for(int i = 0; i < size; i++) {
			if(heap[i].getId() == id) {
				return true;
			}
		}
		return false;
	}
	
	public int min_key() {
		return heap[0].getKey();
	}
	
	public int min_id() {
		return heap[0].getId();
	}
	
	public int key(int id) {
		for(int i = 0; i < size; i++) {
			if(heap[i].getId() == id) {
				return heap[i].getKey();
			}
		}
		return id;
	}
	
	public void delete_min() {
		//Remove the first element of the heap (the one with the minimum value)
		Element temp = heap[0];
		//Hold the Element that is to be deleted in a temp variable
		size -= 1;
		//Decrease the size of the heap by 1
		//heapify the root
	}
	
	public void decrease_key(int id, int new_key) {
		for(int i = 0; i < size ; i++) {
			if(heap[i].getId() == id) {
				if(heap[i].getKey() > new_key) {
					heap[i].setKey(new_key);
				}
			}
		}
	}
	
	private int leftChild(int i) {
		int lChild = 2*i;
		return lChild; 
	}
	
	private int rightChild(int i) {
		int rChild = (2*i)+1;
		return rChild; 
	}
	
	private boolean isLeaf(int i){
	 
	    if (i > (curr / 2) && i <= curr) {
	    	return true;
	    }
	 
	    return false;
	}
	
	private void swap(int x, int y){
        Element temp;
        temp = heap[x];
 
        heap[x] = heap[y];
        heap[y] = temp;
    }
	
	private void minimumHeap(int i){
 
        if (!isLeaf(i)) {
            if (heap[i].getId() > heap[leftChild(i)].getId() || heap[i].getId() > heap[rightChild(i)].getId()) {
 
                // Swap with the left child and heapify lChild
                if (heap[leftChild(i)].getId() < heap[rightChild(i)].getId()) {
                    swap(i, leftChild(i));
                    minimumHeap(leftChild(i));
                }
 
                // Swap with the right child and heapify rChild
                else {
                    swap(i, rightChild(i));
                    minimumHeap(rightChild(i));
                }
            }
        }
    }
	

}
