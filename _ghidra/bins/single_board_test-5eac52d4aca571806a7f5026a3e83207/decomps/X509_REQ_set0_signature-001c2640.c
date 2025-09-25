
void X509_REQ_set0_signature(int param_1,undefined4 param_2)

{
  if (*(ASN1_STRING **)(param_1 + 0x24) != (ASN1_STRING *)0x0) {
    ASN1_BIT_STRING_free(*(ASN1_STRING **)(param_1 + 0x24));
  }
  *(undefined4 *)(param_1 + 0x24) = param_2;
  return;
}

