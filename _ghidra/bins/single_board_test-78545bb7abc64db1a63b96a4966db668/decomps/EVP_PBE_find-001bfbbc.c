
int EVP_PBE_find(int type,int pbe_nid,int *pcnid,int *pmnid,undefined1 **pkeygen)

{
  undefined4 uVar1;
  void *pvVar2;
  int local_2c;
  int local_28;
  
  if (pbe_nid == 0) {
    return 0;
  }
  local_2c = type;
  local_28 = pbe_nid;
  if (pbe_algs != 0) {
    uVar1 = OPENSSL_sk_find(pbe_algs,&local_2c);
    pvVar2 = (void *)OPENSSL_sk_value(pbe_algs,uVar1);
    if (pvVar2 != (void *)0x0) goto LAB_001bfbea;
  }
  pvVar2 = OBJ_bsearch_(&local_2c,&builtin_pbe,0x1d,0x14,(cmp *)0x1bfaad);
  if (pvVar2 == (void *)0x0) {
    return 0;
  }
LAB_001bfbea:
  if (pcnid != (int *)0x0) {
    *pcnid = *(int *)((int)pvVar2 + 8);
  }
  if (pmnid != (int *)0x0) {
    *pmnid = *(int *)((int)pvVar2 + 0xc);
  }
  if (pkeygen != (undefined1 **)0x0) {
    *pkeygen = *(undefined1 **)((int)pvVar2 + 0x10);
  }
  return 1;
}

