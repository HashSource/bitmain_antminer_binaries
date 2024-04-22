
undefined4 utf8_check_string(int param_1,uint param_2)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  undefined8 uVar4;
  
  if (param_2 == 0) {
    return 1;
  }
  uVar3 = 0;
  uVar2 = param_2;
  do {
    uVar1 = utf8_check_first(*(undefined *)(param_1 + uVar3),uVar2);
    if (uVar1 == 0) {
      return 0;
    }
    uVar2 = uVar1;
    if (1 < uVar1) {
      if (param_2 - uVar3 < uVar1) {
        return 0;
      }
      uVar4 = utf8_check_full(param_1 + uVar3,uVar1,0);
      uVar2 = (uint)((ulonglong)uVar4 >> 0x20);
      if ((int)uVar4 == 0) {
        return 0;
      }
      uVar3 = (uVar3 + uVar1) - 1;
    }
    uVar3 = uVar3 + 1;
    if (param_2 <= uVar3) {
      return 1;
    }
  } while( true );
}

