//---------------------------------------------------------------------------

#pragma hdrstop

#include "UEstatisticaCor.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
UEstatisticaCor::UEstatisticaCor()
{
	this ->cor = 0;
	this ->qtd = 0;
}
void UEstatisticaCor::setCor(int cor)
{
	this->cor = cor;
}
int UEstatisticaCor::getCor()
{
	return cor;
}
void UEstatisticaCor::setQtd(int qtd)
{
	this->qtd = qtd;
}
int UEstatisticaCor::getQtd()
{
	return qtd;
}
void UEstatisticaCor::resetar()
{
	this->cor = 0;
	this->qtd = 0;
}
void UEstatisticaCor::incrementar()
{
	this->qtd++;
}
