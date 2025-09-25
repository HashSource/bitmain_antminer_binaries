
undefined4 * SRP_get_default_gN(char *param_1)

{
  int iVar1;
  
  if (param_1 == (char *)0x0) {
    return &knowngN;
  }
  iVar1 = strcmp(knowngN,param_1);
  if (iVar1 != 0) {
    iVar1 = strcmp(DAT_002746e8,param_1);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcmp(DAT_002746f4,param_1);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcmp(DAT_00274700,param_1);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcmp(DAT_0027470c,param_1);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcmp(DAT_00274718,param_1);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcmp(DAT_00274724,param_1);
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

