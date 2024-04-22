
void calc_diff(int param_1)

{
  int iVar1;
  double in_d0;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  double dVar6;
  UDItype UVar7;
  undefined4 in_stack_ffffffe0;
  undefined4 in_stack_ffffffe4;
  
  dVar4 = DAT_0001b948;
  iVar1 = *(int *)(param_1 + 0x104);
  if (in_d0 == 0.0) {
    dVar5 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xb8),*(undefined4 *)(param_1 + 0xbc));
    dVar2 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb4));
    dVar2 = dVar2 * DAT_0001b950;
    dVar3 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xa8),*(undefined4 *)(param_1 + 0xac));
    dVar3 = dVar3 * DAT_0001b958;
    dVar6 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4));
    dVar6 = dVar5 * dVar4 + dVar2 + dVar3 + dVar6;
    if (dVar6 == 0.0) {
      UVar7 = 0xffffffffffffffff;
      in_d0 = DAT_0001b960;
    }
    else {
      in_d0 = DAT_0001b960 / dVar6;
      round((double)CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
      UVar7 = __fixunsdfdi((DFtype)CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
    }
    *(double *)(param_1 + 0x178) = in_d0;
  }
  else {
    *(double *)(param_1 + 0x178) = in_d0;
    round((double)CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
    UVar7 = __fixunsdfdi((DFtype)CONCAT44(in_stack_ffffffe4,in_stack_ffffffe0));
  }
  *(double *)(iVar1 + 0x1e0) = in_d0;
  suffix_string((int)UVar7,(int)(UVar7 >> 0x20),iVar1 + 0x30,8,0);
  dVar4 = *(double *)(iVar1 + 0x1d0);
  if (dVar4 == in_d0) {
    *(int *)(iVar1 + 0x1e8) = *(int *)(iVar1 + 0x1e8) + 1;
LAB_0001b84e:
    dVar4 = *(double *)(iVar1 + 0x1d8);
  }
  else {
    if (dVar4 == in_d0 || dVar4 < in_d0 != (NAN(dVar4) || NAN(in_d0))) {
      if (dVar4 != 0.0) goto LAB_0001b84e;
      *(double *)(iVar1 + 0x1d0) = in_d0;
      *(undefined4 *)(iVar1 + 0x1e8) = 1;
    }
    else {
      *(double *)(iVar1 + 0x1d0) = in_d0;
      *(undefined4 *)(iVar1 + 0x1e8) = 1;
    }
    dVar4 = *(double *)(iVar1 + 0x1d8);
  }
  if (dVar4 != in_d0) {
    if ((int)((uint)(dVar4 < in_d0) << 0x1f) < 0) {
      *(double *)(iVar1 + 0x1d8) = in_d0;
      *(undefined4 *)(iVar1 + 0x1ec) = 1;
    }
    return;
  }
  *(int *)(iVar1 + 0x1ec) = *(int *)(iVar1 + 0x1ec) + 1;
  return;
}

