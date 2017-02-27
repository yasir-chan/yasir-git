namespace top_win_desktop
{
    partial class Form1
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
            this.btn_desktop1 = new System.Windows.Forms.Button();
            this.btn_desktop2 = new System.Windows.Forms.Button();
            this.lst_topwin = new System.Windows.Forms.ListBox();
            this.btn_refresh = new System.Windows.Forms.Button();
            this.txtMsg = new System.Windows.Forms.TextBox();
            this.btn_all_desktop1 = new System.Windows.Forms.Button();
            this.btn_all_desktop2 = new System.Windows.Forms.Button();
            this.SuspendLayout();
            // 
            // btn_desktop1
            // 
            this.btn_desktop1.Location = new System.Drawing.Point(213, 41);
            this.btn_desktop1.Name = "btn_desktop1";
            this.btn_desktop1.Size = new System.Drawing.Size(75, 23);
            this.btn_desktop1.TabIndex = 0;
            this.btn_desktop1.Text = "移到主屏";
            this.btn_desktop1.UseVisualStyleBackColor = true;
            this.btn_desktop1.Click += new System.EventHandler(this.btn_desktop1_Click);
            // 
            // btn_desktop2
            // 
            this.btn_desktop2.Location = new System.Drawing.Point(213, 70);
            this.btn_desktop2.Name = "btn_desktop2";
            this.btn_desktop2.Size = new System.Drawing.Size(75, 23);
            this.btn_desktop2.TabIndex = 1;
            this.btn_desktop2.Text = "移到副屏";
            this.btn_desktop2.UseVisualStyleBackColor = true;
            this.btn_desktop2.Click += new System.EventHandler(this.btn_desktop2_Click);
            // 
            // lst_topwin
            // 
            this.lst_topwin.FormattingEnabled = true;
            this.lst_topwin.ItemHeight = 12;
            this.lst_topwin.Location = new System.Drawing.Point(1, 1);
            this.lst_topwin.Name = "lst_topwin";
            this.lst_topwin.Size = new System.Drawing.Size(206, 256);
            this.lst_topwin.TabIndex = 2;
            // 
            // btn_refresh
            // 
            this.btn_refresh.Location = new System.Drawing.Point(213, 1);
            this.btn_refresh.Name = "btn_refresh";
            this.btn_refresh.Size = new System.Drawing.Size(75, 23);
            this.btn_refresh.TabIndex = 3;
            this.btn_refresh.Text = "Refresh";
            this.btn_refresh.UseVisualStyleBackColor = true;
            this.btn_refresh.Click += new System.EventHandler(this.btn_refresh_Click);
            // 
            // txtMsg
            // 
            this.txtMsg.Location = new System.Drawing.Point(1, 266);
            this.txtMsg.Multiline = true;
            this.txtMsg.Name = "txtMsg";
            this.txtMsg.Size = new System.Drawing.Size(297, 92);
            this.txtMsg.TabIndex = 4;
            // 
            // btn_all_desktop1
            // 
            this.btn_all_desktop1.Location = new System.Drawing.Point(213, 114);
            this.btn_all_desktop1.Name = "btn_all_desktop1";
            this.btn_all_desktop1.Size = new System.Drawing.Size(75, 23);
            this.btn_all_desktop1.TabIndex = 5;
            this.btn_all_desktop1.Text = "全部主屏";
            this.btn_all_desktop1.UseVisualStyleBackColor = true;
            this.btn_all_desktop1.Click += new System.EventHandler(this.btn_all_desktop1_Click);
            // 
            // btn_all_desktop2
            // 
            this.btn_all_desktop2.Location = new System.Drawing.Point(213, 143);
            this.btn_all_desktop2.Name = "btn_all_desktop2";
            this.btn_all_desktop2.Size = new System.Drawing.Size(75, 23);
            this.btn_all_desktop2.TabIndex = 6;
            this.btn_all_desktop2.Text = "全部副屏";
            this.btn_all_desktop2.UseVisualStyleBackColor = true;
            this.btn_all_desktop2.Click += new System.EventHandler(this.btn_all_desktop2_Click);
            // 
            // Form1
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 12F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(297, 355);
            this.Controls.Add(this.btn_all_desktop2);
            this.Controls.Add(this.btn_all_desktop1);
            this.Controls.Add(this.txtMsg);
            this.Controls.Add(this.btn_refresh);
            this.Controls.Add(this.lst_topwin);
            this.Controls.Add(this.btn_desktop2);
            this.Controls.Add(this.btn_desktop1);
            this.MaximizeBox = false;
            this.Name = "Form1";
            this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
            this.Text = "Form1";
            this.TopMost = true;
            this.Load += new System.EventHandler(this.Form1_Load);
            this.ResumeLayout(false);
            this.PerformLayout();

        }

        #endregion

        private System.Windows.Forms.Button btn_desktop1;
        private System.Windows.Forms.Button btn_desktop2;
        private System.Windows.Forms.ListBox lst_topwin;
        private System.Windows.Forms.Button btn_refresh;
        private System.Windows.Forms.TextBox txtMsg;
        private System.Windows.Forms.Button btn_all_desktop1;
        private System.Windows.Forms.Button btn_all_desktop2;
    }
}

