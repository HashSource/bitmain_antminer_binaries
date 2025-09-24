
int EVP_PKEY_cmp_parameters(EVP_PKEY *a,EVP_PKEY *b)

{
  int iVar1;
  code *UNRECOVERED_JUMPTABLE;
  
  if (a->type == b->type) {
    if ((a->ameth != (EVP_PKEY_ASN1_METHOD *)0x0) &&
       (UNRECOVERED_JUMPTABLE = *(code **)(a->ameth + 0x4c), UNRECOVERED_JUMPTABLE != (code *)0x0))
    {
                    /* WARNING: Could not recover jumptable at 0x00131976. Too many branches */
                    /* WARNING: Treating indirect jump as call */
      iVar1 = (*UNRECOVERED_JUMPTABLE)();
      return iVar1;
    }
    iVar1 = -2;
  }
  else {
    iVar1 = -1;
  }
  return iVar1;
}

