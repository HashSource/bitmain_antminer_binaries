
undefined4 do_esc_char_constprop_7(uint param_1,uint param_2,undefined *param_3,FILE *param_4)

{
  size_t sVar1;
  uint uVar2;
  bool bVar3;
  undefined local_20 [4];
  char acStack_1c [16];
  
  if (param_1 < 0x10000) {
    if (param_1 < 0x100) {
      bVar3 = -1 < (int)(param_1 << 0x18);
      uVar2 = DAT_000b5f6c;
      if (!bVar3) {
        uVar2 = param_2 & 4;
      }
      local_20[0] = (undefined)param_1;
      if (bVar3) {
        uVar2 = *(byte *)(uVar2 + param_1) & param_2;
      }
      if ((uVar2 & 0x61) == 0) {
        if ((uVar2 & 6) != 0) {
          BIO_snprintf(acStack_1c,0xb,DAT_000b5f7c,param_1);
          if ((param_4 != (FILE *)0x0) && (sVar1 = fwrite(acStack_1c,1,3,param_4), sVar1 != 3)) {
            return 0xffffffff;
          }
          return 3;
        }
        if (((param_1 & 0xff) == 0x5c) && ((param_2 & 0xf) != 0)) {
          if (param_4 == (FILE *)0x0) {
            return 2;
          }
          sVar1 = fwrite(DAT_000b5f70,1,2,param_4);
          if (sVar1 != 2) {
            return 0xffffffff;
          }
          return 2;
        }
      }
      else {
        if (-1 < (int)(uVar2 << 0x1c)) {
          if (param_4 != (FILE *)0x0) {
            sVar1 = fwrite(DAT_000b5f80,1,1,param_4);
            if (sVar1 != 1) {
              return 0xffffffff;
            }
            sVar1 = fwrite(local_20,1,1,param_4);
            if (sVar1 != 1) {
              return 0xffffffff;
            }
          }
          return 2;
        }
        if (param_3 != (undefined *)0x0) {
          *param_3 = 1;
        }
      }
      if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(local_20,1,1,param_4), sVar1 == 1)) {
        return 1;
      }
    }
    else {
      BIO_snprintf(acStack_1c,0xb,DAT_000b5f78,param_1);
      if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(acStack_1c,1,6,param_4), sVar1 == 6)) {
        return 6;
      }
    }
  }
  else {
    BIO_snprintf(acStack_1c,0xb,DAT_000b5f74,param_1);
    if ((param_4 == (FILE *)0x0) || (sVar1 = fwrite(acStack_1c,1,10,param_4), sVar1 == 10)) {
      return 10;
    }
  }
  return 0xffffffff;
}

