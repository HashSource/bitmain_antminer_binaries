
int EVP_PKEY_get_default_digest_nid(EVP_PKEY *pkey,int *pnid)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (pkey->ameth == (EVP_PKEY_ASN1_METHOD *)0x0) {
    return -2;
  }
  UNRECOVERED_JUMPTABLE = *(code **)(pkey->ameth + 0x5c);
  if (UNRECOVERED_JUMPTABLE != (code *)0x0) {
                    /* WARNING: Could not recover jumptable at 0x0013c126. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)(pkey,3,0,pnid);
    return iVar1;
  }
  return -2;
}

