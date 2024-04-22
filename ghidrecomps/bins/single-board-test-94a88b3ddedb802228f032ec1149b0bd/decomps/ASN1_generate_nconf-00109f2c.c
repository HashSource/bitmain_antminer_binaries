
ASN1_TYPE * ASN1_generate_nconf(char *str,CONF *nconf)

{
  ASN1_TYPE *pAVar1;
  CONF *local_28;
  X509V3_CTX XStack_24;
  
  local_28 = nconf;
  if (nconf != (CONF *)0x0) {
    X509V3_set_nconf(&XStack_24,nconf);
    local_28 = (CONF *)0x0;
    nconf = (CONF *)&XStack_24;
  }
  pAVar1 = (ASN1_TYPE *)generate_v3_constprop_2(str,nconf,&local_28);
  if (local_28 != (CONF *)0x0) {
    ERR_put_error(0xd,0xb2,(int)local_28,DAT_00109f68,0x90);
  }
  return pAVar1;
}

