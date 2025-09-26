
undefined4 SRP_user_pwd_set_sv(int param_1,char *param_2,char *param_3)

{
  size_t sVar1;
  int iVar2;
  BIGNUM *pBVar3;
  uchar auStack_9dc [2504];
  
  sVar1 = strlen(param_2);
  if ((sVar1 < 0x9c5) && (sVar1 = strlen(param_3), sVar1 < 0x9c5)) {
    iVar2 = t_fromb64(auStack_9dc,param_3);
    pBVar3 = BN_bin2bn(auStack_9dc,iVar2,(BIGNUM *)0x0);
    *(BIGNUM **)(param_1 + 8) = pBVar3;
    if (pBVar3 != (BIGNUM *)0x0) {
      iVar2 = t_fromb64(auStack_9dc,param_2);
      pBVar3 = BN_bin2bn(auStack_9dc,iVar2,(BIGNUM *)0x0);
      *(BIGNUM **)(param_1 + 4) = pBVar3;
      if (pBVar3 == (BIGNUM *)0x0) {
        return 0;
      }
      return 1;
    }
  }
  return 0;
}

