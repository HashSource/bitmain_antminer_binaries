
void ECDSA_SIG_free(ECDSA_SIG *sig)

{
  ASN1_item_free((ASN1_VALUE *)sig,(ASN1_ITEM *)&ECDSA_SIG_it);
  return;
}

