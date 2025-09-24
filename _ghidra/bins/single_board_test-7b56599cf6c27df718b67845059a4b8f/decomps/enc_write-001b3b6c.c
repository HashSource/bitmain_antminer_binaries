
int enc_write(BIO *param_1,uchar *param_2,int param_3)

{
  int *outl;
  BIO *b;
  int iVar1;
  int iVar2;
  int iVar3;
  int *data;
  int iVar4;
  bool bVar5;
  
  outl = (int *)BIO_get_data();
  b = BIO_next(param_1);
  if (b != (BIO *)0x0 && outl != (int *)0x0) {
    BIO_clear_flags(param_1,0xf);
    iVar2 = outl[1];
    iVar4 = *outl - iVar2;
    while (0 < iVar4) {
      iVar2 = BIO_write(b,(void *)(iVar2 + 0x20 + (int)outl),iVar4);
      iVar4 = iVar4 - iVar2;
      if (iVar2 < 1) {
        BIO_copy_next_retry(param_1);
        return iVar2;
      }
      iVar2 = outl[1] + iVar2;
      outl[1] = iVar2;
    }
    bVar5 = (int)param_2 < 0;
    if (param_2 != (uchar *)0x0) {
      bVar5 = param_3 < 0;
    }
    if ((param_2 != (uchar *)0x0 && param_3 != 0) && !bVar5) {
      outl[1] = 0;
      iVar2 = param_3;
      do {
        iVar4 = iVar2;
        if (0xfff < iVar2) {
          iVar4 = 0x1000;
        }
        iVar1 = EVP_CipherUpdate((EVP_CIPHER_CTX *)outl[5],(uchar *)(outl + 8),outl,param_2,iVar4);
        if (iVar1 == 0) {
          BIO_clear_flags(param_1,0xf);
          outl[4] = 0;
          return 0;
        }
        iVar1 = *outl;
        iVar2 = iVar2 - iVar4;
        param_2 = param_2 + iVar4;
        outl[1] = 0;
        data = outl + 8;
        if (0 < iVar1) {
          while( true ) {
            iVar4 = BIO_write(b,data,iVar1);
            iVar1 = iVar1 - iVar4;
            if (iVar4 < 1) {
              BIO_copy_next_retry(param_1);
              if (param_3 == iVar2) {
                return iVar4;
              }
              return param_3 - iVar2;
            }
            iVar3 = outl[1];
            outl[1] = iVar4 + iVar3;
            if (iVar1 < 1) break;
            data = (int *)((int)outl + iVar4 + iVar3 + 0x20);
          }
        }
        *outl = 0;
        outl[1] = 0;
      } while (0 < iVar2);
      BIO_copy_next_retry(param_1);
      return param_3;
    }
  }
  return 0;
}

