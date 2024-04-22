
void submit_nonce_2(undefined4 param_1)

{
  undefined4 uVar1;
  
  uVar1 = make_work();
  _copy_work(uVar1,param_1,0);
  submit_work_async(uVar1);
  return;
}

