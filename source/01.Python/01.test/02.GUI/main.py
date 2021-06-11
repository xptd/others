
from tkinter import*;
from tkinter import ttk;
from XptdWidgets import *;
from config import *;

def init_win(win,**kw):
	if isinstance(win,Tk):
		#set title
		win.title(kw.get("title"));
		#set resizeable
		win.resizable(kw.get("x_disresize"),kw.get("y_disresize"));
		#set center
		screen_width = win.winfo_screenwidth();
		screen_height = win.winfo_screenheight();
		win.geometry("{0}x{1}+{2}+{3}".format(kw.get("width"),
			kw.get("height"),((screen_width-kw.get("width")) // 2),
			((screen_height-kw.get("height")) // 2)));
		#set icon
		icon = kw.get("icon_path");
		if icon:
			if icon.endswith(".ico"):
				win.iconbitmap(default = icon);
		
		return True;

	else:
		print("win type err");
		return False;


if __name__ == "__main__":
	log_in_win = Tk();
	#set title
	#
	log_in_win_config ={
	"title":"WeHi",
	"width":g_log_win_height,
	"height":g_log_win_height,
	"x_disresize":False,
	"y_disresize":False,
	"icon_path":g_log_win_icon,
	};

	if not init_win(log_in_win,**log_in_win_config):
		print("window init err");
		sys.exit();
	log_in_win.mainloop();
	

