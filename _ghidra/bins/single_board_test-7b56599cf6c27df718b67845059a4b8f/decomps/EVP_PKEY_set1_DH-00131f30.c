
int EVP_PKEY_set1_DH(EVP_PKEY *pkey,dh_st *key)

{
  int iVar1;
  
  iVar1 = DH_get0_q(key);
  if (iVar1 == 0) {
    iVar1 = 0x1c;
  }
  else {
    iVar1 = 0x398;
  }
  iVar1 = EVP_PKEY_assign(pkey,iVar1,key);
  if (iVar1 != 0) {
    DH_up_ref(key);
  }
  return iVar1;
}

