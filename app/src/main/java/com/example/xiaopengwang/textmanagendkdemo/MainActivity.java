package com.example.xiaopengwang.textmanagendkdemo;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.view.View;
import android.widget.EditText;
import android.widget.TextView;

public class MainActivity extends AppCompatActivity {

    // Used to load the 'native-lib' library on application startup.
    static {
        System.loadLibrary("encode");
    }
    EditText et ;

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
        // Example of a call to a native method
        et = (EditText) findViewById(R.id.et_text);
    }
    public void encode(View v){
        //获取edittext的文字
        String word = et.getText().toString();
        //传递c加密处理
        if(!word.equals(""))
            word = encodeInC(word);
        //把处理后的结果显示到edittext上
        et.setText(word);
    }
    public void decode(View v){
        //获取edittext的文字
        String word = et.getText().toString();
        //传递c加密处理
        if(!word.equals(""))
            word = decodeInC(word);
        //把处理后的结果显示到edittext上
        et.setText(word);

    }
    /**
     * A native method that is implemented by the 'native-lib' native library,
     * which is packaged with this application.
     */
    public native String encodeInC(String word);

    public native String decodeInC(String word);
}
