
int pkey_dsa_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,int param_5)

{
  EVP_MD *md;
  int iVar1;
  DSA *dsa;
  uint uStack_1c;
  
  md = *(EVP_MD **)(*(int *)(param_1 + 0x14) + 0x14);
  dsa = *(DSA **)(*(int *)(param_1 + 8) + 0x14);
  if (md == (EVP_MD *)0x0) {
    iVar1 = 0x40;
  }
  else {
    iVar1 = EVP_MD_type(md);
  }
  iVar1 = DSA_sign(iVar1,param_4,param_5,param_2,&uStack_1c,dsa);
  if (0 < iVar1) {
    iVar1 = 1;
    *param_3 = uStack_1c;
  }
  return iVar1;
}

