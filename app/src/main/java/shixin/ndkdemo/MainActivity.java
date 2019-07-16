package shixin.ndkdemo;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = MainActivity.class.getSimpleName();

    // Used to load the 'native-lib' library on application startup.

    /**
     * 引入动态库
     */
    static {
        System.loadLibrary("my_native_lib");
    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        // Example of a call to a native method
        TextView tv = (TextView) findViewById(R.id.sample_text);
        tv.setText(intFromJni() + "");
        //测试日志
//        testAndroidLog();
        //测试调用静态方法
//        testStaticMethodUse();

        //测试调用事例方法
//        try {
//            testObjectMethodUse(12,"小宝贝");
//        } catch (Exception e) {
//            e.printStackTrace();
//        }

        //异常测试
//        testCrash();

        //修改传入字段测试
//        byte[] bytes = new byte[8];
//        testSetInField(bytes);
//        Log.i(TAG, Arrays.toString(bytes));

        testCallSuper();
    }

    private void testCallSuper() {
        /*使用java来创建进行调用say方法*/
//        People beibi = new Beibi(12, "小北鼻");
//        beibi.say();

        //jni来调用
        testCallSuperMethod(13,"大北鼻");
    }

    /**
     * 测试调用父类方法
     *
     * @return
     */
    private native int testCallSuperMethod(int age,String name);

    /**
     * 测试传入字段
     *
     * @param bytes
     * @return
     */
    private native int testSetInField(byte[] bytes);

    /**
     * 实例方法调用
     */
    private native void testObjectMethodUse(int age, String name);

    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String stringFromJNI();

    public native String stringFromJNI(String string);

    public static native void callStaticNative(String string);

    public static native void callStaticNative(String string, int age);

    /**
     * 从jni获取int返回
     *
     * @return int值
     */
    public native int intFromJni();

    /**
     * 日志测试
     */
    public native void testAndroidLog();


    public native void testStaticMethodUse();

    /**
     * 异常测试
     */
    public native void testCrash();
}
