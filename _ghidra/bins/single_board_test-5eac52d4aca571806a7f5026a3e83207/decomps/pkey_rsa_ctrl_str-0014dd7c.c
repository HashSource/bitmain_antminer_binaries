
int pkey_rsa_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  BIGNUM *pBVar2;
  void *p2;
  long lVar3;
  undefined4 uVar4;
  BIGNUM *local_1c [2];
  
  if (param_3 == (char *)0x0) {
    ERR_put_error(4,0x90,0x93,"crypto/rsa/rsa_pmeth.c",0x251);
    return 0;
  }
  iVar1 = strcmp(param_2,"rsa_padding_mode");
  if (iVar1 == 0) {
    iVar1 = strcmp(param_3,"pkcs1");
    if (iVar1 == 0) {
      uVar4 = 1;
    }
    else {
      iVar1 = strcmp(param_3,"sslv23");
      if (iVar1 == 0) {
        uVar4 = 2;
      }
      else {
        iVar1 = strcmp(param_3,"none");
        if (iVar1 == 0) {
          uVar4 = 3;
        }
        else {
          iVar1 = strcmp(param_3,"oeap");
          if ((iVar1 == 0) || (iVar1 = strcmp(param_3,"oaep"), iVar1 == 0)) {
            uVar4 = 4;
          }
          else {
            iVar1 = strcmp(param_3,"x931");
            if (iVar1 == 0) {
              uVar4 = 5;
            }
            else {
              if ((((*param_3 != 'p') || (param_3[1] != 's')) || (param_3[2] != 's')) ||
                 (param_3[3] != '\0')) {
                ERR_put_error(4,0x90,0x76,"crypto/rsa/rsa_pmeth.c",0x266);
                return -2;
              }
              uVar4 = 6;
            }
          }
        }
      }
    }
    iVar1 = RSA_pkey_ctx_ctrl(param_1,0xffffffff,0x1001,uVar4,0);
    return iVar1;
  }
  iVar1 = strcmp(param_2,"rsa_pss_saltlen");
  if (iVar1 == 0) {
    iVar1 = strcmp(param_3,"digest");
    lVar3 = -1;
    if (iVar1 != 0) {
      if ((((*param_3 == 'm') && (param_3[1] == 'a')) && (param_3[2] == 'x')) &&
         (param_3[3] == '\0')) {
        lVar3 = -3;
      }
      else {
        iVar1 = strcmp(param_3,"auto");
        lVar3 = -2;
        if (iVar1 != 0) {
          lVar3 = strtol(param_3,(char **)0x0,10);
        }
      }
    }
    iVar1 = RSA_pkey_ctx_ctrl(param_1,0x18,0x1002,lVar3,0);
  }
  else {
    iVar1 = strcmp(param_2,"rsa_keygen_bits");
    if (iVar1 == 0) {
      lVar3 = strtol(param_3,(char **)0x0,10);
      iVar1 = RSA_pkey_ctx_ctrl(param_1,4,0x1003,lVar3,0);
    }
    else {
      pBVar2 = (BIGNUM *)strcmp(param_2,"rsa_keygen_pubexp");
      if (pBVar2 == (BIGNUM *)0x0) {
        local_1c[0] = pBVar2;
        iVar1 = BN_asc2bn(local_1c,param_3);
        if ((iVar1 != 0) && (iVar1 = RSA_pkey_ctx_ctrl(param_1,4,0x1004,0,local_1c[0]), iVar1 < 1))
        {
          BN_free(local_1c[0]);
        }
      }
      else {
        iVar1 = strcmp(param_2,"rsa_keygen_primes");
        if (iVar1 == 0) {
          lVar3 = strtol(param_3,(char **)0x0,10);
          iVar1 = RSA_pkey_ctx_ctrl(param_1,4,0x100d,lVar3,0);
        }
        else {
          iVar1 = strcmp(param_2,"rsa_mgf1_md");
          if (iVar1 == 0) {
            iVar1 = EVP_PKEY_CTX_md(param_1,0x3f8,0x1005,param_3);
          }
          else {
            if (**(int **)param_1 == 0x390) {
              iVar1 = strcmp(param_2,"rsa_pss_keygen_mgf1_md");
              if (iVar1 == 0) {
                iVar1 = EVP_PKEY_CTX_md(param_1,4,0x1005,param_3);
                return iVar1;
              }
              iVar1 = strcmp(param_2,"rsa_pss_keygen_md");
              if (iVar1 == 0) {
                iVar1 = EVP_PKEY_CTX_md(param_1,4,1,param_3);
                return iVar1;
              }
              iVar1 = strcmp(param_2,"rsa_pss_keygen_saltlen");
              if (iVar1 == 0) {
                lVar3 = strtol(param_3,(char **)0x0,10);
                iVar1 = EVP_PKEY_CTX_ctrl(param_1,0x390,4,0x1002,lVar3,(void *)0x0);
                return iVar1;
              }
            }
            iVar1 = strcmp(param_2,"rsa_oaep_md");
            if (iVar1 == 0) {
              iVar1 = EVP_PKEY_CTX_md(param_1,0x300,0x1009,param_3);
            }
            else {
              iVar1 = strcmp(param_2,"rsa_oaep_label");
              if (iVar1 == 0) {
                p2 = (void *)OPENSSL_hexstr2buf(param_3,local_1c);
                iVar1 = 0;
                if ((p2 != (void *)0x0) &&
                   (iVar1 = EVP_PKEY_CTX_ctrl(param_1,6,0x300,0x100a,(int)local_1c[0],p2), iVar1 < 1
                   )) {
                  CRYPTO_free(p2);
                }
              }
              else {
                iVar1 = -2;
              }
            }
          }
        }
      }
    }
  }
  return iVar1;
}

