public class BoundedBuffer {
    private Object[] buffer = new Object[20]; // arbitrary size
    private int numOccupied = 0;
    private int firstOccupied = 0;
    /*
     * invariant: 0 <= numOccupied <= buffer.length 0 <= firstOccupied <
     * buffer.length buffer[(firstOccupied + i) % buffer.length] contains the
     * (i+1)th oldest entry, for all i such that 0 <= i < numOccupied
     */

    // Producer is one who is inserting
    public synchronized void insert(Object o) throws InterruptedException {
        while (numOccupied == buffer.length)
            // wait for space
            wait();
        buffer[(firstOccupied + numOccupied) % buffer.length] = o;
        numOccupied++;
        // in case any retrieves are waiting for data, wake them
        if (numOccupied == 1) {
            notifyAll();
        }
    }

    // Consumer, one who is retrieving
    public synchronized Object retrieve() throws InterruptedException {
        while (numOccupied == 0)
            // wait for data
            wait();
        Object retrieved = buffer[firstOccupied];
        buffer[firstOccupied] = null; // may help garbage collector
        firstOccupied = (firstOccupied + 1) % buffer.length;
        numOccupied--;
        // in case any inserts are waiting for space, wake them
        if (numOccupied == buffer.length - 1) {
            notifyAll();
        }
        return retrieved;
    }
}

// public class Consumer extends Thread {
//      //same thing but in reverse
//      //reads, waits if empty, and notifies all when no space is free

// }

// public class Provider extends Thread {
//      //calls insert... waits if full, notifies all when space is free
// }
