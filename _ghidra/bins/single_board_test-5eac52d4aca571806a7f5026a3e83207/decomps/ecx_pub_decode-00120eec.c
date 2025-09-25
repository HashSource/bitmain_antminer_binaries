
undefined4 ecx_pub_decode(EVP_PKEY *param_1,X509_PUBKEY *param_2)

{
  int iVar1;
  void *__dest;
  size_t sVar2;
  uchar *local_30;
  size_t local_2c;
  X509_ALGOR *local_28;
  int local_24 [2];
  
  iVar1 = X509_PUBKEY_get0_param((ASN1_OBJECT **)0x0,&local_30,(int *)&local_2c,&local_28,param_2);
  if (iVar1 == 0) {
    return 0;
  }
  iVar1 = *(int *)param_1->ameth;
  if ((local_28 == (X509_ALGOR *)0x0) ||
     (X509_ALGOR_get0((ASN1_OBJECT **)0x0,local_24,(void **)0x0,local_28), local_24[0] == -1)) {
    if (local_30 != (uchar *)0x0) {
      if (iVar1 == 0x40a || iVar1 == 0x43f) {
        sVar2 = 0x20;
      }
      else if (iVar1 == 0x40b) {
        sVar2 = 0x38;
      }
      else {
        sVar2 = 0x39;
      }
      if (local_2c == sVar2) {
        __dest = (void *)CRYPTO_zalloc(0x40,"crypto/ec/ecx_meth.c",0x46);
        if (__dest != (void *)0x0) {
          memcpy(__dest,local_30,local_2c);
          EVP_PKEY_assign(param_1,iVar1,__dest);
          return 1;
        }
        ERR_put_error(0x10,0x10a,0x41,"crypto/ec/ecx_meth.c",0x48);
        return 0;
      }
    }
    iVar1 = 0x41;
  }
  else {
    iVar1 = 0x3b;
  }
  ERR_put_error(0x10,0x10a,0x66,"crypto/ec/ecx_meth.c",iVar1);
  return 0;
}

