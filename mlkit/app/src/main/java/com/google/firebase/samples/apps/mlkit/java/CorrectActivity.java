package com.google.firebase.samples.apps.mlkit.java;
import android.content.ComponentName;
import android.content.Context;
import android.content.Intent;
import android.content.pm.PackageManager;
import android.os.Bundle;
import android.os.Handler;
import android.widget.Button;
import android.widget.TextView;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.app.ActivityCompat;
import androidx.core.content.IntentCompat;

import com.google.firebase.samples.apps.mlkit.R;


public class CorrectActivity extends AppCompatActivity {
    public String getString;
    public String finalString;
    public static TextView testview;
    @Override
    protected void onCreate(@Nullable Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_go);


        testview = findViewById(R.id.txtbox2);
        Intent intent = getIntent();
        getString = intent.getStringExtra("answer");
        //testview.setText(getString);
        //finalString = getString.substring(1,6);

        Handler handler = new Handler();
        handler.postDelayed(new Runnable() {public void run() {((BluetoothMainActivity) BluetoothMainActivity.ncontext).sendMessage(getString.substring(1,6));}},1000);
        //((BluetoothMainActivity) BluetoothMainActivity.ncontext).sendMessage("12312");
        //finishAffinity(); 다 실행된 후 2초 딜레이 주는 것.
        //moveTaskToBack(true);finish(); android.os.Process.killProcess(android.os.Process.myPid());

    }


}

