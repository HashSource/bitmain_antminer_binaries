
void engine_table_unregister(_LHASH **param_1,void *param_2)

{
  CRYPTO_lock(9,0x1e,DAT_00101bc4,0xd1);
  if (*param_1 != (_LHASH *)0x0) {
    lh_doall_arg(*param_1,DAT_00101bc8,param_2);
  }
  CRYPTO_lock(10,0x1e,DAT_00101bc4,0xd6);
  return;
}

