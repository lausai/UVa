'�y�@�� cpp �ɮץΨӼg uva �D��

Option Explicit

Dim cpp_content : cpp_content = "#include <cstdio>" & vbNewLine & vbNewLine & _
				  				"using namespace std;" & vbNewLine & vbNewLine & _
				  				"int main()" & vbNewLine & "{" & vbNewLine & vbTab & _
				  				"return 0;" & vbNewLine & "}"

Dim file_name, fso, f

file_name = InputBox("��J�ɮצW��")

If file_name = "" Then
	Wscript.Quit
Else
	file_name = file_name & ".cpp"
End If

Set fso = CreateObject("Scripting.FileSystemObject")

If fso.FileExists(file_name) Then
	MsgBox "�ɮפw�s�b"
Else
	Set f = fso.CreateTextFile(file_name)
	f.Write cpp_content
	f.Close
End If
