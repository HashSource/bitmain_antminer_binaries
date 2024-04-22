
void d2i_GOST_KEY_TRANSPORT(ASN1_VALUE **param_1,uchar **param_2,long param_3)

{
  ASN1_item_d2i(param_1,param_2,param_3,(ASN1_ITEM *)&GOST_KEY_TRANSPORT_it);
  return;
}

