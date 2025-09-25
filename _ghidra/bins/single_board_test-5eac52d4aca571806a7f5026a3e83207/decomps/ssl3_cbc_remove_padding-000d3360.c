
uint ssl3_cbc_remove_padding(int param_1,uint param_2,int param_3)

{
  uint uVar1;
  uint uVar2;
  uint uVar3;
  
  uVar2 = *(uint *)(param_1 + 8);
  if (uVar2 < param_3 + 1U) {
    uVar2 = 0;
  }
  else {
    uVar3 = (uint)*(byte *)(*(int *)(param_1 + 0x14) + uVar2 + -1);
    uVar1 = param_3 + 1U + uVar3;
    uVar3 = uVar3 + 1;
    uVar1 = ~((int)((uVar2 ^ uVar1 | uVar1 ^ uVar2 - uVar1) ^ uVar2) >> 0x1f) &
            ~((int)(param_2 ^ (uVar3 ^ param_2 | param_2 - uVar3 ^ uVar3)) >> 0x1f);
    *(uint *)(param_1 + 8) = uVar2 - (uVar1 & uVar3);
    uVar2 = uVar1 & 1 | ~uVar1;
  }
  return uVar2;
}

