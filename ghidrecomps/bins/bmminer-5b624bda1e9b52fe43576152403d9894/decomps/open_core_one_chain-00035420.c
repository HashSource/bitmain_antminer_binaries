
/* WARNING: Unknown calling convention */

void open_core_one_chain(int chainIndex,_Bool nullwork_enable)

{
  uchar *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  uint *puVar7;
  uint uVar8;
  int iVar9;
  vil_work_1387 *pvVar10;
  uchar *puVar11;
  int iVar12;
  uint uVar13;
  int iVar14;
  all_parameters *paVar15;
  uint uVar16;
  uchar gateblk [4];
  uchar buf_vil [9];
  uint cmd_buf [3];
  uint buf [13];
  uint buf_vil_tw [13];
  uchar data [52];
  vil_work_1387 work_vil_1387;
  char logstr [256];
  
  iVar14 = 0;
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
    uVar5 = get_dhash_acc_control();
    set_dhash_acc_control(uVar5 & 0xffffffdf);
    set_hash_counting_number(0);
    paVar15 = dev;
    gateblk[1] = '\0';
    gateblk[0] = 0x86;
    gateblk[3] = 0x80;
    uVar13 = dev->baud | 0x80;
    gateblk[2] = (uchar)uVar13;
    bVar4 = CRC5(gateblk,'\x1b');
    uVar5 = bVar4 & 0x1f | 0x80;
    gateblk[3] = (uchar)uVar5;
    if ((opt_debug == false) ||
       (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7)))) {
      uVar8 = 0x86000000;
    }
    else {
      snprintf(logstr,0x800,
               "%s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n",
               "open_core_one_chain",0x86,0,uVar13,uVar5);
      _applog(7,logstr,false);
      uVar13 = (uint)gateblk[2];
      uVar5 = (uint)gateblk[3];
      uVar8 = (uint)gateblk[0] << 0x18 | (uint)gateblk[1] << 0x10;
      paVar15 = dev;
    }
    uVar16 = 0;
    cmd_buf[0] = uVar5 | uVar8 | uVar13 << 8;
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
    if (paVar15->chain_exist[chainIndex] == 1) {
      set_BC_command_buffer(cmd_buf);
      uVar5 = get_BC_write_command();
      bVar4 = (byte)chainIndex | 0x80;
      iVar14 = 0;
      set_BC_write_command(uVar5 & 0xfff0ffff | chainIndex << 0x10 | 0x80800000U);
      cgsleep_us(10000);
      puVar6 = axi_fpga_addr;
LAB_00035852:
      uVar5 = puVar6[3];
      while ((1 << (chainIndex & 0xffU) & uVar5) == 0) {
        cgsleep_us(1000);
        uVar5 = axi_fpga_addr[3];
      }
      if (iVar14 == 0) {
        data[1] = bVar4;
        data[0] = '\x11';
        uVar5 = get_BC_write_command();
        set_BC_write_command(uVar5 & 0xffbfffff);
        uVar5 = data._0_4_ & 0xff;
        uVar13 = (uint)data._0_4_ >> 8 & 0xff;
      }
      else {
        data[1] = bVar4;
        data[0] = '\x01';
        if ((iVar14 == 0x71) && (nullwork_enable)) {
          uVar5 = get_BC_write_command();
          set_BC_write_command(uVar5 & ((chainIndex & 0xfU) << 0x10 | 0xc00000));
          uVar5 = data._0_4_ & 0xff;
          uVar13 = (uint)data._0_4_ >> 8 & 0xff;
        }
        else {
          uVar5 = 1;
          uVar13 = chainIndex & 0xffU | 0x80;
        }
      }
      puVar6 = axi_fpga_addr;
      buf[0] = 0;
      puVar11 = data;
      buf[1] = 0;
      puVar7 = cmd_buf + 2;
      buf[2] = 0;
      iVar9 = 1;
      buf[3] = buf[3] & 0xffffff00;
      do {
        puVar7 = puVar7 + 1;
        *puVar7 = uVar5 << 0x18 | uVar13 << 0x10 | (uint)puVar11[3] | (uint)puVar11[2] << 8;
        if (iVar9 == 10) {
          buf[9] = uVar16;
          uVar16 = uVar16 + 1;
        }
        else if (iVar9 == 0xd) goto code_r0x000358e0;
        uVar5 = (uint)puVar11[4];
        iVar9 = iVar9 + 1;
        uVar13 = (uint)puVar11[5];
        puVar11 = puVar11 + 4;
      } while( true );
    }
LAB_0003555c:
    uVar5 = get_dhash_acc_control();
    set_dhash_acc_control(uVar5 | 0x20);
  }
  else {
    uVar5 = get_dhash_acc_control();
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | 0x8000 | uVar5 & 0xffff7fdf);
    set_hash_counting_number(0);
    paVar15 = dev;
    buf_vil[4] = '@';
    buf_vil[0] = 'X';
    buf_vil[1] = '\t';
    buf_vil[3] = '\x1c';
    buf_vil[5] = ' ';
    buf_vil[7] = 0x80;
    buf_vil[2] = '\0';
    uVar5 = dev->baud & 0x1f | 0x80;
    buf_vil[6] = (uchar)uVar5;
    buf_vil[8] = CRC5(buf_vil,'@');
    cmd_buf[2] = (uint)buf_vil[8] << 0x18;
    cmd_buf[1] = uVar5 << 8 | 0x40200080;
    buf_vil_tw[0] = 0;
    buf_vil_tw[1] = 0;
    buf_vil_tw[2] = 0;
    buf_vil_tw[3] = buf_vil_tw[3] & 0xffffff00;
    cmd_buf[0] = 0x5809001c;
    memset(&work_vil_1387,0xff,0x34);
    if (paVar15->chain_exist[chainIndex] == 1) {
      uVar5 = get_BC_write_command();
      bVar4 = (byte)chainIndex | 0x80;
      set_BC_write_command((uVar5 & 0xfff0ffff | chainIndex << 0x10) & 0xffbfffff | 0x800000);
      cgsleep_us(1000);
      work_vil_1387.data[0] = 0xff;
      work_vil_1387.data[0xb] = 0xff;
      work_vil_1387.work_type = '\x01';
      work_vil_1387.reserved1[0] = '\0';
      work_vil_1387.reserved1[1] = '\0';
      work_vil_1387.work_count = 0;
      work_vil_1387.chain_id = bVar4;
      set_BC_command_buffer(cmd_buf);
      uVar5 = get_BC_write_command();
      set_BC_write_command(chainIndex << 0x10 | 0x80800000U | uVar5 & 0xfff0ffff);
      cgsleep_us(10000);
      while( true ) {
        iVar9 = 0xbb9;
        while ((1 << (chainIndex & 0xffU) & axi_fpga_addr[3]) == 0) {
          cgsleep_us(1000);
          iVar9 = iVar9 + -1;
          if (iVar9 == 0) {
            sprintf(logstr,"Error: send open core work Failed on Chain[%d]!\n",chainIndex);
            writeInitLogFile(logstr);
            goto LAB_00035612;
          }
        }
        if (iVar14 == 0) {
          uVar5 = 0x11000000;
          work_vil_1387.work_type = '\x11';
        }
        else {
          uVar5 = 0x1000000;
          work_vil_1387.work_type = '\x01';
        }
        pvVar10 = &work_vil_1387;
        puVar6 = buf_vil_tw + 1;
        work_vil_1387.chain_id = bVar4;
        buf_vil_tw[0] =
             (uint)CONCAT11(work_vil_1387.reserved1[0],work_vil_1387.reserved1[1]) |
             (chainIndex & 0xffU | 0x80) << 0x10 | uVar5;
        buf_vil_tw[1] = work_vil_1387.work_count;
        do {
          puVar1 = pvVar10->data;
          puVar11 = pvVar10->data;
          puVar2 = pvVar10->data;
          puVar3 = pvVar10->data;
          pvVar10 = (vil_work_1387 *)&pvVar10->work_count;
          puVar6 = puVar6 + 1;
          *puVar6 = (uint)puVar1[1] << 0x10 | (uint)*puVar11 << 0x18 | (uint)puVar2[3] |
                    (uint)puVar3[2] << 8;
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
        if (iVar14 == 0x71) break;
        iVar14 = iVar14 + 1;
      }
      if (nullwork_enable) {
        uVar5 = get_BC_write_command();
        set_BC_write_command(uVar5 | 0x400000);
      }
    }
LAB_00035612:
    uVar5 = get_dhash_acc_control();
    set_dhash_acc_control(uVar5 | (opt_multi_version & 0xfU) << 8 | 0x8000);
  }
  return;
code_r0x000358e0:
  iVar9 = 0;
  do {
    iVar12 = iVar9 + 4;
    *(undefined4 *)((int)puVar6 + iVar9 + 0x40) = *(undefined4 *)((int)buf + iVar9);
    iVar9 = iVar12;
  } while (iVar12 != 0x34);
  iVar14 = iVar14 + 1;
  if (iVar14 == 0x72) goto LAB_0003555c;
  goto LAB_00035852;
}

