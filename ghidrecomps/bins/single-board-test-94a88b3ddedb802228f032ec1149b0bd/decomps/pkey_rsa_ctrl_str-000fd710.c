
EVP_MD * pkey_rsa_ctrl_str(EVP_PKEY_CTX *param_1,char *param_2,char *param_3)

{
  int iVar1;
  uchar *p2;
  EVP_MD *pEVar2;
  long lVar3;
  BIGNUM *local_20;
  int local_1c [2];
  
  if (param_3 == (char *)0x0) {
    ERR_put_error(4,0x90,0x93,DAT_000fd98c,0x282);
    pEVar2 = (EVP_MD *)0x0;
  }
  else {
    iVar1 = strcmp(param_2,DAT_000fd958);
    if (iVar1 == 0) {
      iVar1 = strcmp(param_3,DAT_000fd974);
      if (iVar1 == 0) {
        iVar1 = 1;
      }
      else {
        iVar1 = strcmp(param_3,DAT_000fd978);
        if (iVar1 == 0) {
          iVar1 = 2;
        }
        else {
          iVar1 = strcmp(param_3,DAT_000fd97c);
          if (iVar1 == 0) {
            iVar1 = 3;
          }
          else {
            iVar1 = strcmp(param_3,DAT_000fd980);
            if ((iVar1 == 0) || (iVar1 = strcmp(param_3,DAT_000fd984), iVar1 == 0)) {
              iVar1 = 4;
            }
            else {
              iVar1 = strcmp(param_3,DAT_000fd988);
              if (iVar1 == 0) {
                iVar1 = 5;
              }
              else if ((((*param_3 != 'p') || (param_3[1] != 's')) || (param_3[2] != 's')) ||
                      (iVar1 = 6, param_3[3] != '\0')) {
                ERR_put_error(4,0x90,0x76,DAT_000fd98c,0x296);
                return (EVP_MD *)0xfffffffe;
              }
            }
          }
        }
      }
      pEVar2 = (EVP_MD *)EVP_PKEY_CTX_ctrl(param_1,6,-1,0x1001,iVar1,(void *)0x0);
    }
    else {
      iVar1 = strcmp(param_2,DAT_000fd95c);
      if (iVar1 == 0) {
        lVar3 = strtol(param_3,(char **)0x0,10);
        pEVar2 = (EVP_MD *)EVP_PKEY_CTX_ctrl(param_1,6,0x18,0x1002,lVar3,(void *)0x0);
      }
      else {
        iVar1 = strcmp(param_2,DAT_000fd960);
        if (iVar1 == 0) {
          lVar3 = strtol(param_3,(char **)0x0,10);
          pEVar2 = (EVP_MD *)EVP_PKEY_CTX_ctrl(param_1,6,4,0x1003,lVar3,(void *)0x0);
        }
        else {
          local_20 = (BIGNUM *)strcmp(param_2,DAT_000fd964);
          if (local_20 == (BIGNUM *)0x0) {
            pEVar2 = (EVP_MD *)BN_asc2bn(&local_20,param_3);
            if ((pEVar2 != (EVP_MD *)0x0) &&
               (pEVar2 = (EVP_MD *)EVP_PKEY_CTX_ctrl(param_1,6,4,0x1004,0,local_20), (int)pEVar2 < 1
               )) {
              BN_free(local_20);
            }
          }
          else {
            iVar1 = strcmp(param_2,DAT_000fd968);
            if (iVar1 == 0) {
              pEVar2 = EVP_get_digestbyname(param_3);
              iVar1 = 0x2b6;
              if (pEVar2 != (EVP_MD *)0x0) {
                pEVar2 = (EVP_MD *)EVP_PKEY_CTX_ctrl(param_1,6,0x3f8,0x1005,0,pEVar2);
                return pEVar2;
              }
            }
            else {
              iVar1 = strcmp(param_2,DAT_000fd96c);
              if (iVar1 != 0) {
                iVar1 = strcmp(param_2,DAT_000fd970);
                if (iVar1 != 0) {
                  return (EVP_MD *)0xfffffffe;
                }
                p2 = string_to_hex(param_3,local_1c);
                if (p2 == (uchar *)0x0) {
                  return (EVP_MD *)0x0;
                }
                pEVar2 = (EVP_MD *)EVP_PKEY_CTX_ctrl(param_1,6,0x300,0x100a,local_1c[0],p2);
                if (0 < (int)pEVar2) {
                  return pEVar2;
                }
                CRYPTO_free(p2);
                return pEVar2;
              }
              pEVar2 = EVP_get_digestbyname(param_3);
              if (pEVar2 != (EVP_MD *)0x0) {
                pEVar2 = (EVP_MD *)EVP_PKEY_CTX_ctrl(param_1,6,0x300,0x1009,0,pEVar2);
                return pEVar2;
              }
              iVar1 = 0x2bf;
              pEVar2 = (EVP_MD *)0x0;
            }
            ERR_put_error(4,0x90,0xa0,DAT_000fd98c,iVar1);
          }
        }
      }
    }
  }
  return pEVar2;
}

