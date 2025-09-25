
undefined4 * mime_hdr_new(char *param_1,char *param_2)

{
  char *pcVar1;
  char cVar2;
  undefined4 *ptr;
  int iVar3;
  
  if (param_1 != (char *)0x0) {
    param_1 = CRYPTO_strdup(param_1,"crypto/asn1/asn_mime.c",0x325);
    if (param_1 == (char *)0x0) {
      return (undefined4 *)0x0;
    }
    cVar2 = *param_1;
    pcVar1 = param_1;
    while (cVar2 != '\0') {
      cVar2 = ossl_tolower();
      *pcVar1 = cVar2;
      pcVar1 = pcVar1 + 1;
      cVar2 = *pcVar1;
    }
  }
  if (param_2 != (char *)0x0) {
    param_2 = CRYPTO_strdup(param_2,"crypto/asn1/asn_mime.c",0x32b);
    if (param_2 == (char *)0x0) {
      ptr = (undefined4 *)0x0;
      goto LAB_001c5386;
    }
    cVar2 = *param_2;
    pcVar1 = param_2;
    while (cVar2 != '\0') {
      cVar2 = ossl_tolower();
      *pcVar1 = cVar2;
      pcVar1 = pcVar1 + 1;
      cVar2 = *pcVar1;
    }
  }
  ptr = (undefined4 *)CRYPTO_malloc(0xc,"crypto/asn1/asn_mime.c",0x330);
  if (ptr != (undefined4 *)0x0) {
    *ptr = param_1;
    ptr[1] = param_2;
    iVar3 = OPENSSL_sk_new(0x1c5125);
    ptr[2] = iVar3;
    if (iVar3 != 0) {
      return ptr;
    }
  }
LAB_001c5386:
  CRYPTO_free(param_1);
  CRYPTO_free(param_2);
  CRYPTO_free(ptr);
  return (undefined4 *)0x0;
}

