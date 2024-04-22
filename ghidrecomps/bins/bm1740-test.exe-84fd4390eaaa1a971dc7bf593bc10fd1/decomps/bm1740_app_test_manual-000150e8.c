
undefined4 bm1740_app_test_manual(void)

{
  undefined4 uVar1;
  undefined2 local_18 [6];
  int local_c;
  
  local_c = 1;
  while( true ) {
    if (local_c == 0) {
      return 0;
    }
    local_18[0] = 0;
    sleep(1);
    setbuf(stdin,(char *)0x0);
    printf("\nInput test paramter:");
    __isoc99_fscanf(stdin,&DAT_0002c1c8,local_18);
    if ((byte)local_18[0] - 0x61 < 0x17) break;
    puts("unknow command");
  }
                    /* WARNING: Could not recover jumptable at 0x0001514e. Too many branches */
                    /* WARNING: Treating indirect jump as call */
  uVar1 = (**(code **)(&DAT_00015154 + ((byte)local_18[0] - 0x61) * 4))();
  return uVar1;
}

