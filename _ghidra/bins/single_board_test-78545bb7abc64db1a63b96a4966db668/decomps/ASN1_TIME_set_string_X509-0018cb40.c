
int ASN1_TIME_set_string_X509(ASN1_STRING *param_1,uchar *param_2)

{
  int iVar1;
  ASN1_TIME local_4c;
  undefined1 auStack_3c [20];
  int local_28;
  
  local_4c.length = strlen((char *)param_2);
  local_4c.flags = 0x100;
  local_4c.type = 0x17;
  local_4c.data = param_2;
  iVar1 = ASN1_TIME_check(&local_4c);
  if (iVar1 == 0) {
    local_4c.type = 0x18;
    iVar1 = ASN1_TIME_check(&local_4c);
    if (iVar1 == 0) {
      return 0;
    }
  }
  if (param_1 == (ASN1_STRING *)0x0) {
    iVar1 = 1;
  }
  else {
    if (local_4c.type == 0x18) {
      iVar1 = asn1_time_to_tm(auStack_3c,&local_4c);
      if (iVar1 == 0) {
        return 0;
      }
      if (local_28 - 0x32U < 100) {
        iVar1 = local_4c.length - 1;
        local_4c.length = local_4c.length - 2;
        local_4c.data = (uchar *)CRYPTO_zalloc(iVar1,"crypto/asn1/a_time.c",0x1a4);
        if (local_4c.data == (uchar *)0x0) {
          return 0;
        }
        memcpy(local_4c.data,param_2 + 2,local_4c.length);
        local_4c.type = 0x17;
      }
    }
    iVar1 = ASN1_STRING_copy(param_1,&local_4c);
    if (iVar1 != 0) {
      iVar1 = 1;
    }
  }
  if (param_2 != local_4c.data) {
    CRYPTO_free(local_4c.data);
  }
  return iVar1;
}

