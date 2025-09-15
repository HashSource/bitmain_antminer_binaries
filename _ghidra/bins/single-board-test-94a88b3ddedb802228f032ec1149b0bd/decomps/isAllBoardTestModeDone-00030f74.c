
undefined4 isAllBoardTestModeDone(void)

{
  int local_c;
  
  local_c = 0;
  while( true ) {
    if (0xf < local_c) {
      return 1;
    }
    if ((*(int *)(cgpu + (local_c + 0x9c638) * 4) != 0) &&
       (*(int *)(testModeOKCounter + local_c * 4) < TEST_MODE_OK_NUM)) break;
    local_c = local_c + 1;
  }
  return 0;
}

