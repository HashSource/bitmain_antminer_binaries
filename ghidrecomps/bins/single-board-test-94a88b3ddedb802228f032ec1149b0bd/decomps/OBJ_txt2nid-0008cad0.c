
int OBJ_txt2nid(char *s)

{
  ASN1_OBJECT *a;
  void *pvVar1;
  int *piVar2;
  int iVar3;
  ASN1_OBJECT *local_1c;
  int local_18;
  ASN1_OBJECT *local_14;
  
  a = OBJ_txt2obj(s,0);
  local_1c = a;
  if (a != (ASN1_OBJECT *)0x0) {
    iVar3 = a->nid;
    if (iVar3 != 0) goto LAB_0008cafe;
    if (a->length != 0) {
      if (*(_LHASH **)(DAT_0008cb28 + 4) != (_LHASH *)0x0) {
        local_18 = iVar3;
        local_14 = a;
        pvVar1 = lh_retrieve(*(_LHASH **)(DAT_0008cb28 + 4),&local_18);
        if (pvVar1 != (void *)0x0) {
          iVar3 = *(int *)(*(int *)((int)pvVar1 + 4) + 8);
          goto LAB_0008cafe;
        }
      }
      piVar2 = (int *)OBJ_bsearch_ex__constprop_9(&local_1c);
      if (piVar2 != (int *)0x0) {
        iVar3 = *(int *)(DAT_0008cb2c + *piVar2 * 0x18 + 8);
        goto LAB_0008cafe;
      }
    }
  }
  iVar3 = 0;
LAB_0008cafe:
  ASN1_OBJECT_free(a);
  return iVar3;
}

