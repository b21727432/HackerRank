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
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void button3_Click(object sender, EventArgs e)
        {
            int sayi1 = Int32.Parse(textBox1.Text);
            int sayi2 = Int32.Parse(textBox2.Text);

            double sonuc = usAl(sayi1, sayi2);

            MessageBox.Show("Us alma isleminin sonucu : " + sonuc);

        }

        private double usAl(int sayi1, int sayi2)
        {
            return Math.Pow(sayi1, sayi2);
        }

        private void button4_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 form1 = new Form1();
            form1.Show();
        }
    }
}
