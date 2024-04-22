
int ECDSA_do_verify(uchar *dgst,int dgst_len,ECDSA_SIG *sig,EC_KEY *eckey)

{
  int iVar1;
  
  iVar1 = ecdsa_check(eckey);
  if (iVar1 != 0) {
    iVar1 = (**(code **)(*(int *)(iVar1 + 0xc) + 0xc))(dgst,dgst_len,sig,eckey);
  }
  return iVar1;
}

