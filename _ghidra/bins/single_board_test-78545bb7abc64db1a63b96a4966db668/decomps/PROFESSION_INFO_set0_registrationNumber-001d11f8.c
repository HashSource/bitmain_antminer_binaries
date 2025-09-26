
void PROFESSION_INFO_set0_registrationNumber(int param_1,undefined4 param_2)

{
  ASN1_PRINTABLESTRING_free(*(ASN1_STRING **)(param_1 + 0xc));
  *(undefined4 *)(param_1 + 0xc) = param_2;
  return;
}

