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
            notifyAll();
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
            notifyAll();
        return retrieved;
    }
}
class BoundedBufferModified {
    private Object[] buffer = new Object[20]; // arbitrary size
    private int numOccupied = 0;
    private int firstOccupied = 0;
class Producer extends Thread {
    public synchronized void insert(Object o) throws InterruptedException {
        while (numOccupied == buffer.length)
            // wait for space
            wait();
        buffer[(firstOccupied + numOccupied) % buffer.length] = o;
        numOccupied++;
        // in case any retrieves are waiting for data, wake them
        if (numOccupied == buffer.length) {
            notifyAll();
        }
    }
}
class Consumer extends Thread {
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
            if (numOccupied == 0) {
                notifyAll();
            }
            return retrieved;
        }
     //calls insert... waits if full, notifies all when space is free
}
}





10:59
/**
 * Unit tests for BoundedBuffer. Tests include errors and
 * functionality.
 */
public class BoundedBufferTest {
    private static Object o = new Object();
    private static Object objectRetrieved;
    static BoundedBuffer bb = new BoundedBuffer();
    public static void main(String[] args) {
        try {
            testBoundedBuffer_t0();
        } catch (InterruptedException e) {
            System.out.println("Your error from t0 is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }
        try {
            testBoundedBuffer_t1();
        } catch (InterruptedException e) {
            System.out.println("Your error from t1 is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }
        System.out.println("All tests passed");
    }
    //Test .insert() throws error
    public static void testBoundedBuffer_t0() throws InterruptedException {
        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        
        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }
        try {
            bb.insert(o);
            System.out.println("Buffer is now full."); // Test that result is an exception
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }
        try {
            for(int i=0; i < 20; i++) {
                bb.retrieve();
            }
            System.out.println("Buffer is now empty."); // Test that result is an exception
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }
    }
       //Test .retrieve() returns object o
       public static void testBoundedBuffer_t1() throws InterruptedException{
        // BoundedBuffer bb = new BoundedBuffer();
        boolean sameVals;
        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }           
        try {
            objectRetrieved = bb.retrieve();
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }           
        if (o == objectRetrieved) {
            sameVals = true;
        } else {
            sameVals = false;
        } 
        System.out.println("The values returned and inserted were correct: " + sameVals);
       }  
       public static void testBoundedBuffer_t2() throws InterruptedException{
        BoundedBuffer bb = new BoundedBuffer();
        boolean sameVals;
        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }           
        try {
            objectRetrieved = bb.retrieve();
        } catch (InterruptedException e) {
            System.out.println(e);
        }
        try {
            bb.insert(o);
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }           
        if (o == objectRetrieved) {
            sameVals = true;
        } else {
            sameVals = false;
        } 
        System.out.println("The values returned and inserted were correct: " + sameVals);
       } 
}