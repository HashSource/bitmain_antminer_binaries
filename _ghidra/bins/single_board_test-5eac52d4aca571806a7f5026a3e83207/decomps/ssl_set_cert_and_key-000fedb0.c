
undefined4
ssl_set_cert_and_key
          (int param_1,int param_2,X509 *param_3,EVP_PKEY *param_4,int param_5,int param_6)

{
  int iVar1;
  int iVar2;
  EVP_PKEY *pkey;
  undefined4 uVar3;
  EVP_PKEY *pEVar4;
  int *piVar5;
  int local_2c [2];
  
  if (param_1 == 0) {
    piVar5 = *(int **)(param_2 + 0xc0);
  }
  else {
    piVar5 = *(int **)(param_1 + 0x404);
  }
  iVar1 = ssl_security_cert(param_1,param_2,param_3,0,1);
  if (iVar1 == 1) {
    iVar1 = 0;
    while( true ) {
      iVar2 = OPENSSL_sk_num(param_5);
      if (iVar2 <= iVar1) break;
      uVar3 = OPENSSL_sk_value(param_5,iVar1);
      iVar2 = ssl_security_cert(param_1,param_2,uVar3,0,0);
      iVar1 = iVar1 + 1;
      if (iVar2 != 1) {
        ERR_put_error(0x14,0x26d,iVar2,"ssl/ssl_rsa.c",0x437);
        EVP_PKEY_free((EVP_PKEY *)0x0);
        return 0;
      }
    }
    pkey = X509_get_pubkey(param_3);
    if (pkey == (EVP_PKEY *)0x0) {
      uVar3 = 0;
    }
    else {
      pEVar4 = pkey;
      if (param_4 != (EVP_PKEY *)0x0) {
        iVar1 = EVP_PKEY_missing_parameters(param_4);
        if (iVar1 == 0) {
          iVar1 = EVP_PKEY_missing_parameters(pkey);
          if (iVar1 != 0) {
            EVP_PKEY_copy_parameters(pkey,param_4);
          }
        }
        else {
          iVar1 = EVP_PKEY_missing_parameters(pkey);
          if (iVar1 != 0) {
            uVar3 = 0;
            ERR_put_error(0x14,0x26d,0x122,"ssl/ssl_rsa.c",0x446);
            goto LAB_000feeaa;
          }
          EVP_PKEY_copy_parameters(param_4,pkey);
        }
        iVar1 = EVP_PKEY_cmp(pkey,param_4);
        pEVar4 = param_4;
        if (iVar1 != 1) {
          uVar3 = 0;
          ERR_put_error(0x14,0x26d,0x120,"ssl/ssl_rsa.c",0x453);
          goto LAB_000feeaa;
        }
      }
      iVar1 = ssl_cert_lookup_by_pkey(pkey,local_2c);
      if (iVar1 == 0) {
        ERR_put_error(0x14,0x26d,0xf7,"ssl/ssl_rsa.c",0x458);
        uVar3 = 0;
      }
      else if ((param_6 == 0) &&
              (((piVar5[local_2c[0] * 5 + 5] != 0 || (piVar5[local_2c[0] * 5 + 6] != 0)) ||
               (piVar5[local_2c[0] * 5 + 7] != 0)))) {
        uVar3 = 0;
        ERR_put_error(0x14,0x26d,0x121,"ssl/ssl_rsa.c",0x460);
      }
      else if ((param_5 == 0) || (param_5 = X509_chain_up_ref(param_5), param_5 != 0)) {
        uVar3 = 1;
        OPENSSL_sk_pop_free(piVar5[local_2c[0] * 5 + 7],(undefined *)0x16a341);
        piVar5[local_2c[0] * 5 + 7] = param_5;
        X509_free((X509 *)piVar5[local_2c[0] * 5 + 5]);
        X509_up_ref(param_3);
        piVar5[local_2c[0] * 5 + 5] = (int)param_3;
        EVP_PKEY_free((EVP_PKEY *)piVar5[local_2c[0] * 5 + 6]);
        EVP_PKEY_up_ref(pEVar4);
        piVar5[local_2c[0] * 5 + 6] = (int)pEVar4;
        *piVar5 = (int)(piVar5 + local_2c[0] * 5 + 5);
      }
      else {
        ERR_put_error(0x14,0x26d,0x41,"ssl/ssl_rsa.c",0x467);
        uVar3 = 0;
      }
    }
  }
  else {
    pkey = (EVP_PKEY *)0x0;
    uVar3 = 0;
    ERR_put_error(0x14,0x26d,iVar1,"ssl/ssl_rsa.c",0x431);
  }
LAB_000feeaa:
  EVP_PKEY_free(pkey);
  return uVar3;
}

