
ASN1_TYPE * ASN1_generate_v3(char *str,X509V3_CTX *cnf)

{
  ASN1_TYPE *pAVar1;
  int local_c;
  
  local_c = 0;
  pAVar1 = (ASN1_TYPE *)generate_v3_constprop_2(str,cnf,&local_c);
  if (local_c != 0) {
    ERR_put_error(0xd,0xb2,local_c,DAT_00109f98,0x90);
  }
  return pAVar1;
}

