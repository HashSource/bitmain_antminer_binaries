
void jsonp_error_init(undefined4 *param_1,int param_2)

{
  if (param_1 != (undefined4 *)0x0) {
    *(undefined *)(param_1 + 0x17) = 0;
    *param_1 = 0xffffffff;
    param_1[1] = 0xffffffff;
    param_1[2] = 0;
    if (param_2 == 0) {
      *(undefined *)(param_1 + 3) = 0;
    }
    else {
      jsonp_error_set_source(param_1,param_2);
    }
  }
  return;
}

