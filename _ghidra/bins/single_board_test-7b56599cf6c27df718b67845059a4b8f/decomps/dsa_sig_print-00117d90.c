
uint dsa_sig_print(BIO *param_1,undefined4 param_2,ASN1_STRING *param_3,int param_4)

{
  DSA_SIG *a;
  int iVar1;
  uint uVar2;
  uchar *local_24;
  BIGNUM *local_20;
  BIGNUM *local_1c [2];
  
  if (param_3 == (ASN1_STRING *)0x0) {
    iVar1 = BIO_puts(param_1,"\n");
    return (uint)(0 < iVar1);
  }
  local_24 = param_3->data;
  a = d2i_DSA_SIG((DSA_SIG **)0x0,&local_24,param_3->length);
  if (a != (DSA_SIG *)0x0) {
    DSA_SIG_get0(a,&local_20,local_1c);
    iVar1 = BIO_write(param_1,"\n",1);
    if ((iVar1 == 1) &&
       (iVar1 = ASN1_bn_print(param_1,"r:   ",local_20,(uchar *)0x0,param_4), iVar1 != 0)) {
      uVar2 = ASN1_bn_print(param_1,"s:   ",local_1c[0],(uchar *)0x0,param_4);
      if (uVar2 != 0) {
        uVar2 = 1;
      }
    }
    else {
      uVar2 = 0;
    }
    DSA_SIG_free(a);
    return uVar2;
  }
  uVar2 = X509_signature_dump(param_1,param_3,param_4);
  return uVar2;
}

