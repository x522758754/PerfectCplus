#pragma once
#include "unitApp.h"

//文件重定向
class ioRedirect : public unitApp
{
public:
	ioRedirect();

	virtual ~ioRedirect();

	virtual void run(int argc, char** argv);
};