
int enc_write(BIO *param_1,uchar *param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int *outl;
  int iVar3;
  int len;
  bool bVar4;
  bool bVar5;
  
  outl = (int *)param_1->ptr;
  BIO_clear_flags(param_1,0xf);
  iVar1 = outl[1];
  iVar2 = *outl;
  iVar3 = iVar2 - iVar1;
  while( true ) {
    if (iVar3 < 1) {
      bVar4 = (int)param_2 < 0;
      bVar5 = param_2 == (uchar *)0x0;
      if (!bVar5) {
        bVar4 = param_3 < 0;
      }
      if ((!bVar5 && param_3 != 0) && !bVar4) {
        iVar2 = 0;
      }
      if ((bVar5 || param_3 == 0) || bVar4) {
        param_3 = 0;
      }
      else {
        outl[1] = iVar2;
        iVar1 = param_3;
        do {
          iVar3 = iVar1;
          if (0xfff < iVar1) {
            iVar3 = 0x1000;
          }
          EVP_CipherUpdate((EVP_CIPHER_CTX *)(outl + 5),(uchar *)(outl + 0x28),outl,param_2,iVar3);
          len = *outl;
          iVar1 = iVar1 - iVar3;
          param_2 = param_2 + iVar3;
          outl[1] = iVar2;
          if (0 < len) {
            iVar3 = 0;
            do {
              iVar3 = BIO_write(param_1->next_bio,(void *)((int)outl + iVar3 + 0xa0),len);
              len = len - iVar3;
              if (iVar3 < 1) {
                BIO_copy_next_retry(param_1);
                if (param_3 == iVar1) {
                  return iVar3;
                }
                return param_3 - iVar1;
              }
              iVar3 = iVar3 + outl[1];
              outl[1] = iVar3;
            } while (0 < len);
          }
          *outl = iVar2;
          outl[1] = iVar2;
        } while (0 < iVar1);
        BIO_copy_next_retry(param_1);
      }
      return param_3;
    }
    iVar1 = BIO_write(param_1->next_bio,(void *)((int)outl + iVar1 + 0xa0),iVar3);
    iVar3 = iVar3 - iVar1;
    if (iVar1 < 1) break;
    iVar2 = outl[1];
    iVar1 = iVar1 + iVar2;
    outl[1] = iVar1;
  }
  BIO_copy_next_retry(param_1);
  return iVar1;
}

