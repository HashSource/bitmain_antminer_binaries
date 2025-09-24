
undefined4 ssl3_check_cert_and_algorithm(int param_1)

{
  undefined4 uVar1;
  int iVar2;
  uint uVar3;
  uint uVar4;
  int local_1c [2];
  
  iVar2 = *(int *)(*(int *)(param_1 + 0x7c) + 0x210);
  uVar3 = *(uint *)(iVar2 + 0x14);
  if ((uVar3 & 0xab) != 0) {
    uVar4 = *(uint *)(iVar2 + 0x10);
    uVar1 = X509_get0_pubkey(*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x19c));
    iVar2 = ssl_cert_lookup_by_pkey(uVar1,local_1c);
    if ((iVar2 == 0) || ((uVar3 & *(uint *)(iVar2 + 4)) == 0)) {
      ossl_statem_fatal(param_1,0x28,0x82,0xdd,"ssl/statem/statem_clnt.c",0xe17);
      return 0;
    }
    if ((*(uint *)(iVar2 + 4) & 8) == 0) {
      if (((uVar4 & 0x41) != 0) && (local_1c[0] != 0)) {
        ossl_statem_fatal(param_1,0x28,0x82,0xa9,"ssl/statem/statem_clnt.c",0xe28);
        return 0;
      }
      if (((int)(uVar4 << 0x1e) < 0) && (*(int *)(*(int *)(param_1 + 0x7c) + 0x358) == 0)) {
        ossl_statem_fatal(param_1,0x50,0x82,0x44,"ssl/statem/statem_clnt.c",0xe2f);
        return 0;
      }
    }
    else {
      iVar2 = ssl_check_srvr_ecc_cert_and_alg
                        (*(undefined4 *)(*(int *)(param_1 + 0x474) + 0x19c),param_1);
      if (iVar2 == 0) {
        ossl_statem_fatal(param_1,0x28,0x82,0x130,"ssl/statem/statem_clnt.c",0xe20);
        return 0;
      }
    }
  }
  return 1;
}

