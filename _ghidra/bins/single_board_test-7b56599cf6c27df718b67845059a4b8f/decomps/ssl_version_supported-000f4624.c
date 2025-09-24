
bool ssl_version_supported(int *param_1,int param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  EC_KEY *key;
  EC_GROUP *group;
  int iVar2;
  int iVar3;
  uint uVar4;
  undefined1 *puVar5;
  int *piVar6;
  int iVar7;
  int iVar8;
  
  piVar6 = (int *)param_1[1];
  if (*piVar6 == 0x10000) {
    iVar3 = 0x304;
    puVar5 = (undefined1 *)&tls_version_table;
  }
  else {
    if (*piVar6 != 0x1ffff) {
      return *param_1 == param_2;
    }
    iVar3 = 0xfefd;
    puVar5 = dtls_version_table;
  }
  iVar8 = param_2;
  if (param_2 == 0x100) {
    iVar8 = 0xff00;
  }
  do {
    if (param_2 == iVar3) {
      if (*(code **)((int)puVar5 + 4) != (code *)0x0) {
        piVar6 = (int *)(**(code **)((int)puVar5 + 4))();
        iVar3 = param_1[0x13d];
        iVar7 = *piVar6;
        if ((iVar3 == 0) || (iVar7 == iVar3)) {
LAB_000f46b8:
          iVar3 = ssl_security(param_1,9,0,iVar7,0);
          if (iVar3 != 0) {
            iVar3 = param_1[0x13e];
            if ((iVar3 == 0) || (iVar7 == iVar3)) {
LAB_000f4730:
              if (((param_1[0x13b] & piVar6[2]) == 0) &&
                 ((-1 < piVar6[1] << 0x1e || ((*(uint *)(param_1[0x101] + 0x10) & 0x30000) == 0))))
              {
                uVar4 = param_2 - 0x304;
                if (uVar4 != 0) {
                  uVar4 = 1;
                }
                if (param_1[7] == 0) {
                  uVar4 = uVar4 | 1;
                }
                if (uVar4 != 0) {
LAB_000f477a:
                  if (param_3 == (undefined4 *)0x0) {
                    return true;
                  }
                  uVar1 = (**(code **)((int)puVar5 + 4))();
                  *param_3 = uVar1;
                  return true;
                }
                if ((param_1[0x134] != 0) && (param_1[0x178] != 0)) {
                  if (((*(int *)(param_1[0x134] + 0x130) == 0) &&
                      (((*(int *)(param_1[0x178] + 0x130) == 0 && (param_1[0x131] == 0)) &&
                       (param_1[0x132] == 0)))) && (*(int *)(param_1[0x101] + 0xe0) == 0)) {
                    iVar3 = 1;
                    uVar4 = 0;
                    do {
                      if ((uVar4 == 2) || ((1 < uVar4 && (uVar4 - 4 < 3)))) {
LAB_000f4816:
                        if (iVar3 == 9) goto LAB_000f46e4;
                      }
                      else {
                        iVar7 = param_1[0x101] + uVar4 * 0x14;
                        if ((*(int *)(iVar7 + 0x14) == 0) || (*(int *)(iVar7 + 0x18) == 0))
                        goto LAB_000f4816;
                        if (uVar4 != 3) break;
                        key = (EC_KEY *)EVP_PKEY_get0_EC_KEY(*(undefined4 *)(param_1[0x101] + 0x54))
                        ;
                        if (key != (EC_KEY *)0x0) {
                          group = EC_KEY_get0_group(key);
                          iVar7 = EC_GROUP_get_curve_name(group);
                          iVar7 = tls_check_sigalg_curve(param_1,iVar7);
                          if (iVar7 != 0) break;
                        }
                      }
                      uVar4 = uVar4 + 1;
                      iVar3 = iVar3 + 1;
                    } while( true );
                  }
                  goto LAB_000f477a;
                }
              }
            }
            else if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
              if (iVar7 < iVar3) goto LAB_000f4730;
            }
            else {
              if (iVar7 == 0x100) {
                if (iVar3 == 0x100) goto LAB_000f46e4;
                iVar7 = 0xff00;
              }
              else if (iVar3 == 0x100) {
                iVar3 = 0xff00;
              }
              if (iVar3 < iVar7) goto LAB_000f4730;
            }
          }
        }
        else if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
          if (iVar3 <= iVar7) goto LAB_000f46b8;
        }
        else {
          if (iVar7 == 0x100) {
            if (iVar3 == 0x100) goto LAB_000f46b8;
            iVar2 = 0xff00;
          }
          else {
            iVar2 = iVar7;
            if (iVar3 == 0x100) {
              iVar3 = 0xff00;
            }
          }
          if (iVar2 <= iVar3) goto LAB_000f46b8;
        }
      }
    }
    else if ((*(uint *)(piVar6[0x19] + 0x30) & 8) == 0) {
      if (iVar3 <= param_2) {
        return false;
      }
    }
    else {
      if (iVar3 == 0x100) {
        iVar3 = 0xff00;
      }
      if (iVar8 <= iVar3) {
        return false;
      }
    }
LAB_000f46e4:
    HintPreloadData((int *)((int)puVar5 + 0x18));
    puVar5 = (undefined1 *)((int)puVar5 + 0xc);
    iVar3 = *(int *)puVar5;
    if (iVar3 == 0) {
      return false;
    }
    piVar6 = (int *)param_1[1];
  } while( true );
}

