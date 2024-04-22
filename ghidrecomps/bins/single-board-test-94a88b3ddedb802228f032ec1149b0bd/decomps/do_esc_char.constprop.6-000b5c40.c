
undefined4 do_esc_char_constprop_6(uint param_1,uint param_2,undefined *param_3,BIO *param_4)

{
  int iVar1;
  uint uVar2;
  bool bVar3;
  undefined local_20 [4];
  char acStack_1c [16];
  
  if (param_1 < 0x10000) {
    if (param_1 < 0x100) {
      bVar3 = -1 < (int)(param_1 << 0x18);
      uVar2 = DAT_000b5d38;
      if (!bVar3) {
        uVar2 = param_2 & 4;
      }
      local_20[0] = (undefined)param_1;
      if (bVar3) {
        uVar2 = *(byte *)(uVar2 + param_1) & param_2;
      }
      if ((uVar2 & 0x61) == 0) {
        if ((uVar2 & 6) != 0) {
          BIO_snprintf(acStack_1c,0xb,DAT_000b5d48,param_1);
          if ((param_4 != (BIO *)0x0) && (iVar1 = BIO_write(param_4,acStack_1c,3), iVar1 != 3)) {
            return 0xffffffff;
          }
          return 3;
        }
        if (((param_1 & 0xff) == 0x5c) && ((param_2 & 0xf) != 0)) {
          if (param_4 == (BIO *)0x0) {
            return 2;
          }
          iVar1 = BIO_write(param_4,DAT_000b5d3c,2);
          if (iVar1 != 2) {
            return 0xffffffff;
          }
          return 2;
        }
      }
      else {
        if (-1 < (int)(uVar2 << 0x1c)) {
          if (param_4 != (BIO *)0x0) {
            iVar1 = BIO_write(param_4,DAT_000b5d4c,1);
            if (iVar1 != 1) {
              return 0xffffffff;
            }
            iVar1 = BIO_write(param_4,local_20,1);
            if (iVar1 != 1) {
              return 0xffffffff;
            }
          }
          return 2;
        }
        if (param_3 != (undefined *)0x0) {
          *param_3 = 1;
        }
      }
      if ((param_4 == (BIO *)0x0) || (iVar1 = BIO_write(param_4,local_20,1), iVar1 == 1)) {
        return 1;
      }
    }
    else {
      BIO_snprintf(acStack_1c,0xb,DAT_000b5d44,param_1);
      if ((param_4 == (BIO *)0x0) || (iVar1 = BIO_write(param_4,acStack_1c,6), iVar1 == 6)) {
        return 6;
      }
    }
  }
  else {
    BIO_snprintf(acStack_1c,0xb,DAT_000b5d40,param_1);
    if ((param_4 == (BIO *)0x0) || (iVar1 = BIO_write(param_4,acStack_1c,10), iVar1 == 10)) {
      return 10;
    }
  }
  return 0xffffffff;
}

