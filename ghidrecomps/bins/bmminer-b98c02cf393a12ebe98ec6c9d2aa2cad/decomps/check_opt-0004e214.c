
void check_opt(byte **param_1,undefined4 param_2,undefined4 param_3,byte *param_4)

{
  byte bVar1;
  bool bVar2;
  byte *pbVar3;
  undefined4 *puVar4;
  undefined4 uVar5;
  byte *pbVar6;
  undefined4 uVar7;
  byte *pbVar8;
  undefined4 uVar9;
  undefined4 *puVar10;
  bool bVar11;
  bool bVar12;
  byte *local_1c;
  
  pbVar3 = param_1[1];
  bVar12 = (byte *)0x3 < pbVar3;
  bVar11 = pbVar3 != (byte *)0x4;
  if (bVar11) {
    bVar12 = pbVar3 != (byte *)0x1;
  }
  bVar2 = pbVar3 != (byte *)0x2;
  if (bVar12 && (bVar11 && bVar2)) {
    param_4 = (byte *)0x1;
  }
  if (!bVar12 || (!bVar11 || !bVar2)) {
    param_4 = (byte *)0x0;
  }
  if (!bVar12 || (!bVar11 || !bVar2)) {
    if (param_1[6] != (byte *)0x0) {
      pbVar6 = *param_1;
      pbVar3 = pbVar6;
      if (*pbVar6 == 0x2d) {
        do {
          pbVar8 = param_4;
          pbVar3 = pbVar3 + 1;
          bVar1 = *pbVar3;
          if ((bVar1 & 0xdf) == 0) break;
          param_4 = pbVar8 + 1;
        } while (bVar1 != 0x3d && bVar1 != 0x7c);
        pbVar6 = pbVar6 + 1;
        while( true ) {
          if (pbVar6 == (byte *)0x0) {
            return;
          }
          local_1c = pbVar8;
          if (*pbVar6 != 0x2d) break;
          if (pbVar8 == (byte *)0x1) goto LAB_0004e2f8;
          pbVar3 = param_1[1];
          opt_num_long = opt_num_long + 1;
LAB_0004e29c:
          if ((pbVar3 == (byte *)0x1) &&
             (pbVar6[(int)pbVar8] == 0x3d || pbVar6[(int)pbVar8] == 0x20)) goto LAB_0004e2e4;
          pbVar6 = (byte *)next_name(pbVar6,&local_1c);
          pbVar8 = local_1c;
        }
        if (pbVar8 == (byte *)0x1) {
          pbVar3 = param_1[1];
          opt_num_short = opt_num_short + 1;
          if (((uint)(pbVar3 + -2) & 0xfffffffd) == 0) {
            opt_num_short_arg = opt_num_short_arg + 1;
          }
          goto LAB_0004e29c;
        }
        pbVar8 = pbVar8 + 1;
        pbVar6 = (byte *)errx(1,"Option %s: invalid short option \'%.*s\'",*param_1,pbVar8,
                              pbVar6 + -1);
LAB_0004e2e4:
        pbVar8 = pbVar8 + 1 + (int)pbVar6;
        errx(pbVar3,"Option %s: does not take arguments \'%s\'",*param_1,pbVar8);
LAB_0004e2f8:
        errx(pbVar8,"Option %s: invalid long option \'--\'",*param_1);
      }
      errx(1,"Option %s: does not begin with \'-\'");
    }
    errx(1,"Option %s: description cannot be NULL",*param_1);
  }
  puVar4 = (undefined4 *)errx(1,"Option %s: unknown entry type %u",*param_1);
  opt_table = realloc(opt_table,(opt_count + 1) * 0x1c);
  uVar5 = puVar4[1];
  uVar7 = puVar4[2];
  uVar9 = puVar4[3];
  puVar10 = (undefined4 *)((int)opt_table + opt_count * 0x1c);
  opt_count = opt_count + 1;
  *puVar10 = *puVar4;
  puVar10[1] = uVar5;
  puVar10[2] = uVar7;
  puVar10[3] = uVar9;
  uVar5 = puVar4[5];
  uVar7 = puVar4[6];
  puVar10[4] = puVar4[4];
  puVar10[5] = uVar5;
  puVar10[6] = uVar7;
  return;
}

