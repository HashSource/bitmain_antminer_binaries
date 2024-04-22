
void set_PWM_according_to_temperature(void)

{
  char cVar1;
  
  if (*(int *)(highest_temp + (uint)gChain * 4) < (int)(uint)Conf[212]) {
    fan_control(0);
  }
  else if (*(int *)(highest_temp + (uint)gChain * 4) < 0x32) {
    fan_control(0x28);
  }
  else if (*(int *)(highest_temp + (uint)gChain * 4) < (int)(uint)Conf[213]) {
    cVar1 = __aeabi_idiv(*(int *)(highest_temp + (uint)gChain * 4) * 0x3c + -3000,Conf[213] - 0x32);
    fan_control(cVar1 + '(');
  }
  else {
    fan_control(100);
  }
  return;
}

