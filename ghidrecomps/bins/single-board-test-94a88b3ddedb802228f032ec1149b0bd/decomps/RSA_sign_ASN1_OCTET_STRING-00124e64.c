
int RSA_sign_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  int flen;
  int iVar1;
  uchar *from;
  uint uVar2;
  uchar *local_34;
  ASN1_OCTET_STRING local_30;
  
  local_30.type = 4;
  local_30.length = m_length;
  local_30.data = m;
  flen = i2d_ASN1_OCTET_STRING(&local_30,(uchar **)0x0);
  iVar1 = RSA_size(rsa);
  if (flen < iVar1 + -10) {
    from = (uchar *)CRYPTO_malloc(iVar1 + 1U,DAT_00124f0c,0x56);
    if (from == (uchar *)0x0) {
      ERR_put_error(4,0x76,0x41,DAT_00124f0c,0x58);
      uVar2 = 0;
    }
    else {
      local_34 = from;
      i2d_ASN1_OCTET_STRING(&local_30,&local_34);
      uVar2 = RSA_private_encrypt(flen,from,sigret,rsa,1);
      if (0 < (int)uVar2) {
        *siglen = uVar2;
      }
      uVar2 = (uint)(0 < (int)uVar2);
      OPENSSL_cleanse(from,iVar1 + 1U);
      CRYPTO_free(from);
    }
  }
  else {
    ERR_put_error(4,0x76,0x70,DAT_00124f0c,0x53);
    uVar2 = 0;
  }
  return uVar2;
}

