﻿
namespace iachkin
{
    partial class CheckInMultiForm
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            System.ComponentModel.ComponentResourceManager resources = new System.ComponentModel.ComponentResourceManager(typeof(CheckInMultiForm));
            this.buttonCancel = new System.Windows.Forms.Button();
            this.listViewImportFiles = new System.Windows.Forms.ListView();
            this.columnHeaderImage = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderDateModified = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderType = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderSize = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.columnHeaderFolder = ((System.Windows.Forms.ColumnHeader)(new System.Windows.Forms.ColumnHeader()));
            this.groupBoxImport = new System.Windows.Forms.GroupBox();
            this.buttonProperties = new System.Windows.Forms.Button();
            this.buttonImport = new System.Windows.Forms.Button();
            this.pictureBox1 = new System.Windows.Forms.PictureBox();
            this.groupBoxImport.SuspendLayout();
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).BeginInit();
            this.SuspendLayout();
            // 
            // buttonCancel
            // 
            this.buttonCancel.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonCancel.Location = new System.Drawing.Point(785, 480);
            this.buttonCancel.Name = "buttonCancel";
            this.buttonCancel.Size = new System.Drawing.Size(79, 29);
            this.buttonCancel.TabIndex = 11;
            this.buttonCancel.Text = "Cancel";
            this.buttonCancel.UseVisualStyleBackColor = true;
            // 
            // listViewImportFiles
            // 
            this.listViewImportFiles.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.listViewImportFiles.Columns.AddRange(new System.Windows.Forms.ColumnHeader[] {
            this.columnHeaderImage,
            this.columnHeaderDateModified,
            this.columnHeaderType,
            this.columnHeaderSize,
            this.columnHeaderFolder});
            this.listViewImportFiles.HideSelection = false;
            this.listViewImportFiles.Location = new System.Drawing.Point(24, 42);
            this.listViewImportFiles.Margin = new System.Windows.Forms.Padding(30, 20, 30, 30);
            this.listViewImportFiles.Name = "listViewImportFiles";
            this.listViewImportFiles.Size = new System.Drawing.Size(969, 421);
            this.listViewImportFiles.TabIndex = 0;
            this.listViewImportFiles.UseCompatibleStateImageBehavior = false;
            this.listViewImportFiles.View = System.Windows.Forms.View.Details;
            // 
            // columnHeaderImage
            // 
            this.columnHeaderImage.Text = "Image";
            this.columnHeaderImage.Width = 150;
            // 
            // columnHeaderDateModified
            // 
            this.columnHeaderDateModified.Text = "Date modified";
            this.columnHeaderDateModified.Width = 150;
            // 
            // columnHeaderType
            // 
            this.columnHeaderType.Text = "Type";
            this.columnHeaderType.Width = 120;
            // 
            // columnHeaderSize
            // 
            this.columnHeaderSize.Text = "Size";
            this.columnHeaderSize.Width = 100;
            // 
            // columnHeaderFolder
            // 
            this.columnHeaderFolder.Text = "Folder";
            this.columnHeaderFolder.Width = 250;
            // 
            // groupBoxImport
            // 
            this.groupBoxImport.Anchor = ((System.Windows.Forms.AnchorStyles)((((System.Windows.Forms.AnchorStyles.Top | System.Windows.Forms.AnchorStyles.Bottom) 
            | System.Windows.Forms.AnchorStyles.Left) 
            | System.Windows.Forms.AnchorStyles.Right)));
            this.groupBoxImport.Controls.Add(this.listViewImportFiles);
            this.groupBoxImport.Controls.Add(this.buttonCancel);
            this.groupBoxImport.Controls.Add(this.buttonProperties);
            this.groupBoxImport.Controls.Add(this.buttonImport);
            this.groupBoxImport.Location = new System.Drawing.Point(25, 74);
            this.groupBoxImport.Name = "groupBoxImport";
            this.groupBoxImport.RightToLeft = System.Windows.Forms.RightToLeft.No;
            this.groupBoxImport.Size = new System.Drawing.Size(1026, 531);
            this.groupBoxImport.TabIndex = 13;
            this.groupBoxImport.TabStop = false;
            this.groupBoxImport.Text = "Selected items for Import";
            // 
            // buttonProperties
            // 
            this.buttonProperties.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Left)));
            this.buttonProperties.Location = new System.Drawing.Point(24, 480);
            this.buttonProperties.Name = "buttonProperties";
            this.buttonProperties.Size = new System.Drawing.Size(95, 29);
            this.buttonProperties.TabIndex = 12;
            this.buttonProperties.Text = "Properties";
            this.buttonProperties.UseVisualStyleBackColor = true;
            // 
            // buttonImport
            // 
            this.buttonImport.Anchor = ((System.Windows.Forms.AnchorStyles)((System.Windows.Forms.AnchorStyles.Bottom | System.Windows.Forms.AnchorStyles.Right)));
            this.buttonImport.Location = new System.Drawing.Point(907, 480);
            this.buttonImport.Name = "buttonImport";
            this.buttonImport.Size = new System.Drawing.Size(86, 29);
            this.buttonImport.TabIndex = 10;
            this.buttonImport.Text = "Import";
            this.buttonImport.UseVisualStyleBackColor = true;
            // 
            // pictureBox1
            // 
            this.pictureBox1.Image = ((System.Drawing.Image)(resources.GetObject("pictureBox1.Image")));
            this.pictureBox1.InitialImage = ((System.Drawing.Image)(resources.GetObject("pictureBox1.InitialImage")));
            this.pictureBox1.Location = new System.Drawing.Point(25, 24);
            this.pictureBox1.Name = "pictureBox1";
            this.pictureBox1.Size = new System.Drawing.Size(32, 30);
            this.pictureBox1.TabIndex = 14;
            this.pictureBox1.TabStop = false;
            // 
            // CheckInForm
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(1081, 631);
            this.Controls.Add(this.pictureBox1);
            this.Controls.Add(this.groupBoxImport);
            this.Icon = ((System.Drawing.Icon)(resources.GetObject("$this.Icon")));
            this.Name = "CheckInForm";
            this.Text = "Check-in - ImgArchive";
            this.groupBoxImport.ResumeLayout(false);
            ((System.ComponentModel.ISupportInitialize)(this.pictureBox1)).EndInit();
            this.ResumeLayout(false);

        }

        #endregion

        private System.Windows.Forms.Button buttonCancel;
        private System.Windows.Forms.ListView listViewImportFiles;
        private System.Windows.Forms.ColumnHeader columnHeaderImage;
        private System.Windows.Forms.ColumnHeader columnHeaderDateModified;
        private System.Windows.Forms.ColumnHeader columnHeaderType;
        private System.Windows.Forms.ColumnHeader columnHeaderSize;
        private System.Windows.Forms.ColumnHeader columnHeaderFolder;
        private System.Windows.Forms.GroupBox groupBoxImport;
        private System.Windows.Forms.Button buttonProperties;
        private System.Windows.Forms.Button buttonImport;
        private System.Windows.Forms.PictureBox pictureBox1;
    }
}

