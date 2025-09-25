
long b64_ctrl(BIO *param_1,int param_2,long param_3,void *param_4)

{
  int *outl;
  BIO *bp;
  long lVar1;
  int iVar2;
  uint uVar3;
  int iVar4;
  
  outl = (int *)BIO_get_data();
  bp = BIO_next(param_1);
  if (bp == (BIO *)0x0 || outl == (int *)0x0) {
    return 0;
  }
  if (param_2 == 0xb) {
    iVar2 = *outl;
    iVar4 = outl[1];
    while( true ) {
      while( true ) {
        if (iVar4 != iVar2) {
          do {
            iVar2 = b64_write(param_1,0);
            if (iVar2 < 0) {
              return iVar2;
            }
          } while (outl[1] != *outl);
        }
        uVar3 = BIO_test_flags(param_1,-1);
        if ((uVar3 & 0x100) != 0) break;
        if ((outl[4] == 0) || (iVar2 = EVP_ENCODE_CTX_num(outl[7]), iVar2 == 0)) goto LAB_001d0c5a;
        outl[1] = 0;
        EVP_EncodeFinal((EVP_ENCODE_CTX *)outl[7],(uchar *)(outl + 8),outl);
        iVar2 = *outl;
        iVar4 = outl[1];
      }
      if (outl[2] == 0) break;
      iVar2 = EVP_EncodeBlock((uchar *)(outl + 8),(uchar *)((int)outl + 0x5fe),outl[2]);
      iVar4 = 0;
      *outl = iVar2;
      outl[1] = 0;
      outl[2] = 0;
    }
LAB_001d0c5a:
    lVar1 = BIO_ctrl(bp,0xb,param_3,param_4);
    return lVar1;
  }
  if (0xb < param_2) {
    if (param_2 == 0xd) {
      if (*outl < outl[1]) {
                    /* WARNING: Subroutine does not return */
        OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",0x1da);
      }
      iVar2 = *outl - outl[1];
      if (iVar2 != 0) {
        return iVar2;
      }
      if ((outl[4] == 0) || (iVar2 = EVP_ENCODE_CTX_num(outl[7]), iVar2 == 0)) {
        lVar1 = BIO_ctrl(bp,0xd,param_3,param_4);
        return lVar1;
      }
    }
    else if (0xc < param_2) {
      if (param_2 == 0x65) {
        BIO_clear_flags(param_1,0xf);
        lVar1 = BIO_ctrl(bp,0x65,param_3,param_4);
        BIO_copy_next_retry(param_1);
        return lVar1;
      }
LAB_001d0b6a:
      lVar1 = BIO_ctrl(bp,param_2,param_3,param_4);
      return lVar1;
    }
    return 1;
  }
  if (param_2 == 2) {
    if (outl[6] < 1) {
      return 1;
    }
  }
  else {
    if (param_2 != 10) {
      if (param_2 == 1) {
        outl[4] = 0;
        outl[6] = 1;
        outl[5] = 1;
        lVar1 = BIO_ctrl(bp,1,param_3,param_4);
        return lVar1;
      }
      goto LAB_001d0b6a;
    }
    if (*outl < outl[1]) {
                    /* WARNING: Subroutine does not return */
      OPENSSL_die("assertion failed: ctx->buf_len >= ctx->buf_off","crypto/evp/bio_b64.c",0x1e3);
    }
    iVar2 = *outl - outl[1];
    if (iVar2 != 0) {
      return iVar2;
    }
  }
  lVar1 = BIO_ctrl(bp,param_2,param_3,param_4);
  return lVar1;
}

