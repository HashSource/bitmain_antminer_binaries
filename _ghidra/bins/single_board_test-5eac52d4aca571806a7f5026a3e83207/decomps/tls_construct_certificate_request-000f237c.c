
undefined4 tls_construct_certificate_request(int param_1,undefined4 param_2)

{
  uchar *buf;
  int iVar1;
  int iVar2;
  undefined4 uVar3;
  undefined4 local_1c [2];
  
  if (-1 < *(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c) {
    iVar2 = **(int **)(param_1 + 4);
    iVar1 = iVar2 + -0x10000;
    if (iVar1 != 0) {
      iVar1 = 1;
    }
    if (iVar2 < 0x304) {
      iVar1 = 0;
    }
    if (iVar1 != 0) {
      if (*(int *)(param_1 + 0x5f4) == 3) {
        CRYPTO_free(*(void **)(param_1 + 0x5fc));
        *(undefined4 *)(param_1 + 0x600) = 0x20;
        buf = (uchar *)CRYPTO_malloc(0x20,"ssl/statem/statem_srvr.c",0xb29);
        *(uchar **)(param_1 + 0x5fc) = buf;
        if (buf == (uchar *)0x0) {
          *(undefined4 *)(param_1 + 0x600) = 0;
          ossl_statem_fatal(param_1,0x50,0x174,0x44,"ssl/statem/statem_srvr.c",0xb2d);
          return 0;
        }
        iVar1 = RAND_bytes(buf,*(int *)(param_1 + 0x600));
        if ((iVar1 < 1) ||
           (iVar1 = WPACKET_sub_memcpy__
                              (param_2,*(undefined4 *)(param_1 + 0x5fc),
                               *(undefined4 *)(param_1 + 0x600),1), iVar1 == 0)) {
          uVar3 = 0xb35;
          goto LAB_000f2408;
        }
        iVar1 = tls13_restore_handshake_digest_for_pha(param_1);
        if (iVar1 == 0) {
          return 0;
        }
      }
      else {
        iVar1 = WPACKET_put_bytes__(param_2,1,0,0,1);
        if (iVar1 == 0) {
          ossl_statem_fatal(param_1,0x50,0x174,0x44,"ssl/statem/statem_srvr.c",0xb41);
          return 0;
        }
      }
      iVar1 = tls_construct_extensions(param_1,param_2,0x4000,0,0);
      goto joined_r0x000f2482;
    }
  }
  iVar1 = WPACKET_start_sub_packet_len__(param_2,1);
  if (((iVar1 != 0) && (iVar1 = ssl3_get_req_cert_type(param_1,param_2), iVar1 != 0)) &&
     (iVar1 = WPACKET_close(param_2), iVar1 != 0)) {
    if (*(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1e < 0) {
      uVar3 = tls12_get_psigalgs(param_1,1,local_1c);
      iVar1 = WPACKET_start_sub_packet_len__(param_2,2);
      if (((iVar1 == 0) || (iVar1 = WPACKET_set_flags(param_2,1), iVar1 == 0)) ||
         ((iVar1 = tls12_copy_sigalgs(param_1,param_2,local_1c[0],uVar3), iVar1 == 0 ||
          (iVar1 = WPACKET_close(param_2), iVar1 == 0)))) {
        uVar3 = 0xb61;
        goto LAB_000f2408;
      }
    }
    uVar3 = get_ca_names(param_1);
    iVar1 = construct_ca_names(param_1,uVar3,param_2);
joined_r0x000f2482:
    if (iVar1 == 0) {
      return 0;
    }
    *(int *)(param_1 + 0x604) = *(int *)(param_1 + 0x604) + 1;
    *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x244) = 1;
    return 1;
  }
  uVar3 = 0xb53;
LAB_000f2408:
  ossl_statem_fatal(param_1,0x50,0x174,0x44,"ssl/statem/statem_srvr.c",uVar3);
  return 0;
}

