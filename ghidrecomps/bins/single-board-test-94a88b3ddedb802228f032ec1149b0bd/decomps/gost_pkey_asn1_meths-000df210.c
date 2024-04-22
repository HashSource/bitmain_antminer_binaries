
undefined4
gost_pkey_asn1_meths(undefined4 param_1,undefined4 *param_2,undefined4 *param_3,int param_4)

{
  if (param_2 == (undefined4 *)0x0) {
    *param_3 = DAT_000df258;
    return 3;
  }
  if (param_4 == 0x32c) {
    *param_2 = *(undefined4 *)(DAT_000df25c + 0xc);
    return 1;
  }
  if (param_4 == 0x32f) {
    *param_2 = *(undefined4 *)(DAT_000df25c + 0x14);
    return 1;
  }
  if (param_4 != 0x32b) {
    *param_2 = 0;
    return 0;
  }
  *param_2 = *(undefined4 *)(DAT_000df25c + 0x10);
  return 1;
}

