
PKCS7_ISSUER_AND_SERIAL * PKCS7_get_issuer_and_serial(PKCS7 *p7,int idx)

{
  int iVar1;
  stack_st_PKCS7_RECIP_INFO *psVar2;
  
  iVar1 = OBJ_obj2nid(p7->type);
  if ((((iVar1 == 0x18) && ((p7->d).signed_and_enveloped != (PKCS7_SIGN_ENVELOPE *)0x0)) &&
      (psVar2 = ((p7->d).signed_and_enveloped)->recipientinfo,
      psVar2 != (stack_st_PKCS7_RECIP_INFO *)0x0)) && (iVar1 = OPENSSL_sk_num(psVar2), idx < iVar1))
  {
    iVar1 = OPENSSL_sk_value(psVar2,idx);
    return *(PKCS7_ISSUER_AND_SERIAL **)(iVar1 + 4);
  }
  return (PKCS7_ISSUER_AND_SERIAL *)0x0;
}

