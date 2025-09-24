
undefined4 tls_choose_sigalg(int param_1,int param_2)

{
  RSA *rsa;
  int iVar1;
  EC_KEY *key;
  EC_GROUP *group;
  uint uVar2;
  uint uVar3;
  int iVar4;
  uint uVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  int iVar9;
  uint uVar10;
  int iVar11;
  uint uVar12;
  uint uVar13;
  int iVar14;
  EVP_MD *local_2c [2];
  
  piVar8 = *(int **)(param_1 + 4);
  iVar4 = *(int *)(param_1 + 0x7c);
  uVar2 = *(uint *)(piVar8[0x19] + 0x30);
  *(undefined4 *)(iVar4 + 0x264) = 0;
  *(undefined4 *)(iVar4 + 0x260) = 0;
  if ((uVar2 & 8) == 0) {
    iVar9 = *piVar8;
    iVar11 = iVar9 + -0x10000;
    if (iVar11 != 0) {
      iVar11 = 1;
    }
    if (iVar9 < 0x304) {
      iVar11 = 0;
    }
    if (iVar11 == 0) goto LAB_000fcd58;
    iVar4 = find_sig_alg(param_1,0);
    if (iVar4 == 0) {
      if (param_2 == 0) {
        return 1;
      }
      uVar7 = 0xac8;
      goto LAB_000fd05a;
    }
  }
  else {
LAB_000fcd58:
    if ((*(uint *)(*(int *)(iVar4 + 0x210) + 0x14) & 0xab) == 0) {
      return 1;
    }
    if (*(int *)(param_1 + 0x1c) == 0) {
      piVar8 = *(int **)(param_1 + 0x404);
      iVar9 = *piVar8 - (int)(piVar8 + 5) >> 2;
      if (8 < (uint)(iVar9 * -0x33333333)) {
        return 1;
      }
      if (piVar8[iVar9 + 5] == 0) {
        return 1;
      }
      if (piVar8[iVar9 + 6] == 0) {
        return 1;
      }
    }
    if ((int)(uVar2 << 0x1e) < 0) {
      if (*(int *)(iVar4 + 0x268) == 0) {
        iVar4 = tls1_get_legacy_sigalg(param_1,0xffffffff);
        if (iVar4 != 0) {
          iVar9 = tls12_get_psigalgs(param_1,1,local_2c);
          if (iVar9 != 0) {
            iVar11 = 0;
            do {
              if ((*(short *)(iVar4 + 4) == (short)local_2c[0]->type) &&
                 (*(uint *)(iVar4 + 0x14) < 9)) {
                iVar1 = *(int *)(param_1 + 0x404) + *(uint *)(iVar4 + 0x14) * 0x14;
                iVar14 = *(int *)(iVar1 + 0x14);
                if ((iVar14 != 0) &&
                   ((iVar1 = *(int *)(iVar1 + 0x18), iVar1 != 0 &&
                    (iVar1 = check_cert_usable_isra_8(param_1 + 0x7c,iVar4 + 8,iVar14,iVar1),
                    iVar1 != 0)))) {
                  if (iVar9 != iVar11) goto LAB_000fcd54;
                  break;
                }
              }
              iVar11 = iVar11 + 1;
              local_2c[0] = (EVP_MD *)((int)&local_2c[0]->type + 2);
            } while (iVar9 != iVar11);
          }
          if (param_2 == 0) {
            return 1;
          }
          ossl_statem_fatal(param_1,0x2f,0x201,0x172,"ssl/t1_lib.c",0xb38);
          return 0;
        }
        if (param_2 == 0) {
          return 1;
        }
        uVar7 = 0xb28;
LAB_000fcf6a:
        ossl_statem_fatal(param_1,0x50,0x201,0x44,"ssl/t1_lib.c",uVar7);
        return 0;
      }
      if ((*(uint *)(*(int *)(param_1 + 0x404) + 0x10) & 0x30000) == 0) {
        iVar9 = -1;
      }
      else {
        key = (EC_KEY *)EVP_PKEY_get0_EC_KEY(*(undefined4 *)(*(int *)(param_1 + 0x404) + 0x54));
        group = EC_KEY_get0_group(key);
        iVar9 = EC_GROUP_get_curve_name(group);
      }
      uVar2 = *(uint *)(param_1 + 0xf8c);
      if (uVar2 == 0) {
LAB_000fce9c:
        if ((*(uint *)(*(int *)(*(int *)(param_1 + 0x7c) + 0x210) + 0x14) & 0xa0) == 0) {
LAB_000fceac:
          if (param_2 == 0) {
            return 1;
          }
          ossl_statem_fatal(param_1,0x28,0x201,0x76,"ssl/t1_lib.c",0xb1a);
          return 0;
        }
        iVar4 = tls1_get_legacy_sigalg(param_1,0xffffffff);
        if (iVar4 == 0) {
          if (param_2 == 0) {
            return 1;
          }
          uVar7 = 0xb0d;
LAB_000fd05a:
          ossl_statem_fatal(param_1,0x28,0x201,0x76,"ssl/t1_lib.c",uVar7);
          return 0;
        }
        if (*(int *)(param_1 + 0xf8c) == 0) goto LAB_000fceac;
        uVar12 = *(uint *)(iVar4 + 0x14);
      }
      else {
        uVar10 = 0;
        uVar3 = uVar2;
LAB_000fcdce:
        do {
          iVar4 = *(int *)(*(int *)(param_1 + 0xf88) + uVar10 * 4);
          if (*(int *)(param_1 + 0x1c) == 0) {
            uVar13 = *(uint *)(iVar4 + 0x14);
            uVar5 = (**(int **)(param_1 + 0x404) - (int)(*(int **)(param_1 + 0x404) + 5) >> 2) *
                    -0x33333333;
            uVar12 = uVar13;
            if ((uVar5 - uVar13 == 0) && (uVar2 = uVar3, uVar12 = uVar5, uVar5 != 0xffffffff)) {
LAB_000fce22:
              uVar12 = uVar13;
              if (uVar12 < 9) {
                iVar11 = *(int *)(param_1 + 0x404) + uVar12 * 0x14;
                if ((*(int *)(iVar11 + 0x14) != 0) && (*(int *)(iVar11 + 0x18) != 0)) {
                  iVar11 = check_cert_usable_isra_8(param_1 + 0x7c,iVar4 + 8);
                  if (iVar11 == 0) {
                    uVar3 = *(uint *)(param_1 + 0xf8c);
                    uVar2 = uVar3;
                    goto LAB_000fcdc8;
                  }
                  if (*(int *)(iVar4 + 0x10) == 0x390) {
                    rsa = (RSA *)EVP_PKEY_get0(*(EVP_PKEY **)
                                                (*(int *)(param_1 + 0x404) + uVar12 * 0x14 + 0x18));
                    if (((rsa != (RSA *)0x0) &&
                        (iVar11 = tls1_lookup_md(iVar4,local_2c), iVar11 != 0)) &&
                       (local_2c[0] != (EVP_MD *)0x0)) {
                      iVar11 = RSA_size(rsa);
                      iVar1 = EVP_MD_size(local_2c[0]);
                      if (iVar11 + (iVar1 + 1) * -2 < 0 == SBORROW4(iVar11,(iVar1 + 1) * 2))
                      goto LAB_000fce54;
                    }
                  }
                  else {
LAB_000fce54:
                    if ((iVar9 == -1) || (iVar9 == *(int *)(iVar4 + 0x1c))) {
                      uVar2 = *(uint *)(param_1 + 0xf8c);
                      break;
                    }
                  }
                }
              }
              uVar2 = *(uint *)(param_1 + 0xf8c);
              uVar10 = uVar10 + 1;
              uVar3 = uVar2;
              if (uVar2 <= uVar10) break;
              goto LAB_000fcdce;
            }
          }
          else {
            uVar13 = *(uint *)(iVar4 + 0x14);
            piVar8 = (int *)ssl_cert_lookup_by_idx(uVar13);
            if (piVar8 != (int *)0x0) {
              iVar11 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
              if (((piVar8[1] & *(uint *)(iVar11 + 0x14)) != 0) &&
                 ((*piVar8 != 0x390 || (-1 < *(int *)(iVar11 + 0x10) << 0x1f)))) {
                uVar2 = *(uint *)(*(int *)(param_1 + 0x7c) + uVar13 * 4 + 0x27c) & 1 ^ 1;
                if (uVar13 == 0xffffffff) {
                  uVar2 = 1;
                }
                if (uVar2 == 0) goto LAB_000fce22;
              }
            }
            uVar3 = *(uint *)(param_1 + 0xf8c);
            uVar2 = uVar3;
            uVar12 = 0xffffffff;
          }
LAB_000fcdc8:
          uVar10 = uVar10 + 1;
        } while (uVar10 < uVar3);
        if (uVar10 == uVar2) goto LAB_000fce9c;
      }
      if (uVar12 != 0xffffffff) goto LAB_000fce7a;
    }
    else {
      iVar4 = tls1_get_legacy_sigalg(param_1,0xffffffff);
      if (iVar4 == 0) {
        if (param_2 == 0) {
          return 1;
        }
        uVar7 = 0xb41;
        goto LAB_000fcf6a;
      }
    }
  }
LAB_000fcd54:
  uVar12 = *(uint *)(iVar4 + 0x14);
LAB_000fce7a:
  piVar8 = *(int **)(param_1 + 0x404);
  iVar9 = *(int *)(param_1 + 0x7c);
  piVar6 = piVar8 + uVar12 * 5 + 5;
  *(int **)(iVar9 + 0x264) = piVar6;
  *piVar8 = (int)piVar6;
  *(int *)(iVar9 + 0x260) = iVar4;
  return 1;
}

