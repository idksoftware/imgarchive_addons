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

namespace iachkin
{
    public partial class CheckInSingleForm : Form
    {
        public CheckInSingleForm(string file)
        {
            InitializeComponent();

            FileInfo fileItem = new FileInfo(file);
            labelType.Text = fileItem.Extension;
            DateTime lastmodified = fileItem.LastWriteTime;
            string dateString = lastmodified.ToString("HH:mm MM/dd/yyyy");
            labelDateModified.Text = dateString;
            labelFolder.Text = fileItem.DirectoryName;
            labelImage.Text = fileItem.Name;
            labelSize.Text = fileItem.Length.ToString();
        }
    }
}
