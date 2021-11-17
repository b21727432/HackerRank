using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.CompilerServices;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form3 : Form
    {
        public Form3()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int satir = 3;
            int sutun = 3;

            int[,] ikiboyutarray = new int[satir, sutun];
            
            int mult = 0;
            for (int i = 0; i != satir; i++)
            {
                mult = mult + 10;
                for (int j = 0; j != sutun; j++)
                {
                    ikiboyutarray[i, j] = mult;

                    listBox1.Items.Add(i + ".satirdaki," + j + ". sutundaki sayi : " + ikiboyutarray[i, j]);
                    mult = mult * 10;
                }
                mult = mult / 1000;
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 form1 = new Form1();
            form1.Show();
        }
    }
}
