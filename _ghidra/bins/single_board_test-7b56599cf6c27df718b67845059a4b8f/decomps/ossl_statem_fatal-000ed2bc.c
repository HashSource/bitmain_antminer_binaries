
void ossl_statem_fatal(int param_1,int param_2,int param_3,int param_4,char *param_5,int param_6)

{
  ERR_put_error(0x14,param_3,param_4,param_5,param_6);
  if ((*(int *)(param_1 + 0x48) == 0) || (*(int *)(param_1 + 0x2c) != 1)) {
    *(undefined4 *)(param_1 + 0x48) = 1;
    *(undefined4 *)(param_1 + 0x2c) = 1;
    if ((param_2 != -1) && (*(int *)(param_1 + 0x60) != 1)) {
      ssl3_send_alert(param_1,2,param_2);
      return;
    }
  }
  return;
}

