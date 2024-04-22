
void down_freq_n_steps(undefined4 param_1,int *param_2,int param_3)

{
  int iVar1;
  FILE *pFVar2;
  long lVar3;
  undefined4 uVar4;
  int iVar5;
  int iVar6;
  int *piVar7;
  uint uVar8;
  
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: down_freq_n_steps chain[%d] steps = %d\n","driver-btm-c5.c",0x2788,
              DAT_00035858,param_1,param_3);
    }
    fclose(pFVar2);
  }
  uVar8 = 1;
  iVar6 = 0;
  piVar7 = param_2;
  do {
    while( true ) {
      iVar5 = dev;
      iVar1 = *piVar7;
      *piVar7 = iVar1 - param_3;
      set_frequency_with_addr_plldatai
                (iVar1 - param_3,0,
                 (int)(short)(ushort)*(byte *)(iVar5 + 0x542d) * (int)(short)iVar6 & 0xff,param_1);
      if (3 < log_level) break;
LAB_0003554e:
      iVar6 = iVar6 + 1;
      piVar7 = piVar7 + 1;
      uVar8 = uVar8 + 1;
      if (iVar6 == 0x54) goto LAB_000355e2;
    }
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"Asic[%2d]:%s ",iVar6,*(undefined4 *)(freq_pll_1385 + *piVar7 * 0x10));
    }
    fclose(pFVar2);
    if (((uVar8 & 7) != 0) || (log_level < 4)) goto LAB_0003554e;
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fputc(10,pFVar2);
    }
    iVar6 = iVar6 + 1;
    fclose(pFVar2);
    piVar7 = piVar7 + 1;
    uVar8 = uVar8 + 1;
  } while (iVar6 != 0x54);
LAB_000355e2:
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fputc(10,pFVar2);
    }
    fclose(pFVar2);
  }
  lVar3 = strtol(*(char **)(freq_pll_1385 + *param_2 * 0x10),(char **)0x0,10);
  uVar8 = log_level;
  *(short *)(dev + 0x5443) = (short)lVar3;
  if (uVar8 < 4) {
LAB_00035610:
    if ((int)((uint)config_parameter[4] << 0x1d) < 0) goto LAB_00035620;
  }
  else {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: max freq = %d\n","driver-btm-c5.c",0x27ad,DAT_00035858,
              (uint)*(ushort *)(dev + 0x5443));
    }
    fclose(pFVar2);
    if (3 < log_level) {
      pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
      if (pFVar2 != (FILE *)0x0) {
        fprintf(pFVar2,"%s:%d:%s: dev->timeout = %d\n","driver-btm-c5.c",0x27af,DAT_00035858,
                *(undefined4 *)(dev + 0x48));
      }
      fclose(pFVar2);
      goto LAB_00035610;
    }
    if (-1 < (int)((uint)config_parameter[4] << 0x1d)) goto LAB_00035654;
LAB_00035620:
    iVar6 = dev;
    if (config_parameter._18_2_ == 0) {
      uVar4 = calculate_core_number(*(undefined *)(dev + 0x542c));
      iVar6 = dev;
      iVar5 = __aeabi_idiv(0x1000000,uVar4);
      iVar5 = __aeabi_idiv((uint)*(byte *)(iVar6 + 0x542d) * iVar5,*(undefined2 *)(iVar6 + 0x5443));
      uVar8 = (iVar5 * 0x5a) / 100;
      *(uint *)(iVar6 + 0x48) = uVar8;
    }
    else {
      uVar8 = (uint)config_parameter[18] * 1000 + (uint)config_parameter[19];
      *(uint *)(dev + 0x48) = uVar8;
    }
    if (0x1ffff < uVar8) {
      *(undefined4 *)(iVar6 + 0x48) = 0x1ffff;
    }
  }
  if (3 < log_level) {
    pFVar2 = fopen(log_file,(char *)&DAT_0005e760);
    if (pFVar2 != (FILE *)0x0) {
      fprintf(pFVar2,"%s:%d:%s: dev->timeout = %d\n","driver-btm-c5.c",0x27c1,DAT_00035858,
              *(undefined4 *)(dev + 0x48));
    }
    fclose(pFVar2);
  }
LAB_00035654:
  set_asic_ticket_mask(ticket_mask);
  set_hcnt(0);
  set_sno(0);
  cgsleep_ms(10);
  if (opt_multi_version != 0) {
    set_time_out_control(*(int *)(dev + 0x48) * opt_multi_version & 0x1ffffU | 0x80000000);
    return;
  }
  set_time_out_control(*(uint *)(dev + 0x48) & 0x1ffff | 0x80000000);
  return;
}

