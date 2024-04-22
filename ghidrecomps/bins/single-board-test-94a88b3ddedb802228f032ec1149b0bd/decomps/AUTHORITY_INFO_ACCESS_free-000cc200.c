
void AUTHORITY_INFO_ACCESS_free(AUTHORITY_INFO_ACCESS *a)

{
  ASN1_item_free((ASN1_VALUE *)a,DAT_000cc208);
  return;
}

