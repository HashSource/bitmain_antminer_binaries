
void PROFESSION_INFO_set0_namingAuthority(undefined4 *param_1,undefined4 param_2)

{
  NAMING_AUTHORITY_free(*param_1);
  *param_1 = param_2;
  return;
}

