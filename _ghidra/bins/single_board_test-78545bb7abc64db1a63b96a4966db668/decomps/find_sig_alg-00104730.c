
int find_sig_alg(int param_1,undefined4 param_2,EVP_PKEY *param_3)

{
  uint uVar1;
  int iVar2;
  EVP_PKEY *pkey;
  RSA *rsa;
  int iVar3;
  EC_KEY *key;
  EC_GROUP *group;
  uint uVar4;
  int iVar5;
  int iVar6;
  EVP_MD *local_2c [2];
  
  uVar1 = *(uint *)(param_1 + 0xf8c);
  if (uVar1 != 0) {
    iVar6 = -1;
    uVar4 = 0;
    do {
      iVar5 = *(int *)(*(int *)(param_1 + 0xf88) + uVar4 * 4);
      if ((*(int *)(iVar5 + 8) != 0x2a3 && *(int *)(iVar5 + 8) != 0x40) &&
         (*(int *)(iVar5 + 0x10) != 0x74 && *(int *)(iVar5 + 0x10) != 6)) {
        iVar2 = tls1_lookup_md(iVar5,0);
        if (iVar2 != 0) {
          if (param_3 == (EVP_PKEY *)0x0) {
            if ((((*(uint *)(iVar5 + 0x14) < 9) &&
                 (iVar2 = *(int *)(param_1 + 0x404) + *(uint *)(iVar5 + 0x14) * 0x14,
                 *(int *)(iVar2 + 0x14) != 0)) && (*(int *)(iVar2 + 0x18) != 0)) &&
               (iVar2 = check_cert_usable_isra_8(param_1 + 0x7c,iVar5 + 8), iVar2 != 0)) {
              pkey = *(EVP_PKEY **)
                      (*(int *)(param_1 + 0x404) + *(int *)(iVar5 + 0x14) * 0x14 + 0x18);
              goto LAB_001047c2;
            }
          }
          else {
            iVar2 = ssl_cert_lookup_by_pkey(param_3,local_2c);
            if (((iVar2 != 0) && (*(EVP_MD **)(iVar5 + 0x14) == local_2c[0])) &&
               (iVar2 = check_cert_usable_isra_8(param_1 + 0x7c,iVar5 + 8,param_2,param_3),
               pkey = param_3, iVar2 != 0)) {
LAB_001047c2:
              if (*(int *)(iVar5 + 0x10) == 0x198) {
                if (iVar6 == -1) {
                  key = (EC_KEY *)EVP_PKEY_get0_EC_KEY();
                  group = EC_KEY_get0_group(key);
                  iVar6 = EC_GROUP_get_curve_name(group);
                }
                uVar1 = *(uint *)(param_1 + 0xf8c);
                if (*(int *)(iVar5 + 0x1c) != 0 && iVar6 != *(int *)(iVar5 + 0x1c))
                goto LAB_0010479a;
                break;
              }
              if (*(int *)(iVar5 + 0x10) != 0x390) {
LAB_00104804:
                uVar1 = *(uint *)(param_1 + 0xf8c);
                break;
              }
              rsa = (RSA *)EVP_PKEY_get0(pkey);
              if (((rsa != (RSA *)0x0) && (iVar2 = tls1_lookup_md(iVar5,local_2c), iVar2 != 0)) &&
                 (local_2c[0] != (EVP_MD *)0x0)) {
                iVar2 = RSA_size(rsa);
                iVar3 = EVP_MD_size(local_2c[0]);
                if (iVar2 + (iVar3 + 1) * -2 < 0 == SBORROW4(iVar2,(iVar3 + 1) * 2))
                goto LAB_00104804;
              }
            }
          }
        }
        uVar1 = *(uint *)(param_1 + 0xf8c);
      }
LAB_0010479a:
      uVar4 = uVar4 + 1;
    } while (uVar4 < uVar1);
    if (uVar4 != uVar1) {
      return iVar5;
    }
  }
  return 0;
}

