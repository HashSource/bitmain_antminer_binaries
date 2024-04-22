
undefined8 rotr64(uint param_1,uint param_2,uint param_3)

{
  uint uVar1;
  
  uVar1 = -param_3 + 0x40;
  return CONCAT44(param_2 << (uVar1 & 0xff) | param_1 << (-param_3 + 0x20 & 0xff) |
                  param_1 >> (0x20 - uVar1 & 0xff) | param_2 >> (param_3 & 0xff),
                  param_1 << (uVar1 & 0xff) |
                  param_1 >> (param_3 & 0xff) | param_2 << (0x20 - param_3 & 0xff) |
                  param_2 >> (param_3 - 0x20 & 0xff));
}

