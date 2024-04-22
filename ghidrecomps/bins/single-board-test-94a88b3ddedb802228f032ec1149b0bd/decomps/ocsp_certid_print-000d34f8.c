
undefined4 ocsp_certid_print(BIO *param_1,undefined4 *param_2,int param_3,undefined4 param_4)

{
  int iVar1;
  
  iVar1 = param_3 + 2;
  BIO_printf(param_1,"%*sCertificate ID:\n",param_3,&DAT_0013a6fc,param_4);
  BIO_printf(param_1,"%*sHash Algorithm: ",iVar1,&DAT_0013a6fc);
  i2a_ASN1_OBJECT(param_1,*(ASN1_OBJECT **)*param_2);
  BIO_printf(param_1,"\n%*sIssuer Name Hash: ",iVar1,&DAT_0013a6fc);
  i2a_ASN1_STRING(param_1,(ASN1_STRING *)param_2[1],4);
  BIO_printf(param_1,"\n%*sIssuer Key Hash: ",iVar1,&DAT_0013a6fc);
  i2a_ASN1_STRING(param_1,(ASN1_STRING *)param_2[2],4);
  BIO_printf(param_1,"\n%*sSerial Number: ",iVar1,&DAT_0013a6fc);
  i2a_ASN1_INTEGER(param_1,(ASN1_INTEGER *)param_2[3]);
  BIO_printf(param_1,"\n");
  return 1;
}

