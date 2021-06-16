using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using iaforms;

namespace iaprop
{
    static class Program
    {
        /// <summary>
        /// The main entry point for the application.
        /// </summary>
        [STAThread]
        static void Main(string[] args)
        {
           
            string file = "";

            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            bool single = FileArg(args, ref file);
            if (file.Length == 0)
            {
                string box_msg = "No arguments";
                string box_title = "Image Archive";
                MessageBox.Show(box_msg, box_title);

            }
            if (FileArg(args, ref file))
            {
                string fileName = Path.GetFileName(file);
                string path = Path.GetDirectoryName(file);
                string fullPath = path + "\\.imga\\metadata\\" + fileName + ".xml";
                Application.Run(new PropertiesForm(fullPath));
            }
            else
            {
                //string box_msg = file;
                //string box_title = "Image Archive";
                // MessageBox.Show(box_msg, box_title);
                
                Application.Run(new MainPropertiesForm(file));
            }
        }

        static bool FileArg(string[] args, ref string file)
        {
            bool single = true;
            file = "";
            if (args.Length == 1)
            {
                file = args[0];
            }
            else if (args.Length == 2)
            {
                if (args[0] == "-f")
                {
                    file = args[1];
                    single = false;
                }
            }
            return single;
        }
    }
}
