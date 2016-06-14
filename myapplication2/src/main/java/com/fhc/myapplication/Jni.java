package com.fhc.myapplication;

/**
 * Created by Administrator on 2016/6/13.
 */
public class Jni {
    static {
        System.loadLibrary("Jni");
    }

    public native int sum(int x, int y);
    public native String sayHello(String s);
    public native int[] increaseArrayEles(int[] intArray);
}
