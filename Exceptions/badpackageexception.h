#pragma once
#include "exception.h"

class BadPackageException :
	public Exception
{
public:
	BadPackageException(void);
	~BadPackageException(void);

	void send();
};

