
undefined4 bitstr_cb(char *param_1,int param_2,ASN1_BIT_STRING *param_3)

{
  ulong n;
  int iVar1;
  char *local_14;
  
  if (param_1 != (char *)0x0) {
    n = strtoul(param_1,&local_14,10);
    if (((local_14 == (char *)0x0) || (*local_14 == '\0')) || (local_14 == param_1 + param_2)) {
      if (-1 < (int)n) {
        iVar1 = ASN1_BIT_STRING_set_bit(param_3,n,1);
        if (iVar1 != 0) {
          return 1;
        }
        ERR_put_error(0xd,0xb4,0x41,"crypto/asn1/asn1_gen.c",0x2f7);
        return 0;
      }
      ERR_put_error(0xd,0xb4,0xbb,"crypto/asn1/asn1_gen.c",0x2f3);
    }
  }
  return 0;
}

