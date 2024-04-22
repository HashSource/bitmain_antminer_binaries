
void block_socket(int param_1)

{
  uint uVar1;
  
  uVar1 = fcntl(param_1,3,0);
  (*(code *)PTR_fcntl_0007cf90)(param_1,4,uVar1 & 0xfffff7ff);
  return;
}

