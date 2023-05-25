// Fill out your copyright notice in the Description page of Project Settings.


#include "AdaptadorMovimientoAleatorio_CA.h"

UAdaptadorMovimientoAleatorio_CA::UAdaptadorMovimientoAleatorio_CA():
	Super()
{
	PrimaryComponentTick.bCanEverTick = true;

	// ...
	SetLimitesMovimiento(0.0f, 10.0f, 10.0f);
}

void UAdaptadorMovimientoAleatorio_CA::SetLimitesMovimiento(float _XMovimiento, float _YMovimiento, float _ZMovimiento)
{
	AnchoMovimiento = _XMovimiento;
	AltoMovimiento = _YMovimiento;
	ProfundidadMovimiento = _ZMovimiento;
}
