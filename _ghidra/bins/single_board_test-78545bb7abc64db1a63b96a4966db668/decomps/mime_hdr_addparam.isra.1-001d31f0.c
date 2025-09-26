
undefined4 mime_hdr_addparam_isra_1(undefined4 *param_1,char *param_2,char *param_3)

{
  char *pcVar1;
  char cVar2;
  char *ptr;
  undefined4 *ptr_00;
  int iVar3;
  
  if (param_2 == (char *)0x0) {
    ptr = (char *)0x0;
  }
  else {
    ptr = CRYPTO_strdup(param_2,"crypto/asn1/asn_mime.c",0x346);
    if (ptr == (char *)0x0) {
      param_3 = (char *)0x0;
      ptr_00 = (undefined4 *)0x0;
      goto LAB_001d3256;
    }
    cVar2 = *ptr;
    pcVar1 = ptr;
    while (cVar2 != '\0') {
      cVar2 = ossl_tolower();
      *pcVar1 = cVar2;
      pcVar1 = pcVar1 + 1;
      cVar2 = *pcVar1;
    }
  }
  if ((param_3 == (char *)0x0) ||
     (param_3 = CRYPTO_strdup(param_3,"crypto/asn1/asn_mime.c",0x34d), param_3 != (char *)0x0)) {
    ptr_00 = (undefined4 *)CRYPTO_malloc(8,"crypto/asn1/asn_mime.c",0x352);
    if (ptr_00 != (undefined4 *)0x0) {
      *ptr_00 = ptr;
      ptr_00[1] = param_3;
      iVar3 = OPENSSL_sk_push(*param_1,ptr_00);
      if (iVar3 != 0) {
        return 1;
      }
    }
  }
  else {
    ptr_00 = (undefined4 *)0x0;
  }
LAB_001d3256:
  CRYPTO_free(ptr);
  CRYPTO_free(param_3);
  CRYPTO_free(ptr_00);
  return 0;
}

