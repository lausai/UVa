'�\��:
'	�Ұʤ@�� cmd.exe �]�w�����ܼƨӨϥ� VC++ ���sĶ�u��
'	��u�@�ؿ�������o�� script �ɮשҦb�ؿ�
'
'���g��]:
'	�C���Ұ� Visual studio 2008 �R�O���ܦr�����٭n��ʤ�����e�u�@�ؿ��ӳ·ФF
'
'���g���:
'	2010.3.27

Option Explicit		'�j���ܼƻݫŧi

Dim wsh_shell, arg

Set wsh_shell = CreateObject("WScript.Shell")

'Visual studio 2008 �R�O���ܦr���]�w��
arg = "C:\Program Files\Microsoft Visual Studio 9.0\VC\vcvarsall.bat"

'/K :����r�ꤤ�Ҵy�z���R�O�M��O�d�R�O����
wsh_shell.Run("cmd /K""" & arg & """")

'SendKeys method �|��e�������ðe�X�T��
'�o�̥������Ȱ��{���@�U����Ұʪ��R�O���������Ы� �_�h SendKeys �|�줣�쥦
'Wscript.sleep 300

'�e�X ctrl+whitespace �H�������U�誺�ܾe��J�k
'�n�e�X�⦸ ctrl+whitespace �~�|�����ܾe��J�k ��]����
'wsh_shell.SendKeys "^ ^ "