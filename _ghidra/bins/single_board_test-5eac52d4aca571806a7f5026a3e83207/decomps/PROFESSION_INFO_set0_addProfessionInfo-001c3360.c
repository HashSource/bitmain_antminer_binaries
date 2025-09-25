
void PROFESSION_INFO_set0_addProfessionInfo(int param_1,undefined4 param_2)

{
  ASN1_OCTET_STRING_free(*(ASN1_STRING **)(param_1 + 0x10));
  *(undefined4 *)(param_1 + 0x10) = param_2;
  return;
}

