
void suffix_string_c5_constprop_16
               (undefined *param_1,uint param_2,char *param_3,size_t param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  double dVar3;
  double dVar4;
  double in_stack_ffffffb8;
  undefined2 local_34 [2];
  
  bVar2 = param_2 <= DAT_0002d26c;
  local_34[0] = 0;
  if (DAT_0002d26c == param_2) {
    bVar2 = param_1 <= DAT_0002d268;
  }
  if (bVar2) {
    bVar2 = param_2 == 0;
    if (param_2 == 0) {
      bVar2 = param_1 < &DAT_000f4240;
    }
    if (bVar2) {
      if (param_2 == 0 && param_1 < (undefined *)0x3e8) {
        if (param_5 == 0) {
          snprintf(param_3,param_4,"%d%s",param_1,local_34);
          return;
        }
        dVar4 = (double)(longlong)(int)param_1;
        goto LAB_0002d15a;
      }
      local_34[0] = 0x4b;
      dVar4 = (double)(longlong)(int)param_1 / DAT_0002d258;
    }
    else {
      iVar1 = __aeabi_uldivmod(param_1,param_2,1000,0);
      local_34[0] = 0x4d;
      dVar4 = (double)(longlong)iVar1 / DAT_0002d258;
    }
  }
  else {
    __aeabi_uldivmod(param_1,param_2,&DAT_000f4240,0);
    dVar4 = (double)__floatundidf();
    local_34[0] = 0x47;
    dVar4 = dVar4 / DAT_0002d258;
  }
  if (param_5 == 0) {
    snprintf(param_3,param_4,"%.3g%s",local_34,dVar4,local_34);
    return;
  }
LAB_0002d15a:
  dVar3 = DAT_0002d260;
  if (dVar4 != 0.0 && dVar4 < 0.0 == NAN(dVar4)) {
    log10(in_stack_ffffffb8);
    dVar3 = floor(in_stack_ffffffb8);
  }
  snprintf(param_3,param_4,"%*.*f",param_5 + 1,
           (int)(longlong)((double)(longlong)(param_5 + -1) - dVar3));
  return;
}

