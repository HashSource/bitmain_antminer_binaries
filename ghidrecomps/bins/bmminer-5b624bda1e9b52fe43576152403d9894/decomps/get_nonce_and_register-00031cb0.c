
/* WARNING: Unknown calling convention */

void * get_nonce_and_register(void)

{
  byte bVar1;
  int iVar2;
  uint *puVar3;
  int iVar4;
  pthread_mutex_t *ppVar5;
  uint *puVar6;
  uint *puVar7;
  int iVar8;
  uint *puVar9;
  uint uVar10;
  nonce_buf *pnVar11;
  int iVar12;
  int ret;
  uint uVar13;
  nonce_buf *pnVar14;
  uint uVar15;
  uint uVar16;
  uint uVar17;
  char tmp42 [2048];
  
  iVar8 = DAT_00031f04;
  puVar6 = DAT_00031f00;
  iVar4 = DAT_00031eec;
  puVar3 = DAT_00031ee8;
  do {
    do {
      while (cgsleep_ms(1), *(char *)(iVar8 + 0xdd4) != '\0') {
        cgsleep_ms(100);
      }
      iVar12 = *(int *)(iVar4 + 0x8d4);
      uVar15 = *(uint *)(iVar12 + 0x18) & 0x1ff;
    } while (uVar15 == 0);
    if ((opt_debug != false) &&
       (((use_syslog != false || (opt_log_output != false)) || (6 < opt_log_level)))) {
      snprintf(tmp42,0x800,DAT_00031ef4,DAT_00031ef0,uVar15);
      _applog(7,tmp42,false);
      iVar12 = *(int *)(iVar4 + 0x8d4);
    }
    uVar17 = 0;
    while( true ) {
      uVar16 = *(uint *)(iVar12 + 0x10);
      uVar13 = *(uint *)(iVar12 + 0x14);
      if ((int)uVar16 < 0) {
        if ((*(char *)(iVar8 + 0xdd5) != '\0') && ((uVar16 & 0x80) != 0)) {
          pthread_mutex_lock(DAT_00031ef8);
          puVar9 = nonce2_jobid_address;
          uVar10 = (uVar16 << 1) >> 0x11;
          puVar6[*puVar6 * 0xf + 4] = uVar10;
          puVar6[*puVar6 * 0xf + 8] = uVar13;
          puVar6[*puVar6 * 0xf + 9] = uVar16 & 0xf;
          puVar6[*puVar6 * 0xf + 3] = puVar9[uVar10 * 0x10];
          puVar6[*puVar6 * 0xf + 5] = puVar9[uVar10 * 0x10 + 1];
          uVar16 = *puVar6;
          uVar13 = puVar9[uVar10 * 0x10 + 3];
          iVar12 = 0;
          puVar6[uVar16 * 0xf + 6] = puVar9[uVar10 * 0x10 + 2];
          puVar6[uVar16 * 0xf + 7] = uVar13;
          do {
            puVar7 = DAT_00031f00;
            bVar1 = *(byte *)((int)puVar9 + iVar12 + uVar10 * 0x40 + 0x20);
            uVar13 = (uint)bVar1;
            iVar2 = iVar12 + *puVar6 * 0x3c;
            iVar12 = iVar12 + 1;
            *(byte *)((int)puVar6 + iVar2 + 0x28) = bVar1;
            ppVar5 = DAT_00031ef8;
          } while (iVar12 != 0x20);
          if (*puVar7 < 0x1ff) {
            uVar16 = *puVar7 + 1;
          }
          else {
            uVar16 = 0;
          }
          *puVar7 = uVar16;
          uVar16 = puVar6[2];
          if (uVar16 < 0x1ff) {
            pnVar11 = &nonce_read_out;
            pnVar14 = (nonce_buf *)nonce_read_out.nonce_num;
          }
          else {
            uVar13 = 0x1ff;
            pnVar11 = (nonce_buf *)0x20;
            pnVar14 = &nonce_read_out;
          }
          if (uVar16 < 0x1ff) {
            pnVar14 = (nonce_buf *)((int)&pnVar14->p_wr + 1);
          }
          else {
            pnVar14->nonce_num = uVar13;
          }
          if (uVar16 < 0x1ff) {
            pnVar11->nonce_num = (uint)pnVar14;
          }
          pthread_mutex_unlock(ppVar5);
        }
      }
      else if ((puVar3[2] < 0x1ff) && (*puVar3 < 0x1ff)) {
        pthread_mutex_lock(DAT_00031efc);
        ppVar5 = DAT_00031efc;
        uVar10 = (uVar16 << 3) >> 0x1b;
        puVar3[(*puVar3 + 1) * 2 + 1] = uVar13;
        *(byte *)(puVar3 + (*puVar3 + 1) * 2 + 2) = (byte)((uVar16 << 3) >> 0x1b);
        *(byte *)((int)puVar3 + (*puVar3 + 1) * 8 + 9) = (byte)uVar16 & 0xf;
        if (*puVar3 < 0x1ff) {
          *puVar3 = *puVar3 + 1;
        }
        else {
          *puVar3 = 0;
        }
        uVar13 = puVar3[2];
        if (uVar13 < 0x1ff) {
          uVar16 = puVar3[2];
        }
        else {
          uVar10 = 0x1ff;
          uVar16 = uVar13;
        }
        if (uVar13 < 0x1ff) {
          uVar16 = uVar16 + 1;
        }
        else {
          puVar3[2] = uVar10;
        }
        if (uVar13 < 0x1ff) {
          puVar3[2] = uVar16;
        }
        pthread_mutex_unlock(ppVar5);
      }
      else {
        clear_register_value_buf();
      }
      uVar17 = uVar17 + 1;
      if (uVar17 == uVar15) break;
      iVar12 = *(int *)(iVar4 + 0x8d4);
    }
  } while( true );
}

