
undefined4 ec_GF2m_precompute_mult(EC_GROUP *param_1,BN_CTX *param_2)

{
  undefined4 uVar1;
  EC_GROUP **ptr;
  EC_POINT *pEVar2;
  BIGNUM *order;
  int iVar3;
  uint uVar4;
  EC_GROUP *pEVar5;
  EC_POINT **points;
  EC_POINT *pEVar6;
  EC_POINT **ppEVar7;
  EC_POINT **dst;
  int iVar8;
  EC_GROUP *num;
  EC_POINT **ppEVar9;
  EC_GROUP *pEVar10;
  BN_CTX *c;
  undefined4 uVar11;
  EC_POINT **ppEVar12;
  int iStack_44;
  EC_GROUP *pEStack_38;
  EC_GROUP *pEStack_30;
  
  EC_EX_DATA_free_data(param_1 + 0x44,DAT_000a2a7c,DAT_000a2a80,DAT_000a2a84);
  if (param_1 == (EC_GROUP *)0x0) {
    return 0;
  }
  ptr = (EC_GROUP **)CRYPTO_malloc(0x1c,DAT_000a2a88,0x67);
  if (ptr == (EC_GROUP **)0x0) {
    ERR_put_error(0x10,0xc4,0x41,DAT_000a2a88,0x69);
    return 0;
  }
  *ptr = param_1;
  ptr[1] = (EC_GROUP *)0x8;
  ptr[2] = (EC_GROUP *)0x0;
  ptr[4] = (EC_GROUP *)0x0;
  ptr[5] = (EC_GROUP *)0x0;
  ptr[3] = (EC_GROUP *)0x4;
  ptr[6] = (EC_GROUP *)0x1;
  pEVar2 = EC_GROUP_get0_generator(param_1);
  if (pEVar2 == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0xbc,0x71,DAT_000a2a88,0x2f9);
    if (param_2 == (BN_CTX *)0x0) goto LAB_000a2a0c;
    BN_CTX_end(param_2);
    points = (EC_POINT **)0x0;
    ppEVar7 = (EC_POINT **)0x0;
    dst = (EC_POINT **)0x0;
    uVar11 = 0;
  }
  else {
    c = (BN_CTX *)0x0;
    if ((param_2 == (BN_CTX *)0x0) &&
       (param_2 = BN_CTX_new(), c = param_2, param_2 == (BN_CTX *)0x0)) {
LAB_000a2a0c:
      uVar11 = 0;
      points = (EC_POINT **)0x0;
      ppEVar7 = points;
      dst = points;
    }
    else {
      BN_CTX_start(param_2);
      order = BN_CTX_get(param_2);
      if (order == (BIGNUM *)0x0) {
        points = (EC_POINT **)0x0;
        ppEVar7 = (EC_POINT **)0x0;
        dst = (EC_POINT **)0x0;
        uVar11 = 0;
      }
      else {
        iVar3 = EC_GROUP_get_order(param_1,order,param_2);
        if (iVar3 == 0) {
          points = (EC_POINT **)0x0;
          ppEVar7 = (EC_POINT **)0x0;
          dst = (EC_POINT **)0x0;
          uVar11 = 0;
        }
        else if (order->top == 0) {
          ERR_put_error(0x10,0xbc,0x72,DAT_000a2a88,0x30b);
          points = (EC_POINT **)0x0;
          ppEVar7 = (EC_POINT **)0x0;
          dst = (EC_POINT **)0x0;
          uVar11 = 0;
        }
        else {
          uVar4 = BN_num_bits(order);
          if (uVar4 < 800) {
            iStack_44 = 8;
            pEStack_38 = (EC_GROUP *)0x4;
          }
          else if (uVar4 < 2000) {
            iStack_44 = 0x10;
            pEStack_38 = (EC_GROUP *)0x5;
          }
          else {
            iStack_44 = 0x20;
            pEStack_38 = (EC_GROUP *)0x6;
          }
          pEVar5 = (EC_GROUP *)(uVar4 + 7 >> 3);
          num = (EC_GROUP *)((int)pEVar5 * iStack_44);
          points = (EC_POINT **)CRYPTO_malloc((int)(num + 1) * 4,DAT_000a2a88,0x325);
          if (points == (EC_POINT **)0x0) {
            ERR_put_error(0x10,0xbc,0x41,DAT_000a2bd8,0x327);
            ppEVar7 = (EC_POINT **)0x0;
            dst = (EC_POINT **)0x0;
            uVar11 = 0;
          }
          else {
            points[(int)num] = (EC_POINT *)0x0;
            if (num != (EC_GROUP *)0x0) {
              ppEVar7 = points + -1;
              pEVar10 = (EC_GROUP *)0x0;
              do {
                pEVar10 = pEVar10 + 1;
                pEVar6 = EC_POINT_new(param_1);
                ppEVar7 = ppEVar7 + 1;
                *ppEVar7 = pEVar6;
                if (pEVar6 == (EC_POINT *)0x0) {
                  ERR_put_error(0x10,0xbc,0x41,DAT_000a2a88,0x32f);
                  ppEVar7 = (EC_POINT **)0x0;
                  dst = (EC_POINT **)0x0;
                  uVar11 = 0;
                  goto LAB_000a290a;
                }
              } while (pEVar10 != num);
            }
            ppEVar7 = (EC_POINT **)EC_POINT_new(param_1);
            if ((ppEVar7 == (EC_POINT **)0x0) ||
               (dst = (EC_POINT **)EC_POINT_new(param_1), dst == (EC_POINT **)0x0)) {
              uVar11 = 0;
              ERR_put_error(0x10,0xbc,0x41,DAT_000a2bd8,0x335);
              dst = (EC_POINT **)0x0;
            }
            else {
              iVar3 = EC_POINT_copy((EC_POINT *)dst,pEVar2);
              if (iVar3 != 0) {
                if (pEVar5 != (EC_GROUP *)0x0) {
                  pEStack_30 = (EC_GROUP *)0x0;
                  ppEVar9 = points;
                  do {
                    iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)ppEVar7,(EC_POINT *)dst,param_2);
                    if ((iVar3 == 0) ||
                       (iVar3 = EC_POINT_copy(*ppEVar9,(EC_POINT *)dst), iVar3 == 0))
                    goto LAB_000a2ab8;
                    iVar3 = 1;
                    ppEVar12 = ppEVar9;
                    do {
                      iVar3 = iVar3 + 1;
                      ppEVar9 = ppEVar12 + 2;
                      iVar8 = EC_POINT_add(param_1,ppEVar12[1],(EC_POINT *)ppEVar7,*ppEVar12,param_2
                                          );
                      if (iVar8 == 0) goto LAB_000a2ab8;
                      ppEVar12 = ppEVar12 + 1;
                    } while (iVar3 != iStack_44);
                    if ((pEStack_30 < pEVar5 + -1) &&
                       ((((iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)ppEVar7,param_2)
                          , iVar3 == 0 ||
                          (iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)dst,param_2),
                          iVar3 == 0)) ||
                         (iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)dst,param_2),
                         iVar3 == 0)) ||
                        (((iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)dst,param_2),
                          iVar3 == 0 ||
                          (iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)dst,param_2),
                          iVar3 == 0)) ||
                         ((iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)dst,param_2),
                          iVar3 == 0 ||
                          (iVar3 = EC_POINT_dbl(param_1,(EC_POINT *)dst,(EC_POINT *)dst,param_2),
                          iVar3 == 0)))))))) goto LAB_000a2ab8;
                    pEStack_30 = pEStack_30 + 1;
                  } while (pEStack_30 != pEVar5);
                }
                iVar3 = EC_POINTs_make_affine(param_1,(size_t)num,points,param_2);
                if (iVar3 != 0) {
                  *ptr = param_1;
                  uVar11 = DAT_000a2bdc;
                  ptr[1] = (EC_GROUP *)0x8;
                  ptr[2] = pEVar5;
                  ptr[4] = (EC_GROUP *)points;
                  ptr[3] = pEStack_38;
                  uVar1 = DAT_000a2be0;
                  ptr[5] = num;
                  iVar3 = EC_EX_DATA_set_data(param_1 + 0x44,ptr,uVar1,DAT_000a2be4,uVar11);
                  if (iVar3 == 0) {
                    points = (EC_POINT **)0x0;
                    uVar11 = 0;
                  }
                  else {
                    ptr = (EC_GROUP **)0x0;
                    uVar11 = 1;
                    points = (EC_POINT **)0x0;
                  }
                  goto LAB_000a290a;
                }
              }
LAB_000a2ab8:
              uVar11 = 0;
            }
          }
        }
      }
LAB_000a290a:
      BN_CTX_end(param_2);
      if (c != (BN_CTX *)0x0) {
        BN_CTX_free(c);
      }
      if (ptr == (EC_GROUP **)0x0) goto LAB_000a2936;
    }
  }
  iVar3 = CRYPTO_add_lock((int *)(ptr + 6),-1,0x24,DAT_000a2a88,0x89);
  if (iVar3 < 1) {
    ppEVar9 = (EC_POINT **)ptr[4];
    if (ppEVar9 != (EC_POINT **)0x0) {
      pEVar2 = *ppEVar9;
      if (pEVar2 != (EC_POINT *)0x0) {
        do {
          EC_POINT_free(pEVar2);
          ppEVar9 = ppEVar9 + 1;
          pEVar2 = *ppEVar9;
        } while (pEVar2 != (EC_POINT *)0x0);
        ppEVar9 = (EC_POINT **)ptr[4];
      }
      CRYPTO_free(ppEVar9);
    }
    CRYPTO_free(ptr);
  }
LAB_000a2936:
  if (points != (EC_POINT **)0x0) {
    pEVar2 = *points;
    ppEVar9 = points;
    while (pEVar2 != (EC_POINT *)0x0) {
      EC_POINT_free(pEVar2);
      ppEVar9 = ppEVar9 + 1;
      pEVar2 = *ppEVar9;
    }
    CRYPTO_free(points);
  }
  if (ppEVar7 != (EC_POINT **)0x0) {
    EC_POINT_free((EC_POINT *)ppEVar7);
  }
  if (dst != (EC_POINT **)0x0) {
    EC_POINT_free((EC_POINT *)dst);
    return uVar11;
  }
  return uVar11;
}

