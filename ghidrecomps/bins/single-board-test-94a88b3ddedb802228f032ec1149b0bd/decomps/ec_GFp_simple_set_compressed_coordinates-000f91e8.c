
int ec_GFp_simple_set_compressed_coordinates
              (int *param_1,EC_POINT *param_2,BIGNUM *param_3,uint param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *ret;
  int iVar2;
  ulong uVar3;
  uint uVar4;
  BN_CTX *c;
  int iVar5;
  code *pcVar6;
  BIGNUM *d;
  
  ERR_clear_error();
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  r = BN_CTX_get(param_5);
  r_00 = BN_CTX_get(param_5);
  ret = BN_CTX_get(param_5);
  if (ret != (BIGNUM *)0x0) {
    d = (BIGNUM *)(param_1 + 0x12);
    iVar2 = BN_nnmod(r_00,param_3,d,param_5);
    if (iVar2 != 0) {
      if (*(int *)(*param_1 + 0x94) == 0) {
        iVar2 = (**(code **)(*param_1 + 0x88))(param_1,r,param_3,param_5);
        if (iVar2 != 0) {
          iVar2 = (**(code **)(*param_1 + 0x84))(param_1,pBVar1,r,param_3,param_5);
          goto joined_r0x000f9392;
        }
      }
      else {
        iVar2 = BN_mod_sqr(r,param_3,d,param_5);
        if (iVar2 != 0) {
          iVar2 = BN_mod_mul(pBVar1,r,param_3,d,param_5);
joined_r0x000f9392:
          if (iVar2 != 0) {
            if (param_1[0x27] == 0) {
              pcVar6 = *(code **)(*param_1 + 0x94);
              if (pcVar6 == (code *)0x0) {
                iVar2 = (**(code **)(*param_1 + 0x84))(param_1,r,param_1 + 0x1d,r_00,param_5);
              }
              else {
                iVar2 = (*pcVar6)(param_1,r,param_1 + 0x1d,param_5);
                if (iVar2 == 0) goto LAB_000f923e;
                iVar2 = BN_mod_mul(r,r,r_00,d,param_5);
              }
              if (iVar2 != 0) {
                iVar2 = BN_mod_add_quick(pBVar1,pBVar1,r,d);
                goto joined_r0x000f92ca;
              }
            }
            else {
              iVar2 = BN_mod_lshift1_quick(r,r_00,d);
              if ((iVar2 != 0) && (iVar2 = BN_mod_add_quick(r,r,r_00,d), iVar2 != 0)) {
                iVar2 = BN_mod_sub_quick(pBVar1,pBVar1,r,d);
joined_r0x000f92ca:
                if (iVar2 != 0) {
                  if (*(code **)(*param_1 + 0x94) == (code *)0x0) {
                    iVar2 = BN_mod_add_quick(pBVar1,pBVar1,(BIGNUM *)(param_1 + 0x22),d);
                  }
                  else {
                    iVar2 = (**(code **)(*param_1 + 0x94))(param_1,r,param_1 + 0x22,param_5);
                    if (iVar2 == 0) goto LAB_000f923e;
                    iVar2 = BN_mod_add_quick(pBVar1,pBVar1,r,d);
                  }
                  if (iVar2 != 0) {
                    pBVar1 = BN_mod_sqrt(ret,pBVar1,d,param_5);
                    if (pBVar1 == (BIGNUM *)0x0) {
                      uVar3 = ERR_peek_last_error();
                      if ((uVar3 >> 0x18 == 3) && ((uVar3 & 0xfff) == 0x6f)) {
                        ERR_clear_error();
                        iVar2 = 0xa3;
LAB_000f934c:
                        iVar5 = 0;
                        ERR_put_error(0x10,0xa9,0x6e,DAT_000f9494,iVar2);
                        goto LAB_000f9240;
                      }
                      ERR_put_error(0x10,0xa9,3,DAT_000f9494,0xa6);
                    }
                    else {
                      iVar2 = ret->top;
                      if (iVar2 < 1) {
                        uVar4 = 0;
                      }
                      else {
                        uVar4 = *ret->d & 1;
                      }
                      if (param_4 != 0) {
                        param_4 = 1;
                      }
                      if (uVar4 == param_4) {
LAB_000f9416:
                        if (iVar2 < 1) {
                          uVar4 = 0;
                        }
                        else {
                          uVar4 = *ret->d & 1;
                        }
                        if (uVar4 == param_4) {
                          iVar5 = EC_POINT_set_affine_coordinates_GFp
                                            ((EC_GROUP *)param_1,param_2,r_00,ret,param_5);
                          if (iVar5 != 0) {
                            iVar5 = 1;
                          }
                        }
                        else {
                          ERR_put_error(0x10,0xa9,0x44,DAT_000f9494,0xc2);
                          iVar5 = 0;
                        }
                        goto LAB_000f9240;
                      }
                      if (iVar2 == 0) {
                        iVar2 = BN_kronecker(r_00,d,param_5);
                        if (iVar2 != -2) {
                          iVar5 = 0;
                          if (iVar2 == 1) {
                            ERR_put_error(0x10,0xa9,0x6d,DAT_000f9494,0xb4);
                            goto LAB_000f9240;
                          }
                          iVar2 = 0xba;
                          goto LAB_000f934c;
                        }
                      }
                      else {
                        iVar2 = BN_usub(ret,d,ret);
                        if (iVar2 != 0) {
                          iVar2 = ret->top;
                          goto LAB_000f9416;
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
LAB_000f923e:
  iVar5 = 0;
LAB_000f9240:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return iVar5;
}

