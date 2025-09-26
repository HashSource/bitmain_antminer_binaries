
undefined4 cmd_MaxProtocol(int param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 uVar3;
  
  puVar2 = *(undefined4 **)(param_1 + 0xc);
  if (puVar2 == (undefined4 *)0x0) {
    if (*(int *)(param_1 + 0x10) == 0) {
      return 0;
    }
    puVar2 = *(undefined4 **)(*(int *)(param_1 + 0x10) + 0x4d0);
  }
  uVar3 = *(undefined4 *)*puVar2;
  iVar1 = strcmp("None",param_2);
  if (iVar1 != 0) {
    iVar1 = strcmp("SSLv3",param_2);
    if (iVar1 == 0) {
      iVar1 = 1;
    }
    else {
      iVar1 = strcmp("TLSv1",param_2);
      if (iVar1 == 0) {
        iVar1 = 2;
      }
      else {
        iVar1 = strcmp("TLSv1.1",param_2);
        if (iVar1 == 0) {
          iVar1 = 3;
        }
        else {
          iVar1 = strcmp("TLSv1.2",param_2);
          if (iVar1 == 0) {
            iVar1 = 4;
          }
          else {
            iVar1 = strcmp("TLSv1.3",param_2);
            if (iVar1 == 0) {
              iVar1 = 5;
            }
            else {
              iVar1 = strcmp("DTLSv1",param_2);
              if (iVar1 == 0) {
                iVar1 = 6;
              }
              else {
                iVar1 = strcmp("DTLSv1.2",param_2);
                if (iVar1 != 0) {
                  return 0;
                }
                iVar1 = 7;
              }
            }
          }
        }
      }
    }
  }
  if (*(int *)(versions_25856 + iVar1 * 8 + 4) < 0) {
    return 0;
  }
  uVar3 = ssl_set_version_bound
                    (uVar3,*(int *)(versions_25856 + iVar1 * 8 + 4),*(undefined4 *)(param_1 + 0x48))
  ;
  return uVar3;
}

