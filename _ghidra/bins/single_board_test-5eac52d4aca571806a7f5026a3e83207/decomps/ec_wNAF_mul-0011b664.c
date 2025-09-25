
int ec_wNAF_mul(EC_GROUP *param_1,EC_POINT *param_2,BIGNUM *param_3,uint param_4,undefined4 *param_5
               ,undefined4 *param_6,BN_CTX *param_7)

{
  undefined4 *puVar1;
  int iVar2;
  uint *ptr;
  uint *ptr_00;
  int *ptr_01;
  uint uVar3;
  void *__dest;
  int iVar4;
  EC_POINT **ppEVar5;
  BIGNUM *pBVar6;
  uint uVar7;
  void *pvVar8;
  uint uVar9;
  int *piVar10;
  uint *puVar11;
  EC_POINT **points;
  int *piVar12;
  int *piVar13;
  uint *puVar14;
  EC_POINT **ppEVar15;
  EC_POINT *pEVar16;
  void *__src;
  uint uVar17;
  uint uVar18;
  int *piVar19;
  int *local_64;
  int local_60;
  uint local_54;
  EC_POINT *local_50;
  uint local_4c;
  int local_44;
  uint local_40;
  int local_3c;
  size_t local_38;
  uint local_2c [2];
  
  iVar2 = BN_is_zero(*(undefined4 *)(param_1 + 8));
  if ((iVar2 == 0) && (iVar2 = BN_is_zero(*(undefined4 *)(param_1 + 0xc)), iVar2 == 0)) {
    if (*(BIGNUM **)(param_1 + 8) != param_3) {
      pBVar6 = param_3;
      if (param_3 != (BIGNUM *)0x0) {
        pBVar6 = (BIGNUM *)0x1;
      }
      if (param_4 != 0) {
        pBVar6 = (BIGNUM *)0x0;
      }
      if (pBVar6 != (BIGNUM *)0x0) {
        iVar2 = ec_scalar_mul_ladder(param_1,param_2,param_3,0,param_7);
        return iVar2;
      }
    }
    if (param_3 != (BIGNUM *)0x0 || param_4 != 1) goto LAB_0011b67e;
    if (*(BIGNUM **)(param_1 + 8) != (BIGNUM *)*param_6) {
      iVar2 = ec_scalar_mul_ladder(param_1,param_2,(BIGNUM *)*param_6,*param_5,param_7);
      return iVar2;
    }
LAB_0011ba54:
    local_44 = 0;
    local_60 = 0;
    local_3c = 0;
    local_54 = 0;
    local_40 = 0;
    local_50 = (EC_POINT *)0x0;
  }
  else {
LAB_0011b67e:
    if (param_3 == (BIGNUM *)0x0) goto LAB_0011ba54;
    local_50 = EC_GROUP_get0_generator(param_1);
    if (local_50 == (EC_POINT *)0x0) {
      ERR_put_error(0x10,0xbb,0x71,"crypto/ec/ec_mult.c",0x1cf);
LAB_0011bb28:
      EC_POINT_free((EC_POINT *)0x0);
      iVar2 = 0;
      CRYPTO_free((void *)0x0);
      local_64 = (int *)0x0;
      CRYPTO_free((void *)0x0);
      goto LAB_0011b99e;
    }
    local_60 = *(int *)(param_1 + 100);
    if (local_60 == 0) {
      local_44 = 1;
      local_54 = 1;
      local_40 = 0;
      local_3c = 0;
    }
    else if (*(int *)(local_60 + 8) == 0) {
      local_44 = 1;
      local_54 = 1;
      local_60 = 0;
      local_40 = 0;
      local_3c = 0;
    }
    else {
      iVar2 = EC_POINT_cmp(param_1,local_50,(EC_POINT *)**(undefined4 **)(local_60 + 0x10),param_7);
      if (iVar2 == 0) {
        local_40 = *(uint *)(local_60 + 4);
        iVar2 = BN_num_bits(param_3);
        uVar9 = *(uint *)(local_60 + 8);
        local_3c = 1 << (*(int *)(local_60 + 0xc) - 1U & 0xff);
        if (*(int *)(local_60 + 0x14) != local_3c * uVar9) {
          ERR_put_error(0x10,0xbb,0x44,"crypto/ec/ec_mult.c",0x1eb);
          goto LAB_0011bb28;
        }
        iVar2 = __aeabi_uidiv(iVar2,local_40);
        local_54 = iVar2 + 1U;
        if (uVar9 <= iVar2 + 1U) {
          local_54 = uVar9;
        }
        local_44 = 0;
      }
      else {
        local_60 = 0;
        local_3c = 0;
        local_40 = 0;
        local_44 = 1;
        local_54 = 1;
      }
    }
  }
  local_4c = local_54 + param_4;
  iVar2 = local_4c * 4;
  ptr = (uint *)CRYPTO_malloc(iVar2,"crypto/ec/ec_mult.c",0x1f9);
  ptr_00 = (uint *)CRYPTO_malloc(iVar2,"crypto/ec/ec_mult.c",0x1fa);
  ptr_01 = (int *)CRYPTO_malloc(iVar2 + 4,"crypto/ec/ec_mult.c",0x1fc);
  local_64 = (int *)CRYPTO_malloc(iVar2,"crypto/ec/ec_mult.c",0x1fd);
  if (ptr_01 == (int *)0x0) {
    if (ptr == (uint *)0x0 || ptr_00 == (uint *)0x0) {
      ERR_put_error(0x10,0xbb,0x41,"crypto/ec/ec_mult.c",0x204);
    }
    else {
      ERR_put_error(0x10,0xbb,0x41,"crypto/ec/ec_mult.c",0x204);
    }
    iVar2 = 0;
    EC_POINT_free((EC_POINT *)0x0);
    CRYPTO_free(ptr);
    CRYPTO_free(ptr_00);
    goto LAB_0011b99e;
  }
  *ptr_01 = 0;
  piVar10 = ptr_01;
  if (ptr_00 == (uint *)0x0 || ptr == (uint *)0x0) {
    ERR_put_error(0x10,0xbb,0x41,"crypto/ec/ec_mult.c",0x204);
  }
  else {
    local_38 = 0;
    if (local_64 != (int *)0x0) {
      uVar9 = param_4 + local_44;
      if (uVar9 == 0) {
        uVar17 = 0;
        local_38 = 0;
      }
      else {
        puVar14 = ptr + -1;
        piVar13 = ptr_01;
        puVar11 = ptr_00;
        uVar17 = local_38;
        uVar18 = local_38;
        do {
          if (uVar18 < param_4) {
            uVar3 = BN_num_bits((BIGNUM *)*param_6);
            if (uVar3 < 2000) {
LAB_0011b75e:
              if (uVar3 < 800) {
                if (uVar3 < 300) {
                  if (uVar3 < 0x46) {
                    if (uVar3 < 0x14) {
                      uVar3 = 1;
                      uVar7 = uVar3;
                    }
                    else {
                      uVar3 = 2;
                      uVar7 = 2;
                    }
                  }
                  else {
                    uVar3 = 3;
                    uVar7 = 4;
                  }
                }
                else {
                  uVar3 = 4;
                  uVar7 = 8;
                }
              }
              else {
                uVar3 = 5;
                uVar7 = 0x10;
              }
              puVar14[1] = uVar3;
              local_38 = local_38 + uVar7;
              piVar13[1] = 0;
              if (param_4 <= uVar18) goto LAB_0011b7f0;
            }
            else {
              uVar3 = 6;
              puVar14[1] = 6;
              local_38 = local_38 + 0x20;
              piVar13[1] = 0;
            }
            iVar2 = bn_compute_wNAF(*param_6,uVar3,puVar11);
            *piVar13 = iVar2;
          }
          else {
            uVar3 = BN_num_bits(param_3);
            if (uVar3 < 2000) goto LAB_0011b75e;
            local_38 = local_38 + 0x20;
            uVar3 = 6;
            puVar14[1] = 6;
            piVar13[1] = 0;
LAB_0011b7f0:
            iVar2 = bn_compute_wNAF(param_3,uVar3,puVar11);
            *piVar13 = iVar2;
          }
          if (iVar2 == 0) goto LAB_0011b936;
          puVar14 = puVar14 + 1;
          piVar13 = piVar13 + 1;
          uVar18 = uVar18 + 1;
          param_6 = param_6 + 1;
          if (uVar17 < *puVar11) {
            uVar17 = *puVar11;
          }
          puVar11 = puVar11 + 1;
        } while (uVar18 != uVar9);
      }
      if (local_54 != 0) {
        if (local_60 != 0) {
          local_2c[0] = 0;
          if (local_44 == 0) {
            uVar18 = *(uint *)(local_60 + 0xc);
            ptr[param_4] = uVar18;
            pvVar8 = (void *)bn_compute_wNAF(param_3,uVar18,local_2c);
            if (pvVar8 != (void *)0x0) {
              if (uVar17 < local_2c[0]) {
                if (local_2c[0] < local_54 * local_40) {
                  local_4c = __aeabi_uidiv((local_2c[0] - 1) + local_40);
                  if (*(uint *)(local_60 + 8) < local_4c) {
                    ERR_put_error(0x10,0xbb,0x44,"crypto/ec/ec_mult.c",0x256);
                    CRYPTO_free(pvVar8);
                    goto LAB_0011b936;
                  }
                  local_4c = param_4 + local_4c;
                }
                piVar13 = *(int **)(local_60 + 0x10);
                if (param_4 < local_4c) {
                  puVar11 = ptr_00 + param_4;
                  uVar18 = param_4;
                  piVar12 = ptr_01 + param_4;
                  __src = pvVar8;
                  piVar19 = local_64 + param_4;
                  do {
                    if (uVar18 < local_4c - 1) {
                      *puVar11 = local_40;
                      if (local_2c[0] < local_40) {
                        ERR_put_error(0x10,0xbb,0x44,"crypto/ec/ec_mult.c",0x265);
                        CRYPTO_free(pvVar8);
                        goto LAB_0011b936;
                      }
                      uVar3 = *puVar11;
                      local_2c[0] = local_2c[0] - local_40;
                    }
                    else {
                      *puVar11 = local_2c[0];
                      uVar3 = local_2c[0];
                    }
                    piVar12[1] = 0;
                    __dest = CRYPTO_malloc(uVar3,"crypto/ec/ec_mult.c",0x272);
                    uVar18 = uVar18 + 1;
                    *piVar12 = (int)__dest;
                    if (__dest == (void *)0x0) {
                      ERR_put_error(0x10,0xbb,0x41,"crypto/ec/ec_mult.c",0x274);
                      CRYPTO_free(pvVar8);
                      goto LAB_0011b936;
                    }
                    memcpy(__dest,__src,*puVar11);
                    if (uVar17 < *puVar11) {
                      uVar17 = *puVar11;
                    }
                    if (*piVar13 == 0) {
                      ERR_put_error(0x10,0xbb,0x44,"crypto/ec/ec_mult.c",0x27d);
                      CRYPTO_free(pvVar8);
                      goto LAB_0011b936;
                    }
                    *piVar19 = (int)piVar13;
                    piVar13 = piVar13 + local_3c;
                    puVar11 = puVar11 + 1;
                    piVar12 = piVar12 + 1;
                    __src = (void *)((int)__src + local_40);
                    piVar19 = piVar19 + 1;
                  } while (local_4c != uVar18);
                }
                CRYPTO_free(pvVar8);
              }
              else {
                ptr_01[param_4] = (int)pvVar8;
                ptr_01[param_4 + 1] = 0;
                local_4c = param_4 + 1;
                iVar2 = *(int *)(local_60 + 0x10);
                ptr_00[param_4] = local_2c[0];
                local_64[param_4] = iVar2;
              }
              goto LAB_0011b87c;
            }
          }
          else {
            ERR_put_error(0x10,0xbb,0x44,"crypto/ec/ec_mult.c",0x22b);
          }
LAB_0011b936:
          iVar2 = 0;
          points = (EC_POINT **)0x0;
          pEVar16 = (EC_POINT *)0x0;
          goto LAB_0011b93e;
        }
        if (local_44 == 0) {
          ERR_put_error(0x10,0xbb,0x44,"crypto/ec/ec_mult.c",0x222);
          points = (EC_POINT **)0x0;
          iVar2 = 0;
          pEVar16 = (EC_POINT *)0x0;
          goto LAB_0011b93e;
        }
      }
LAB_0011b87c:
      points = (EC_POINT **)CRYPTO_malloc((local_38 + 1) * 4,"crypto/ec/ec_mult.c",0x28f);
      if (points == (EC_POINT **)0x0) {
        ERR_put_error(0x10,0xbb,0x41,"crypto/ec/ec_mult.c",0x291);
        iVar2 = 0;
        pEVar16 = (EC_POINT *)0x0;
      }
      else {
        points[local_38] = (EC_POINT *)0x0;
        ppEVar5 = points;
        if (uVar9 != 0) {
          uVar18 = 0;
          piVar13 = local_64 + -1;
          puVar11 = ptr;
          do {
            uVar3 = *puVar11;
            piVar13 = piVar13 + 1;
            *piVar13 = (int)ppEVar5;
            if (1 << (uVar3 - 1 & 0xff) != 0) {
              uVar3 = 0;
              ppEVar15 = ppEVar5;
              do {
                uVar3 = uVar3 + 1;
                pEVar16 = EC_POINT_new(param_1);
                ppEVar5 = ppEVar15 + 1;
                *ppEVar15 = pEVar16;
                if (pEVar16 == (EC_POINT *)0x0) {
                  iVar2 = 0;
                  pEVar16 = (EC_POINT *)0x0;
                  goto LAB_0011b93e;
                }
                ppEVar15 = ppEVar5;
              } while (uVar3 < (uint)(1 << (*puVar11 - 1 & 0xff)));
            }
            uVar18 = uVar18 + 1;
            puVar11 = puVar11 + 1;
          } while (uVar18 != uVar9);
        }
        if (points + local_38 == ppEVar5) {
          pEVar16 = EC_POINT_new(param_1);
          if (pEVar16 == (EC_POINT *)0x0) {
            iVar2 = 0;
          }
          else {
            if (uVar9 != 0) {
              uVar18 = 0;
              puVar11 = ptr;
              piVar13 = local_64;
              do {
                if (uVar18 < param_4) {
                  iVar2 = EC_POINT_copy(*(EC_POINT **)*piVar13,(EC_POINT *)param_5[uVar18]);
                }
                else {
                  iVar2 = EC_POINT_copy(*(EC_POINT **)*piVar13,local_50);
                }
                if (iVar2 == 0) goto LAB_0011b93e;
                if (1 < *puVar11) {
                  iVar2 = EC_POINT_dbl(param_1,pEVar16,*(EC_POINT **)*piVar13,param_7);
                  if (iVar2 == 0) goto LAB_0011b93e;
                  if (1 < (uint)(1 << (*puVar11 - 1 & 0xff))) {
                    iVar2 = 0;
                    uVar3 = 1;
                    do {
                      puVar1 = (undefined4 *)(*piVar13 + iVar2);
                      iVar2 = iVar2 + 4;
                      iVar4 = uVar3 * 4;
                      uVar3 = uVar3 + 1;
                      iVar4 = EC_POINT_add(param_1,*(EC_POINT **)(*piVar13 + iVar4),
                                           (EC_POINT *)*puVar1,pEVar16,param_7);
                      if (iVar4 == 0) {
                        iVar2 = 0;
                        goto LAB_0011b93e;
                      }
                    } while (uVar3 < (uint)(1 << (*puVar11 - 1 & 0xff)));
                  }
                }
                uVar18 = uVar18 + 1;
                piVar13 = piVar13 + 1;
                puVar11 = puVar11 + 1;
              } while (uVar18 != uVar9);
            }
            iVar2 = EC_POINTs_make_affine(param_1,local_38,points,param_7);
            if (iVar2 != 0) {
              iVar2 = 1;
              uVar9 = 0;
              while (uVar17 = uVar17 - 1, -1 < (int)uVar17) {
                if ((iVar2 == 0) &&
                   (iVar4 = EC_POINT_dbl(param_1,param_2,param_2,param_7), iVar4 == 0))
                goto LAB_0011b93e;
                if (local_4c != 0) {
                  uVar18 = 0;
                  puVar11 = ptr_00 + -1;
                  piVar13 = local_64;
                  do {
                    puVar11 = puVar11 + 1;
                    if ((uVar17 < *puVar11) &&
                       (uVar3 = (uint)*(char *)(ptr_01[uVar18] + uVar17), uVar3 != 0)) {
                      uVar7 = (int)uVar3 >> 0x1f;
                      if (uVar9 != -uVar7) {
                        if ((iVar2 == 0) &&
                           (iVar4 = EC_POINT_invert(param_1,param_2,param_7), iVar4 == 0))
                        goto LAB_0011b93e;
                        uVar9 = uVar9 ^ 1;
                      }
                      iVar4 = (int)((uVar3 ^ uVar7) - uVar7) >> 1;
                      if (iVar2 == 0) {
                        iVar4 = EC_POINT_add(param_1,param_2,param_2,
                                             *(EC_POINT **)(*piVar13 + iVar4 * 4),param_7);
                        if (iVar4 == 0) goto LAB_0011b93e;
                      }
                      else {
                        iVar2 = EC_POINT_copy(param_2,*(EC_POINT **)(*piVar13 + iVar4 * 4));
                        if (iVar2 == 0) {
                          iVar2 = 0;
                          goto LAB_0011b93e;
                        }
                        iVar2 = ec_point_blind_coordinates(param_1,param_2,param_7);
                        if (iVar2 == 0) {
                          ERR_put_error(0x10,0xbb,0xa3,"crypto/ec/ec_mult.c",0x2f1);
                          iVar2 = 0;
                          goto LAB_0011b93e;
                        }
                        iVar2 = 0;
                      }
                    }
                    uVar18 = uVar18 + 1;
                    piVar13 = piVar13 + 1;
                  } while (local_4c != uVar18);
                }
              }
              if (iVar2 == 0) {
                if (uVar9 == 0) {
                  iVar2 = 1;
                }
                else {
                  iVar2 = EC_POINT_invert(param_1,param_2,param_7);
                  if (iVar2 != 0) {
                    iVar2 = 1;
                  }
                }
              }
              else {
                iVar2 = EC_POINT_set_to_infinity(param_1,param_2);
                if (iVar2 != 0) {
                  iVar2 = 1;
                }
              }
            }
          }
        }
        else {
          iVar2 = 0;
          ERR_put_error(0x10,0xbb,0x44,"crypto/ec/ec_mult.c",0x2a2);
          pEVar16 = (EC_POINT *)0x0;
        }
      }
LAB_0011b93e:
      EC_POINT_free(pEVar16);
      CRYPTO_free(ptr);
      CRYPTO_free(ptr_00);
      pvVar8 = (void *)*ptr_01;
      goto joined_r0x0011b968;
    }
    ERR_put_error(0x10,0xbb,0x41,"crypto/ec/ec_mult.c",0x204);
  }
  EC_POINT_free((EC_POINT *)0x0);
  CRYPTO_free(ptr);
  points = (EC_POINT **)0x0;
  CRYPTO_free(ptr_00);
  iVar2 = 0;
  pvVar8 = (void *)*ptr_01;
  if (pvVar8 == (void *)0x0) {
    CRYPTO_free(ptr_01);
    iVar2 = 0;
  }
  else {
    do {
      CRYPTO_free(pvVar8);
      piVar10 = piVar10 + 1;
      pvVar8 = (void *)*piVar10;
joined_r0x0011b968:
    } while (pvVar8 != (void *)0x0);
    CRYPTO_free(ptr_01);
    if (points != (EC_POINT **)0x0) {
      pEVar16 = *points;
      ppEVar5 = points;
      while (pEVar16 != (EC_POINT *)0x0) {
        EC_POINT_clear_free(pEVar16);
        ppEVar5 = ppEVar5 + 1;
        pEVar16 = *ppEVar5;
      }
      CRYPTO_free(points);
    }
  }
LAB_0011b99e:
  CRYPTO_free(local_64);
  return iVar2;
}

