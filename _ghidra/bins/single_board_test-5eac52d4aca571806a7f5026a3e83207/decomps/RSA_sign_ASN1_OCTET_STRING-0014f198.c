
int RSA_sign_ASN1_OCTET_STRING(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  int flen;
  int iVar1;
  uchar *from;
  uint uVar2;
  uint uVar3;
  uint *extraout_r3;
  uint *puVar4;
  uchar *local_34;
  ASN1_OCTET_STRING local_30;
  
  local_30.type = 4;
  local_30.length = m_length;
  local_30.data = m;
  flen = i2d_ASN1_OCTET_STRING(&local_30,(uchar **)0x0);
  iVar1 = RSA_size(rsa);
  if (flen < iVar1 + -10) {
    from = (uchar *)CRYPTO_malloc(iVar1 + 1,"crypto/rsa/rsa_saos.c",0x25);
    if (from == (uchar *)0x0) {
      ERR_put_error(4,0x76,0x41,"crypto/rsa/rsa_saos.c",0x27);
      uVar3 = 0;
    }
    else {
      local_34 = from;
      i2d_ASN1_OCTET_STRING(&local_30,&local_34);
      uVar2 = RSA_private_encrypt(flen,from,sigret,rsa,1);
      puVar4 = extraout_r3;
      if (0 < (int)uVar2) {
        puVar4 = siglen;
      }
      uVar3 = (uint)(0 < (int)uVar2);
      if (0 < (int)uVar2) {
        *puVar4 = uVar2;
      }
      CRYPTO_clear_free(from,iVar1 + 1,"crypto/rsa/rsa_saos.c",0x32);
    }
    return uVar3;
  }
  ERR_put_error(4,0x76,0x70,"crypto/rsa/rsa_saos.c",0x22);
  return 0;
}

