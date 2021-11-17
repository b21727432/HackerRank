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
    public partial class Form3 : Form
    {

        private int PgSize = 1;
        private int CurrentPageIndex = 1;
        private int TotalPage = 0;
        private int currentIndex = 0;

        public Form3()
        {
            InitializeComponent();
        }

        private void Form3_Load(object sender, EventArgs e)
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

            button3.Visible = false;
            button2.Visible = false;
            CalculateTotalPages();
            
            if(Form2.isimList.Count == 0)
            {
                MessageBox.Show("Hiç Öğrenci Yok");
            }
            for (int i = 0; i < PgSize; i++)
            {
                dataGridView1.Rows.Add(Form2.isimList[i], Form2.sinifList[i], Form2.tcList[i], Form2.memleketList[i], Form2.cinsiyetList[i], Form2.dogumTarihiList[i]);
                
            }
            currentIndex = PgSize;
            if(CurrentPageIndex < TotalPage)
            {
                button3.Visible = true;
            }

        }

        private void CalculateTotalPages()
        {
            int totalCount = Form2.isimList.Count;
            if(totalCount % PgSize == 0)
            {
                TotalPage = totalCount / PgSize;

            }
            else
            {
                TotalPage = totalCount / PgSize;
                TotalPage += 1;
            }
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Close();
        }

        // önce
        private void button2_Click(object sender, EventArgs e)
        {
            int flag = 0;
            CurrentPageIndex -= 1;
            if(CurrentPageIndex == 1)
            {
                button2.Visible = false;
                button3.Visible = true;
                flag = 1;
            }
            dataGridView1.Rows.Clear();
            if (flag != 1)
            {
                currentIndex -= PgSize;
            }
            for (int i = currentIndex; i < currentIndex + PgSize; i++)
            {
                dataGridView1.Rows.Add(Form2.isimList[i], Form2.sinifList[i], Form2.tcList[i], Form2.memleketList[i], Form2.cinsiyetList[i], Form2.dogumTarihiList[i]);
            }
            
          
        }
        // sonra
        private void button3_Click(object sender, EventArgs e)
        {
            int flag = 0;
            CurrentPageIndex += 1;
            if(CurrentPageIndex < TotalPage)
            {
                button3.Visible = true;
                button2.Visible = true;
            }
            else if(CurrentPageIndex == TotalPage)
            {
                button3.Visible = false;
                flag = 1;
            }
            dataGridView1.Rows.Clear();
            for (int i = currentIndex; i < currentIndex + PgSize; i++)
            {
                dataGridView1.Rows.Add(Form2.isimList[i], Form2.sinifList[i], Form2.tcList[i], Form2.memleketList[i], Form2.cinsiyetList[i], Form2.dogumTarihiList[i]);
            }
            if (flag == 0)
            {
                currentIndex += PgSize;
            }

            
        }
    }
}
