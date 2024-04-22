
undefined4 pkey_ec_copy(int param_1,int param_2)

{
  EC_GROUP **ppEVar1;
  EC_GROUP *pEVar2;
  EC_KEY *pEVar3;
  EC_GROUP *pEVar4;
  EC_GROUP *pEVar5;
  EC_GROUP **ppEVar6;
  
  ppEVar1 = (EC_GROUP **)CRYPTO_malloc(0x20,DAT_000f89a4,0x5e);
  if (ppEVar1 == (EC_GROUP **)0x0) {
    return 0;
  }
  *(undefined *)(ppEVar1 + 3) = 0xff;
  *(undefined *)((int)ppEVar1 + 0xd) = 1;
  *ppEVar1 = (EC_GROUP *)0x0;
  ppEVar1[1] = (EC_GROUP *)0x0;
  ppEVar1[2] = (EC_GROUP *)0x0;
  ppEVar1[4] = (EC_GROUP *)0x0;
  ppEVar1[7] = (EC_GROUP *)0x0;
  ppEVar1[5] = (EC_GROUP *)0x0;
  ppEVar1[6] = (EC_GROUP *)0x0;
  *(EC_GROUP ***)(param_1 + 0x14) = ppEVar1;
  ppEVar6 = *(EC_GROUP ***)(param_2 + 0x14);
  if (*ppEVar6 != (EC_GROUP *)0x0) {
    pEVar2 = EC_GROUP_dup(*ppEVar6);
    *ppEVar1 = pEVar2;
    if (pEVar2 == (EC_GROUP *)0x0) {
      return 0;
    }
  }
  pEVar3 = (EC_KEY *)ppEVar6[2];
  ppEVar1[1] = ppEVar6[1];
  if (pEVar3 != (EC_KEY *)0x0) {
    pEVar3 = EC_KEY_dup(pEVar3);
    ppEVar1[2] = (EC_GROUP *)pEVar3;
    if (pEVar3 == (EC_KEY *)0x0) {
      return 0;
    }
  }
  pEVar4 = ppEVar6[4];
  pEVar5 = ppEVar6[7];
  pEVar2 = ppEVar6[5];
  *(undefined *)((int)ppEVar1 + 0xd) = *(undefined *)((int)ppEVar6 + 0xd);
  ppEVar1[4] = pEVar4;
  ppEVar1[7] = pEVar5;
  if (pEVar2 == (EC_GROUP *)0x0) {
    ppEVar1[5] = (EC_GROUP *)0x0;
  }
  else {
    pEVar2 = (EC_GROUP *)BUF_memdup(pEVar2,(size_t)ppEVar6[6]);
    ppEVar1[5] = pEVar2;
    if (pEVar2 == (EC_GROUP *)0x0) {
      return 0;
    }
  }
  ppEVar1[6] = ppEVar6[6];
  return 1;
}

