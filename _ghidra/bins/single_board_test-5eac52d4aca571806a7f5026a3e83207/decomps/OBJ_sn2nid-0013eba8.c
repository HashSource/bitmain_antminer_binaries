
int OBJ_sn2nid(char *s)

{
  int iVar1;
  int *piVar2;
  char **local_2c;
  undefined4 local_28;
  char **local_24;
  char *local_20 [6];
  
  local_2c = local_20;
  local_20[0] = s;
  if (added != 0) {
    local_28 = 1;
    local_24 = local_2c;
    iVar1 = OPENSSL_LH_retrieve(added,&local_28);
    if (iVar1 != 0) {
      return *(int *)(*(int *)(iVar1 + 4) + 8);
    }
  }
  piVar2 = (int *)OBJ_bsearch_(&local_2c,sn_objs,0x4a2,4,(cmp *)0x13e381);
  if (piVar2 == (int *)0x0) {
    return 0;
  }
  return *(int *)(&DAT_0025c14c + *piVar2 * 0x18);
}

