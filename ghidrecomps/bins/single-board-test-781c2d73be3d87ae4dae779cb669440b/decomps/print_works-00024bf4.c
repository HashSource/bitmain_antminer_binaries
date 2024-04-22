
/* WARNING: Unknown calling convention */

void print_works(void)

{
  int iVar1;
  work *works;
  uint OpenCoreNum1;
  uint OpenCoreNum2;
  uint OpenCoreNum3;
  uint OpenCoreNum4;
  uint OpenCoreNum5;
  uint OpenCoreNum6;
  uint OpenCoreNum7;
  uint OpenCoreNum8;
  byte *pbVar2;
  uchar *puVar3;
  uchar *puVar4;
  int iVar5;
  work *work;
  int n;
  uint uVar6;
  uint uVar7;
  uint local_54;
  uint local_50;
  uint local_4c;
  uint local_48;
  uint local_44;
  int *local_40;
  uint local_3c;
  uint local_38;
  uint local_34;
  
  local_50 = Conf.OpenCoreNum1;
  local_4c = Conf.OpenCoreNum2;
  local_48 = Conf.OpenCoreNum3;
  local_44 = Conf.OpenCoreNum4;
  local_40 = (int *)Conf.OpenCoreNum5;
  local_3c = Conf.OpenCoreNum6;
  local_38 = Conf.OpenCoreNum7;
  local_34 = Conf.OpenCoreNum8;
  printf("\n--- %s begin\n\n","print_works");
  if (Conf.AsicNum == 1) {
    n = 0;
    local_54 = 0;
    do {
      if ((int)(local_50 << 0x1f) < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",n,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar4 != puVar3 + 0x20);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      n = n + 1;
      local_50 = local_50 >> 1;
    } while (n != 0x20);
    iVar1 = 0x20;
    do {
      if ((int)(local_4c << 0x1f) < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",iVar1,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar4 != puVar3 + 0x20);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      iVar1 = iVar1 + 1;
      local_4c = local_4c >> 1;
    } while (iVar1 != 0x40);
    iVar1 = 0x40;
    do {
      if ((int)(local_48 << 0x1f) < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",iVar1,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar4 != puVar3 + 0x20);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      iVar1 = iVar1 + 1;
      local_48 = local_48 >> 1;
    } while (iVar1 != 0x60);
    iVar1 = 0x60;
    do {
      if ((int)(local_44 << 0x1f) < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",iVar1,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar4 != puVar3 + 0x20);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      iVar1 = iVar1 + 1;
      local_44 = local_44 >> 1;
    } while (iVar1 != 0x80);
    iVar1 = 0x80;
    do {
      if ((int)local_40 << 0x1f < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",iVar1,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar4 != puVar3 + 0x20);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      iVar1 = iVar1 + 1;
      local_40 = (int *)((uint)local_40 >> 1);
    } while (iVar1 != 0xa0);
    iVar1 = 0xa0;
    do {
      if ((int)(local_3c << 0x1f) < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",iVar1,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar3 + 0x20 != puVar4);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      iVar1 = iVar1 + 1;
      local_3c = local_3c >> 1;
    } while (iVar1 != 0xc0);
    iVar1 = 0xc0;
    do {
      if ((int)(local_38 << 0x1f) < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",iVar1,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar3 + 0x20 != puVar4);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      iVar1 = iVar1 + 1;
      local_38 = local_38 >> 1;
    } while (iVar1 != 0xe0);
    iVar1 = 0xe0;
    do {
      if ((int)(local_34 << 0x1f) < 0) {
        uVar7 = 0;
        puVar3 = cgpu.works[local_54]->data + 0xb;
        if (Conf.pattern_number != 0) {
          do {
            printf("core[%02d][%02d].midstate=0x",iVar1,uVar7);
            puVar4 = puVar3;
            do {
              puVar4 = puVar4 + 1;
              printf("%02x",(uint)*puVar4);
            } while (puVar3 + 0x20 != puVar4);
            pbVar2 = puVar3 + -0xc;
            printf(" data2=");
            do {
              pbVar2 = pbVar2 + 1;
              printf("%02x",(uint)*pbVar2);
            } while (pbVar2 != puVar3);
            uVar7 = uVar7 + 1;
            printf(" nonce=0x%08x\n",*(uint *)(puVar3 + -0xf));
            puVar3 = puVar3 + 0x44;
          } while (uVar7 < Conf.pattern_number);
        }
        local_54 = local_54 + 1;
        putchar(10);
      }
      iVar1 = iVar1 + 1;
      local_34 = local_34 >> 1;
    } while (iVar1 != 0x100);
  }
  else if (Conf.AsicNum != 0) {
    local_40 = DAT_00024d3c;
    local_54 = 0;
    do {
      uVar7 = 0;
      local_40 = local_40 + 1;
      iVar1 = *local_40;
      if (Conf.CoreNum != 0) {
        do {
          uVar6 = 0;
          if (Conf.pattern_number != 0) {
            do {
              iVar5 = iVar1 + (Conf.pattern_number * uVar7 + uVar6) * 0x44;
              printf("asic[%02d][%02d][%02d].midstate=0x",local_54,uVar7,uVar6);
              pbVar2 = (byte *)(iVar5 + 0x13);
              do {
                pbVar2 = pbVar2 + 1;
                printf("%02x",(uint)*pbVar2);
              } while (pbVar2 != (byte *)(iVar5 + 0x33));
              pbVar2 = (byte *)(iVar5 + 7);
              printf(" data2=");
              do {
                pbVar2 = pbVar2 + 1;
                printf("%02x",(uint)*pbVar2);
              } while ((byte *)(iVar5 + 0x13) != pbVar2);
              uVar6 = uVar6 + 1;
              printf(" nonce=0x%08x\n",*(undefined4 *)(iVar5 + 4));
            } while (uVar6 < Conf.pattern_number);
          }
          uVar7 = uVar7 + 1;
        } while (uVar7 < Conf.CoreNum);
      }
      local_54 = local_54 + 1;
      putchar(10);
    } while (local_54 < Conf.AsicNum);
  }
  (*(code *)PTR_printf_00030118)("\n--- %s end\n\n","print_works");
  return;
}

