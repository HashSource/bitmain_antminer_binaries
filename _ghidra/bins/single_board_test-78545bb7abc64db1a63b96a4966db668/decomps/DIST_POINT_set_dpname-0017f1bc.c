
int DIST_POINT_set_dpname(DIST_POINT_NAME *dpn,X509_NAME *iname)

{
  bool bVar1;
  X509_NAME *pXVar2;
  X509_NAME_ENTRY *ne;
  int iVar3;
  int iVar4;
  GENERAL_NAMES *pGVar5;
  
  if ((dpn == (DIST_POINT_NAME *)0x0) || (dpn->type != 1)) {
LAB_0017f1c6:
    iVar4 = 1;
  }
  else {
    pGVar5 = (dpn->name).fullname;
    pXVar2 = X509_NAME_dup(iname);
    dpn->dpname = pXVar2;
    if (pXVar2 == (X509_NAME *)0x0) {
      iVar4 = 0;
    }
    else {
      iVar4 = 0;
      do {
        iVar3 = OPENSSL_sk_num(pGVar5);
        if (iVar3 <= iVar4) {
          iVar4 = i2d_X509_NAME(dpn->dpname,(uchar **)0x0);
          if (iVar4 < 0) {
            X509_NAME_free(dpn->dpname);
            dpn->dpname = (X509_NAME *)0x0;
            return 0;
          }
          goto LAB_0017f1c6;
        }
        ne = (X509_NAME_ENTRY *)OPENSSL_sk_value(pGVar5,iVar4);
        bVar1 = iVar4 == 0;
        iVar4 = iVar4 + 1;
        iVar3 = X509_NAME_add_entry(dpn->dpname,ne,-1,(uint)bVar1);
      } while (iVar3 != 0);
      X509_NAME_free(dpn->dpname);
      dpn->dpname = (X509_NAME *)0x0;
      iVar4 = 0;
    }
  }
  return iVar4;
}

