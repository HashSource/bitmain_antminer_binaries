
undefined4 int_def_cb(char *param_1,size_t param_2,uint *param_3)

{
  int iVar1;
  
  if (param_1 != (char *)0x0) {
    iVar1 = strncmp(param_1,"ALL",param_2);
    if (iVar1 == 0) {
      *param_3 = ~(~(*param_3 >> 0x10) << 0x10);
      return 1;
    }
    iVar1 = strncmp(param_1,"RSA",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 1;
      return 1;
    }
    iVar1 = strncmp(param_1,"DSA",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 2;
      return 1;
    }
    iVar1 = strncmp(param_1,"ECDH",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x10;
      return 1;
    }
    iVar1 = strncmp(param_1,"ECDSA",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x20;
      return 1;
    }
    iVar1 = strncmp(param_1,"DH",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 4;
      return 1;
    }
    iVar1 = strncmp(param_1,"RAND",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 8;
      return 1;
    }
    iVar1 = strncmp(param_1,"CIPHERS",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x40;
      return 1;
    }
    iVar1 = strncmp(param_1,"DIGESTS",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x80;
      return 1;
    }
    iVar1 = strncmp(param_1,"PKEY",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x600;
      return 1;
    }
    iVar1 = strncmp(param_1,"PKEY_CRYPTO",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x200;
      return 1;
    }
    iVar1 = strncmp(param_1,"PKEY_ASN1",param_2);
    if (iVar1 == 0) {
      *param_3 = *param_3 | 0x400;
      return 1;
    }
  }
  return 0;
}

