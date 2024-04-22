
/* WARNING: Unknown calling convention */

void * BHB07601_send_func(void *arg)

{
  byte bVar1;
  chain_info *chain_info;
  uint uVar2;
  uint uVar3;
  uchar *puVar4;
  uchar *puVar5;
  work **works;
  int iVar6;
  uchar *puVar7;
  vil_work_1397 *pvVar8;
  uint uVar9;
  uchar which_i2c;
  uint uVar10;
  uchar which_chain;
  uint uVar11;
  work *work;
  void *__src;
  uint *puVar12;
  uint *puVar13;
  int local_b0;
  uchar local_a8;
  uint local_9c;
  int *local_98;
  vil_work_1397 work_vil_1397;
  uint buf_vil [13];
  
                    /* WARNING: Load size is inaccurate */
  uVar11 = (uint)*arg;
  bVar1 = *(byte *)((int)arg + 1);
  memset(buf_vil,0,0x34);
  printf("\n--- %s: which_chain = %d, which_i2c = %d\n","BHB07601_send_func",uVar11,(uint)bVar1);
  if (gBegin_Get_Nonce == false) {
    uVar2 = read_axi_fpga(7);
    write_axi_fpga(7,uVar2 | 0x10000);
    gBegin_Get_Nonce = true;
  }
  if (BHB07601_ASIC_NUMBER == 0) {
    uVar2 = gSend_Work_Num[uVar11];
  }
  else {
    uVar2 = 0;
    local_98 = DAT_0001fcc8;
    local_9c = 0;
    uVar9 = Conf.pattern_number;
    do {
      local_98 = local_98 + 1;
      iVar6 = *local_98;
      local_b0 = 0;
      do {
        uVar10 = 0;
        if (uVar9 != 0) {
          do {
            if (gReadingTemp != false) {
              usleep(10000);
            }
            uVar3 = read_axi_fpga(3);
            if ((1 << gChain & uVar3) == 0) {
              usleep(1000);
            }
            else {
              __src = (void *)(iVar6 + (uVar9 * local_b0 + uVar10) * 0x44);
              memset(buf_vil,0,0x34);
              memset(&work_vil_1397,0,0x34);
              local_a8 = (uchar)(uVar11 | 0x80);
              work_vil_1397.work_count = uVar2 & 0x7f | uVar10 << 7;
              puVar7 = (uchar *)((int)__src + 7);
              puVar5 = (uchar *)((int)__src + 0x13);
              work_vil_1397.work_type = '\x01';
              puVar4 = (uchar *)((int)&work_vil_1397.work_count + 3);
              work_vil_1397.chain_id = local_a8;
              do {
                puVar7 = puVar7 + 1;
                puVar4 = puVar4 + 1;
                *puVar4 = *puVar7;
              } while (puVar5 != puVar7);
              puVar7 = work_vil_1397.data + 0xb;
              do {
                puVar5 = puVar5 + 1;
                puVar7 = puVar7 + 1;
                *puVar7 = *puVar5;
              } while (puVar7 != work_vil_1397.midstate + 0x1f);
              buf_vil[0] = (uVar11 | 0x80) << 0x10 | 0x1000000;
              puVar12 = buf_vil + 1;
              pvVar8 = &work_vil_1397;
              do {
                puVar13 = &pvVar8->work_count;
                puVar12 = puVar12 + 1;
                *puVar12 = (uint)pvVar8->data[3] |
                           (uint)pvVar8->data[1] << 0x10 | (uint)pvVar8->data[0] << 0x18 |
                           (uint)pvVar8->data[2] << 8;
                pvVar8 = (vil_work_1397 *)puVar13;
              } while (puVar13 != (uint *)(work_vil_1397.data + 4));
              puVar12 = buf_vil + 4;
              pvVar8 = &work_vil_1397;
              do {
                puVar13 = &pvVar8->work_count;
                puVar12 = puVar12 + 1;
                *puVar12 = (uint)pvVar8->midstate[3] |
                           (uint)pvVar8->midstate[1] << 0x10 | (uint)pvVar8->midstate[0] << 0x18 |
                           (uint)pvVar8->midstate[2] << 8;
                pvVar8 = (vil_work_1397 *)puVar13;
              } while ((uint *)(work_vil_1397.midstate + 0xc) != puVar13);
              uVar10 = uVar10 + 1;
              buf_vil[1] = work_vil_1397.work_count;
              set_TW_write_command(buf_vil);
              uVar9 = uVar2 + 1;
              memcpy(gWorks_For_Hw_Check[uVar11] + uVar2,__src,0x44);
              if (0x7f < uVar9) {
                uVar9 = 0;
              }
              gSend_Work_Num[uVar11] = gSend_Work_Num[uVar11] + 1;
              uVar2 = uVar9;
            }
            uVar9 = Conf.pattern_number;
          } while (uVar10 < Conf.pattern_number);
        }
        local_b0 = local_b0 + 1;
      } while (local_b0 != 0x2a0);
      local_9c = local_9c + 1;
    } while (local_9c < BHB07601_ASIC_NUMBER);
    uVar2 = gSend_Work_Num[uVar11];
    uVar9 = uVar9 * BHB07601_ASIC_NUMBER * 0x2a0;
    if (uVar2 <= uVar9 && uVar9 - uVar2 != 0) {
      do {
        printf("\n\n---%s: Chain%d send work num : %d, less than %d\n","BHB07601_send_func",uVar11,
               uVar2,uVar9);
        uVar2 = gSend_Work_Num[uVar11];
        uVar9 = BHB07601_ASIC_NUMBER * Conf.pattern_number * 0x2a0;
      } while (uVar2 < uVar9);
    }
  }
  printf("\n\n---%s: Chain%d send work num : %d\n","BHB07601_send_func",uVar11,uVar2);
  puts("\nsend test pattern done");
  uVar9 = 0;
  system("date");
  putchar(10);
  uVar10 = gValid_Nonce_Num[uVar11];
  uVar2 = uVar10;
  do {
    uVar9 = uVar9 + 1;
    if (uVar2 == uVar10) {
      if (2 < uVar9) {
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
      uVar9 = 0;
      uVar2 = uVar10;
    }
    uVar10 = gValid_Nonce_Num[uVar11];
  } while( true );
}

