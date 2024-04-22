
/* WARNING: Unknown calling convention */

int send_job(uchar *buf)

{
  byte *pbVar1;
  byte *pbVar2;
  byte *pbVar3;
  byte *pbVar4;
  byte bVar5;
  byte bVar6;
  int iVar7;
  char *pcVar8;
  char *pcVar9;
  int **ppiVar10;
  char *pcVar11;
  void *pvVar12;
  void *__s;
  uint **ppuVar13;
  void **ppvVar14;
  int iVar15;
  uint *puVar16;
  uint uVar17;
  size_t sVar18;
  void *pvVar19;
  char cVar20;
  uint value;
  size_t __size;
  uint uVar21;
  void *local_8b8;
  size_t local_8b0;
  void *local_8ac;
  uint buf2 [32];
  char tmp42 [2048];
  
  iVar7 = DAT_00038b04;
  memset(buf2,0,0x80);
  pcVar9 = DAT_00038b0c;
  pcVar8 = DAT_00038b08;
  if (*(char *)(iVar7 + 0xdd4) != '\0') {
    return 0;
  }
  if (*buf != 0x52) {
    if ((*DAT_00038b08 != '\0') &&
       (((*DAT_00038b0c != '\0' || (*DAT_00038b10 != '\0')) || (6 < *DAT_00038b14)))) {
      snprintf(tmp42,0x800,DAT_00038b18,DAT_00038b1c,(uint)*buf);
      _applog(7,tmp42,false);
      return -1;
    }
    return -1;
  }
  iVar15 = *(int *)(buf + 4);
  if (*DAT_00038b08 == '\0') {
    pvVar12 = malloc(iVar15 + 8);
    cVar20 = '\0';
    if (pvVar12 == (void *)0x0) {
      return -2;
    }
  }
  else if (((*DAT_00038b0c == '\0') && (*DAT_00038b10 == '\0')) && (*DAT_00038b14 < 7)) {
    pvVar12 = malloc(iVar15 + 8);
    if (pvVar12 == (void *)0x0) {
LAB_00038ac8:
      if (((*pcVar9 == '\0') && (*DAT_00038b10 == '\0')) && (*DAT_00038b14 < 7)) {
        return -2;
      }
      snprintf(tmp42,0x800,DAT_00038b2c,DAT_00038b1c);
      _applog(7,tmp42,false);
      return -2;
    }
    cVar20 = '\x01';
  }
  else {
    snprintf(tmp42,0x800,DAT_00038b28,DAT_00038b1c,iVar15);
    _applog(7,tmp42,false);
    cVar20 = *pcVar8;
    pvVar12 = malloc(iVar15 + 8);
    if (pvVar12 == (void *)0x0) {
      if (cVar20 == '\0') {
        return -2;
      }
      goto LAB_00038ac8;
    }
  }
  ppiVar10 = DAT_00038b20;
  memset(pvVar12,0,iVar15 + 8U);
  memcpy(pvVar12,buf,iVar15 + 8U);
  ppuVar13 = (uint **)*ppiVar10;
  puVar16 = *ppuVar13;
  if (puVar16 == job_start_address_1) {
    *ppuVar13 = job_start_address_2;
  }
  else {
    if (puVar16 != job_start_address_2) {
      if ((cVar20 != '\0') &&
         (((*DAT_00038b0c != '\0' || (*DAT_00038b10 != '\0')) || (6 < *DAT_00038b14)))) {
        snprintf(tmp42,0x800,DAT_00038b24,DAT_00038b1c,puVar16,job_start_address_1,
                 job_start_address_2);
        _applog(7,tmp42,false);
        return -3;
      }
      return -3;
    }
    *ppuVar13 = job_start_address_1;
  }
  uVar21 = (uint)*(ushort *)((int)pvVar12 + 0x3c);
  if ((uVar21 & 0x3f) < 0x38) {
    __size = (uVar21 & 0xffc0) + 0x40;
  }
  else {
    __size = (uVar21 & 0xffc0) + 0x80;
  }
  __s = malloc(__size);
  if (__s == (void *)0x0) {
    if ((cVar20 != '\0') &&
       (((*DAT_000390e0 != '\0' || (*DAT_000390e4 != '\0')) || (6 < *DAT_000390e8)))) {
      snprintf(tmp42,0x800,DAT_000390f8,DAT_000390f0);
      _applog(7,tmp42,false);
      return -4;
    }
    return -4;
  }
  if ((cVar20 != '\0') &&
     (((*DAT_00038e3c != '\0' || (*DAT_00038e40 != '\0')) || (6 < *DAT_00038e44)))) {
    snprintf(tmp42,0x800,DAT_00038e48,DAT_00038e4c,__s);
    _applog(7,tmp42,false);
  }
  value = (uint)*(ushort *)((int)pvVar12 + 0x42);
  if (value == 0) {
    local_8b8 = (void *)0x0;
    local_8b0 = 0;
  }
  else {
    local_8b0 = value << 5;
    local_8b8 = malloc(local_8b0);
    if (local_8b8 == (void *)0x0) {
      if ((*pcVar8 != '\0') &&
         (((*DAT_000390e0 != '\0' || (*DAT_000390e4 != '\0')) || (6 < *DAT_000390e8)))) {
        snprintf(tmp42,0x800,DAT_000390fc,DAT_000390f0);
        _applog(7,tmp42,false);
        return -5;
      }
      return -5;
    }
    if ((*pcVar8 != '\0') &&
       (((*DAT_00038e3c != '\0' || (*DAT_00038e40 != '\0')) || (6 < *DAT_00038e44)))) {
      snprintf(tmp42,0x800,DAT_00038e50,DAT_00038e4c,local_8b8);
      _applog(7,tmp42,false);
    }
  }
  memset(__s,0,__size);
  memcpy(__s,buf + 0x50,uVar21);
  l_coinbase_padding = c_coinbase_padding;
  c_coinbase_padding = __size;
  *(undefined *)((int)__s + uVar21) = 0x80;
  *(uint *)((int)__s + (__size - 4)) =
       (uVar21 << 3 & 0xff00) << 8 | (uVar21 << 3 & 0xff0000) >> 8 | uVar21 << 0x1b;
  uVar17 = 0;
  *(undefined4 *)((int)__s + (__size - 8)) = 0;
  do {
    *(undefined *)(**ppiVar10 + uVar17) = *(undefined *)((int)__s + uVar17);
    uVar17 = uVar17 + 1;
  } while (uVar17 < __size);
  uVar17 = 0;
  local_8ac = pvVar12;
  do {
    if ((((uint)*(byte *)(**ppiVar10 + uVar17) != (uint)*(byte *)((int)__s + uVar17)) &&
        (*pcVar8 != '\0')) &&
       ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
      snprintf(tmp42,0x800,DAT_00038e54,DAT_00038e4c,uVar17,(uint)*(byte *)(**ppiVar10 + uVar17),
               uVar17,(uint)*(byte *)((int)__s + uVar17));
      _applog(7,tmp42,false);
    }
    pvVar12 = local_8ac;
    uVar17 = uVar17 + 1;
  } while (uVar17 < __size);
  l_merkles_num = c_merkles_num;
  c_merkles_num = value;
  if (value != 0) {
    if ((*pcVar8 != '\0') &&
       (((*DAT_00038e3c != '\0' || (*DAT_00038e40 != '\0')) || (6 < *DAT_00038e44)))) {
      snprintf(tmp42,0x800,DAT_00038e58,DAT_00038e4c);
      _applog(7,tmp42,false);
    }
    memset(local_8b8,0,local_8b0);
    memcpy(local_8b8,buf + uVar21 + 0x50,local_8b0);
    if (local_8b0 != 0) {
      sVar18 = 0;
      do {
        *(undefined *)(**ppiVar10 + __size + sVar18) = *(undefined *)((int)local_8b8 + sVar18);
        sVar18 = sVar18 + 1;
      } while (local_8b0 != sVar18);
      sVar18 = 0;
      do {
        uVar21 = (uint)*(byte *)(**ppiVar10 + __size + sVar18);
        if (((uVar21 != *(byte *)((int)local_8b8 + sVar18)) && (*pcVar8 != '\0')) &&
           ((use_syslog != false || ((opt_log_output != false || (6 < opt_log_level)))))) {
          snprintf(tmp42,0x800,DAT_00038e5c,DAT_00038e4c,sVar18,uVar21,sVar18,
                   (uint)*(byte *)((int)local_8b8 + sVar18));
          _applog(7,tmp42,false);
        }
        sVar18 = sVar18 + 1;
      } while (local_8b0 != sVar18);
    }
  }
  pcVar11 = DAT_00038e40;
  pcVar9 = DAT_00038e3c;
  uVar21 = get_dhash_acc_control();
  set_dhash_acc_control(uVar21 & 0xffffffbf);
  while (uVar21 = get_dhash_acc_control(), (uVar21 & 0x40) != 0) {
    while( true ) {
      cgsleep_ms(1);
      if ((*pcVar8 == '\0') || (((*pcVar9 == '\0' && (*pcVar11 == '\0')) && (opt_log_level < 7))))
      break;
      snprintf(tmp42,0x800,DAT_00038e60,DAT_00038e4c);
      _applog(7,tmp42,false);
      uVar21 = get_dhash_acc_control();
      if ((uVar21 & 0x40) == 0) goto LAB_00038e80;
    }
  }
LAB_00038e80:
  cgsleep_ms(1);
  if ((uint *)**ppiVar10 == job_start_address_1) {
    set_job_start_address(*(int *)(DAT_00039100 + 0x8c) + 0x200000);
  }
  else if ((uint *)**ppiVar10 == *(uint **)(DAT_000390d4 + 0x20c)) {
    set_job_start_address(*(int *)(DAT_00039100 + 0x8c) + 0x210000);
  }
  bVar5 = *(byte *)((int)pvVar12 + 9);
  if ((int)((uint)bVar5 << 0x1e) < 0) {
    bVar6 = *(byte *)((int)pvVar12 + 10);
    set_ticket_mask((uint)bVar6);
    *(byte *)((int)*ppiVar10 + 0x2feb) = bVar6;
  }
  set_job_id(*(uint *)((int)pvVar12 + 0xc));
  set_block_header_version(*(uint *)((int)pvVar12 + 0x10));
  memset(buf2,0,0x80);
  iVar15 = DAT_000390d8;
  ppvVar14 = &local_8ac;
  pvVar19 = pvVar12;
  do {
    pbVar2 = (byte *)((int)pvVar19 + 0x16);
    pbVar1 = (byte *)((int)pvVar19 + 0x17);
    pbVar3 = (byte *)((int)pvVar19 + 0x14);
    pbVar4 = (byte *)((int)pvVar19 + 0x15);
    pvVar19 = (void *)((int)pvVar19 + 4);
    ppvVar14 = ppvVar14 + 1;
    *ppvVar14 = (void *)((uint)*pbVar2 << 0x10 | (uint)*pbVar1 << 0x18 | (uint)*pbVar3 |
                        (uint)*pbVar4 << 8);
  } while (ppvVar14 != (void **)(buf2 + 7));
  set_pre_header_hash(buf2);
  set_time_stamp(*(uint *)((int)pvVar12 + 0x34));
  set_target_bits(*(uint *)((int)pvVar12 + 0x38));
  set_coinbase_length_and_nonce2_length
            ((uint)*(ushort *)((int)pvVar12 + 0x3e) << 0x10 |
             (uint)*(byte *)((int)pvVar12 + 0x40) << 8 | (__size << 0x12) >> 0x18);
  buf2[1] = *(uint *)((int)pvVar12 + 0x4c);
  buf2[0] = *(uint *)((int)pvVar12 + 0x48);
  set_work_nonce2(buf2);
  set_merkle_bin_number(value);
  set_job_length(__size + local_8b0 & 0xffff);
  cgsleep_ms(1);
  if (*(char *)(iVar7 + 0xdd5) == '\0') {
    uVar21 = get_nonce_fifo_interrupt();
    set_nonce_fifo_interrupt(uVar21 | 0x10000);
    *(undefined *)(iVar15 + 0xdd5) = 1;
  }
  puVar16 = DAT_000390dc;
  if ((int)((uint)bVar5 << 0x1f) < 0) {
    if (*DAT_000390dc == 0) {
      uVar21 = get_dhash_acc_control();
      set_dhash_acc_control(uVar21 | 0x80);
LAB_00038f6c:
      uVar21 = get_dhash_acc_control();
      set_dhash_acc_control(uVar21 & 0xfffff0ff | (*puVar16 & 0xf) << 8 | 0x60);
      goto LAB_00038f86;
    }
    uVar21 = get_dhash_acc_control();
    set_dhash_acc_control(uVar21 | 0x80);
  }
  else if (*DAT_000390dc == 0) goto LAB_00038f6c;
  uVar21 = get_dhash_acc_control();
  set_dhash_acc_control(uVar21 & 0xfffff0ff | (*puVar16 & 0xf) << 8 | 0x8060);
LAB_00038f86:
  free(pvVar12);
  free(__s);
  if (*(short *)((int)pvVar12 + 0x42) != 0) {
    free(local_8b8);
  }
  if ((*pcVar8 != '\0') &&
     (((*DAT_000390e0 != '\0' || (*DAT_000390e4 != '\0')) || (6 < *DAT_000390e8)))) {
    snprintf(tmp42,0x800,DAT_000390ec,DAT_000390f0);
    _applog(7,tmp42,false);
  }
  cgtime(DAT_000390f4);
  return 0;
}

