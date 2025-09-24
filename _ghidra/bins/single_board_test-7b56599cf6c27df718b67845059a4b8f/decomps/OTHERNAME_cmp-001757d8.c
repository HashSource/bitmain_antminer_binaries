
int OTHERNAME_cmp(OTHERNAME *a,OTHERNAME *b)

{
  int iVar1;
  
  if (b == (OTHERNAME *)0x0 || a == (OTHERNAME *)0x0) {
    return -1;
  }
  iVar1 = OBJ_cmp(a->type_id,b->type_id);
  if (iVar1 != 0) {
    return iVar1;
  }
  iVar1 = ASN1_TYPE_cmp(a->value,b->value);
  return iVar1;
}

