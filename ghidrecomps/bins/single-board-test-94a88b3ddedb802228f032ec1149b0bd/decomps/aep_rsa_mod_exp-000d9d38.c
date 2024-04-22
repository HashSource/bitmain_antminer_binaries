
int aep_rsa_mod_exp(BIGNUM *param_1,BIGNUM *param_2,RSA *param_3,BN_CTX *param_4)

{
  int iVar1;
  RSA_METHOD *pRVar2;
  int iVar3;
  uint uVar4;
  BIGNUM *pBVar5;
  BIGNUM *pBVar6;
  BIGNUM *pBVar7;
  int iVar8;
  BIGNUM *pBVar9;
  BIGNUM *pBVar10;
  int local_2c [2];
  
  iVar3 = DAT_000d9f28;
  if (*(int *)(DAT_000d9f28 + 8) == 0) {
    iVar1 = *(int *)(DAT_000d9f28 + 4);
    if (iVar1 == 0) {
      iVar1 = ERR_get_next_error_library();
      *(int *)(iVar3 + 4) = iVar1;
    }
    ERR_put_error(iVar1,0x6b,0x6f,DAT_000d9f2c,0x309);
    iVar3 = 0;
  }
  else {
    pBVar7 = param_3->q;
    if ((((pBVar7 == (BIGNUM *)0x0) || (pBVar9 = param_3->dmp1, pBVar9 == (BIGNUM *)0x0)) ||
        (pBVar5 = param_3->dmq1, pBVar5 == (BIGNUM *)0x0)) ||
       (pBVar10 = param_3->iqmp, pBVar10 == (BIGNUM *)0x0)) {
      pBVar7 = param_3->d;
      if ((pBVar7 == (BIGNUM *)0x0) || (pBVar9 = param_3->n, pBVar9 == (BIGNUM *)0x0)) {
        iVar1 = *(int *)(DAT_000d9f28 + 4);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar3 + 4) = iVar1;
        }
        ERR_put_error(iVar1,0x6b,0x6c,DAT_000d9f2c,0x31c);
        iVar3 = 0;
      }
      else {
        iVar8 = BN_num_bits(pBVar9);
        iVar1 = DAT_000d9f28;
        if (iVar8 < 0x881) {
          uVar4 = aep_mod_exp_part_0(param_1,param_2,pBVar7,pBVar9,param_4);
        }
        else {
          iVar3 = *(int *)(iVar3 + 4);
          if (iVar3 == 0) {
            iVar3 = ERR_get_next_error_library();
            *(int *)(iVar1 + 4) = iVar3;
          }
          ERR_put_error(iVar3,0x68,0x74,DAT_000d9f2c,0x265);
          uVar4 = BN_mod_exp(param_1,param_2,pBVar7,pBVar9,param_4);
        }
        iVar3 = 1 - uVar4;
        if (1 < uVar4) {
          iVar3 = 0;
        }
      }
    }
    else {
      pBVar6 = param_3->p;
      iVar1 = aep_get_connection(local_2c);
      if (iVar1 == 0) {
        iVar1 = (**(code **)(iVar3 + 0x10))
                          (local_2c[0],param_2,pBVar6,pBVar7,pBVar9,pBVar5,pBVar10,param_1,0);
        if (iVar1 == 0) {
          CRYPTO_lock(9,0x1e,DAT_000d9f2c,0x3dc);
          iVar1 = 0;
          do {
            iVar8 = iVar1 * 8;
            iVar1 = iVar1 + 1;
            if (local_2c[0] == *(int *)(iVar3 + iVar8 + 0x2c)) {
              *(undefined4 *)(DAT_000d9f28 + iVar8 + 0x28) = 1;
              break;
            }
          } while (iVar1 != 0x100);
          CRYPTO_lock(10,0x1e,DAT_000d9f2c,1000);
          return 1;
        }
        iVar1 = *(int *)(iVar3 + 4);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar3 + 4) = iVar1;
        }
        iVar8 = 0;
        ERR_put_error(iVar1,0x69,0x6d,DAT_000d9f2c,0x2a5);
        CRYPTO_lock(9,0x1e,DAT_000d9f2c,0x3f2);
        iVar3 = DAT_000d9f28;
        do {
          iVar1 = iVar8 * 8;
          iVar8 = iVar8 + 1;
          if (local_2c[0] == *(int *)(DAT_000d9f30 + iVar1 + 4)) {
            iVar8 = (**(code **)(DAT_000d9f28 + 0x24))(local_2c[0]);
            if (iVar8 == 0) {
              iVar1 = iVar1 + iVar3;
              *(undefined4 *)(iVar1 + 0x28) = 0;
              *(undefined4 *)(iVar1 + 0x2c) = 0;
            }
            break;
          }
        } while (iVar8 != 0x100);
        CRYPTO_lock(10,0x1e,DAT_000d9f2c,0x403);
      }
      else {
        iVar1 = *(int *)(iVar3 + 4);
        if (iVar1 == 0) {
          iVar1 = ERR_get_next_error_library();
          *(int *)(iVar3 + 4) = iVar1;
        }
        ERR_put_error(iVar1,0x69,0x69,DAT_000d9f2c,0x29a);
      }
      pRVar2 = RSA_PKCS1_SSLeay();
      iVar3 = (*pRVar2->rsa_mod_exp)(param_1,param_2,param_3,param_4);
    }
  }
  return iVar3;
}

