#include "StringConvert.h"

EXPORT_COMMON char *ConvertToASCII(gcroot<System::String^> netString) {
   	pin_ptr<const wchar_t> pin = PtrToStringChars(netString);
	char *ascii = new char[netString->Length+1];
	WideCharToMultiByte(CP_ACP, 0, pin, -1, ascii, netString->Length+1, NULL, NULL);
    return ascii; 
}


EXPORT_COMMON std::string ConvertToString(gcroot<System::String^> netString) {
	char *ascii = ConvertToASCII(netString);
	std::string s = ascii;
	delete [] ascii;
	return s;
}

EXPORT_COMMON TAO::String_Manager Convert(gcroot<System::String^> netString) {
    char *ascii = ConvertToASCII(netString);
	TAO::String_Manager corbaString = CORBA::string_dup(ascii);
	delete [] ascii;
	return corbaString;
}

EXPORT_COMMON gcroot<System::String^> Convert(TAO::String_Manager corbaString) {
	return gcnew System::String(corbaString.in());
}
