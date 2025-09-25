
undefined4 srp_generate_server_master_secret(int param_1)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar2;
  uchar *to;
  undefined4 uVar3;
  
  iVar1 = SRP_Verify_A_mod_N(*(undefined4 *)(param_1 + 0x630),*(undefined4 *)(param_1 + 0x620));
  if ((iVar1 == 0) ||
     (a = (BIGNUM *)
          SRP_Calc_u(*(undefined4 *)(param_1 + 0x630),*(undefined4 *)(param_1 + 0x62c),
                     *(undefined4 *)(param_1 + 0x620)), a == (BIGNUM *)0x0)) {
    a = (BIGNUM *)0x0;
    uVar3 = 0xffffffff;
    a_00 = (BIGNUM *)0x0;
  }
  else {
    a_00 = (BIGNUM *)
           SRP_Calc_server_key(*(undefined4 *)(param_1 + 0x630),*(undefined4 *)(param_1 + 0x63c),a,
                               *(undefined4 *)(param_1 + 0x638),*(undefined4 *)(param_1 + 0x620));
    if (a_00 == (BIGNUM *)0x0) {
      uVar3 = 0xffffffff;
    }
    else {
      iVar2 = BN_num_bits(a_00);
      iVar1 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar1 = iVar2 + 7;
      }
      to = (uchar *)CRYPTO_malloc(iVar1 >> 3,"ssl/tls_srp.c",0x108);
      if (to == (uchar *)0x0) {
        uVar3 = 0xffffffff;
        ossl_statem_fatal(param_1,0x50,0x24d,0x41,"ssl/tls_srp.c",0x10a);
      }
      else {
        BN_bn2bin(a_00,to);
        uVar3 = ssl_generate_master_secret(param_1,to,iVar1 >> 3,1);
      }
    }
  }
  BN_clear_free(a_00);
  BN_clear_free(a);
  return uVar3;
}

