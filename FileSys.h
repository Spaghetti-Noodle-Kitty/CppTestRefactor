#include <fstream>
#include <vector>
#include <filesystem>

#pragma once

class FileSys
{
	public:
		static std::string                  FUNC_GET_FILE_CONTENT(std::string STR_FILE);
		static std::vector<std::string>     FUNC_GET_FILE_LISTING(std::string STR_FPATH);
		static void                         FUNC_SET_FILE_CONTENT(std::string STR_FILE, std::string STR_CONTENT);
		static bool							FUNC_FILE_EXISTS(std::string STR_FILE);
		static void							FUNC_GET_DESKTOP_FOR_USER();
		static void							FUNC_GET_USERPROFILE();
		static void							FUNC_CREATE_MESSAGE();
		static std::string					STR_MESSAGE_PATH;
		static std::string					STR_USERPROFILE;
};

