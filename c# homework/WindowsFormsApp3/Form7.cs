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
    public partial class Form7 : Form
    {
        public Form7()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int sayi = Int32.Parse(textBox1.Text);
            int sonuc = faktoriyel(sayi);
            MessageBox.Show(sayi + " sayisinin faktoriyeli : " + sonuc);
        }

        private int faktoriyel(int sayi)
        {
            if(sayi == 1)
            {
                return 1;
            }
            else
            {
                return sayi * faktoriyel(sayi - 1);
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
