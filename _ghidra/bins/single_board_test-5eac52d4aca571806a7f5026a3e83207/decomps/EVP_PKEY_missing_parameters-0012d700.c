
int EVP_PKEY_missing_parameters(EVP_PKEY *pkey)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (((pkey != (EVP_PKEY *)0x0) && (pkey->ameth != (EVP_PKEY_ASN1_METHOD *)0x0)) &&
     (UNRECOVERED_JUMPTABLE = *(code **)(pkey->ameth + 0x44), UNRECOVERED_JUMPTABLE != (code *)0x0))
  {
                    /* WARNING: Could not recover jumptable at 0x0012d70a. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*UNRECOVERED_JUMPTABLE)();
    return iVar1;
  }
  return 0;
}

