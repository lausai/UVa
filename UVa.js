// �\��:
// 	  �Ұʤ@�� cmd.exe �]�w�����ܼƨӨϥ� VC++ ���sĶ�u��
// 	  ��u�@�ؿ�������o�� script �ɮשҦb�ؿ�
// 
// ���g��]:
// 	  �C���Ұ� Visual studio 2008 �R�O���ܦr�����٭n��ʤ�����e�u�@�ؿ��ӳ·ФF
// 
// ���g���:
// 	  2010.3.27

var shell = new ActiveXObject('WScript.Shell');

arg = '"C:\\Program Files (x86)\\Microsoft Visual Studio 10.0\\VC\\vcvarsall.bat" x86';

// /K option make cmd window not exit
shell.Run('cmd /K ' + arg);
