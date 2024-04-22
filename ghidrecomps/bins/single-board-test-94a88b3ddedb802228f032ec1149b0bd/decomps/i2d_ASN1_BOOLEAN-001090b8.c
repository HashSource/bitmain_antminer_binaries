
int i2d_ASN1_BOOLEAN(int a,uchar **pp)

{
  int iVar1;
  uchar *local_14;
  
  iVar1 = ASN1_object_size(0,1,1);
  if (pp != (uchar **)0x0) {
    local_14 = *pp;
    ASN1_put_object(&local_14,0,1,1,0);
    *local_14 = (uchar)a;
    *pp = local_14 + 1;
  }
  return iVar1;
}

