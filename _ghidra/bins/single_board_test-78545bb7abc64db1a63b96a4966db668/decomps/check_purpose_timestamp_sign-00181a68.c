
uint check_purpose_timestamp_sign(undefined4 param_1,X509 *param_2,int param_3)

{
  uint uVar1;
  int loc;
  X509_EXTENSION *ex;
  uint uVar2;
  
  uVar1 = param_2[1].references;
  if (param_3 == 0) {
    if (((-1 < (int)(uVar1 << 0x1e)) ||
        ((uVar2 = 0, ((uint)param_2[1].name & 0xffffff3f) == 0 &&
         (uVar2 = (uint)param_2[1].name & 0xc0, uVar2 != 0)))) && (uVar2 = uVar1 & 4, uVar2 != 0)) {
      if (param_2[1].ex_data.sk != (stack_st_void *)0x40) {
        return 0;
      }
      loc = X509_get_ext_by_NID(param_2,0x7e,-1);
      if (loc < 0) {
        return 1;
      }
      ex = X509_get_ext(param_2,loc);
      uVar1 = X509_EXTENSION_get_critical(ex);
      if (uVar1 != 0) {
        uVar1 = 1;
      }
      return uVar1;
    }
  }
  else if (((uVar1 & 2) == 0) || (uVar2 = (uint)param_2[1].name & 4, uVar2 != 0)) {
    if ((int)(uVar1 << 0x1f) < 0) {
      return (uVar1 << 0x1b) >> 0x1f;
    }
    if ((uVar1 & 0x2040) == 0x2040) {
      return 3;
    }
    if ((uVar1 & 2) != 0) {
      return 4;
    }
    if (-1 < (int)(uVar1 << 0x1c)) {
      return 0;
    }
    if ((param_2[1].ex_data.dummy & 7U) == 0) {
      uVar1 = 0;
    }
    else {
      uVar1 = 5;
    }
    return uVar1;
  }
  return uVar2;
}

