
ssize_t v9_key_read(void *param_1,size_t param_2)

{
  ssize_t sVar1;
  
  lseek(cgpu._44_4_,0,0);
  sVar1 = read(cgpu._44_4_,param_1,param_2);
  return sVar1;
}

