
undefined4 SRP_check_known_gN_param(BIGNUM *param_1,BIGNUM *param_2)

{
  int iVar1;
  int iVar2;
  undefined4 *puVar3;
  
  if (param_2 != (BIGNUM *)0x0 && param_1 != (BIGNUM *)0x0) {
    iVar2 = 0;
    puVar3 = &knowngN;
    do {
      iVar1 = BN_cmp((BIGNUM *)puVar3[1],param_1);
      if ((iVar1 == 0) && (iVar1 = BN_cmp((BIGNUM *)puVar3[2],param_2), iVar1 == 0)) {
        return (&knowngN)[iVar2 * 3];
      }
      iVar2 = iVar2 + 1;
      puVar3 = puVar3 + 3;
    } while (iVar2 != 7);
  }
  return 0;
}

