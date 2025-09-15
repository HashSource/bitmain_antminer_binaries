
undefined4 surewarehk_ctrl(undefined4 param_1,int param_2,undefined4 param_3,BIO *param_4)

{
  BIO *pBVar1;
  undefined4 uVar2;
  int iVar3;
  
  if (param_2 == 1) {
    CRYPTO_lock(9,0x1e,"e_sureware.c",0x19a);
    if (logstream != (BIO *)0x0) {
      BIO_free(logstream);
      logstream = (BIO *)0x0;
    }
    iVar3 = CRYPTO_add_lock(&param_4->references,1,0x15,"e_sureware.c",0x19f);
    pBVar1 = param_4;
    if (iVar3 < 2) {
      if (SUREWARE_lib_error_code == 0) {
        SUREWARE_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(SUREWARE_lib_error_code,100,100,"e_sureware.c",0x1a3);
      pBVar1 = logstream;
    }
    logstream = pBVar1;
    CRYPTO_lock(10,0x1e,"e_sureware.c",0x1a5);
    uVar2 = 1;
  }
  else if (param_2 == 0x65) {
    CRYPTO_lock(9,0x1e,"e_sureware.c",0x1af);
    threadsafe = 0;
    CRYPTO_lock(10,0x1e,"e_sureware.c",0x1b1);
    uVar2 = 1;
  }
  else {
    if (SUREWARE_lib_error_code == 0) {
      SUREWARE_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(SUREWARE_lib_error_code,100,0x77,"e_sureware.c",0x1b7);
    uVar2 = 0;
  }
  return uVar2;
}

