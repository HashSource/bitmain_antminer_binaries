
void NETSCAPE_SPKI_free(NETSCAPE_SPKI *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)NETSCAPE_SPKI_it);
  return;
}

