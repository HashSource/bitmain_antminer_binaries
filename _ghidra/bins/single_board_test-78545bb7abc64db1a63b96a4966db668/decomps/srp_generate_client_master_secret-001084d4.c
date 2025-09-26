
undefined4 srp_generate_client_master_secret(int param_1)

{
  int iVar1;
  BIGNUM *a;
  char *__s;
  BIGNUM *a_00;
  BIGNUM *a_01;
  int iVar2;
  uchar *to;
  undefined4 uVar3;
  size_t sVar4;
  
  iVar1 = SRP_Verify_B_mod_N(*(undefined4 *)(param_1 + 0x62c),*(undefined4 *)(param_1 + 0x620));
  if ((iVar1 == 0) ||
     (a = (BIGNUM *)
          SRP_Calc_u(*(undefined4 *)(param_1 + 0x630),*(undefined4 *)(param_1 + 0x62c),
                     *(undefined4 *)(param_1 + 0x620)), a == (BIGNUM *)0x0)) {
    a = (BIGNUM *)0x0;
LAB_001085bc:
    ossl_statem_fatal(param_1,0x50,0x253,0x44,"ssl/tls_srp.c",0x126);
  }
  else {
    if (*(code **)(param_1 + 0x618) == (code *)0x0) goto LAB_001085bc;
    __s = (char *)(**(code **)(param_1 + 0x618))(param_1,*(undefined4 *)(param_1 + 0x60c));
    if (__s != (char *)0x0) {
      a_00 = (BIGNUM *)
             SRP_Calc_x(*(undefined4 *)(param_1 + 0x628),*(undefined4 *)(param_1 + 0x61c),__s);
      if (a_00 == (BIGNUM *)0x0) {
LAB_001085e8:
        uVar3 = 0xffffffff;
        ossl_statem_fatal(param_1,0x50,0x253,0x44,"ssl/tls_srp.c",0x136);
        a_01 = (BIGNUM *)0x0;
      }
      else {
        a_01 = (BIGNUM *)
               SRP_Calc_client_key(*(undefined4 *)(param_1 + 0x620),*(undefined4 *)(param_1 + 0x62c)
                                   ,*(undefined4 *)(param_1 + 0x624),a_00,
                                   *(undefined4 *)(param_1 + 0x634),a);
        if (a_01 == (BIGNUM *)0x0) goto LAB_001085e8;
        iVar2 = BN_num_bits(a_01);
        iVar1 = iVar2 + 0xe;
        if (-1 < iVar2 + 7) {
          iVar1 = iVar2 + 7;
        }
        to = (uchar *)CRYPTO_malloc(iVar1 >> 3,"ssl/tls_srp.c",0x13b);
        if (to == (uchar *)0x0) {
          uVar3 = 0xffffffff;
          ossl_statem_fatal(param_1,0x50,0x253,0x41,"ssl/tls_srp.c",0x13d);
        }
        else {
          BN_bn2bin(a_01,to);
          uVar3 = ssl_generate_master_secret(param_1,to,iVar1 >> 3,1);
        }
      }
      BN_clear_free(a_01);
      BN_clear_free(a_00);
      sVar4 = strlen(__s);
      CRYPTO_clear_free(__s,sVar4,"ssl/tls_srp.c",0x147);
      goto LAB_001085ac;
    }
    ossl_statem_fatal(param_1,0x50,0x253,0xea,"ssl/tls_srp.c",0x12e);
  }
  uVar3 = 0xffffffff;
  BN_clear_free((BIGNUM *)0x0);
  BN_clear_free((BIGNUM *)0x0);
LAB_001085ac:
  BN_clear_free(a);
  return uVar3;
}

