package com.example.ad.barthomermorphing;

import android.support.v7.app.AppCompatActivity;
import android.os.Bundle;
import android.util.Log;
import android.view.View;
import android.widget.ImageView;

public class MainActivity extends AppCompatActivity {

    boolean swap = true;
    public void ClickFunction(View view){


        ImageView bartImageView = (ImageView)findViewById(R.id.bartImageView);
        ImageView homerImageView = (ImageView)findViewById(R.id.homerImageView);
        if(swap)
        {
            bartImageView.animate().alpha(0).setDuration(5000);
            homerImageView.animate().alpha(1).setDuration(5000);
            swap = false;
            Log.i("swaap to false","bart to homer");
        }
        else {
            homerImageView.animate().alpha(0).setDuration(5000);
            bartImageView.animate().alpha(1).setDuration(5000);
            swap = true;
            Log.i("swap to true","homer to bart");
        }

    }

    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);
    }
}
