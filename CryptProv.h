#include <iostream>

#pragma once

class CryptProv
{
	private:
		static char                         FUNC_ENCRYPT_SINGULAR(char C_CHARACTER);
		static char                         FUNC_DECRYPT_SINGULAR(char C_CHARACTER);
	public:
		static void                         FUNC_ENCRYPT_FILE(std::string STR_FPATH);
		static void                         FUNC_DECRYPT_FILE(std::string STR_FPATH);
};

