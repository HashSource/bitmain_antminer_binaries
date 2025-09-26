
int EC_KEY_set_private_key(EC_KEY *key,BIGNUM *prv)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  piVar3 = *(int **)(key + 0xc);
  if (((((piVar3 != (int *)0x0) && (*piVar3 != 0)) &&
       (iVar1 = EC_GROUP_get0_order(piVar3), iVar1 != 0)) &&
      ((iVar2 = BN_is_zero(), iVar2 == 0 &&
       ((*(code **)(**(int **)(key + 0xc) + 0xac) == (code *)0x0 ||
        (iVar2 = (**(code **)(**(int **)(key + 0xc) + 0xac))(key,prv), iVar2 != 0)))))) &&
     ((*(code **)(*(int *)key + 0x18) == (code *)0x0 ||
      (iVar2 = (**(code **)(*(int *)key + 0x18))(key,prv), iVar2 != 0)))) {
    iVar2 = 0;
    if (prv == (BIGNUM *)0x0) {
LAB_0012744c:
      BN_clear_free(*(BIGNUM **)(key + 0x14));
      *(BIGNUM **)(key + 0x14) = prv;
      return iVar2;
    }
    prv = BN_dup(prv);
    if (prv != (BIGNUM *)0x0) {
      BN_set_flags(prv,4);
      iVar1 = bn_get_top(iVar1);
      iVar1 = bn_wexpand(prv,iVar1 + 2);
      if (iVar1 != 0) {
        iVar2 = 1;
        goto LAB_0012744c;
      }
      BN_clear_free(prv);
    }
  }
  return 0;
}

