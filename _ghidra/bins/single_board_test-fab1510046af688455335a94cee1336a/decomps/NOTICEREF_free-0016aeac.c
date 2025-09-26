
void NOTICEREF_free(NOTICEREF *a)

{
  ASN1_item_free((ASN1_VALUE *)a,(ASN1_ITEM *)NOTICEREF_it);
  return;
}

