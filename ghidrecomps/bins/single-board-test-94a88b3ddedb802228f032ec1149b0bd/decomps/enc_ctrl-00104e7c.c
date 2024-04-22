
int enc_ctrl(BIO *param_1,int param_2,long param_3,int **param_4)

{
  int iVar1;
  long lVar2;
  int *piVar3;
  int *outl;
  
  outl = (int *)param_1->ptr;
  if (param_2 == 0xc) {
    piVar3 = param_4[8];
    EVP_CIPHER_CTX_init((EVP_CIPHER_CTX *)(piVar3 + 5));
    iVar1 = EVP_CIPHER_CTX_copy((EVP_CIPHER_CTX *)(piVar3 + 5),(EVP_CIPHER_CTX *)(outl + 5));
    if (iVar1 == 0) {
      return 0;
    }
    param_4[3] = (int *)0x1;
    return iVar1;
  }
  if (param_2 < 0xd) {
    if (param_2 == 2) {
      if (outl[2] < 1) {
        return 1;
      }
      goto LAB_00104f34;
    }
    if (param_2 < 3) {
      if (param_2 == 1) {
        outl[4] = 1;
        outl[3] = 0;
        EVP_CipherInit_ex((EVP_CIPHER_CTX *)(outl + 5),(EVP_CIPHER *)0x0,(ENGINE *)0x0,(uchar *)0x0,
                          (uchar *)0x0,outl[7]);
      }
      goto LAB_00104efa;
    }
    if (param_2 != 10) {
      if (param_2 == 0xb) {
        while( true ) {
          while (*outl != outl[1]) {
            iVar1 = enc_write(param_1,0,0);
            if (iVar1 < 0) {
              return iVar1;
            }
          }
          if (outl[3] != 0) break;
          outl[3] = 1;
          outl[1] = 0;
          iVar1 = EVP_CipherFinal_ex((EVP_CIPHER_CTX *)(outl + 5),(uchar *)(outl + 0x28),outl);
          outl[4] = iVar1;
          if (iVar1 < 1) {
            return iVar1;
          }
        }
        iVar1 = BIO_ctrl(param_1->next_bio,0xb,param_3,param_4);
        return iVar1;
      }
      goto LAB_00104efa;
    }
  }
  else {
    if (param_2 == 0x65) {
      BIO_clear_flags(param_1,0xf);
      lVar2 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
      BIO_copy_next_retry(param_1);
      return lVar2;
    }
    if (0x65 < param_2) {
      if (param_2 == 0x71) {
        return outl[4];
      }
      if (param_2 == 0x81) {
        *param_4 = outl + 5;
        param_1->init = 1;
        return 1;
      }
LAB_00104efa:
      iVar1 = BIO_ctrl(param_1->next_bio,param_2,param_3,param_4);
      return iVar1;
    }
    if (param_2 != 0xd) goto LAB_00104efa;
  }
  if (0 < *outl - outl[1]) {
    return *outl - outl[1];
  }
LAB_00104f34:
  iVar1 = BIO_ctrl(param_1->next_bio,param_2,param_3,param_4);
  return iVar1;
}

