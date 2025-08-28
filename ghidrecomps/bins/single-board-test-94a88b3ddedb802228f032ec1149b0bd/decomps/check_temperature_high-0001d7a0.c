
bool check_temperature_high(void)

{
  char cVar1;
  byte bVar2;
  FILE *pFVar3;
  bool bVar4;
  int local_1c;
  int local_18;
  byte local_11;
  
  cVar1 = is_S9_Hydro();
  if (cVar1 == '\x01') {
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d: Enter into check_temperature_high\n","driver-bitmain.c",0x9b3);
      }
      fclose(pFVar3);
    }
    local_11 = 0;
    cgpu[0x27196b] = 3;
    cgpu[0x27196d] = 3;
    cgpu[0x27196f] = 3;
    cgpu[0x271969] = 3;
    cgpu[0x2719b3] = 0;
    cgpu[0x2719c3] = 0;
    cgpu[0x2719d3] = 0;
    cgpu[0x2719a3] = 0;
    cgpu[0x2719b4] = 8;
    cgpu[0x2719c4] = 8;
    cgpu[0x2719d4] = 8;
    cgpu[0x2719a4] = 8;
    cgpu[0x2719b5] = 0x10;
    cgpu[0x2719c5] = 0x10;
    cgpu[0x2719d5] = 0x10;
    cgpu[0x2719a5] = 0x10;
    for (local_18 = 0; local_18 < 0x10; local_18 = local_18 + 1) {
      if (*(int *)(cgpu + (local_18 + 0x9c638) * 4) == 1) {
        if ((fpga_version < 0xe) && (fpga_major_version < 0xc6)) {
          if (local_18 % 3 == 1) {
LAB_0001d9e4:
            for (local_1c = 0; local_1c < (char)cgpu[local_18 + 0x271963]; local_1c = local_1c + 1)
            {
              bVar2 = read_asic_temperature_onechain
                                (local_18,cgpu[local_18 * 8 + local_1c + 0x271973]);
              if (local_11 < bVar2) {
                local_11 = bVar2;
              }
            }
          }
        }
        else if ((local_18 == 8) || (((local_18 == 10 || (local_18 == 0xc)) || (local_18 == 6))))
        goto LAB_0001d9e4;
      }
    }
    if (3 < log_level) {
      pFVar3 = fopen(log_file,"a+");
      if (pFVar3 != (FILE *)0x0) {
        fprintf(pFVar3,"%s:%d: The PCB MAX temperature is %d \n","driver-bitmain.c",0x9e3,
                (uint)local_11);
      }
      fclose(pFVar3);
    }
    bVar4 = 0x50 < local_11;
  }
  else {
    bVar4 = false;
  }
  return bVar4;
}

