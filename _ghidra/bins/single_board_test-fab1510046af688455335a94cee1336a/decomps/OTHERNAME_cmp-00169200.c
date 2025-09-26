
int OTHERNAME_cmp(OTHERNAME *a,OTHERNAME *b)

{
  int iVar1;
  
  if (a == (OTHERNAME *)0x0 || b == (OTHERNAME *)0x0) {
    iVar1 = -1;
  }
  else {
    iVar1 = OBJ_cmp(a->type_id,b->type_id);
    if (iVar1 == 0) {
      iVar1 = ASN1_TYPE_cmp(a->value,b->value);
      return iVar1;
    }
  }
  return iVar1;
}

