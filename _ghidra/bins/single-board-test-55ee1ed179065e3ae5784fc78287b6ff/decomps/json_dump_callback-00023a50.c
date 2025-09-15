
undefined4 json_dump_callback(int *param_1,undefined4 param_2,undefined4 param_3,uint param_4)

{
  undefined4 uVar1;
  
  if ((((param_4 & 0x200) == 0) && ((param_1 == (int *)0x0 || (*param_1 != 1)))) &&
     ((param_1 == (int *)0x0 || (*param_1 != 0)))) {
    uVar1 = 0xffffffff;
  }
  else {
    uVar1 = do_dump(param_1,param_4,0,param_2,param_3);
  }
  return uVar1;
}

