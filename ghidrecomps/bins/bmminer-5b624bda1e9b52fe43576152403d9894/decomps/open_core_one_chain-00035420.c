
/* WARNING: Unknown calling convention */

void open_core_one_chain(int chainIndex,_Bool nullwork_enable)

{
  undefined4 *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  int *piVar5;
  int iVar6;
  byte bVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  int ret;
  vil_work_1387 *pvVar13;
  uchar *puVar14;
  int iVar15;
  uint uVar16;
  int iVar17;
  uint m;
  uint uVar18;
  int iVar19;
  undefined4 in_stack_fffff6c8;
  undefined4 in_stack_fffff6cc;
  uchar gateblk [4];
  uchar buf_vil [9];
  uint cmd_buf [3];
  uint buf [13];
  uint buf_vil_tw [13];
  uchar data [52];
  vil_work_1387 work_vil_1387;
  char logstr [256];
  
  piVar5 = DAT_00035718;
  puVar9 = DAT_00035714;
  iVar17 = 0;
  buf[4] = 0;
  buf_vil_tw[4] = 0;
  buf[5] = 0;
  buf_vil_tw[5] = 0;
  buf[6] = 0;
  buf_vil_tw[6] = 0;
  buf[7] = 0;
  buf_vil_tw[7] = 0;
  buf[8] = 0;
  buf_vil_tw[8] = 0;
  buf[9] = 0;
  buf_vil_tw[9] = 0;
  buf[10] = 0;
  buf_vil_tw[10] = 0;
  buf[11] = 0;
  buf_vil_tw[11] = 0;
  buf[12] = 0;
  buf_vil_tw[12] = 0;
  gateblk[0] = '\0';
  gateblk[1] = '\0';
  gateblk[2] = '\0';
  gateblk[3] = '\0';
  cmd_buf[0] = 0;
  cmd_buf[1] = 0;
  cmd_buf[2] = 0;
  buf[0] = 0;
  buf[1] = 0;
  buf[2] = 0;
  buf[3] = 0;
  buf_vil_tw[0] = 0;
  buf_vil_tw[1] = 0;
  buf_vil_tw[2] = 0;
  buf_vil_tw[3] = 0;
  data[4] = '\0';
  data[5] = '\0';
  data[6] = '\0';
  data[7] = '\0';
  data[8] = '\0';
  data[9] = '\0';
  data[10] = '\0';
  data[11] = '\0';
  data[12] = '\0';
  data[13] = '\0';
  data[14] = '\0';
  data[15] = '\0';
  data[16] = '\0';
  data[17] = '\0';
  data[18] = '\0';
  data[19] = '\0';
  data[20] = '\0';
  data[21] = '\0';
  data[22] = '\0';
  data[23] = '\0';
  data[24] = '\0';
  data[25] = '\0';
  data[26] = '\0';
  data[27] = '\0';
  data[28] = '\0';
  data[29] = '\0';
  data[30] = '\0';
  data[31] = '\0';
  data[32] = '\0';
  data[33] = '\0';
  data[34] = '\0';
  data[35] = '\0';
  data[36] = '\0';
  data[37] = '\0';
  data[38] = '\0';
  data[39] = '\0';
  data[40] = '\0';
  data[41] = '\0';
  data[42] = '\0';
  data[43] = '\0';
  data[44] = '\0';
  data[45] = '\0';
  data[46] = '\0';
  data[47] = '\0';
  data[48] = '\0';
  data[49] = '\0';
  data[50] = '\0';
  data[51] = '\0';
  data[0] = 0xff;
  data[1] = '\0';
  data[2] = '\0';
  data[3] = '\0';
  buf_vil[0] = '\0';
  buf_vil[1] = '\0';
  buf_vil[2] = '\0';
  buf_vil[3] = '\0';
  buf_vil[4] = '\0';
  buf_vil[5] = '\0';
  buf_vil[6] = '\0';
  buf_vil[7] = '\0';
  buf_vil[8] = '\0';
  if (*DAT_00035714 == 0) {
    uVar8 = get_dhash_acc_control();
    set_dhash_acc_control(uVar8 & 0xffffffdf);
    set_hash_counting_number(0);
    iVar17 = *piVar5;
    gateblk[1] = '\0';
    gateblk[0] = 0x86;
    gateblk[3] = 0x80;
    uVar16 = *(byte *)(iVar17 + 0x2fea) | 0x80;
    gateblk[2] = (uchar)uVar16;
    bVar7 = CRC5(gateblk,'\x1b');
    uVar8 = bVar7 & 0x1f | 0x80;
    gateblk[3] = (uchar)uVar8;
    if ((*DAT_0003571c == '\0') ||
       (((*DAT_00035720 == '\0' && (*DAT_00035724 == '\0')) && (*DAT_00035728 < 7)))) {
      uVar10 = 0x86000000;
    }
    else {
      in_stack_fffff6c8 = 0x86;
      in_stack_fffff6cc = 0;
      snprintf(logstr,0x800,DAT_00035730,DAT_0003572c,0x86,0,uVar16,uVar8);
      _applog(7,logstr,false);
      iVar17 = *piVar5;
      uVar16 = (uint)gateblk[2];
      uVar8 = (uint)gateblk[3];
      uVar10 = (uint)gateblk[0] << 0x18 | (uint)gateblk[1] << 0x10;
    }
    iVar6 = DAT_00035938;
    uVar18 = 0;
    cmd_buf[0] = uVar8 | uVar10 | uVar16 << 8;
    data[0] = '\0';
    data[1] = '\0';
    data[2] = '\0';
    data[3] = '\0';
    data[4] = '\0';
    data[5] = '\0';
    data[6] = '\0';
    data[7] = '\0';
    data[8] = '\0';
    data[9] = '\0';
    data[10] = '\0';
    data[11] = '\0';
    data[12] = '\0';
    data[13] = '\0';
    data[14] = '\0';
    data[15] = '\0';
    data[16] = '\0';
    data[17] = '\0';
    data[18] = '\0';
    data[19] = '\0';
    data[20] = '\0';
    data[21] = '\0';
    data[22] = '\0';
    data[23] = '\0';
    data[24] = '\0';
    data[25] = '\0';
    data[26] = '\0';
    data[27] = '\0';
    data[28] = '\0';
    data[29] = '\0';
    data[30] = '\0';
    data[31] = '\0';
    data[32] = '\0';
    data[33] = '\0';
    data[34] = '\0';
    data[35] = '\0';
    data[36] = '\0';
    data[37] = '\0';
    data[38] = '\0';
    data[39] = '\0';
    data[44] = '\0';
    data[45] = '\0';
    data[46] = '\0';
    data[47] = '\0';
    data[48] = '\0';
    data[49] = '\0';
    data[50] = '\0';
    data[51] = 0xff;
    data[40] = 0xff;
    data[41] = '\0';
    data[42] = '\0';
    data[43] = '\0';
    if (*(int *)(iVar17 + (chainIndex + 2) * 4) == 1) {
      set_BC_command_buffer(cmd_buf);
      uVar8 = get_BC_write_command();
      bVar7 = (byte)chainIndex | 0x80;
      iVar19 = 0;
      set_BC_write_command(uVar8 & 0xfff0ffff | chainIndex << 0x10 | 0x80800000U);
      cgsleep_us(CONCAT44(in_stack_fffff6cc,in_stack_fffff6c8));
      iVar17 = *(int *)(iVar6 + 0x8d4);
LAB_00035852:
      uVar8 = *(uint *)(iVar17 + 0xc);
      while ((1 << (chainIndex & 0xffU) & uVar8) == 0) {
        cgsleep_us(CONCAT44(in_stack_fffff6cc,in_stack_fffff6c8));
        uVar8 = *(uint *)(*(int *)(iVar6 + 0x8d4) + 0xc);
      }
      if (iVar19 == 0) {
        data[1] = bVar7;
        data[0] = '\x11';
        uVar8 = get_BC_write_command();
        set_BC_write_command(uVar8 & 0xffbfffff);
        uVar8 = data._0_4_ & 0xff;
        uVar16 = (uint)data._0_4_ >> 8 & 0xff;
      }
      else {
        data[1] = bVar7;
        data[0] = '\x01';
        if ((iVar19 == 0x71) && (nullwork_enable)) {
          uVar8 = get_BC_write_command();
          set_BC_write_command(uVar8 & ((chainIndex & 0xfU) << 0x10 | 0xc00000));
          uVar8 = data._0_4_ & 0xff;
          uVar16 = (uint)data._0_4_ >> 8 & 0xff;
        }
        else {
          uVar8 = 1;
          uVar16 = chainIndex & 0xffU | 0x80;
        }
      }
      buf[0] = 0;
      puVar14 = data;
      buf[1] = 0;
      puVar9 = cmd_buf + 2;
      buf[2] = 0;
      iVar17 = 1;
      buf[3] = buf[3] & 0xffffff00;
      do {
        puVar9 = puVar9 + 1;
        *puVar9 = uVar8 << 0x18 | uVar16 << 0x10 | (uint)puVar14[3] | (uint)puVar14[2] << 8;
        if (iVar17 == 10) {
          buf[9] = uVar18;
          uVar18 = uVar18 + 1;
        }
        else if (iVar17 == 0xd) goto code_r0x000358e0;
        uVar8 = (uint)puVar14[4];
        iVar17 = iVar17 + 1;
        uVar16 = (uint)puVar14[5];
        puVar14 = puVar14 + 4;
      } while( true );
    }
LAB_0003555c:
    uVar8 = get_dhash_acc_control();
    set_dhash_acc_control(uVar8 | 0x20);
  }
  else {
    uVar8 = get_dhash_acc_control();
    set_dhash_acc_control((*puVar9 & 0xf) << 8 | 0x8000 | uVar8 & 0xffff7fdf);
    set_hash_counting_number(0);
    buf_vil[4] = '@';
    iVar19 = *DAT_00035718;
    buf_vil[0] = 'X';
    buf_vil[1] = '\t';
    buf_vil[3] = '\x1c';
    buf_vil[5] = ' ';
    buf_vil[7] = 0x80;
    buf_vil[2] = '\0';
    uVar8 = *(byte *)(iVar19 + 0x2fea) & 0x1f | 0x80;
    buf_vil[6] = (uchar)uVar8;
    buf_vil[8] = CRC5(buf_vil,'@');
    cmd_buf[2] = (uint)buf_vil[8] << 0x18;
    cmd_buf[1] = uVar8 << 8 | 0x40200080;
    buf_vil_tw[0] = 0;
    buf_vil_tw[1] = 0;
    buf_vil_tw[2] = 0;
    buf_vil_tw[3] = buf_vil_tw[3] & 0xffffff00;
    cmd_buf[0] = 0x5809001c;
    memset(&work_vil_1387,0xff,0x34);
    iVar6 = DAT_00035734;
    if (*(int *)(iVar19 + (chainIndex + 2) * 4) == 1) {
      uVar8 = get_BC_write_command();
      bVar7 = (byte)chainIndex | 0x80;
      set_BC_write_command((uVar8 & 0xfff0ffff | chainIndex << 0x10) & 0xffbfffff | 0x800000);
      cgsleep_us(CONCAT44(in_stack_fffff6cc,in_stack_fffff6c8));
      work_vil_1387.data[0] = 0xff;
      work_vil_1387.data[11] = 0xff;
      work_vil_1387.work_type = '\x01';
      work_vil_1387.reserved1[0] = '\0';
      work_vil_1387.reserved1[1] = '\0';
      work_vil_1387.work_count = 0;
      work_vil_1387.chain_id = bVar7;
      set_BC_command_buffer(cmd_buf);
      uVar8 = get_BC_write_command();
      set_BC_write_command(chainIndex << 0x10 | 0x80800000U | uVar8 & 0xfff0ffff);
      cgsleep_us(CONCAT44(in_stack_fffff6cc,in_stack_fffff6c8));
      while( true ) {
        iVar19 = 0xbb9;
        while ((1 << (chainIndex & 0xffU) & *(uint *)(*(int *)(iVar6 + 0x8d4) + 0xc)) == 0) {
          cgsleep_us(CONCAT44(in_stack_fffff6cc,in_stack_fffff6c8));
          iVar19 = iVar19 + -1;
          if (iVar19 == 0) {
            sprintf(logstr,DAT_00035934,chainIndex);
            writeInitLogFile(logstr);
            goto LAB_00035612;
          }
        }
        if (iVar17 == 0) {
          uVar8 = 0x11000000;
          work_vil_1387.work_type = '\x11';
        }
        else {
          uVar8 = 0x1000000;
          work_vil_1387.work_type = '\x01';
        }
        pvVar13 = &work_vil_1387;
        puVar11 = buf_vil_tw + 1;
        work_vil_1387.chain_id = bVar7;
        buf_vil_tw[0] =
             (uint)CONCAT11(work_vil_1387.reserved1[0],work_vil_1387.reserved1[1]) |
             (chainIndex & 0xffU | 0x80) << 0x10 | uVar8;
        buf_vil_tw[1] = work_vil_1387.work_count;
        do {
          puVar2 = pvVar13->data;
          puVar14 = pvVar13->data;
          puVar3 = pvVar13->data;
          puVar4 = pvVar13->data;
          pvVar13 = (vil_work_1387 *)&pvVar13->work_count;
          puVar11 = puVar11 + 1;
          *puVar11 = (uint)puVar2[1] << 0x10 | (uint)*puVar14 << 0x18 | (uint)puVar3[3] |
                     (uint)puVar4[2] << 8;
        } while (pvVar13 != (vil_work_1387 *)(work_vil_1387.data + 4));
        buf_vil_tw[5] = 0;
        buf_vil_tw[6] = 0;
        buf_vil_tw[7] = 0;
        buf_vil_tw[8] = 0;
        buf_vil_tw[9] = 0;
        buf_vil_tw[10] = 0;
        buf_vil_tw[11] = 0;
        buf_vil_tw[12] = 0;
        set_TW_write_command_vil(buf_vil_tw);
        if (iVar17 == 0x71) break;
        iVar17 = iVar17 + 1;
      }
      if (nullwork_enable) {
        uVar8 = get_BC_write_command();
        set_BC_write_command(uVar8 | 0x400000);
      }
    }
LAB_00035612:
    uVar8 = get_dhash_acc_control();
    set_dhash_acc_control(uVar8 | (*puVar9 & 0xf) << 8 | 0x8000);
  }
  return;
code_r0x000358e0:
  iVar17 = *(int *)(iVar6 + 0x8d4);
  iVar15 = 0;
  do {
    puVar1 = (undefined4 *)((int)buf + iVar15);
    iVar12 = iVar17 + iVar15;
    iVar15 = iVar15 + 4;
    *(undefined4 *)(iVar12 + 0x40) = *puVar1;
  } while (iVar15 != 0x34);
  iVar19 = iVar19 + 1;
  if (iVar19 == 0x72) goto LAB_0003555c;
  goto LAB_00035852;
}

