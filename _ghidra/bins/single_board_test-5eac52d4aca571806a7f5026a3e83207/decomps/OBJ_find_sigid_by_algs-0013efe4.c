
int OBJ_find_sigid_by_algs(int *psignid,int dig_nid,int pkey_nid)

{
  int iVar1;
  undefined1 **ppuVar2;
  undefined1 *local_20;
  undefined1 auStack_1c [4];
  int local_18;
  int local_14;
  
  local_20 = auStack_1c;
  local_18 = dig_nid;
  local_14 = pkey_nid;
  if ((sigx_app == 0) || (iVar1 = OPENSSL_sk_find(sigx_app,local_20), iVar1 < 0)) {
    ppuVar2 = (undefined1 **)OBJ_bsearch_(&local_20,&sigoid_srt_xref,0x2b,4,(cmp *)0x13ef39);
    if (ppuVar2 == (undefined1 **)0x0) {
      return 0;
    }
  }
  else {
    local_20 = (undefined1 *)OPENSSL_sk_value(sigx_app);
    ppuVar2 = &local_20;
  }
  if (psignid != (int *)0x0) {
    *psignid = *(int *)*ppuVar2;
  }
  return 1;
}

