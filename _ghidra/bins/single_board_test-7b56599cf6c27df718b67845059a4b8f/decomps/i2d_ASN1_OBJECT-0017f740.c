
int i2d_ASN1_OBJECT(ASN1_OBJECT *a,uchar **pp)

{
  uchar *puVar1;
  uchar *num;
  uchar *local_24 [2];
  
  if (a == (ASN1_OBJECT *)0x0) {
    return 0;
  }
  num = a->data;
  if ((num != (uchar *)0x0) &&
     (num = (uchar *)ASN1_object_size(0,a->length,6),
     num != (uchar *)0xffffffff && pp != (uchar **)0x0)) {
    local_24[0] = *pp;
    if (local_24[0] == (uchar *)0x0) {
      puVar1 = (uchar *)CRYPTO_malloc((int)num,"crypto/asn1/a_object.c",0x22);
      local_24[0] = puVar1;
      if (puVar1 == (uchar *)0x0) {
        ERR_put_error(0xd,0x8f,0x41,"crypto/asn1/a_object.c",0x23);
        return 0;
      }
      ASN1_put_object(local_24,0,a->length,6,0);
      memcpy(local_24[0],a->data,a->length);
    }
    else {
      ASN1_put_object(local_24,0,a->length,6,0);
      memcpy(local_24[0],a->data,a->length);
      puVar1 = local_24[0] + a->length;
    }
    *pp = puVar1;
    return (int)num;
  }
  return (int)num;
}

