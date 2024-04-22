
ushort smtp_endofresp(int param_1,byte *param_2,uint param_3,int *param_4)

{
  ushort uVar1;
  ushort **ppuVar2;
  int iVar3;
  ushort *puVar4;
  
  if (param_3 < 4) {
    return 0;
  }
  ppuVar2 = __ctype_b_loc();
  puVar4 = *ppuVar2;
  if ((puVar4[*param_2] & 0x800) == 0) {
    uVar1 = 0;
  }
  else {
    uVar1 = puVar4[param_2[1]] & 0x800;
    if ((uVar1 != 0) && (uVar1 = puVar4[param_2[2]] & 0x800, uVar1 != 0)) {
      if ((param_2[3] == 0x20) || (param_3 == 5)) {
        strtol((char *)param_2,(char **)0x0,10);
        iVar3 = curlx_sltosi();
        if (iVar3 == 1) {
          *param_4 = 0;
        }
        else {
          *param_4 = iVar3;
        }
        return 1;
      }
      if (param_2[3] != 0x2d) {
        return 0;
      }
      if (*(int *)(param_1 + 0x3f8) == 2 || *(int *)(param_1 + 0x3f8) == 7) {
        *param_4 = 1;
        return 1;
      }
      uVar1 = 0;
    }
  }
  return uVar1;
}

