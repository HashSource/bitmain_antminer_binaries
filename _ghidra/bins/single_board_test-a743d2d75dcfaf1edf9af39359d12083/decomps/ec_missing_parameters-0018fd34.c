
int ec_missing_parameters(int param_1)

{
  EC_GROUP *pEVar1;
  int iVar2;
  
  pEVar1 = EC_KEY_get0_group(*(EC_KEY **)(param_1 + 0x14));
  iVar2 = 1 - (int)pEVar1;
  if ((EC_GROUP *)0x1 < pEVar1) {
    iVar2 = 0;
  }
  return iVar2;
}

