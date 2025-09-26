
undefined4 use_ecc(int *param_1)

{
  undefined4 uVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  uint uVar5;
  int local_20;
  uint local_1c [2];
  
  iVar4 = 0;
  local_20 = 0;
  if (*param_1 != 0x300) {
    uVar1 = SSL_get1_supported_ciphers();
    iVar2 = OPENSSL_sk_num();
    if (0 < iVar2) {
      do {
        iVar3 = OPENSSL_sk_value(uVar1,iVar4);
        iVar4 = iVar4 + 1;
        if ((((*(uint *)(iVar3 + 0x10) & 0x84) != 0) || (*(int *)(iVar3 + 0x14) << 0x1c < 0)) ||
           (0x303 < *(int *)(iVar3 + 0x20))) {
          OPENSSL_sk_free(uVar1);
          uVar5 = 0;
          tls1_get_supported_groups(param_1,&local_20,local_1c);
          if (local_1c[0] == 0) {
            return 0;
          }
          do {
            iVar4 = uVar5 * 2;
            uVar5 = uVar5 + 1;
            iVar4 = tls_curve_allowed(param_1,*(undefined2 *)(local_20 + iVar4),0x20004);
            if (iVar4 != 0) {
              return 1;
            }
          } while (uVar5 < local_1c[0]);
          return 0;
        }
      } while (iVar4 != iVar2);
    }
    OPENSSL_sk_free(uVar1);
  }
  return 0;
}

