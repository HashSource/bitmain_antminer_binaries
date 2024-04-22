
undefined4 submit_nonce_direct(undefined4 param_1,int param_2,undefined4 param_3)

{
  undefined4 uVar1;
  
  *(undefined4 *)(param_2 + 0x4c) = param_3;
  uVar1 = make_work();
  _copy_work(uVar1,param_2,0);
  submit_work_async(uVar1);
  return 1;
}

