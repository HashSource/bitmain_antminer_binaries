
int param_cmp(EVP_PKEY *a,EVP_PKEY *b)

{
  int iVar1;
  
                    /* WARNING: Could not recover jumptable at 0x00012410. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*(code *)PTR_LAB_00194368)(*(undefined4 *)a->type,*(undefined4 *)b->type);
  return iVar1;
}

