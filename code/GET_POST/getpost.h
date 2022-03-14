#ifndef GETPOST_H
#define GETPOST_H

#include <cstring>
#include <unistd.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
class Getpost{

public:
    Getpost();
    ~Getpost();
    /*
        获取一个getpost实例
    */
    static Getpost* Instance();
    bool FileExit(std::string& filepath);
private:
    /*GET文件的映射首地址*/
    char * fileAddressMmap;
    /*文件路径*/
    std::string getfilepath;
    /*文件大小*/
    size_t filesize;
    /*索引*/
    size_t writeIndex;
    /*通过文件名判断 文件是否存在*/
    bool FileExit();
    /*获取文件大小*/
    size_t GetFileSize();
    /*将文件映射*/
    void MmapFile();
    
};



#endif