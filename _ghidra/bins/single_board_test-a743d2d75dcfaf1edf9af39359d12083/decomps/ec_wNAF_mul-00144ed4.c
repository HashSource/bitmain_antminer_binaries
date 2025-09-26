
/* WARNING: Type propagation algorithm not settling */

EC_POINT *
ec_wNAF_mul(EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,EC_POINT *param_4,
           undefined4 *param_5,int param_6,BN_CTX *param_7)

{
  undefined4 *puVar1;
  BIGNUM *pBVar2;
  uint uVar3;
  void *__dest;
  int iVar4;
  undefined4 uVar5;
  EC_POINT *pEVar6;
  int iVar7;
  EC_POINT *pEVar8;
  EC_POINT *pEVar9;
  EC_POINT *pEVar10;
  EC_POINT *pEVar11;
  int *piVar12;
  EC_POINT *pEVar13;
  EC_POINT *pEVar14;
  EC_POINT *pEVar15;
  int iVar16;
  EC_POINT *local_7c;
  EC_POINT *local_74;
  EC_POINT *local_70;
  EC_POINT *local_6c;
  EC_POINT *local_64;
  EC_POINT *local_60;
  BN_CTX *local_5c;
  uint local_58;
  EC_POINT *local_54;
  int local_50;
  int local_4c;
  EC_POINT *local_48;
  EC_POINT *local_40;
  EC_POINT *local_2c [2];
  
  if (*(int *)param_1 != *(int *)param_2) {
    iVar7 = 0x168;
LAB_00144ef0:
    ERR_put_error(0x10,0xbb,0x65,"ec_mult.c",iVar7);
    return (EC_POINT *)0x0;
  }
  if (param_4 == (EC_POINT *)0x0 && param_3 == (BIGNUM *)0x0) {
    pEVar8 = (EC_POINT *)EC_POINT_set_to_infinity(param_1,param_2);
    return pEVar8;
  }
  pEVar8 = (EC_POINT *)0x0;
  if (param_4 != (EC_POINT *)0x0) {
    iVar7 = *(int *)*param_5;
    puVar1 = param_5;
    while (*(int *)param_1 == iVar7) {
      pEVar8 = pEVar8 + 1;
      if (pEVar8 == param_4) goto LAB_00144f3e;
      puVar1 = puVar1 + 1;
      iVar7 = *(int *)*puVar1;
    }
    iVar7 = 0x172;
    goto LAB_00144ef0;
  }
LAB_00144f3e:
  if (param_7 == (BN_CTX *)0x0) {
    param_7 = BN_CTX_new();
    local_5c = param_7;
    if (param_7 == (BN_CTX *)0x0) {
      return (EC_POINT *)0x0;
    }
  }
  else {
    local_5c = (BN_CTX *)0x0;
  }
  if (param_3 == (BIGNUM *)0x0) {
    local_70 = (EC_POINT *)0x0;
    local_58 = 0;
    local_54 = (EC_POINT *)0x0;
    local_50 = 0;
    local_4c = 0;
    local_48 = (EC_POINT *)0x0;
  }
  else {
    local_54 = EC_GROUP_get0_generator(param_1);
    if (local_54 == (EC_POINT *)0x0) {
      iVar7 = 0x71;
      iVar4 = 0x180;
LAB_00145208:
      pEVar11 = (EC_POINT *)0x0;
      ERR_put_error(0x10,0xbb,iVar7,"ec_mult.c",iVar4);
      pEVar8 = pEVar11;
      pEVar14 = pEVar11;
      pEVar10 = pEVar11;
      local_74 = pEVar11;
      local_6c = pEVar11;
      local_64 = pEVar11;
      goto LAB_001450c4;
    }
    local_70 = (EC_POINT *)
               EC_EX_DATA_get_data(*(undefined4 *)(param_1 + 0x44),0x144c89,0x144e85,0x144e25);
    if (local_70 == (EC_POINT *)0x0) {
      local_50 = 1;
      local_58 = 1;
      local_4c = 0;
      local_48 = (EC_POINT *)0x0;
    }
    else if (*(int *)((int)local_70 + 8) == 0) {
      local_50 = 1;
      local_58 = 1;
      local_70 = (EC_POINT *)0x0;
      local_4c = 0;
      local_48 = (EC_POINT *)0x0;
    }
    else {
      iVar7 = EC_POINT_cmp(param_1,local_54,(EC_POINT *)**(undefined4 **)((int)local_70 + 0x10),
                           param_7);
      if (iVar7 == 0) {
        local_48 = *(EC_POINT **)((int)local_70 + 4);
        iVar7 = BN_num_bits(param_3);
        uVar3 = *(uint *)((int)local_70 + 8);
        local_4c = 1 << (*(int *)((int)local_70 + 0xc) - 1U & 0xff);
        if (*(int *)((int)local_70 + 0x14) != uVar3 * local_4c) {
          iVar4 = 0x19f;
          iVar7 = 0x44;
          goto LAB_00145208;
        }
        iVar7 = __aeabi_uidiv(iVar7,local_48);
        local_58 = iVar7 + 1U;
        if (uVar3 <= iVar7 + 1U) {
          local_58 = uVar3;
        }
        local_50 = 0;
      }
      else {
        local_70 = (EC_POINT *)0x0;
        local_50 = 1;
        local_58 = 1;
        local_4c = 0;
        local_48 = (EC_POINT *)0x0;
      }
    }
  }
  local_60 = param_4 + local_58;
  iVar7 = (int)local_60 * 4;
  local_74 = (EC_POINT *)CRYPTO_malloc(iVar7,"ec_mult.c",0x1ad);
  local_64 = (EC_POINT *)CRYPTO_malloc(iVar7,"ec_mult.c",0x1ae);
  pEVar8 = (EC_POINT *)CRYPTO_malloc((int)(local_60 + 1) * 4,"ec_mult.c",0x1af);
  local_6c = (EC_POINT *)CRYPTO_malloc(iVar7,"ec_mult.c",0x1b1);
  if (pEVar8 != (EC_POINT *)0x0) {
    *(EC_POINT **)pEVar8 = (EC_POINT *)0x0;
  }
  if ((local_74 == (EC_POINT *)0x0 || local_64 == (EC_POINT *)0x0) ||
     (pEVar8 == (EC_POINT *)0x0 || local_6c == (EC_POINT *)0x0)) {
    pEVar11 = (EC_POINT *)0x0;
    ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x1b8);
    pEVar14 = (EC_POINT *)0x0;
    pEVar10 = (EC_POINT *)0x0;
    goto LAB_001450c4;
  }
  pEVar10 = (EC_POINT *)0x0;
  pEVar9 = param_4 + local_50;
  pEVar13 = pEVar10;
  local_40 = pEVar10;
  pEVar11 = local_64;
  pEVar14 = pEVar10;
  while (pEVar14 != pEVar9) {
    pBVar2 = param_3;
    if (pEVar14 < param_4) {
      pBVar2 = *(BIGNUM **)(pEVar10 + param_6);
    }
    uVar3 = BN_num_bits(pBVar2);
    if (uVar3 < 2000) {
      if (uVar3 < 800) {
        if (uVar3 < 300) {
          if (uVar3 < 0x46) {
            if (uVar3 < 0x14) {
              uVar5 = 1;
              iVar7 = 1;
            }
            else {
              uVar5 = 2;
              iVar7 = 2;
            }
          }
          else {
            uVar5 = 3;
            iVar7 = 4;
          }
        }
        else {
          uVar5 = 4;
          iVar7 = 8;
        }
      }
      else {
        uVar5 = 5;
        iVar7 = 0x10;
      }
    }
    else {
      uVar5 = 6;
      iVar7 = 0x20;
    }
    pEVar13 = pEVar13 + iVar7;
    if (pEVar14 < param_4) {
      iVar7 = param_6;
    }
    pEVar15 = pEVar14 + 1;
    *(undefined4 *)(local_74 + (int)pEVar10) = uVar5;
    *(undefined4 *)(pEVar8 + (int)pEVar10 + 4) = 0;
    pBVar2 = param_3;
    if (pEVar14 < param_4) {
      pBVar2 = *(BIGNUM **)(pEVar10 + iVar7);
    }
    iVar7 = compute_wNAF(pBVar2,uVar5,pEVar11);
    pEVar14 = pEVar11 + 4;
    *(int *)(pEVar8 + (int)pEVar10) = iVar7;
    if (iVar7 == 0) {
      pEVar11 = (EC_POINT *)0x0;
      pEVar14 = (EC_POINT *)0x0;
      pEVar10 = (EC_POINT *)0x0;
      goto LAB_001450c4;
    }
    pEVar6 = *(EC_POINT **)pEVar11;
    pEVar10 = pEVar10 + 4;
    pEVar11 = pEVar14;
    pEVar14 = pEVar15;
    if (local_40 < pEVar6) {
      local_40 = pEVar6;
    }
  }
  if (local_58 != 0) {
    if (local_70 != (EC_POINT *)0x0) {
      local_2c[0] = (EC_POINT *)0x0;
      if (local_50 == 0) {
        iVar7 = (int)param_4 * 4;
        uVar5 = *(undefined4 *)((int)local_70 + 0xc);
        *(undefined4 *)(local_74 + (int)param_4 * 4) = uVar5;
        pEVar11 = (EC_POINT *)compute_wNAF(param_3,uVar5,local_2c);
        if (pEVar11 != (EC_POINT *)0x0) {
          if (local_40 < local_2c[0]) {
            if (local_2c[0] < (EC_POINT *)((int)local_48 * local_58)) {
              uVar3 = __aeabi_uidiv(local_2c[0] + -1 + (int)local_48);
              if (*(uint *)((int)local_70 + 8) < uVar3) {
                iVar7 = 0x20c;
                goto LAB_001451c8;
              }
              local_60 = param_4 + uVar3;
            }
            piVar12 = *(int **)((int)local_70 + 0x10);
            if (param_4 < local_60) {
              local_7c = pEVar8 + iVar7;
              pEVar14 = pEVar11;
              pEVar10 = param_4;
              do {
                pEVar15 = local_64 + iVar7;
                if (pEVar10 < local_60 + -1) {
                  *(EC_POINT **)(local_64 + iVar7) = local_48;
                  pEVar6 = local_2c[0] + -(int)local_48;
                  if (local_2c[0] < local_48) {
                    iVar7 = 0x21a;
                    goto LAB_001451c8;
                  }
                }
                else {
                  *(EC_POINT **)(local_64 + iVar7) = local_2c[0];
                  pEVar6 = local_2c[0];
                }
                local_2c[0] = pEVar6;
                pEVar10 = pEVar10 + 1;
                local_7c = local_7c + 4;
                *(undefined4 *)local_7c = 0;
                HintPreloadData(piVar12 + local_4c * 4);
                __dest = CRYPTO_malloc(*(size_t *)pEVar15,"ec_mult.c",0x226);
                *(void **)(pEVar8 + iVar7) = __dest;
                if (__dest == (void *)0x0) {
                  ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x228);
                  CRYPTO_free(pEVar11);
                  goto LAB_001451d6;
                }
                memcpy(__dest,pEVar14,*(size_t *)pEVar15);
                if (local_40 < *(EC_POINT **)pEVar15) {
                  local_40 = *(EC_POINT **)pEVar15;
                }
                if (*piVar12 == 0) {
                  ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x231);
                  CRYPTO_free(pEVar11);
                  goto LAB_001451d6;
                }
                *(int **)(local_6c + iVar7) = piVar12;
                iVar7 = iVar7 + 4;
                piVar12 = piVar12 + local_4c;
                pEVar14 = pEVar14 + (int)local_48;
              } while (pEVar10 < local_60);
            }
            CRYPTO_free(pEVar11);
          }
          else {
            local_60 = param_4 + 1;
            *(EC_POINT **)(pEVar8 + (int)param_4 * 4) = pEVar11;
            *(undefined4 *)(pEVar8 + (int)local_60 * 4) = 0;
            uVar5 = *(undefined4 *)((int)local_70 + 0x10);
            *(EC_POINT **)(local_64 + (int)param_4 * 4) = local_2c[0];
            *(undefined4 *)(local_6c + (int)param_4 * 4) = uVar5;
            if (local_40 < local_2c[0]) {
              local_40 = local_2c[0];
            }
          }
          goto LAB_00145298;
        }
      }
      else {
        iVar7 = 0x1df;
LAB_001451c8:
        ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",iVar7);
      }
LAB_001451d6:
      pEVar11 = (EC_POINT *)0x0;
      pEVar14 = (EC_POINT *)0x0;
      pEVar10 = (EC_POINT *)0x0;
      goto LAB_001450c4;
    }
    if (local_50 != 1) {
      ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x1d6);
      pEVar11 = (EC_POINT *)0x0;
      pEVar14 = (EC_POINT *)0x0;
      pEVar10 = (EC_POINT *)0x0;
      goto LAB_001450c4;
    }
  }
LAB_00145298:
  pEVar11 = (EC_POINT *)CRYPTO_malloc((int)(pEVar13 + 1) * 4,"ec_mult.c",0x243);
  if (pEVar11 == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0xbb,0x41,"ec_mult.c",0x245);
    pEVar14 = (EC_POINT *)0x0;
    pEVar10 = (EC_POINT *)0x0;
  }
  else {
    *(undefined4 *)(pEVar11 + (int)pEVar13 * 4) = 0;
    pEVar14 = pEVar11;
    if (pEVar9 != (EC_POINT *)0x0) {
      pEVar10 = (EC_POINT *)0x0;
      do {
        iVar7 = *(int *)(local_74 + (int)pEVar10 * 4);
        *(EC_POINT **)(local_6c + (int)pEVar10 * 4) = pEVar14;
        if (1 << (iVar7 - 1U & 0xff) != 0) {
          uVar3 = 0;
          pEVar15 = pEVar14;
          do {
            uVar3 = uVar3 + 1;
            pEVar6 = EC_POINT_new(param_1);
            pEVar14 = pEVar15 + 4;
            *(EC_POINT **)pEVar15 = pEVar6;
            if (pEVar6 == (EC_POINT *)0x0) {
              pEVar14 = (EC_POINT *)0x0;
              pEVar10 = (EC_POINT *)0x0;
              goto LAB_001450c4;
            }
            pEVar15 = pEVar14;
          } while (uVar3 < (uint)(1 << (*(int *)(local_74 + (int)pEVar10 * 4) - 1U & 0xff)));
        }
        pEVar10 = pEVar10 + 1;
      } while (pEVar9 != pEVar10);
    }
    if (pEVar14 == pEVar11 + (int)pEVar13 * 4) {
      pEVar10 = EC_POINT_new(param_1);
      if (pEVar10 == (EC_POINT *)0x0) {
        pEVar14 = (EC_POINT *)0x0;
      }
      else {
        iVar7 = 0;
        for (local_70 = (EC_POINT *)0x0; local_70 != pEVar9; local_70 = local_70 + 1) {
          if (local_70 < param_4) {
            pEVar14 = (EC_POINT *)
                      EC_POINT_copy((EC_POINT *)**(undefined4 **)(local_6c + iVar7),
                                    *(EC_POINT **)((int)param_5 + iVar7));
          }
          else {
            pEVar14 = (EC_POINT *)
                      EC_POINT_copy((EC_POINT *)**(undefined4 **)(local_6c + iVar7),local_54);
          }
          if (pEVar14 == (EC_POINT *)0x0) goto LAB_001450c4;
          if (1 < *(uint *)(local_74 + iVar7)) {
            pEVar14 = (EC_POINT *)
                      EC_POINT_dbl(param_1,pEVar10,(EC_POINT *)**(undefined4 **)(local_6c + iVar7),
                                   param_7);
            if (pEVar14 == (EC_POINT *)0x0) goto LAB_001450c4;
            if (1 < (uint)(1 << (*(int *)(local_74 + iVar7) - 1U & 0xff))) {
              uVar3 = 1;
              do {
                iVar16 = uVar3 - 1;
                iVar4 = uVar3 * 4;
                uVar3 = uVar3 + 1;
                pEVar14 = (EC_POINT *)
                          EC_POINT_add(param_1,*(EC_POINT **)(*(int *)(local_6c + iVar7) + iVar4),
                                       *(EC_POINT **)(*(int *)(local_6c + iVar7) + iVar16 * 4),
                                       pEVar10,param_7);
                if (pEVar14 == (EC_POINT *)0x0) goto LAB_001450c4;
              } while (uVar3 < (uint)(1 << (*(int *)(local_74 + iVar7) - 1U & 0xff)));
            }
          }
          iVar7 = iVar7 + 4;
        }
        pEVar14 = (EC_POINT *)
                  EC_POINTs_make_affine(param_1,(size_t)pEVar13,(EC_POINT **)pEVar11,param_7);
        if (pEVar14 != (EC_POINT *)0x0) {
          pEVar14 = (EC_POINT *)0x1;
          local_7c = (EC_POINT *)0x0;
          while (local_40 = local_40 + -1, -1 < (int)local_40) {
            if ((pEVar14 == (EC_POINT *)0x0) &&
               (iVar7 = EC_POINT_dbl(param_1,param_2,param_2,param_7), iVar7 == 0))
            goto LAB_001450c4;
            if (local_60 != (EC_POINT *)0x0) {
              pEVar13 = (EC_POINT *)0x0;
              do {
                if ((local_40 < *(EC_POINT **)(local_64 + (int)pEVar13 * 4)) &&
                   (iVar7 = (int)(char)local_40[*(int *)(pEVar8 + (int)pEVar13 * 4)], iVar7 != 0)) {
                  iVar4 = iVar7 >> 0x1f;
                  if (iVar7 < 0) {
                    iVar7 = -iVar7;
                  }
                  if (-(int)local_7c != iVar4) {
                    if ((pEVar14 == (EC_POINT *)0x0) &&
                       (iVar4 = EC_POINT_invert(param_1,param_2,param_7), iVar4 == 0))
                    goto LAB_001450c4;
                    local_7c = (EC_POINT *)((uint)local_7c ^ 1);
                  }
                  if (pEVar14 == (EC_POINT *)0x0) {
                    iVar7 = EC_POINT_add(param_1,param_2,param_2,
                                         *(EC_POINT **)
                                          (*(int *)(local_6c + (int)pEVar13 * 4) + (iVar7 >> 1) * 4)
                                         ,param_7);
                    if (iVar7 == 0) goto LAB_001450c4;
                  }
                  else {
                    iVar7 = EC_POINT_copy(param_2,*(EC_POINT **)
                                                   (*(int *)(local_6c + (int)pEVar13 * 4) +
                                                   (iVar7 >> 1) * 4));
                    if (iVar7 == 0) {
                      pEVar14 = (EC_POINT *)0x0;
                      goto LAB_001450c4;
                    }
                    pEVar14 = (EC_POINT *)0x0;
                  }
                }
                pEVar13 = pEVar13 + 1;
              } while (pEVar13 != local_60);
            }
          }
          if (pEVar14 == (EC_POINT *)0x0) {
            if (local_7c == (EC_POINT *)0x0) {
              pEVar14 = (EC_POINT *)0x1;
            }
            else {
              pEVar14 = (EC_POINT *)EC_POINT_invert(param_1,param_2,param_7);
              if (pEVar14 != (EC_POINT *)0x0) {
                pEVar14 = (EC_POINT *)0x1;
              }
            }
          }
          else {
            pEVar14 = (EC_POINT *)EC_POINT_set_to_infinity(param_1,param_2);
            if (pEVar14 != (EC_POINT *)0x0) {
              pEVar14 = (EC_POINT *)0x1;
            }
          }
        }
      }
    }
    else {
      ERR_put_error(0x10,0xbb,0x44,"ec_mult.c",0x256);
      pEVar14 = (EC_POINT *)0x0;
      pEVar10 = (EC_POINT *)0x0;
    }
  }
LAB_001450c4:
  if (local_5c != (BN_CTX *)0x0) {
    BN_CTX_free(local_5c);
  }
  if (pEVar10 != (EC_POINT *)0x0) {
    EC_POINT_free(pEVar10);
  }
  if (local_74 != (EC_POINT *)0x0) {
    CRYPTO_free(local_74);
  }
  if (local_64 != (EC_POINT *)0x0) {
    CRYPTO_free(local_64);
  }
  if (pEVar8 != (EC_POINT *)0x0) {
    pEVar13 = *(EC_POINT **)pEVar8;
    pEVar10 = pEVar8;
    while (pEVar13 != (EC_POINT *)0x0) {
      CRYPTO_free(pEVar13);
      pEVar10 = pEVar10 + 4;
      pEVar13 = *(EC_POINT **)pEVar10;
    }
    CRYPTO_free(pEVar8);
  }
  if (pEVar11 != (EC_POINT *)0x0) {
    pEVar10 = *(EC_POINT **)pEVar11;
    pEVar8 = pEVar11;
    while (pEVar10 != (EC_POINT *)0x0) {
      EC_POINT_clear_free(pEVar10);
      pEVar8 = pEVar8 + 4;
      pEVar10 = *(EC_POINT **)pEVar8;
    }
    CRYPTO_free(pEVar11);
  }
  if (local_6c != (EC_POINT *)0x0) {
    CRYPTO_free(local_6c);
  }
  return pEVar14;
}

