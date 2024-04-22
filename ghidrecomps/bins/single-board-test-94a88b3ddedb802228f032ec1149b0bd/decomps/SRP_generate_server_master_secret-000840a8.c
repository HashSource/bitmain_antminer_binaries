
undefined4 SRP_generate_server_master_secret(int param_1,undefined4 param_2)

{
  int iVar1;
  BIGNUM *a;
  BIGNUM *a_00;
  int iVar2;
  uchar *to;
  undefined4 uVar3;
  size_t len;
  
  iVar1 = SRP_Verify_A_mod_N(*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1a8));
  if ((iVar1 == 0) ||
     (a = (BIGNUM *)
          SRP_Calc_u(*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1b4),
                     *(undefined4 *)(param_1 + 0x1a8)), a == (BIGNUM *)0x0)) {
    a = (BIGNUM *)0x0;
    a_00 = (BIGNUM *)0x0;
  }
  else {
    a_00 = (BIGNUM *)
           SRP_Calc_server_key(*(undefined4 *)(param_1 + 0x1b8),*(undefined4 *)(param_1 + 0x1c4),a,
                               *(undefined4 *)(param_1 + 0x1c0),*(undefined4 *)(param_1 + 0x1a8));
    if (a_00 != (BIGNUM *)0x0) {
      iVar2 = BN_num_bits(a_00);
      iVar1 = iVar2 + 0xe;
      if (-1 < iVar2 + 7) {
        iVar1 = iVar2 + 7;
      }
      len = iVar1 >> 3;
      to = (uchar *)CRYPTO_malloc(len,DAT_00084164,0x162);
      if (to != (uchar *)0x0) {
        BN_bn2bin(a_00,to);
        uVar3 = (**(code **)(*(int *)(*(int *)(param_1 + 8) + 100) + 0xc))(param_1,param_2,to,len);
        OPENSSL_cleanse(to,len);
        CRYPTO_free(to);
        goto LAB_00084144;
      }
    }
  }
  uVar3 = 0xffffffff;
LAB_00084144:
  BN_clear_free(a_00);
  BN_clear_free(a);
  return uVar3;
}

