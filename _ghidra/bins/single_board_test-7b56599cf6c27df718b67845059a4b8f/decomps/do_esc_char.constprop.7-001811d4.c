
undefined4 do_esc_char_constprop_7(uint param_1,uint param_2,undefined1 *param_3,FILE *param_4)

{
  size_t sVar1;
  uint uVar2;
  undefined1 local_1d;
  char acStack_1c [16];
  
  if (0xffff < param_1) {
    BIO_snprintf(acStack_1c,0xb,"\\W%08lX",param_1);
    if ((param_4 != (FILE *)0x0) && (sVar1 = fwrite(acStack_1c,1,10,param_4), sVar1 != 10)) {
      return 0xffffffff;
    }
    return 10;
  }
  if (0xff < param_1) {
    BIO_snprintf(acStack_1c,0xb,"\\U%04lX",param_1);
    if ((param_4 != (FILE *)0x0) && (sVar1 = fwrite(acStack_1c,1,6,param_4), sVar1 != 6)) {
      return 0xffffffff;
    }
    return 6;
  }
  local_1d = (undefined1)param_1;
  if ((int)(param_1 << 0x18) < 0) {
    uVar2 = param_2 & 4;
  }
  else {
    uVar2 = *(ushort *)(&char_type + param_1 * 2) & param_2;
    if ((uVar2 & 0x61) != 0) {
      if (-1 < (int)(uVar2 << 0x1c)) {
        if (param_4 == (FILE *)0x0) {
          return 2;
        }
        sVar1 = fwrite(&DAT_0022467c,1,1,param_4);
        if (sVar1 == 1) {
          sVar1 = fwrite(&local_1d,1,1,param_4);
          if (sVar1 == 1) {
            return 2;
          }
          return 0xffffffff;
        }
        return 0xffffffff;
      }
      if (param_3 != (undefined1 *)0x0) {
        *param_3 = 1;
      }
      goto LAB_0018120c;
    }
  }
  if ((uVar2 & 0x406) != 0) {
    BIO_snprintf(acStack_1c,0xb,"\\%02X",param_1);
    if ((param_4 != (FILE *)0x0) && (sVar1 = fwrite(acStack_1c,1,3,param_4), sVar1 != 3)) {
      return 0xffffffff;
    }
    return 3;
  }
  if ((param_1 == 0x5c) && ((param_2 & 0x40f) != 0)) {
    if ((param_4 != (FILE *)0x0) && (sVar1 = fwrite(&DAT_00200360,1,2,param_4), sVar1 != 2)) {
      return 0xffffffff;
    }
    return 2;
  }
LAB_0018120c:
  if ((param_4 != (FILE *)0x0) && (sVar1 = fwrite(&local_1d,1,1,param_4), sVar1 != 1)) {
    return 0xffffffff;
  }
  return 1;
}

