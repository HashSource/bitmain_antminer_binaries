
undefined4 ossl_statem_client_post_work(int param_1)

{
  int iVar1;
  int iVar2;
  int *piVar3;
  
  *(undefined4 *)(param_1 + 0x74) = 0;
  switch(*(undefined4 *)(param_1 + 0x40)) {
  case 0xc:
    if ((*(int *)(param_1 + 0x68) == 2) && (*(int *)(param_1 + 0xf50) != 0)) {
      if ((-1 < *(int *)(param_1 + 0x4ec) << 0xb) &&
         (iVar1 = tls13_change_cipher_state(param_1,0x52), iVar1 == 0)) {
        return 0;
      }
    }
    else {
      iVar1 = statem_flush(param_1);
      if (iVar1 == 0) {
        return 3;
      }
    }
    if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c) {
      return 2;
    }
    *(undefined4 *)(param_1 + 0x500) = 1;
    return 2;
  default:
    goto switchD_000f0e08_caseD_d;
  case 0xe:
    iVar1 = tls_client_key_exchange_post_work();
    break;
  case 0x10:
    iVar1 = (*(int **)(param_1 + 4))[0x19];
    if ((-1 < *(int *)(iVar1 + 0x30) << 0x1c) &&
       (iVar2 = **(int **)(param_1 + 4), iVar2 != 0x10000 && 0x303 < iVar2)) {
      return 2;
    }
    if (*(int *)(param_1 + 0x44c) == 1) {
      return 2;
    }
    if ((*(int *)(param_1 + 0x68) == 2) && (*(int *)(param_1 + 0xf50) != 0)) {
      iVar1 = tls13_change_cipher_state(param_1,0x52);
      if (iVar1 == 0) {
        return 0;
      }
      return 2;
    }
    iVar2 = *(int *)(param_1 + 0x474);
    piVar3 = *(int **)(*(int *)(param_1 + 0x7c) + 0x240);
    *(undefined4 *)(iVar2 + 0x1b8) = *(undefined4 *)(*(int *)(param_1 + 0x7c) + 0x210);
    if (piVar3 != (int *)0x0) {
      piVar3 = (int *)*piVar3;
    }
    *(int **)(iVar2 + 0x1b4) = piVar3;
    iVar1 = (**(code **)(iVar1 + 8))(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x10))(param_1,0x12);
    if (iVar1 == 0) {
      return 0;
    }
    if (-1 < *(int *)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x30) << 0x1c) {
      return 2;
    }
    dtls1_reset_seq_numbers(param_1,2);
    return 2;
  case 0x12:
    iVar1 = statem_flush();
    if (iVar1 != 1) {
      return 4;
    }
    if (*(int *)((*(int **)(param_1 + 4))[0x19] + 0x30) << 0x1c < 0) {
      return 2;
    }
    iVar1 = **(int **)(param_1 + 4);
    if (iVar1 == 0x10000 || iVar1 < 0x304) {
      return 2;
    }
    iVar1 = tls13_save_handshake_digest_for_pha(param_1);
    if (iVar1 == 0) {
      return 0;
    }
    if (*(int *)(param_1 + 0x5f4) == 4) {
      return 2;
    }
    iVar1 = (**(code **)(*(int *)(*(int *)(param_1 + 4) + 100) + 0x10))(param_1,0x112);
    break;
  case 0x2b:
    iVar1 = statem_flush();
    if (iVar1 != 1) {
      return 3;
    }
    iVar1 = tls13_update_key(param_1,1);
    break;
  case 0x30:
    EVP_CIPHER_CTX_free(*(EVP_CIPHER_CTX **)(param_1 + 0x3ec));
    *(undefined4 *)(param_1 + 0x3ec) = 0;
    return 2;
  }
  if (iVar1 == 0) {
    return 0;
  }
switchD_000f0e08_caseD_d:
  return 2;
}

