
ASN1_STRING * asn1_time_from_tm(ASN1_STRING *param_1,undefined4 *param_2,int param_3)

{
  int iVar1;
  
  if (param_3 != -1) {
    if (param_3 == 0x17) {
      if (param_2[5] - 0x32 < 100) goto joined_r0x0017ec2a;
    }
    else if (param_3 == 0x18) goto joined_r0x0017ec2a;
    if (param_1 == (ASN1_STRING *)0x0) {
      return (ASN1_STRING *)0x0;
    }
    param_1 = (ASN1_STRING *)0x0;
LAB_0017eba6:
    ASN1_STRING_free(param_1);
    return (ASN1_STRING *)0x0;
  }
  if (param_2[5] - 0x32 < 100) {
    param_3 = 0x17;
  }
  else {
    param_3 = 0x18;
  }
joined_r0x0017ec2a:
  if (param_1 == (ASN1_STRING *)0x0) {
    param_1 = ASN1_STRING_new();
    if (param_1 == (ASN1_STRING *)0x0) {
      return (ASN1_STRING *)0x0;
    }
    iVar1 = ASN1_STRING_set(param_1,(void *)0x0,0x14);
    if (iVar1 == 0) goto LAB_0017eba6;
  }
  else {
    iVar1 = ASN1_STRING_set(param_1,(void *)0x0,0x14);
    if (iVar1 == 0) {
      return (ASN1_STRING *)0x0;
    }
  }
  param_1->type = param_3;
  if (param_3 != 0x18) {
    iVar1 = BIO_snprintf((char *)param_1->data,0x14,"%02d%02d%02d%02d%02d%02dZ",
                         (int)param_2[5] % 100,param_2[4] + 1,param_2[3],param_2[2],param_2[1],
                         *param_2);
    param_1->length = iVar1;
    return param_1;
  }
  iVar1 = BIO_snprintf((char *)param_1->data,0x14,"%04d%02d%02d%02d%02d%02dZ",param_2[5] + 0x76c,
                       param_2[4] + 1,param_2[3],param_2[2],param_2[1],*param_2);
  param_1->length = iVar1;
  return param_1;
}

