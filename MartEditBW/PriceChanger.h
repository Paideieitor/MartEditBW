#pragma once

#include "MartChanger.h"

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
        swprintf_s(file_name, 1024u, L"%s\\4_%s.bin", item_folder_path.GetBuffer(), ID_str);
        
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

        CString new_item_file = current_item_file;
        int slash_position = new_item_file.ReverseFind(L'\\');
        new_item_file.Insert(slash_position + 1, L"Changed\\");

        if (CopyFileW(current_item_file, new_item_file, FALSE) == FALSE && GetLastError() == (DWORD)3)
        {
            CString changed_folder_path = item_folder_path;
            changed_folder_path.Insert(changed_folder_path.GetLength(), L"\\Changed");
            if (_wmkdir(changed_folder_path) < 0)
            {
                last_error = Error::CANT_OPEN_ITEM_FILE;
                return -1;
            }
            if (CopyFileW(current_item_file, new_item_file, FALSE) == FALSE)
            {
                last_error = Error::CANT_OPEN_ITEM_FILE;
                return -1;
            }
        }

        FILE* file;
        _wfopen_s(&file, new_item_file.GetBuffer(), L"r+");
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
