
int ASN1_put_eoc(uchar **pp)

{
  uchar *puVar1;
  
  puVar1 = *pp;
  *puVar1 = '\0';
  puVar1[1] = '\0';
  *pp = puVar1 + 2;
  return 2;
}

