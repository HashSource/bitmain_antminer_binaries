
int nc_match(int *param_1,undefined4 *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int *piVar3;
  int iVar4;
  int iVar5;
  undefined8 uVar6;
  
  iVar5 = 0;
  piVar3 = (int *)0x0;
  do {
    iVar1 = OPENSSL_sk_num(*param_2);
    if (iVar1 <= (int)piVar3) {
      if (iVar5 == 1) {
        return 0x2f;
      }
      iVar5 = 0;
      do {
        do {
          iVar1 = OPENSSL_sk_num(param_2[1],piVar3);
          iVar4 = iVar5 + 1;
          if (iVar1 <= iVar5) {
            return 0;
          }
          puVar2 = (undefined4 *)OPENSSL_sk_value(param_2[1],iVar5);
          piVar3 = (int *)*puVar2;
          iVar5 = iVar4;
        } while (*param_1 != *piVar3);
        if ((puVar2[1] != 0) || (puVar2[2] != 0)) {
          return 0x31;
        }
        uVar6 = nc_match_single(param_1);
        piVar3 = (int *)((ulonglong)uVar6 >> 0x20);
        iVar1 = (int)uVar6;
        if (iVar1 == 0) {
          return 0x30;
        }
      } while (iVar1 == 0x2f);
      return iVar1;
    }
    puVar2 = (undefined4 *)OPENSSL_sk_value(*param_2);
    if (*param_1 == *(int *)*puVar2) {
      if (puVar2[1] != 0) {
        return 0x31;
      }
      if (puVar2[2] != 0) {
        return 0x31;
      }
      if (iVar5 != 2) {
        if (iVar5 == 0) {
          iVar5 = 1;
        }
        iVar1 = nc_match_single(param_1);
        if (iVar1 != 0) {
          if (iVar1 != 0x2f) {
            return iVar1;
          }
          goto LAB_00172334;
        }
      }
      iVar5 = 2;
    }
LAB_00172334:
    piVar3 = (int *)((int)piVar3 + 1);
  } while( true );
}

