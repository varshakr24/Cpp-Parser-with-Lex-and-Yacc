#include<iostream>
#include<fstream>
#include <string>
#include<string.h>
#include <vector>
#include<malloc.h>
#include <map>
#include<stdlib.h>
#include<sstream>
#include<cstring>
#include<algorithm>
using namespace std;

std::vector <std::string> words; // Vector to hold our words we read in.
std::string str; // Temp string to
typedef std::map<std::string,int> var_map;

var_map v;
typedef std::map<int,int> loop_map;

loop_map loop_v, line_map;
int mnf=0;
int nest=0;
//  std::ofstream fout("output.txt");
int nest_flag=1;
int nt;
int i;
int loop_exists=0;
int rec=0;
int get_line;
int main_flag=0;
int main_i=0;
std::vector<string> list;


int main(int argc, char * argv[])
{
  std::cout << "Read from a file!" << std::endl;
//  argv[1]="int main()";
  std::ifstream fin("int main()");
  std::ofstream fout("log.txt",ios::app);
 // Open it up!

 fout<<"In Function: int main() "<<endl;

 //fout<<"Output File: log"<<endl;
 //char cmd[5]="gcc ";
 //char cmd2[20]=argv[1];
 //std::strcat(cmd, argv[1]);
 
 //int ret_val=system(cmd);
 /*if(ret_val!=0){
 	std::strcat(cmd," 2>output.txt");
 	system(cmd);
 	fout<<"Code compiling not successful!!!"<<endl;
 	exit(0);
 }*/
 
 //fout<<"Code Compilation successful!!!\n"<<endl;
 int flag=0;
 int length;
 
 int line=0;
string t;
int h=0;
    
/*    while(getline(fin,t)){

    istringstream iss(t);	
  while (iss >> str) // Will read up to eof() and stop at every
  { 
  
      words.push_back(str);
      cout<<h<<endl;
      line_map.insert(make_pair(h++,line));
      //cout<<str<<"\t"<
      
    	if(str=="main")
  	{
  		main_i=h-1;
	  fout<<"// Main function: line : \n"<<line<<endl; 
	    
	 
	   //flag=1;
	  }        // whitespace it hits. (like spaces!)

  } line++;
}
*/
int vd=0,ci=0,co=0;
int count=0;
int j;
int tmp;
int line;
  for (i = 0; i < words.size(); ++i){ 


	  if(i==0) {if( words.at(i)=="{" ) ; else fout<<" Required \"{\" at the beginning of input";}  
  
if(words.at(i)=="int"||words.at(i)=="char") { if(ci==1||co==1||vd==1) fout<<"Expected operator before "<<words.at(i)<<endl;
vd=1;  j=i; while(i<words.size()){i++; if(words.at(i)==";"||words.at(i)=="cin"||words.at(i)=="cout"||words.at(i)=="for") break;} if(words.at(i)==";"&&vd==1) vd=0;}	

if(words.at(i)=="cin") {if(ci==1||co==1||vd==1) {fout<<"Expected operator before "<<words.at(i)<<endl; ci=1;co=0;vd=0;}
if(words.at(++i)==">>") ; else fout<<"Operator following cin improper"<<endl;	while(i<words.size()){  if(words.at(i)==";"||words.at(i)=="cin"||words.at(i)=="cout"||words.at(i)=="for") break;i++;} if(words.at(i)==";"&&ci==1) ci=0;}

if(words.at(i)=="cout") {if(ci==1||co==1||vd==1) {fout<<"Expected operator before "<<words.at(i)<<endl; co=1; ci=0;vd=0;}if(words.at(++i)=="<<") ; else fout<<"Operator following cout improper"<<endl; while(i<words.size()){  if(words.at(i)==";"||words.at(i)=="cin"||words.at(i)=="cout"||words.at(i)=="for") break;i++;} if(words.at(i)==";"&&co==1) co=0;}

if(words.at(i)=="for"){	if(words.at(++i)=="(") { while(i<words.size()){ i++; if(words.at(i)==")"||words.at(i)=="cin"||words.at(i)=="cout"||words.at(i)=="for") break; if(words.at(i)==";") count++; } if(words.at(i)==")") ; else fout<<"Improper FOR loop format"<<endl; if(count!=2) fout<<"\"For\" loop format improper"<<endl; count=0;}}

line=words.size
}

  return 0;
}
