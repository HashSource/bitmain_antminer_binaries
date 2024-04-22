
/* WARNING: Unknown calling convention */

void open_core(_Bool nullwork_enable)

{
  undefined4 *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  int *piVar5;
  byte bVar6;
  uint uVar7;
  uint uVar8;
  uint *puVar9;
  uint uVar10;
  int iVar11;
  uchar *puVar12;
  int iVar13;
  int ret;
  vil_work_1387 *pvVar14;
  int iVar15;
  int iVar16;
  uint uVar17;
  int iVar18;
  undefined4 in_stack_fffff6c0;
  undefined4 in_stack_fffff6c4;
  uint local_928;
  uchar gateblk [4];
  uchar buf_vil [9];
  uint cmd_buf [3];
  uint buf [13];
  uint buf_vil_tw [13];
  uchar data [52];
  vil_work_1387 work_vil_1387;
  char logstr [256];
  
  piVar5 = DAT_00035214;
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
  if (opt_multi_version != 0) {
    uVar7 = get_dhash_acc_control();
    iVar15 = DAT_0003521c;
    piVar5 = DAT_00035214;
    uVar17 = 0;
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | 0x8000 | uVar7 & 0xffff7fdf);
    set_hash_counting_number(0);
    buf_vil[4] = '@';
    buf_vil[0] = 'X';
    iVar16 = *piVar5;
    buf_vil[2] = '\0';
    buf_vil[1] = '\t';
    buf_vil[3] = '\x1c';
    buf_vil[5] = ' ';
    uVar7 = *(byte *)(iVar16 + 0x2fea) & 0x1f | 0x80;
    buf_vil[6] = (uchar)uVar7;
    buf_vil[7] = 0x80;
    buf_vil[8] = CRC5(buf_vil,'@');
    cmd_buf[2] = (uint)buf_vil[8] << 0x18;
    cmd_buf[1] = uVar7 << 8 | 0x40200080;
    buf_vil_tw[0] = 0;
    buf_vil_tw[1] = 0;
    buf_vil_tw[2] = 0;
    buf_vil_tw[3] = buf_vil_tw[3] & 0xffffff00;
    cmd_buf[0] = 0x5809001c;
    memset(&work_vil_1387,0xff,0x34);
    do {
      if (*(int *)(iVar16 + (uVar17 + 2) * 4) == 1) {
        bVar6 = (byte)uVar17 | 0x80;
        uVar7 = get_BC_write_command();
        set_BC_write_command((uVar7 & 0xfff0ffff | uVar17 << 0x10) & 0xffbfffff | 0x800000);
        cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
        work_vil_1387.data[0] = 0xff;
        work_vil_1387.data[11] = 0xff;
        work_vil_1387.work_type = '\x01';
        iVar16 = 0;
        work_vil_1387.reserved1[0] = '\0';
        work_vil_1387.reserved1[1] = '\0';
        work_vil_1387.work_count = 0;
        work_vil_1387.chain_id = bVar6;
        set_BC_command_buffer(cmd_buf);
        uVar7 = get_BC_write_command();
        set_BC_write_command(uVar17 << 0x10 | 0x80800000 | uVar7 & 0xfff0ffff);
        cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
        while( true ) {
          iVar18 = 0xbb9;
          while ((1 << (uVar17 & 0xff) & *(uint *)(*(int *)(iVar15 + 0x8d4) + 0xc)) == 0) {
            cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
            iVar18 = iVar18 + -1;
            if (iVar18 == 0) {
              sprintf(logstr,DAT_00035408,uVar17);
              writeInitLogFile(logstr);
              goto joined_r0x00035228;
            }
          }
          if (iVar16 == 0) {
            uVar7 = 0x11000000;
            work_vil_1387.work_type = '\x11';
          }
          else {
            uVar7 = 0x1000000;
            work_vil_1387.work_type = '\x01';
          }
          pvVar14 = &work_vil_1387;
          puVar9 = buf_vil_tw + 1;
          work_vil_1387.chain_id = bVar6;
          buf_vil_tw[0] =
               (uint)CONCAT11(work_vil_1387.reserved1[0],work_vil_1387.reserved1[1]) |
               (uVar17 | 0x80) << 0x10 | uVar7;
          buf_vil_tw[1] = work_vil_1387.work_count;
          do {
            puVar2 = pvVar14->data;
            puVar12 = pvVar14->data;
            puVar3 = pvVar14->data;
            puVar4 = pvVar14->data;
            pvVar14 = (vil_work_1387 *)&pvVar14->work_count;
            puVar9 = puVar9 + 1;
            *puVar9 = (uint)puVar2[1] << 0x10 | (uint)*puVar12 << 0x18 | (uint)puVar3[3] |
                      (uint)puVar4[2] << 8;
          } while (pvVar14 != (vil_work_1387 *)(work_vil_1387.data + 4));
          buf_vil_tw[5] = 0;
          buf_vil_tw[6] = 0;
          buf_vil_tw[7] = 0;
          buf_vil_tw[8] = 0;
          buf_vil_tw[9] = 0;
          buf_vil_tw[10] = 0;
          buf_vil_tw[11] = 0;
          buf_vil_tw[12] = 0;
          set_TW_write_command_vil(buf_vil_tw);
          if (iVar16 == 0x71) break;
          iVar16 = iVar16 + 1;
        }
        if (nullwork_enable) {
          uVar7 = get_BC_write_command();
          set_BC_write_command(uVar7 | 0x400000);
        }
      }
joined_r0x00035228:
      if (uVar17 == 0xf) {
        uVar7 = get_dhash_acc_control();
        set_dhash_acc_control(uVar7 | (opt_multi_version & 0xfU) << 8 | 0x8000);
        return;
      }
      uVar17 = uVar17 + 1;
      iVar16 = *piVar5;
    } while( true );
  }
  uVar7 = get_dhash_acc_control();
  set_dhash_acc_control(uVar7 & 0xffffffdf);
  set_hash_counting_number(0);
  gateblk[0] = 0x86;
  iVar15 = *piVar5;
  gateblk[3] = 0x80;
  gateblk[1] = '\0';
  uVar17 = *(byte *)(iVar15 + 0x2fea) | 0x80;
  gateblk[2] = (uchar)uVar17;
  bVar6 = CRC5(gateblk,'\x1b');
  uVar7 = bVar6 & 0x1f | 0x80;
  gateblk[3] = (uchar)uVar7;
  if ((*DAT_00035218 == '\0') ||
     (((*DAT_0003540c == '\0' && (*DAT_00035410 == '\0')) && (*DAT_00035414 < 7)))) {
    uVar10 = 0x86000000;
  }
  else {
    in_stack_fffff6c0 = 0x86;
    in_stack_fffff6c4 = 0;
    snprintf(logstr,0x800,DAT_00035418,DAT_0003541c,0x86,0,uVar17,uVar7);
    _applog(7,logstr,false);
    uVar17 = (uint)gateblk[2];
    uVar7 = (uint)gateblk[3];
    iVar15 = *piVar5;
    uVar10 = (uint)gateblk[0] << 0x18 | (uint)gateblk[1] << 0x10;
  }
  iVar16 = DAT_0003521c;
  cmd_buf[0] = uVar10 | uVar7 | uVar17 << 8;
  uVar7 = 0;
  local_928 = 0;
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
LAB_0003500c:
  if (*(int *)(iVar15 + (local_928 + 2) * 4) == 1) {
    uVar10 = local_928 & 0xff | 0x80;
    iVar18 = 0;
    set_BC_command_buffer(cmd_buf);
    uVar17 = get_BC_write_command();
    set_BC_write_command(local_928 << 0x10 | 0x80800000 | uVar17 & 0xfff0ffff);
    cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
    iVar15 = *(int *)(iVar16 + 0x8d4);
LAB_0003505e:
    uVar17 = *(uint *)(iVar15 + 0xc);
    while ((1 << (local_928 & 0xff) & uVar17) == 0) {
      cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
      uVar17 = *(uint *)(*(int *)(iVar16 + 0x8d4) + 0xc);
    }
    if (iVar18 == 0) {
      data[1] = (byte)local_928 | 0x80;
      data[0] = '\x11';
      uVar17 = get_BC_write_command();
      set_BC_write_command(uVar17 & 0xffbfffff);
      uVar17 = data._0_4_ & 0xff;
      uVar8 = (uint)data._0_4_ >> 8 & 0xff;
    }
    else {
      data[1] = (uchar)uVar10;
      data[0] = '\x01';
      if ((iVar18 == 0x71) && (nullwork_enable)) {
        uVar17 = get_BC_write_command();
        set_BC_write_command(uVar17 & (local_928 << 0x10 | 0xc00000));
        uVar17 = data._0_4_ & 0xff;
        uVar8 = (uint)data._0_4_ >> 8 & 0xff;
      }
      else {
        uVar17 = 1;
        uVar8 = uVar10;
      }
    }
    buf[0] = 0;
    puVar12 = data;
    buf[1] = 0;
    puVar9 = cmd_buf + 2;
    buf[2] = 0;
    iVar15 = 1;
    buf[3] = buf[3] & 0xffffff00;
    do {
      puVar9 = puVar9 + 1;
      *puVar9 = uVar17 << 0x18 | uVar8 << 0x10 | (uint)puVar12[3] | (uint)puVar12[2] << 8;
      if (iVar15 == 10) {
        buf[9] = uVar7;
        uVar7 = uVar7 + 1;
      }
      else if (iVar15 == 0xd) goto code_r0x000350ec;
      uVar17 = (uint)puVar12[4];
      iVar15 = iVar15 + 1;
      uVar8 = (uint)puVar12[5];
      puVar12 = puVar12 + 4;
    } while( true );
  }
  if (local_928 != 0xf) goto LAB_00035008;
LAB_00035114:
  uVar7 = get_dhash_acc_control();
  set_dhash_acc_control(uVar7 | 0x20);
  return;
code_r0x000350ec:
  iVar15 = *(int *)(iVar16 + 0x8d4);
  iVar13 = 0;
  do {
    puVar1 = (undefined4 *)((int)buf + iVar13);
    iVar11 = iVar15 + iVar13;
    iVar13 = iVar13 + 4;
    *(undefined4 *)(iVar11 + 0x40) = *puVar1;
  } while (iVar13 != 0x34);
  iVar18 = iVar18 + 1;
  if (iVar18 == 0x72) goto code_r0x00035108;
  goto LAB_0003505e;
code_r0x00035108:
  if (local_928 == 0xf) goto LAB_00035114;
LAB_00035008:
  local_928 = local_928 + 1;
  iVar15 = *piVar5;
  goto LAB_0003500c;
}

