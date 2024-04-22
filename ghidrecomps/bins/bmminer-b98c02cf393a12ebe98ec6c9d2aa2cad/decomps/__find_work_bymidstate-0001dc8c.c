
int __find_work_bymidstate
              (int param_1,void *param_2,size_t param_3,void *param_4,int param_5,size_t param_6)

{
  int iVar1;
  int iVar2;
  
  if (param_1 != 0) {
    iVar2 = *(int *)(param_1 + 0x160);
    for (; ((iVar1 = memcmp((void *)(param_1 + 0x80),param_2,param_3), iVar1 != 0 ||
            (iVar1 = memcmp((void *)(param_1 + param_5),param_4,param_6), iVar1 != 0)) &&
           (param_1 = iVar2, iVar2 != 0)); iVar2 = *(int *)(iVar2 + 0x160)) {
    }
  }
  return param_1;
}

