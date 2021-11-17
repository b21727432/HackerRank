using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp3
{
    public partial class Form2 : Form
    {
        public Form2()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int sayi = Int32.Parse(textBox1.Text);
            listBox1.Items.Add(sayi);
        }

        private void button2_Click(object sender, EventArgs e)
        {
            int toplam = 0;
            foreach(int x in listBox1.Items)
            {
                toplam += x;
            }
            MessageBox.Show("Toplam : " + toplam);
        }

        private void button3_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 form1 = new Form1();
            form1.Show();
        }
    }
}
