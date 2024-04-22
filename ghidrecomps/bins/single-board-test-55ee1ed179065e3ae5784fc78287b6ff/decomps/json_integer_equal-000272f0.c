
undefined json_integer_equal(undefined4 param_1,undefined4 param_2)

{
  bool bVar1;
  undefined uVar2;
  int iVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar5 = json_integer_value(param_1);
  uVar6 = json_integer_value(param_2);
  iVar3 = (int)((ulonglong)uVar6 >> 0x20);
  bVar4 = (int)((ulonglong)uVar5 >> 0x20) == iVar3;
  bVar1 = (int)uVar5 != (int)uVar6;
  if (!bVar4 || bVar1) {
    iVar3 = 0;
  }
  uVar2 = (undefined)iVar3;
  if (bVar4 && !bVar1) {
    uVar2 = 1;
  }
  return uVar2;
}

