
void NAMING_AUTHORITY_set0_authorityText(int param_1,undefined4 param_2)

{
  ASN1_IA5STRING_free(*(ASN1_STRING **)(param_1 + 8));
  *(undefined4 *)(param_1 + 8) = param_2;
  return;
}

