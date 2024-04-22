
undefined4 dh_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  DH *dh;
  ASN1_INTEGER *ai;
  BIGNUM *pBVar2;
  uchar *puStack_28;
  uchar *local_24;
  long local_20;
  int local_1c;
  long *local_18;
  X509_ALGOR *local_14;
  
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&puStack_28,&local_20,&local_14,param_2);
  if (iVar1 != 0) {
    X509_ALGOR_get0((ASN1_OBJECT **)0x0,&local_1c,&local_18,local_14);
    if (local_1c == 0x10) {
      local_24 = (uchar *)local_18[2];
      if (param_1->ameth == DAT_000a5b58) {
        dh = (DH *)d2i_DHxparams();
      }
      else {
        dh = d2i_DHparams((DH **)0x0,&local_24,*local_18);
      }
      if (dh == (DH *)0x0) {
        ERR_put_error(5,0x6c,0x68,DAT_000a5b54,0x7b);
      }
      else {
        ai = d2i_ASN1_INTEGER((ASN1_INTEGER **)0x0,&puStack_28,local_20);
        if (ai == (ASN1_INTEGER *)0x0) {
          ERR_put_error(5,0x6c,0x68,DAT_000a5b54,0x80);
        }
        else {
          pBVar2 = ASN1_INTEGER_to_BN(ai,(BIGNUM *)0x0);
          *(BIGNUM **)&dh->field_0x14 = pBVar2;
          if (pBVar2 != (BIGNUM *)0x0) {
            ASN1_INTEGER_free(ai);
            EVP_PKEY_assign(param_1,*(int *)param_1->ameth,dh);
            return 1;
          }
          ERR_put_error(5,0x6c,0x6d,DAT_000a5b54,0x86);
          ASN1_INTEGER_free(ai);
        }
        DH_free(dh);
      }
    }
    else {
      ERR_put_error(5,0x6c,0x69,DAT_000a5b54,0x72);
    }
  }
  return 0;
}

