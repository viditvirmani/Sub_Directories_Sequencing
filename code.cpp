#include <stdio.h>
#include<bits/stdc++.h>
#include <dirent.h>
#include <sys/stat.h>
#include<stdio.h>
using namespace std;
int main(void)
{
    struct dirent *de;  // Pointer for directory structure (comes from dirent.h)
    struct stat info;   // structure for information about each entry (comes from sys/stat.h)
    
    string add_directory ="/Vidit"  //change this string name to the directory you want to add.
    
    DIR *my_dir = opendir(add_directory.c_str()); // opendir() returns a pointer of DIR type.
    string directory= "C:/Vidit";
    if (my_dir == NULL){
        return 0;
    }

    int counter=0;
    while ((de = readdir(my_dir)) != NULL)
    {
        if(de->d_name[0]!='.'){
                cout<<de->d_name<<" "; //print the folder names
                string path = directory+"/"+string(de->d_name); //make path
                cout<<path<<"\n"; //print their paths
                stat(path.c_str(),&info);
                string x=directory+"/"+to_string(counter); //new name for the directory
                rename(path.c_str(),x.c_str());
                counter++;

        }

    }
    closedir(my_dir);
    return 0;
}
