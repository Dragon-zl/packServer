#include "getpost.h"

Getpost :: Getpost(){
    getfilepath = "../../source"
    filesize = 0;
    writeIndex = 0;
}
Getpost :: ~Getpost(){

}
Getpost *::Instance(){
    static Getpost inst;
    return &inst;
}
/*通过文件名判断 文件是否存在*/
bool Getpost::FileExit(){
    if (access(getfilepath.c_str(), F_OK) == 0)
    {
        return true;
    }
    else{
        return false;
    }
}
/*获取文件大小*/
size_t Getpost:: GetFileSize()
{
    //获取文件属性
    stat(getfilepath.c_str(), &m_file_stat);
    //保存文件大小
    return m_file_stat.st_size;
}
/*将文件映射*/
void Getpost::MmapFile(){
    //打开文件
    int fd = open(getfilepath.c_str(), O_RDONLY);
    //将文件进行映射
    fileAddressMmap = (char *)mmap(0, filesize, PROT_READ, MAP_PRIVATE, fd, 0);
    close(fd);
}
/*判断文件是否存在，存在则进行内存映射*/
bool Getpost::FileExit(std::string& filepath)
{
    /*拼接成 文件路径*/
    getfilepath += filepath;
    if(FileExit())
    {
        /*获取文件大小*/
        filesize = GetFileSize();
        /*将文件进行映射*/
        MmapFile();
        return true;
    }
    else{
        return false;
    }

}