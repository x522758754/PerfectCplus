#pragma once
#include "unitApp.h"

//�ļ��ض���
class ioRedirect : public unitApp
{
public:
	ioRedirect();

	virtual ~ioRedirect();

	virtual void run(int argc, char** argv);
};