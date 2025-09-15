
void check_opt(undefined4 *param_1,undefined4 param_2,undefined4 param_3,int param_4)

{
  byte bVar1;
  uint uVar2;
  undefined4 *puVar3;
  undefined4 uVar4;
  byte *pbVar5;
  undefined4 uVar6;
  int extraout_r3;
  int iVar7;
  int extraout_r3_00;
  undefined4 uVar8;
  byte *pbVar9;
  undefined4 *puVar10;
  bool bVar11;
  bool bVar12;
  bool bVar13;
  int local_1c;
  
  uVar2 = param_1[1];
  bVar13 = 3 < uVar2;
  bVar11 = uVar2 != 4;
  if (bVar11) {
    bVar13 = uVar2 != 1;
  }
  bVar12 = uVar2 != 2;
  if (bVar13 && (bVar11 && bVar12)) {
    param_4 = 1;
  }
  if (!bVar13 || (!bVar11 || !bVar12)) {
    param_4 = 0;
  }
  if (!bVar13 || (!bVar11 || !bVar12)) {
    if (param_1[6] != 0) {
      pbVar5 = (byte *)*param_1;
      pbVar9 = pbVar5;
      if (*pbVar5 == 0x2d) {
        do {
          iVar7 = param_4;
          pbVar9 = pbVar9 + 1;
          bVar1 = *pbVar9;
          if ((bVar1 & 0xdf) == 0) break;
          param_4 = iVar7 + 1;
        } while (bVar1 != 0x3d && bVar1 != 0x7c);
        pbVar5 = pbVar5 + 1;
        while( true ) {
          if (pbVar5 == (byte *)0x0) {
            return;
          }
          local_1c = iVar7;
          if (*pbVar5 != 0x2d) break;
          if (iVar7 == 1) goto LAB_0004e2f8;
          pbVar9 = (byte *)param_1[1];
          opt_num_long = opt_num_long + 1;
LAB_0004e29c:
          if ((pbVar9 == (byte *)0x1) && (pbVar5[iVar7] == 0x3d || pbVar5[iVar7] == 0x20))
          goto LAB_0004e2e4;
          pbVar5 = (byte *)next_name(pbVar5,&local_1c);
          iVar7 = local_1c;
        }
        if (iVar7 == 1) {
          pbVar9 = (byte *)param_1[1];
          opt_num_short = opt_num_short + 1;
          if (((uint)(pbVar9 + -2) & 0xfffffffd) == 0) {
            opt_num_short_arg = opt_num_short_arg + 1;
          }
          goto LAB_0004e29c;
        }
        pbVar5 = (byte *)errx(1,"Option %s: invalid short option \'%.*s\'",*param_1,iVar7 + 1,
                              pbVar5 + -1);
        iVar7 = extraout_r3;
LAB_0004e2e4:
        errx(pbVar9,"Option %s: does not take arguments \'%s\'",*param_1,pbVar5 + iVar7 + 1);
        iVar7 = extraout_r3_00;
LAB_0004e2f8:
        errx(iVar7,"Option %s: invalid long option \'--\'",*param_1);
      }
      errx(1,"Option %s: does not begin with \'-\'");
    }
    uVar2 = errx(1,"Option %s: description cannot be NULL",*param_1);
  }
  puVar3 = (undefined4 *)errx(1,"Option %s: unknown entry type %u",*param_1,uVar2);
  opt_table = realloc(opt_table,(opt_count + 1) * 0x1c);
  uVar4 = puVar3[1];
  uVar6 = puVar3[2];
  uVar8 = puVar3[3];
  puVar10 = (undefined4 *)((int)opt_table + opt_count * 0x1c);
  opt_count = opt_count + 1;
  *puVar10 = *puVar3;
  puVar10[1] = uVar4;
  puVar10[2] = uVar6;
  puVar10[3] = uVar8;
  uVar4 = puVar3[5];
  uVar6 = puVar3[6];
  puVar10[4] = puVar3[4];
  puVar10[5] = uVar4;
  puVar10[6] = uVar6;
  return;
}

