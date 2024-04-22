
long b64_ctrl(BIO *param_1,int param_2,long param_3,void *param_4)

{
  long lVar1;
  uint uVar2;
  int iVar3;
  BIO *bp;
  int iVar4;
  int *outl;
  
  outl = (int *)param_1->ptr;
  if (param_2 == 0xb) {
    iVar4 = *outl;
    iVar3 = outl[1];
    while( true ) {
      while( true ) {
        if (iVar3 != iVar4) {
          do {
            iVar3 = b64_write(param_1,0,0);
            if (iVar3 < 0) {
              return iVar3;
            }
          } while (outl[1] != *outl);
        }
        uVar2 = BIO_test_flags(param_1,-1);
        if ((uVar2 & 0x100) == 0) break;
        if (outl[2] == 0) goto LAB_0012bf3e;
        iVar4 = EVP_EncodeBlock((uchar *)(outl + 0x1f),(uchar *)((int)outl + 0x65a),outl[2]);
        iVar3 = 0;
        *outl = iVar4;
        outl[1] = 0;
        outl[2] = 0;
      }
      if ((outl[4] == 0) || (outl[7] == 0)) break;
      outl[1] = 0;
      EVP_EncodeFinal((EVP_ENCODE_CTX *)(outl + 7),(uchar *)(outl + 0x1f),outl);
      iVar4 = *outl;
      iVar3 = outl[1];
    }
LAB_0012bf3e:
    lVar1 = BIO_ctrl(param_1->next_bio,0xb,param_3,param_4);
    return lVar1;
  }
  if (param_2 < 0xc) {
    if (param_2 != 2) {
      if (param_2 == 10) {
        iVar3 = *outl;
        iVar4 = outl[1];
        if (iVar3 < iVar4) {
          OpenSSLDie(DAT_0012bf74,0x1f9,DAT_0012bf78);
          iVar3 = *outl;
          iVar4 = outl[1];
        }
        if (iVar3 - iVar4 < 1) {
          lVar1 = BIO_ctrl(param_1->next_bio,10,param_3,param_4);
          return lVar1;
        }
        return iVar3 - iVar4;
      }
      if (param_2 == 1) {
        bp = param_1->next_bio;
        outl[6] = 1;
        outl[5] = 1;
        outl[4] = 0;
        lVar1 = BIO_ctrl(bp,1,param_3,param_4);
        return lVar1;
      }
      goto LAB_0012be08;
    }
    if (0 < outl[6]) {
      lVar1 = BIO_ctrl(param_1->next_bio,2,param_3,param_4);
      return lVar1;
    }
  }
  else {
    if (param_2 == 0xd) {
      iVar3 = *outl;
      iVar4 = outl[1];
      if (iVar3 < iVar4) {
        OpenSSLDie(DAT_0012bf74,0x1f0,DAT_0012bf78);
        iVar3 = *outl;
        iVar4 = outl[1];
      }
      iVar3 = iVar3 - iVar4;
      if (iVar3 == 0) {
        if ((outl[4] != 0) && (outl[7] != 0)) {
          return 1;
        }
      }
      else if (0 < iVar3) {
        return iVar3;
      }
      lVar1 = BIO_ctrl(param_1->next_bio,0xd,param_3,param_4);
      return lVar1;
    }
    if (0xc < param_2) {
      if (param_2 == 0x65) {
        BIO_clear_flags(param_1,0xf);
        lVar1 = BIO_ctrl(param_1->next_bio,0x65,param_3,param_4);
        BIO_copy_next_retry(param_1);
        return lVar1;
      }
LAB_0012be08:
      lVar1 = BIO_ctrl(param_1->next_bio,param_2,param_3,param_4);
      return lVar1;
    }
  }
  return 1;
}

