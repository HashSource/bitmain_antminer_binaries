
int OBJ_find_sigid_algs(int signid,int *pdig_nid,int *ppkey_nid)

{
  int *piVar1;
  int iVar2;
  void *pvVar3;
  int local_24 [4];
  
  local_24[0] = signid;
  if ((((sig_app != (_STACK *)0x0) && (iVar2 = sk_find(sig_app,local_24), -1 < iVar2)) &&
      (pvVar3 = sk_value(sig_app,iVar2), pvVar3 != (void *)0x0)) ||
     (pvVar3 = OBJ_bsearch_(local_24,&sigoid_srt,0x28,0xc,(cmp *)0x135efd), pvVar3 != (void *)0x0))
  {
    if (pdig_nid != (int *)0x0) {
      *pdig_nid = *(int *)((int)pvVar3 + 4);
    }
    if (ppkey_nid == (int *)0x0) {
      pvVar3 = (void *)0x1;
    }
    else {
      piVar1 = (int *)((int)pvVar3 + 8);
      pvVar3 = (void *)0x1;
      *ppkey_nid = *piVar1;
    }
  }
  return (int)pvVar3;
}

