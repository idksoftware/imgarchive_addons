using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Text;
using System.Windows.Forms;

namespace iaforms
{
    public partial class KeywordForm : Form
    {
        public String editKeyword = null;

        public KeywordForm(String edit)
        {
            InitializeComponent();
            editKeyword = edit;
            textBoxAddKeyword.Text = editKeyword;
        }

        public String keyword { get { return textBoxAddKeyword.Text; } }
    }
}