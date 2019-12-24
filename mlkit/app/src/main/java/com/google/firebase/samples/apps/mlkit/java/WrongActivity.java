package com.google.firebase.samples.apps.mlkit.java;
import android.os.Bundle;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;

import com.google.firebase.samples.apps.mlkit.R;
public class WrongActivity extends AppCompatActivity {
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_stop);
        //자료를 intent로 주고 받지도 않고 블루투스로
        //전송할 일도 없다.
    }
}
