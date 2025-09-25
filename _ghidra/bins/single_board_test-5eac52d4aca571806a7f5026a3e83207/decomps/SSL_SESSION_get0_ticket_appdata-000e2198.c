
undefined4 SSL_SESSION_get0_ticket_appdata(int param_1,undefined4 *param_2,undefined4 *param_3)

{
  undefined4 uVar1;
  
  uVar1 = *(undefined4 *)(param_1 + 0x1f8);
  *param_2 = *(undefined4 *)(param_1 + 500);
  *param_3 = uVar1;
  return 1;
}

