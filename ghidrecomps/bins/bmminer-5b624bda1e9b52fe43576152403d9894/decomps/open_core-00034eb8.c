
/* WARNING: Unknown calling convention */

void open_core(_Bool nullwork_enable)

{
  uchar *puVar1;
  uchar *puVar2;
  uchar *puVar3;
  byte bVar4;
  uint uVar5;
  uint *puVar6;
  uint uVar7;
  uint *puVar8;
  uint uVar9;
  int iVar10;
  uchar *puVar11;
  int iVar12;
  vil_work_1387 *pvVar13;
  all_parameters *paVar14;
  uint uVar15;
  int iVar16;
  uint local_928;
  uchar gateblk [4];
  uchar buf_vil [9];
  uint cmd_buf [3];
  uint buf [13];
  uint buf_vil_tw [13];
  uchar data [52];
  vil_work_1387 work_vil_1387;
  char logstr [256];
  
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
  if (opt_multi_version != 0) {
    uVar5 = get_dhash_acc_control();
    uVar15 = 0;
    set_dhash_acc_control((opt_multi_version & 0xfU) << 8 | 0x8000 | uVar5 & 0xffff7fdf);
    set_hash_counting_number(0);
    paVar14 = dev;
    buf_vil[4] = '@';
    buf_vil[0] = 'X';
    buf_vil[2] = '\0';
    buf_vil[1] = '\t';
    buf_vil[3] = '\x1c';
    buf_vil[5] = ' ';
    uVar5 = dev->baud & 0x1f | 0x80;
    buf_vil[6] = (uchar)uVar5;
    buf_vil[7] = 0x80;
    buf_vil[8] = CRC5(buf_vil,'@');
    cmd_buf[2] = (uint)buf_vil[8] << 0x18;
    cmd_buf[1] = uVar5 << 8 | 0x40200080;
    buf_vil_tw[0] = 0;
    buf_vil_tw[1] = 0;
    buf_vil_tw[2] = 0;
    buf_vil_tw[3] = buf_vil_tw[3] & 0xffffff00;
    cmd_buf[0] = 0x5809001c;
    memset(&work_vil_1387,0xff,0x34);
    do {
      if (paVar14->chain_exist[uVar15] == 1) {
        bVar4 = (byte)uVar15 | 0x80;
        uVar5 = get_BC_write_command();
        set_BC_write_command((uVar5 & 0xfff0ffff | uVar15 << 0x10) & 0xffbfffff | 0x800000);
        cgsleep_us(1000);
        work_vil_1387.data[0] = 0xff;
        work_vil_1387.data[0xb] = 0xff;
        work_vil_1387.work_type = '\x01';
        iVar16 = 0;
        work_vil_1387.reserved1[0] = '\0';
        work_vil_1387.reserved1[1] = '\0';
        work_vil_1387.work_count = 0;
        work_vil_1387.chain_id = bVar4;
        set_BC_command_buffer(cmd_buf);
        uVar5 = get_BC_write_command();
        set_BC_write_command(uVar15 << 0x10 | 0x80800000 | uVar5 & 0xfff0ffff);
        cgsleep_us(10000);
        while( true ) {
          iVar10 = 0xbb9;
          while ((1 << (uVar15 & 0xff) & axi_fpga_addr[3]) == 0) {
            cgsleep_us(1000);
            iVar10 = iVar10 + -1;
            if (iVar10 == 0) {
              sprintf(logstr,"Error: send open core work Failed on Chain[%d]!\n",uVar15);
              writeInitLogFile(logstr);
              goto joined_r0x00035228;
            }
          }
          if (iVar16 == 0) {
            uVar5 = 0x11000000;
            work_vil_1387.work_type = '\x11';
          }
          else {
            uVar5 = 0x1000000;
            work_vil_1387.work_type = '\x01';
          }
          pvVar13 = &work_vil_1387;
          puVar6 = buf_vil_tw + 1;
          work_vil_1387.chain_id = bVar4;
          buf_vil_tw[0] =
               (uint)CONCAT11(work_vil_1387.reserved1[0],work_vil_1387.reserved1[1]) |
               (uVar15 | 0x80) << 0x10 | uVar5;
          buf_vil_tw[1] = work_vil_1387.work_count;
          do {
            puVar1 = pvVar13->data;
            puVar11 = pvVar13->data;
            puVar2 = pvVar13->data;
            puVar3 = pvVar13->data;
            pvVar13 = (vil_work_1387 *)&pvVar13->work_count;
            puVar6 = puVar6 + 1;
            *puVar6 = (uint)puVar1[1] << 0x10 | (uint)*puVar11 << 0x18 | (uint)puVar2[3] |
                      (uint)puVar3[2] << 8;
          } while (pvVar13 != (vil_work_1387 *)(work_vil_1387.data + 4));
          buf_vil_tw[5] = 0;
          buf_vil_tw[6] = 0;
          buf_vil_tw[7] = 0;
          buf_vil_tw[8] = 0;
          buf_vil_tw[9] = 0;
          buf_vil_tw[10] = 0;
          buf_vil_tw[0xb] = 0;
          buf_vil_tw[0xc] = 0;
          set_TW_write_command_vil(buf_vil_tw);
          if (iVar16 == 0x71) break;
          iVar16 = iVar16 + 1;
        }
        if (nullwork_enable) {
          uVar5 = get_BC_write_command();
          set_BC_write_command(uVar5 | 0x400000);
        }
      }
joined_r0x00035228:
      if (uVar15 == 0xf) {
        uVar5 = get_dhash_acc_control();
        set_dhash_acc_control(uVar5 | (opt_multi_version & 0xfU) << 8 | 0x8000);
        return;
      }
      uVar15 = uVar15 + 1;
      paVar14 = dev;
    } while( true );
  }
  uVar5 = get_dhash_acc_control();
  set_dhash_acc_control(uVar5 & 0xffffffdf);
  set_hash_counting_number(0);
  paVar14 = dev;
  gateblk[0] = 0x86;
  gateblk[3] = 0x80;
  gateblk[1] = '\0';
  uVar15 = dev->baud | 0x80;
  gateblk[2] = (uchar)uVar15;
  bVar4 = CRC5(gateblk,'\x1b');
  uVar5 = bVar4 & 0x1f | 0x80;
  gateblk[3] = (uchar)uVar5;
  if ((opt_debug == false) ||
     (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7)))) {
    uVar9 = 0x86000000;
  }
  else {
    snprintf(logstr,0x800,"%s: gateblk[0]=0x%x, gateblk[1]=0x%x, gateblk[2]=0x%x, gateblk[3]=0x%x\n"
             ,"open_core",0x86,0,uVar15,uVar5);
    _applog(7,logstr,false);
    uVar15 = (uint)gateblk[2];
    uVar5 = (uint)gateblk[3];
    uVar9 = (uint)gateblk[0] << 0x18 | (uint)gateblk[1] << 0x10;
    paVar14 = dev;
  }
  cmd_buf[0] = uVar9 | uVar5 | uVar15 << 8;
  uVar5 = 0;
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
LAB_0003500c:
  if (paVar14->chain_exist[local_928] == 1) {
    uVar9 = local_928 & 0xff | 0x80;
    iVar16 = 0;
    set_BC_command_buffer(cmd_buf);
    uVar15 = get_BC_write_command();
    set_BC_write_command(local_928 << 0x10 | 0x80800000 | uVar15 & 0xfff0ffff);
    cgsleep_us(10000);
    puVar6 = axi_fpga_addr;
LAB_0003505e:
    uVar15 = puVar6[3];
    while ((1 << (local_928 & 0xff) & uVar15) == 0) {
      cgsleep_us(1000);
      uVar15 = axi_fpga_addr[3];
    }
    if (iVar16 == 0) {
      data[1] = (byte)local_928 | 0x80;
      data[0] = '\x11';
      uVar15 = get_BC_write_command();
      set_BC_write_command(uVar15 & 0xffbfffff);
      uVar15 = data._0_4_ & 0xff;
      uVar7 = (uint)data._0_4_ >> 8 & 0xff;
    }
    else {
      data[1] = (uchar)uVar9;
      data[0] = '\x01';
      if ((iVar16 == 0x71) && (nullwork_enable)) {
        uVar15 = get_BC_write_command();
        set_BC_write_command(uVar15 & (local_928 << 0x10 | 0xc00000));
        uVar15 = data._0_4_ & 0xff;
        uVar7 = (uint)data._0_4_ >> 8 & 0xff;
      }
      else {
        uVar15 = 1;
        uVar7 = uVar9;
      }
    }
    puVar6 = axi_fpga_addr;
    buf[0] = 0;
    puVar11 = data;
    buf[1] = 0;
    puVar8 = cmd_buf + 2;
    buf[2] = 0;
    iVar10 = 1;
    buf[3] = buf[3] & 0xffffff00;
    do {
      puVar8 = puVar8 + 1;
      *puVar8 = uVar15 << 0x18 | uVar7 << 0x10 | (uint)puVar11[3] | (uint)puVar11[2] << 8;
      if (iVar10 == 10) {
        buf[9] = uVar5;
        uVar5 = uVar5 + 1;
      }
      else if (iVar10 == 0xd) goto code_r0x000350ec;
      uVar15 = (uint)puVar11[4];
      iVar10 = iVar10 + 1;
      uVar7 = (uint)puVar11[5];
      puVar11 = puVar11 + 4;
    } while( true );
  }
  if (local_928 != 0xf) goto LAB_00035008;
LAB_00035114:
  uVar5 = get_dhash_acc_control();
  set_dhash_acc_control(uVar5 | 0x20);
  return;
code_r0x000350ec:
  iVar10 = 0;
  do {
    iVar12 = iVar10 + 4;
    *(undefined4 *)((int)puVar6 + iVar10 + 0x40) = *(undefined4 *)((int)buf + iVar10);
    iVar10 = iVar12;
  } while (iVar12 != 0x34);
  iVar16 = iVar16 + 1;
  if (iVar16 == 0x72) goto code_r0x00035108;
  goto LAB_0003505e;
code_r0x00035108:
  if (local_928 == 0xf) goto LAB_00035114;
LAB_00035008:
  local_928 = local_928 + 1;
  paVar14 = dev;
  goto LAB_0003500c;
}

