
/* WARNING: Unknown calling convention */

uint single_BM1385_get_result(uchar which_chain)

{
  uint (*pauVar1) [1];
  uint uVar2;
  work *pwVar3;
  undefined4 *puVar4;
  uint uVar5;
  uint *puVar6;
  uint OpenCoreNum1;
  uint uVar7;
  int iVar8;
  uint OpenCoreNum2;
  uint uVar9;
  uint uVar10;
  uchar *puVar11;
  
  uVar9 = Conf.OpenCoreNum2;
  uVar7 = Conf.OpenCoreNum1;
  uVar2 = (uint)which_chain;
  puts(
      "\n\n------------------------------------------------------------------------------------------------------\n"
      );
  puVar6 = (uint *)(gAsic_Core_Nonce_Num + uVar2);
  printf("every CORE require nonce number: %u\n\n",Conf.pattern_number);
  printf("Open core number : Conf.OpenCoreNum1 = %u = 0x%08x\n",Conf.OpenCoreNum1);
  puVar4 = (undefined4 *)((int)&reg_mutex + uVar2 * 0x80000 + 0x14);
  printf("Open core number : Conf.OpenCoreNum2 = %u = 0x%08x\n",Conf.OpenCoreNum2);
  printf("Open core number : Conf.OpenCoreNum3 = %u = 0x%08x\n",Conf.OpenCoreNum3);
  printf("Open core number : Conf.OpenCoreNum4 = %u = 0x%08x\n\n",Conf.OpenCoreNum4);
  uVar5 = 0;
  do {
    if (uVar5 == (uVar5 / 10) * 10) {
      putchar(10);
    }
    puVar4 = puVar4 + 1;
    uVar10 = uVar5 + 1;
    printf("core[%02d]=%02d\t",uVar5,*puVar4);
    uVar5 = uVar10;
  } while (uVar10 != 0x32);
  iVar8 = 0;
  uVar5 = 0;
  uVar10 = 1;
  puts("\n\n");
  do {
    if (uVar5 < 0x20) {
      if ((int)(uVar7 << 0x1f) < 0) {
        if (*puVar6 < Conf.pattern_number) {
          pwVar3 = cgpu.works[iVar8];
          printf("core[%02d] = %d,      lost these nonce : ",uVar5);
          if (Conf.pattern_number != 0) {
            puVar11 = pwVar3->data + uVar2 * 4 + -8;
            uVar10 = 0;
            do {
              while (pauVar1 = (uint (*) [1])(puVar11 + 0x34), puVar11 = puVar11 + 0x44,
                    (*pauVar1)[0] != 0) {
                uVar10 = uVar10 + 1;
                if (Conf.pattern_number <= uVar10) goto LAB_00011b24;
              }
              printf("%d  ",uVar10);
              uVar10 = uVar10 + 1;
            } while (uVar10 < Conf.pattern_number);
          }
LAB_00011b24:
          uVar10 = 0;
          putchar(10);
        }
        uVar7 = uVar7 >> 1;
        iVar8 = iVar8 + 1;
      }
      else {
        uVar7 = uVar7 >> 1;
      }
    }
    else if ((uVar9 & 1) == 0) {
      uVar9 = uVar9 >> 1;
    }
    else {
      pwVar3 = cgpu.works[iVar8];
      if (*puVar6 < Conf.pattern_number) {
        printf("core[%02d] = %d,      lost these nonce : ",uVar5);
        if (Conf.pattern_number != 0) {
          uVar10 = 0;
          puVar11 = pwVar3->data + uVar2 * 4 + -8;
          do {
            pauVar1 = (uint (*) [1])(puVar11 + 0x34);
            puVar11 = puVar11 + 0x44;
            if ((*pauVar1)[0] == 0) {
              printf("%d  ",uVar10);
            }
            uVar10 = uVar10 + 1;
          } while (uVar10 < Conf.pattern_number);
        }
        uVar10 = 0;
        putchar(10);
      }
      uVar9 = uVar9 >> 1;
      iVar8 = iVar8 + 1;
    }
    uVar5 = uVar5 + 1;
    puVar6 = puVar6 + 1;
    if (uVar5 == 0x32) {
      puts(
          "\n------------------------------------------------------------------------------------------------------\n"
          );
      printf("Chain%d total valid nonce number: %d\n\n",uVar2,gValid_Nonce_Num[uVar2]);
      if (uVar10 == 0) {
        puts("Pattern NG\n");
      }
      else {
        puts("Pattern OK\n");
      }
      printf("HW number = %d\n\n",gHw_Nonce_Num[uVar2]);
      return uVar10;
    }
  } while( true );
}

