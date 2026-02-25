

#include "Serializer.hpp"

int main(void) {
	char a = 'v';
	char b = 'b';
	Data paquet = {'a', &a, &b, 6, 9.8};
	uintptr_t	_raw;
	Data*		_ptrData;
	Data*		_ptrData2;
	_ptrData = &paquet;

	std::cout << "El valor del puntero _ptrData es: " << _ptrData << std::endl;
	std::cout << "El valor del campo char es: " << _ptrData->caracter << std::endl;
	if (_ptrData->_ptr != NULL)
		std::cout << "El valor del campo char ptr* es: " << _ptrData->_ptr << std::endl;
	if (_ptrData->_ptrVoid != NULL)
		std::cout << "El valor del campo void ptr*: " << _ptrData->_ptrVoid << std::endl;
	std::cout << "El valor del campo int es: " << _ptrData->caracter << std::endl;

	_raw = Serializer::serialize(_ptrData);
	std::cout << "El valor del puntero serializado es: " << _raw << std::endl;
	_ptrData2 = Serializer::deserialize(_raw);
	std::cout << "El valor de puntero deserializado es: " << _ptrData2 << std::endl;
	if (_ptrData == _ptrData2) {
		std::cout << "La serialización y deserialización son consistentes." << std::endl;
	} else {
		std::cout << "Error: Los punteros no coinciden." << std::endl;
	}
	return (0);
}