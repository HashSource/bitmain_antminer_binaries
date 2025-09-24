
int ec_GF2m_simple_set_compressed_coordinates
              (int *param_1,undefined4 param_2,undefined4 param_3,int param_4,BN_CTX *param_5)

{
  BIGNUM *pBVar1;
  BIGNUM *pBVar2;
  BIGNUM *pBVar3;
  BIGNUM *pBVar4;
  int iVar5;
  ulong uVar6;
  int iVar7;
  BN_CTX *c;
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
    piVar8 = param_1 + 0xb;
    iVar5 = BN_GF2m_mod_arr(pBVar2,param_3,piVar8);
    if (iVar5 != 0) {
      iVar5 = BN_is_zero(pBVar2);
      if (iVar5 == 0) {
        iVar5 = (**(code **)(*param_1 + 0x8c))(param_1,pBVar1,pBVar2,param_5);
        if ((((iVar5 != 0) &&
             (iVar5 = (**(code **)(*param_1 + 0x90))(param_1,pBVar1,param_1[0x12],pBVar1,param_5),
             iVar5 != 0)) && (iVar5 = BN_GF2m_add(pBVar1,param_1[0x11],pBVar1), iVar5 != 0)) &&
           (iVar5 = BN_GF2m_add(pBVar1,pBVar2,pBVar1), iVar5 != 0)) {
          iVar5 = BN_GF2m_mod_solve_quad_arr(pBVar4,pBVar1,piVar8,param_5);
          if (iVar5 == 0) {
            uVar6 = ERR_peek_last_error();
            if ((uVar6 >> 0x18 != 3) || ((uVar6 & 0xfff) != 0x74)) {
              iVar5 = 0;
              ERR_put_error(0x10,0xa4,3,"crypto/ec/ec2_oct.c",0x55);
              goto LAB_001afc86;
            }
            ERR_clear_error();
            ERR_put_error(0x10,0xa4,0x6e,"crypto/ec/ec2_oct.c",0x52);
          }
          else {
            iVar5 = BN_is_odd(pBVar4);
            iVar7 = (**(code **)(*param_1 + 0x88))(param_1,pBVar3,pBVar2,pBVar4,param_5);
            if (iVar7 != 0) {
              if (param_4 != 0) {
                param_4 = 1;
              }
              if (iVar5 != 0) {
                iVar5 = 1;
              }
              if (param_4 != iVar5) {
                iVar5 = BN_GF2m_add(pBVar3,pBVar3,pBVar2);
                goto joined_r0x001afd98;
              }
              goto LAB_001afcb2;
            }
          }
        }
      }
      else {
        iVar5 = BN_GF2m_mod_sqrt_arr(pBVar3,param_1[0x12],piVar8,param_5);
joined_r0x001afd98:
        if (iVar5 != 0) {
LAB_001afcb2:
          iVar5 = EC_POINT_set_affine_coordinates(param_1,param_2,pBVar2,pBVar3,param_5);
          if (iVar5 != 0) {
            iVar5 = 1;
          }
          goto LAB_001afc86;
        }
      }
    }
  }
  iVar5 = 0;
LAB_001afc86:
  BN_CTX_end(param_5);
  BN_CTX_free(c);
  return iVar5;
}

