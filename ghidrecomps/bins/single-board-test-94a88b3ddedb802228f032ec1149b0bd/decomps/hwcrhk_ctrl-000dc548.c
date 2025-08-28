
undefined4 hwcrhk_ctrl(undefined4 param_1,int param_2,int param_3,BIO *param_4,undefined4 param_5)

{
  BIO *pBVar1;
  int iVar2;
  
  if (param_2 == 0x65) {
    CRYPTO_lock(9,0x1e,"e_chil.c",0x2e9);
    disable_mutex_callbacks = 1;
    CRYPTO_lock(10,0x1e,"e_chil.c",0x2eb);
    return 1;
  }
  if (param_2 < 0x66) {
    if (param_2 == 4) {
LAB_000dc66e:
      CRYPTO_lock(9,0x1e,"e_chil.c",0x2ca);
      password_context._4_4_ = param_4;
      CRYPTO_lock(10,0x1e,"e_chil.c",0x2cc);
      return 1;
    }
    if (param_2 < 5) {
      if (param_2 == 1) {
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2b7);
        if (logstream != (BIO *)0x0) {
          BIO_free(logstream);
          logstream = (BIO *)0x0;
        }
        iVar2 = CRYPTO_add_lock(&param_4->references,1,0x15,"e_chil.c",700);
        pBVar1 = param_4;
        if (iVar2 < 2) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(HWCRHK_lib_error_code,100,0x65,"e_chil.c",0x2bf);
          pBVar1 = logstream;
        }
        logstream = pBVar1;
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2c1);
        return 1;
      }
      if (param_2 == 2) {
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2c4);
        password_context._0_4_ = param_5;
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2c6);
        return 1;
      }
    }
    else {
      if (param_2 == 5) goto LAB_000dc5ce;
      if (param_2 == 100) goto LAB_000dc596;
    }
  }
  else {
    if (param_2 == 0xca) {
      CRYPTO_lock(9,0x1e,"e_chil.c",0x2ee);
      if (param_3 != 0) {
        param_3 = 1;
      }
      disable_mutex_callbacks = param_3;
      CRYPTO_lock(10,0x1e,"e_chil.c",0x2f0);
      return 1;
    }
    if (param_2 < 0xcb) {
      if (param_2 == 200) {
        if (hwcrhk_dso != 0) {
          if (HWCRHK_lib_error_code == 0) {
            HWCRHK_lib_error_code = ERR_get_next_error_library();
          }
          ERR_put_error(HWCRHK_lib_error_code,100,100,"e_chil.c",0x2ab);
          return 0;
        }
        if (param_4 != (BIO *)0x0) {
          if (HWCRHK_LIBNAME != (char *)0x0) {
            CRYPTO_free(HWCRHK_LIBNAME);
          }
          HWCRHK_LIBNAME = (char *)0x0;
          HWCRHK_LIBNAME = BUF_strdup((char *)param_4);
          if (HWCRHK_LIBNAME == (char *)0x0) {
            return 0;
          }
          return 1;
        }
        if (HWCRHK_lib_error_code == 0) {
          HWCRHK_lib_error_code = ERR_get_next_error_library();
        }
        ERR_put_error(HWCRHK_lib_error_code,100,0x43,"e_chil.c",0x2af);
        return 0;
      }
      if (param_2 == 0xc9) {
LAB_000dc596:
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2da);
        if (param_3 == 0) {
          hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ & 0xffffffef;
        }
        else {
          hwcrhk_globals._0_4_ = hwcrhk_globals._0_4_ | 0x10;
        }
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2df);
        return 1;
      }
    }
    else {
      if (param_2 == 0xcb) goto LAB_000dc66e;
      if (param_2 == 0xcc) {
LAB_000dc5ce:
        CRYPTO_lock(9,0x1e,"e_chil.c",0x2d0);
        password_context._8_4_ = param_4;
        CRYPTO_lock(10,0x1e,"e_chil.c",0x2d2);
        return 1;
      }
    }
  }
  if (HWCRHK_lib_error_code == 0) {
    HWCRHK_lib_error_code = ERR_get_next_error_library();
  }
  ERR_put_error(HWCRHK_lib_error_code,100,0x67,"e_chil.c",0x2f6);
  return 0;
}

