
undefined4 ssl3_renegotiate_check(int param_1,int param_2)

{
  int iVar1;
  
  if (*(int *)(*(int *)(param_1 + 0x7c) + 0xf0) == 0) {
    return 0;
  }
  iVar1 = RECORD_LAYER_read_pending(param_1 + 0x650);
  if (((iVar1 == 0) && (iVar1 = RECORD_LAYER_write_pending(param_1 + 0x650), iVar1 == 0)) &&
     ((param_2 != 0 || (iVar1 = SSL_in_init(param_1), iVar1 == 0)))) {
    ossl_statem_set_renegotiate(param_1);
    iVar1 = *(int *)(param_1 + 0x7c);
    *(undefined4 *)(iVar1 + 0xf0) = 0;
    *(int *)(iVar1 + 0xf8) = *(int *)(iVar1 + 0xf8) + 1;
    *(int *)(iVar1 + 0xf4) = *(int *)(iVar1 + 0xf4) + 1;
    return 1;
  }
  return 0;
}

