
int ASN1_TYPE_get_int_octetstring(ASN1_TYPE *a,long *num,uchar *data,int max_len)

{
  void *__src;
  ASN1_VALUE *val;
  size_t sVar1;
  
  if (((a->type == 0x10) && ((a->value).ptr != (char *)0x0)) &&
     (val = (ASN1_VALUE *)ASN1_TYPE_unpack_sequence(&asn1_int_oct_it,a), val != (ASN1_VALUE *)0x0))
  {
    if (num != (long *)0x0) {
      *num = *(long *)val;
    }
    sVar1 = ASN1_STRING_length(*(ASN1_STRING **)(val + 4));
    if (data != (uchar *)0x0) {
      __src = (void *)ASN1_STRING_get0_data(*(long *)(val + 4));
      if ((int)sVar1 <= max_len) {
        max_len = sVar1;
      }
      memcpy(data,__src,max_len);
    }
    if (sVar1 != 0xffffffff) goto LAB_00180f14;
  }
  else {
    val = (ASN1_VALUE *)0x0;
  }
  sVar1 = 0xffffffff;
  ERR_put_error(0xd,0x86,0x6d,"crypto/asn1/evp_asn1.c",0x6f);
LAB_00180f14:
  ASN1_item_free(val,(ASN1_ITEM *)&asn1_int_oct_it);
  return sVar1;
}

