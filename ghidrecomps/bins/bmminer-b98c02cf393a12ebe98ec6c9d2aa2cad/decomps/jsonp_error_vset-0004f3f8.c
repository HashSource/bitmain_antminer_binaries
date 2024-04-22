
void jsonp_error_vset(undefined4 *param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                     char *param_5,__gnuc_va_list param_6)

{
  if (param_1 != (undefined4 *)0x0) {
    if (*(char *)(param_1 + 0x17) == '\0') {
      *param_1 = param_2;
      param_1[1] = param_3;
      param_1[2] = param_4;
      vsnprintf((char *)(param_1 + 0x17),0xa0,param_5,param_6);
      *(undefined *)((int)param_1 + 0xfb) = 0;
    }
    return;
  }
  return;
}

