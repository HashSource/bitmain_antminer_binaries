
size_t md_write(BIO *param_1,void *param_2,int param_3)

{
  EVP_MD_CTX *ctx;
  BIO *b;
  size_t sVar1;
  size_t sVar2;
  int iVar3;
  size_t unaff_r5;
  size_t cnt;
  bool bVar4;
  bool bVar5;
  
  bVar4 = (int)param_2 < 0;
  bVar5 = param_2 != (void *)0x0;
  if (bVar5) {
    bVar4 = param_3 < 0;
  }
  if ((!bVar5 || param_3 == 0) || bVar4) {
    unaff_r5 = 0;
  }
  if ((bVar5 && param_3 != 0) && !bVar4) {
    ctx = (EVP_MD_CTX *)BIO_get_data();
    b = BIO_next(param_1);
    if (ctx == (EVP_MD_CTX *)0x0 || b == (BIO *)0x0) {
      cnt = 0;
      BIO_get_init(param_1);
      if (b != (BIO *)0x0) {
LAB_001b4170:
        BIO_clear_flags(param_1,0xf);
        BIO_copy_next_retry(param_1);
        return cnt;
      }
      unaff_r5 = 0;
    }
    else {
      cnt = BIO_write(b,param_2,param_3);
      sVar1 = BIO_get_init(param_1);
      sVar2 = sVar1;
      if (sVar1 != 0) {
        sVar2 = cnt;
      }
      if (((sVar1 == 0 || cnt == 0) || (int)sVar2 < 0) ||
         (iVar3 = EVP_DigestUpdate(ctx,param_2,cnt), iVar3 != 0)) goto LAB_001b4170;
      BIO_clear_flags(param_1,0xf);
      unaff_r5 = 0;
    }
  }
  return unaff_r5;
}

