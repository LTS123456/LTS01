// ���� ifdef ���Ǵ���ʹ�� DLL �������򵥵�
// ��ı�׼�������� DLL �е������ļ��������������϶���� EX103_EXPORTS
// ���ű���ġ���ʹ�ô� DLL ��
// �κ�������Ŀ�ϲ�Ӧ����˷��š�������Դ�ļ��а������ļ����κ�������Ŀ���Ὣ
// EX103_API ������Ϊ�Ǵ� DLL ����ģ����� DLL ���ô˺궨���
// ������Ϊ�Ǳ������ġ�
#ifdef EX103_EXPORTS
#define EX103_API __declspec(dllexport)
#else
#define EX103_API __declspec(dllimport)
#endif

// �����Ǵ� Ex10.3.dll ������
class EX103_API CEx103 {
public:
	CEx103(void);
	// TODO:  �ڴ�������ķ�����
};

extern EX103_API int nEx103;

EX103_API int fnEx103(void);

EX103_API int factorial(int n);

EX103_API float convert(float deg);
