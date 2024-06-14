#pragma once

#include "MartChanger.h"

#include <time.h>

class PriceChanger : public MartChanger
{
public:

    PriceChanger() {}
    ~PriceChanger() {}

    void SetItemFolderPath(CString path)
    {
        item_folder_path = path;
    }

    CString LoadCurrentPrice(CString name)
    {
        if (name == NULL_NAME)
        {
            current_item_file = CString();
            return L"0";
        }

        if (item_folder_path.GetLength() <= 0u)
        {
            last_error = Error::NULL_ITEM_DATA_PATH;
            return CString();
        }
        
        int ID = GetItemID(name);
        if (ID < 0)
        {
            last_error = Error::ITEM_DOESNT_EXIST;
            return CString();
        }
        
        wchar_t ID_str[16u];
        memset(ID_str, 0, 16u);
        _itow_s(ID, ID_str, 10);
        
        wchar_t file_name[1024u];
        memset(file_name, 0, 1024u);

        // CAUTION: professional hardcoding ahead
        short digits = 1;
        if (ID >= 10)
            digits = 2;
        if (ID >= 100)
            digits = 3;
        if (ID >= 1000)
            digits = 4;
        switch (digits)
        {
        case 1:
            swprintf_s(file_name, 1024u, L"%s\\4_0000000%s.bin", item_folder_path.GetBuffer(), ID_str);
            break;
        case 2:
            swprintf_s(file_name, 1024u, L"%s\\4_000000%s.bin", item_folder_path.GetBuffer(), ID_str);
            break;
        case 3:
            swprintf_s(file_name, 1024u, L"%s\\4_00000%s.bin", item_folder_path.GetBuffer(), ID_str);
            break;
        case 4:
            swprintf_s(file_name, 1024u, L"%s\\4_0000%s.bin", item_folder_path.GetBuffer(), ID_str);
            break;
        }
        // end of hardcoding zone

        FILE* file;
        _wfopen_s(&file, file_name, L"r");
        if (!file)
        {
            last_error = Error::ITEM_DOESNT_EXIST;
            return CString();
        }

        unsigned short int price_tmp;
        char* price_ptr = (char*)&price_tmp;
        price_ptr[0] = fgetc(file);
        price_ptr[1] = fgetc(file);
        
        fclose(file);
        
        int price = (int)price_tmp * 10;
        wchar_t price_str[16u];
        memset(price_str, 0, 16u);
        _itow_s(price, price_str, 10);

        current_item_file = file_name;
        return price_str;
    }

    int ChangeCurrentPrice(CString price_str)
    {
        if (current_item_file.GetLength() <= 0u)
        {
            last_error = Error::NO_ITEM_SELECTED_TO_SAVE;
            return -1;
        }

        int price = _wtoi(price_str.GetBuffer());

        CString backup_folder = current_item_file;
        int slash_position = backup_folder.ReverseFind(L'\\');

        CString item_file_name = current_item_file.Right(current_item_file.GetLength() - slash_position - 1);

        backup_folder = backup_folder.Left(slash_position);
        slash_position = backup_folder.ReverseFind(L'\\');
        backup_folder = backup_folder.Left(slash_position + 1);

        backup_folder.Insert(slash_position + 1, L"MartEditItemDataBackUp\\");

        CString backup_item_file = backup_folder;
        backup_item_file.Insert(backup_item_file.GetLength(), item_file_name);

        time_t t = time(NULL);
        tm date;
        localtime_s(&date, &t);
        wchar_t dateStr[128];
        memset(dateStr, 0, 128);
        swprintf_s(dateStr, L"_%d-%02d-%02d_%02d-%02d-%02d", date.tm_year + 1900, date.tm_mon + 1, date.tm_mday, date.tm_hour, date.tm_min, date.tm_sec);
        backup_item_file.Insert(backup_item_file.GetLength(), dateStr);

        backup_item_file.Insert(backup_item_file.GetLength(), L".bak");

        if (CopyFileW(current_item_file, backup_item_file, FALSE) == FALSE && GetLastError() == (DWORD)3)
        {
            if (_wmkdir(backup_folder) < 0)
            {
                last_error = Error::CANT_OPEN_ITEM_FILE;
                return -1;
            }
            if (CopyFileW(current_item_file, backup_item_file, FALSE) == FALSE)
            {
                last_error = Error::CANT_OPEN_ITEM_FILE;
                return -1;
            }
        }

        FILE* file;
        _wfopen_s(&file, current_item_file.GetBuffer(), L"r+");
        if (!file)
        {
            last_error = Error::CANT_OPEN_ITEM_FILE;
            return -1;
        }

        unsigned short int price_tmp = (unsigned short int)(price / 10);
        char* price_ptr = (char*)&price_tmp;
        fputc(price_ptr[0], file);
        fputc(price_ptr[1], file);

        fclose(file);

        return 0;
    }

private:

    CString item_folder_path;
    CString current_item_file;
};
