
void SSL_SESSION_get0_ticket(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  *param_3 = *(undefined4 *)(param_1 + 0x1d4);
  if (param_2 != (undefined4 *)0x0) {
    *param_2 = *(undefined4 *)(param_1 + 0x1d0);
  }
  return;
}

