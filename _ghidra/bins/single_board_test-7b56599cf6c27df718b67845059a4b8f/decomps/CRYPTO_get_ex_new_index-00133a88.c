
int CRYPTO_get_ex_new_index
              (int class_index,long argl,void *argp,undefined1 *new_func,undefined1 *dup_func,
              undefined1 *free_func)

{
  int iVar1;
  long *ptr;
  int iVar2;
  
  if (0xf < (uint)class_index) {
    ERR_put_error(0xf,0x71,7,"crypto/ex_data.c",0x37);
    return -1;
  }
  iVar1 = CRYPTO_THREAD_run_once(&ex_data_init,0x133955);
  if ((iVar1 == 0) || (do_ex_data_init_ossl_ret_ == 0)) {
    ERR_put_error(0xf,0x71,0x41,"crypto/ex_data.c",0x3c);
    return -1;
  }
  if (ex_data_lock == 0) {
    return -1;
  }
  iVar1 = class_index * 4;
  CRYPTO_THREAD_write_lock();
  if (*(int *)(ex_data + iVar1) == 0) {
    iVar2 = OPENSSL_sk_new_null();
    *(int *)(ex_data + iVar1) = iVar2;
    if ((iVar2 != 0) && (iVar2 = OPENSSL_sk_push(iVar2,0), iVar2 != 0)) goto LAB_00133ac8;
    iVar1 = 0xac;
  }
  else {
LAB_00133ac8:
    ptr = (long *)CRYPTO_malloc(0x14,"crypto/ex_data.c",0xb1);
    if (ptr != (long *)0x0) {
      *ptr = argl;
      ptr[1] = (long)argp;
      ptr[2] = (long)new_func;
      ptr[4] = (long)dup_func;
      ptr[3] = (long)free_func;
      iVar2 = OPENSSL_sk_push(*(undefined4 *)(ex_data + iVar1),0);
      if (iVar2 == 0) {
        ERR_put_error(0xf,100,0x41,"crypto/ex_data.c",0xbd);
        iVar2 = -1;
        CRYPTO_free(ptr);
      }
      else {
        iVar2 = OPENSSL_sk_num(*(undefined4 *)(ex_data + iVar1));
        iVar2 = iVar2 + -1;
        OPENSSL_sk_set(*(undefined4 *)(ex_data + iVar1),iVar2,ptr);
      }
      goto LAB_00133b10;
    }
    iVar1 = 0xb3;
  }
  ERR_put_error(0xf,100,0x41,"crypto/ex_data.c",iVar1);
  iVar2 = -1;
LAB_00133b10:
  CRYPTO_THREAD_unlock(ex_data_lock);
  return iVar2;
}

