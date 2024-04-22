
undefined4 SSL_SRP_CTX_init(int param_1)

{
  char *pcVar1;
  undefined4 uVar2;
  undefined4 uVar3;
  BIGNUM *pBVar4;
  int iVar5;
  undefined4 uVar6;
  undefined4 uVar7;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar5 = *(int *)(param_1 + 0xe4);
  if (iVar5 == 0) {
    return 0;
  }
  uVar7 = *(undefined4 *)(iVar5 + 0x168);
  uVar6 = *(undefined4 *)(iVar5 + 0x16c);
  *(undefined4 *)(param_1 + 0x194) = *(undefined4 *)(iVar5 + 0x164);
  uVar2 = *(undefined4 *)(iVar5 + 0x170);
  pBVar4 = *(BIGNUM **)(iVar5 + 0x178);
  *(undefined4 *)(param_1 + 0x1c8) = *(undefined4 *)(iVar5 + 0x198);
  uVar3 = *(undefined4 *)(iVar5 + 0x19c);
  *(undefined4 *)(param_1 + 0x198) = uVar7;
  *(undefined4 *)(param_1 + 0x19c) = uVar6;
  *(undefined4 *)(param_1 + 0x1a0) = uVar2;
  *(undefined4 *)(param_1 + 0x1cc) = uVar3;
  *(undefined4 *)(param_1 + 0x1a8) = 0;
  *(undefined4 *)(param_1 + 0x1ac) = 0;
  *(undefined4 *)(param_1 + 0x1b0) = 0;
  *(undefined4 *)(param_1 + 0x1b4) = 0;
  *(undefined4 *)(param_1 + 0x1b8) = 0;
  *(undefined4 *)(param_1 + 0x1bc) = 0;
  *(undefined4 *)(param_1 + 0x1c0) = 0;
  *(undefined4 *)(param_1 + 0x1c4) = 0;
  *(undefined4 *)(param_1 + 0x1a4) = 0;
  if (pBVar4 != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(pBVar4);
    *(BIGNUM **)(param_1 + 0x1a8) = pBVar4;
    if (pBVar4 != (BIGNUM *)0x0) goto LAB_00083d48;
LAB_00083dd8:
    ERR_put_error(0x14,0x139,3,DAT_00083e50,0xb0);
LAB_00083dea:
    CRYPTO_free(*(void **)(param_1 + 0x1a4));
    BN_free(*(BIGNUM **)(param_1 + 0x1a8));
    BN_free(*(BIGNUM **)(param_1 + 0x1ac));
    BN_free(*(BIGNUM **)(param_1 + 0x1b0));
    BN_free(*(BIGNUM **)(param_1 + 0x1b4));
    BN_free(*(BIGNUM **)(param_1 + 0x1b8));
    BN_free(*(BIGNUM **)(param_1 + 0x1bc));
    BN_free(*(BIGNUM **)(param_1 + 0x1c0));
    BN_free(*(BIGNUM **)(param_1 + 0x1c4));
    return 0;
  }
LAB_00083d48:
  if (*(BIGNUM **)(iVar5 + 0x17c) != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(*(BIGNUM **)(iVar5 + 0x17c));
    *(BIGNUM **)(param_1 + 0x1ac) = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_00083dd8;
  }
  if (*(BIGNUM **)(iVar5 + 0x180) != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(*(BIGNUM **)(iVar5 + 0x180));
    *(BIGNUM **)(param_1 + 0x1b0) = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_00083dd8;
  }
  if (*(BIGNUM **)(iVar5 + 0x184) != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(*(BIGNUM **)(iVar5 + 0x184));
    *(BIGNUM **)(param_1 + 0x1b4) = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_00083dd8;
  }
  if (*(BIGNUM **)(iVar5 + 0x188) != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(*(BIGNUM **)(iVar5 + 0x188));
    *(BIGNUM **)(param_1 + 0x1b8) = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_00083dd8;
  }
  if (*(BIGNUM **)(iVar5 + 0x18c) != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(*(BIGNUM **)(iVar5 + 0x18c));
    *(BIGNUM **)(param_1 + 0x1bc) = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_00083dd8;
  }
  if (*(BIGNUM **)(iVar5 + 0x194) != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(*(BIGNUM **)(iVar5 + 0x194));
    *(BIGNUM **)(param_1 + 0x1c4) = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_00083dd8;
  }
  if (*(BIGNUM **)(iVar5 + 400) != (BIGNUM *)0x0) {
    pBVar4 = BN_dup(*(BIGNUM **)(iVar5 + 400));
    *(BIGNUM **)(param_1 + 0x1c0) = pBVar4;
    if (pBVar4 == (BIGNUM *)0x0) goto LAB_00083dd8;
  }
  if (*(char **)(iVar5 + 0x174) != (char *)0x0) {
    pcVar1 = BUF_strdup(*(char **)(iVar5 + 0x174));
    *(char **)(param_1 + 0x1a4) = pcVar1;
    if (pcVar1 == (char *)0x0) {
      ERR_put_error(0x14,0x139,0x44,DAT_00083e50,0xb5);
      goto LAB_00083dea;
    }
  }
  *(undefined4 *)(param_1 + 0x1d0) = *(undefined4 *)(iVar5 + 0x1a0);
  return 1;
}

