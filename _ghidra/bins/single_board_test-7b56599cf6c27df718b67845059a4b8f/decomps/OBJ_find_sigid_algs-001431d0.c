
int OBJ_find_sigid_algs(int signid,int *pdig_nid,int *ppkey_nid)

{
  undefined4 uVar1;
  void *pvVar2;
  int local_24 [4];
  
  local_24[0] = signid;
  if (sig_app != 0) {
    uVar1 = OPENSSL_sk_find(sig_app,local_24);
    pvVar2 = (void *)OPENSSL_sk_value(sig_app,uVar1);
    if (pvVar2 != (void *)0x0) goto LAB_001431f4;
  }
  pvVar2 = OBJ_bsearch_(local_24,&sigoid_srt,0x30,0xc,(cmp *)0x143175);
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
LAB_001431f4:
  if (pdig_nid != (int *)0x0) {
    *pdig_nid = *(int *)((int)pvVar2 + 4);
  }
  if (ppkey_nid != (int *)0x0) {
    *ppkey_nid = *(int *)((int)pvVar2 + 8);
  }
  return 1;
}

