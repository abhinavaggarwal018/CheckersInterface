#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace System::Drawing;
[STAThread]

void print(void*)
{
	while (1)
	{
		fflush(stdout);
		Sleep(10);
	}
}

int main(array<String^ > ^ args)
{
	freopen("Console.log", "w+", stdout);
	HANDLE log = ((HANDLE)_beginthread(print, 0, (void*)NULL));

	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	CheckersInterface::MyForm form;
	Application::Run(%form);

	TerminateThread(log, 0);
	CloseHandle(log);

}