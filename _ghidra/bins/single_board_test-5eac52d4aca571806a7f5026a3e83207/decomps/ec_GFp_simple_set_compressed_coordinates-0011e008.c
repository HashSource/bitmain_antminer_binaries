
int ec_GFp_simple_set_compressed_coordinates
              (int *param_1,undefined4 param_2,BIGNUM *param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *r;
  BIGNUM *r_00;
  BIGNUM *ret;
  int iVar2;
  ulong uVar3;
  code *pcVar4;
  BN_CTX *c;
  
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
  if ((ret != (BIGNUM *)0x0) &&
     (iVar2 = BN_nnmod(r_00,param_3,(BIGNUM *)param_1[10],param_5), iVar2 != 0)) {
    if (*(int *)(*param_1 + 0x9c) == 0) {
      iVar2 = (**(code **)(*param_1 + 0x8c))(param_1,r,param_3,param_5);
      if (iVar2 != 0) {
        iVar2 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,r,param_3,param_5);
        goto joined_r0x0011e19a;
      }
    }
    else {
      iVar2 = BN_mod_sqr(r,param_3,(BIGNUM *)param_1[10],param_5);
      if (iVar2 != 0) {
        iVar2 = BN_mod_mul(pBVar1,r,param_3,(BIGNUM *)param_1[10],param_5);
joined_r0x0011e19a:
        if (iVar2 != 0) {
          if (param_1[0x13] == 0) {
            pcVar4 = *(code **)(*param_1 + 0x9c);
            if (pcVar4 == (code *)0x0) {
              iVar2 = (**(code **)(*param_1 + 0x88))(param_1,r,param_1[0x11],r_00,param_5);
            }
            else {
              iVar2 = (*pcVar4)(param_1,r,param_1[0x11],param_5);
              if (iVar2 == 0) goto LAB_0011e05c;
              iVar2 = BN_mod_mul(r,r,r_00,(BIGNUM *)param_1[10],param_5);
            }
            if (iVar2 != 0) {
              iVar2 = BN_mod_add_quick(pBVar1,pBVar1,r,(BIGNUM *)param_1[10]);
              goto joined_r0x0011e0de;
            }
          }
          else {
            iVar2 = BN_mod_lshift1_quick(r,r_00,(BIGNUM *)param_1[10]);
            if ((iVar2 != 0) &&
               (iVar2 = BN_mod_add_quick(r,r,r_00,(BIGNUM *)param_1[10]), iVar2 != 0)) {
              iVar2 = BN_mod_sub_quick(pBVar1,pBVar1,r,(BIGNUM *)param_1[10]);
joined_r0x0011e0de:
              if (iVar2 != 0) {
                if (*(code **)(*param_1 + 0x9c) == (code *)0x0) {
                  iVar2 = BN_mod_add_quick(pBVar1,pBVar1,(BIGNUM *)param_1[0x12],
                                           (BIGNUM *)param_1[10]);
                }
                else {
                  iVar2 = (**(code **)(*param_1 + 0x9c))(param_1,r,param_1[0x12],param_5);
                  if (iVar2 == 0) goto LAB_0011e05c;
                  iVar2 = BN_mod_add_quick(pBVar1,pBVar1,r,(BIGNUM *)param_1[10]);
                }
                if (iVar2 != 0) {
                  pBVar1 = BN_mod_sqrt(ret,pBVar1,(BIGNUM *)param_1[10],param_5);
                  if (pBVar1 == (BIGNUM *)0x0) {
                    uVar3 = ERR_peek_last_error();
                    if ((uVar3 >> 0x18 == 3) && ((uVar3 & 0xfff) == 0x6f)) {
                      ERR_clear_error();
                      ERR_put_error(0x10,0xa9,0x6e,"crypto/ec/ecp_oct.c",0x6c);
                      iVar2 = 0;
                    }
                    else {
                      iVar2 = 0;
                      ERR_put_error(0x10,0xa9,3,"crypto/ec/ecp_oct.c",0x6f);
                    }
                    goto LAB_0011e05e;
                  }
                  if (param_4 != 0) {
                    param_4 = 1;
                  }
                  iVar2 = BN_is_odd(ret);
                  if (param_4 == iVar2) {
LAB_0011e214:
                    iVar2 = BN_is_odd(ret);
                    if (param_4 == iVar2) {
                      iVar2 = EC_POINT_set_affine_coordinates(param_1,param_2,r_00,ret,param_5);
                      if (iVar2 != 0) {
                        iVar2 = 1;
                      }
                    }
                    else {
                      iVar2 = 0;
                      ERR_put_error(0x10,0xa9,0x44,"crypto/ec/ecp_oct.c",0x8b);
                    }
                    goto LAB_0011e05e;
                  }
                  iVar2 = BN_is_zero(ret);
                  if (iVar2 == 0) {
                    iVar2 = BN_usub(ret,(BIGNUM *)param_1[10],ret);
                    if (iVar2 != 0) goto LAB_0011e214;
                  }
                  else {
                    iVar2 = BN_kronecker(r_00,(BIGNUM *)param_1[10],param_5);
                    if (iVar2 != -2) {
                      if (iVar2 != 1) {
                        iVar2 = 0;
                        ERR_put_error(0x10,0xa9,0x6e,"crypto/ec/ecp_oct.c",0x83);
                        goto LAB_0011e05e;
                      }
                      ERR_put_error(0x10,0xa9,0x6d,"crypto/ec/ecp_oct.c",0x7d);
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
LAB_0011e05c:
  iVar2 = 0;
LAB_0011e05e:
  BN_CTX_end(param_5);
  BN_CTX_free(c);
  return iVar2;
}

