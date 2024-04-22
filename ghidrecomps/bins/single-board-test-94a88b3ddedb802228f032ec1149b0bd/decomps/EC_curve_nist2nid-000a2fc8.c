
undefined4 EC_curve_nist2nid(char *param_1)

{
  int iVar1;
  
  iVar1 = strcmp(DAT_000a30c0,param_1);
  if (iVar1 != 0) {
    iVar1 = strcmp(DAT_000a30c4,param_1);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcmp(DAT_000a30c8,param_1);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcmp(DAT_000a30cc,param_1);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcmp(DAT_000a30d0,param_1);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcmp(DAT_000a30d4,param_1);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcmp(DAT_000a30d8,param_1);
              if (iVar1 == 0) {
                iVar1 = 6;
              }
              else {
                iVar1 = strcmp(DAT_000a30dc,param_1);
                if (iVar1 == 0) {
                  iVar1 = 7;
                }
                else {
                  iVar1 = strcmp(DAT_000a30e0,param_1);
                  if (iVar1 == 0) {
                    iVar1 = 8;
                  }
                  else {
                    iVar1 = strcmp(DAT_000a30e4,param_1);
                    if (iVar1 == 0) {
                      iVar1 = 9;
                    }
                    else {
                      iVar1 = strcmp(DAT_000a30e8,param_1);
                      if (iVar1 == 0) {
                        iVar1 = 10;
                      }
                      else {
                        iVar1 = strcmp(DAT_000a30ec,param_1);
                        if (iVar1 == 0) {
                          iVar1 = 0xb;
                        }
                        else {
                          iVar1 = strcmp(DAT_000a30f0,param_1);
                          if (iVar1 == 0) {
                            iVar1 = 0xc;
                          }
                          else {
                            iVar1 = strcmp(DAT_000a30f4,param_1);
                            if (iVar1 == 0) {
                              iVar1 = 0xd;
                            }
                            else {
                              iVar1 = strcmp(DAT_000a30f8,param_1);
                              if (iVar1 != 0) {
                                return 0;
                              }
                              iVar1 = 0xe;
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return *(undefined4 *)(DAT_000a30fc + iVar1 * 8 + 0x514);
}

