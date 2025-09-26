
int DIST_POINT_set_dpname(DIST_POINT_NAME *dpn,X509_NAME *iname)

{
  X509_NAME *pXVar1;
  X509_NAME_ENTRY *ne;
  int iVar2;
  uint uVar3;
  _STACK *p_Var4;
  
  if ((dpn == (DIST_POINT_NAME *)0x0) || (dpn->type != 1)) {
    return 1;
  }
  p_Var4 = &((dpn->name).fullname)->stack;
  pXVar1 = X509_NAME_dup(iname);
  dpn->dpname = pXVar1;
  if (pXVar1 != (X509_NAME *)0x0) {
    uVar3 = 0;
    while (iVar2 = sk_num(p_Var4), (int)uVar3 < iVar2) {
      ne = (X509_NAME_ENTRY *)sk_value(p_Var4,uVar3);
      iVar2 = 1 - uVar3;
      if (1 < uVar3) {
        iVar2 = 0;
      }
      uVar3 = uVar3 + 1;
      iVar2 = X509_NAME_add_entry(dpn->dpname,ne,-1,iVar2);
      if (iVar2 == 0) {
        X509_NAME_free(dpn->dpname);
        dpn->dpname = (X509_NAME *)0x0;
        return 0;
      }
    }
    iVar2 = i2d_X509_NAME(dpn->dpname,(uchar **)0x0);
    if (-1 < iVar2) {
      return 1;
    }
    X509_NAME_free(dpn->dpname);
    pXVar1 = (X509_NAME *)0x0;
    dpn->dpname = (X509_NAME *)0x0;
  }
  return (int)pXVar1;
}

