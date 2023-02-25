%{
#include<stdio.h>
#include<stdlib.h>
#include"global.h"

%}
%%
[\n]	{line++;}
"#"[A-Za-z0-9<>]+"."?[A-Za-z0-9<>]*	{ fprintf(hout,yytext);}
"using namespace "	{ns=1; ns1=1;}
"<<"|">>"	{fprintf(fout,"\n%s\t%d\n",yytext,line);}
("int"|"char")?[" "]?"main"[" "]*"("[" "]*(("int"|"char")[" "]?[A-Za-z]*(",")?)*")"	{fout=fopen(yytext,"w"); f=1; fprintf(fns,yytext); fprintf(fns,"\n");me=1;}
("int"|"char")?[" "]?[A-Za-z]*[" "]*"("[" "]*(("int"|"char")[" "]?[A-Za-z]*(",")?)*")"	{fout=fopen(yytext,"w"); f=1; fprintf(fns,yytext); fprintf(fns,"\n");if(yytext=="int main()") me=1;}
("int"|"char"|"float")	{vd=1; type=yytext;fprintf(fout,"%s\t%d",yytext,line);}

[A-Za-z]+	{if(ns==1)	{ printf("Namespace used: %s\n",yytext);ns=0;}	else if(vd==1) {fprintf(vout,yytext);fprintf(vout,"\t");fprintf(vout,type);fprintf(vout,"\n");fprintf(fout,"%s\t%d",yytext,line);	}	else fprintf(fout,"%s\t%d",yytext,line);	}
"("	{pr++;fprintf(fout,"\n%s\t%d\n",yytext,line);}
")"	{pr--;fprintf(fout,"\n%s\t%d\n",yytext,line);}
"{"	{br++;fprintf(fout,"%s\t%d",yytext,line);}
"}"	{br--;	fprintf(fout,"%s\t%d",yytext,line);if(br==0&&f==1)	{  f=0; fclose(fout);}}
";"	{if(vd==1)	{vd=0;fprintf(fout,"\n%s\t%d\n",yytext,line);} else fprintf(fout,"\n%s\n",yytext); }
.	{fprintf(fout,"\n%s\n",yytext,line); }
%%

main(int argc, char * argv[])
{

	hout=fopen("header.txt","w");
	vout=fopen("variable.txt","w");
	fns=fopen("functions.txt","w");
	br=0;
	yyin=fopen(argv[1],"r");
	logger=fopen("log.txt","w");
	
if(yyin==NULL) printf("input file not opened");
	yylex();
if(me==0) {	fprintf(logger,"No main function"); }
if(ns1==0) {	fprintf(logger,"Namespace unrecognised"); }
if(br!=0||pr!=0) { fprintf(logger,"Braces not balanced"); }
if(vd!=0) { fprintf(logger,"Missing semicolon"); }
	return 0;
}

yywrap()
{
	return 1;
}