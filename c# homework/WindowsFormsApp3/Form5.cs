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
    public partial class Form5 : Form
    {
        public Form5()
        {
            InitializeComponent();
        }

        private void button1_Click(object sender, EventArgs e)
        {
            char harf = Convert.ToChar(textBox2.Text);
            harfBulucu(textBox1.Text, harf);
        }

        private void harfBulucu(string cumle, char harf)
        {
            int sayac = 0;
            for(int i = 0; i < cumle.Length; i++)
            {
                if(cumle[i] == harf)
                {
                    sayac++;
                }
            }
            MessageBox.Show("Cumlenin icerisinde " + sayac + " adet " + harf + " harfi bulundu");
        }

        private void button2_Click(object sender, EventArgs e)
        {
            this.Close();
            Form1 form1 = new Form1();
            form1.Show();
        }
    }
}
