
int OBJ_find_sigid_algs(int signid,int *pdig_nid,int *ppkey_nid)

{
  int *piVar1;
  _STACK **pp_Var2;
  int iVar3;
  void *pvVar4;
  int local_24 [4];
  
  pp_Var2 = DAT_0008d07c;
  local_24[0] = signid;
  if ((((*DAT_0008d07c != (_STACK *)0x0) && (iVar3 = sk_find(*DAT_0008d07c,local_24), -1 < iVar3))
      && (pvVar4 = sk_value(*pp_Var2,iVar3), pvVar4 != (void *)0x0)) ||
     (pvVar4 = OBJ_bsearch_(local_24,DAT_0008d084,0x28,0xc,DAT_0008d080), pvVar4 != (void *)0x0)) {
    if (pdig_nid != (int *)0x0) {
      *pdig_nid = *(int *)((int)pvVar4 + 4);
    }
    if (ppkey_nid == (int *)0x0) {
      pvVar4 = (void *)0x1;
    }
    else {
      piVar1 = (int *)((int)pvVar4 + 8);
      pvVar4 = (void *)0x1;
      *ppkey_nid = *piVar1;
    }
  }
  return (int)pvVar4;
}

