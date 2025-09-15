
/* WARNING: Restarted to delay deadcode elimination for space: ram */

int ubsec_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  code *pcVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  int iVar8;
  BIGNUM *pBVar9;
  RSA_METHOD *pRVar10;
  ulong *puVar11;
  ulong *puVar12;
  BIGNUM *a;
  BIGNUM *a_00;
  BIGNUM *a_01;
  ulong *puVar13;
  ulong *puVar14;
  ulong *puVar15;
  BIGNUM *a_02;
  ulong *puVar16;
  BIGNUM *a_03;
  int local_2c [2];
  
  a = param_3->p;
  if ((((a == (BIGNUM *)0x0) || (a_00 = param_3->q, a_00 == (BIGNUM *)0x0)) ||
      (a_01 = param_3->dmp1, a_01 == (BIGNUM *)0x0)) ||
     ((a_02 = param_3->dmq1, a_02 == (BIGNUM *)0x0 || (a_03 = param_3->iqmp, a_03 == (BIGNUM *)0x0))
     )) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x6c,0x68,"e_ubsec.c",0x26a);
    iVar2 = 0;
  }
  else {
    iVar2 = BN_num_bits(a);
    local_2c[0] = BN_num_bits(a_00);
    local_2c[0] = iVar2 + local_2c[0];
    if (max_key_len < local_2c[0]) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x6e,0x6b,"e_ubsec.c",0x287);
    }
    else {
      iVar2 = a->top + a_00->top;
      if ((param_1->dmax <= iVar2) &&
         (pBVar9 = bn_expand2(param_1,iVar2 + 1), pBVar9 == (BIGNUM *)0x0)) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6e,0x65,"e_ubsec.c",0x28c);
        return 0;
      }
      iVar2 = (*p_UBSEC_ubsec_open)("/dev/ubskey");
      pcVar1 = p_UBSEC_rsa_mod_exp_crt_ioctl;
      if (iVar2 < 1) {
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6e,0x6c,"e_ubsec.c",0x292);
      }
      else {
        puVar11 = param_2->d;
        iVar3 = BN_num_bits(param_2);
        puVar12 = a_03->d;
        iVar4 = BN_num_bits(a_03);
        puVar13 = a_01->d;
        iVar5 = BN_num_bits(a_01);
        puVar14 = a->d;
        iVar6 = BN_num_bits(a);
        puVar15 = a_02->d;
        iVar7 = BN_num_bits(a_02);
        puVar16 = a_00->d;
        iVar8 = BN_num_bits(a_00);
        iVar3 = (*pcVar1)(iVar2,puVar11,iVar3,puVar12,iVar4,puVar13,iVar5,puVar14,iVar6,puVar15,
                          iVar7,puVar16,iVar8,param_1->d,local_2c);
        if (iVar3 == 0) {
          (*p_UBSEC_ubsec_close)(iVar2);
          iVar3 = BN_num_bits(a);
          iVar4 = BN_num_bits(a_00);
          iVar2 = iVar3 + iVar4 + 0x1f;
          if (iVar2 < 0) {
            iVar2 = iVar3 + iVar4 + 0x3e;
          }
          param_1->top = iVar2 >> 5;
          return 1;
        }
        if (UBSEC_lib_error_code == 0) {
          UBSEC_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(UBSEC_lib_error_code,0x6e,0x6a,"e_ubsec.c",0x29f);
        (*p_UBSEC_ubsec_close)(iVar2);
      }
    }
    pRVar10 = RSA_PKCS1_SSLeay();
    iVar2 = (*pRVar10->rsa_mod_exp)(param_1,param_2,param_3,param_4);
  }
  return iVar2;
}

