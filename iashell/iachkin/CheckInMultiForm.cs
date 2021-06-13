using System;
using System;
using System.Collections.Generic;
using System.Windows.Forms;
using iaforms;
using System.IO;


namespace iachkin
{
    public partial class CheckInMultiForm : Form
    {
        public CheckInMultiForm(string file)
        {
            InitializeComponent();
            List<FileInfo> fileIist = new List<FileInfo>();
            string box_msg = file;
            string box_title = "Image Archive";
            MessageBox.Show(box_msg, box_title);
            ReadImportListFile(file, fileIist);
            AddImportItems(fileIist);
        }

        public void AddImportItems(List<FileInfo> fileIist)
        {

            foreach (FileInfo item in fileIist)
            {
                ListViewItem lvi = new ListViewItem(item.Name);
                DateTime lastmodified = item.LastWriteTime;
                string dateString = lastmodified.ToString("HH:mm MM/dd/yyyy");
                lvi.SubItems.Add(dateString);
                lvi.SubItems.Add(item.Extension);
                lvi.SubItems.Add(item.Length.ToString());
                lvi.SubItems.Add(item.DirectoryName);
                listViewImportFiles.Items.Add(lvi);
            }
        }
        public bool ReadImportListFile(string path, List<FileInfo> fileIist)
        {
            string box_msg = path;
            string box_title = "Image Archive";
            MessageBox.Show(box_msg, box_title);

            if (File.Exists(path))
            {
                // Read all the content in one string 
                // and display the string 
                string[] lines = File.ReadAllLines(path);
                foreach (string ln in lines)
                {
                    var fileItem = new FileInfo(ln);
                    fileIist.Add(fileItem);

                }

            }
            return true;
        }
    }
}
