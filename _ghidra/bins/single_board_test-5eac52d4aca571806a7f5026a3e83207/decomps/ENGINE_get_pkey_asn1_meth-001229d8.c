
EVP_PKEY_ASN1_METHOD * ENGINE_get_pkey_asn1_meth(ENGINE *e,int nid)

{
  ENGINE_PKEY_ASN1_METHS_PTR pEVar1;
  int iVar2;
  EVP_PKEY_ASN1_METHOD *local_14;
  
  pEVar1 = ENGINE_get_pkey_asn1_meths(e);
  if ((pEVar1 != (ENGINE_PKEY_ASN1_METHS_PTR)0x0) &&
     (iVar2 = (*pEVar1)(e,&local_14,(int **)0x0,nid), iVar2 != 0)) {
    return local_14;
  }
  ERR_put_error(0x26,0xc1,0x65,"crypto/engine/tb_asnmth.c",0x59);
  return (EVP_PKEY_ASN1_METHOD *)0x0;
}

