
void calc_diff(int param_1)

{
  int iVar1;
  double in_d0;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  UDItype UVar6;
  
  iVar1 = *(int *)(param_1 + 0x104);
  if (in_d0 == 0.0) {
    dVar4 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xb8),*(undefined4 *)(param_1 + 0xbc));
    dVar2 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xb0),*(undefined4 *)(param_1 + 0xb4));
    dVar3 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xa8),*(undefined4 *)(param_1 + 0xac));
    dVar5 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xa0),*(undefined4 *)(param_1 + 0xa4));
    dVar5 = dVar4 * 6.277101735386681e+57 + dVar2 * 3.402823669209385e+38 +
            dVar3 * 1.8446744073709552e+19 + dVar5;
    if (dVar5 == 0.0) {
      in_d0 = 2.695953529101131e+67;
      UVar6 = 0xffffffffffffffff;
    }
    else {
      in_d0 = 2.695953529101131e+67 / dVar5;
      dVar2 = round(in_d0);
      UVar6 = __fixunsdfdi(dVar2);
    }
    *(double *)(param_1 + 0x178) = in_d0;
  }
  else {
    *(double *)(param_1 + 0x178) = in_d0;
    dVar2 = round(in_d0);
    UVar6 = __fixunsdfdi(dVar2);
  }
  *(double *)(iVar1 + 0x1e0) = in_d0;
  suffix_string((int)UVar6,(int)(UVar6 >> 0x20),iVar1 + 0x30,8,0);
  dVar2 = *(double *)(iVar1 + 0x1d0);
  if (dVar2 == in_d0) {
    *(int *)(iVar1 + 0x1e8) = *(int *)(iVar1 + 0x1e8) + 1;
LAB_0001b84e:
    dVar2 = *(double *)(iVar1 + 0x1d8);
  }
  else {
    if (dVar2 <= in_d0) {
      if (dVar2 != 0.0) goto LAB_0001b84e;
      *(double *)(iVar1 + 0x1d0) = in_d0;
      *(undefined4 *)(iVar1 + 0x1e8) = 1;
    }
    else {
      *(double *)(iVar1 + 0x1d0) = in_d0;
      *(undefined4 *)(iVar1 + 0x1e8) = 1;
    }
    dVar2 = *(double *)(iVar1 + 0x1d8);
  }
  if (dVar2 != in_d0) {
    if ((int)((uint)(dVar2 < in_d0) << 0x1f) < 0) {
      *(double *)(iVar1 + 0x1d8) = in_d0;
      *(undefined4 *)(iVar1 + 0x1ec) = 1;
    }
    return;
  }
  *(int *)(iVar1 + 0x1ec) = *(int *)(iVar1 + 0x1ec) + 1;
  return;
}

