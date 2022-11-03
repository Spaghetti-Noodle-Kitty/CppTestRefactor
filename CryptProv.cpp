#include <iostream>
#include "CryptProv.h"
#include "FileSys.h"
#include "Constants.h"

static FileSys CL_FILESYS;
static Constants CL_CONST;

char CryptProv::FUNC_ENCRYPT_SINGULAR(char C_CHARACTER)
{
    return C_CHARACTER += CL_CONST.INT_SHIFT;
}

char CryptProv::FUNC_DECRYPT_SINGULAR(char C_CHARACTER)
{
    return C_CHARACTER -= CL_CONST.INT_SHIFT;
}

void CryptProv::FUNC_ENCRYPT_FILE(std::string STR_FPATH)
{
    std::string STR_BASE;
    char* C_BUFF{};

    STR_BASE = CL_FILESYS.FUNC_GET_FILE_CONTENT(STR_FPATH);

    for (int I_ITER = 0; I_ITER < STR_BASE.length(); ++I_ITER)
    {
        C_BUFF += FUNC_ENCRYPT_SINGULAR(STR_BASE.at(I_ITER));
    }

    try
    {
        CL_FILESYS.FUNC_SET_FILE_CONTENT(STR_FPATH, C_BUFF);
    }
    catch(...){}

}

void CryptProv::FUNC_DECRYPT_FILE(std::string STR_FPATH)
{
    std::string STR_BASE;
    char* C_BUFF{};

    STR_BASE = CL_FILESYS.FUNC_GET_FILE_CONTENT(STR_FPATH);

    for (int I_ITER = 0; I_ITER < STR_BASE.length(); ++I_ITER)
    {
        C_BUFF += FUNC_DECRYPT_SINGULAR(STR_BASE.at(I_ITER));
    }

    try
    {
        CL_FILESYS.FUNC_SET_FILE_CONTENT(STR_FPATH, C_BUFF);
    }
    catch (...) {}
}