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
    public partial class Form2 : Form
    {
        public static List<string> isimList = new List<string>();
        public static List<string> sinifList = new List<string>();
        public static List<string> tcList = new List<string>();
        public static List<string> memleketList = new List<string>();
        public static List<string> cinsiyetList = new List<string>();
        public static List<string> dogumTarihiList = new List<string>();

        public Form2()
        {
            InitializeComponent();

        }

        private void Form2_Load(object sender, EventArgs e)
        {
            comboBox1.Items.Add("9/A");
            comboBox1.Items.Add("9/B");
            comboBox1.Items.Add("10/A");
            comboBox1.Items.Add("10/B");
            comboBox1.Items.Add("11/A");
            comboBox1.Items.Add("11/B");
            comboBox1.Items.Add("12/A");
            comboBox1.Items.Add("12/B");

            comboBox2.Items.Add("Antalya");
            comboBox2.Items.Add("Ankara");
            comboBox2.Items.Add("Bilecik");
            comboBox2.Items.Add("Eskişehir");
            comboBox2.Items.Add("Gaziantep");
            comboBox2.Items.Add("İstanbul");
            comboBox2.Items.Add("Burdur");
            comboBox2.Items.Add("Trabzon");
            comboBox2.Items.Add("Ağrı");
        }
        // kaydet
        private void button2_Click(object sender, EventArgs e)
        {
            isimList.Add(textBox1.Text);
            sinifList.Add(comboBox1.SelectedItem.ToString());
            tcList.Add(textBox2.Text);
            memleketList.Add(comboBox2.SelectedItem.ToString());

            if (checkBox1.Checked)
            {
                cinsiyetList.Add("Erkek");
            }
            else if (checkBox2.Checked)
            {
                cinsiyetList.Add("Kadin");
            }

            dogumTarihiList.Add(dateTimePicker1.Value.ToString());

            button1_Click(sender, e);
        }
        // temizle
        private void button1_Click(object sender, EventArgs e)
        {
            textBox1.Text = string.Empty;
            comboBox1.SelectedItem = null;
            textBox2.Text = string.Empty;
            comboBox2.SelectedItem = null;
            if (checkBox1.Checked)
            {
                checkBox2.Enabled = true;
                checkBox1.Checked = false;
            }
            else if (checkBox2.Checked)
            {
                checkBox2.Checked = false;
                checkBox1.Enabled = true;
            }
            dateTimePicker1.Value = DateTime.Now;

        }

        private void button3_Click(object sender, EventArgs e)
        {
            Form1 form1 = new Form1();
            form1.Show();
            this.Close();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox1.Checked)
            {
                checkBox2.Enabled = false;
            }
            else
            {
                checkBox2.Enabled = true;
            }
            
        }

        private void checkBox2_CheckedChanged(object sender, EventArgs e)
        {
            if (checkBox2.Checked)
            {
                checkBox1.Enabled = false;
            }
            else
            {
                checkBox1.Enabled = true;
            }
        }
    }
}
