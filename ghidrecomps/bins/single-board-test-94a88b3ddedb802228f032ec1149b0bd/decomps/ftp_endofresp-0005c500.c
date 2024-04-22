
undefined2 ftp_endofresp(undefined4 param_1,byte *param_2,uint param_3,undefined4 *param_4)

{
  ushort **ppuVar1;
  undefined4 uVar2;
  ushort *puVar3;
  
  if (3 < param_3) {
    ppuVar1 = __ctype_b_loc();
    puVar3 = *ppuVar1;
    if ((puVar3[*param_2] & 0x800) == 0) {
      return 0;
    }
    if ((puVar3[param_2[1]] & 0x800) == 0) {
      return 0;
    }
    if ((puVar3[param_2[2]] & 0x800) == 0) {
      return 0;
    }
    if (param_2[3] == 0x20) {
      strtol((char *)param_2,(char **)0x0,10);
      uVar2 = curlx_sltosi();
      *param_4 = uVar2;
      return 1;
    }
  }
  return 0;
}

