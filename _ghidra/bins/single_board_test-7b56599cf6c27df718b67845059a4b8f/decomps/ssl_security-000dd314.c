
void ssl_security(int param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4,
                 undefined4 param_5)

{
  (**(code **)(*(int *)(param_1 + 0x404) + 0xf8))
            (param_1,0,param_2,param_3,param_4,param_5,
             *(undefined4 *)(*(int *)(param_1 + 0x404) + 0x100));
  return;
}

