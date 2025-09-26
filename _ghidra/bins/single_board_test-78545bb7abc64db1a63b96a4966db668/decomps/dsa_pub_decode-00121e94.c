
undefined4 dsa_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  DSA *ai;
  BIGNUM *pBVar2;
  DSA *r;
  uchar *puStack_28;
  uchar *local_24;
  long local_20;
  int local_1c;
  long *local_18;
  X509_ALGOR *local_14;
  
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&puStack_28,&local_20,&local_14,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_1c,&local_18,local_14);
  if (local_1c == 0x10) {
    local_24 = (uchar *)local_18[2];
    r = d2i_DSAparams((DSA **)0x0,&local_24,*local_18);
    if (r == (DSA *)0x0) {
      ERR_put_error(10,0x75,0x68,"crypto/dsa/dsa_ameth.c",0x2a);
      ai = (DSA *)0x0;
      goto LAB_00121f22;
    }
  }
  else {
    if (local_1c != -1 && local_1c != 5) {
      r = (DSA *)0x0;
      ERR_put_error(10,0x75,0x69,"crypto/dsa/dsa_ameth.c",0x34);
      ai = r;
      goto LAB_00121f22;
    }
    r = DSA_new();
    if (r == (DSA *)0x0) {
      ERR_put_error(10,0x75,0x41,"crypto/dsa/dsa_ameth.c",0x30);
      ai = (DSA *)0x0;
      goto LAB_00121f22;
    }
  }
  ai = (DSA *)d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&puStack_28,local_20);
  if (ai == (DSA *)0x0) {
    ERR_put_error(10,0x75,0x68,"crypto/dsa/dsa_ameth.c",0x39);
  }
  else {
    pBVar2 = ASN1_INTEGER_to_BN((ASN1_INTEGER *)ai,(BIGNUM *)0x0);
    r->g = pBVar2;
    if (pBVar2 != (BIGNUM *)0x0) {
      ASN1_INTEGER_free((ASN1_STRING *)ai);
      EVP_PKEY_assign(param_1,0x74,r);
      return 1;
    }
    ERR_put_error(10,0x75,0x6c,"crypto/dsa/dsa_ameth.c",0x3e);
  }
LAB_00121f22:
  ASN1_INTEGER_free((ASN1_STRING *)ai);
  DSA_free(r);
  return 0;
}

