
using System.Collections.Generic;
using System.IO;
using System.Windows.Forms;

namespace iaforms
{
    public class SetectedFiles
    {
        public void readFiles(string targetFile, List<FileInfo> fileIist)
        {
            RegSetting regSetting = new RegSetting();
            regSetting.ReadRegister();
            string tempPath = regSetting.TempPath;
            string importFile = tempPath;
            importFile += "\\";
            importFile += targetFile;

            string box_msg = importFile;
            string box_title = "Image Archive";
            MessageBox.Show(box_msg, box_title);
       
            ReadImportListFile(importFile, fileIist);
            
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
