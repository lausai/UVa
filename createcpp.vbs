'造一個 cpp 檔案用來寫 uva 題目

Option Explicit

Dim cpp_content : cpp_content = "#include <cstdio>" & vbNewLine & vbNewLine & _
				  				"using namespace std;" & vbNewLine & vbNewLine & _
				  				"int main()" & vbNewLine & "{" & vbNewLine & vbTab & _
				  				"return 0;" & vbNewLine & "}"

Dim file_name, fso, f

file_name = InputBox("輸入檔案名稱")

If file_name = "" Then
	Wscript.Quit
Else
	file_name = file_name & ".cpp"
End If

Set fso = CreateObject("Scripting.FileSystemObject")

If fso.FileExists(file_name) Then
	MsgBox "檔案已存在"
Else
	Set f = fso.CreateTextFile(file_name)
	f.Write cpp_content
	f.Close
End If
