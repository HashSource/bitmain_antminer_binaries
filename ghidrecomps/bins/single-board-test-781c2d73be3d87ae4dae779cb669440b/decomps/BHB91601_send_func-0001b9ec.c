
/* WARNING: Restarted to delay deadcode elimination for space: ram */
/* WARNING: Unknown calling convention */

void * BHB91601_send_func(void *arg)

{
  byte bVar1;
  undefined4 uVar2;
  chain_info *chain_info;
  uint uVar3;
  uint uVar4;
  work *__dest;
  uchar *puVar5;
  work **works;
  uchar which_i2c;
  uchar *puVar6;
  uint uVar7;
  int iVar8;
  uchar *puVar9;
  vil_work_1391 *pvVar10;
  work *work;
  void *__src;
  uchar which_chain;
  uint uVar11;
  uint *puVar12;
  work *__src_00;
  uint *puVar13;
  int local_b4;
  uchar local_ac;
  uint local_9c;
  int *local_98;
  vil_work_1391 work_vil_1391;
  uint buf_vil [13];
  
                    /* WARNING: Load size is inaccurate */
  uVar11 = (uint)*arg;
  bVar1 = *(byte *)((int)arg + 1);
  memset(buf_vil,0,0x34);
  printf("\n--- %s: which_chain = %d, which_i2c = %d\n",DAT_0001bd3c,uVar11,(uint)bVar1);
  if (gBegin_Get_Nonce == false) {
    uVar3 = read_axi_fpga(7);
    write_axi_fpga(7,uVar3 | 0x10000);
    gBegin_Get_Nonce = true;
  }
  if (BHB91601_ASIC_NUMBER == 0) {
    uVar3 = gSend_Work_Num[uVar11];
  }
  else {
    local_98 = DAT_0001bd40;
    local_9c = 0;
    uVar7 = Conf.pattern_number;
    do {
      local_98 = local_98 + 1;
      iVar8 = *local_98;
      local_b4 = 0;
      do {
        uVar3 = 0;
        if (uVar7 != 0) {
          do {
            if (gReadingTemp != false) {
              usleep(10000);
            }
            uVar4 = read_axi_fpga(3);
            if ((1 << gChain & uVar4) == 0) {
              usleep(1000);
            }
            else {
              __src = (void *)(iVar8 + (uVar7 * local_b4 + uVar3) * 0x44);
              memset(buf_vil,0,0x34);
              memset(&work_vil_1391,0,0x34);
              local_ac = (uchar)(uVar11 | 0x80);
              puVar9 = (uchar *)((int)__src + 7);
              puVar6 = (uchar *)((int)__src + 0x13);
              puVar5 = (uchar *)((int)&work_vil_1391.work_count + 3);
              work_vil_1391.work_type = '\x01';
              work_vil_1391.chain_id = local_ac;
              do {
                puVar9 = puVar9 + 1;
                puVar5 = puVar5 + 1;
                *puVar5 = *puVar9;
              } while (puVar6 != puVar9);
              puVar9 = work_vil_1391.data + 0xb;
              do {
                puVar6 = puVar6 + 1;
                puVar9 = puVar9 + 1;
                *puVar9 = *puVar6;
              } while (puVar9 != work_vil_1391.midstate + 0x1f);
              buf_vil[0] = (uVar11 | 0x80) << 0x10 | 0x1000000;
              puVar12 = buf_vil + 1;
              pvVar10 = &work_vil_1391;
              do {
                puVar13 = &pvVar10->work_count;
                puVar12 = puVar12 + 1;
                *puVar12 = (uint)pvVar10->data[3] |
                           (uint)pvVar10->data[1] << 0x10 | (uint)pvVar10->data[0] << 0x18 |
                           (uint)pvVar10->data[2] << 8;
                pvVar10 = (vil_work_1391 *)puVar13;
              } while (puVar13 != (uint *)(work_vil_1391.data + 4));
              puVar12 = buf_vil + 4;
              pvVar10 = &work_vil_1391;
              do {
                puVar13 = &pvVar10->work_count;
                puVar12 = puVar12 + 1;
                *puVar12 = (uint)pvVar10->midstate[3] |
                           (uint)pvVar10->midstate[1] << 0x10 | (uint)pvVar10->midstate[0] << 0x18 |
                           (uint)pvVar10->midstate[2] << 8;
                pvVar10 = (vil_work_1391 *)puVar13;
              } while (puVar13 != (uint *)(work_vil_1391.midstate + 0xc));
              work_vil_1391.work_count = uVar3;
              buf_vil[1] = uVar3;
              set_TW_write_command(buf_vil);
              pthread_mutex_lock((pthread_mutex_t *)(HW_check_mutex + uVar11));
              __dest = gWorks_For_Hw_Check[uVar11] + 0x7f;
              do {
                __src_00 = __dest + -1;
                memcpy(__dest,__src_00,0x44);
                __dest = __src_00;
              } while (gWorks_For_Hw_Check[uVar11] != __src_00);
              uVar3 = uVar3 + 1;
              gWork_Num_For_Hw_Check = gWork_Num_For_Hw_Check + 1;
              if (0x7e < gWork_Num_For_Hw_Check) {
                gWork_Num_For_Hw_Check = 0x7f;
              }
              memcpy(gWorks_For_Hw_Check[uVar11],__src,0x44);
              pthread_mutex_unlock((pthread_mutex_t *)(HW_check_mutex + uVar11));
              gSend_Work_Num[uVar11] = gSend_Work_Num[uVar11] + 1;
            }
            uVar7 = Conf.pattern_number;
          } while (uVar3 < Conf.pattern_number);
        }
        uVar2 = DAT_0001bd3c;
        local_b4 = local_b4 + 1;
      } while (local_b4 != 0x100);
      local_9c = local_9c + 1;
    } while (local_9c < BHB91601_ASIC_NUMBER);
    uVar3 = gSend_Work_Num[uVar11];
    uVar7 = uVar7 * BHB91601_ASIC_NUMBER * 0x100;
    if (uVar3 <= uVar7 && uVar7 - uVar3 != 0) {
      do {
        printf("\n\n---%s: Chain%d send work num : %d, less than %d\n",uVar2,uVar11,uVar3,uVar7);
        uVar3 = gSend_Work_Num[uVar11];
        uVar7 = BHB91601_ASIC_NUMBER * Conf.pattern_number * 0x100;
      } while (uVar3 < uVar7);
    }
  }
  printf("\n\n---%s: Chain%d send work num : %d\n",DAT_0001bd3c,uVar11,uVar3);
  puts("\nsend test pattern done");
  system("date");
  uVar7 = 0;
  putchar(10);
  uVar4 = gValid_Nonce_Num[uVar11];
  uVar3 = uVar4;
  do {
    uVar7 = uVar7 + 1;
    if (uVar3 == uVar4) {
      if (2 < uVar7) {
        while (gReadingTemp != false) {
          usleep(10000);
        }
        start_receive = false;
        puts("to stop receive");
        return (void *)0x0;
      }
      usleep(1000000);
    }
    else {
      usleep(1000000);
      uVar7 = 0;
      uVar3 = uVar4;
    }
    uVar4 = gValid_Nonce_Num[uVar11];
  } while( true );
}

