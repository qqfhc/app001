package com.fhc.myapplication;

/**
 * Created by Administrator on 2016/6/12.
 */
public class JNIS {
static {
    System.loadLibrary("HelloJni");
}
    public native String helloJNI();





}
