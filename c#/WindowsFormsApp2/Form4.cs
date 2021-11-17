using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp2
{
    public partial class Form4 : Form
    {
        public Form4()
        {
            InitializeComponent();
        }

        private void Form4_Load(object sender, EventArgs e)
        {
            dataGridView1.ReadOnly = true;
            dataGridView1.AllowUserToDeleteRows = false;
            dataGridView1.ColumnCount = 6;
            dataGridView1.Columns[0].Name = "İsim-Soyad";
            dataGridView1.Columns[1].Name = "Sınıf";
            dataGridView1.Columns[2].Name = "Tc Kimlik No";
            dataGridView1.Columns[3].Name = "Memleket";
            dataGridView1.Columns[4].Name = "Cinsiyet";
            dataGridView1.Columns[5].Name = "Doğum Tarihi";
        }

        private void button1_Click(object sender, EventArgs e)
        {
            int flag = 0;
            foreach(String tc in Form2.tcList)
            {
                if (tc.Equals(textBox1.Text))
                {
                    flag = 1;
                    int i = Form2.tcList.IndexOf(tc);
                    dataGridView1.Rows.Add(Form2.isimList[i], Form2.sinifList[i], Form2.tcList[i], Form2.memleketList[i], Form2.cinsiyetList[i], Form2.dogumTarihiList[i]);
                }
            }
            if(flag == 0)
            {
                MessageBox.Show("Aranan tc numaralı öğrenci bilgisi bulunamadı.");
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Close();
        }
    }
}
