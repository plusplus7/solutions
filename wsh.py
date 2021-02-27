import win32gui
import win32api
import win32con
import win32clipboard as w
import time
 
def prepare_message(msg):
    w.OpenClipboard()
    w.EmptyClipboard()
    w.SetClipboardData(win32con.CF_UNICODETEXT, msg)
    w.CloseClipboard()

def send_message(hwnd):
    win32gui.SendMessage(hwnd, 770, 0, 0)
    time.sleep(0.5)
    win32gui.SendMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)
    time.sleep(0.5)
    win32gui.SendMessage(hwnd, win32con.WM_KEYDOWN, win32con.VK_ESCAPE, 0)
    time.sleep(0.5)
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN| win32con.MOUSEEVENTF_ABSOLUTE,1,1); time.sleep(0.1); win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_ABSOLUTE,1, 1)

def invoke(number_of_context, message):

    #prepare_message(message)

    inplay_children = []

    def is_win_ok(hwnd, args):
        s = win32gui.GetWindowText(hwnd)
        print(s)
        if "%d个会话" % number_of_context in s:
            inplay_children.append((hwnd, s))

    win32gui.EnumChildWindows(0, is_win_ok, None)

    hwnd = inplay_children[0][0]
    win32gui.ShowWindow(hwnd,win32con.SW_SHOW)
    win32gui.SetForegroundWindow(hwnd); 
    win32gui.SetWindowPos(hwnd, None, 377,0, 800, 800, 0)
    win32api.SetCursorPos((650,730))

    print("续火机器人：准备发送信息\n倒计时5秒")
    for i in range(5):
        print("        " + str(i))
        time.sleep(1)
    
    time.sleep(1)
    for i in range(0, number_of_context):
        send_message(hwnd)

def select_target():
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN| win32con.MOUSEEVENTF_ABSOLUTE,1,1); time.sleep(0.1); win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_ABSOLUTE,1, 1)
    time.sleep(0.1);
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN| win32con.MOUSEEVENTF_ABSOLUTE,1,1); time.sleep(0.1); win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_ABSOLUTE,1, 1)
    time.sleep(0.1);
    win32api.mouse_event(win32con.MOUSEEVENTF_WHEEL ,0,0, -45)
    time.sleep(1);

def orchestrate(number_of_target, name = "QQ", offset = 0):
    hwnd = win32gui.FindWindow(None, name)
    s = win32gui.GetWindowText(hwnd)
    time.sleep(1)
    win32gui.ShowWindow(hwnd,win32con.SW_SHOW)
    win32gui.SetForegroundWindow(hwnd); 
    win32gui.SetWindowPos(hwnd, None, 77,0, 100, 800, 0)

    time.sleep(1)
    win32api.SetCursorPos((225,350 + offset*30))
    win32api.mouse_event(win32con.MOUSEEVENTF_LEFTDOWN| win32con.MOUSEEVENTF_ABSOLUTE,1,1); time.sleep(0.5); win32api.mouse_event(win32con.MOUSEEVENTF_LEFTUP | win32con.MOUSEEVENTF_ABSOLUTE,1, 1)
    win32api.SetCursorPos((173,375 + offset*45))
    for i in range(0, number_of_target):
        select_target()

if __name__ == "__main__":
    msg = "212"#open("msg.txt").readline()
    import sys
    print("续火机器人: 开始执行，目标" + sys.argv[1] + "人，内容为\"" + msg + "\"\n倒计时5秒")
    for i in range(5):
        print("        " + str(i))
        time.sleep(1)
    orchestrate(int(sys.argv[1]), "QQ", int(sys.argv[2]))
    
    invoke(int(sys.argv[1]), msg)
    print("续火机器人: 执行成功")

"""
# win32gui.SendMessage(handle, 770, 0, 0)
# win32gui.SendMessage(handle, win32con.WM_KEYDOWN, win32con.VK_RETURN, 0)

win32gui.ShowWindow(hwnd,win32con.SW_SHOW); win32gui.SetForegroundWindow(hwnd); time.sleep(1); win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN,1,1); time.sleep(0.5); win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP,1, 1)

win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN| win32con.MOUSEEVENTF_ABSOLUTE,1,1); time.sleep(0.5); win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP | win32con.MOUSEEVENTF_ABSOLUTE,1, 1)
win32con.MOUSEEVENTF_ABSOLUTE
KeyboardInterrupt
win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN| win32con.MOUSEEVENTF_ABSOLUTE,1,1); time.sleep(0.5); win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP | win32con.MOUSEEVENTF_ABSOLUTE,1, 1)
KeyboardInterrupt
win32api.SetCursorPos((0,0))
win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTDOWN| win32con.MOUSEEVENTF_ABSOLUTE,1,1); time.sleep(0.5); win32api.mouse_event(win32con.MOUSEEVENTF_RIGHTUP | win32con.MOUSEEVENTF_ABSOLUTE,1, 1)
win32api.GetCursorPos()
(2100, 538)
win32api.GetCursorPos()
(0, 202)
win32api.mouse_event(win32con.MOUSEEVENTF_WHEEL ,1,1, 220);
win32api.mouse_event(win32con.MOUSEEVENTF_WHEEL ,1,1, 220);
"""