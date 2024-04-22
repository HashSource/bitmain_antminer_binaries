
int EVP_PBE_find(int type,int pbe_nid,int *pcnid,int *pmnid,undefined1 **pkeygen)

{
  _STACK **pp_Var1;
  int iVar2;
  void *pvVar3;
  int local_2c;
  int local_28;
  
  pp_Var1 = DAT_000b3080;
  if (pbe_nid == 0) {
LAB_000b3052:
    iVar2 = 0;
  }
  else {
    local_2c = type;
    local_28 = pbe_nid;
    if (((*DAT_000b3080 == (_STACK *)0x0) || (iVar2 = sk_find(*DAT_000b3080,&local_2c), iVar2 == -1)
        ) || (pvVar3 = sk_value(*pp_Var1,iVar2), pvVar3 == (void *)0x0)) {
      pvVar3 = OBJ_bsearch_(&local_2c,DAT_000b3088,0x15,0x14,DAT_000b3084);
      if (pvVar3 == (void *)0x0) goto LAB_000b3052;
    }
    if (pcnid != (int *)0x0) {
      *pcnid = *(int *)((int)pvVar3 + 8);
    }
    if (pmnid != (int *)0x0) {
      *pmnid = *(int *)((int)pvVar3 + 0xc);
    }
    if (pkeygen == (undefined1 **)0x0) {
      iVar2 = 1;
    }
    else {
      iVar2 = 1;
      *pkeygen = *(undefined1 **)((int)pvVar3 + 0x10);
    }
  }
  return iVar2;
}

