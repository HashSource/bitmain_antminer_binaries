
int i2d_ASN1_OBJECT(ASN1_OBJECT *a,uchar **pp)

{
  uchar *puVar1;
  uchar *local_14;
  
  if (a == (ASN1_OBJECT *)0x0) {
    puVar1 = (uchar *)0x0;
  }
  else {
    puVar1 = a->data;
    if ((puVar1 != (uchar *)0x0) &&
       (puVar1 = (uchar *)ASN1_object_size(0,a->length,6), pp != (uchar **)0x0)) {
      local_14 = *pp;
      ASN1_put_object(&local_14,0,a->length,6,0);
      memcpy(local_14,a->data,a->length);
      *pp = local_14 + a->length;
    }
  }
  return (int)puVar1;
}

