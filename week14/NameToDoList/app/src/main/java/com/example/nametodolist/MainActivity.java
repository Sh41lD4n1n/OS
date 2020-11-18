package com.example.nametodolist;


import androidx.appcompat.app.AlertDialog;
import androidx.appcompat.app.AppCompatActivity;


import android.content.DialogInterface;
import android.os.Bundle;
import android.util.Log;
import android.view.Menu;
import android.view.MenuItem;
import android.view.View;
import android.widget.AdapterView;
import android.widget.ArrayAdapter;
import android.widget.Button;
import android.widget.EditText;
import android.widget.ListView;
import android.widget.TextView;
import android.widget.Toast;

import java.util.ArrayList;

public class MainActivity extends AppCompatActivity {
    private static final String TAG = "text";
    ArrayList<String> taskList = new ArrayList<String>();
    ListView mTaskListView;
    ArrayAdapter<String> mAdapter;
    @Override
    protected void onCreate(Bundle savedInstanceState) {
        super.onCreate(savedInstanceState);
        setContentView(R.layout.activity_main);

        mTaskListView = findViewById(R.id.list_todo);

        mAdapter = new ArrayAdapter<String>(this, R.layout.todo_items, R.id.task_title, taskList);
        mTaskListView.setAdapter(mAdapter);
    }

    @Override
    public boolean onCreateOptionsMenu(Menu menu) {
        getMenuInflater().inflate(R.menu.main_menu, menu);
        return super.onCreateOptionsMenu(menu);
    }


    @Override
    public boolean onOptionsItemSelected(MenuItem item) {
        switch (item.getItemId()) {
            case R.id.action_add_task:
                Log.d("MainClass", "Add a new task");
                final EditText taskEditText = new EditText ( this );
                AlertDialog dialog = new AlertDialog . Builder ( this )
                        . setTitle (" Add a new task " )
                        . setMessage ( " What do you want to do next ?")
                        . setView ( taskEditText )
                        . setPositiveButton (" Add " , new DialogInterface .
                                OnClickListener () {
                            @Override
                            public void onClick ( DialogInterface dialog , int which )
                            {
                                String task = String . valueOf ( taskEditText . getText ()
                                );
                                addItem(task);
                                Log .d(TAG , " Task to add : " + task ) ;
                            }
                        })
                        . setNegativeButton (" Cancel " , null )
                        . create () ;
                dialog.show();
                return true;
            case R.id.action_remove_task:
                removeFirstItem();
            default:
                return super.onOptionsItemSelected(item);
        }
    }
    public boolean deleteTask(View view){
        /*switch(view.getId())  {
            case  mTaskListView.getId(): // идентификатор "@+id/button1"
                showAlertDialog();
                break;
        }*/
        removeFirstItem();
        String task = String.valueOf (view.getId());
        Log .d(TAG , " Delete function: " +"/"+task);
        return true;
    }


    private void addItem ( String itemText ){
        taskList.add( itemText );
        mAdapter.notifyDataSetChanged();
    }
    private void removeFirstItem () {
        taskList.remove(0);
        mAdapter.notifyDataSetChanged () ;
    }
    private void removeItem ( String itemText ) {
        taskList.remove( itemText );
        mAdapter.notifyDataSetChanged () ;
    }
}
