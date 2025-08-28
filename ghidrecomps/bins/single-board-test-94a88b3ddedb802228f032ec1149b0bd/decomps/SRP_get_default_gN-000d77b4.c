
undefined4 * SRP_get_default_gN(char *param_1)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return &knowngN;
  }
  iVar1 = strcmp(knowngN,param_1);
  if (iVar1 != 0) {
    iVar1 = strcmp(DAT_0019a7c4,param_1);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcmp(DAT_0019a7d0,param_1);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcmp(DAT_0019a7dc,param_1);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcmp(DAT_0019a7e8,param_1);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcmp(DAT_0019a7f4,param_1);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcmp(DAT_0019a800,param_1);
              if (iVar1 != 0) {
                return (undefined4 *)0x0;
              }
              iVar1 = 6;
            }
          }
        }
      }
    }
  }
  return &knowngN + iVar1 * 3;
}

