
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

ERR_STATE * ERR_get_state(void)

{
  int *piVar1;
  int iVar2;
  ERR_STATE *ptr;
  int iVar3;
  
  piVar1 = __errno_location();
  iVar3 = *piVar1;
  iVar2 = OPENSSL_init_crypto(0x40000,0,0);
  if ((((iVar2 == 0) || (iVar2 = CRYPTO_THREAD_run_once(&err_init,0x123019), iVar2 == 0)) ||
      (err_do_init_ossl_ret_ == 0)) ||
     (ptr = (ERR_STATE *)CRYPTO_THREAD_get_local(&err_thread_local), ptr == (ERR_STATE *)0xffffffff)
     ) {
    return (ERR_STATE *)0x0;
  }
  if (ptr == (ERR_STATE *)0x0) {
    iVar2 = CRYPTO_THREAD_set_local(&err_thread_local,0xffffffff);
    if (iVar2 == 0) {
      return (ERR_STATE *)0x0;
    }
    ptr = (ERR_STATE *)CRYPTO_zalloc(0x188,"crypto/err/err.c",0x2fe);
    if (ptr == (ERR_STATE *)0x0) {
      CRYPTO_THREAD_set_local(&err_thread_local,0);
      return (ERR_STATE *)0x0;
    }
    iVar2 = ossl_init_thread_start(2,0);
    if ((iVar2 == 0) || (iVar2 = CRYPTO_THREAD_set_local(&err_thread_local,ptr), iVar2 == 0)) {
      if ((int)ptr->err_data[0xe] << 0x1f < 0) {
        CRYPTO_free((void *)ptr->err_buffer[0xe]);
        ptr->err_buffer[0xe] = 0;
      }
      ptr->err_data[0xe] = (char *)0x0;
      if ((int)ptr->err_data[0xf] << 0x1f < 0) {
        CRYPTO_free((void *)ptr->err_buffer[0xf]);
        ptr->err_buffer[0xf] = 0;
      }
      iVar2 = ptr->err_data_flags[0];
      ptr->err_data[0xf] = (char *)0x0;
      if (iVar2 << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[0]);
        ptr->err_data[0] = (char *)0x0;
      }
      iVar2 = ptr->err_data_flags[1];
      ptr->err_data_flags[0] = 0;
      if (iVar2 << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[1]);
        ptr->err_data[1] = (char *)0x0;
      }
      ptr->err_data_flags[1] = 0;
      if (ptr->err_data_flags[2] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[2]);
        ptr->err_data[2] = (char *)0x0;
      }
      ptr->err_data_flags[2] = 0;
      if (ptr->err_data_flags[3] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[3]);
        ptr->err_data[3] = (char *)0x0;
      }
      ptr->err_data_flags[3] = 0;
      if (ptr->err_data_flags[4] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[4]);
        ptr->err_data[4] = (char *)0x0;
      }
      ptr->err_data_flags[4] = 0;
      if (ptr->err_data_flags[5] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[5]);
        ptr->err_data[5] = (char *)0x0;
      }
      ptr->err_data_flags[5] = 0;
      if (ptr->err_data_flags[6] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[6]);
        ptr->err_data[6] = (char *)0x0;
      }
      ptr->err_data_flags[6] = 0;
      if (ptr->err_data_flags[7] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[7]);
        ptr->err_data[7] = (char *)0x0;
      }
      ptr->err_data_flags[7] = 0;
      if (ptr->err_data_flags[8] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[8]);
        ptr->err_data[8] = (char *)0x0;
      }
      ptr->err_data_flags[8] = 0;
      if (ptr->err_data_flags[9] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[9]);
        ptr->err_data[9] = (char *)0x0;
      }
      ptr->err_data_flags[9] = 0;
      if (ptr->err_data_flags[10] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[10]);
        ptr->err_data[10] = (char *)0x0;
      }
      ptr->err_data_flags[10] = 0;
      if (ptr->err_data_flags[0xb] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[0xb]);
        ptr->err_data[0xb] = (char *)0x0;
      }
      ptr->err_data_flags[0xb] = 0;
      if (ptr->err_data_flags[0xc] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[0xc]);
        ptr->err_data[0xc] = (char *)0x0;
      }
      ptr->err_data_flags[0xc] = 0;
      if (ptr->err_data_flags[0xd] << 0x1f < 0) {
        CRYPTO_free(ptr->err_data[0xd]);
        ptr->err_data[0xd] = (char *)0x0;
      }
      ptr->err_data_flags[0xd] = 0;
      CRYPTO_free(ptr);
      CRYPTO_THREAD_set_local(&err_thread_local,0);
      return (ERR_STATE *)0x0;
    }
    OPENSSL_init_crypto(2,0,0);
  }
  *piVar1 = iVar3;
  return ptr;
}

