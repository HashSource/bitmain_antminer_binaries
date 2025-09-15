
void hash_board_reset(int chain)

{
  int chain_local;
  
  set_reset_hashboard(chain,1);
  sleep(1);
  set_reset_hashboard(chain,0);
  sleep(1);
  return;
}

