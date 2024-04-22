
int RSA_sign(int type,uchar *m,uint m_length,uchar *sigret,uint *siglen,RSA *rsa)

{
  int iVar1;
  int flen;
  uint uVar2;
  _func_1768 *p_Var3;
  uchar *ptr;
  uchar *local_54;
  X509_SIG local_50;
  ASN1_TYPE local_48;
  X509_ALGOR local_40;
  ASN1_OCTET_STRING local_38;
  
  if (((rsa->flags & 0x40U) != 0) && (p_Var3 = rsa->meth->rsa_sign, p_Var3 != (_func_1768 *)0x0)) {
    iVar1 = (*p_Var3)(type,m,m_length,sigret,siglen,rsa);
    return iVar1;
  }
  if (type == 0x72) {
    if (m_length != 0x24) {
      ERR_put_error(4,0x75,0x83,DAT_000a40e0,0x5d);
      return 0;
    }
    iVar1 = RSA_size(rsa);
    if (iVar1 < 0x2f) goto LAB_000a40a2;
    ptr = (uchar *)0x0;
    flen = 0x24;
  }
  else {
    local_50.algor = &local_40;
    local_40.algorithm = OBJ_nid2obj(type);
    if ((local_50.algor)->algorithm == (ASN1_OBJECT *)0x0) {
      ERR_put_error(4,0x75,0x75,DAT_000a40e0,0x66);
      return 0;
    }
    if ((local_50.algor)->algorithm->length == 0) {
      ERR_put_error(4,0x75,0x74,DAT_000a40e0,0x6b);
      return 0;
    }
    local_48.value.ptr = (char *)0x0;
    (local_50.algor)->parameter = &local_48;
    local_50.digest = &local_38;
    local_48.type = 5;
    local_38.length = m_length;
    local_38.data = m;
    flen = i2d_X509_SIG(&local_50,(uchar **)0x0);
    iVar1 = RSA_size(rsa);
    if (iVar1 + -10 <= flen) {
LAB_000a40a2:
      ERR_put_error(4,0x75,0x70,DAT_000a40e0,0x7a);
      return 0;
    }
    m = (uchar *)CRYPTO_malloc(iVar1 + 1,DAT_000a40e0,0x7e);
    if (m == (uchar *)0x0) {
      ERR_put_error(4,0x75,0x41,DAT_000a40e0,0x80);
      return 0;
    }
    local_54 = m;
    i2d_X509_SIG(&local_50,&local_54);
    ptr = m;
  }
  uVar2 = RSA_private_encrypt(flen,m,sigret,rsa,1);
  if (0 < (int)uVar2) {
    *siglen = uVar2;
  }
  if (type != 0x72) {
    OPENSSL_cleanse(ptr,iVar1 + 1);
    CRYPTO_free(ptr);
  }
  return (uint)(0 < (int)uVar2);
}

