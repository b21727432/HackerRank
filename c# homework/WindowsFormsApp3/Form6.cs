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
    public partial class Form6 : Form
    {
        public Form6()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            double sayi1 = Int32.Parse(textBox1.Text);
            double sayi2 = Int32.Parse(textBox2.Text);
            double sonuc;
            if(!String.IsNullOrEmpty(textBox3.Text))
            {
                double sayi3 = Int32.Parse(textBox3.Text);
                sonuc = carpim(sayi1, sayi2, sayi3);
            }
            else
            {
                sonuc = carpim(sayi1, sayi2);
            }
            MessageBox.Show("Girilen Sayilarin Carpimi : " + sonuc);
        }

        private double carpim(double sayi1, double sayi2)
        {
            return sayi1 * sayi2;
        }

        private double carpim(double sayi1, double sayi2, double sayi3)
        {
            return sayi1 * sayi2 * sayi3;
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 form1 = new Form1();
            form1.Show();
        }
    }
}
