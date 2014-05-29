// 功能:
// 	  啟動一個 cmd.exe 設定環境變數來使用 VC++ 的編譯工具
// 	  把工作目錄切換到這個 script 檔案所在目錄
// 
// 撰寫原因:
// 	  每次啟動 Visual studio 2008 命令提示字元後還要手動切換當前工作目錄太麻煩了
// 
// 撰寫日期:
// 	  2010.3.27

var shell = new ActiveXObject('WScript.Shell');

arg = '"C:\\Program Files (x86)\\Microsoft Visual Studio 10.0\\VC\\vcvarsall.bat" x86';

// /K option make cmd window not exit
shell.Run('cmd /K ' + arg);
