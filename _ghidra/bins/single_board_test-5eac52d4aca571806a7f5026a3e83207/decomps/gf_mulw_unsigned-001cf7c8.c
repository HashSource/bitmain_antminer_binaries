
void gf_mulw_unsigned(uint *param_1,uint *param_2,uint param_3)

{
  ulonglong uVar1;
  ulonglong uVar2;
  longlong lVar3;
  longlong lVar4;
  uint uVar5;
  uint uVar6;
  uint uVar7;
  uint uVar8;
  uint uVar9;
  uint local_38;
  
  uVar5 = *param_2;
  uVar7 = param_2[8];
  uVar6 = (uint)((ulonglong)uVar5 * (ulonglong)param_3) & 0xfffffff;
  *param_1 = uVar6;
  local_38 = (uint)((ulonglong)uVar7 * (ulonglong)param_3);
  param_1[8] = local_38 & 0xfffffff;
  uVar1 = (ulonglong)param_2[1] * (ulonglong)param_3 +
          ((ulonglong)uVar5 * (ulonglong)param_3 >> 0x1c);
  uVar2 = (ulonglong)param_2[9] * (ulonglong)param_3 +
          ((ulonglong)uVar7 * (ulonglong)param_3 >> 0x1c);
  uVar8 = (uint)uVar1 & 0xfffffff;
  param_1[1] = uVar8;
  uVar9 = (uint)uVar2 & 0xfffffff;
  param_1[9] = uVar9;
  uVar1 = (ulonglong)param_2[2] * (ulonglong)param_3 + (uVar1 >> 0x1c);
  uVar2 = (ulonglong)param_2[10] * (ulonglong)param_3 + (uVar2 >> 0x1c);
  param_1[2] = (uint)uVar1 & 0xfffffff;
  param_1[10] = (uint)uVar2 & 0xfffffff;
  uVar1 = (ulonglong)param_2[3] * (ulonglong)param_3 + (uVar1 >> 0x1c);
  uVar2 = (ulonglong)param_2[0xb] * (ulonglong)param_3 + (uVar2 >> 0x1c);
  param_1[3] = (uint)uVar1 & 0xfffffff;
  param_1[0xb] = (uint)uVar2 & 0xfffffff;
  uVar1 = (ulonglong)param_2[4] * (ulonglong)param_3 + (uVar1 >> 0x1c);
  uVar2 = (ulonglong)param_2[0xc] * (ulonglong)param_3 + (uVar2 >> 0x1c);
  param_1[4] = (uint)uVar1 & 0xfffffff;
  param_1[0xc] = (uint)uVar2 & 0xfffffff;
  uVar1 = (ulonglong)param_2[5] * (ulonglong)param_3 + (uVar1 >> 0x1c);
  uVar2 = (ulonglong)param_2[0xd] * (ulonglong)param_3 + (uVar2 >> 0x1c);
  param_1[5] = (uint)uVar1 & 0xfffffff;
  param_1[0xd] = (uint)uVar2 & 0xfffffff;
  uVar1 = (ulonglong)param_2[6] * (ulonglong)param_3 + (uVar1 >> 0x1c);
  uVar2 = (ulonglong)param_2[0xe] * (ulonglong)param_3 + (uVar2 >> 0x1c);
  param_1[6] = (uint)uVar1 & 0xfffffff;
  param_1[0xe] = (uint)uVar2 & 0xfffffff;
  uVar1 = (ulonglong)param_3 * (ulonglong)param_2[7] + (uVar1 >> 0x1c);
  uVar2 = (ulonglong)param_3 * (ulonglong)param_2[0xf] + (uVar2 >> 0x1c);
  param_1[7] = (uint)uVar1 & 0xfffffff;
  param_1[0xf] = (uint)uVar2 & 0xfffffff;
  uVar2 = uVar2 >> 0x1c;
  lVar3 = uVar2 + (uVar1 >> 0x1c) + (ulonglong)(local_38 & 0xfffffff);
  uVar7 = (uint)lVar3;
  param_1[8] = uVar7 & 0xfffffff;
  lVar4 = uVar2 + uVar6;
  uVar5 = (uint)lVar4;
  param_1[9] = (uVar7 >> 0x1c | (int)((ulonglong)lVar3 >> 0x20) * 0x10) + uVar9;
  *param_1 = uVar5 & 0xfffffff;
  param_1[1] = (uVar5 >> 0x1c | (int)((ulonglong)lVar4 >> 0x20) * 0x10) + uVar8;
  return;
}

