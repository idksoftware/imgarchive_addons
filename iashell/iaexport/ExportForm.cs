using System;
using System.Collections.Generic;
using System.Windows.Forms;
using iaforms;
using System.IO;

namespace iaexport
{
    public partial class ExportForm : Form
    {
        public ExportForm()
        {
            InitializeComponent();
            List<FileInfo> fileIist = new List<FileInfo>();

            SetectedFiles setectedFiles = new SetectedFiles();
            //setectedFiles.readFiles(fileIist);
            //AddImportItems(fileIist);
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

    }
}