package com.google.firebase.samples.apps.mlkit.java;

import androidx.appcompat.app.AppCompatActivity;

import android.content.Intent;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;

import com.google.firebase.samples.apps.mlkit.R;



public class ReturnActivity extends AppCompatActivity {
    public static Button returnbutton;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_return);

        ((BluetoothMainActivity) BluetoothMainActivity.ncontext).sendMessage("12312");
        returnbutton = findViewById(R.id.returnbtn);
        returnbutton.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(ReturnActivity.this, LivePreviewActivity.class );
                startActivity(intent);
            }
        });
    }


}
