
int SSL_SESSION_get0_id_context(int param_1,undefined4 *param_2)

{
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x16c);
  }
  return param_1 + 0x170;
}

