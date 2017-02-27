using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Runtime.InteropServices;
using System.Text;
using System.Windows.Forms;

namespace top_win_desktop
{
    public partial class Form1 : Form
    {
        public delegate bool CallBack(int hwnd, int y);
        [DllImport("user32")]
        public static extern int EnumWindows(CallBack x, int y);
        [DllImport("user32")]
        private static extern int GetWindowText(int hWnd, StringBuilder title, int size);
        [DllImport("user32")]
        public static extern int GetParent(int hwnd);
        [DllImport("user32")]
        public static extern int IsWindowVisible(int hwnd);
        [DllImport("user32")]
        public static extern int MoveWindow(int hWnd, int x, int y, int nWidth, int nHeight, bool BRePaint);

        public struct Rect
        {
            public int Left;
            public int Top;
            public int Right;
            public int Bottom;

            public int Width { get { return Right - Left; } }
            public int Height { get { return Bottom - Top; } }
        }
        [DllImport("user32.dll")]
        public static extern bool GetWindowRect(int hWnd, ref Rect lpRect);

        public const int SW_SHOWMAXIMIZED = 3;
        public const int SW_MAXIMIZE = 3;
        public const int SW_SHOWNOACTIVATE = 4;
        public const int SW_SHOW = 5;
        [DllImport("user32.dll")]
        public static extern int ShowWindow(int hwnd, int nCmdShow);

        Screen main_screen;
        Screen sub_screen;
        List<int> hwnd_list = new List<int>();

        public Form1()
        {
            InitializeComponent();
        }

        public bool check_top_visible_win(int hwnd, int lparam)
        {
            int parent_hwnd = GetParent(hwnd);
            if (parent_hwnd == 0 && IsWindowVisible(hwnd) == 1)
            {
                StringBuilder sb = new StringBuilder(256);
                GetWindowText(hwnd, sb, sb.Capacity);
                if (sb.Length > 0)
                {
                    this.lst_topwin.Items.Add(sb.ToString());
                    hwnd_list.Add(hwnd);
                }
            }
            return true;
        }

        public void Msg(string fmt, params object[] args)
        {
            StringBuilder sb = new StringBuilder(1024);
            sb.AppendFormat(fmt, args);
            txtMsg.Text = sb.ToString() + "\r\n" + txtMsg.Text;
        }

        void move_and_center_hwnd(int hwnd, Screen s)
        {
            Rect rt = new Rect();
            Rectangle wrt = s.WorkingArea;

            ShowWindow(hwnd, SW_SHOWNOACTIVATE);
            GetWindowRect(hwnd, ref rt);
            MoveWindow(hwnd,
                wrt.Left + Math.Max(0, wrt.Width - rt.Width) / 2,
                wrt.Top + Math.Max(0, wrt.Height - rt.Height) / 2,
                Math.Min(wrt.Width, rt.Width),
                Math.Min(wrt.Height, rt.Height),
                true);
        }

        private void btn_desktop1_Click(object sender, EventArgs e)
        {
            int sel_idx = lst_topwin.SelectedIndex;
            if (sel_idx < 0)
            {
                return;
            }

            move_and_center_hwnd(hwnd_list[sel_idx], main_screen);
        }

        private void btn_desktop2_Click(object sender, EventArgs e)
        {
            int sel_idx = lst_topwin.SelectedIndex;
            if (sel_idx < 0)
            {
                return;
            }

            move_and_center_hwnd(hwnd_list[sel_idx], sub_screen);
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            main_screen = Screen.PrimaryScreen;
            btn_refresh_Click(null, null);

            for (int i = 0; i < Screen.AllScreens.Length; i++)
            {
                var s = Screen.AllScreens[i];
                Msg("[{0}], ({1},{2},{3},{4})", s.DeviceName, s.WorkingArea.Left, s.WorkingArea.Top, s.WorkingArea.Width, s.WorkingArea.Height);
                if (s.DeviceName != main_screen.DeviceName)
                {
                    sub_screen = s;
                    break;
                }
            }
        }

        private void btn_refresh_Click(object sender, EventArgs e)
        {
            this.lst_topwin.Items.Clear();
            hwnd_list.Clear();
            EnumWindows(this.check_top_visible_win, 0);
        }

        private void btn_all_desktop1_Click(object sender, EventArgs e)
        {
            for(int i = 0; i < hwnd_list.Count; ++i)
            {
                move_and_center_hwnd(hwnd_list[i], main_screen);
            }
        }

        private void btn_all_desktop2_Click(object sender, EventArgs e)
        {
            for (int i = 0; i < hwnd_list.Count; i++)
            {
                move_and_center_hwnd(hwnd_list[i], sub_screen);
            }
        }
    }
}
