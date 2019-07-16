package shixin.ndkdemo.supermethod;

import android.util.Log;

public class Beibi extends People {
    private static final String TAG = Beibi.class.getSimpleName();
    private int age;
    private String name;

    public Beibi(int age, String name) {
        this.age = age;
        this.name = name;
    }

    /**
     * 重写的父类说方法
     */
    @Override
    public void say() {
        Log.d(TAG, "beibi say:my name is " + name);
    }

    @Override
    public void sayAge() {
        Log.d(TAG, "beibi say:my age is " + age);
    }
}
