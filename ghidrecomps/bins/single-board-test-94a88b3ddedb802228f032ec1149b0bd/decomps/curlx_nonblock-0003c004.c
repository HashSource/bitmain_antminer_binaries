
void curlx_nonblock(int param_1,int param_2,undefined4 param_3,undefined4 param_4)

{
  uint uVar1;
  
  uVar1 = fcntl(param_1,3,0);
  if (param_2 == 0) {
    uVar1 = uVar1 & 0xfffff7ff;
  }
  else {
    uVar1 = uVar1 | 0x800;
  }
  (*(code *)PTR_fcntl_00194318)(param_1,4,uVar1,param_4);
  return;
}

