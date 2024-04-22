
undefined4 json_dump_callback(uint *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  undefined4 uVar1;
  
  if ((param_4 << 0x16 < 0) || ((param_1 != (uint *)0x0 && (*param_1 < 2)))) {
    uVar1 = do_dump(param_1,param_4,0,param_2,param_3);
  }
  else {
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

