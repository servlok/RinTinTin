#pragma once

#include <string>

/**
	Klasa abstrakcyjna, kt�ra wysy�a powiadomienie do klienta.
*/
class Exception
{
protected:
	std::string message;
public:
	Exception(void);
	Exception(std::string message);
	virtual ~Exception(void);

	virtual void send() = 0;
};

