
UDItype share_ndiff(int param_1)

{
  double dVar1;
  double dVar2;
  double dVar3;
  double dVar4;
  double dVar5;
  DFtype unaff_d8;
  UDItype UVar6;
  
  dVar1 = DAT_0001cdd0;
  if (param_1 != 0) {
    dVar4 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xd8),*(undefined4 *)(param_1 + 0xdc));
    dVar2 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xd0),*(undefined4 *)(param_1 + 0xd4));
    dVar2 = dVar2 * DAT_0001cdd8;
    dVar3 = (double)__floatundidf(*(undefined4 *)(param_1 + 200),*(undefined4 *)(param_1 + 0xcc));
    dVar3 = dVar3 * DAT_0001cde0;
    dVar5 = (double)__floatundidf(*(undefined4 *)(param_1 + 0xc0),*(undefined4 *)(param_1 + 0xc4));
    if (dVar4 * dVar1 + dVar2 + dVar3 + dVar5 == 0.0) {
      UVar6 = 0;
    }
    else {
      UVar6 = __fixunsdfdi(unaff_d8);
    }
    return UVar6;
  }
  return 0;
}

