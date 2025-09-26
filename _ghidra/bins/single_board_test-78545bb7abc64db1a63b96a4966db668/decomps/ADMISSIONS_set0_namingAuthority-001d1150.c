
void ADMISSIONS_set0_namingAuthority(int param_1,undefined4 param_2)

{
  NAMING_AUTHORITY_free(*(undefined4 *)(param_1 + 4));
  *(undefined4 *)(param_1 + 4) = param_2;
  return;
}

