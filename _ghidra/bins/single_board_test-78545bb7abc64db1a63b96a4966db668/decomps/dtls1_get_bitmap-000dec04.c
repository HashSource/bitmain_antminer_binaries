
ushort * dtls1_get_bitmap(int param_1,int param_2,undefined4 *param_3)

{
  ushort *puVar1;
  uint uVar2;
  ushort *puVar3;
  uint uVar4;
  
  puVar3 = *(ushort **)(param_1 + 0xf38);
  puVar1 = (ushort *)0x0;
  uVar4 = *(uint *)(param_2 + 0x24);
  uVar2 = (uint)*puVar3;
  *param_3 = 0;
  if (uVar4 == uVar2) {
    puVar1 = puVar3 + 2;
  }
  else if (((uVar4 == uVar2 + 1) && (puVar3[0xe] != uVar2)) && (*(int *)(param_2 + 4) - 0x15U < 2))
  {
    puVar1 = puVar3 + 8;
    *param_3 = 1;
  }
  return puVar1;
}

