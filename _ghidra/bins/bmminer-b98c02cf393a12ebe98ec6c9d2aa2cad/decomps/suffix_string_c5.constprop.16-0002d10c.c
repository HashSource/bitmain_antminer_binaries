
void suffix_string_c5_constprop_16
               (undefined *param_1,int param_2,char *param_3,size_t param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  double dVar3;
  undefined2 local_34 [2];
  
  bVar2 = param_2 == 0;
  local_34[0] = 0;
  if (param_2 == 0) {
    bVar2 = param_1 < (undefined *)0x3b9aca00;
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
        dVar3 = (double)(longlong)(int)param_1;
        goto LAB_0002d15a;
      }
      dVar3 = (double)(longlong)(int)param_1;
      local_34[0] = 0x4b;
    }
    else {
      iVar1 = __aeabi_uldivmod(param_1,param_2,1000,0);
      dVar3 = (double)(longlong)iVar1;
      local_34[0] = 0x4d;
    }
  }
  else {
    __aeabi_uldivmod(param_1,param_2,&DAT_000f4240,0);
    dVar3 = (double)__floatundidf();
    local_34[0] = 0x47;
  }
  dVar3 = dVar3 / 1000.0;
  if (param_5 == 0) {
    snprintf(param_3,param_4,"%.3g%s",local_34,dVar3,local_34);
    return;
  }
LAB_0002d15a:
  if (dVar3 <= 0.0) {
    dVar3 = 0.0;
  }
  else {
    dVar3 = log10(dVar3);
    dVar3 = floor(dVar3);
  }
  snprintf(param_3,param_4,"%*.*f",param_5 + 1,
           (int)(longlong)((double)(longlong)(param_5 + -1) - dVar3));
  return;
}

