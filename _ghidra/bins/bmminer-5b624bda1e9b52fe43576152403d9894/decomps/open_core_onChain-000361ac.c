
/* WARNING: Unknown calling convention */

void open_core_onChain(int chainIndex,int coreNum,int opencore_num,_Bool nullwork_enable)

{
  uchar *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  uchar *puVar4;
  byte bVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  vil_work_1387 *pvVar10;
  byte *pbVar11;
  int iVar12;
  uint uVar13;
  uint uVar14;
  uint uVar15;
  all_parameters *paVar16;
  int iVar17;
  uchar gateblk [4];
  uchar buf_vil [9];
  uint cmd_buf [3];
  uint buf [13];
  uint buf_vil_tw [13];
  uchar data [52];
  vil_work_1387 work_vil_1387;
  char logstr [256];
  
  uVar15 = 0;
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
  buf[0xb] = 0;
  buf_vil_tw[0xb] = 0;
  buf[0xc] = 0;
  buf_vil_tw[0xc] = 0;
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
  data[0xb] = '\0';
  data[0xc] = '\0';
  data[0xd] = '\0';
  data[0xe] = '\0';
  data[0xf] = '\0';
  data[0x10] = '\0';
  data[0x11] = '\0';
  data[0x12] = '\0';
  data[0x13] = '\0';
  data[0x14] = '\0';
  data[0x15] = '\0';
  data[0x16] = '\0';
  data[0x17] = '\0';
  data[0x18] = '\0';
  data[0x19] = '\0';
  data[0x1a] = '\0';
  data[0x1b] = '\0';
  data[0x1c] = '\0';
  data[0x1d] = '\0';
  data[0x1e] = '\0';
  data[0x1f] = '\0';
  data[0x20] = '\0';
  data[0x21] = '\0';
  data[0x22] = '\0';
  data[0x23] = '\0';
  data[0x24] = '\0';
  data[0x25] = '\0';
  data[0x26] = '\0';
  data[0x27] = '\0';
  data[0x28] = '\0';
  data[0x29] = '\0';
  data[0x2a] = '\0';
  data[0x2b] = '\0';
  data[0x2c] = '\0';
  data[0x2d] = '\0';
  data[0x2e] = '\0';
  data[0x2f] = '\0';
  data[0x30] = '\0';
  data[0x31] = '\0';
  data[0x32] = '\0';
  data[0x33] = '\0';
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
  if (opt_multi_version == 0) {
    uVar15 = get_dhash_acc_control();
    set_dhash_acc_control(uVar15 & 0xffffffdf);
    set_hash_counting_number(0);
    paVar16 = dev;
    gateblk[1] = '\0';
    gateblk[0] = 0x86;
    gateblk[3] = 0x80;
    uVar13 = dev->baud | 0x80;
    gateblk[2] = (uchar)uVar13;
    bVar5 = CRC5(gateblk,'\x1b');
    uVar15 = bVar5 & 0x1f | 0x80;
    gateblk[3] = (uchar)uVar15;
    if ((opt_debug == false) ||
       (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7)))) {
      uVar8 = 0x86000000;
    }
    else {
      snprintf(logstr,0x800,
               "%s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n",
               "open_core_onChain",0x86,0,uVar13,uVar15);
      _applog(7,logstr,false);
      uVar13 = (uint)gateblk[2];
      uVar15 = (uint)gateblk[3];
      uVar8 = (uint)gateblk[0] << 0x18 | (uint)gateblk[1] << 0x10;
      paVar16 = dev;
    }
    uVar14 = 0;
    data[0] = '\0';
    data[1] = '\0';
    data[2] = '\0';
    data[3] = '\0';
    cmd_buf[0] = uVar15 | uVar8 | uVar13 << 8;
    data[4] = '\0';
    data[5] = '\0';
    data[6] = '\0';
    data[7] = '\0';
    data[8] = '\0';
    data[9] = '\0';
    data[10] = '\0';
    data[0xb] = '\0';
    data[0xc] = '\0';
    data[0xd] = '\0';
    data[0xe] = '\0';
    data[0xf] = '\0';
    data[0x10] = '\0';
    data[0x11] = '\0';
    data[0x12] = '\0';
    data[0x13] = '\0';
    data[0x14] = '\0';
    data[0x15] = '\0';
    data[0x16] = '\0';
    data[0x17] = '\0';
    data[0x18] = '\0';
    data[0x19] = '\0';
    data[0x1a] = '\0';
    data[0x1b] = '\0';
    data[0x1c] = '\0';
    data[0x1d] = '\0';
    data[0x1e] = '\0';
    data[0x1f] = '\0';
    data[0x20] = '\0';
    data[0x21] = '\0';
    data[0x22] = '\0';
    data[0x23] = '\0';
    data[0x24] = '\0';
    data[0x25] = '\0';
    data[0x26] = '\0';
    data[0x27] = '\0';
    data[0x2c] = '\0';
    data[0x2d] = '\0';
    data[0x2e] = '\0';
    data[0x2f] = '\0';
    data[0x30] = '\0';
    data[0x31] = '\0';
    data[0x32] = '\0';
    data[0x33] = 0xff;
    data[0x28] = 0xff;
    data[0x29] = '\0';
    data[0x2a] = '\0';
    data[0x2b] = '\0';
    if (paVar16->chain_exist[chainIndex] == 1) {
      set_BC_command_buffer(cmd_buf);
      uVar15 = get_BC_write_command();
      set_BC_write_command(uVar15 & 0xfff0ffff | chainIndex << 0x10 | 0x80800000U);
      cgsleep_us(10000);
      if (coreNum != 0) {
        iVar17 = 0;
        bVar5 = (byte)chainIndex | 0x80;
        puVar6 = axi_fpga_addr;
LAB_00036626:
        uVar15 = puVar6[3];
        while ((1 << (chainIndex & 0xffU) & uVar15) == 0) {
          cgsleep_us(1000);
          uVar15 = axi_fpga_addr[3];
        }
        if (iVar17 == 0) {
          data[1] = bVar5;
          data[0] = '\x11';
          uVar15 = get_BC_write_command();
          set_BC_write_command(uVar15 & 0xffbfffff);
          if (coreNum != 1) goto LAB_00036664;
        }
        else {
          data[1] = bVar5;
          data[0] = '\x01';
          if (iVar17 != coreNum + -1) goto LAB_00036664;
        }
        if (nullwork_enable) {
          uVar15 = get_BC_write_command();
          set_BC_write_command(uVar15 & ((chainIndex & 0xfU) << 0x10 | 0xc00000));
        }
LAB_00036664:
        puVar6 = axi_fpga_addr;
        buf[0] = 0;
        pbVar11 = data;
        buf[1] = 0;
        puVar7 = cmd_buf + 2;
        buf[2] = 0;
        iVar9 = 1;
        buf[3] = buf[3] & 0xffffff00;
        do {
          puVar7 = puVar7 + 1;
          *puVar7 = (uint)pbVar11[1] << 0x10 | (uint)*pbVar11 << 0x18 | (uint)pbVar11[3] |
                    (uint)pbVar11[2] << 8;
          if (iVar9 == 10) {
            buf[9] = uVar14;
            uVar14 = uVar14 + 1;
          }
          else if (iVar9 == 0xd) goto code_r0x000366b0;
          pbVar11 = pbVar11 + 4;
          iVar9 = iVar9 + 1;
        } while( true );
      }
    }
LAB_000362ec:
    uVar15 = get_dhash_acc_control();
    set_dhash_acc_control(uVar15 | 0x20);
  }
  else {
    uVar13 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | 0x8000 | uVar13 & 0xffff7fdf);
    set_hash_counting_number(0);
    paVar16 = dev;
    buf_vil[4] = '@';
    buf_vil[0] = 'X';
    buf_vil[1] = '\t';
    buf_vil[3] = '\x1c';
    buf_vil[5] = ' ';
    buf_vil[7] = 0x80;
    buf_vil[2] = '\0';
    uVar13 = dev->baud & 0x1f | 0x80;
    buf_vil[6] = (uchar)uVar13;
    buf_vil[8] = CRC5(buf_vil,'@');
    cmd_buf[2] = (uint)buf_vil[8] << 0x18;
    cmd_buf[1] = uVar13 << 8 | 0x40200080;
    buf_vil_tw[0] = 0;
    buf_vil_tw[1] = 0;
    buf_vil_tw[2] = 0;
    buf_vil_tw[3] = buf_vil_tw[3] & 0xffffff00;
    cmd_buf[0] = 0x5809001c;
    memset(&work_vil_1387,0xff,0x34);
    if (paVar16->chain_exist[chainIndex] == 1) {
      uVar13 = get_BC_write_command();
      set_BC_write_command((uVar13 & 0xfff0ffff | chainIndex << 0x10) & 0xffbfffff | 0x800000);
      cgsleep_us(1000);
      bVar5 = (byte)chainIndex | 0x80;
      work_vil_1387.work_type = '\x01';
      work_vil_1387.reserved1[0] = '\0';
      work_vil_1387.reserved1[1] = '\0';
      work_vil_1387.work_count = 0;
      work_vil_1387.data[0] = 0xff;
      work_vil_1387.data[0xb] = 0xff;
      work_vil_1387.chain_id = bVar5;
      set_BC_command_buffer(cmd_buf);
      uVar13 = get_BC_write_command();
      set_BC_write_command(uVar13 & 0xfff0ffff | chainIndex << 0x10 | 0x80800000U);
      cgsleep_us(10000);
      if (coreNum != 0) {
        do {
          iVar17 = 0xbb9;
          if (uVar15 < (uint)opencore_num) {
            work_vil_1387.data[0] = 0xff;
            work_vil_1387.data[0xb] = 0xff;
          }
          else {
            work_vil_1387.data[0] = '\0';
            work_vil_1387.data[0xb] = '\0';
          }
          while ((1 << (chainIndex & 0xffU) & axi_fpga_addr[3]) == 0) {
            cgsleep_us(1000);
            iVar17 = iVar17 + -1;
            if (iVar17 == 0) {
              sprintf(logstr,"Error: send open core work Failed on Chain[%d]!\n",chainIndex);
              writeInitLogFile(logstr);
              goto LAB_000363a6;
            }
          }
          if (uVar15 == 0) {
            uVar13 = 0x11000000;
            work_vil_1387.work_type = '\x11';
          }
          else {
            uVar13 = 0x1000000;
            work_vil_1387.work_type = '\x01';
          }
          pvVar10 = &work_vil_1387;
          puVar6 = buf_vil_tw + 1;
          work_vil_1387.chain_id = bVar5;
          buf_vil_tw[0] =
               (uint)CONCAT11(work_vil_1387.reserved1[0],work_vil_1387.reserved1[1]) |
               (chainIndex & 0xffU | 0x80) << 0x10 | uVar13;
          buf_vil_tw[1] = work_vil_1387.work_count;
          do {
            puVar2 = pvVar10->data;
            puVar1 = pvVar10->data;
            puVar3 = pvVar10->data;
            puVar4 = pvVar10->data;
            pvVar10 = (vil_work_1387 *)&pvVar10->work_count;
            puVar6 = puVar6 + 1;
            *puVar6 = (uint)puVar2[1] << 0x10 | (uint)*puVar1 << 0x18 | (uint)puVar3[3] |
                      (uint)puVar4[2] << 8;
          } while (pvVar10 != (vil_work_1387 *)(work_vil_1387.data + 4));
          buf_vil_tw[5] = 0;
          buf_vil_tw[6] = 0;
          buf_vil_tw[7] = 0;
          buf_vil_tw[8] = 0;
          buf_vil_tw[9] = 0;
          buf_vil_tw[10] = 0;
          buf_vil_tw[0xb] = 0;
          buf_vil_tw[0xc] = 0;
          set_TW_write_command_vil(buf_vil_tw);
          if ((coreNum - 1U == uVar15) && (nullwork_enable)) {
            uVar13 = get_BC_write_command();
            set_BC_write_command(uVar13 | 0x400000);
          }
          uVar15 = uVar15 + 1;
        } while (coreNum != uVar15);
      }
    }
LAB_000363a6:
    uVar15 = get_dhash_acc_control();
    set_dhash_acc_control(uVar15 | (opt_multi_version & 0xfU) << 8 | 0x8000);
  }
  return;
code_r0x000366b0:
  iVar9 = 0;
  do {
    iVar12 = iVar9 + 4;
    *(undefined4 *)((int)puVar6 + iVar9 + 0x40) = *(undefined4 *)((int)buf + iVar9);
    iVar9 = iVar12;
  } while (iVar12 != 0x34);
  iVar17 = iVar17 + 1;
  if (coreNum == iVar17) goto LAB_000362ec;
  goto LAB_00036626;
}

