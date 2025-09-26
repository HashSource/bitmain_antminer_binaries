
int EVP_PKEY_get_default_digest_nid(EVP_PKEY *pkey,int *pnid)

{
  int iVar1;
  code *pcVar2;
  
  if ((pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
     (pcVar2 = *(code **)(pkey->ameth + 0x58), pcVar2 != (code *)0x0)) {
    iVar1 = (*pcVar2)(pkey,3,0,pnid);
    return iVar1;
  }
  return -2;
}

