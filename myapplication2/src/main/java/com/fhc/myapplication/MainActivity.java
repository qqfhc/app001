package com.fhc.myapplication;

import android.os.Bundle;
import android.support.v7.app.AppCompatActivity;
import android.util.Log;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        Jni jni = new Jni();
        int sum = jni.sum(3, 4);
        Log.e("TAG", "result"+sum);
        String fhc = jni.sayHello("fhc");
        Log.e("TAG", "yy" + fhc);
        int[] Array={1,2,3};
        int[] Array2= jni.increaseArrayEles(Array);
        for (int i=0;i<Array2.length;i++){
            Log.e("TAG", "aa"+Array2[i]);
        }

    }
}
