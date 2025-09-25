
undefined4 CRYPTO_free_ex_index(uint param_1,int param_2)

{
  int iVar1;
  undefined4 uVar2;
  
  if (0xf < param_1) {
    ERR_put_error(0xf,0x71,7,"crypto/ex_data.c",0x37);
    return 0;
  }
  iVar1 = CRYPTO_THREAD_run_once(&ex_data_init,0x12f705);
  if ((iVar1 == 0) || (do_ex_data_init_ossl_ret_ == 0)) {
    ERR_put_error(0xf,0x71,0x41,"crypto/ex_data.c",0x3c);
    return 0;
  }
  if (ex_data_lock == 0) {
    return 0;
  }
  CRYPTO_THREAD_write_lock();
  if (-1 < param_2) {
    iVar1 = OPENSSL_sk_num(*(undefined4 *)(ex_data + param_1 * 4));
    if ((param_2 < iVar1) &&
       (iVar1 = OPENSSL_sk_value(*(undefined4 *)(ex_data + param_1 * 4),param_2), iVar1 != 0)) {
      uVar2 = 1;
      *(undefined4 *)(iVar1 + 8) = 0x12f735;
      *(undefined4 *)(iVar1 + 0x10) = 0x12f6f1;
      *(undefined4 *)(iVar1 + 0xc) = 0x12f6ed;
      goto LAB_0012f7b6;
    }
  }
  uVar2 = 0;
LAB_0012f7b6:
  CRYPTO_THREAD_unlock(ex_data_lock);
  return uVar2;
}

