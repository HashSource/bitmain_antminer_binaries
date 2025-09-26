
int OBJ_obj2nid(ASN1_OBJECT *o)

{
  void *pvVar1;
  int *piVar2;
  int iVar3;
  ASN1_OBJECT *local_14;
  int local_10;
  ASN1_OBJECT *local_c;
  
  if (o != (ASN1_OBJECT *)0x0) {
    iVar3 = o->nid;
    if (iVar3 != 0) {
      return iVar3;
    }
    if (o->length != 0) {
      local_14 = o;
      if ((added != (_LHASH *)0x0) &&
         (local_10 = iVar3, local_c = o, pvVar1 = lh_retrieve(added,&local_10),
         pvVar1 != (void *)0x0)) {
        return *(int *)(*(int *)((int)pvVar1 + 4) + 8);
      }
      piVar2 = (int *)OBJ_bsearch_ex__constprop_9(&local_14);
      if (piVar2 != (int *)0x0) {
        return *(int *)(&DAT_001f7880 + *piVar2 * 0x18);
      }
    }
  }
  return 0;
}

