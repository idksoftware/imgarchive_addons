using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace iachkin
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
                Application.Run(new CheckInSingleForm(file));
            }
            else
            {
                string box_msg = file;
                string box_title = "Image Archive";
                MessageBox.Show(box_msg, box_title);
                Application.Run(new CheckInMultiForm(file));
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
