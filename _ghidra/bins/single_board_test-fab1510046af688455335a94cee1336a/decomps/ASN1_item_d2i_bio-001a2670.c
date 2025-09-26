
void * ASN1_item_d2i_bio(ASN1_ITEM *it,BIO *in,void *x)

{
  int len;
  ASN1_VALUE *pAVar1;
  BUF_MEM *local_18;
  uchar *local_14;
  
  pAVar1 = (ASN1_VALUE *)0x0;
  local_18 = (BUF_MEM *)0x0;
  len = asn1_d2i_read_bio(in,&local_18);
  if (-1 < len) {
    local_14 = (uchar *)local_18->data;
    pAVar1 = ASN1_item_d2i((ASN1_VALUE **)x,&local_14,len,it);
  }
  if (local_18 != (BUF_MEM *)0x0) {
    BUF_MEM_free(local_18);
  }
  return pAVar1;
}

