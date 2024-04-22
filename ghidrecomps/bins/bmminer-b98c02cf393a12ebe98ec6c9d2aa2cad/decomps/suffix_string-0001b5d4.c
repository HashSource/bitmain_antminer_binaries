
void suffix_string(undefined *param_1,uint param_2,char *param_3,size_t param_4,int param_5)

{
  int iVar1;
  bool bVar2;
  double dVar3;
  double dVar4;
  double in_stack_ffffffb0;
  undefined2 local_34 [2];
  
  bVar2 = param_2 <= DAT_0001b7c4;
  local_34[0] = 0;
  if (DAT_0001b7c4 == param_2) {
    bVar2 = param_1 <= DAT_0001b7c0;
  }
  if (bVar2) {
    bVar2 = param_2 <= DAT_0001b7d4;
    if (DAT_0001b7d4 == param_2) {
      bVar2 = param_1 <= DAT_0001b7d0;
    }
    if (bVar2) {
      bVar2 = param_2 <= DAT_0001b7e4;
      if (DAT_0001b7e4 == param_2) {
        bVar2 = param_1 <= DAT_0001b7e0;
      }
      if (bVar2) {
        bVar2 = param_2 <= DAT_0001b7ec;
        if (DAT_0001b7ec == param_2) {
          bVar2 = param_1 <= DAT_0001b7e8;
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
              goto LAB_0001b61e;
            }
            local_34[0] = 0x4b;
            dVar4 = (double)(longlong)(int)param_1 / DAT_0001b7b0;
          }
          else {
            iVar1 = __aeabi_uldivmod(param_1,param_2,1000,0);
            local_34[0] = 0x4d;
            dVar4 = (double)(longlong)iVar1 / DAT_0001b7b0;
          }
        }
        else {
          iVar1 = __aeabi_uldivmod(param_1,param_2,&DAT_000f4240,0);
          local_34[0] = 0x47;
          dVar4 = (double)(longlong)iVar1 / DAT_0001b7b0;
        }
      }
      else {
        iVar1 = __aeabi_uldivmod(param_1,param_2,DAT_0001b7f0,DAT_0001b7f4);
        local_34[0] = 0x54;
        dVar4 = (double)(longlong)iVar1 / DAT_0001b7b0;
      }
    }
    else {
      iVar1 = __aeabi_uldivmod(param_1,param_2,DAT_0001b7d8,DAT_0001b7dc);
      local_34[0] = 0x50;
      dVar4 = (double)(longlong)iVar1 / DAT_0001b7b0;
    }
  }
  else {
    iVar1 = __aeabi_uldivmod(param_1,param_2,DAT_0001b7c8,DAT_0001b7cc);
    local_34[0] = 0x45;
    dVar4 = (double)(longlong)iVar1 / DAT_0001b7b0;
  }
  if (param_5 == 0) {
    snprintf(param_3,param_4,"%.3g%s",local_34,dVar4,local_34);
    return;
  }
LAB_0001b61e:
  dVar3 = DAT_0001b7b8;
  if (dVar4 != 0.0 && dVar4 < 0.0 == NAN(dVar4)) {
    log10(in_stack_ffffffb0);
    dVar3 = floor(in_stack_ffffffb0);
  }
  snprintf(param_3,param_4,"%*.*f%s",param_5 + 1,
           (int)(longlong)((double)(longlong)(param_5 + -1) - dVar3));
  return;
}

