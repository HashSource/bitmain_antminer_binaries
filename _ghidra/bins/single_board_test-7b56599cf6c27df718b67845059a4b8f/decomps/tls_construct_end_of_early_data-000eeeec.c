
undefined4 tls_construct_end_of_early_data(int param_1)

{
  if ((*(uint *)(param_1 + 0x68) & 0xfffffffb) == 3) {
    *(undefined4 *)(param_1 + 0x68) = 7;
    return 1;
  }
  ossl_statem_fatal(param_1,0x50,0x218,0x42,"ssl/statem/statem_clnt.c",0xf09);
  return 0;
}

