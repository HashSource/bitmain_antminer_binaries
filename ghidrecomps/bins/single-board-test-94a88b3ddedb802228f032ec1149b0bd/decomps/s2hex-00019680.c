
int s2hex(int param_1,int param_2,uint param_3)

{
  undefined uVar1;
  FILE *__stream;
  int iVar2;
  uint uVar3;
  int local_14;
  
  if (((param_2 == 0) || ((int)param_3 < 1)) || (param_1 == 0)) {
    if (3 < log_level) {
      __stream = fopen(log_file,"a+");
      if (__stream != (FILE *)0x0) {
        fprintf(__stream,"%s:%d: s2hex para error dst(%p), src(%p), inlen(%d)\n","driver-bitmain.c",
                0x2b7,param_1,param_2,param_3);
      }
      fclose(__stream);
    }
    iVar2 = -1;
  }
  else {
    uVar3 = param_3 & 1;
    if ((int)param_3 < 0) {
      uVar3 = -uVar3;
    }
    for (local_14 = 0; local_14 < (int)param_3 / 2; local_14 = local_14 + 1) {
      uVar1 = twoc2hex(*(undefined *)(param_2 + local_14 * 2),
                       *(undefined *)(local_14 * 2 + 1 + param_2));
      *(undefined *)(param_1 + local_14) = uVar1;
    }
    if (uVar3 != 0) {
      uVar1 = twoc2hex(*(undefined *)(param_2 + local_14 * 2),0);
      *(undefined *)(param_1 + local_14) = uVar1;
    }
    iVar2 = uVar3 + (int)param_3 / 2;
  }
  return iVar2;
}

