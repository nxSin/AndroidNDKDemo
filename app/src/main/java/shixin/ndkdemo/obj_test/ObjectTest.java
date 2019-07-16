package shixin.ndkdemo.obj_test;

import android.util.Log;

/**
 * jni实例调用测试:
 * 1. 测试调用打印年龄和姓名，预期打印 0 和null
 * 2. 通过修改字段，设置age和name的值，然后再打印
 * 3. 重新创建一个对象，初始化方法中传入性别，调用打印性别的方法
 */
public class ObjectTest {
    private static final String TAG = ObjectTest.class.getSimpleName();

    /**
     * 性别
     */
    private String sex;
    /**
     * 年龄
     */
    private int age;
    /**
     * 姓名
     */
    private final String name = "12345";

    /**
     * 无参数构造方法
     */
    public ObjectTest() {
    }

    /**
     * 带参数构造方法
     *
     * @param sex 性别
     */
    public ObjectTest(String sex) {
        this.sex = sex;
    }

    /**
     * 用于打印age和name
     */
    public void logInfo() {
        Log.i(TAG, null);
        Log.i(TAG, "age:" + age + ",name:" + name);
    }

    /**
     * 用于打印性别
     */
    public void logSex() {
        Log.i(TAG, "性别：" + sex);
    }
}
