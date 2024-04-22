
undefined4 read_key(undefined param_1)

{
  undefined4 uVar1;
  undefined local_11 [5];
  ssize_t local_c;
  
  local_c = 0;
  local_11[0] = param_1;
  lseek(key_fd,0,0);
  local_c = read(key_fd,local_11,1);
  if (local_c == 1) {
    uVar1 = 1;
  }
  else {
    printf("%s: can\'t read out key value\n","read_key");
    uVar1 = 0xffffffff;
  }
  return uVar1;
}

