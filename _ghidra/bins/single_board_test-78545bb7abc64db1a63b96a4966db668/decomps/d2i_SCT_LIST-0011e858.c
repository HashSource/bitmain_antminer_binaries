
ASN1_OCTET_STRING * d2i_SCT_LIST(undefined4 param_1,int *param_2,long param_3)

{
  ASN1_OCTET_STRING *pAVar1;
  ASN1_OCTET_STRING *local_20;
  uchar *local_1c [2];
  
  local_1c[0] = (uchar *)*param_2;
  local_20 = (ASN1_STRING *)0x0;
  pAVar1 = d2i_ASN1_OCTET_STRING(&local_20,local_1c,param_3);
  if (pAVar1 != (ASN1_OCTET_STRING *)0x0) {
    local_1c[0] = local_20->data;
    pAVar1 = (ASN1_OCTET_STRING *)o2i_SCT_LIST(param_1,local_1c,local_20->length);
    if (pAVar1 != (ASN1_OCTET_STRING *)0x0) {
      *param_2 = param_3 + *param_2;
    }
    ASN1_OCTET_STRING_free(local_20);
  }
  return pAVar1;
}

