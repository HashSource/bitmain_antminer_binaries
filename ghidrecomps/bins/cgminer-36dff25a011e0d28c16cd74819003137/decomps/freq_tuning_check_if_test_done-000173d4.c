
_Bool freq_tuning_check_if_test_done(freq_tuning_info *freq_info)

{
  undefined uVar1;
  bool bVar2;
  freq_tuning_info *freq_info_local;
  int chain;
  int chain_num;
  int done_num;
  
  done_num = 0;
  chain_num = 0;
  for (chain = 0; chain < 0x10; chain = chain + 1) {
    if ((dev->chain_exist[chain] != 0) &&
       (chain_num = chain_num + 1, freq_info->test_done[chain] != false)) {
      done_num = done_num + 1;
    }
  }
  bVar2 = done_num == chain_num;
  if (bVar2) {
    chain_num = 1;
  }
  uVar1 = (undefined)chain_num;
  if (!bVar2) {
    uVar1 = 0;
  }
  return (_Bool)uVar1;
}

