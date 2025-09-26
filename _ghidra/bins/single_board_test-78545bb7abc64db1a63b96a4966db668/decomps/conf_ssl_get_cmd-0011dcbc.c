
void conf_ssl_get_cmd(int param_1,int param_2,undefined4 *param_3,undefined4 *param_4)

{
  *param_3 = *(undefined4 *)(param_1 + param_2 * 8);
  *param_4 = *(undefined4 *)(param_1 + param_2 * 8 + 4);
  return;
}

