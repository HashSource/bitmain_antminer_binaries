
undefined4
get_queue_work(undefined4 param_1,undefined4 param_2,undefined4 param_3,undefined4 param_4)

{
  undefined4 uVar1;
  
  uVar1 = get_work(param_1,param_3,param_3,param_4,param_4);
  add_queued(param_2,uVar1);
  return uVar1;
}

