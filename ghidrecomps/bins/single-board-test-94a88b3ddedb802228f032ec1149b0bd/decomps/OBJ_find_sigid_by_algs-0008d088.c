
int OBJ_find_sigid_by_algs(int *psignid,int dig_nid,int pkey_nid)

{
  _STACK **pp_Var1;
  int iVar2;
  int **ppiVar3;
  int *local_20;
  int iStack_1c;
  int local_18;
  int local_14;
  
  pp_Var1 = DAT_0008d0dc;
  local_20 = &iStack_1c;
  local_18 = dig_nid;
  local_14 = pkey_nid;
  if ((*DAT_0008d0dc == (_STACK *)0x0) || (iVar2 = sk_find(*DAT_0008d0dc,local_20), iVar2 < 0)) {
    ppiVar3 = (int **)OBJ_bsearch_(&local_20,DAT_0008d0e4,0x25,4,DAT_0008d0e0);
    if (ppiVar3 == (int **)0x0) {
      return 0;
    }
  }
  else {
    local_20 = (int *)sk_value(*pp_Var1,iVar2);
    ppiVar3 = &local_20;
  }
  if (psignid != (int *)0x0) {
    *psignid = **ppiVar3;
  }
  return 1;
}

