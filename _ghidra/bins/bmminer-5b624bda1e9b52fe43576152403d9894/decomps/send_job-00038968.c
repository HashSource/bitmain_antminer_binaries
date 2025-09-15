
/* WARNING: Unknown calling convention */

int send_job(uchar *buf)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  void *pvVar7;
  void *__s;
  void **ppvVar8;
  int iVar9;
  uint *puVar10;
  uint uVar11;
  size_t sVar12;
  void *pvVar13;
  char cVar14;
  uint value;
  size_t __size;
  uint uVar15;
  uint uVar16;
  void *local_8b8;
  size_t local_8b0;
  void *local_8ac;
  uint buf2 [32];
  char tmp42 [2048];
  
  memset(buf2,0,0x80);
  cVar14 = opt_debug;
  if (doTestPatten != false) {
    return 0;
  }
  if (*buf != 0x52) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: SEND_JOB_TYPE is wrong : 0x%x\n","send_job",(uint)*buf);
      _applog(7,tmp42,false);
      return -1;
    }
    return -1;
  }
  iVar9 = *(int *)(buf + 4);
  if (opt_debug == false) {
    pvVar7 = malloc(iVar9 + 8);
    if (pvVar7 == (void *)0x0) {
      return -2;
    }
  }
  else if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
    pvVar7 = malloc(iVar9 + 8);
    if (pvVar7 == (void *)0x0) {
LAB_00038ac8:
      if (((use_syslog == false) && (opt_log_output == false)) && (opt_log_level < 7)) {
        return -2;
      }
      snprintf(tmp42,0x800,"%s: malloc buffer failed.\n","send_job");
      _applog(7,tmp42,false);
      return -2;
    }
    cVar14 = '\x01';
  }
  else {
    snprintf(tmp42,0x800,"%s: len = 0x%x\n","send_job",iVar9);
    _applog(7,tmp42,false);
    cVar14 = opt_debug;
    pvVar7 = malloc(iVar9 + 8);
    if (pvVar7 == (void *)0x0) {
      if ((_Bool)cVar14 == false) {
        return -2;
      }
      goto LAB_00038ac8;
    }
  }
  memset(pvVar7,0,iVar9 + 8U);
  memcpy(pvVar7,buf,iVar9 + 8U);
  puVar10 = dev->current_job_start_address;
  if (puVar10 == job_start_address_1) {
    dev->current_job_start_address = job_start_address_2;
  }
  else {
    if (puVar10 != job_start_address_2) {
      if ((cVar14 != '\0') &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,
                 "%s: dev->current_job_start_address = 0x%x, but job_start_address_1 = 0x%x, job_start_address_2 = 0x%x\n"
                 ,"send_job",puVar10,job_start_address_1,job_start_address_2);
        _applog(7,tmp42,false);
        return -3;
      }
      return -3;
    }
    dev->current_job_start_address = job_start_address_1;
  }
  uVar15 = (uint)*(ushort *)((int)pvVar7 + 0x3c);
  if ((uVar15 & 0x3f) < 0x38) {
    __size = (uVar15 & 0xffc0) + 0x40;
  }
  else {
    __size = (uVar15 & 0xffc0) + 0x80;
  }
  __s = malloc(__size);
  if (__s == (void *)0x0) {
    if ((cVar14 != '\0') &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: malloc coinbase_padding failed.\n","send_job");
      _applog(7,tmp42,false);
      return -4;
    }
    return -4;
  }
  if ((cVar14 != '\0') &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"%s: coinbase_padding = 0x%x","send_job",__s);
    _applog(7,tmp42,false);
  }
  value = (uint)*(ushort *)((int)pvVar7 + 0x42);
  if (value == 0) {
    local_8b8 = (void *)0x0;
    local_8b0 = 0;
  }
  else {
    local_8b0 = value << 5;
    local_8b8 = malloc(local_8b0);
    if (local_8b8 == (void *)0x0) {
      if ((opt_debug != false) &&
         (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
        snprintf(tmp42,0x800,"%s: malloc merkles_bin failed.\n","send_job");
        _applog(7,tmp42,false);
        return -5;
      }
      return -5;
    }
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: merkles_bin = 0x%x","send_job",local_8b8);
      _applog(7,tmp42,false);
    }
  }
  memset(__s,0,__size);
  memcpy(__s,buf + 0x50,uVar15);
  l_coinbase_padding = c_coinbase_padding;
  c_coinbase_padding = __size;
  *(undefined1 *)((int)__s + uVar15) = 0x80;
  *(uint *)((int)__s + (__size - 4)) =
       (uVar15 << 3 & 0xff00) << 8 | (uVar15 << 3 & 0xff0000) >> 8 | uVar15 << 0x1b;
  uVar11 = 0;
  *(undefined4 *)((int)__s + (__size - 8)) = 0;
  do {
    *(undefined1 *)((int)dev->current_job_start_address + uVar11) =
         *(undefined1 *)((int)__s + uVar11);
    uVar11 = uVar11 + 1;
  } while (uVar11 < __size);
  uVar11 = 0;
  local_8ac = pvVar7;
  do {
    uVar16 = (uint)*(byte *)((int)dev->current_job_start_address + uVar11);
    if (((uVar16 != *(byte *)((int)__s + uVar11)) && (opt_debug != false)) &&
       ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
      snprintf(tmp42,0x800,
               "%s: coinbase_padding_in_ddr[%d] = 0x%x, but *(coinbase_padding + %d) = 0x%x",
               "send_job",uVar11,uVar16,uVar11,(uint)*(byte *)((int)__s + uVar11));
      _applog(7,tmp42,false);
    }
    pvVar7 = local_8ac;
    uVar11 = uVar11 + 1;
  } while (uVar11 < __size);
  l_merkles_num = c_merkles_num;
  c_merkles_num = value;
  if (value != 0) {
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,"%s: copy merkle bin into memory ...\n","send_job");
      _applog(7,tmp42,false);
    }
    memset(local_8b8,0,local_8b0);
    memcpy(local_8b8,buf + uVar15 + 0x50,local_8b0);
    if (local_8b0 != 0) {
      sVar12 = 0;
      do {
        *(undefined1 *)((int)dev->current_job_start_address + sVar12 + __size) =
             *(undefined1 *)((int)local_8b8 + sVar12);
        sVar12 = sVar12 + 1;
      } while (local_8b0 != sVar12);
      sVar12 = 0;
      do {
        uVar15 = (uint)*(byte *)((int)dev->current_job_start_address + sVar12 + __size);
        if (((uVar15 != *(byte *)((int)local_8b8 + sVar12)) && (opt_debug != false)) &&
           ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
          snprintf(tmp42,0x800,"%s: merkles_in_ddr[%d] = 0x%x, but *(merkles_bin + %d) =0x%x",
                   "send_job",sVar12,uVar15,sVar12,(uint)*(byte *)((int)local_8b8 + sVar12));
          _applog(7,tmp42,false);
        }
        sVar12 = sVar12 + 1;
      } while (local_8b0 != sVar12);
    }
  }
  uVar15 = get_dhash_acc_control();
  set_dhash_acc_control(uVar15 & 0xffffffbf);
  while (uVar15 = get_dhash_acc_control(), (uVar15 & 0x40) != 0) {
    while( true ) {
      cgsleep_ms(1);
      if ((opt_debug == false) ||
         (((use_syslog == false && (opt_log_output == false)) && (opt_log_level < 7)))) break;
      snprintf(tmp42,0x800,"%s: run bit is 1 after set it to 0\n","send_job");
      _applog(7,tmp42,false);
      uVar15 = get_dhash_acc_control();
      if ((uVar15 & 0x40) == 0) goto LAB_00038e80;
    }
  }
LAB_00038e80:
  cgsleep_ms(1);
  if (dev->current_job_start_address == job_start_address_1) {
    set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x200000);
  }
  else if (dev->current_job_start_address == job_start_address_2) {
    set_job_start_address(PHY_MEM_NONCE2_JOBID_ADDRESS + 0x210000);
  }
  bVar5 = *(byte *)((int)pvVar7 + 9);
  if ((int)((uint)bVar5 << 0x1e) < 0) {
    bVar6 = *(byte *)((int)pvVar7 + 10);
    set_ticket_mask((uint)bVar6);
    dev->diff = bVar6;
  }
  set_job_id(*(uint *)((int)pvVar7 + 0xc));
  set_block_header_version(*(uint *)((int)pvVar7 + 0x10));
  memset(buf2,0,0x80);
  ppvVar8 = &local_8ac;
  pvVar13 = pvVar7;
  do {
    pbVar2 = (byte *)((int)pvVar13 + 0x16);
    pbVar1 = (byte *)((int)pvVar13 + 0x17);
    pbVar3 = (byte *)((int)pvVar13 + 0x14);
    pbVar4 = (byte *)((int)pvVar13 + 0x15);
    pvVar13 = (void *)((int)pvVar13 + 4);
    ppvVar8 = ppvVar8 + 1;
    *ppvVar8 = (void *)((uint)*pbVar2 << 0x10 | (uint)*pbVar1 << 0x18 | (uint)*pbVar3 |
                       (uint)*pbVar4 << 8);
  } while (ppvVar8 != (void **)(buf2 + 7));
  set_pre_header_hash(buf2);
  set_time_stamp(*(uint *)((int)pvVar7 + 0x34));
  set_target_bits(*(uint *)((int)pvVar7 + 0x38));
  set_coinbase_length_and_nonce2_length
            ((uint)*(ushort *)((int)pvVar7 + 0x3e) << 0x10 |
             (uint)*(byte *)((int)pvVar7 + 0x40) << 8 | (__size << 0x12) >> 0x18);
  buf2[1] = *(uint *)((int)pvVar7 + 0x4c);
  buf2[0] = *(uint *)((int)pvVar7 + 0x48);
  set_work_nonce2(buf2);
  set_merkle_bin_number(value);
  set_job_length(__size + local_8b0 & 0xffff);
  cgsleep_ms(1);
  if (gBegin_get_nonce == false) {
    uVar15 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar15 | 0x10000);
    gBegin_get_nonce = true;
  }
  if ((int)((uint)bVar5 << 0x1f) < 0) {
    if (opt_multi_version == 0) {
      uVar15 = get_dhash_acc_control();
      set_dhash_acc_control(uVar15 | 0x80);
LAB_00038f6c:
      uVar15 = get_dhash_acc_control();
      set_dhash_acc_control(uVar15 & 0xfffff0ff | (opt_multi_version & 0xfU) << 8 | 0x60);
      goto LAB_00038f86;
    }
    uVar15 = get_dhash_acc_control();
    set_dhash_acc_control(uVar15 | 0x80);
  }
  else if (opt_multi_version == 0) goto LAB_00038f6c;
  uVar15 = get_dhash_acc_control();
  set_dhash_acc_control(uVar15 & 0xfffff0ff | (opt_multi_version & 0xfU) << 8 | 0x8060);
LAB_00038f86:
  free(pvVar7);
  free(__s);
  if (*(short *)((int)pvVar7 + 0x42) != 0) {
    free(local_8b8);
  }
  if ((opt_debug != false) &&
     (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
    snprintf(tmp42,0x800,"--- %s end\n","send_job");
    _applog(7,tmp42,false);
  }
  cgtime(&tv_send_job);
  return 0;
}

