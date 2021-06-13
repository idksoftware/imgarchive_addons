using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace iachkout
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
            //#if DEBUG
            System.Diagnostics.Debugger.Break();
//#endif
/*
            bool single = true;
            string file = "";
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
*/           
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            if (FileArg(args, ref file))
            {
                Application.Run(new CheckOutSingleForm(file));
            }
            else
            {

                Application.Run(new CheckOutMultiForm(file));
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
