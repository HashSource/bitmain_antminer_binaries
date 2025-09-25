
void SM2_Ciphertext_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)&SM2_Ciphertext_it);
  return;
}

