
undefined4 ssl_choose_server_version(uint *param_1,int param_2,undefined4 *param_3)

{
  bool bVar1;
  uint *puVar2;
  int iVar3;
  uint uVar4;
  uint uVar5;
  byte *pbVar6;
  uint uVar7;
  int iVar8;
  uint uVar9;
  int *piVar10;
  uint uVar11;
  byte *pbVar12;
  undefined1 *puVar13;
  uint local_2c [2];
  
  piVar10 = (int *)param_1[1];
  uVar11 = *(uint *)(param_2 + 4);
  iVar8 = *piVar10;
  param_1[0x141] = uVar11;
  if (iVar8 == 0x10000) {
LAB_000fe5fe:
    puVar13 = (undefined1 *)&tls_version_table;
    uVar9 = 0x304;
    iVar8 = *(int *)(param_2 + 0x268);
    iVar3 = *(int *)(iVar8 + 0x1a0);
  }
  else {
    if (iVar8 != 0x1ffff) {
      if ((iVar8 < 0x304 || iVar8 == 0x10000) || (int)(*(uint *)(piVar10[0x19] + 0x30) << 0x1c) < 0)
      {
        uVar9 = *param_1;
        if (uVar11 != uVar9) {
          if ((*(uint *)(piVar10[0x19] + 0x30) & 8) == 0) {
            if ((int)uVar11 < (int)uVar9) {
              return 0x10a;
            }
          }
          else {
            if (uVar11 == 0x100) {
              if (uVar9 == 0x100) goto LAB_000fe7d0;
              uVar11 = 0xff00;
            }
            else if (uVar9 == 0x100) {
              uVar9 = 0xff00;
            }
            if ((int)uVar9 < (int)uVar11) {
              return 0x10a;
            }
          }
        }
LAB_000fe7d0:
        *param_3 = 0;
        return 0;
      }
      goto LAB_000fe5fe;
    }
    iVar8 = *(int *)(param_2 + 0x268);
    uVar9 = 0xfefd;
    iVar3 = *(int *)(iVar8 + 0x1a0);
    puVar13 = dtls_version_table;
  }
  if (iVar3 == 0) {
    if (param_1[0x113] != 0) {
      return 0x102;
    }
    uVar4 = *(uint *)(piVar10[0x19] + 0x30);
LAB_000fe61a:
    if (uVar11 == 0x304) {
      uVar11 = 0x303;
    }
    else if ((uVar4 & 8) == 0) {
      if (0x302 < (int)uVar11) {
        uVar11 = 0x303;
      }
    }
    else if (uVar11 != 0x100 && (int)uVar11 < 0x305) {
      uVar11 = 0x303;
    }
    bVar1 = false;
    do {
      if (*(code **)((int)puVar13 + 8) == (code *)0x0) goto LAB_000fe67e;
      if (uVar11 == uVar9) {
LAB_000fe646:
        puVar2 = (uint *)(**(code **)((int)puVar13 + 8))();
        uVar9 = param_1[0x13d];
        uVar4 = *puVar2;
        if ((uVar9 == 0) || (uVar4 == uVar9)) {
LAB_000fe668:
          iVar8 = ssl_security(param_1,9,0,uVar4,0);
          if (iVar8 != 0) {
            uVar9 = param_1[0x13e];
            if ((uVar9 == 0) || (uVar4 == uVar9)) {
LAB_000fe736:
              if (((param_1[0x13b] & puVar2[2]) == 0) &&
                 ((-1 < (int)(puVar2[1] << 0x1e) ||
                  ((*(uint *)(param_1[0x101] + 0x10) & 0x30000) == 0)))) {
                uVar11 = *(uint *)puVar13;
                if (uVar11 == 0x303) {
                  iVar8 = ssl_version_supported(param_1,0x304,0);
                  if (iVar8 != 0) {
                    uVar11 = *(uint *)puVar13;
                    *param_3 = 1;
                    goto LAB_000fe786;
                  }
LAB_000fe936:
                  uVar11 = *(uint *)puVar13;
                }
                else if (((uint)((int)uVar11 < 0x303) &
                         (*(uint *)(*(int *)(param_1[1] + 100) + 0x30) ^ 8) >> 3) != 0) {
                  iVar8 = ssl_version_supported(param_1,0x303,0);
                  if (iVar8 != 0) {
                    uVar11 = *(uint *)puVar13;
                    *param_3 = 2;
                    goto LAB_000fe786;
                  }
                  goto LAB_000fe936;
                }
                *param_3 = 0;
LAB_000fe786:
                *param_1 = uVar11;
                param_1[1] = (uint)puVar2;
                return 0;
              }
            }
            else if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
              if ((int)uVar4 < (int)uVar9) goto LAB_000fe736;
            }
            else {
              if (uVar4 == 0x100) {
                if (uVar9 == 0x100) goto LAB_000fe67c;
                uVar4 = 0xff00;
              }
              else if (uVar9 == 0x100) {
                uVar9 = 0xff00;
              }
              if ((int)uVar9 < (int)uVar4) goto LAB_000fe736;
            }
          }
        }
        else if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
          if ((int)uVar9 <= (int)uVar4) goto LAB_000fe668;
        }
        else {
          if (uVar4 == 0x100) {
            if (uVar9 == 0x100) goto LAB_000fe668;
            uVar5 = 0xff00;
          }
          else {
            uVar5 = uVar4;
            if (uVar9 == 0x100) {
              uVar9 = 0xff00;
            }
          }
          if ((int)uVar5 <= (int)uVar9) goto LAB_000fe668;
        }
LAB_000fe67c:
        bVar1 = true;
      }
      else if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
        if ((int)uVar9 <= (int)uVar11) goto LAB_000fe646;
      }
      else {
        if (uVar11 == 0x100) {
          if (uVar9 == 0x100) goto LAB_000fe646;
          uVar4 = 0xff00;
        }
        else {
          uVar4 = uVar11;
          if (uVar9 == 0x100) {
            uVar9 = 0xff00;
          }
        }
        if ((int)uVar4 <= (int)uVar9) goto LAB_000fe646;
      }
LAB_000fe67e:
      HintPreloadData((uint *)((int)puVar13 + 0x24));
      puVar13 = (undefined1 *)((int)puVar13 + 0xc);
      uVar9 = *(uint *)puVar13;
      if (uVar9 == 0) {
        if (bVar1) {
          return 0x102;
        }
        return 0x18c;
      }
    } while( true );
  }
  uVar4 = *(uint *)(piVar10[0x19] + 0x30);
  if ((uVar4 & 8) != 0) goto LAB_000fe61a;
  *(undefined4 *)(iVar8 + 0x1a4) = 1;
  if (*(int *)(iVar8 + 0x19c) == 0) {
    return 0x9f;
  }
  pbVar6 = *(byte **)(iVar8 + 0x198);
  uVar9 = *(int *)(iVar8 + 0x19c) - 1;
  uVar4 = (uint)*pbVar6;
  if (uVar9 < uVar4) {
    return 0x9f;
  }
  if (uVar4 != uVar9) {
    return 0x9f;
  }
  *(undefined4 *)(iVar8 + 0x19c) = 0;
  *(byte **)(iVar8 + 0x198) = pbVar6 + uVar4 + 1;
  if ((int)uVar11 < 0x301) {
    return 0x124;
  }
  uVar11 = 0;
  local_2c[0] = 0;
  for (pbVar12 = pbVar6 + 3; pbVar12 != pbVar6 + (uVar4 & 0xfe) + 3; pbVar12 = pbVar12 + 2) {
    uVar9 = (uint)CONCAT11(pbVar12[-2],pbVar12[-1]);
    if (uVar9 != uVar11) {
      if ((*(uint *)(*(int *)(param_1[1] + 100) + 0x30) & 8) == 0) {
        if (uVar11 <= uVar9) goto LAB_000fe87e;
      }
      else {
        uVar5 = uVar11;
        if (uVar9 == 0x100) {
          if (uVar11 == 0x100) goto LAB_000fe87e;
          uVar7 = 0xff00;
        }
        else {
          uVar7 = uVar9;
          if (uVar11 == 0x100) {
            uVar5 = 0xff00;
          }
        }
        if (uVar7 <= uVar5) {
LAB_000fe87e:
          iVar8 = ssl_version_supported(param_1,uVar9,local_2c);
          if (iVar8 != 0) {
            uVar11 = uVar9;
          }
        }
      }
    }
  }
  if (uVar4 != (uVar4 & 0xfe)) {
    return 0x9f;
  }
  if (uVar11 == 0) {
    return 0x102;
  }
  if (param_1[0x113] != 0) {
    if (uVar11 == 0x304) {
      return 0;
    }
    return 0x102;
  }
  if (uVar11 == 0x303) {
    iVar8 = ssl_version_supported(param_1,0x304);
    if (iVar8 != 0) {
      *param_3 = 1;
      goto LAB_000fe988;
    }
  }
  else if ((((uint)(uVar11 < 0x303) & (*(uint *)(*(int *)(param_1[1] + 100) + 0x30) ^ 8) >> 3) != 0)
          && (iVar8 = ssl_version_supported(param_1), iVar8 != 0)) {
    *param_3 = 2;
    goto LAB_000fe988;
  }
  *param_3 = 0;
LAB_000fe988:
  *param_1 = uVar11;
  param_1[1] = local_2c[0];
  return 0;
}

