#include<cmath>
#include<iostream>
#include<string>
#include<Windows.h>
#include"AES.h"
//#pragma execution_character_set( "utf-8" )
#pragma warning(disable: 4996)
void CopyToClipboard(const wchar_t* buffer, size_t size) {

    //set the default size
    if (size <= 0)
        size = sizeof(WCHAR) * (wcslen(buffer) + 1);

    OpenClipboard(0);
    EmptyClipboard();
    HGLOBAL hClipboardData = GlobalAlloc(GMEM_MOVEABLE, size);
    WCHAR* pchData;
    pchData = (WCHAR*)GlobalLock(hClipboardData);
    wcscpy_s(pchData, size / sizeof(wchar_t), buffer);
    GlobalUnlock(hClipboardData);
    SetClipboardData(CF_UNICODETEXT, hClipboardData);
    CloseClipboard();
}
int main() {
    //setlocale(LC_ALL, "Russian");
    system("chcp 65001");
    //long double l = pow(12,256);
    //printf("%.lf\n", l);
    std::string input;
sd:
    std::cout << "enter length: ";
    std::getline(std::cin, input);

    size_t length = atoi(input.c_str());
    if (length == 0) {
        system("cls");
        std::cout << "entered 0 length, prohibited\n";
        goto sd;
    }
    std::cout << "allocated length " << length<<'\n';
    wchar_t* operate = new wchar_t[length];
    std::cout << "Enter value to evaluate: ";
    std::wstring ope;
    std::getline(std::wcin, ope);
    //std::cout << '\n';

    wcsncpy(operate, ope.c_str(), length - 1);
    operate[length - 1] = L'\0';
    std::cout << "operating bits ";
    for (size_t i = 0; i < wcslen(operate); i++)
    {
        printf("%u ", operate[i]);
    }
    std::cout << "\noperating string ";
    for (size_t i = 0; i < wcslen(operate); i++)
    {
        printf("%c ", operate[i]);
    }
    std::cout << '\n';
    uint16_t unit;
    while (true) {

        //system("color 8");
        std::cout << "!: Quit without clipping evaluated string\n";
        std::cout << "Q: Close with clipping\n";
        std::cout << "AND:\n";
        std::cout << "OR:\n";
        std::cout << "ADD:\n";
        std::cout << "SUB:\n";
        std::cout << "MUL:\n";
        std::cout << "DIV:\n";
        std::cout << "XOR:\n";
        std::cout << "XNOR:\n";
        std::cout << "NEG:\n";
        std::cout << "RSH:\n";
        std::cout << "LSH:\n";
        std::cout << "R: reoperate\n";
        std::getline(std::cin, input);
        if (input == "!")
        {
            return 0;
        }
        else if (input == "q" || input == "Q")
        {
            CopyToClipboard(operate,length*2);
            return 0;
        }else if (input == "r"||input=="R")
        {
            std::cout << "\nreoperating\n";
            //system("cls");
            
            //std::cout << "Enter value to revaluate: ";
            
            //std::getline(std::cin,ope);
            //strcpy((char*)operate, ope.c_str());
            //std::cout << "\noperating bits ";
            //for (size_t i = 0; i < strlen((char*)operate); i++)
            //{
            //    printf("%u ", operate[i]);
            //}
            //std::cout << '\n';
            //std::cout << "operating string ";
            //for (size_t i = 0; i < strlen((char*)operate); i++)
            //{
            //   printf("%c ", operate[i]);
            //}

            /*std::cout << "\n!: Quit without clipping evaluated string\n";
            std::cout << "Q: Close with clipping\n";
            std::cout << "AND:\n";
            std::cout << "OR:\n";
            std::cout << "ADD:\n";
            std::cout << "SUB:\n";
            std::cout << "MUL:\n";
            std::cout << "NOR\n";
            std::cout << "DIV:\n";
            std::cout << "XOR:\n";
            std::cout << "XNOR:\n";
            std::cout << "NEG:\n";
            std::cout << "RSH:\n";
            std::cout << "LSH:\n";
            std::cout << "R: reoperate\n";
            std::cout << '\n'<<"choose operation:\n";
            
            std::getline(std::cin, input);*/
            delete(operate);
            goto sd;
        }
        std::cout << "Now define operation steps of "+input+' ';
        std::getline(std::wcin, ope);
        unit = _wtoi(ope.c_str());
        if (input=="and"|| input == "AND") {
            for (size_t i = 0; i < wcslen(operate); i++){
                operate[i]=(operate[i] & unit);
            }
        }
        else if (input == "neg"|| input == "NEG") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i]=~operate[i];
            }
        }
        else if (input == "or"||input == "OR") {
            for (size_t i = 0; i < wcslen(operate); i++){
                operate[i]=operate[i] | unit;
            }
        }
        else if (input == "nor"|| input == "NOR") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i]=~(operate[i] | unit);
            }
        }
        else if (input == "add"||input == "ADD") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i]+=unit;
            }
        }
        else if (input == "sub"|| input == "SUB") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i]-=unit;
            }        }
        else if (input == "mul"|| input == "MUL") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i]*=unit;
            }
        }
        else if (input == "div"||input == "DIV") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i] /= unit;
            }
        }
        else if (input == "xor"|| input == "XOR") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i]^=unit;
            }
        }
        else if (input == "xnor"|| input == "XNOR") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i] ^=~(operate[i] | unit);
            }
        }
        else if (input == "rsh"|| input == "RSH") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i] >>= unit;
            }
        }
        else if (input == "lsh"|| input == "LSH") {
            for (size_t i = 0; i < wcslen(operate); i++) {
                operate[i]<<=unit;
            }
        }
        system("cls");
        std::cout << "operating bits ";
        for (size_t i = 0; i < wcslen(operate); i++)
        {
            printf("%u ", operate[i]);
        }
        std::cout << '\n';
        std::cout << "operating string ";
        for (size_t i = 0; i < wcslen(operate); i++)
        {
            printf("%c ", operate[i]);
        }
        std::cout << '\n';
        
    }
}
