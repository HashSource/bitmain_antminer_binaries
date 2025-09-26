
undefined4 RSA_get0_multi_prime_crt_params(int param_1,int param_2,int param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  int iVar6;
  undefined4 *puVar7;
  undefined4 *puVar8;
  
  iVar1 = RSA_get_multi_prime_extra_count();
  if (iVar1 != 0) {
    if ((param_3 != 0 || param_2 != 0) && (0 < iVar1)) {
      if (param_2 == 0) {
        if (param_3 == 0) {
          do {
            iVar6 = param_3 + 1;
            OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),param_3);
            param_3 = iVar6;
          } while (iVar1 != iVar6);
        }
        else {
          iVar6 = 0;
          if (8 < iVar1) {
            iVar6 = 0;
            iVar3 = param_3 + 0x28;
            iVar4 = 1;
            do {
              iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6);
              HintPreloadData(iVar3);
              iVar5 = iVar4 + 8;
              *(undefined4 *)(iVar3 + -0x28) = *(undefined4 *)(iVar2 + 8);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar4);
              *(undefined4 *)(iVar3 + -0x24) = *(undefined4 *)(iVar4 + 8);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 2);
              *(undefined4 *)(iVar3 + -0x20) = *(undefined4 *)(iVar4 + 8);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 3);
              *(undefined4 *)(iVar3 + -0x1c) = *(undefined4 *)(iVar4 + 8);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 4);
              *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(iVar4 + 8);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 5);
              *(undefined4 *)(iVar3 + -0x14) = *(undefined4 *)(iVar4 + 8);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 6);
              iVar2 = iVar6 + 7;
              iVar6 = iVar6 + 8;
              *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(iVar4 + 8);
              iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar2);
              *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(iVar4 + 8);
              iVar3 = iVar3 + 0x20;
              iVar4 = iVar5;
            } while (iVar5 < iVar1 + -7);
          }
          puVar7 = (undefined4 *)(param_3 + iVar6 * 4);
          do {
            iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6);
            iVar6 = iVar6 + 1;
            *puVar7 = *(undefined4 *)(iVar3 + 8);
            puVar7 = puVar7 + 1;
          } while (iVar6 < iVar1);
        }
      }
      else if (param_3 == 0) {
        iVar6 = 0;
        if (8 < iVar1) {
          iVar6 = 0;
          iVar3 = param_2 + 0x28;
          iVar4 = 1;
          do {
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6);
            HintPreloadData(iVar3);
            iVar5 = iVar4 + 8;
            *(undefined4 *)(iVar3 + -0x28) = *(undefined4 *)(iVar2 + 4);
            iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar4);
            *(undefined4 *)(iVar3 + -0x24) = *(undefined4 *)(iVar4 + 4);
            iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 2);
            *(undefined4 *)(iVar3 + -0x20) = *(undefined4 *)(iVar4 + 4);
            iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 3);
            *(undefined4 *)(iVar3 + -0x1c) = *(undefined4 *)(iVar4 + 4);
            iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 4);
            *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(iVar4 + 4);
            iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 5);
            *(undefined4 *)(iVar3 + -0x14) = *(undefined4 *)(iVar4 + 4);
            iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 6);
            iVar2 = iVar6 + 7;
            iVar6 = iVar6 + 8;
            *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(iVar4 + 4);
            iVar4 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar2);
            *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(iVar4 + 4);
            iVar3 = iVar3 + 0x20;
            iVar4 = iVar5;
          } while (iVar5 < iVar1 + -7);
        }
        puVar7 = (undefined4 *)(param_2 + iVar6 * 4);
        do {
          iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6);
          iVar6 = iVar6 + 1;
          *puVar7 = *(undefined4 *)(iVar3 + 4);
          puVar7 = puVar7 + 1;
        } while (iVar6 < iVar1);
      }
      else {
        if (iVar1 < 9) {
          iVar6 = 0;
        }
        else {
          iVar6 = 0;
          iVar3 = param_3 + 0x20;
          iVar4 = param_2 + 0x20;
          do {
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6);
            HintPreloadData(iVar3);
            HintPreloadData(iVar4);
            *(undefined4 *)(iVar4 + -0x20) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -0x20) = *(undefined4 *)(iVar2 + 8);
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 1);
            *(undefined4 *)(iVar4 + -0x1c) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -0x1c) = *(undefined4 *)(iVar2 + 8);
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 2);
            *(undefined4 *)(iVar4 + -0x18) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -0x18) = *(undefined4 *)(iVar2 + 8);
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 3);
            *(undefined4 *)(iVar4 + -0x14) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -0x14) = *(undefined4 *)(iVar2 + 8);
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 4);
            *(undefined4 *)(iVar4 + -0x10) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -0x10) = *(undefined4 *)(iVar2 + 8);
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 5);
            *(undefined4 *)(iVar4 + -0xc) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -0xc) = *(undefined4 *)(iVar2 + 8);
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6 + 6);
            iVar5 = iVar6 + 7;
            iVar6 = iVar6 + 8;
            *(undefined4 *)(iVar4 + -8) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -8) = *(undefined4 *)(iVar2 + 8);
            iVar2 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar5);
            *(undefined4 *)(iVar4 + -4) = *(undefined4 *)(iVar2 + 4);
            *(undefined4 *)(iVar3 + -4) = *(undefined4 *)(iVar2 + 8);
            iVar3 = iVar3 + 0x20;
            iVar4 = iVar4 + 0x20;
          } while (iVar6 != (iVar1 - 9U & 0xfffffff8) + 8);
        }
        puVar7 = (undefined4 *)(param_2 + iVar6 * 4);
        puVar8 = (undefined4 *)(param_3 + iVar6 * 4);
        do {
          iVar3 = OPENSSL_sk_value(*(undefined4 *)(param_1 + 0x30),iVar6);
          iVar6 = iVar6 + 1;
          *puVar7 = *(undefined4 *)(iVar3 + 4);
          *puVar8 = *(undefined4 *)(iVar3 + 8);
          puVar7 = puVar7 + 1;
          puVar8 = puVar8 + 1;
        } while (iVar6 < iVar1);
      }
    }
    return 1;
  }
  return 0;
}

