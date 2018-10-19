#pragma once
#include "unitApp.h"

//虚函数了解参考 https://blog.csdn.net/bao_jinyu/article/details/7843275?utm_source=blogxgwz0
class virtualDetail : public unitApp
{
public:
	virtualDetail();
	virtual ~virtualDetail();

	virtual void run(int argc, char** argv);
};