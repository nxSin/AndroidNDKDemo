package shixin.ndkdemo.supermethod;

import android.util.Log;

public class People {
    private static final String TAG = People.class.getSimpleName();

    /**
     * 说方法,在其中调用下sayAge
     */
    public void say() {
        Log.d(TAG, "people say");
        sayAge();
    }

    public void sayAge() {
        Log.d(TAG, "people say age");
    }
}
