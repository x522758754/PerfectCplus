#pragma once
#include "unitApp.h"

//�麯���˽�ο� https://blog.csdn.net/bao_jinyu/article/details/7843275?utm_source=blogxgwz0
class virtualDetail : public unitApp
{
public:
	virtualDetail();
	virtual ~virtualDetail();

	virtual void run(int argc, char** argv);
};