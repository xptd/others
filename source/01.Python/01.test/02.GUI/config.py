#config parames
#
import os;
current_file_path = os.path.dirname(os.path.abspath(__file__));
#global
g_font=("Monaco", 9);
g_theme ="dark";
#icon
g_log_win_icon_name = "title.ico";

#log window size
g_log_win_width = 430;
g_log_win_height =325;
#icon path;

g_log_win_icon = current_file_path+os.sep+"image"+os.sep+g_log_win_icon_name;
#print(g_log_win_icon)



