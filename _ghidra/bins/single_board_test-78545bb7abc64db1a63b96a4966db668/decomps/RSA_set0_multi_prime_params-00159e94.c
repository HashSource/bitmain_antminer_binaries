
undefined4 RSA_set0_multi_prime_params(int param_1,int param_2,int param_3,int param_4,int param_5)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  int iVar4;
  int *piVar5;
  int *piVar6;
  int *piVar7;
  int iVar8;
  
  if ((param_3 != 0 && param_2 != 0) && (param_5 != 0 && param_4 != 0)) {
    iVar8 = 0;
    iVar1 = OPENSSL_sk_new_reserve(0,param_5);
    if (iVar1 != 0) {
      iVar4 = *(int *)(param_1 + 0x30);
      if (0 < param_5) {
        piVar6 = (int *)(param_2 + -4);
        piVar7 = (int *)(param_3 + -4);
        piVar5 = (int *)(param_4 + -4);
        do {
          piVar3 = (int *)rsa_multip_info_new();
          iVar8 = iVar8 + 1;
          if (piVar3 == (int *)0x0) goto LAB_00159f54;
          piVar6 = piVar6 + 1;
          if (((*piVar6 == 0) || (piVar7 = piVar7 + 1, *piVar7 == 0)) ||
             (piVar5 = piVar5 + 1, *piVar5 == 0)) {
            rsa_multip_info_free(piVar3);
            OPENSSL_sk_pop_free(iVar1,0x15a3fd);
            return 0;
          }
          BN_clear_free((BIGNUM *)*piVar3);
          BN_clear_free((BIGNUM *)piVar3[1]);
          BN_clear_free((BIGNUM *)piVar3[2]);
          iVar2 = *piVar6;
          *piVar3 = iVar2;
          piVar3[1] = *piVar7;
          piVar3[2] = *piVar5;
          BN_set_flags(iVar2,4);
          BN_set_flags(piVar3[1],4);
          BN_set_flags(piVar3[2],4);
          OPENSSL_sk_push(iVar1,piVar3);
        } while (param_5 != iVar8);
      }
      *(int *)(param_1 + 0x30) = iVar1;
      iVar8 = rsa_multip_calc_product(param_1);
      if (iVar8 != 0) {
        if (iVar4 != 0) {
          OPENSSL_sk_pop_free(iVar4,(undefined *)0x15a41d);
        }
        *(undefined4 *)(param_1 + 4) = 1;
        return 1;
      }
      *(int *)(param_1 + 0x30) = iVar4;
LAB_00159f54:
      OPENSSL_sk_pop_free(iVar1,0x15a3fd);
    }
  }
  return 0;
}

