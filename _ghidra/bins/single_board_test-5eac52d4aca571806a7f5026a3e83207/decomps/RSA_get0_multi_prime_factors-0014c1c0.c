
undefined4 RSA_get0_multi_prime_factors(int param_1,int param_2)

{
  int iVar1;
  undefined4 *puVar2;
  undefined4 *puVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  int iVar7;
  
  iVar1 = RSA_get_multi_prime_extra_count();
  if (iVar1 != 0) {
    if (0 < iVar1) {
      if (iVar1 < 9) {
        iVar5 = 0;
      }
      else {
        iVar5 = 0;
        iVar6 = param_2 + 0x28;
        iVar4 = 1;
        do {
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5);
          HintPreloadData(iVar6);
          iVar7 = iVar4 + 8;
          *(undefined4 *)(iVar6 + -0x28) = *puVar2;
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar4);
          *(undefined4 *)(iVar6 + -0x24) = *puVar2;
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5 + 2);
          *(undefined4 *)(iVar6 + -0x20) = *puVar2;
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5 + 3);
          *(undefined4 *)(iVar6 + -0x1c) = *puVar2;
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5 + 4);
          *(undefined4 *)(iVar6 + -0x18) = *puVar2;
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5 + 5);
          *(undefined4 *)(iVar6 + -0x14) = *puVar2;
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5 + 6);
          iVar4 = iVar5 + 7;
          iVar5 = iVar5 + 8;
          *(undefined4 *)(iVar6 + -0x10) = *puVar2;
          puVar2 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar4);
          *(undefined4 *)(iVar6 + -0xc) = *puVar2;
          iVar6 = iVar6 + 0x20;
          iVar4 = iVar7;
        } while (iVar7 < iVar1 + -7);
      }
      puVar2 = (undefined4 *)(param_2 + iVar5 * 4);
      do {
        puVar3 = (undefined4 *)OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5);
        iVar5 = iVar5 + 1;
        *puVar2 = *puVar3;
        puVar2 = puVar2 + 1;
      } while (iVar5 < iVar1);
    }
    return 1;
  }
  return 0;
}

