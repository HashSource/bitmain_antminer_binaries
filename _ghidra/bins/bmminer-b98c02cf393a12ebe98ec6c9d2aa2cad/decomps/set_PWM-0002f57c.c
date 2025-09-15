
void set_PWM(int param_1)

{
  int iVar1;
  undefined *puVar2;
  
  iVar1 = dev;
  if (param_1 < 0x14) {
    param_1 = 0x14;
    puVar2 = &DAT_000a0028;
  }
  else if (param_1 < 0x65) {
    puVar2 = (undefined *)((param_1 >> 1) << 0x10 | 100 - param_1 >> 1);
  }
  else {
    param_1 = 100;
    puVar2 = (undefined *)0x320000;
  }
  *(undefined **)(dev + 4) = puVar2;
  *(char *)(iVar1 + 0x53fc) = (char)param_1;
  set_fan_control(puVar2);
  return;
}

