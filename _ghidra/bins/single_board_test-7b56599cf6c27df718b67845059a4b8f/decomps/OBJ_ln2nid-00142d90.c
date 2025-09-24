
int OBJ_ln2nid(char *s)

{
  int iVar1;
  int *piVar2;
  undefined1 *local_2c;
  undefined4 local_28;
  undefined1 *local_24;
  undefined1 auStack_20 [4];
  char *local_1c;
  
  local_2c = auStack_20;
  local_1c = s;
  if (added != 0) {
    local_28 = 2;
    local_24 = local_2c;
    iVar1 = OPENSSL_LH_retrieve(added,&local_28);
    if (iVar1 != 0) {
      return *(int *)(*(int *)(iVar1 + 4) + 8);
    }
  }
  piVar2 = (int *)OBJ_bsearch_(&local_2c,ln_objs,0x4a2,4,(cmp *)0x1425b5);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  return *(int *)(&DAT_00261738 + *piVar2 * 0x18);
}

