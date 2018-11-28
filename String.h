#pragma once

#ifndef _INC_STRING
#include <string.h>
#endif // !_INC_STRING

// Структура обозначает массив символов. Количество символов и указатель менять запрещено.
typedef struct {
	char * str; // Указатель на первый символ строки.
	size_t length; // Количество доступных символов.
} string;

// Структура обозначает массив двухбайтных символов. Количество символов и указатель менять запрещено.
typedef struct {
	wchar_t * str; // Указатель на первый символ строки.
	size_t length; // Количество доступных символов.
} wstring;

string String_intilizalStringMalloc(size_t length)
{
	string output = {
		(char*)malloc(sizeof(char)*length),
		length
	};
	return output;
}

string String_CopyFromCharMalloc(const char * input)
{
	if (input == NULL)
		return (string){ NULL, 0 };
	size_t len = strlen(input);
	string output = {
		(char*)malloc(len*sizeof(char)),
		len
	};
	#ifdef _MSC_VER
		memcpy_s(output.str, output.length, input, len);
	#else
		memcpy(output.str, input, len);
	#endif
	return output;
}

wstring String_intilizalWstringMalloc(size_t length)
{
	wstring output = {
		(wchar_t*)malloc(sizeof(wchar_t)*length),
		length
	};
	return output;
}

void String_destructorFree(string * str)
{
	if(str != NULL && str->str != NULL)
		free(str->str);
	*str = (string){ NULL, 0 };
}