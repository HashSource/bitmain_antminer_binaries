
int ec_GF2m_simple_set_compressed_coordinates
              (int *param_1,undefined4 param_2,undefined4 param_3,uint param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  ulong uVar6;
  BN_CTX *c;
  uint uVar7;
  int *piVar8;
  
  ERR_clear_error();
  c = (BN_CTX *)0x0;
  if ((param_5 == (BN_CTX *)0x0) && (param_5 = BN_CTX_new(), c = param_5, param_5 == (BN_CTX *)0x0))
  {
    return 0;
  }
  BN_CTX_start(param_5);
  pBVar1 = BN_CTX_get(param_5);
  pBVar2 = BN_CTX_get(param_5);
  pBVar3 = BN_CTX_get(param_5);
  pBVar4 = BN_CTX_get(param_5);
  if (pBVar4 != (BIGNUM *)0x0) {
    piVar8 = param_1 + 0x17;
    iVar5 = BN_GF2m_mod_arr(pBVar2,param_3,piVar8);
    if (iVar5 != 0) {
      if (pBVar2->top == 0) {
        iVar5 = BN_GF2m_mod_sqrt_arr(pBVar3,param_1 + 0x22,piVar8,param_5);
joined_r0x000f9c6a:
        if (iVar5 != 0) {
LAB_000f9bb4:
          iVar5 = EC_POINT_set_affine_coordinates_GF2m(param_1,param_2,pBVar2,pBVar3,param_5);
          if (iVar5 != 0) {
            iVar5 = 1;
          }
          goto LAB_000f9b86;
        }
      }
      else {
        iVar5 = (**(code **)(*param_1 + 0x88))(param_1,pBVar1,pBVar2,param_5);
        if ((((iVar5 != 0) &&
             (iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar1,param_1 + 0x22,pBVar1,param_5),
             iVar5 != 0)) && (iVar5 = BN_GF2m_add(pBVar1,param_1 + 0x1d,pBVar1), iVar5 != 0)) &&
           (iVar5 = BN_GF2m_add(pBVar1,pBVar2,pBVar1), iVar5 != 0)) {
          iVar5 = BN_GF2m_mod_solve_quad_arr(pBVar4,pBVar1,piVar8,param_5);
          if (iVar5 == 0) {
            uVar6 = ERR_peek_last_error();
            if ((uVar6 >> 0x18 != 3) || ((uVar6 & 0xfff) != 0x74)) {
              ERR_put_error(0x10,0xa4,3,DAT_000f9cbc,0x90);
              iVar5 = 0;
              goto LAB_000f9b86;
            }
            ERR_clear_error();
            ERR_put_error(0x10,0xa4,0x6e,DAT_000f9cbc,0x8d);
          }
          else {
            if (pBVar4->top < 1) {
              uVar7 = 0;
            }
            else {
              uVar7 = *pBVar4->d;
            }
            if (0 < pBVar4->top) {
              uVar7 = uVar7 & 1;
            }
            iVar5 = (**(code **)(*param_1 + 0x84))(param_1,pBVar3,pBVar2,pBVar4,param_5);
            if (iVar5 != 0) {
              if (param_4 != 0) {
                param_4 = 1;
              }
              if (uVar7 != param_4) {
                iVar5 = BN_GF2m_add(pBVar3,pBVar3,pBVar2);
                goto joined_r0x000f9c6a;
              }
              goto LAB_000f9bb4;
            }
          }
        }
      }
    }
  }
  iVar5 = 0;
LAB_000f9b86:
  BN_CTX_end(param_5);
  if (c != (BN_CTX *)0x0) {
    BN_CTX_free(c);
  }
  return iVar5;
}

