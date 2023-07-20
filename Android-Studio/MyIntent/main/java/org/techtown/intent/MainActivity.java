package org.techtown.intent;

import androidx.annotation.Nullable;
import androidx.appcompat.app.AppCompatActivity;
import androidx.core.view.KeyEventDispatcher;

import android.content.ComponentName;
import android.content.Intent;
import android.net.Uri;
import android.os.Bundle;
import android.view.View;
import android.widget.Button;
import android.widget.Toast;

public class MainActivity extends AppCompatActivity {

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        Button button = findViewById(R.id.button);
        button.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(getApplicationContext(), MenuActivity.class);
                startActivityForResult(intent, 101);

                /*
                Intent intent = new Intent();
                ComponentName name = new ComponentName("org.techtown.intent", "org.techtown.intent.MenuActivity");
                intent.setComponent(name);
                startActivityForResult(intent, 101);
                **/

            }
        });

        Button button2 = findViewById(R.id.button2);
        button2.setOnClickListener(new View.OnClickListener() {
            @Override
            public void onClick(View v) {
                Intent intent = new Intent(Intent.ACTION_VIEW, Uri.parse("tel:010-1000-1000"));
                startActivity(intent);
            }
        });
    }

    @Override
    protected void onActivityResult(int requestCode, int resultCode, @Nullable Intent data) {
        super.onActivityResult(requestCode, resultCode, data);

        if(requestCode == 101){
            if(data != null){
                String name = data.getStringExtra("name");
                if(name != null){
                    Toast.makeText(this, "응답으로 받은 데이터 : " + name, Toast.LENGTH_LONG).show();
                }
            }
        }
    }
}