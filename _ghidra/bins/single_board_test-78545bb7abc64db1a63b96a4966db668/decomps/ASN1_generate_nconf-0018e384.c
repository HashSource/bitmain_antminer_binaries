
ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  ASN1_TYPE *pAVar1;
  X509V3_CTX *ctx;
  X509V3_CTX XStack_2c;
  
  ctx = (X509V3_CTX *)nconf;
  if (nconf != (CONF *)0x0) {
    ctx = &XStack_2c;
    X509V3_set_nconf(ctx,nconf);
  }
  pAVar1 = ASN1_generate_v3(str,ctx);
  return pAVar1;
}

