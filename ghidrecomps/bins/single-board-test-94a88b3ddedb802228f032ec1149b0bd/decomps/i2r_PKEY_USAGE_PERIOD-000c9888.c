
undefined4
i2r_PKEY_USAGE_PERIOD
          (undefined4 param_1,ASN1_GENERALIZEDTIME **param_2,BIO *param_3,undefined4 param_4)

{
  BIO_printf(param_3,DAT_000c98dc,param_4,DAT_000c98d8,param_4);
  if (*param_2 != (ASN1_GENERALIZEDTIME *)0x0) {
    BIO_write(param_3,DAT_000c98e0,0xc);
    ASN1_GENERALIZEDTIME_print(param_3,*param_2);
    if (param_2[1] == (ASN1_GENERALIZEDTIME *)0x0) {
      return 1;
    }
    BIO_write(param_3,DAT_000c98e4,2);
  }
  if (param_2[1] != (ASN1_GENERALIZEDTIME *)0x0) {
    BIO_write(param_3,DAT_000c98e8,0xb);
    ASN1_GENERALIZEDTIME_print(param_3,param_2[1]);
  }
  return 1;
}

