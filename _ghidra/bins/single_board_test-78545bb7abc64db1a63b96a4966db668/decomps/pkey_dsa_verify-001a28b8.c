
int pkey_dsa_verify(int param_1,uchar *param_2,int param_3,uchar *param_4,int param_5)

{
  EVP_MD *md;
  int iVar1;
  DSA *dsa;
  
  md = *(EVP_MD **)(*(int *)(param_1 + 0x14) + 0x14);
  dsa = *(DSA **)(*(int *)(param_1 + 8) + 0x18);
  if ((md != (EVP_MD *)0x0) && (iVar1 = EVP_MD_size(md), iVar1 != param_5)) {
    return 0;
  }
  iVar1 = DSA_verify(0,param_4,param_5,param_2,param_3,dsa);
  return iVar1;
}

