
int enc_ctrl(BIO *param_1,int param_2,long param_3,int *param_4)

{
  int *outl;
  BIO *bp;
  int iVar1;
  long lVar2;
  EVP_CIPHER_CTX *pEVar3;
  
  outl = (int *)BIO_get_data();
  bp = BIO_next(param_1);
  if (outl == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0xc) {
    iVar1 = BIO_get_data(param_4);
    pEVar3 = EVP_CIPHER_CTX_new();
    *(EVP_CIPHER_CTX **)(iVar1 + 0x14) = pEVar3;
    if (pEVar3 == (EVP_CIPHER_CTX *)0x0) {
      return 0;
    }
    iVar1 = EVP_CIPHER_CTX_copy(pEVar3,(EVP_CIPHER_CTX *)outl[5]);
    if (iVar1 == 0) {
      return 0;
    }
    BIO_set_init(param_4,1);
    return iVar1;
  }
  if (param_2 < 0xd) {
    if (param_2 == 2) {
      if (outl[2] < 1) {
        return 1;
      }
      goto LAB_001afafe;
    }
    if (param_2 < 3) {
      if (param_2 == 1) {
        pEVar3 = (EVP_CIPHER_CTX *)outl[5];
        outl[4] = 1;
        outl[3] = 0;
        iVar1 = EVP_CIPHER_CTX_encrypting(pEVar3);
        iVar1 = EVP_CipherInit_ex(pEVar3,(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,(uchar *)0x0,
                                  iVar1);
        if (iVar1 == 0) {
          return 0;
        }
      }
      goto LAB_001afb4c;
    }
    if (param_2 != 10) {
      if (param_2 == 0xb) {
        while( true ) {
          while (*outl != outl[1]) {
            iVar1 = enc_write(param_1,0);
            if (iVar1 < 0) {
              return iVar1;
            }
          }
          if (outl[3] != 0) break;
          outl[3] = 1;
          outl[1] = 0;
          iVar1 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)outl[5],(uchar *)(outl + 8),outl);
          outl[4] = iVar1;
          if (iVar1 < 1) {
            return iVar1;
          }
        }
        param_2 = 0xb;
        goto LAB_001afafe;
      }
      goto LAB_001afb4c;
    }
  }
  else {
    if (param_2 == 0x65) {
      BIO_clear_flags(param_1,0xf);
      lVar2 = BIO_ctrl(bp,0x65,param_3,param_4);
      BIO_copy_next_retry(param_1);
      return lVar2;
    }
    if (0x65 < param_2) {
      if (param_2 == 0x71) {
        return outl[4];
      }
      if (param_2 == 0x81) {
        *param_4 = outl[5];
        BIO_set_init(param_1,1);
        return 1;
      }
LAB_001afb4c:
      iVar1 = BIO_ctrl(bp,param_2,param_3,param_4);
      return iVar1;
    }
    if (param_2 != 0xd) goto LAB_001afb4c;
  }
  if (0 < *outl - outl[1]) {
    return *outl - outl[1];
  }
LAB_001afafe:
  iVar1 = BIO_ctrl(bp,param_2,param_3,param_4);
  return iVar1;
}

