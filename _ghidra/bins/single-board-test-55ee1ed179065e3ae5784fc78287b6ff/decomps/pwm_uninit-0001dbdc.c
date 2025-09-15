
void pwm_uninit(int param_1)

{
  if (param_1 + -1 < 2) {
    *(undefined4 *)(&pwm_param + (param_1 + -1) * 8) = 0;
    (&DAT_00235de8)[(param_1 + -1) * 8] = 0;
  }
  else {
    printf("%s:%d","pwm_uninit",0x1d);
    puts("bad param");
  }
  return;
}

