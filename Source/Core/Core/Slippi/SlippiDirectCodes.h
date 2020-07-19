#pragma once

#include "Common/CommonTypes.h"
#include <atomic>
#include <string>
#include <vector>
#include <thread>

class SlippiDirectCodes
{
    public:
        static const uint8_t SORT_BY_TIME = 1;
        static const uint8_t SORT_BY_FAVORITE = 2;
        static const uint8_t SORT_BY_NAME = 3;

        struct CodeInfo
        {
            std::string connectCode = "";
            std::string lastPlayed = "";
            bool isFavorite = false;
        };

        SlippiDirectCodes();
        ~SlippiDirectCodes();

        void ReadFile();
        void AddOrUpdateCode(std::string code);
        std::string get(u8 index);
        void Sort(u8 sortByProperty = SlippiDirectCodes::SORT_BY_TIME);

    protected:
        void WriteFile();
        std::string getCodesFilePath();
        std::vector<CodeInfo> parseFile(std::string fileContents);
        std::vector<CodeInfo> directCodeInfos;
        
};