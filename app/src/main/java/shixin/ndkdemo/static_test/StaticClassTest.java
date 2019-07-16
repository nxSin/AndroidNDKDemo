package shixin.ndkdemo.static_test;

import android.util.Log;

import java.util.List;

/**
 * 静态方法测试类
 */
public class StaticClassTest {
    private static final String TAG = StaticClassTest.class.getSimpleName();

    private static int age = 5;

    /**
     * 调用静态方法测试
     */
    public static void staticMethodTest() {
        Log.d(TAG, "1 调用到静态方法了");
        Log.d(TAG, "2 调用到静态方法了,age:" + age);
    }

    /**
     * 调用带参数静态方法测试
     */
    public static int staticMethodTest(String name) {
        Log.d(TAG, "3 调用到带参静态方法了,name:" + name);
        Log.d(TAG, "4 调用到带参静态方法了,修改后age:" + age);
        return 1;
    }

    /**
     * 调用带参数静态方法测试
     */
    public static int staticMethodTest(List<String> names) {
        Log.d(TAG, "5 调用到带参静态方法了,name:" + names);
        Log.d(TAG, "6 调用到带参静态方法了,修改后age:" + age);
        return 1;
    }
}
