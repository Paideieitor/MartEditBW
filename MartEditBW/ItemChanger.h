#pragma once

#include "MartChanger.h"

class ItemChanger : public MartChanger
{
public:

    ItemChanger() 
    {
        LoadMarts();
    }

    ~ItemChanger() {}

    void SetMartFilePath(CString path)
    {
        mart_file_path = path;
    }

    std::vector<CString> GetMartNames()
    {
        return mart_names;
    }

    int LoadMartItems(CString name, std::vector<CString>& mart_items)
    {
        if (name == NULL_NAME)
        {
            return 0;
        }
        if (mart_file_path.GetLength() <= 0u)
        {
            last_error = Error::NULL_MART_DATA_PATH;
            return -1;
        }

        long int position = 0l;
        unsigned int amount = 0u;
        int error = GetMartData(name, position, amount);
        if (error < 0)
        {
            last_error = Error::CANT_FIND_MART_DATA;
            return -1;
        }

        bool isSubway = IsSubwayShop(name); // Subway shops are stored differently

        FILE* file;
        _wfopen_s(&file, mart_file_path, L"rb");
        if (!file)
        {
            last_error = Error::MART_FILE_DOESNT_EXIST;
            return -1;
        }
        fseek(file, position, 0);

        for (unsigned int i = 0u; i < amount; ++i)
        {
            unsigned short int ID;
            char* ID_ptr = (char*)&ID;
            ID_ptr[0] = fgetc(file);
            ID_ptr[1] = fgetc(file);

            CString item_name = GetItemName((int)ID);
            if (item_name.GetLength() <= 0)
                item_name = L"???";

            mart_items.push_back(item_name);

            if (isSubway)
                fseek(file, position + (i * 8), 0); // we need to advance 8 bytes that don't hold relevant data (at least as far as I know)
        }

        fclose(file);

        return 0;
    }

    int SaveItemChanges(CString mart_name, std::vector<CString> mart_items)
    {
        long int position = 0l;
        unsigned int amount = 0u;
        int error = GetMartData(mart_name, position, amount);
        if (error < 0)
        {
            last_error = Error::CANT_FIND_MART_DATA;
            return -1;
        }

        if (mart_items.size() != amount)
        {
            last_error = Error::INCOMPATIBLE_MART_SIZE;
            return -1;
        }

        bool isSubway = IsSubwayShop(mart_name); // Subway shops are stored differently

        CString new_mart_file = mart_file_path;
        int dot_position = new_mart_file.ReverseFind(L'.');
        new_mart_file.Insert(dot_position, L"(Changed)");

        if (CopyFileW(mart_file_path, new_mart_file, FALSE) == FALSE && GetLastError() == (DWORD)3)
        {
            last_error = Error::MART_FILE_DOESNT_EXIST;
            return -1;
        }

        FILE* file;
        _wfopen_s(&file, new_mart_file, L"r+b");
        if (!file)
        {
            last_error = Error::MART_FILE_DOESNT_EXIST;
            return -1;
        }
        fseek(file, position, 0);

        for (unsigned int i = 0u; i < amount; ++i)
        {
            unsigned short int ID = (unsigned short int)GetItemID(mart_items[i]);
            char* ID_ptr = (char*)&ID;
            fputc(ID_ptr[0], file);
            fputc(ID_ptr[1], file);

            if (isSubway)
                fseek(file, position + (i * 8), 0); // we need to advance 8 bytes that don't hold relevant data (at least as far as I know)
        }

        fclose(file);

        return 0;
    }

private:

    void LoadMarts()
    {
        mart_names.push_back(NULL_NAME); mart_position.push_back(-1); mart_amount.push_back(0);
        mart_names.push_back(L"1 Badge Pokemart"); mart_position.push_back(0x51538); mart_amount.push_back(2);
        mart_names.push_back(L"Shopping Mall TM Counter"); mart_position.push_back(0x5153C); mart_amount.push_back(2);
        mart_names.push_back(L"Icirrus City TM Counter"); mart_position.push_back(0x51546); mart_amount.push_back(3);
        mart_names.push_back(L"Driftveil Market Herbs"); mart_position.push_back(0x5154C); mart_amount.push_back(4);
        mart_names.push_back(L"Mistralton City TM Counter"); mart_position.push_back(0x51564); mart_amount.push_back(4);
        mart_names.push_back(L"Shopping Mall Vitamin Counter"); mart_position.push_back(0x51590); mart_amount.push_back(6);
        mart_names.push_back(L"Accumula Town Pokemart"); mart_position.push_back(0x515E4); mart_amount.push_back(7);
        mart_names.push_back(L"Nimbasa City TM Counter"); mart_position.push_back(0x515F2); mart_amount.push_back(7);
        mart_names.push_back(L"Striaton City Pokemart"); mart_position.push_back(0x51600); mart_amount.push_back(8);
        mart_names.push_back(L"Pokemon League Pokemart"); mart_position.push_back(0x51610); mart_amount.push_back(8);
        mart_names.push_back(L"Lacunosa Town Pokemart"); mart_position.push_back(0x51620); mart_amount.push_back(8);
        mart_names.push_back(L"Black City Pokemart"); mart_position.push_back(0x51630); mart_amount.push_back(8);
        mart_names.push_back(L"Nacrene City/Shopping Mall x Item Shop"); mart_position.push_back(0x51640); mart_amount.push_back(8);
        mart_names.push_back(L"Driftveil City Market Incense Shop"); mart_position.push_back(0x51650); mart_amount.push_back(9);
        mart_names.push_back(L"Nacrene City Pokemart"); mart_position.push_back(0x51662); mart_amount.push_back(9);
        mart_names.push_back(L"Undella Town Pokemart"); mart_position.push_back(0x51674); mart_amount.push_back(9);
        mart_names.push_back(L"2 Badges Pokemart"); mart_position.push_back(0x51686); mart_amount.push_back(11);
        mart_names.push_back(L"Castelia City Pokemart"); mart_position.push_back(0x5169C); mart_amount.push_back(11);
        mart_names.push_back(L"Driftveil City Pokemart"); mart_position.push_back(0x516B2); mart_amount.push_back(11);
        mart_names.push_back(L"Opelucid City Pokemart"); mart_position.push_back(0x516C8); mart_amount.push_back(11);
        mart_names.push_back(L"3 Badges Pokemart"); mart_position.push_back(0x516F8); mart_amount.push_back(14);
        mart_names.push_back(L"Shopping Mall Bottom Counter"); mart_position.push_back(0x51714); mart_amount.push_back(16);
        mart_names.push_back(L"Shopping Mall Middle Counter"); mart_position.push_back(0x51734); mart_amount.push_back(16);
        mart_names.push_back(L"5 Badges Pokemart"); mart_position.push_back(0x51774); mart_amount.push_back(17);
        mart_names.push_back(L"7 Badges Pokemart"); mart_position.push_back(0x51796); mart_amount.push_back(18);
        mart_names.push_back(L"8 Badges Pokemart"); mart_position.push_back(0x517BA); mart_amount.push_back(19);
        mart_names.push_back(L"Battle Subway TM Counter"); mart_position.push_back(0x51850); mart_amount.push_back(11);
        mart_names.push_back(L"Battle Subway Item Counter"); mart_position.push_back(0x518A0); mart_amount.push_back(39);
    }

    int GetMartData(CString name, long int& position, unsigned int& amount)
    {
        int output = -1;
        for (unsigned int i = 0u; i < mart_names.size(); ++i)
            if (mart_names[i] == name)
            {
                position = mart_position[i];
                amount = mart_amount[i];
                output = i;

                break;
            }

        return output;
    }

    bool IsSubwayShop(CString name)
    {
        if (name == L"Battle Subway TM Counter" || name == L"Battle Subway Item Counter")
            return true;
        return false;
    }

    CString mart_file_path;

    std::vector<CString> mart_names;
    std::vector<long int> mart_position;
    std::vector<unsigned int> mart_amount; // this vec stores amount of items, each item is 2 bytes
};

