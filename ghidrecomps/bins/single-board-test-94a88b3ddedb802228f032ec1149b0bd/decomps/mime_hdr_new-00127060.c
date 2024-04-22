
byte ** mime_hdr_new(byte *param_1,byte *param_2)

{
  byte *pbVar1;
  ushort **ppuVar2;
  __int32_t **pp_Var3;
  byte **ppbVar4;
  _STACK *p_Var5;
  ushort uVar6;
  
  if (param_1 != (byte *)0x0) {
    param_1 = (byte *)BUF_strdup((char *)param_1);
    if (param_1 == (byte *)0x0) {
      return (byte **)0x0;
    }
    uVar6 = (ushort)*param_1;
    if (uVar6 != 0) {
      ppuVar2 = __ctype_b_loc();
      pbVar1 = param_1;
      do {
        if ((int)((uint)(*ppuVar2)[(short)uVar6] << 0x17) < 0) {
          pp_Var3 = __ctype_tolower_loc();
          *pbVar1 = (byte)(*pp_Var3)[(short)uVar6];
        }
        uVar6 = (ushort)pbVar1[1];
        pbVar1 = pbVar1 + 1;
      } while (uVar6 != 0);
    }
  }
  if (param_2 != (byte *)0x0) {
    param_2 = (byte *)BUF_strdup((char *)param_2);
    if (param_2 == (byte *)0x0) {
      return (byte **)0x0;
    }
    uVar6 = (ushort)*param_2;
    if (uVar6 != 0) {
      ppuVar2 = __ctype_b_loc();
      pbVar1 = param_2;
      do {
        if ((int)((uint)(*ppuVar2)[(short)uVar6] << 0x17) < 0) {
          pp_Var3 = __ctype_tolower_loc();
          *pbVar1 = (byte)(*pp_Var3)[(short)uVar6];
        }
        uVar6 = (ushort)pbVar1[1];
        pbVar1 = pbVar1 + 1;
      } while (uVar6 != 0);
    }
  }
  ppbVar4 = (byte **)CRYPTO_malloc(0xc,DAT_0012710c,0x33d);
  if (ppbVar4 != (byte **)0x0) {
    *ppbVar4 = param_1;
    ppbVar4[1] = param_2;
    p_Var5 = sk_new(DAT_00127110);
    ppbVar4[2] = (byte *)p_Var5;
    if (p_Var5 != (_STACK *)0x0) {
      return ppbVar4;
    }
  }
  return (byte **)0x0;
}

