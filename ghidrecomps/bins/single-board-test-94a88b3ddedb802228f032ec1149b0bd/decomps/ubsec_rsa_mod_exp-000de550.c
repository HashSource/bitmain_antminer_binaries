
int ubsec_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  BIGNUM *pBVar8;
  RSA_METHOD *pRVar9;
  int iVar10;
  ulong *puVar11;
  code *pcVar12;
  ulong *puVar13;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  ulong *puVar14;
  ulong *puVar15;
  ulong *puVar16;
  BIGNUM *a_02;
  ulong *puVar17;
  BIGNUM *a_03;
  int local_2c [2];
  
  iVar10 = DAT_000de784;
  a = param_3->p;
  if ((((a == (BIGNUM *)0x0) || (a_00 = param_3->q, a_00 == (BIGNUM *)0x0)) ||
      (a_01 = param_3->dmp1, a_01 == (BIGNUM *)0x0)) ||
     ((a_02 = param_3->dmq1, a_02 == (BIGNUM *)0x0 || (a_03 = param_3->iqmp, a_03 == (BIGNUM *)0x0))
     )) {
    iVar1 = *(int *)(DAT_000de784 + 4);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar10 + 4) = iVar1;
    }
    ERR_put_error(iVar1,0x6c,0x68,DAT_000de788,0x26a);
    iVar10 = 0;
  }
  else {
    iVar1 = BN_num_bits(a);
    local_2c[0] = BN_num_bits(a_00);
    iVar10 = DAT_000de784;
    local_2c[0] = iVar1 + local_2c[0];
    if (*(int *)(DAT_000de77c + 0xcc) < local_2c[0]) {
      iVar1 = *(int *)(DAT_000de784 + 4);
      if (iVar1 == 0) {
        iVar1 = ERR_get_next_error_library();
        *(int *)(iVar10 + 4) = iVar1;
      }
      ERR_put_error(iVar1,0x6e,0x6b,DAT_000de788,0x287);
    }
    else {
      iVar10 = a->top + a_00->top;
      if ((param_1->dmax <= iVar10) &&
         (pBVar8 = bn_expand2(param_1,iVar10 + 1), iVar10 = DAT_000de784, pBVar8 == (BIGNUM *)0x0))
      {
        iVar1 = *(int *)(DAT_000de784 + 4);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar10 + 4) = iVar1;
        }
        ERR_put_error(iVar1,0x6e,0x65,DAT_000de788,0x28c);
        return 0;
      }
      iVar10 = DAT_000de784;
      iVar1 = (**(code **)(DAT_000de784 + 0x14))(DAT_000de780);
      if (iVar1 < 1) {
        iVar1 = *(int *)(iVar10 + 4);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar10 + 4) = iVar1;
        }
        ERR_put_error(iVar1,0x6e,0x6c,DAT_000de788,0x292);
      }
      else {
        pcVar12 = *(code **)(iVar10 + 0x28);
        puVar11 = param_2->d;
        iVar2 = BN_num_bits(param_2);
        puVar13 = a_03->d;
        iVar3 = BN_num_bits(a_03);
        puVar14 = a_01->d;
        iVar4 = BN_num_bits(a_01);
        puVar15 = a->d;
        iVar5 = BN_num_bits(a);
        puVar16 = a_02->d;
        iVar6 = BN_num_bits(a_02);
        puVar17 = a_00->d;
        iVar7 = BN_num_bits(a_00);
        iVar2 = (*pcVar12)(iVar1,puVar11,iVar2,puVar13,iVar3,puVar14,iVar4,puVar15,iVar5,puVar16,
                           iVar6,puVar17,iVar7,param_1->d,local_2c);
        if (iVar2 == 0) {
          (**(code **)(iVar10 + 0x18))(iVar1);
          iVar1 = BN_num_bits(a);
          iVar2 = BN_num_bits(a_00);
          iVar10 = iVar1 + iVar2 + 0x1f;
          if (iVar10 < 0) {
            iVar10 = iVar1 + iVar2 + 0x3e;
          }
          param_1->top = iVar10 >> 5;
          return 1;
        }
        iVar2 = *(int *)(iVar10 + 4);
        if (iVar2 == 0) {
          iVar2 = ERR_get_next_error_library();
          *(int *)(iVar10 + 4) = iVar2;
        }
        ERR_put_error(iVar2,0x6e,0x6a,DAT_000de788,0x29f);
        (**(code **)(iVar10 + 0x18))(iVar1);
      }
    }
    pRVar9 = RSA_PKCS1_SSLeay();
    iVar10 = (*pRVar9->rsa_mod_exp)(param_1,param_2,param_3,param_4);
  }
  return iVar10;
}

