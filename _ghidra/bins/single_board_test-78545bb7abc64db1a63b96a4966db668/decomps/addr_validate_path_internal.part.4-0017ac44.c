
int addr_validate_path_internal_part_4(int param_1,undefined4 param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  int iVar9;
  undefined8 uVar10;
  
  iVar8 = 0;
  uVar5 = 0xffffffff;
  iVar6 = 0;
  if (param_3 == 0) {
    iVar6 = OPENSSL_sk_value(param_2,0);
    param_3 = *(int *)(iVar6 + 0xa8);
    iVar1 = 1;
    if (param_3 == 0) goto LAB_0017ae48;
    iVar8 = 1;
    uVar5 = 0;
  }
  iVar1 = X509v3_addr_is_canonical(param_3);
  if (iVar1 == 0) {
    if (param_1 != 0) {
      *(undefined4 *)(param_1 + 0x5c) = uVar5;
      *(undefined4 *)(param_1 + 0x60) = 0x29;
      *(int *)(param_1 + 100) = iVar6;
      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
      if (iVar1 != 0) {
        OPENSSL_sk_set_cmp_func(param_3,0x179455);
        param_3 = OPENSSL_sk_dup(param_3);
        if (param_3 == 0) {
          ERR_put_error(0x22,0xa6,0x41,"crypto/x509v3/v3_addr.c",0x4cd);
          goto LAB_0017aee0;
        }
        goto LAB_0017acaa;
      }
    }
  }
  else {
    iVar1 = 1;
    OPENSSL_sk_set_cmp_func(param_3,0x179455);
    param_3 = OPENSSL_sk_dup(param_3);
    if (param_3 != 0) {
LAB_0017acaa:
      uVar10 = OPENSSL_sk_num(param_2);
      iVar2 = (int)((ulonglong)uVar10 >> 0x20);
      if (iVar8 < (int)uVar10) {
        do {
          iVar6 = OPENSSL_sk_value(param_2,iVar8);
          iVar2 = X509v3_addr_is_canonical(*(undefined4 *)(iVar6 + 0xa8));
          if (iVar2 == 0) {
            if (param_1 == 0) goto LAB_0017ae9a;
            *(int *)(param_1 + 0x5c) = iVar8;
            *(undefined4 *)(param_1 + 0x60) = 0x29;
            *(int *)(param_1 + 100) = iVar6;
            iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
            if (iVar1 == 0) goto LAB_0017ae48;
          }
          iVar2 = *(int *)(iVar6 + 0xa8);
          if (iVar2 == 0) {
            do {
              iVar3 = OPENSSL_sk_num(param_3);
              if (iVar3 <= iVar2) goto LAB_0017add0;
              iVar3 = OPENSSL_sk_value(param_3,iVar2);
              iVar2 = iVar2 + 1;
            } while (**(int **)(iVar3 + 4) == 0);
            if (param_1 == 0) {
LAB_0017ae9a:
              OPENSSL_sk_free(param_3);
              return param_1;
            }
            *(undefined4 *)(param_1 + 0x60) = 0x2e;
            *(int *)(param_1 + 0x5c) = iVar8;
LAB_0017ae82:
            *(int *)(param_1 + 100) = iVar6;
            iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
            if (iVar1 == 0) goto LAB_0017ae48;
          }
          else {
            OPENSSL_sk_set_cmp_func(iVar2,0x179455);
            for (iVar2 = 0; iVar3 = OPENSSL_sk_num(param_3), iVar2 < iVar3; iVar2 = iVar2 + 1) {
              iVar3 = OPENSSL_sk_value(param_3,iVar2);
              uVar5 = OPENSSL_sk_find(*(undefined4 *)(iVar6 + 0xa8),iVar3);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(iVar6 + 0xa8),uVar5);
              if (iVar4 == 0) {
                if (**(int **)(iVar3 + 4) == 1) {
                  if (param_1 == 0) goto LAB_0017ae9a;
                  *(undefined4 *)(param_1 + 0x60) = 0x2e;
                  *(int *)(param_1 + 0x5c) = iVar8;
                  goto LAB_0017ae82;
                }
              }
              else if (**(int **)(iVar4 + 4) == 1) {
                if (**(int **)(iVar3 + 4) != 0) {
                  iVar9 = (*(int **)(iVar3 + 4))[1];
                  iVar7 = (*(int **)(iVar4 + 4))[1];
                  X509v3_addr_get_afi(iVar3);
                  if ((iVar7 != iVar9 && iVar9 != 0) &&
                     ((iVar7 == 0 || (iVar3 = addr_contains_part_1(iVar7,iVar9), iVar3 == 0)))) {
                    if (param_1 != 0) {
                      *(undefined4 *)(param_1 + 0x60) = 0x2e;
                      *(int *)(param_1 + 100) = iVar6;
                      *(int *)(param_1 + 0x5c) = iVar8;
                      iVar1 = (**(code **)(param_1 + 0x1c))(0,param_1);
                      if (iVar1 != 0) goto LAB_0017ad0e;
                      goto LAB_0017ae48;
                    }
                    goto LAB_0017ae9a;
                  }
                }
                OPENSSL_sk_set(param_3,iVar2,iVar4);
              }
LAB_0017ad0e:
            }
          }
LAB_0017add0:
          iVar8 = iVar8 + 1;
          uVar10 = OPENSSL_sk_num(param_2);
          iVar2 = (int)((ulonglong)uVar10 >> 0x20);
        } while (iVar8 < (int)uVar10);
      }
      iVar3 = *(int *)(iVar6 + 0xa8);
      if (iVar3 != 0) {
        if (param_1 == 0) {
          while( true ) {
            iVar8 = OPENSSL_sk_num(iVar3);
            if (iVar8 <= param_1) break;
            iVar8 = OPENSSL_sk_value(*(undefined4 *)(iVar6 + 0xa8),param_1);
            if ((**(int **)(iVar8 + 4) == 0) && (iVar8 = OPENSSL_sk_find(param_3,iVar8), -1 < iVar8)
               ) {
              iVar1 = 0;
              break;
            }
            iVar3 = *(int *)(iVar6 + 0xa8);
            param_1 = param_1 + 1;
          }
        }
        else {
          iVar4 = 0;
          while( true ) {
            iVar2 = OPENSSL_sk_num(iVar3,iVar2);
            if (iVar2 <= iVar4) break;
            uVar10 = OPENSSL_sk_value(*(undefined4 *)(iVar6 + 0xa8),iVar4);
            iVar2 = (int)((ulonglong)uVar10 >> 0x20);
            if ((**(int **)((int)uVar10 + 4) == 0) &&
               (iVar3 = OPENSSL_sk_find(param_3,(int)uVar10), iVar2 = param_1, -1 < iVar3)) {
              *(undefined4 *)(param_1 + 0x60) = 0x2e;
              *(int *)(param_1 + 0x5c) = iVar8;
              *(int *)(param_1 + 100) = iVar6;
              uVar10 = (**(code **)(param_1 + 0x1c))(0);
              iVar2 = (int)((ulonglong)uVar10 >> 0x20);
              iVar1 = (int)uVar10;
              if (iVar1 == 0) break;
            }
            iVar3 = *(int *)(iVar6 + 0xa8);
            iVar4 = iVar4 + 1;
          }
        }
      }
      goto LAB_0017ae48;
    }
    ERR_put_error(0x22,0xa6,0x41,"crypto/x509v3/v3_addr.c",0x4cd);
    if (param_1 != 0) {
LAB_0017aee0:
      param_3 = 0;
      *(undefined4 *)(param_1 + 0x60) = 0x11;
      iVar1 = param_3;
      goto LAB_0017ae48;
    }
  }
  iVar1 = 0;
  param_3 = 0;
LAB_0017ae48:
  OPENSSL_sk_free(param_3);
  return iVar1;
}

