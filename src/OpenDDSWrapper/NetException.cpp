using namespace System;

public ref class DDSNetException : public Exception {
public:
	DDSNetException(String^ what) : Exception(what) {}
};

