
int EVP_PBE_find(int type,int pbe_nid,int *pcnid,int *pmnid,undefined1 **pkeygen)

{
  int iVar1;
  void *pvVar2;
  int local_2c;
  int local_28;
  
  if (pbe_nid == 0) {
LAB_00153cae:
    iVar1 = 0;
  }
  else {
    local_2c = type;
    local_28 = pbe_nid;
    if (((pbe_algs == (_STACK *)0x0) || (iVar1 = sk_find(pbe_algs,&local_2c), iVar1 == -1)) ||
       (pvVar2 = sk_value(pbe_algs,iVar1), pvVar2 == (void *)0x0)) {
      pvVar2 = OBJ_bsearch_(&local_2c,&builtin_pbe,0x15,0x14,(cmp *)0x153a05);
      if (pvVar2 == (void *)0x0) goto LAB_00153cae;
    }
    if (pcnid != (int *)0x0) {
      *pcnid = *(int *)((int)pvVar2 + 8);
    }
    if (pmnid != (int *)0x0) {
      *pmnid = *(int *)((int)pvVar2 + 0xc);
    }
    if (pkeygen == (undefined1 **)0x0) {
      iVar1 = 1;
    }
    else {
      iVar1 = 1;
      *pkeygen = *(undefined1 **)((int)pvVar2 + 0x10);
    }
  }
  return iVar1;
}

