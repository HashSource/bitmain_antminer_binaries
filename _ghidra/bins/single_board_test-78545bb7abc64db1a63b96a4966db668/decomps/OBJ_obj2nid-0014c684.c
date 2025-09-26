
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  int *piVar1;
  int iVar2;
  ASN1_OBJECT *local_14;
  int local_10;
  ASN1_OBJECT *local_c;
  
  if (o != (ASN1_OBJECT *)0x0) {
    iVar2 = o->nid;
    if (iVar2 != 0) {
      return iVar2;
    }
    if (o->length != 0) {
      local_14 = o;
      if ((added != 0) &&
         (local_10 = iVar2, local_c = o, iVar2 = OPENSSL_LH_retrieve(added,&local_10), iVar2 != 0))
      {
        return *(int *)(*(int *)(iVar2 + 4) + 8);
      }
      piVar1 = (int *)OBJ_bsearch_(&local_14,&obj_objs,0x42f,4,(cmp *)0x14c259);
      if (piVar1 != (int *)0x0) {
        return *(int *)(&DAT_0026d218 + *piVar1 * 0x18);
      }
    }
  }
  return 0;
}

