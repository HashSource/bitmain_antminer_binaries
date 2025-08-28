
int aep_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  uint uVar3;
  BIGNUM *pBVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  int iVar7;
  BIGNUM *pBVar8;
  BIGNUM *pBVar9;
  int local_2c [2];
  
  if (aep_dso == 0) {
    if (AEPHK_lib_error_code == 0) {
      AEPHK_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(AEPHK_lib_error_code,0x6b,0x6f,"e_aep.c",0x309);
    iVar1 = 0;
  }
  else {
    pBVar6 = param_3->q;
    if ((((pBVar6 == (BIGNUM *)0x0) || (pBVar8 = param_3->dmp1, pBVar8 == (BIGNUM *)0x0)) ||
        (pBVar4 = param_3->dmq1, pBVar4 == (BIGNUM *)0x0)) ||
       (pBVar9 = param_3->iqmp, pBVar9 == (BIGNUM *)0x0)) {
      pBVar6 = param_3->d;
      if ((pBVar6 == (BIGNUM *)0x0) || (pBVar8 = param_3->n, pBVar8 == (BIGNUM *)0x0)) {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x6b,0x6c,"e_aep.c",0x31c);
        iVar1 = 0;
      }
      else {
        iVar1 = BN_num_bits(pBVar8);
        if (iVar1 < 0x881) {
          uVar3 = aep_mod_exp_part_0(param_1,param_2,pBVar6,pBVar8,param_4);
        }
        else {
          if (AEPHK_lib_error_code == 0) {
            AEPHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(AEPHK_lib_error_code,0x68,0x74,"e_aep.c",0x265);
          uVar3 = BN_mod_exp(param_1,param_2,pBVar6,pBVar8,param_4);
        }
        iVar1 = 1 - uVar3;
        if (1 < uVar3) {
          iVar1 = 0;
        }
      }
    }
    else {
      pBVar5 = param_3->p;
      iVar1 = aep_get_connection(local_2c);
      if (iVar1 == 0) {
        iVar1 = (*p_AEP_ModExpCrt)(local_2c[0],param_2,pBVar5,pBVar6,pBVar8,pBVar4,pBVar9,param_1,0)
        ;
        if (iVar1 == 0) {
          CRYPTO_lock(9,0x1e,"e_aep.c",0x3dc);
          iVar1 = 0;
          do {
            iVar7 = iVar1 * 8;
            iVar1 = iVar1 + 1;
            if (local_2c[0] == *(int *)(aep_app_conn_table + iVar7 + 4)) {
              *(undefined4 *)(aep_app_conn_table + iVar7) = 1;
              break;
            }
          } while (iVar1 != 0x100);
          CRYPTO_lock(10,0x1e,"e_aep.c",1000);
          return 1;
        }
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        iVar1 = 0;
        ERR_put_error(AEPHK_lib_error_code,0x69,0x6d,"e_aep.c",0x2a5);
        CRYPTO_lock(9,0x1e,"e_aep.c",0x3f2);
        do {
          iVar7 = iVar1 * 8;
          iVar1 = iVar1 + 1;
          if (local_2c[0] == *(int *)(aep_app_conn_table + iVar7 + 4)) {
            iVar1 = (*p_AEP_CloseConnection)(local_2c[0]);
            if (iVar1 == 0) {
              *(undefined4 *)(aep_app_conn_table + iVar7) = 0;
              *(undefined4 *)(aep_app_conn_table + iVar7 + 4) = 0;
            }
            break;
          }
        } while (iVar1 != 0x100);
        CRYPTO_lock(10,0x1e,"e_aep.c",0x403);
      }
      else {
        if (AEPHK_lib_error_code == 0) {
          AEPHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(AEPHK_lib_error_code,0x69,0x69,"e_aep.c",0x29a);
      }
      pRVar2 = RSA_PKCS1_SSLeay();
      iVar1 = (*pRVar2->rsa_mod_exp)(param_1,param_2,param_3,param_4);
    }
  }
  return iVar1;
}

