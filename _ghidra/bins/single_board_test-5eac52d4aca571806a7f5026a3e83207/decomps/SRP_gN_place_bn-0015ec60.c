
undefined4 SRP_gN_place_bn(int param_1,char *param_2)

{
  int iVar1;
  undefined4 *puVar2;
  int iVar3;
  
  if (param_1 == 0) {
    return 0;
  }
  iVar3 = 0;
  while( true ) {
    iVar1 = OPENSSL_sk_num(param_1);
    if (iVar1 <= iVar3) break;
    puVar2 = (undefined4 *)OPENSSL_sk_value(param_1,iVar3);
    iVar1 = strcmp((char *)*puVar2,param_2);
    iVar3 = iVar3 + 1;
    if (iVar1 == 0) {
      return puVar2[1];
    }
  }
  puVar2 = (undefined4 *)SRP_gN_new_init(param_2);
  if (puVar2 != (undefined4 *)0x0) {
    iVar3 = OPENSSL_sk_insert(param_1,puVar2,0);
    if (0 < iVar3) {
      return puVar2[1];
    }
    CRYPTO_free((void *)*puVar2);
    BN_free((BIGNUM *)puVar2[1]);
    CRYPTO_free(puVar2);
  }
  return 0;
}

