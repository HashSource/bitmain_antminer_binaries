
undefined4 ec_GF2m_precompute_mult(EC_GROUP *param_1,BN_CTX *param_2)

{
  undefined4 *ptr;
  EC_POINT *pEVar1;
  BIGNUM *order;
  int iVar2;
  uint uVar3;
  EC_POINT *points;
  EC_POINT *pEVar4;
  EC_POINT *pEVar5;
  int iVar6;
  size_t num;
  int *ptr_00;
  EC_POINT *pEVar7;
  size_t sVar8;
  BN_CTX *c;
  undefined4 uVar9;
  int iStack_44;
  undefined4 uStack_38;
  uint uStack_30;
  
  EC_EX_DATA_free_data(param_1 + 0x44,0x144c89,0x144e85,0x144e25);
  if (param_1 == (EC_GROUP *)0x0) {
    return 0;
  }
  ptr = (undefined4 *)CRYPTO_malloc(0x1c,"ec_mult.c",0x67);
  if (ptr == (undefined4 *)0x0) {
    ERR_put_error(0x10,0xc4,0x41,"ec_mult.c",0x69);
    return 0;
  }
  *ptr = param_1;
  ptr[1] = 8;
  ptr[2] = 0;
  ptr[4] = 0;
  ptr[5] = 0;
  ptr[3] = 4;
  ptr[6] = 1;
  pEVar1 = EC_GROUP_get0_generator(param_1);
  if (pEVar1 == (EC_POINT *)0x0) {
    ERR_put_error(0x10,0xbc,0x71,"ec_mult.c",0x2f9);
    if (param_2 == (BN_CTX *)0x0) goto LAB_00145948;
    BN_CTX_end(param_2);
    points = (EC_POINT *)0x0;
    pEVar7 = (EC_POINT *)0x0;
    pEVar4 = (EC_POINT *)0x0;
    uVar9 = 0;
  }
  else {
    c = (BN_CTX *)0x0;
    if ((param_2 == (BN_CTX *)0x0) &&
       (param_2 = BN_CTX_new(), c = param_2, param_2 == (BN_CTX *)0x0)) {
LAB_00145948:
      uVar9 = 0;
      points = (EC_POINT *)0x0;
      pEVar7 = points;
      pEVar4 = points;
    }
    else {
      BN_CTX_start(param_2);
      order = BN_CTX_get(param_2);
      if (order == (BIGNUM *)0x0) {
        points = (EC_POINT *)0x0;
        pEVar7 = (EC_POINT *)0x0;
        pEVar4 = (EC_POINT *)0x0;
        uVar9 = 0;
      }
      else {
        iVar2 = EC_GROUP_get_order(param_1,order,param_2);
        if (iVar2 == 0) {
          points = (EC_POINT *)0x0;
          pEVar7 = (EC_POINT *)0x0;
          pEVar4 = (EC_POINT *)0x0;
          uVar9 = 0;
        }
        else if (order->top == 0) {
          ERR_put_error(0x10,0xbc,0x72,"ec_mult.c",0x30b);
          points = (EC_POINT *)0x0;
          pEVar7 = (EC_POINT *)0x0;
          pEVar4 = (EC_POINT *)0x0;
          uVar9 = 0;
        }
        else {
          uVar3 = BN_num_bits(order);
          if (uVar3 < 800) {
            iStack_44 = 8;
            uStack_38 = 4;
          }
          else if (uVar3 < 2000) {
            iStack_44 = 0x10;
            uStack_38 = 5;
          }
          else {
            iStack_44 = 0x20;
            uStack_38 = 6;
          }
          uVar3 = uVar3 + 7 >> 3;
          num = uVar3 * iStack_44;
          points = (EC_POINT *)CRYPTO_malloc((num + 1) * 4,"ec_mult.c",0x325);
          if (points == (EC_POINT *)0x0) {
            ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",0x327);
            pEVar7 = (EC_POINT *)0x0;
            pEVar4 = (EC_POINT *)0x0;
            uVar9 = 0;
          }
          else {
            *(undefined4 *)(points + num * 4) = 0;
            if (num != 0) {
              pEVar7 = points + -4;
              sVar8 = 0;
              do {
                sVar8 = sVar8 + 1;
                pEVar4 = EC_POINT_new(param_1);
                pEVar7 = pEVar7 + 4;
                *(EC_POINT **)pEVar7 = pEVar4;
                if (pEVar4 == (EC_POINT *)0x0) {
                  ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",0x32f);
                  pEVar7 = (EC_POINT *)0x0;
                  pEVar4 = (EC_POINT *)0x0;
                  uVar9 = 0;
                  goto LAB_00145846;
                }
              } while (sVar8 != num);
            }
            pEVar7 = EC_POINT_new(param_1);
            if ((pEVar7 == (EC_POINT *)0x0) ||
               (pEVar4 = EC_POINT_new(param_1), pEVar4 == (EC_POINT *)0x0)) {
              uVar9 = 0;
              ERR_put_error(0x10,0xbc,0x41,"ec_mult.c",0x335);
              pEVar4 = (EC_POINT *)0x0;
            }
            else {
              iVar2 = EC_POINT_copy(pEVar4,pEVar1);
              if (iVar2 != 0) {
                if (uVar3 != 0) {
                  uStack_30 = 0;
                  pEVar1 = points;
                  do {
                    iVar2 = EC_POINT_dbl(param_1,pEVar7,pEVar4,param_2);
                    if ((iVar2 == 0) ||
                       (iVar2 = EC_POINT_copy(*(EC_POINT **)pEVar1,pEVar4), iVar2 == 0))
                    goto LAB_001459f4;
                    iVar2 = 1;
                    pEVar5 = pEVar1;
                    do {
                      iVar2 = iVar2 + 1;
                      pEVar1 = pEVar5 + 8;
                      iVar6 = EC_POINT_add(param_1,*(EC_POINT **)(pEVar5 + 4),pEVar7,
                                           *(EC_POINT **)pEVar5,param_2);
                      if (iVar6 == 0) goto LAB_001459f4;
                      pEVar5 = pEVar5 + 4;
                    } while (iVar2 != iStack_44);
                    if ((uStack_30 < uVar3 - 1) &&
                       ((((iVar2 = EC_POINT_dbl(param_1,pEVar4,pEVar7,param_2), iVar2 == 0 ||
                          (iVar2 = EC_POINT_dbl(param_1,pEVar4,pEVar4,param_2), iVar2 == 0)) ||
                         (iVar2 = EC_POINT_dbl(param_1,pEVar4,pEVar4,param_2), iVar2 == 0)) ||
                        (((iVar2 = EC_POINT_dbl(param_1,pEVar4,pEVar4,param_2), iVar2 == 0 ||
                          (iVar2 = EC_POINT_dbl(param_1,pEVar4,pEVar4,param_2), iVar2 == 0)) ||
                         ((iVar2 = EC_POINT_dbl(param_1,pEVar4,pEVar4,param_2), iVar2 == 0 ||
                          (iVar2 = EC_POINT_dbl(param_1,pEVar4,pEVar4,param_2), iVar2 == 0))))))))
                    goto LAB_001459f4;
                    uStack_30 = uStack_30 + 1;
                  } while (uStack_30 != uVar3);
                }
                iVar2 = EC_POINTs_make_affine(param_1,num,(EC_POINT **)points,param_2);
                if (iVar2 != 0) {
                  *ptr = param_1;
                  ptr[1] = 8;
                  ptr[2] = uVar3;
                  ptr[4] = points;
                  ptr[3] = uStack_38;
                  ptr[5] = num;
                  iVar2 = EC_EX_DATA_set_data(param_1 + 0x44,ptr,0x144c89,0x144e85,0x144e25);
                  if (iVar2 == 0) {
                    points = (EC_POINT *)0x0;
                    uVar9 = 0;
                  }
                  else {
                    ptr = (undefined4 *)0x0;
                    uVar9 = 1;
                    points = (EC_POINT *)0x0;
                  }
                  goto LAB_00145846;
                }
              }
LAB_001459f4:
              uVar9 = 0;
            }
          }
        }
      }
LAB_00145846:
      BN_CTX_end(param_2);
      if (c != (BN_CTX *)0x0) {
        BN_CTX_free(c);
      }
      if (ptr == (undefined4 *)0x0) goto LAB_00145872;
    }
  }
  iVar2 = CRYPTO_add_lock(ptr + 6,-1,0x24,"ec_mult.c",0x89);
  if (iVar2 < 1) {
    ptr_00 = (int *)ptr[4];
    if (ptr_00 != (int *)0x0) {
      pEVar1 = (EC_POINT *)*ptr_00;
      if (pEVar1 != (EC_POINT *)0x0) {
        do {
          EC_POINT_free(pEVar1);
          ptr_00 = ptr_00 + 1;
          pEVar1 = (EC_POINT *)*ptr_00;
        } while (pEVar1 != (EC_POINT *)0x0);
        ptr_00 = (int *)ptr[4];
      }
      CRYPTO_free(ptr_00);
    }
    CRYPTO_free(ptr);
  }
LAB_00145872:
  if (points != (EC_POINT *)0x0) {
    pEVar5 = *(EC_POINT **)points;
    pEVar1 = points;
    while (pEVar5 != (EC_POINT *)0x0) {
      EC_POINT_free(pEVar5);
      pEVar1 = pEVar1 + 4;
      pEVar5 = *(EC_POINT **)pEVar1;
    }
    CRYPTO_free(points);
  }
  if (pEVar7 != (EC_POINT *)0x0) {
    EC_POINT_free(pEVar7);
  }
  if (pEVar4 != (EC_POINT *)0x0) {
    EC_POINT_free(pEVar4);
    return uVar9;
  }
  return uVar9;
}

