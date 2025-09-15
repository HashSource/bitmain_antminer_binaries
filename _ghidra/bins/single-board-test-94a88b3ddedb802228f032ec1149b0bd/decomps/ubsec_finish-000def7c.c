
undefined4 ubsec_finish(void)

{
  int iVar1;
  undefined4 uVar2;
  
  if (UBSEC_LIBNAME != (void *)0x0) {
    CRYPTO_free(UBSEC_LIBNAME);
  }
  UBSEC_LIBNAME = (void *)0x0;
  if (ubsec_dso == (DSO *)0x0) {
    if (UBSEC_lib_error_code == 0) {
      UBSEC_lib_error_code = ERR_get_next_error_library();
    }
    ERR_put_error(UBSEC_lib_error_code,0x68,0x69,"e_ubsec.c",0x203);
    uVar2 = 0;
  }
  else {
    iVar1 = DSO_free(ubsec_dso);
    if (iVar1 == 0) {
      if (UBSEC_lib_error_code == 0) {
        UBSEC_lib_error_code = ERR_get_next_error_library();
      }
      ERR_put_error(UBSEC_lib_error_code,0x68,0x67,"e_ubsec.c",0x207);
      uVar2 = 0;
    }
    else {
      uVar2 = 1;
      ubsec_dso = (DSO *)0x0;
      p_UBSEC_ubsec_bytes_to_bits = 0;
      p_UBSEC_ubsec_bits_to_bytes = 0;
      p_UBSEC_ubsec_open = 0;
      p_UBSEC_ubsec_close = 0;
      p_UBSEC_diffie_hellman_generate_ioctl = 0;
      p_UBSEC_diffie_hellman_agree_ioctl = 0;
      p_UBSEC_rsa_mod_exp_ioctl = 0;
      p_UBSEC_rsa_mod_exp_crt_ioctl = 0;
      p_UBSEC_dsa_sign_ioctl = 0;
      p_UBSEC_dsa_verify_ioctl = 0;
      p_UBSEC_math_accelerate_ioctl = 0;
      p_UBSEC_rng_ioctl = 0;
      p_UBSEC_max_key_len_ioctl = 0;
    }
  }
  return uVar2;
}

