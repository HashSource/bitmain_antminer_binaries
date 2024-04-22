
uint check_purpose_timestamp_sign(undefined4 param_1,X509 *param_2,int param_3)

{
  uint uVar1;
  int loc;
  X509_EXTENSION *ex;
  uint uVar2;
  
  if (param_3 == 0) {
    if ((int)(param_2->ex_flags << 0x1e) < 0) {
      if ((param_2->ex_kusage & 0xffffff3f) != 0) {
        return 0;
      }
      if ((param_2->ex_kusage & 0xc0) == 0) {
        return 0;
      }
    }
    uVar1 = param_2->ex_flags & 4;
    if (uVar1 != 0) {
      if (param_2->ex_xkusage == 0x40) {
        loc = X509_get_ext_by_NID(param_2,0x7e,-1);
        if (-1 < loc) {
          ex = X509_get_ext(param_2,loc);
          uVar2 = X509_EXTENSION_get_critical(ex);
          if (uVar2 != 0) {
            uVar2 = 1;
          }
          return uVar2;
        }
        return 1;
      }
      uVar1 = 0;
    }
  }
  else {
    uVar2 = param_2->ex_flags;
    if (((uVar2 & 2) == 0) || (uVar1 = param_2->ex_kusage & 4, uVar1 != 0)) {
      if ((int)(uVar2 << 0x1f) < 0) {
        return (uVar2 << 0x1b) >> 0x1f;
      }
      if ((uVar2 & 0x2040) == 0x2040) {
        return 3;
      }
      if ((uVar2 & 2) != 0) {
        return 4;
      }
      if ((int)(uVar2 << 0x1c) < 0) {
        if ((param_2->ex_nscert & 7) == 0) {
          uVar2 = 0;
        }
        else {
          uVar2 = 5;
        }
        return uVar2;
      }
      return 0;
    }
  }
  return uVar1;
}

