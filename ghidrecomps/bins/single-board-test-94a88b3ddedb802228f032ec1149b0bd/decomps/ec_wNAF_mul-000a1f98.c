
EC_POINT **
ec_wNAF_mul(int *param_1,int *param_2,BIGNUM *param_3,EC_POINT *param_4,int **param_5,int param_6,
           BN_CTX *param_7)

{
  int **ppiVar1;
  char *file;
  EC_POINT **ppEVar2;
  BIGNUM *pBVar3;
  uint uVar4;
  void *__dest;
  EC_POINT **ppEVar5;
  EC_POINT **ppEVar6;
  int iVar7;
  undefined4 uVar8;
  EC_POINT *pEVar9;
  EC_POINT *pEVar10;
  int iVar11;
  EC_POINT *pEVar12;
  EC_POINT *pEVar13;
  EC_POINT *pEVar14;
  EC_POINT **ppEVar15;
  int *piVar16;
  EC_POINT *pEVar17;
  int iVar18;
  EC_POINT **local_7c;
  EC_POINT **local_74;
  EC_POINT *local_70;
  EC_POINT **local_6c;
  EC_POINT **local_64;
  EC_POINT *local_60;
  BN_CTX *local_5c;
  uint local_58;
  EC_POINT *local_54;
  int local_50;
  int local_4c;
  EC_POINT *local_48;
  EC_POINT *local_40;
  EC_POINT *local_2c [2];
  
  if (*param_1 != *param_2) {
    iVar11 = 0x168;
LAB_000a1fb4:
    ERR_put_error(0x10,0xbb,0x65,DAT_000a2254,iVar11);
    return (EC_POINT **)0x0;
  }
  if (param_4 == (EC_POINT *)0x0 && param_3 == (BIGNUM *)0x0) {
    ppEVar2 = (EC_POINT **)EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2);
    return ppEVar2;
  }
  pEVar12 = (EC_POINT *)0x0;
  if (param_4 != (EC_POINT *)0x0) {
    iVar11 = **param_5;
    ppiVar1 = param_5;
    while (*param_1 == iVar11) {
      pEVar12 = pEVar12 + 1;
      if (pEVar12 == param_4) goto LAB_000a2002;
      ppiVar1 = ppiVar1 + 1;
      iVar11 = **ppiVar1;
    }
    iVar11 = 0x172;
    goto LAB_000a1fb4;
  }
LAB_000a2002:
  if (param_7 == (BN_CTX *)0x0) {
    param_7 = BN_CTX_new();
    local_5c = param_7;
    if (param_7 == (BN_CTX *)0x0) {
      return (EC_POINT **)0x0;
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
    local_54 = EC_GROUP_get0_generator((EC_GROUP *)param_1);
    if (local_54 == (EC_POINT *)0x0) {
      iVar11 = 0x71;
      iVar7 = 0x180;
LAB_000a22cc:
      ppEVar15 = (EC_POINT **)0x0;
      ERR_put_error(0x10,0xbb,iVar11,DAT_000a255c,iVar7);
      ppEVar2 = ppEVar15;
      ppEVar6 = ppEVar15;
      ppEVar5 = ppEVar15;
      local_74 = ppEVar15;
      local_6c = ppEVar15;
      local_64 = ppEVar15;
      goto LAB_000a2188;
    }
    local_70 = (EC_POINT *)EC_EX_DATA_get_data(param_1[0x11],DAT_000a2258,DAT_000a225c,DAT_000a2260)
    ;
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
      iVar11 = EC_POINT_cmp((EC_GROUP *)param_1,local_54,**(EC_POINT ***)((int)local_70 + 0x10),
                            param_7);
      if (iVar11 == 0) {
        local_48 = *(EC_POINT **)((int)local_70 + 4);
        iVar11 = BN_num_bits(param_3);
        uVar4 = *(uint *)((int)local_70 + 8);
        local_4c = 1 << (*(int *)((int)local_70 + 0xc) - 1U & 0xff);
        if (*(int *)((int)local_70 + 0x14) != uVar4 * local_4c) {
          iVar7 = 0x19f;
          iVar11 = 0x44;
          goto LAB_000a22cc;
        }
        iVar11 = __aeabi_uidiv(iVar11,local_48);
        local_58 = iVar11 + 1U;
        if (uVar4 <= iVar11 + 1U) {
          local_58 = uVar4;
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
  iVar11 = (int)local_60 * 4;
  local_74 = (EC_POINT **)CRYPTO_malloc(iVar11,DAT_000a2254,0x1ad);
  local_64 = (EC_POINT **)CRYPTO_malloc(iVar11,DAT_000a2254,0x1ae);
  ppEVar2 = (EC_POINT **)CRYPTO_malloc((int)(local_60 + 1) * 4,DAT_000a2254,0x1af);
  local_6c = (EC_POINT **)CRYPTO_malloc(iVar11,DAT_000a2254,0x1b1);
  if (ppEVar2 != (EC_POINT **)0x0) {
    *ppEVar2 = (EC_POINT *)0x0;
  }
  if ((local_74 == (EC_POINT **)0x0 || local_64 == (EC_POINT **)0x0) ||
     (ppEVar2 == (EC_POINT **)0x0 || local_6c == (EC_POINT **)0x0)) {
    ppEVar15 = (EC_POINT **)0x0;
    ERR_put_error(0x10,0xbb,0x41,DAT_000a2254,0x1b8);
    ppEVar6 = (EC_POINT **)0x0;
    ppEVar5 = (EC_POINT **)0x0;
    goto LAB_000a2188;
  }
  pEVar14 = (EC_POINT *)0x0;
  pEVar13 = param_4 + local_50;
  pEVar12 = pEVar14;
  local_40 = pEVar14;
  ppEVar15 = local_64;
  pEVar9 = pEVar14;
  while (pEVar9 != pEVar13) {
    pBVar3 = param_3;
    if (pEVar9 < param_4) {
      pBVar3 = *(BIGNUM **)(pEVar14 + param_6);
    }
    uVar4 = BN_num_bits(pBVar3);
    if (uVar4 < 2000) {
      if (uVar4 < 800) {
        if (uVar4 < 300) {
          if (uVar4 < 0x46) {
            if (uVar4 < 0x14) {
              uVar8 = 1;
              iVar11 = 1;
            }
            else {
              uVar8 = 2;
              iVar11 = 2;
            }
          }
          else {
            uVar8 = 3;
            iVar11 = 4;
          }
        }
        else {
          uVar8 = 4;
          iVar11 = 8;
        }
      }
      else {
        uVar8 = 5;
        iVar11 = 0x10;
      }
    }
    else {
      uVar8 = 6;
      iVar11 = 0x20;
    }
    pEVar12 = pEVar12 + iVar11;
    if (pEVar9 < param_4) {
      iVar11 = param_6;
    }
    pEVar17 = pEVar9 + 1;
    *(undefined4 *)((int)local_74 + (int)pEVar14) = uVar8;
    *(undefined4 *)((EC_POINT *)((int)ppEVar2 + (int)pEVar14) + 4) = 0;
    pBVar3 = param_3;
    if (pEVar9 < param_4) {
      pBVar3 = *(BIGNUM **)(pEVar14 + iVar11);
    }
    iVar11 = compute_wNAF(pBVar3,uVar8,ppEVar15);
    ppEVar6 = ppEVar15 + 1;
    *(int *)((int)ppEVar2 + (int)pEVar14) = iVar11;
    if (iVar11 == 0) {
      ppEVar15 = (EC_POINT **)0x0;
      ppEVar6 = (EC_POINT **)0x0;
      ppEVar5 = (EC_POINT **)0x0;
      goto LAB_000a2188;
    }
    pEVar10 = *ppEVar15;
    pEVar14 = pEVar14 + 4;
    ppEVar15 = ppEVar6;
    pEVar9 = pEVar17;
    if (local_40 < pEVar10) {
      local_40 = pEVar10;
    }
  }
  if (local_58 != 0) {
    if (local_70 != (EC_POINT *)0x0) {
      local_2c[0] = (EC_POINT *)0x0;
      if (local_50 == 0) {
        iVar11 = (int)param_4 * 4;
        pEVar9 = *(EC_POINT **)((int)local_70 + 0xc);
        local_74[(int)param_4] = pEVar9;
        pEVar9 = (EC_POINT *)compute_wNAF(param_3,pEVar9,local_2c);
        if (pEVar9 != (EC_POINT *)0x0) {
          if (local_40 < local_2c[0]) {
            if (local_2c[0] < (EC_POINT *)((int)local_48 * local_58)) {
              uVar4 = __aeabi_uidiv(local_2c[0] + -1 + (int)local_48);
              if (*(uint *)((int)local_70 + 8) < uVar4) {
                iVar11 = 0x20c;
                goto LAB_000a228c;
              }
              local_60 = param_4 + uVar4;
            }
            piVar16 = *(int **)((int)local_70 + 0x10);
            if (param_4 < local_60) {
              local_7c = ppEVar2 + (int)param_4;
              pEVar14 = pEVar9;
              pEVar17 = param_4;
              do {
                ppEVar15 = (EC_POINT **)((int)local_64 + iVar11);
                if (pEVar17 < local_60 + -1) {
                  *(EC_POINT **)((int)local_64 + iVar11) = local_48;
                  pEVar10 = local_2c[0] + -(int)local_48;
                  if (local_2c[0] < local_48) {
                    iVar11 = 0x21a;
                    goto LAB_000a228c;
                  }
                }
                else {
                  *(EC_POINT **)((int)local_64 + iVar11) = local_2c[0];
                  pEVar10 = local_2c[0];
                }
                local_2c[0] = pEVar10;
                file = DAT_000a255c;
                pEVar17 = pEVar17 + 1;
                local_7c = local_7c + 1;
                *local_7c = (EC_POINT *)0x0;
                HintPreloadData(piVar16 + local_4c * 4);
                __dest = CRYPTO_malloc((int)*ppEVar15,file,0x226);
                *(void **)((int)ppEVar2 + iVar11) = __dest;
                if (__dest == (void *)0x0) {
                  ERR_put_error(0x10,0xbb,0x41,DAT_000a27f0,0x228);
                  CRYPTO_free(pEVar9);
                  goto LAB_000a229a;
                }
                memcpy(__dest,pEVar14,(size_t)*ppEVar15);
                if (local_40 < *ppEVar15) {
                  local_40 = *ppEVar15;
                }
                if (*piVar16 == 0) {
                  ERR_put_error(0x10,0xbb,0x44,DAT_000a27f0,0x231);
                  CRYPTO_free(pEVar9);
                  goto LAB_000a229a;
                }
                *(int **)((int)local_6c + iVar11) = piVar16;
                iVar11 = iVar11 + 4;
                piVar16 = piVar16 + local_4c;
                pEVar14 = pEVar14 + (int)local_48;
              } while (pEVar17 < local_60);
            }
            CRYPTO_free(pEVar9);
          }
          else {
            local_60 = param_4 + 1;
            ppEVar2[(int)param_4] = pEVar9;
            ppEVar2[(int)local_60] = (EC_POINT *)0x0;
            pEVar9 = *(EC_POINT **)((int)local_70 + 0x10);
            local_64[(int)param_4] = local_2c[0];
            local_6c[(int)param_4] = pEVar9;
            if (local_40 < local_2c[0]) {
              local_40 = local_2c[0];
            }
          }
          goto LAB_000a235c;
        }
      }
      else {
        iVar11 = 0x1df;
LAB_000a228c:
        ERR_put_error(0x10,0xbb,0x44,DAT_000a255c,iVar11);
      }
LAB_000a229a:
      ppEVar15 = (EC_POINT **)0x0;
      ppEVar6 = (EC_POINT **)0x0;
      ppEVar5 = (EC_POINT **)0x0;
      goto LAB_000a2188;
    }
    if (local_50 != 1) {
      ERR_put_error(0x10,0xbb,0x44,DAT_000a27f0,0x1d6);
      ppEVar15 = (EC_POINT **)0x0;
      ppEVar6 = (EC_POINT **)0x0;
      ppEVar5 = (EC_POINT **)0x0;
      goto LAB_000a2188;
    }
  }
LAB_000a235c:
  ppEVar15 = (EC_POINT **)CRYPTO_malloc((int)(pEVar12 + 1) * 4,DAT_000a255c,0x243);
  if (ppEVar15 == (EC_POINT **)0x0) {
    ERR_put_error(0x10,0xbb,0x41,DAT_000a27f0,0x245);
    ppEVar6 = (EC_POINT **)0x0;
    ppEVar5 = (EC_POINT **)0x0;
  }
  else {
    ppEVar15[(int)pEVar12] = (EC_POINT *)0x0;
    ppEVar6 = ppEVar15;
    if (pEVar13 != (EC_POINT *)0x0) {
      pEVar9 = (EC_POINT *)0x0;
      do {
        pEVar14 = local_74[(int)pEVar9];
        local_6c[(int)pEVar9] = (EC_POINT *)ppEVar6;
        if (1 << ((uint)(pEVar14 + -1) & 0xff) != 0) {
          uVar4 = 0;
          ppEVar5 = ppEVar6;
          do {
            uVar4 = uVar4 + 1;
            pEVar14 = EC_POINT_new((EC_GROUP *)param_1);
            ppEVar6 = ppEVar5 + 1;
            *ppEVar5 = pEVar14;
            if (pEVar14 == (EC_POINT *)0x0) {
              ppEVar6 = (EC_POINT **)0x0;
              ppEVar5 = (EC_POINT **)0x0;
              goto LAB_000a2188;
            }
            ppEVar5 = ppEVar6;
          } while (uVar4 < (uint)(1 << ((uint)(local_74[(int)pEVar9] + -1) & 0xff)));
        }
        pEVar9 = pEVar9 + 1;
      } while (pEVar13 != pEVar9);
    }
    if (ppEVar6 == ppEVar15 + (int)pEVar12) {
      ppEVar5 = (EC_POINT **)EC_POINT_new((EC_GROUP *)param_1);
      if (ppEVar5 == (EC_POINT **)0x0) {
        ppEVar6 = (EC_POINT **)0x0;
      }
      else {
        iVar11 = 0;
        for (local_70 = (EC_POINT *)0x0; local_70 != pEVar13; local_70 = local_70 + 1) {
          if (local_70 < param_4) {
            ppEVar6 = (EC_POINT **)
                      EC_POINT_copy(**(EC_POINT ***)((int)local_6c + iVar11),
                                    *(EC_POINT **)((int)param_5 + iVar11));
          }
          else {
            ppEVar6 = (EC_POINT **)EC_POINT_copy(**(EC_POINT ***)((int)local_6c + iVar11),local_54);
          }
          if (ppEVar6 == (EC_POINT **)0x0) goto LAB_000a2188;
          if (1 < *(uint *)((int)local_74 + iVar11)) {
            ppEVar6 = (EC_POINT **)
                      EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)ppEVar5,
                                   **(EC_POINT ***)((int)local_6c + iVar11),param_7);
            if (ppEVar6 == (EC_POINT **)0x0) goto LAB_000a2188;
            if (1 < (uint)(1 << (*(int *)((int)local_74 + iVar11) - 1U & 0xff))) {
              uVar4 = 1;
              do {
                iVar18 = uVar4 - 1;
                iVar7 = uVar4 * 4;
                uVar4 = uVar4 + 1;
                ppEVar6 = (EC_POINT **)
                          EC_POINT_add((EC_GROUP *)param_1,
                                       *(EC_POINT **)(*(int *)((int)local_6c + iVar11) + iVar7),
                                       *(EC_POINT **)(*(int *)((int)local_6c + iVar11) + iVar18 * 4)
                                       ,(EC_POINT *)ppEVar5,param_7);
                if (ppEVar6 == (EC_POINT **)0x0) goto LAB_000a2188;
              } while (uVar4 < (uint)(1 << (*(int *)((int)local_74 + iVar11) - 1U & 0xff)));
            }
          }
          iVar11 = iVar11 + 4;
        }
        ppEVar6 = (EC_POINT **)
                  EC_POINTs_make_affine((EC_GROUP *)param_1,(size_t)pEVar12,ppEVar15,param_7);
        if (ppEVar6 != (EC_POINT **)0x0) {
          ppEVar6 = (EC_POINT **)0x1;
          local_7c = (EC_POINT **)0x0;
          while (local_40 = local_40 + -1, -1 < (int)local_40) {
            if ((ppEVar6 == (EC_POINT **)0x0) &&
               (iVar11 = EC_POINT_dbl((EC_GROUP *)param_1,(EC_POINT *)param_2,(EC_POINT *)param_2,
                                      param_7), iVar11 == 0)) goto LAB_000a2188;
            if (local_60 != (EC_POINT *)0x0) {
              pEVar12 = (EC_POINT *)0x0;
              do {
                if ((local_40 < local_64[(int)pEVar12]) &&
                   (iVar11 = (int)(char)ppEVar2[(int)pEVar12][(int)local_40], iVar11 != 0)) {
                  iVar7 = iVar11 >> 0x1f;
                  if (iVar11 < 0) {
                    iVar11 = -iVar11;
                  }
                  if (-(int)local_7c != iVar7) {
                    if ((ppEVar6 == (EC_POINT **)0x0) &&
                       (iVar7 = EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,param_7),
                       iVar7 == 0)) goto LAB_000a2188;
                    local_7c = (EC_POINT **)((uint)local_7c ^ 1);
                  }
                  if (ppEVar6 == (EC_POINT **)0x0) {
                    iVar11 = EC_POINT_add((EC_GROUP *)param_1,(EC_POINT *)param_2,
                                          (EC_POINT *)param_2,
                                          *(EC_POINT **)(local_6c[(int)pEVar12] + (iVar11 >> 1) * 4)
                                          ,param_7);
                    if (iVar11 == 0) goto LAB_000a2188;
                  }
                  else {
                    iVar11 = EC_POINT_copy((EC_POINT *)param_2,
                                           *(EC_POINT **)
                                            (local_6c[(int)pEVar12] + (iVar11 >> 1) * 4));
                    if (iVar11 == 0) {
                      ppEVar6 = (EC_POINT **)0x0;
                      goto LAB_000a2188;
                    }
                    ppEVar6 = (EC_POINT **)0x0;
                  }
                }
                pEVar12 = pEVar12 + 1;
              } while (pEVar12 != local_60);
            }
          }
          if (ppEVar6 == (EC_POINT **)0x0) {
            if (local_7c == (EC_POINT **)0x0) {
              ppEVar6 = (EC_POINT **)0x1;
            }
            else {
              ppEVar6 = (EC_POINT **)
                        EC_POINT_invert((EC_GROUP *)param_1,(EC_POINT *)param_2,param_7);
              if (ppEVar6 != (EC_POINT **)0x0) {
                ppEVar6 = (EC_POINT **)0x1;
              }
            }
          }
          else {
            ppEVar6 = (EC_POINT **)EC_POINT_set_to_infinity((EC_GROUP *)param_1,(EC_POINT *)param_2)
            ;
            if (ppEVar6 != (EC_POINT **)0x0) {
              ppEVar6 = (EC_POINT **)0x1;
            }
          }
        }
      }
    }
    else {
      ERR_put_error(0x10,0xbb,0x44,DAT_000a255c,0x256);
      ppEVar6 = (EC_POINT **)0x0;
      ppEVar5 = (EC_POINT **)0x0;
    }
  }
LAB_000a2188:
  if (local_5c != (BN_CTX *)0x0) {
    BN_CTX_free(local_5c);
  }
  if (ppEVar5 != (EC_POINT **)0x0) {
    EC_POINT_free((EC_POINT *)ppEVar5);
  }
  if (local_74 != (EC_POINT **)0x0) {
    CRYPTO_free(local_74);
  }
  if (local_64 != (EC_POINT **)0x0) {
    CRYPTO_free(local_64);
  }
  if (ppEVar2 != (EC_POINT **)0x0) {
    pEVar12 = *ppEVar2;
    ppEVar5 = ppEVar2;
    while (pEVar12 != (EC_POINT *)0x0) {
      CRYPTO_free(pEVar12);
      ppEVar5 = ppEVar5 + 1;
      pEVar12 = *ppEVar5;
    }
    CRYPTO_free(ppEVar2);
  }
  if (ppEVar15 != (EC_POINT **)0x0) {
    pEVar12 = *ppEVar15;
    ppEVar2 = ppEVar15;
    while (pEVar12 != (EC_POINT *)0x0) {
      EC_POINT_clear_free(pEVar12);
      ppEVar2 = ppEVar2 + 1;
      pEVar12 = *ppEVar2;
    }
    CRYPTO_free(ppEVar15);
  }
  if (local_6c != (EC_POINT **)0x0) {
    CRYPTO_free(local_6c);
  }
  return ppEVar6;
}

