
uint object_key_compare_serials(uint *param_1,uint *param_2)

{
  byte bVar1;
  uint uVar2;
  uint uVar3;
  bool bVar4;
  
  uVar2 = *param_1;
  uVar3 = *param_2;
  if (uVar2 < uVar3) {
    uVar2 = 0xffffffff;
  }
  else {
    bVar4 = uVar2 == uVar3;
    if (bVar4) {
      uVar3 = 0;
    }
    bVar1 = (byte)uVar3;
    if (!bVar4) {
      bVar1 = 1;
    }
    uVar2 = (uint)bVar1;
  }
  return uVar2;
}

