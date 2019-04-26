#include "StringConvert.h"

EXPORT_COMMON void GetArguments(int &argc, char **&argv) {
	array<System::String^>^ arguments = System::Environment::GetCommandLineArgs();
	argc = arguments->Length;
	argv = new char *[argc];
	for (int i=0; i<argc; i++)
		argv[i] = ConvertToASCII(arguments[i]);
}


generic <class TSample>
public ref class ProcessEventArgs : public System::EventArgs {
	TSample sample_;
public:
	ProcessEventArgs(TSample sample) : sample_(sample) {}
	property TSample Sample { TSample get() { return sample_; } }
};


generic <class TSample>
public ref class EventManager {
public:
	EventManager() {}

	delegate void ProcessEventHandler(Object^ sender, ProcessEventArgs<TSample> ^args);
	ProcessEventHandler^ pProcess_;
	event ProcessEventHandler^ Process
	{
		void add(ProcessEventHandler^ p) { pProcess_ +=p; }
		void remove(ProcessEventHandler^ p) { pProcess_ -=p; }
		void raise(Object^ obj, ProcessEventArgs<TSample>^ args) {
			if (pProcess_!=nullptr)
				pProcess_(obj, args);
		}
	}
};