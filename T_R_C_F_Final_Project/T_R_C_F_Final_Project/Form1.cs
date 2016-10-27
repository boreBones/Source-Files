/*
 * To Do Application
 * By: Trevor Kinsie, Chris Goguen, Robert Muir, Faizan Syed
 */

using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Diagnostics;
using System.Collections;


namespace T_R_C_F_Final_Project
{
    public partial class Form1 : Form
    {
        private String path = "Tasks.txt";
        private int index = -1;
        public Form1()
        {
            InitializeComponent();
            
        }
        private void Form1_Load(object sender, EventArgs e)
        {

            txtTask.KeyPress += txtTask_KeyPress;
            

            cmbCat.SelectedIndex = 0;
            cmbPriority.SelectedIndex = 0;
            cmbStatus.SelectedIndex = 0;


            if (File.Exists(path))
            {
                readFile();
            }

            setControlState("i");
        }

        //Will check for 
        void txtTask_KeyPress(object sender, KeyPressEventArgs e)
        {
            char c = e.KeyChar;

            // delim being pressed    : 
            // any characters that are not a-z A-Z 0-9 or spaces
            int len = ((TextBox)sender).Text.Length;
            ((TextBox)sender).SelectionStart = len;

            if (c != 8)
            {
                if ((c < 65 || c > 90) && (c < 97 || c > 122) && (c < 48 || c > 57) && (c < 32 || c > 32))
                {
                    e.Handled = true;
                }
            }
        
        
        }

        //dataGood will check if the task textfield is not empty
        private bool dataGood()
        {
            // is that stuff good?
            if (txtTask.Text.Length < 1)
            {
                MessageBox.Show("A Task is required to  contain more than 1 character");
                txtTask.Focus();
                return false;
            }
            return true;
        }

        private void setControlState(String text)
        {
            if(text.Equals("i"))
            {
                cmdInsert.Enabled = true;
                cmdDelete.Enabled = false;
                cmdUpdate.Enabled = false;
                cmdSort.Enabled = false;
                clearText();
            }

            else if (text.Equals("u/d"))
            {
                cmdInsert.Enabled = false;
                cmdDelete.Enabled = true;
                cmdUpdate.Enabled = true;
                cmdSort.Enabled = true;
              //  clearText();
            }
}

        private void clearText()
        {
            // clear the 'input' fields
           txtTask.Text = "";
           
        }

        private void readFile()
        {
            //read the file
            listBox1.Items.Clear();
            StreamReader noteReader = new StreamReader(path);

            string record = noteReader.ReadLine();

            while (record != null)
            
            {
                listBox1.Items.Add(record);
                record = noteReader.ReadLine();

            }
            noteReader.Close();

        }

        private void cmdInsert_Click(object sender, EventArgs e)
        {
          
            // Grabs variables
            string selectedCategory = this.cmbCat.GetItemText(this.cmbCat.SelectedItem);
            string task = txtTask.Text;
            string selectedPriority = this.cmbPriority.GetItemText(this.cmbPriority.SelectedItem);
            string selectedStatus = this.cmbStatus.GetItemText(this.cmbStatus.SelectedItem);
            string selectedDate = pickDate.Value.ToShortDateString();

            if (dataGood())
            {
                //Will write the data into the file
                StreamWriter noteWriter = new StreamWriter(path, true);

                noteWriter.WriteLine(selectedCategory +":" + task + ":"+selectedPriority+":"+selectedStatus+":"+selectedDate);
                noteWriter.Close();
                readFile();
                clearText();
            }
            setControlState("i");
        
        }

        //Update will update the fields and the textfile
        private void cmdUpdate_Click(object sender, EventArgs e)
        {
            string selectedDate = pickDate.Value.ToShortDateString();
            if (dataGood())
            {
                File.Delete(path);
                StreamWriter sw = new StreamWriter(path, true);
                for (int i = 0; i < listBox1.Items.Count; i++)
                {
                    if (i != index)
                    {
                        sw.WriteLine(listBox1.Items[i].ToString());
                    }
                    else
                    {
                        sw.WriteLine(cmbCat.Text + ":" + txtTask.Text + ":" + cmbPriority.Text + ":" + cmbStatus.Text + ":" + selectedDate);
                    }
                }

                sw.Close();
                readFile();
            }
            setControlState("i");
        }

        //Delete will delete the record
        private void cmdDelete_Click(object sender, EventArgs e)
        {

            //Will only delete the record if the user allow it
               if (MessageBox.Show("Are you sure you want want to delete this record?","Confirm Record Delete",MessageBoxButtons.YesNo,MessageBoxIcon.Warning
                   ,MessageBoxDefaultButton.Button2) == System.Windows.Forms.DialogResult.Yes)
               {
                   File.Delete(path);
                   StreamWriter myWriter = new StreamWriter(path, true);
                   for ( int x = 0 ; x < listBox1.Items.Count ; x++)
                   {
                       if ( x != index)
                       {
                           myWriter.WriteLine(listBox1.Items[x].ToString());
                       }
                   }
                   myWriter.Close();
                   readFile();
               }
               setControlState("i");
               readFile(); 
        }

        //Will select a record a put the values into the textboxes,etc
        private void listBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            index = listBox1.SelectedIndex;
            if (index > -1)
            {
                string record = listBox1.Items[index].ToString();
                char[] delims = {':'};
                string[] tokens = record.Split(delims);
                cmbCat.Text = tokens[0];
                txtTask.Text = tokens[1];
                cmbPriority.Text = tokens[2];
                cmbStatus.Text = tokens[3];
                pickDate.Text = tokens[4];
                setControlState("u/d");
            }
        }

        //The sort function will sort the tasks based on category
        private void cmdSort_Click(object sender, EventArgs e)
        {
            //ArrayList to hold the temporary values
            ArrayList myList = new ArrayList();

            //read the file
            listBox1.Items.Clear();

            StreamReader noteReader = new StreamReader(path);

            string record = noteReader.ReadLine();

            while (record != null)
            {
            //Will spit the current record into tokens and then add it to the arraylist
                string [] temp =record.Split(':');
                string tempCat = temp[0];
                string tempTask = temp[1];
                string tempPri = temp[2];
                string tempStatus = temp[3];
                string tempDate = temp[4];
                String finalText = tempCat + ":" + tempTask + ":" + tempPri + ":" + tempStatus + ":" + tempDate;
                myList.Add(finalText);
                record = noteReader.ReadLine();
            }
            
            //Sorts the arraylist alphabetically
            myList.Sort();
            for (int x = 0; x < myList.Count; x++)
            {
                listBox1.Items.Add(myList[x]);

            }
                noteReader.Close();

        }
   
    }
}
