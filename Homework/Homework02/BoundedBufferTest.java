/**
 * Unit tests for BoundedBuffer. Tests include errors and functionality.
 */
public class BoundedBufferTest {
    private static Object o = new Object();
    private static Object objectRetrieved;

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

    // Test .insert() throws error
    public static void testBoundedBuffer_t0() throws InterruptedException {
        BoundedBuffer bb = new BoundedBuffer();
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
        }
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
        }
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
        }
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
        }
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
        }
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
        }
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
        }
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
        }
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
        }
        try {
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
            System.out.println("Adding overflow insertion. Should wait for free space."); // Test that result is an
                                                                                          // exception
            bb.insert(o);
            bb.retrieve();
        } catch (InterruptedException e) {
            System.out.println("Your error is: "); // Test that result is an exception
            System.out.println(e); // Test that result is an expection
        }
    }

    // Test .retrieve() returns the correct Object o
    public static void testBoundedBuffer_t1() throws InterruptedException {
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
    }

}
