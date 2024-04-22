
/* WARNING: Unknown calling convention */

void open_core_onChain(int chainIndex,int coreNum,int opencore_num,_Bool nullwork_enable)

{
  uchar *puVar1;
  undefined4 *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  uchar *puVar5;
  int *piVar6;
  byte bVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  uint *puVar11;
  int iVar12;
  int ret;
  vil_work_1387 *pvVar13;
  byte *pbVar14;
  int iVar15;
  uint uVar16;
  uint uVar17;
  uint uVar18;
  int iVar19;
  int iVar20;
  undefined4 in_stack_fffff6c0;
  undefined4 in_stack_fffff6c4;
  uchar gateblk [4];
  uchar buf_vil [9];
  uint cmd_buf [3];
  uint buf [13];
  uint buf_vil_tw [13];
  uchar data [52];
  vil_work_1387 work_vil_1387;
  char logstr [256];
  
  puVar9 = DAT_0003658c;
  piVar6 = DAT_0003656c;
  uVar18 = 0;
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
  if (*DAT_0003658c == 0) {
    uVar18 = get_dhash_acc_control();
    set_dhash_acc_control(uVar18 & 0xffffffdf);
    set_hash_counting_number(0);
    iVar19 = *piVar6;
    gateblk[1] = '\0';
    gateblk[0] = 0x86;
    gateblk[3] = 0x80;
    uVar16 = *(byte *)(iVar19 + 0x2fea) | 0x80;
    gateblk[2] = (uchar)uVar16;
    bVar7 = CRC5(gateblk,'\x1b');
    uVar18 = bVar7 & 0x1f | 0x80;
    gateblk[3] = (uchar)uVar18;
    if ((*DAT_00036570 == '\0') ||
       (((*DAT_00036574 == '\0' && (*DAT_00036578 == '\0')) && (*DAT_0003657c < 7)))) {
      uVar10 = 0x86000000;
    }
    else {
      in_stack_fffff6c0 = 0x86;
      in_stack_fffff6c4 = 0;
      snprintf(logstr,0x800,DAT_00036584,DAT_00036580,0x86,0,uVar16,uVar18);
      _applog(7,logstr,false);
      iVar19 = *piVar6;
      uVar16 = (uint)gateblk[2];
      uVar18 = (uint)gateblk[3];
      uVar10 = (uint)gateblk[0] << 0x18 | (uint)gateblk[1] << 0x10;
    }
    uVar17 = 0;
    data[0] = '\0';
    data[1] = '\0';
    data[2] = '\0';
    data[3] = '\0';
    cmd_buf[0] = uVar18 | uVar10 | uVar16 << 8;
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
    if (*(int *)(iVar19 + (chainIndex + 2) * 4) == 1) {
      set_BC_command_buffer(cmd_buf);
      uVar18 = get_BC_write_command();
      set_BC_write_command(uVar18 & 0xfff0ffff | chainIndex << 0x10 | 0x80800000U);
      cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
      iVar19 = DAT_000366fc;
      if (coreNum != 0) {
        iVar20 = 0;
        iVar8 = *(int *)(DAT_000366fc + 0x8d4);
        bVar7 = (byte)chainIndex | 0x80;
LAB_00036626:
        uVar18 = *(uint *)(iVar8 + 0xc);
        while ((1 << (chainIndex & 0xffU) & uVar18) == 0) {
          cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
          uVar18 = *(uint *)(*(int *)(iVar19 + 0x8d4) + 0xc);
        }
        if (iVar20 == 0) {
          data[1] = bVar7;
          data[0] = '\x11';
          uVar18 = get_BC_write_command();
          set_BC_write_command(uVar18 & 0xffbfffff);
          if (coreNum != 1) goto LAB_00036664;
        }
        else {
          data[1] = bVar7;
          data[0] = '\x01';
          if (iVar20 != coreNum + -1) goto LAB_00036664;
        }
        if (nullwork_enable) {
          uVar18 = get_BC_write_command();
          set_BC_write_command(uVar18 & ((chainIndex & 0xfU) << 0x10 | 0xc00000));
        }
LAB_00036664:
        buf[0] = 0;
        pbVar14 = data;
        buf[1] = 0;
        puVar9 = cmd_buf + 2;
        buf[2] = 0;
        iVar8 = 1;
        buf[3] = buf[3] & 0xffffff00;
        do {
          puVar9 = puVar9 + 1;
          *puVar9 = (uint)pbVar14[1] << 0x10 | (uint)*pbVar14 << 0x18 | (uint)pbVar14[3] |
                    (uint)pbVar14[2] << 8;
          if (iVar8 == 10) {
            buf[9] = uVar17;
            uVar17 = uVar17 + 1;
          }
          else if (iVar8 == 0xd) goto code_r0x000366b0;
          pbVar14 = pbVar14 + 4;
          iVar8 = iVar8 + 1;
        } while( true );
      }
    }
LAB_000362ec:
    uVar18 = get_dhash_acc_control();
    set_dhash_acc_control(uVar18 | 0x20);
  }
  else {
    uVar16 = get_dhash_acc_control();
    set_dhash_acc_control((*puVar9 & 0xf) << 8 | 0x8000 | uVar16 & 0xffff7fdf);
    set_hash_counting_number(0);
    buf_vil[4] = '@';
    iVar19 = *DAT_0003656c;
    buf_vil[0] = 'X';
    buf_vil[1] = '\t';
    buf_vil[3] = '\x1c';
    buf_vil[5] = ' ';
    buf_vil[7] = 0x80;
    buf_vil[2] = '\0';
    uVar16 = *(byte *)(iVar19 + 0x2fea) & 0x1f | 0x80;
    buf_vil[6] = (uchar)uVar16;
    buf_vil[8] = CRC5(buf_vil,'@');
    cmd_buf[2] = (uint)buf_vil[8] << 0x18;
    cmd_buf[1] = uVar16 << 8 | 0x40200080;
    buf_vil_tw[0] = 0;
    buf_vil_tw[1] = 0;
    buf_vil_tw[2] = 0;
    buf_vil_tw[3] = buf_vil_tw[3] & 0xffffff00;
    cmd_buf[0] = 0x5809001c;
    memset(&work_vil_1387,0xff,0x34);
    if (*(int *)(iVar19 + (chainIndex + 2) * 4) == 1) {
      uVar16 = get_BC_write_command();
      set_BC_write_command((uVar16 & 0xfff0ffff | chainIndex << 0x10) & 0xffbfffff | 0x800000);
      cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
      bVar7 = (byte)chainIndex | 0x80;
      work_vil_1387.work_type = '\x01';
      work_vil_1387.reserved1[0] = '\0';
      work_vil_1387.reserved1[1] = '\0';
      work_vil_1387.work_count = 0;
      work_vil_1387.data[0] = 0xff;
      work_vil_1387.data[11] = 0xff;
      work_vil_1387.chain_id = bVar7;
      set_BC_command_buffer(cmd_buf);
      uVar16 = get_BC_write_command();
      set_BC_write_command(uVar16 & 0xfff0ffff | chainIndex << 0x10 | 0x80800000U);
      cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
      iVar19 = DAT_00036588;
      if (coreNum != 0) {
        do {
          iVar8 = 0xbb9;
          if (uVar18 < (uint)opencore_num) {
            work_vil_1387.data[0] = 0xff;
            work_vil_1387.data[11] = 0xff;
          }
          else {
            work_vil_1387.data[0] = '\0';
            work_vil_1387.data[11] = '\0';
          }
          while ((1 << (chainIndex & 0xffU) & *(uint *)(*(int *)(iVar19 + 0x8d4) + 0xc)) == 0) {
            cgsleep_us(CONCAT44(in_stack_fffff6c4,in_stack_fffff6c0));
            iVar8 = iVar8 + -1;
            if (iVar8 == 0) {
              sprintf(logstr,DAT_000366f8,chainIndex);
              writeInitLogFile(logstr);
              goto LAB_000363a6;
            }
          }
          if (uVar18 == 0) {
            uVar16 = 0x11000000;
            work_vil_1387.work_type = '\x11';
          }
          else {
            uVar16 = 0x1000000;
            work_vil_1387.work_type = '\x01';
          }
          pvVar13 = &work_vil_1387;
          puVar11 = buf_vil_tw + 1;
          work_vil_1387.chain_id = bVar7;
          buf_vil_tw[0] =
               (uint)CONCAT11(work_vil_1387.reserved1[0],work_vil_1387.reserved1[1]) |
               (chainIndex & 0xffU | 0x80) << 0x10 | uVar16;
          buf_vil_tw[1] = work_vil_1387.work_count;
          do {
            puVar3 = pvVar13->data;
            puVar1 = pvVar13->data;
            puVar4 = pvVar13->data;
            puVar5 = pvVar13->data;
            pvVar13 = (vil_work_1387 *)&pvVar13->work_count;
            puVar11 = puVar11 + 1;
            *puVar11 = (uint)puVar3[1] << 0x10 | (uint)*puVar1 << 0x18 | (uint)puVar4[3] |
                       (uint)puVar5[2] << 8;
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
          if ((coreNum - 1U == uVar18) && (nullwork_enable)) {
            uVar16 = get_BC_write_command();
            set_BC_write_command(uVar16 | 0x400000);
          }
          uVar18 = uVar18 + 1;
        } while (coreNum != uVar18);
      }
    }
LAB_000363a6:
    uVar18 = get_dhash_acc_control();
    set_dhash_acc_control(uVar18 | (*puVar9 & 0xf) << 8 | 0x8000);
  }
  return;
code_r0x000366b0:
  iVar8 = *(int *)(iVar19 + 0x8d4);
  iVar15 = 0;
  do {
    puVar2 = (undefined4 *)((int)buf + iVar15);
    iVar12 = iVar8 + iVar15;
    iVar15 = iVar15 + 4;
    *(undefined4 *)(iVar12 + 0x40) = *puVar2;
  } while (iVar15 != 0x34);
  iVar20 = iVar20 + 1;
  if (coreNum == iVar20) goto LAB_000362ec;
  goto LAB_00036626;
}

