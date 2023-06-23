# Computer virus principles and prevention-virus design
 
💡The functions that this virus can perform are as follows:  
1) Deletes files of a specific type in a specified directory (in the text, files of type .pptx, .xlsx)  
2) create a junk file in the specified directory  
3) modify the contents of a .c file in the specified directory (i.e. overwrite the contents of a .c file in the specified directory with the contents of a specific .c file)  
4) Generate a specific .exe junk file in the specified directory  

💡Results show

1: Before running, create 1.xlsx, 2.pptx and helloworld.c files in the virus_test folder. Then create a virus file, virus_create.c, which is infected with helloworld.c. The original contents of the helloworld.c and virus_create.c files are as follows

![image](https://github.com/Frannie1020/Computer-virus-principles-and-prevention--virus-design/assets/137517674/0aa6a966-b81d-4f3f-9cb3-a93fe94d0f3a)

![image](https://github.com/Frannie1020/Computer-virus-principles-and-prevention--virus-design/assets/137517674/c371c82b-52d1-43cd-8cbd-efba1caeda07)


![image](https://github.com/Frannie1020/Computer-virus-principles-and-prevention--virus-design/assets/137517674/467f5ad4-6d5d-486a-80de-df29f373b8ca)

![image](https://github.com/Frannie1020/Computer-virus-principles-and-prevention--virus-design/assets/137517674/8d51a40d-1766-44cc-b43c-9cafbdf86c81)

2: Open virus.cpp, compile and run, you will find the virus.exe file generated, double click on the virus.exe, you can find in the virus_test folder, has deleted all the .xlsx, .pptx files

![image](https://github.com/Frannie1020/Computer-virus-principles-and-prevention--virus-design/assets/137517674/3c03c179-8dbe-4d8e-b255-831d19c89e1a)

3: Open the virus_test folder, the following screen appears, where 1.xlsx,2.pptx has been deleted, then there is also a junk file XXXa07012 and two virus programs worm1/worm2.exe

![image](https://github.com/Frannie1020/Computer-virus-principles-and-prevention--virus-design/assets/137517674/e011ea17-76d3-4205-9a82-0e90d5cdd7cc)

4: If you open the helloworld.c file, you will find that the contents become the contents of virus_create.c. This means that helloword.c is infected by the virus_create.c file.

![image](https://github.com/Frannie1020/Computer-virus-principles-and-prevention--virus-design/assets/137517674/12362d66-bdfe-43be-96ca-da03f2dbc36f)

