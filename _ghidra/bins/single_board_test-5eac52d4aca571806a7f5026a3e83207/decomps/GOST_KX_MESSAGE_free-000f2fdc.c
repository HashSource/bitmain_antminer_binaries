
void GOST_KX_MESSAGE_free(ASN1_VALUE *param_1)

{
  ASN1_item_free(param_1,(ASN1_ITEM *)&GOST_KX_MESSAGE_it);
  return;
}

