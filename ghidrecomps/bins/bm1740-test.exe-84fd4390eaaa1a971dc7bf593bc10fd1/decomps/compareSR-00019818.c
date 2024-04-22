
int compareSR(void *param_1,void *param_2)

{
  int iVar1;
  
  iVar1 = memcmp(param_1,param_2,compare_size);
  return iVar1;
}

