
int pkey_ec_sign(int param_1,uchar *param_2,uint *param_3,uchar *param_4,int param_5)

{
  uint uVar1;
  EVP_MD *md;
  EC_KEY *eckey;
  int iVar2;
  uint local_1c;
  
  iVar2 = *(int *)(param_1 + 0x14);
  eckey = *(EC_KEY **)(*(int *)(param_1 + 8) + 0x18);
  uVar1 = ECDSA_size(eckey);
  if ((int)uVar1 < 1) {
    iVar2 = 0;
  }
  else if (param_2 == (uchar *)0x0) {
    *param_3 = uVar1;
    iVar2 = 1;
  }
  else {
    if (*param_3 < uVar1) {
      ERR_put_error(0x10,0xda,100,"crypto/ec/ec_pmeth.c",0x77);
      return 0;
    }
    md = *(EVP_MD **)(iVar2 + 4);
    if (md == (EVP_MD *)0x0) {
      iVar2 = 0x40;
    }
    else {
      iVar2 = EVP_MD_type(md);
    }
    iVar2 = ECDSA_sign(iVar2,param_4,param_5,param_2,&local_1c,eckey);
    if (0 < iVar2) {
      iVar2 = 1;
      *param_3 = local_1c;
    }
  }
  return iVar2;
}

