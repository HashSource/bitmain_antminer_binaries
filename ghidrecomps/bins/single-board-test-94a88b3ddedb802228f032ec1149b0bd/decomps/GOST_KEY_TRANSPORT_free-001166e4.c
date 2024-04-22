
void GOST_KEY_TRANSPORT_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)&GOST_KEY_TRANSPORT_it);
  return;
}

