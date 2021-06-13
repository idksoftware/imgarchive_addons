using System;
using System.Collections.Generic;
using System.Text;

namespace iaforms
{
    public class RegSetting : RegInitalise
    {
        String tempPath = null;

        public void ReadRegister()
        {
            isSetup = false;
            if (InitReg() == true)
            {
                tempPath = (String)regSubKey.GetValue("TempPath");
                isInstalled = true;
                if (tempPath == null)
                {
                    return;
                }
                isSetup = true;
                
            }   
        }

        public void WriteRegistory()
        {
            if (tempPath != null)
            {
                regSubKey.SetValue("LibraryLocationPath", tempPath);
            }
        }

       

        public String TempPath
        {
            get { return tempPath; }
            set { tempPath = value; }
        }
    }
}
