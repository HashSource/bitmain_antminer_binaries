
undefined1 json_integer_equal(undefined4 param_1,undefined4 param_2)

{
  undefined1 uVar1;
  int iVar2;
  bool bVar3;
  bool bVar4;
  undefined8 uVar5;
  undefined8 uVar6;
  
  uVar5 = json_integer_value(param_1);
  uVar6 = json_integer_value(param_2);
  iVar2 = (int)((ulonglong)uVar6 >> 0x20);
  bVar3 = (int)((ulonglong)uVar5 >> 0x20) == iVar2;
  bVar4 = (int)uVar5 != (int)uVar6;
  if (!bVar3 || bVar4) {
    iVar2 = 0;
  }
  uVar1 = (undefined1)iVar2;
  if (bVar3 && !bVar4) {
    uVar1 = 1;
  }
  return uVar1;
}

