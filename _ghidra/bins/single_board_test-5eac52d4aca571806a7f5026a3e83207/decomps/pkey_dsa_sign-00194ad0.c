
int pkey_dsa_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,int param_5)

{
  EVP_MD *md;
  int iVar1;
  DSA *dsa;
  uint local_1c [2];
  
  md = *(EVP_MD **)(*(int *)(param_1 + 0x14) + 0x14);
  dsa = *(DSA **)(*(int *)(param_1 + 8) + 0x18);
  if ((md == (EVP_MD *)0x0) || (iVar1 = EVP_MD_size(md), iVar1 == param_5)) {
    iVar1 = DSA_sign(0,param_4,param_5,param_2,local_1c,dsa);
    if (0 < iVar1) {
      *param_3 = local_1c[0];
      return 1;
    }
  }
  else {
    iVar1 = 0;
  }
  return iVar1;
}

