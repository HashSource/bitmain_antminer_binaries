
int X509_check_trust(X509 *x,int id,int flags)

{
  int iVar1;
  X509_TRUST *pXVar2;
  
  if (id == 0) {
    iVar1 = obj_trust(0x38e,x,flags | 8);
    return iVar1;
  }
  iVar1 = X509_TRUST_get_by_id(id);
  if (iVar1 != -1) {
    pXVar2 = X509_TRUST_get0(iVar1);
                    /* WARNING: Could not recover jumptable at 0x001d06ce. Too many branches */
                    /* WARNING: Treating indirect jump as call */
    iVar1 = (*pXVar2->check_trust)(pXVar2,x,flags);
    return iVar1;
  }
                    /* WARNING: Could not recover jumptable at 0x001d06ec. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  iVar1 = (*default_trust)(id,x,flags);
  return iVar1;
}

